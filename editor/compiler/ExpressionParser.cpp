#include "AssemblerParser.h"
#include "AssemblerToken.h"
#include "Expression.h"

bool AssemblerParser::parseExpression(std::unique_ptr<Expression>* out)
{
    // FIXME

    if (lastTokenId() == T_NUMBER) {
        *out = std::make_unique<ConstantExpression>(lastToken(), lastToken().number);
        nextToken();
        return true;
    }

    return false;
}
