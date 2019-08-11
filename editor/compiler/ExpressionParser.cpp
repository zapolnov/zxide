#include "AssemblerParser.h"
#include "AssemblerLexer.h"
#include "AssemblerToken.h"
#include "Expression.h"

std::unique_ptr<Expression> AssemblerParser::parseAtomicExpression(int tokenId, bool allowParen)
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

        case T_LPAREN:
            if (allowParen) {
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

std::unique_ptr<Expression> AssemblerParser::parseUnaryExpression(int tokenId, bool allowParen)
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

    return parseAtomicExpression(tokenId, allowParen);
}

std::unique_ptr<Expression> AssemblerParser::parseExpression(int tokenId, bool allowParen)
{
    return parseUnaryExpression(tokenId, allowParen);
}

bool AssemblerParser::tryParseExpression(int tokenId, std::unique_ptr<Expression>* out, bool allowParen)
{
    mLexer->save();

    auto expr = parseExpression(tokenId, allowParen);
    if (!expr) {
        mLexer->restore();
        return false;
    }

    mLexer->forget();
    *out = std::move(expr);
    return true;
}
