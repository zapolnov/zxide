#include "AssemblerParser.h"
#include "AssemblerLexer.h"
#include "AssemblerToken.h"
#include "Expression.h"
#include "Util.h"
#include <unordered_set>

static std::unordered_set<std::string> registerNames = {
        "a",
        "b",
        "c",
        "d",
        "e",
        "h",
        "l",
        "i",
        "r",
        "bc",
        "de",
        "hl",
        "sp",
        "ix",
        "iy",
        "af",
        "af'",
    };

static std::unordered_set<std::string> conditionNames = {
        "c",
        "nc",
        "z",
        "nz",
        "m",
        "p",
        "pe",
        "po",
    };

std::unique_ptr<Expression> AssemblerParser::parseAtomicExpression(int tokenId, bool unambiguous)
{
    switch (tokenId) {
        case T_NUMBER: {
            std::unique_ptr<Expression> expr{new ConstantExpression(lastToken(), lastToken().number)};
            nextToken();
            return expr;
        }

        case T_DOLLAR: {
            std::unique_ptr<Expression> expr{new DollarExpression(lastToken())};
            nextToken();
            return expr;
        }

        case T_IDENTIFIER: {
            std::string lowerText = toLower(lastTokenText());
            if (!unambiguous && registerNames.find(lowerText) != registerNames.end()) {
                mExpressionError =
                    tr("'%1' is ambiguous in this context (could be expression or register)").arg(lowerText.c_str());
                return nullptr;
            }
            if (!unambiguous && conditionNames.find(lowerText) != conditionNames.end()) {
                mExpressionError =
                    tr("'%1' is ambiguous in this context (could be expression or condition)").arg(lowerText.c_str());
                return nullptr;
            }

            std::unique_ptr<Expression> expr{new IdentifierExpression(lastToken())};
            nextToken();
            return expr;
        }

        case T_LOCAL_LABEL_NAME: {
            std::string name = readLabelName(lastTokenId());
            std::unique_ptr<Expression> expr{new IdentifierExpression(lastToken(), std::move(name))};
            nextToken();
            return expr;
        }

        case T_LPAREN:
            if (unambiguous) {
                auto expr = parseExpression(nextToken(), true);
                if (!expr)
                    return nullptr;

                if (lastTokenId() != T_RPAREN) {
                    mExpressionError = tr("expected ')'");
                    return nullptr;
                }

                nextToken();
                return expr;
            }

            mExpressionError = tr("'(' is ambiguous in this context (could be expression or memory reference)");
            return nullptr;

        default:
            mExpressionError = tr("expected expression");
            return nullptr;
    }
}

std::unique_ptr<Expression> AssemblerParser::parseUnaryExpression(int tokenId, bool unambiguous)
{
    switch (tokenId) {
        case T_MINUS: {
            Token token = lastToken();
            auto operand = parseAtomicExpression(nextToken(), true);
            if (!operand)
                return nullptr;
            return std::unique_ptr<Expression>{new NegateExpression(token, std::move(operand))};
        }

        case T_PLUS:
            return parseAtomicExpression(nextToken(), true);
    }

    return parseAtomicExpression(tokenId, unambiguous);
}

std::unique_ptr<Expression> AssemblerParser::parseAdditionExpression(int tokenId, bool unambiguous)
{
    auto expr = parseUnaryExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_PLUS || lastTokenId() == T_MINUS) {
        Token token = lastToken();

        auto op2 = parseUnaryExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_PLUS: expr.reset(new AddExpression(token, std::move(expr), std::move(op2))); break;
            case T_MINUS: expr.reset(new SubtractExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseExpression(int tokenId, bool unambiguous)
{
    return parseAdditionExpression(tokenId, unambiguous);
}

bool AssemblerParser::tryParseExpression(int tokenId, std::unique_ptr<Expression>* out, bool unambiguous)
{
    mLexer->save();

    auto expr = parseExpression(tokenId, unambiguous);
    if (!expr) {
        mLexer->restore();
        return false;
    }

    mLexer->forget();
    *out = std::move(expr);
    return true;
}
