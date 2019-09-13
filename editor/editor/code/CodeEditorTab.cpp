#include "CodeEditorTab.h"
#include "editor/FileManager.h"
#include "compiler/ProgramDebugInfo.h"
#include "ui_CodeEditorTab.h"
#include <SciLexer.h>

static const char LuaKeywords[] =
    "and break do else elseif end for function if in local nil not or repeat "
    "return then until while false true goto";

static const char LuaBasicFunctions[] =
    "assert collectgarbage dofile error _G getmetatable ipairs loadfile next pairs pcall print "
    "rawequal rawget rawset setmetatable tonumber tostring type _VERSION xpcall string table math "
    "coroutine io os debug getfenv gcinfo load loadlib loadstring require select setfenv unpack "
    "_LOADED LUA_PATH _REQUIREDNAME package rawlen package bit32 utf8 _ENV";

static const char LuaStringAndMath[] =
    "string.byte string.char string.dump string.find string.format string.gsub string.len string.lower "
    "string.rep string.sub string.upper table.concat table.insert table.remove table.sort math.abs "
    "math.acos math.asin math.atan math.atan2 math.ceil math.cos math.deg math.exp math.floor math.frexp "
    "math.ldexp math.log math.max math.min math.pi math.pow math.rad math.random math.randomseed math.sin "
    "math.sqrt math.tan string.gfind string.gmatch string.match string.reverse string.pack string.packsize "
    "string.unpack table.foreach table.foreachi table.getn table.setn table.maxn table.pack table.unpack "
    "table.move math.cosh math.fmod math.huge math.log10 math.modf math.mod math.sinh math.tanh math.maxinteger "
    "math.mininteger math.tointeger math.type math.ult bit32.arshift bit32.band bit32.bnot bit32.bor bit32.btest "
    "bit32.bxor bit32.extract bit32.replace bit32.lrotate bit32.lshift bit32.rrotate bit32.rshift utf8.char "
    "utf8.charpattern utf8.codes utf8.codepoint utf8.len utf8.offset";

static const char LuaSystemAndIO[] =
    "coroutine.create coroutine.resume coroutine.status coroutine.wrap coroutine.yield io.close io.flush "
    "io.input io.lines io.open io.output io.read io.tmpfile io.type io.write io.stdin io.stdout io.stderr "
    "os.clock os.date os.difftime os.execute os.exit os.getenv os.remove os.rename os.setlocale os.time "
    "os.tmpname coroutine.isyieldable coroutine.running io.popen module package.loaders package.seeall "
    "package.config package.searchers package.searchpath require package.cpath package.loaded package.loadlib "
    "package.path package.preload";

CodeEditorTab::CodeEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_CodeEditorTab)
{
    mUi->setupUi(this);
    mUi->textEditor->setEnabled(false);
}

CodeEditorTab::~CodeEditorTab()
{
}

int CodeEditorTab::line() const
{
    if (!mDocument)
        return -1;
    return mUi->textEditor->lineFromPosition(mUi->textEditor->currentPos()) + 1;
}

