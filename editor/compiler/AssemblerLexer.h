#ifndef COMPILER_ASSEMBLERLEXER_H
#define COMPILER_ASSEMBLERLEXER_H

#include "AssemblerToken.h"
#include <QObject>

struct SourceFile;
class IErrorReporter;

class LexerError
{
};

class AssemblerLexer : public QObject
{
    Q_OBJECT

public:
    AssemblerLexer(const SourceFile* file, const QByteArray& fileData, IErrorReporter* reporter);
    ~AssemblerLexer() override;

    void save();
    void restore();
    void forget();

    const Token& nextToken();
    const Token& lastToken() const { return mToken; }

private:
    IErrorReporter* mReporter;
    const SourceFile* mFile;
    const char* mSource;
    const char* mSavedSource;
    const char* mEnd;
    int mLine;
    int mSavedLine;
    Token mToken;
    Token mSavedToken;

    int readToken();

    void readHexNumber();
    void readBinNumber();
    void readDecNumber();

    void readStringLiteral();

    void skipLineComment();
    void skipMultilineComment();

    void error(int line, const QString& message);

    Q_DISABLE_COPY(AssemblerLexer)
};

#endif
