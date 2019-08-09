#ifndef COMPILER_ASSEMBLERTOKEN_H
#define COMPILER_ASSEMBLERTOKEN_H

#include <QtGlobal>
#include <string>

class File;

enum TokenID
{
    T_EOF = 0,
    T_EOL,
    T_IDENTIFIER,
    T_NUMBER,
    T_STRING,
    T_LABEL,
    T_LOCAL_LABEL,
    T_AT,
    T_COMMA,
    T_QUESTION,
    T_COLON,
    T_LPAREN,
    T_RPAREN,
    T_LBRACKET,
    T_RBRACKET,
    T_LCURLY,
    T_RCURLY,
    T_AMPERSAND,
    T_LOGIC_AND,
    T_VERTICALBAR,
    T_LOGIC_OR,
    T_CARET,
    T_TILDE,
    T_PLUS,
    T_MINUS,
    T_ASTERISK,
    T_SLASH,
    T_PERCENT,
    T_ASSIGN,
    T_EXCLAMATION,
    T_EQUAL,
    T_NOT_EQUAL,
    T_LESS,
    T_LESS_EQUAL,
    T_SHL,
    T_GREATER,
    T_GREATER_EQUAL,
    T_SHR,
};

struct Token
{
    File* file = nullptr;
    int line = 0;
    int id = 0;
    std::string text;
    quint32 number = 0;
};

#endif