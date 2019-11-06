#include "MemoryMapDialog.h"
#include "debugger/EmulatorCore.h"
#include "compiler/ProgramDebugInfo.h"
#include "ui_MemoryMapDialog.h"
#include <QFontDatabase>

MemoryMapDialog::MemoryMapDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_MemoryMapDialog)
{
    mUi->setupUi(this);

    mUi->treeWidget->setColumnCount(2);
    mUi->treeWidget->setColumnWidth(0, 350);
    mUi->treeWidget->setHeaderItem(new QTreeWidgetItem(QStringList() << tr("Name") << tr("Address")));
    mUi->treeWidget->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));

    QIcon fileIcon(QStringLiteral(":/resources/fatcow16x16/receipt.png"));
    QIcon sectionIcon(QStringLiteral(":/resources/fatcow16x16/tag.png"));
    QIcon symbolIcon(QStringLiteral(":/resources/fatcow16x16/tag_hash.png"));

    for (const auto& it : EmulatorCore::instance()->programSectionInfo()) {
        QString fileName = it.first;
        if (fileName.isEmpty())
            fileName = tr("(main file)");

        QTreeWidgetItem* fileItem = new QTreeWidgetItem(mUi->treeWidget, QStringList() << fileName);
        fileItem->setExpanded(true);
        fileItem->setIcon(0, fileIcon);

        for (const ProgramSectionInfo& section : it.second) {
            QString sectionName = section.name;
            if (sectionName.isEmpty()) {
                if (section.originalLength == 0)
                    continue;
                sectionName = tr("(untitled)");
            }

            QString size;
            if (section.originalLength == section.compressedLength)
                size = tr("%1 byte(s)", nullptr, int(section.originalLength)).arg(section.originalLength);
            else {
                size = tr("%2 / %1 byte(s)", nullptr, int(section.compressedLength))
                    .arg(section.compressedLength).arg(section.originalLength);
            }

            unsigned end = section.startAddress + qMax(section.compressedLength, 1u) - 1;
            QString address = QStringLiteral("0x%1/%2 .. 0x%3/%4  %5")
                .arg(QStringLiteral("%1").arg(section.startAddress, 4, 16, QChar('0')).toUpper())
                .arg(section.startAddress, -5, 10, QChar(' '))
                .arg(QStringLiteral("%1").arg(end, 4, 16, QChar('0')).toUpper())
                .arg(end, -5, 10, QChar(' '))
                .arg(size)
                ;

            QTreeWidgetItem* sectionItem = new QTreeWidgetItem(fileItem, QStringList() << sectionName << address);
            sectionItem->setIcon(0, sectionIcon);

            for (const auto& jt : section.symbols) {
                QString addr = QStringLiteral("0x%1/%2")
                    .arg(QStringLiteral("%1").arg(jt.first, 4, 16, QChar('0')).toUpper()).arg(jt.first);

                QTreeWidgetItem* symbolItem = new QTreeWidgetItem(sectionItem, QStringList() << jt.second << addr);
                symbolItem->setIcon(0, symbolIcon);

                if (it.first.isEmpty()) // FIXME: this doesn't work properly across multiple output files
                    symbolItem->setData(0, Qt::UserRole, QVariant(jt.first));
            }
        }
    }
}

MemoryMapDialog::~MemoryMapDialog()
{
}

void MemoryMapDialog::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    QVariant addr = item->data(0, Qt::UserRole);
    if (!addr.isNull()) {
        emit addressClicked(addr.toUInt());
        accept();
    }
}
