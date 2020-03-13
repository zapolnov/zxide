#ifndef COMPILER_ASSEMBLERLEXER_H
#define COMPILER_ASSEMBLERLEXER_H

#include "AssemblerToken.h"
#include <QObject>

struct SourceFile;
class IErrorReporter;

class LexerError
{
};

class IAssemblerLexer
{
public:
    virtual ~IAssemblerLexer() = default;
    virtual const Token& nextToken() = 0;
    virtual const Token& lastToken() const = 0;
    virtual void save() = 0;
    virtual void restore() = 0;
    virtual void forget() = 0;
};

class AssemblerLexer : public QObject, public IAssemblerLexer
{
    Q_OBJECT

public:
    AssemblerLexer(const SourceFile* file, const QByteArray& fileData, IErrorReporter* reporter);
    ~AssemblerLexer() override;

    void save() override;
    void restore() override;
    void forget() override;

    const Token& nextToken() override;
    const Token& lastToken() const override { return mToken; }

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