bool CodeEditorTab::loadFile(File* f)
{
    bool doLoadFile;
    if (mDocument)
        doLoadFile = (f != file() || mDocument->is_save_point());
    else {
        mDocument = std::make_unique<ScintillaDocument>(this);
        connect(mDocument.get(), &ScintillaDocument::save_point,
            this, &CodeEditorTab::on_textEditor_savePointChanged);
        doLoadFile = true;
    }

    if (doLoadFile) {
        QByteArray fileData = loadFileData(f);
        QByteArray editorData = mDocument->get_char_range(0, mDocument->length());
        if (editorData != fileData) {
            mDocument->delete_chars(0, mDocument->length());
            mDocument->insert_string(0, fileData);
            mDocument->delete_undo_history();
            mDocument->set_save_point();
        }
    }

    bool success = (mDocument != nullptr);
    if (!mDocument) {
        if (!mDummyDocument)
            mDummyDocument = std::make_unique<ScintillaDocument>(this);
        mUi->textEditor->set_doc(mDummyDocument.get());
        mUi->textEditor->setFileName(QString());
        mUi->textEditor->setEnabled(false);
    } else {
        mUi->textEditor->set_doc(mDocument.get());
        mUi->textEditor->setFileName(f->relativeName());
        mUi->textEditor->setEnabled(true);

        QString extension = f->fileInfo().suffix();
        if (extension == QStringLiteral("lua")) {
            mUi->textEditor->setLexer(SCLEX_LUA);
            mUi->textEditor->setKeyWords(0, LuaKeywords);
            mUi->textEditor->setKeyWords(1, LuaBasicFunctions);
            mUi->textEditor->setKeyWords(2, LuaStringAndMath);
            mUi->textEditor->setKeyWords(3, LuaSystemAndIO);
        } else if (extension == QStringLiteral("bas"))
            mUi->textEditor->setLexer(SCLEX_FREEBASIC);
        else if (extension == QStringLiteral("asm"))
            mUi->textEditor->setLexer(SCLEX_ASM);
        else
            mUi->textEditor->setLexer(SCLEX_NULL);

        mUi->textEditor->styleClearAll();
        mUi->textEditor->styleSetFore(0, 0x000000); // whitespace
        mUi->textEditor->styleSetFore(1, 0x3f703f); // block comment
        mUi->textEditor->styleSetItalic(1, 1);
        mUi->textEditor->styleSetFore(2, 0x3f703f); // line comment
        mUi->textEditor->styleSetItalic(2, 1);
        mUi->textEditor->styleSetFore(3, 0x3f703f); // doc comment
        mUi->textEditor->styleSetItalic(3, 1);
        mUi->textEditor->styleSetFore(4, 0x808000); // number
        mUi->textEditor->styleSetFore(5, 0x800000); // keyword
        mUi->textEditor->styleSetBold(5, true);
        mUi->textEditor->styleSetFore(6, 0x800080); // String
        mUi->textEditor->styleSetFore(7, 0x800080); // Character
        mUi->textEditor->styleSetFore(8, 0x804080); // UUID
        mUi->textEditor->styleSetFore(9, 0x008080); // Preprocessor
        mUi->textEditor->styleSetFore(10, 0x000000); // Operators
        mUi->textEditor->styleSetFore(11, 0x000000); // Identifiers

        mUi->textEditor->clearDocumentStyle();
        mUi->textEditor->colourise(0, -1);
    }

    reloadSettings();
    emit updateUi();

    return success;
}

QString CodeEditorTab::lineColumnLabelText() const
{
    if (!mDocument)
        return QString();

    auto pos = mUi->textEditor->currentPos();
    int line = mUi->textEditor->lineFromPosition(pos) + 1;
    int column = mUi->textEditor->column(pos) + 1;
    return tr("Line %1, column %2").arg(line).arg(column);
}

QString CodeEditorTab::insOverwriteLabelText() const
{
    if (!mDocument)
        return QString();

    return (mUi->textEditor->overtype() ? tr("OVR") : tr("INS"));
}

bool CodeEditorTab::isModified() const
{
    return mDocument && !mDocument->is_save_point();
}

bool CodeEditorTab::canUndo() const
{
    return mDocument && mDocument->can_undo();
}

bool CodeEditorTab::canRedo() const
{
    return mDocument && mDocument->can_redo();
}

bool CodeEditorTab::canCut() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canCopy() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canPaste() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canClear() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canSelectAll() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canClearSelection() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canGoToLine() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canRunToCursor() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::save()
{
    bool success = true;
    if (mDocument && !mDocument->is_save_point()) {
        success = writeFileData(mDocument->get_char_range(0, mDocument->length()));
        if (success)
            mDocument->set_save_point();
    }

    emit updateUi();
    return success;
}

void CodeEditorTab::undo()
{
    if (mDocument)
        mUi->textEditor->undo();
}

void CodeEditorTab::redo()
{
    if (mDocument)
        mUi->textEditor->redo();
}

void CodeEditorTab::cut()
{
    if (mDocument)
        mUi->textEditor->cut();
}

void CodeEditorTab::copy()
{
    if (mDocument)
        mUi->textEditor->copy();
}

void CodeEditorTab::paste()
{
    if (mDocument)
        mUi->textEditor->paste();
}

void CodeEditorTab::clear()
{
    if (mDocument)
        mUi->textEditor->clear();
}

void CodeEditorTab::selectAll()
{
    if (mDocument)
        mUi->textEditor->selectAll();
}

void CodeEditorTab::clearSelection()
{
    if (mDocument)
        mUi->textEditor->clearSelections();
}

void CodeEditorTab::goToLine(int line)
{
    if (mDocument)
        mUi->textEditor->gotoLine(line);
}

void CodeEditorTab::updateTStates(ProgramDebugInfo* debugInfo)
{
    File* f = file();
    if (f)
        mUi->textEditor->updateTStates(debugInfo->tstatesForFile(f->relativeName()));
}

void CodeEditorTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
}

void CodeEditorTab::setFocusToEditor()
{
    static_cast<QWidget*>(mUi->textEditor)->setFocus();
}
