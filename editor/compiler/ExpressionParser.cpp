#include "AssemblerParser.h"
#include "AssemblerLexer.h"
#include "AssemblerToken.h"
#include "AssemblerContext.h"
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

            std::unique_ptr<Expression> expr;
            const std::shared_ptr<Value>& value = mContext->getVariable(lastTokenText());
            if (value)
                expr.reset(new MacroVariableExpression(lastToken(), value));
            else
                expr.reset(new IdentifierExpression(lastToken()));

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

        case T_EXCLAMATION: {
            Token token = lastToken();
            auto operand = parseAtomicExpression(nextToken(), true);
            if (!operand)
                return nullptr;
            return std::unique_ptr<Expression>{new LogicNotExpression(token, std::move(operand))};
        }

        case T_TILDE: {
            Token token = lastToken();
            auto operand = parseAtomicExpression(nextToken(), true);
            if (!operand)
                return nullptr;
            return std::unique_ptr<Expression>{new BitwiseNotExpression(token, std::move(operand))};
        }
    }

    return parseAtomicExpression(tokenId, unambiguous);
}

std::unique_ptr<Expression> AssemblerParser::parseMultiplicationExpression(int tokenId, bool unambiguous)
{
    auto expr = parseUnaryExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_ASTERISK || lastTokenId() == T_SLASH || lastTokenId() == T_PERCENT) {
        Token token = lastToken();

        auto op2 = parseUnaryExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_ASTERISK: expr.reset(new MultiplyExpression(token, std::move(expr), std::move(op2))); break;
            case T_SLASH: expr.reset(new DivideExpression(token, std::move(expr), std::move(op2))); break;
            case T_PERCENT: expr.reset(new RemainderExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseAdditionExpression(int tokenId, bool unambiguous)
{
    auto expr = parseMultiplicationExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_PLUS || lastTokenId() == T_MINUS) {
        Token token = lastToken();

        auto op2 = parseMultiplicationExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_PLUS: expr.reset(new AddExpression(token, std::move(expr), std::move(op2))); break;
            case T_MINUS: expr.reset(new SubtractExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseShiftExpression(int tokenId, bool unambiguous)
{
    auto expr = parseAdditionExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_SHL || lastTokenId() == T_SHR) {
        Token token = lastToken();

        auto op2 = parseAdditionExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_SHL: expr.reset(new ShiftLeftExpression(token, std::move(expr), std::move(op2))); break;
            case T_SHR: expr.reset(new ShiftRightExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseRelationalExpression(int tokenId, bool unambiguous)
{
    auto expr = parseShiftExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_LESS || lastTokenId() == T_LESS_EQUAL
            || lastTokenId() == T_GREATER || lastTokenId() == T_GREATER_EQUAL) {
        Token token = lastToken();

        auto op2 = parseShiftExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_LESS: expr.reset(new LessExpression(token, std::move(expr), std::move(op2))); break;
            case T_LESS_EQUAL: expr.reset(new LessEqualExpression(token, std::move(expr), std::move(op2))); break;
            case T_GREATER: expr.reset(new GreaterExpression(token, std::move(expr), std::move(op2))); break;
            case T_GREATER_EQUAL: expr.reset(new GreaterEqualExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseEqualityExpression(int tokenId, bool unambiguous)
{
    auto expr = parseRelationalExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_EQUAL || lastTokenId() == T_NOT_EQUAL) {
        Token token = lastToken();

        auto op2 = parseRelationalExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        switch (token.id) {
            case T_EQUAL: expr.reset(new EqualExpression(token, std::move(expr), std::move(op2))); break;
            case T_NOT_EQUAL: expr.reset(new NotEqualExpression(token, std::move(expr), std::move(op2))); break;
        }
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseBitwiseAndExpression(int tokenId, bool unambiguous)
{
    auto expr = parseEqualityExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_AMPERSAND) {
        Token token = lastToken();

        auto op2 = parseEqualityExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        expr.reset(new BitwiseAndExpression(token, std::move(expr), std::move(op2)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseBitwiseXorExpression(int tokenId, bool unambiguous)
{
    auto expr = parseBitwiseAndExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_CARET) {
        Token token = lastToken();

        auto op2 = parseBitwiseAndExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        expr.reset(new BitwiseXorExpression(token, std::move(expr), std::move(op2)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseBitwiseOrExpression(int tokenId, bool unambiguous)
{
    auto expr = parseBitwiseXorExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_VERTICALBAR) {
        Token token = lastToken();

        auto op2 = parseBitwiseXorExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        expr.reset(new BitwiseOrExpression(token, std::move(expr), std::move(op2)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseLogicalAndExpression(int tokenId, bool unambiguous)
{
    auto expr = parseBitwiseOrExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_LOGIC_AND) {
        Token token = lastToken();

        auto op2 = parseBitwiseOrExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        expr.reset(new LogicalAndExpression(token, std::move(expr), std::move(op2)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseLogicalOrExpression(int tokenId, bool unambiguous)
{
    auto expr = parseLogicalAndExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    while (lastTokenId() == T_LOGIC_OR) {
        Token token = lastToken();

        auto op2 = parseLogicalAndExpression(nextToken(), true);
        if (!op2)
            return nullptr;

        expr.reset(new LogicalOrExpression(token, std::move(expr), std::move(op2)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseConditionalExpression(int tokenId, bool unambiguous)
{
    auto expr = parseLogicalOrExpression(tokenId, unambiguous);
    if (!expr)
        return nullptr;

    if (lastTokenId() == T_QUESTION) {
        Token token = lastToken();

        auto opThen = parseExpression(nextToken(), true);
        if (!opThen)
            return nullptr;

        if (lastTokenId() != T_COLON) {
            mExpressionError = tr("expected ':'");
            return nullptr;
        }

        auto opElse = parseConditionalExpression(nextToken(), true);
        if (!opElse)
            return nullptr;

        expr.reset(new ConditionalExpression(token, std::move(expr), std::move(opThen), std::move(opElse)));
    }

    return expr;
}

std::unique_ptr<Expression> AssemblerParser::parseExpression(int tokenId, bool unambiguous)
{
    return parseConditionalExpression(tokenId, unambiguous);
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
