// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "ProgramSection.h"
#include "AssemblerParser.h"
#include "AssemblerToken.h"
#include <unordered_map>

#ifdef emit
#undef emit
#endif

class Z80OpcodeParser
{
private:
    AssemblerParser* mParser;
    ProgramSection* mSection;
    const Token& mToken;

    bool eol() const { return mParser->matchEol(); }
    bool token(int tok) const { return mParser->matchToken(tok); }
    bool ident(const char* id) const { return mParser->matchIdentifier(id); }
    bool number(quint32 value) const { return mParser->matchNumber(value); }

    bool byteLiteral(unsigned* value) const { return mParser->expectByteLiteral(value); }
    bool byteOffset(unsigned* value) const { return mParser->expectRelativeByteOffset(value); }
    bool wordLiteral(unsigned* value) const { return mParser->expectWordLiteral(value); }

public:
    explicit Z80OpcodeParser(AssemblerParser* parser)
        : mParser(parser)
        , mSection(parser->mSection)
        , mToken(parser->lastToken())
    {
        mParser->nextToken();
    }

    bool adc()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<ADC_A_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<ADC_A_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<ADC_A_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<ADC_A_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<ADC_A_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<ADC_A_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<ADC_A_L>(mToken);
                    return false;
                }
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<ADC_A_n>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADC_A_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADC_A_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADC_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADC_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADC_A_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADC_A_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADC_A_mIYn>(mToken, literal1);
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
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mSection->emit<ADC_HL_BC>(mToken);
                    return false;
                }
                if (ident("de")) {
                    if (eol())
                        return mSection->emit<ADC_HL_DE>(mToken);
                    return false;
                }
                if (ident("hl")) {
                    if (eol())
                        return mSection->emit<ADC_HL_HL>(mToken);
                    return false;
                }
                if (ident("sp")) {
                    if (eol())
                        return mSection->emit<ADC_HL_SP>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool add()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<ADD_A_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<ADD_A_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<ADD_A_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<ADD_A_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<ADD_A_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<ADD_A_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<ADD_A_L>(mToken);
                    return false;
                }
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<ADD_A_n>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADD_A_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADD_A_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADD_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADD_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<ADD_A_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADD_A_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<ADD_A_mIYn>(mToken, literal1);
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
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mSection->emit<ADD_HL_BC>(mToken);
                    return false;
                }
                if (ident("de")) {
                    if (eol())
                        return mSection->emit<ADD_HL_DE>(mToken);
                    return false;
                }
                if (ident("hl")) {
                    if (eol())
                        return mSection->emit<ADD_HL_HL>(mToken);
                    return false;
                }
                if (ident("sp")) {
                    if (eol())
                        return mSection->emit<ADD_HL_SP>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("ix")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mSection->emit<ADD_IX_BC>(mToken);
                    return false;
                }
                if (ident("de")) {
                    if (eol())
                        return mSection->emit<ADD_IX_DE>(mToken);
                    return false;
                }
                if (ident("ix")) {
                    if (eol())
                        return mSection->emit<ADD_IX_IX>(mToken);
                    return false;
                }
                if (ident("sp")) {
                    if (eol())
                        return mSection->emit<ADD_IX_SP>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("iy")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mSection->emit<ADD_IY_BC>(mToken);
                    return false;
                }
                if (ident("de")) {
                    if (eol())
                        return mSection->emit<ADD_IY_DE>(mToken);
                    return false;
                }
                if (ident("iy")) {
                    if (eol())
                        return mSection->emit<ADD_IY_IY>(mToken);
                    return false;
                }
                if (ident("sp")) {
                    if (eol())
                        return mSection->emit<ADD_IY_SP>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool and()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<AND_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<AND_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<AND_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<AND_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<AND_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<AND_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<AND_L>(mToken);
            return false;
        }
        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<AND_n>(mToken, literal1);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<AND_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<AND_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<AND_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<AND_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<AND_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<AND_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<AND_mIYn>(mToken, literal1);
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

    bool bit()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (number(0)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_0_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_0_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_0_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_0_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_0_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_0_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_0_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_0_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_0_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_0_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_0_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_0_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(1)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_1_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_1_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_1_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_1_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_1_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_1_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_1_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_1_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_1_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_1_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_1_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_1_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(2)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_2_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_2_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_2_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_2_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_2_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_2_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_2_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_2_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_2_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_2_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_2_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_2_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(3)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_3_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_3_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_3_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_3_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_3_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_3_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_3_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_3_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_3_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_3_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_3_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_3_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(4)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_4_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_4_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_4_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_4_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_4_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_4_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_4_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_4_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_4_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_4_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_4_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_4_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(5)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_5_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_5_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_5_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_5_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_5_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_5_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_5_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_5_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_5_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_5_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_5_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_5_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(6)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_6_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_6_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_6_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_6_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_6_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_6_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_6_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_6_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_6_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_6_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_6_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_6_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (number(7)) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_7_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_7_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<BIT_7_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_7_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<BIT_7_mIYn>(mToken, literal1);
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
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<BIT_7_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<BIT_7_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<BIT_7_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<BIT_7_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<BIT_7_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<BIT_7_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<BIT_7_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool call()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (wordLiteral(&literal1)) {
            if (eol())
                return mSection->emit<CALL_nn>(mToken, literal1);
            return false;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_C_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("m")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_M_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_NC_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_NZ_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("p")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_P_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("pe")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_PE_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("po")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_PO_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<CALL_Z_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool ccf()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CCF>(mToken);
        return false;
    }

    bool cp()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<CP_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<CP_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<CP_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<CP_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<CP_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<CP_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<CP_L>(mToken);
            return false;
        }
        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<CP_n>(mToken, literal1);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<CP_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<CP_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<CP_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<CP_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<CP_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<CP_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<CP_mIYn>(mToken, literal1);
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

    bool cpd()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CPD>(mToken);
        return false;
    }

    bool cpdr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CPDR>(mToken);
        return false;
    }

    bool cpi()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CPI>(mToken);
        return false;
    }

    bool cpir()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CPIR>(mToken);
        return false;
    }

    bool cpl()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<CPL>(mToken);
        return false;
    }

    bool daa()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<DAA>(mToken);
        return false;
    }

    bool dec()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<DEC_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<DEC_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<DEC_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<DEC_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<DEC_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<DEC_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<DEC_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<DEC_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<DEC_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<DEC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<DEC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<DEC_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<DEC_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<DEC_mIYn>(mToken, literal1);
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
        if (ident("ix")) {
            if (eol())
                return mSection->emit<DEC_IX>(mToken);
            return false;
        }
        if (ident("iy")) {
            if (eol())
                return mSection->emit<DEC_IY>(mToken);
            return false;
        }
        if (ident("bc")) {
            if (eol())
                return mSection->emit<DEC_BC>(mToken);
            return false;
        }
        if (ident("de")) {
            if (eol())
                return mSection->emit<DEC_DE>(mToken);
            return false;
        }
        if (ident("hl")) {
            if (eol())
                return mSection->emit<DEC_HL>(mToken);
            return false;
        }
        if (ident("sp")) {
            if (eol())
                return mSection->emit<DEC_SP>(mToken);
            return false;
        }
        return false;
    }

    bool di()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<DI>(mToken);
        return false;
    }

    bool djnz()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<DJNZ_n>(mToken, literal1);
            return false;
        }
        return false;
    }

    bool ei()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<EI>(mToken);
        return false;
    }

    bool ex()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (token(T_LPAREN)) {
            if (ident("sp")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("hl")) {
                            if (eol())
                                return mSection->emit<EX_mSP_HL>(mToken);
                            return false;
                        }
                        if (ident("ix")) {
                            if (eol())
                                return mSection->emit<EX_mSP_IX>(mToken);
                            return false;
                        }
                        if (ident("iy")) {
                            if (eol())
                                return mSection->emit<EX_mSP_IY>(mToken);
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
        if (ident("af")) {
            if (token(T_COMMA)) {
                if (ident("af'")) {
                    if (eol())
                        return mSection->emit<EX_AF_AFs>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("de")) {
            if (token(T_COMMA)) {
                if (ident("hl")) {
                    if (eol())
                        return mSection->emit<EX_DE_HL>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool exx()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<EXX>(mToken);
        return false;
    }

    bool halt()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<HALT>(mToken);
        return false;
    }

    bool im()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (number(0)) {
            if (eol())
                return mSection->emit<IM_0>(mToken);
            return false;
        }
        if (number(1)) {
            if (eol())
                return mSection->emit<IM_1>(mToken);
            return false;
        }
        if (number(2)) {
            if (eol())
                return mSection->emit<IM_2>(mToken);
            return false;
        }
        return false;
    }

    bool in()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_A_mn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_A_mC>(mToken);
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
        if (ident("b")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_B_mC>(mToken);
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
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_C_mC>(mToken);
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
        if (ident("d")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_D_mC>(mToken);
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
        if (ident("e")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_E_mC>(mToken);
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
        if (ident("h")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_H_mC>(mToken);
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
        if (ident("l")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<IN_L_mC>(mToken);
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

    bool inc()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<INC_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<INC_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<INC_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<INC_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<INC_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<INC_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<INC_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<INC_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<INC_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<INC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<INC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<INC_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<INC_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<INC_mIYn>(mToken, literal1);
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
        if (ident("ix")) {
            if (eol())
                return mSection->emit<INC_IX>(mToken);
            return false;
        }
        if (ident("iy")) {
            if (eol())
                return mSection->emit<INC_IY>(mToken);
            return false;
        }
        if (ident("bc")) {
            if (eol())
                return mSection->emit<INC_BC>(mToken);
            return false;
        }
        if (ident("de")) {
            if (eol())
                return mSection->emit<INC_DE>(mToken);
            return false;
        }
        if (ident("hl")) {
            if (eol())
                return mSection->emit<INC_HL>(mToken);
            return false;
        }
        if (ident("sp")) {
            if (eol())
                return mSection->emit<INC_SP>(mToken);
            return false;
        }
        return false;
    }

    bool ind()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<IND>(mToken);
        return false;
    }

    bool indr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<INDR>(mToken);
        return false;
    }

    bool ini()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<INI>(mToken);
        return false;
    }

    bool inir()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<INIR>(mToken);
        return false;
    }

    bool jp()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (wordLiteral(&literal1)) {
            if (eol())
                return mSection->emit<JP_nn>(mToken, literal1);
            return false;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_C_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("m")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_M_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_NC_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_NZ_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("p")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_P_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("pe")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_PE_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("po")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_PO_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<JP_Z_nn>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<JP_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<JP_mIX>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<JP_mIY>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool jr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (byteOffset(&literal1)) {
            if (eol())
                return mSection->emit<JR_off>(mToken, literal1);
            return false;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (byteOffset(&literal1)) {
                    if (eol())
                        return mSection->emit<JR_C_off>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (byteOffset(&literal1)) {
                    if (eol())
                        return mSection->emit<JR_NC_off>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (byteOffset(&literal1)) {
                    if (eol())
                        return mSection->emit<JR_NZ_off>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (byteOffset(&literal1)) {
                    if (eol())
                        return mSection->emit<JR_Z_off>(mToken, literal1);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool ld()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("bc")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mBC>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("de")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mDE>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mnn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_A_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_A_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_A_mIYn>(mToken, literal1);
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
                if (ident("i")) {
                    if (eol())
                        return mSection->emit<LD_A_I>(mToken);
                    return false;
                }
                if (ident("r")) {
                    if (eol())
                        return mSection->emit<LD_A_R>(mToken);
                    return false;
                }
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_A_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_A_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_A_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_A_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_A_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_A_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_A_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_A_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("bc")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mBC_A>(mToken);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("de")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mDE_A>(mToken);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&literal1)) {
                            if (eol())
                                return mSection->emit<LD_mHL_n>(mToken, literal1);
                            return false;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mHL_A>(mToken);
                            return false;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mSection->emit<LD_mHL_B>(mToken);
                            return false;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mSection->emit<LD_mHL_C>(mToken);
                            return false;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mSection->emit<LD_mHL_D>(mToken);
                            return false;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mSection->emit<LD_mHL_E>(mToken);
                            return false;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mSection->emit<LD_mHL_H>(mToken);
                            return false;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mSection->emit<LD_mHL_L>(mToken);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&literal2)) {
                            if (eol())
                                return mSection->emit<LD_mIXn_n>(mToken, literal1, literal2);
                            return false;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_A>(mToken, literal1);
                            return false;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_B>(mToken, literal1);
                            return false;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_C>(mToken, literal1);
                            return false;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_D>(mToken, literal1);
                            return false;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_E>(mToken, literal1);
                            return false;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_H>(mToken, literal1);
                            return false;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mSection->emit<LD_mIXn_L>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&literal2)) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_n>(mToken, literal1, literal2);
                                    return false;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_A>(mToken, literal1);
                                    return false;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_B>(mToken, literal1);
                                    return false;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_C>(mToken, literal1);
                                    return false;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_D>(mToken, literal1);
                                    return false;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_E>(mToken, literal1);
                                    return false;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_H>(mToken, literal1);
                                    return false;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_L>(mToken, literal1);
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
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&literal2)) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_n>(mToken, literal1, literal2);
                                    return false;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_A>(mToken, literal1);
                                    return false;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_B>(mToken, literal1);
                                    return false;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_C>(mToken, literal1);
                                    return false;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_D>(mToken, literal1);
                                    return false;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_E>(mToken, literal1);
                                    return false;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_H>(mToken, literal1);
                                    return false;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mSection->emit<LD_mIXn_L>(mToken, literal1);
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
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&literal2)) {
                            if (eol())
                                return mSection->emit<LD_mIYn_n>(mToken, literal1, literal2);
                            return false;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_A>(mToken, literal1);
                            return false;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_B>(mToken, literal1);
                            return false;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_C>(mToken, literal1);
                            return false;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_D>(mToken, literal1);
                            return false;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_E>(mToken, literal1);
                            return false;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_H>(mToken, literal1);
                            return false;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mSection->emit<LD_mIYn_L>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&literal2)) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_n>(mToken, literal1, literal2);
                                    return false;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_A>(mToken, literal1);
                                    return false;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_B>(mToken, literal1);
                                    return false;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_C>(mToken, literal1);
                                    return false;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_D>(mToken, literal1);
                                    return false;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_E>(mToken, literal1);
                                    return false;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_H>(mToken, literal1);
                                    return false;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_L>(mToken, literal1);
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
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&literal2)) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_n>(mToken, literal1, literal2);
                                    return false;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_A>(mToken, literal1);
                                    return false;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_B>(mToken, literal1);
                                    return false;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_C>(mToken, literal1);
                                    return false;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_D>(mToken, literal1);
                                    return false;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_E>(mToken, literal1);
                                    return false;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_H>(mToken, literal1);
                                    return false;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mSection->emit<LD_mIYn_L>(mToken, literal1);
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
            if (wordLiteral(&literal1)) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<LD_mnn_A>(mToken, literal1);
                            return false;
                        }
                        if (ident("bc")) {
                            if (eol())
                                return mSection->emit<LD_mnn_BC>(mToken, literal1);
                            return false;
                        }
                        if (ident("de")) {
                            if (eol())
                                return mSection->emit<LD_mnn_DE>(mToken, literal1);
                            return false;
                        }
                        if (ident("hl")) {
                            if (eol())
                                return mSection->emit<LD_mnn_HL>(mToken, literal1);
                            return false;
                        }
                        if (ident("sp")) {
                            if (eol())
                                return mSection->emit<LD_mnn_SP>(mToken, literal1);
                            return false;
                        }
                        if (ident("ix")) {
                            if (eol())
                                return mSection->emit<LD_mnn_IX>(mToken, literal1);
                            return false;
                        }
                        if (ident("iy")) {
                            if (eol())
                                return mSection->emit<LD_mnn_IY>(mToken, literal1);
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
        if (ident("bc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_BC_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_BC_mnn>(mToken, literal1);
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
        if (ident("de")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_DE_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_DE_mnn>(mToken, literal1);
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
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_HL_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_HL_mnn>(mToken, literal1);
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
        if (ident("sp")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_SP_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_SP_mnn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (ident("hl")) {
                    if (eol())
                        return mSection->emit<LD_SP_HL>(mToken);
                    return false;
                }
                if (ident("ix")) {
                    if (eol())
                        return mSection->emit<LD_SP_IX>(mToken);
                    return false;
                }
                if (ident("iy")) {
                    if (eol())
                        return mSection->emit<LD_SP_IY>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("i")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_I_A>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("ix")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_IX_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_IX_mnn>(mToken, literal1);
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
        if (ident("iy")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_IY_nn>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_IY_mnn>(mToken, literal1);
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
        if (ident("r")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_R_A>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("b")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_B_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_B_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_B_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_B_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_B_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_B_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_B_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_B_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_B_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_B_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_B_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_B_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_B_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_B_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_B_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_C_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_C_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_C_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_C_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_C_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_C_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_C_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_C_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_C_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_C_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_C_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_C_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_C_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_C_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_C_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("d")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_D_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_D_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_D_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_D_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_D_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_D_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_D_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_D_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_D_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_D_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_D_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_D_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_D_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_D_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_D_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("e")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_E_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_E_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_E_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_E_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_E_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_E_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_E_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_E_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_E_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_E_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_E_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_E_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_E_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_E_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_E_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("h")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_H_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_H_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_H_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_H_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_H_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_H_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_H_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_H_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_H_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_H_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_H_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_H_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_H_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_H_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_H_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        if (ident("l")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_L_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_L_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_L_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_L_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<LD_L_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_L_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<LD_L_mIYn>(mToken, literal1);
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
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<LD_L_n>(mToken, literal1);
                    return false;
                }
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<LD_L_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<LD_L_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<LD_L_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<LD_L_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<LD_L_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<LD_L_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<LD_L_L>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool ldd()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<LDD>(mToken);
        return false;
    }

    bool lddr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<LDDR>(mToken);
        return false;
    }

    bool ldi()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<LDI>(mToken);
        return false;
    }

    bool ldir()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<LDIR>(mToken);
        return false;
    }

    bool neg()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<NEG>(mToken);
        return false;
    }

    bool nop()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<NOP>(mToken);
        return false;
    }

    bool or()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<OR_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<OR_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<OR_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<OR_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<OR_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<OR_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<OR_L>(mToken);
            return false;
        }
        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<OR_n>(mToken, literal1);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<OR_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<OR_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<OR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<OR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<OR_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<OR_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<OR_mIYn>(mToken, literal1);
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

    bool otdr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<OTDR>(mToken);
        return false;
    }

    bool otir()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<OTIR>(mToken);
        return false;
    }

    bool out()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (token(T_LPAREN)) {
            if (byteLiteral(&literal1)) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<OUT_mn_A>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("c")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mSection->emit<OUT_mC_A>(mToken);
                            return false;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mSection->emit<OUT_mC_B>(mToken);
                            return false;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mSection->emit<OUT_mC_C>(mToken);
                            return false;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mSection->emit<OUT_mC_D>(mToken);
                            return false;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mSection->emit<OUT_mC_E>(mToken);
                            return false;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mSection->emit<OUT_mC_H>(mToken);
                            return false;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mSection->emit<OUT_mC_L>(mToken);
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

    bool outd()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<OUTD>(mToken);
        return false;
    }

    bool outi()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<OUTI>(mToken);
        return false;
    }

    bool pop()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("ix")) {
            if (eol())
                return mSection->emit<POP_IX>(mToken);
            return false;
        }
        if (ident("iy")) {
            if (eol())
                return mSection->emit<POP_IY>(mToken);
            return false;
        }
        if (ident("bc")) {
            if (eol())
                return mSection->emit<POP_BC>(mToken);
            return false;
        }
        if (ident("de")) {
            if (eol())
                return mSection->emit<POP_DE>(mToken);
            return false;
        }
        if (ident("hl")) {
            if (eol())
                return mSection->emit<POP_HL>(mToken);
            return false;
        }
        if (ident("af")) {
            if (eol())
                return mSection->emit<POP_AF>(mToken);
            return false;
        }
        return false;
    }

    bool push()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("ix")) {
            if (eol())
                return mSection->emit<PUSH_IX>(mToken);
            return false;
        }
        if (ident("iy")) {
            if (eol())
                return mSection->emit<PUSH_IY>(mToken);
            return false;
        }
        if (ident("bc")) {
            if (eol())
                return mSection->emit<PUSH_BC>(mToken);
            return false;
        }
        if (ident("de")) {
            if (eol())
                return mSection->emit<PUSH_DE>(mToken);
            return false;
        }
        if (ident("hl")) {
            if (eol())
                return mSection->emit<PUSH_HL>(mToken);
            return false;
        }
        if (ident("af")) {
            if (eol())
                return mSection->emit<PUSH_AF>(mToken);
            return false;
        }
        return false;
    }

    bool res()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (number(0)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_0_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_0_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_0_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_0_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_0_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_0_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_0_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_0_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_0_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_0_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_0_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_0_mIYn>(mToken, literal1);
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
        if (number(1)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_1_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_1_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_1_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_1_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_1_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_1_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_1_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_1_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_1_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_1_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_1_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_1_mIYn>(mToken, literal1);
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
        if (number(2)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_2_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_2_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_2_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_2_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_2_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_2_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_2_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_2_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_2_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_2_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_2_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_2_mIYn>(mToken, literal1);
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
        if (number(3)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_3_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_3_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_3_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_3_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_3_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_3_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_3_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_3_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_3_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_3_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_3_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_3_mIYn>(mToken, literal1);
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
        if (number(4)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_4_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_4_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_4_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_4_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_4_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_4_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_4_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_4_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_4_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_4_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_4_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_4_mIYn>(mToken, literal1);
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
        if (number(5)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_5_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_5_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_5_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_5_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_5_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_5_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_5_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_5_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_5_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_5_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_5_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_5_mIYn>(mToken, literal1);
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
        if (number(6)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_6_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_6_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_6_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_6_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_6_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_6_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_6_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_6_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_6_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_6_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_6_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_6_mIYn>(mToken, literal1);
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
        if (number(7)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<RES_7_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<RES_7_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<RES_7_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<RES_7_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<RES_7_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<RES_7_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<RES_7_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_7_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_7_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RES_7_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_7_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<RES_7_mIYn>(mToken, literal1);
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

    bool ret()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RET>(mToken);
        if (ident("c")) {
            if (eol())
                return mSection->emit<RET_C>(mToken);
            return false;
        }
        if (ident("m")) {
            if (eol())
                return mSection->emit<RET_M>(mToken);
            return false;
        }
        if (ident("nc")) {
            if (eol())
                return mSection->emit<RET_NC>(mToken);
            return false;
        }
        if (ident("nz")) {
            if (eol())
                return mSection->emit<RET_NZ>(mToken);
            return false;
        }
        if (ident("p")) {
            if (eol())
                return mSection->emit<RET_P>(mToken);
            return false;
        }
        if (ident("pe")) {
            if (eol())
                return mSection->emit<RET_PE>(mToken);
            return false;
        }
        if (ident("po")) {
            if (eol())
                return mSection->emit<RET_PO>(mToken);
            return false;
        }
        if (ident("z")) {
            if (eol())
                return mSection->emit<RET_Z>(mToken);
            return false;
        }
        return false;
    }

    bool reti()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RETI>(mToken);
        return false;
    }

    bool retn()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RETN>(mToken);
        return false;
    }

    bool rl()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<RL_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<RL_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<RL_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<RL_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<RL_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<RL_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<RL_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RL_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RL_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RL_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RL_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RL_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RL_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RL_mIYn>(mToken, literal1);
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

    bool rla()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RLA>(mToken);
        return false;
    }

    bool rlc()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<RLC_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<RLC_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<RLC_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<RLC_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<RLC_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<RLC_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<RLC_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RLC_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RLC_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RLC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RLC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RLC_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RLC_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RLC_mIYn>(mToken, literal1);
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

    bool rlca()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RLCA>(mToken);
        return false;
    }

    bool rld()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RLD>(mToken);
        return false;
    }

    bool rr()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<RR_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<RR_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<RR_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<RR_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<RR_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<RR_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<RR_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RR_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RR_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RR_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RR_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RR_mIYn>(mToken, literal1);
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

    bool rra()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RRA>(mToken);
        return false;
    }

    bool rrc()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<RRC_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<RRC_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<RRC_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<RRC_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<RRC_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<RRC_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<RRC_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RRC_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RRC_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RRC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RRC_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<RRC_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RRC_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<RRC_mIYn>(mToken, literal1);
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

    bool rrca()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RRCA>(mToken);
        return false;
    }

    bool rrd()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<RRD>(mToken);
        return false;
    }

    bool rst()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (number(0x00)) {
            if (eol())
                return mSection->emit<RST_00>(mToken);
            return false;
        }
        if (number(0x08)) {
            if (eol())
                return mSection->emit<RST_08>(mToken);
            return false;
        }
        if (number(0x10)) {
            if (eol())
                return mSection->emit<RST_10>(mToken);
            return false;
        }
        if (number(0x18)) {
            if (eol())
                return mSection->emit<RST_18>(mToken);
            return false;
        }
        if (number(0x20)) {
            if (eol())
                return mSection->emit<RST_20>(mToken);
            return false;
        }
        if (number(0x28)) {
            if (eol())
                return mSection->emit<RST_28>(mToken);
            return false;
        }
        if (number(0x30)) {
            if (eol())
                return mSection->emit<RST_30>(mToken);
            return false;
        }
        if (number(0x38)) {
            if (eol())
                return mSection->emit<RST_38>(mToken);
            return false;
        }
        return false;
    }

    bool sbc()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SBC_A_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SBC_A_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SBC_A_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SBC_A_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SBC_A_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SBC_A_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SBC_A_L>(mToken);
                    return false;
                }
                if (byteLiteral(&literal1)) {
                    if (eol())
                        return mSection->emit<SBC_A_n>(mToken, literal1);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SBC_A_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SBC_A_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SBC_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SBC_A_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SBC_A_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SBC_A_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SBC_A_mIYn>(mToken, literal1);
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
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mSection->emit<SBC_HL_BC>(mToken);
                    return false;
                }
                if (ident("de")) {
                    if (eol())
                        return mSection->emit<SBC_HL_DE>(mToken);
                    return false;
                }
                if (ident("hl")) {
                    if (eol())
                        return mSection->emit<SBC_HL_HL>(mToken);
                    return false;
                }
                if (ident("sp")) {
                    if (eol())
                        return mSection->emit<SBC_HL_SP>(mToken);
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool scf()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (eol())
            return mSection->emit<SCF>(mToken);
        return false;
    }

    bool set()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (number(0)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_0_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_0_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_0_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_0_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_0_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_0_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_0_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_0_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_0_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_0_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_0_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_0_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_0_mIYn>(mToken, literal1);
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
        if (number(1)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_1_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_1_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_1_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_1_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_1_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_1_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_1_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_1_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_1_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_1_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_1_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_1_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_1_mIYn>(mToken, literal1);
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
        if (number(2)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_2_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_2_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_2_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_2_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_2_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_2_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_2_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_2_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_2_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_2_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_2_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_2_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_2_mIYn>(mToken, literal1);
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
        if (number(3)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_3_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_3_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_3_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_3_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_3_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_3_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_3_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_3_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_3_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_3_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_3_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_3_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_3_mIYn>(mToken, literal1);
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
        if (number(4)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_4_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_4_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_4_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_4_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_4_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_4_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_4_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_4_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_4_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_4_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_4_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_4_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_4_mIYn>(mToken, literal1);
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
        if (number(5)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_5_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_5_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_5_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_5_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_5_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_5_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_5_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_5_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_5_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_5_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_5_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_5_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_5_mIYn>(mToken, literal1);
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
        if (number(6)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_6_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_6_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_6_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_6_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_6_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_6_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_6_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_6_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_6_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_6_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_6_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_6_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_6_mIYn>(mToken, literal1);
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
        if (number(7)) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mSection->emit<SET_7_A>(mToken);
                    return false;
                }
                if (ident("b")) {
                    if (eol())
                        return mSection->emit<SET_7_B>(mToken);
                    return false;
                }
                if (ident("c")) {
                    if (eol())
                        return mSection->emit<SET_7_C>(mToken);
                    return false;
                }
                if (ident("d")) {
                    if (eol())
                        return mSection->emit<SET_7_D>(mToken);
                    return false;
                }
                if (ident("e")) {
                    if (eol())
                        return mSection->emit<SET_7_E>(mToken);
                    return false;
                }
                if (ident("h")) {
                    if (eol())
                        return mSection->emit<SET_7_H>(mToken);
                    return false;
                }
                if (ident("l")) {
                    if (eol())
                        return mSection->emit<SET_7_L>(mToken);
                    return false;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_7_mHL>(mToken);
                            return false;
                        }
                        return false;
                    }
                    if (ident("ix")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_7_mIXn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_7_mIXn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (ident("iy")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SET_7_mIYn>(mToken, literal1);
                            return false;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_7_mIYn>(mToken, literal1);
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        if (token(T_MINUS)) {
                            if (byteLiteral(&literal1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mSection->emit<SET_7_mIYn>(mToken, literal1);
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

    bool sla()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<SLA_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<SLA_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<SLA_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<SLA_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<SLA_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<SLA_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<SLA_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SLA_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SLA_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SLA_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SLA_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SLA_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SLA_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SLA_mIYn>(mToken, literal1);
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

    bool sra()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<SRA_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<SRA_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<SRA_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<SRA_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<SRA_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<SRA_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<SRA_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRA_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRA_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRA_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRA_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRA_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRA_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRA_mIYn>(mToken, literal1);
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

    bool srl()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<SRL_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<SRL_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<SRL_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<SRL_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<SRL_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<SRL_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<SRL_L>(mToken);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRL_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRL_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRL_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRL_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SRL_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRL_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SRL_mIYn>(mToken, literal1);
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

    bool sub()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<SUB_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<SUB_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<SUB_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<SUB_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<SUB_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<SUB_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<SUB_L>(mToken);
            return false;
        }
        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<SUB_n>(mToken, literal1);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SUB_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SUB_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SUB_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SUB_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<SUB_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SUB_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<SUB_mIYn>(mToken, literal1);
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

    bool xor()
    {
        unsigned literal1, literal2;
        (void)literal1; (void)literal2;

        if (ident("a")) {
            if (eol())
                return mSection->emit<XOR_A>(mToken);
            return false;
        }
        if (ident("b")) {
            if (eol())
                return mSection->emit<XOR_B>(mToken);
            return false;
        }
        if (ident("c")) {
            if (eol())
                return mSection->emit<XOR_C>(mToken);
            return false;
        }
        if (ident("d")) {
            if (eol())
                return mSection->emit<XOR_D>(mToken);
            return false;
        }
        if (ident("e")) {
            if (eol())
                return mSection->emit<XOR_E>(mToken);
            return false;
        }
        if (ident("h")) {
            if (eol())
                return mSection->emit<XOR_H>(mToken);
            return false;
        }
        if (ident("l")) {
            if (eol())
                return mSection->emit<XOR_L>(mToken);
            return false;
        }
        if (byteLiteral(&literal1)) {
            if (eol())
                return mSection->emit<XOR_n>(mToken, literal1);
            return false;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<XOR_mHL>(mToken);
                    return false;
                }
                return false;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<XOR_mIXn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<XOR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<XOR_mIXn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mSection->emit<XOR_mIYn>(mToken, literal1);
                    return false;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<XOR_mIYn>(mToken, literal1);
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (token(T_MINUS)) {
                    if (byteLiteral(&literal1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mSection->emit<XOR_mIYn>(mToken, literal1);
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
};

using Func = bool (Z80OpcodeParser::*)();
static std::unordered_map<std::string, Func> opcodes = {
        { "adc", &Z80OpcodeParser::adc },
        { "add", &Z80OpcodeParser::add },
        { "and", &Z80OpcodeParser::and },
        { "bit", &Z80OpcodeParser::bit },
        { "call", &Z80OpcodeParser::call },
        { "ccf", &Z80OpcodeParser::ccf },
        { "cp", &Z80OpcodeParser::cp },
        { "cpd", &Z80OpcodeParser::cpd },
        { "cpdr", &Z80OpcodeParser::cpdr },
        { "cpi", &Z80OpcodeParser::cpi },
        { "cpir", &Z80OpcodeParser::cpir },
        { "cpl", &Z80OpcodeParser::cpl },
        { "daa", &Z80OpcodeParser::daa },
        { "dec", &Z80OpcodeParser::dec },
        { "di", &Z80OpcodeParser::di },
        { "djnz", &Z80OpcodeParser::djnz },
        { "ei", &Z80OpcodeParser::ei },
        { "ex", &Z80OpcodeParser::ex },
        { "exx", &Z80OpcodeParser::exx },
        { "halt", &Z80OpcodeParser::halt },
        { "im", &Z80OpcodeParser::im },
        { "in", &Z80OpcodeParser::in },
        { "inc", &Z80OpcodeParser::inc },
        { "ind", &Z80OpcodeParser::ind },
        { "indr", &Z80OpcodeParser::indr },
        { "ini", &Z80OpcodeParser::ini },
        { "inir", &Z80OpcodeParser::inir },
        { "jp", &Z80OpcodeParser::jp },
        { "jr", &Z80OpcodeParser::jr },
        { "ld", &Z80OpcodeParser::ld },
        { "ldd", &Z80OpcodeParser::ldd },
        { "lddr", &Z80OpcodeParser::lddr },
        { "ldi", &Z80OpcodeParser::ldi },
        { "ldir", &Z80OpcodeParser::ldir },
        { "neg", &Z80OpcodeParser::neg },
        { "nop", &Z80OpcodeParser::nop },
        { "or", &Z80OpcodeParser::or },
        { "otdr", &Z80OpcodeParser::otdr },
        { "otir", &Z80OpcodeParser::otir },
        { "out", &Z80OpcodeParser::out },
        { "outd", &Z80OpcodeParser::outd },
        { "outi", &Z80OpcodeParser::outi },
        { "pop", &Z80OpcodeParser::pop },
        { "push", &Z80OpcodeParser::push },
        { "res", &Z80OpcodeParser::res },
        { "ret", &Z80OpcodeParser::ret },
        { "reti", &Z80OpcodeParser::reti },
        { "retn", &Z80OpcodeParser::retn },
        { "rl", &Z80OpcodeParser::rl },
        { "rla", &Z80OpcodeParser::rla },
        { "rlc", &Z80OpcodeParser::rlc },
        { "rlca", &Z80OpcodeParser::rlca },
        { "rld", &Z80OpcodeParser::rld },
        { "rr", &Z80OpcodeParser::rr },
        { "rra", &Z80OpcodeParser::rra },
        { "rrc", &Z80OpcodeParser::rrc },
        { "rrca", &Z80OpcodeParser::rrca },
        { "rrd", &Z80OpcodeParser::rrd },
        { "rst", &Z80OpcodeParser::rst },
        { "sbc", &Z80OpcodeParser::sbc },
        { "scf", &Z80OpcodeParser::scf },
        { "set", &Z80OpcodeParser::set },
        { "sla", &Z80OpcodeParser::sla },
        { "sra", &Z80OpcodeParser::sra },
        { "srl", &Z80OpcodeParser::srl },
        { "sub", &Z80OpcodeParser::sub },
        { "xor", &Z80OpcodeParser::xor },
    };

bool AssemblerParser::parseOpcode_generated(const std::string& opcode)
{
    auto it = opcodes.find(opcode);
    if (it != opcodes.end()) {
        Z80OpcodeParser parser(this);
        return (parser.*(it->second))();
    }
    return false;
}
