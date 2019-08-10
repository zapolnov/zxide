// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "ProgramSection.h"
#include "AssemblerParser.h"
#include "AssemblerToken.h"
#include "Util.h"

#ifdef emit
#undef emit
#endif

bool AssemblerParser::parseOpcode_generated(const std::string& opcode)
{
    unsigned literal1, literal2;
    Token token = lastToken();
    if (opcode == "adc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<ADC_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADC_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADC_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "add") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<ADD_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADD_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADD_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_IX>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_IY>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "and") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<AND_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<AND_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<AND_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "bit") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_0_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_0_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_1_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_1_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_2_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_2_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_3_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_3_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_4_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_4_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_5_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_5_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_6_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_6_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_7_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_7_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "call") {
        nextToken();
        if (expectWordLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CALL_nn>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_C_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "m") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_M_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_NC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_NZ_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "p") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_P_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "pe") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_PE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "po") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_PO_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_Z_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ccf") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CCF>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cp") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CP_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<CP_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<CP_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "cpd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpdr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpl") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPL>(token);
            return true;
        }
        return false;
    }
    if (opcode == "daa") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<DAA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "dec") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<DEC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<DEC_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<DEC_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_SP>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "di") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<DI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "djnz") {
        nextToken();
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DJNZ_n>(token, literal1);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ei") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<EI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ex") {
        nextToken();
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_HL>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_IX>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_IY>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af'") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<EX_AF_AFs>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<EX_DE_HL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "exx") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<EXX>(token);
            return true;
        }
        return false;
    }
    if (opcode == "halt") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<HALT>(token);
            return true;
        }
        return false;
    }
    if (opcode == "im") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_0>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_1>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_2>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "in") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_A_mn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_A_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_B_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_C_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_D_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_E_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_H_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_L_mC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "inc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<INC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<INC_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<INC_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_SP>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ind") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<IND>(token);
            return true;
        }
        return false;
    }
    if (opcode == "indr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ini") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "inir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "jp") {
        nextToken();
        if (expectWordLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<JP_nn>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_C_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "m") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_M_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_NC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_NZ_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "p") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_P_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "pe") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_PE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "po") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_PO_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_Z_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mIX>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mIY>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "jr") {
        nextToken();
        if (expectRelativeByteOffset(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<JR_off>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_C_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_NC_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_NZ_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_Z_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ld") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mBC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mDE>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "i") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_I>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "r") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_R>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mBC_A>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mDE_A>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (expectByteLiteral(&literal1)) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_n>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_A>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_B>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_C>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_D>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_E>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_H>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_L>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_COMMA) {
                                nextToken();
                                if (expectByteLiteral(&literal2)) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_n>(token, literal1, literal2);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_A>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_B>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_C>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_D>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_E>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_H>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_L>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_COMMA) {
                                nextToken();
                                if (expectByteLiteral(&literal2)) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_n>(token, literal1, literal2);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_A>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_B>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_C>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_D>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_E>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_H>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_L>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (expectWordLiteral(&literal1)) {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_A>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_BC>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_DE>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_HL>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_SP>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_IX>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_IY>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_BC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_BC_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_DE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_DE_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_HL_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_HL_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_SP_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_IX>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_IY>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "i") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_I_A>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_IX_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_IX_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_IY_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_IY_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "r") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_R_A>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_B_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_B_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_B_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_C_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_C_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_C_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_D_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_D_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_D_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_E_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_E_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_E_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_H_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_H_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_H_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_L_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_L_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_L_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ldd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "lddr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ldi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ldir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "neg") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<NEG>(token);
            return true;
        }
        return false;
    }
    if (opcode == "nop") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<NOP>(token);
            return true;
        }
        return false;
    }
    if (opcode == "or") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<OR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OR_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OR_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "otdr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OTDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "otir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OTIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "out") {
        nextToken();
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (expectByteLiteral(&literal1)) {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mn_A>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_A>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_B>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_C>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_D>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_E>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_H>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_L>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "outd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OUTD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "outi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OUTI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "pop") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_AF>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "push") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_AF>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "res") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_0_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_0_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_1_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_1_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_2_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_2_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_3_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_3_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_4_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_4_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_5_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_5_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_6_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_6_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_7_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_7_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ret") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RET>(token);
            return true;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "m") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_M>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_NC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_NZ>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "p") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_P>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "pe") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_PE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "po") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_PO>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RET_Z>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "reti") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RETI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "retn") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RETN>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rl") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RL_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RL_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RL_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "rla") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rlc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RLC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RLC_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RLC_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "rlca") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLCA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rld") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rr") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RR_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RR_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "rra") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rrc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RRC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RRC_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RRC_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "rrca") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRCA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rrd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rst") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x00) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_00>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x08) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_08>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x10) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_10>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x18) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_18>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x20) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_20>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x28) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_28>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x30) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_30>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x38) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_38>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "sbc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SBC_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SBC_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SBC_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "scf") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<SCF>(token);
            return true;
        }
        return false;
    }
    if (opcode == "set") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_0_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_0_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_1_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_1_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_2_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_2_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_3_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_3_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_4_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_4_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_5_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_5_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_6_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_6_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_7_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_7_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "sla") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SLA_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SLA_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SLA_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "sra") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SRA_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRA_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRA_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "srl") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SRL_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRL_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRL_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "sub") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SUB_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SUB_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SUB_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "xor") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<XOR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<XOR_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<XOR_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
    return false;
}
