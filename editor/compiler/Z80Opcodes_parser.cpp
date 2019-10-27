// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "CodeEmitter.h"
#include "AssemblerParser.h"
#include "AssemblerToken.h"
#include "AssemblerContext.h"
#include <unordered_map>

#ifdef emit
#undef emit
#endif

class Z80OpcodeParser
{
private:
    AssemblerParser* mParser;
    CodeEmitter* mCodeEmitter;
    const Token& mToken;
    Token mMinusToken;
    std::unique_ptr<Expression> mLiteral1;
    std::unique_ptr<Expression> mLiteral2;
    quint8 mByteConstant;

    bool eol() const { return mParser->matchEol(); }
    bool token(int tok) const { return mParser->matchToken(tok); }
    bool ident(const char* id) const { return mParser->matchIdentifier(id); }
    bool byteConstant() { return mParser->matchByte(&mByteConstant); }
    std::unique_ptr<Expression> zero() { return std::make_unique<ConstantExpression>(mParser->lastToken(), 0); }

    bool byteLiteral(std::unique_ptr<Expression>* out) const { return mParser->matchExpression(out); }
    bool byteLiteralNegative(std::unique_ptr<Expression>* out) const { return mParser->matchExpressionNegative(mMinusToken, out); }
    bool byteOffset(std::unique_ptr<Expression>* out) const { return mParser->matchExpression(out); }
    bool wordLiteral(std::unique_ptr<Expression>* out) const { return mParser->matchExpression(out); }

public:
    explicit Z80OpcodeParser(AssemblerParser* parser)
        : mParser(parser)
        , mCodeEmitter(parser->mContext->codeEmitter())
        , mToken(parser->lastToken())
    {
        mParser->nextToken();
    }

    AssemblerParser::OpcodeParseResult opcode_adc()
    {
        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADC_A_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_A_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_HL_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("de")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_HL_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("hl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_HL_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("sp")) {
                    if (eol())
                        return mCodeEmitter->emit<ADC_HL_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_add()
    {
        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADD_A_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<ADD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<ADD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_A_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_HL_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("de")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_HL_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("hl")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_HL_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("sp")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_HL_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ix")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IX_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("de")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IX_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ix")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IX_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("sp")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IX_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IY_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("de")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IY_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iy")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IY_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("sp")) {
                    if (eol())
                        return mCodeEmitter->emit<ADD_IY_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_and()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<AND_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<AND_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<AND_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<AND_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<AND_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<AND_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<AND_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (byteLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<AND_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<AND_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<AND_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<AND_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<AND_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<AND_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<AND_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<AND_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<AND_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<AND_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<AND_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<AND_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_bit()
    {
        if (byteConstant()) {
            if (mByteConstant == 0) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_0_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_0_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 1) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_1_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_1_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 2) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_2_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_2_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 3) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_3_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_3_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 4) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_4_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_4_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 5) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_5_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_5_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 6) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_6_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_6_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 7) {
                if (token(T_COMMA)) {
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_7_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<BIT_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<BIT_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<BIT_7_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_call()
    {
        if (wordLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<CALL_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_C_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("m")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_M_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_NC_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_NZ_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("p")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_P_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("pe")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_PE_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("po")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_PO_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<CALL_Z_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ccf()
    {
        if (eol())
            return mCodeEmitter->emit<CCF>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cp()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<CP_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<CP_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<CP_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<CP_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<CP_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<CP_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<CP_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (byteLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<CP_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<CP_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<CP_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<CP_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<CP_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<CP_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<CP_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<CP_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<CP_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<CP_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<CP_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<CP_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cpd()
    {
        if (eol())
            return mCodeEmitter->emit<CPD>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cpdr()
    {
        if (eol())
            return mCodeEmitter->emit<CPDR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cpi()
    {
        if (eol())
            return mCodeEmitter->emit<CPI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cpir()
    {
        if (eol())
            return mCodeEmitter->emit<CPIR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_cpl()
    {
        if (eol())
            return mCodeEmitter->emit<CPL>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_daa()
    {
        if (eol())
            return mCodeEmitter->emit<DAA>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_dec()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<DEC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<DEC_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<DEC_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<DEC_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<DEC_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<DEC_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<DEC_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<DEC_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<DEC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<DEC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<DEC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<DEC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<DEC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<DEC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ix")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("bc")) {
            if (eol())
                return mCodeEmitter->emit<DEC_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (eol())
                return mCodeEmitter->emit<DEC_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (eol())
                return mCodeEmitter->emit<DEC_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("sp")) {
            if (eol())
                return mCodeEmitter->emit<DEC_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<DEC_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_di()
    {
        if (eol())
            return mCodeEmitter->emit<DI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_djnz()
    {
        if (byteOffset(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<DJNZ_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ei()
    {
        if (eol())
            return mCodeEmitter->emit<EI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ex()
    {
        if (token(T_LPAREN)) {
            if (ident("sp")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("hl")) {
                            if (eol())
                                return mCodeEmitter->emit<EX_mSP_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if (eol())
                                return mCodeEmitter->emit<EX_mSP_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if (eol())
                                return mCodeEmitter->emit<EX_mSP_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("af")) {
            if (token(T_COMMA)) {
                if (token(T_AF_SHADOW)) {
                    if (eol())
                        return mCodeEmitter->emit<EX_AF_AFs>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (token(T_COMMA)) {
                if (ident("hl")) {
                    if (eol())
                        return mCodeEmitter->emit<EX_DE_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_exx()
    {
        if (eol())
            return mCodeEmitter->emit<EXX>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_halt()
    {
        if (eol())
            return mCodeEmitter->emit<HALT>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_im()
    {
        if (byteConstant()) {
            if (mByteConstant == 0) {
                if (eol())
                    return mCodeEmitter->emit<IM_0>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 1) {
                if (eol())
                    return mCodeEmitter->emit<IM_1>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 2) {
                if (eol())
                    return mCodeEmitter->emit<IM_2>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_in()
    {
        if (ident("a")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_A_mn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_A_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_B_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_C_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_D_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_E_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_H_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("c")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<IN_L_mC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_inc()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<INC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<INC_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<INC_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<INC_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<INC_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<INC_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<INC_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<INC_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<INC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<INC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<INC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<INC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<INC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<INC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ix")) {
            if (eol())
                return mCodeEmitter->emit<INC_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (eol())
                return mCodeEmitter->emit<INC_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("bc")) {
            if (eol())
                return mCodeEmitter->emit<INC_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (eol())
                return mCodeEmitter->emit<INC_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (eol())
                return mCodeEmitter->emit<INC_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("sp")) {
            if (eol())
                return mCodeEmitter->emit<INC_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<INC_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<INC_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<INC_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<INC_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ind()
    {
        if (eol())
            return mCodeEmitter->emit<IND>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_indr()
    {
        if (eol())
            return mCodeEmitter->emit<INDR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ini()
    {
        if (eol())
            return mCodeEmitter->emit<INI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_inir()
    {
        if (eol())
            return mCodeEmitter->emit<INIR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_jp()
    {
        if (wordLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<JP_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_C_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("m")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_M_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_NC_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_NZ_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("p")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_P_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("pe")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_PE_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("po")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_PO_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_Z_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_mIX>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<JP_mIY>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_jr()
    {
        if (byteOffset(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<JR_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (byteOffset(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JR_C_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nc")) {
            if (token(T_COMMA)) {
                if (byteOffset(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JR_NC_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nz")) {
            if (token(T_COMMA)) {
                if (byteOffset(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JR_NZ_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("z")) {
            if (token(T_COMMA)) {
                if (byteOffset(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<JR_Z_off>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ld()
    {
        if (ident("a")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("bc")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mBC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("de")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mDE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("i")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_I>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("r")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_R>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_A_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("bc")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mBC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("de")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mDE_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&mLiteral1)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mHL_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&mLiteral2)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIXn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&mLiteral2)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&mLiteral2)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIXn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (byteLiteral(&mLiteral2)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mIYn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&mLiteral2)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (token(T_COMMA)) {
                                if (byteLiteral(&mLiteral2)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_n>(mToken, std::move(mLiteral1), std::move(mLiteral2)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("a")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("b")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_B>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("c")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_C>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("d")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_D>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("e")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_E>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("h")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_H>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                if (ident("l")) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_mIYn_L>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (wordLiteral(&mLiteral1)) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("bc")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_BC>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("de")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_DE>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("hl")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_HL>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("sp")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_SP>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_IX>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if (eol())
                                return mCodeEmitter->emit<LD_mnn_IY>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("bc")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_BC_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_BC_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_DE_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_DE_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_HL_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_HL_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("sp")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_SP_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_SP_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("hl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_SP_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ix")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_SP_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iy")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_SP_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("i")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_I_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ix")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IX_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_IX_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (token(T_COMMA)) {
                if (wordLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IY_nn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (wordLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_IY_mnn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("r")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_R_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_B_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_B_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_B_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_B_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_B_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_B_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_B_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_B_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_C_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_C_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_C_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_C_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_C_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_C_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_C_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_C_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_D_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_D_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_D_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_D_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_D_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_D_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_D_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_D_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_E_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_E_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_E_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_E_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_E_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_E_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_E_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_E_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_H_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_H_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_H_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_H_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_H_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_H_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_H_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_H_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (token(T_COMMA)) {
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_L_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_L_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_L_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_L_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<LD_L_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_L_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<LD_L_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_L_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (token(T_COMMA)) {
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXH_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (token(T_COMMA)) {
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYH_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (token(T_COMMA)) {
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IXL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (token(T_COMMA)) {
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<LD_IYL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ldd()
    {
        if (eol())
            return mCodeEmitter->emit<LDD>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_lddr()
    {
        if (eol())
            return mCodeEmitter->emit<LDDR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ldi()
    {
        if (eol())
            return mCodeEmitter->emit<LDI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ldir()
    {
        if (eol())
            return mCodeEmitter->emit<LDIR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_neg()
    {
        if (eol())
            return mCodeEmitter->emit<NEG>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_nop()
    {
        if (eol())
            return mCodeEmitter->emit<NOP>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_or()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<OR_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<OR_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<OR_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<OR_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<OR_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<OR_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<OR_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (byteLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<OR_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<OR_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<OR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<OR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<OR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<OR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<OR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<OR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<OR_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<OR_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<OR_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<OR_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_otdr()
    {
        if (eol())
            return mCodeEmitter->emit<OTDR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_otir()
    {
        if (eol())
            return mCodeEmitter->emit<OTIR>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_out()
    {
        if (token(T_LPAREN)) {
            if (byteLiteral(&mLiteral1)) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mn_A>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("c")) {
                if (token(T_RPAREN)) {
                    if (token(T_COMMA)) {
                        if (ident("a")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("b")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("c")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("d")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("e")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("h")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("l")) {
                            if (eol())
                                return mCodeEmitter->emit<OUT_mC_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_outd()
    {
        if (eol())
            return mCodeEmitter->emit<OUTD>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_outi()
    {
        if (eol())
            return mCodeEmitter->emit<OUTI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_pop()
    {
        if (ident("ix")) {
            if (eol())
                return mCodeEmitter->emit<POP_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (eol())
                return mCodeEmitter->emit<POP_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("bc")) {
            if (eol())
                return mCodeEmitter->emit<POP_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (eol())
                return mCodeEmitter->emit<POP_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (eol())
                return mCodeEmitter->emit<POP_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("af")) {
            if (eol())
                return mCodeEmitter->emit<POP_AF>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_push()
    {
        if (ident("ix")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_IX>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iy")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_IY>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("bc")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("de")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("af")) {
            if (eol())
                return mCodeEmitter->emit<PUSH_AF>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_res()
    {
        if (byteConstant()) {
            if (mByteConstant == 0) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_0_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_0_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 1) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_1_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_1_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 2) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_2_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_2_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 3) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_3_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_3_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 4) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_4_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_4_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 5) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_5_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_5_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 6) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_6_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_6_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 7) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<RES_7_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_7_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<RES_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<RES_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_ret()
    {
        if (eol())
            return mCodeEmitter->emit<RET>(mToken), AssemblerParser::OpcodeParseResult::Success;
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<RET_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("m")) {
            if (eol())
                return mCodeEmitter->emit<RET_M>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nc")) {
            if (eol())
                return mCodeEmitter->emit<RET_NC>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("nz")) {
            if (eol())
                return mCodeEmitter->emit<RET_NZ>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("p")) {
            if (eol())
                return mCodeEmitter->emit<RET_P>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("pe")) {
            if (eol())
                return mCodeEmitter->emit<RET_PE>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("po")) {
            if (eol())
                return mCodeEmitter->emit<RET_PO>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("z")) {
            if (eol())
                return mCodeEmitter->emit<RET_Z>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_reti()
    {
        if (eol())
            return mCodeEmitter->emit<RETI>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_retn()
    {
        if (eol())
            return mCodeEmitter->emit<RETN>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rl()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<RL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<RL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<RL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<RL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<RL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<RL_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<RL_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RL_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rla()
    {
        if (eol())
            return mCodeEmitter->emit<RLA>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rlc()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<RLC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<RLC_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<RLC_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<RLC_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<RLC_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<RLC_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<RLC_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RLC_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RLC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RLC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RLC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RLC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RLC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RLC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rlca()
    {
        if (eol())
            return mCodeEmitter->emit<RLCA>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rld()
    {
        if (eol())
            return mCodeEmitter->emit<RLD>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rr()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<RR_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<RR_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<RR_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<RR_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<RR_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<RR_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<RR_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RR_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rra()
    {
        if (eol())
            return mCodeEmitter->emit<RRA>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rrc()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<RRC_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<RRC_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<RRC_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<RRC_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<RRC_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<RRC_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<RRC_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RRC_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RRC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RRC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RRC_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<RRC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RRC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<RRC_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rrca()
    {
        if (eol())
            return mCodeEmitter->emit<RRCA>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rrd()
    {
        if (eol())
            return mCodeEmitter->emit<RRD>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_rst()
    {
        if (byteConstant()) {
            if (mByteConstant == 0x00) {
                if (eol())
                    return mCodeEmitter->emit<RST_00>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x08) {
                if (eol())
                    return mCodeEmitter->emit<RST_08>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x10) {
                if (eol())
                    return mCodeEmitter->emit<RST_10>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x18) {
                if (eol())
                    return mCodeEmitter->emit<RST_18>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x20) {
                if (eol())
                    return mCodeEmitter->emit<RST_20>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x28) {
                if (eol())
                    return mCodeEmitter->emit<RST_28>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x30) {
                if (eol())
                    return mCodeEmitter->emit<RST_30>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 0x38) {
                if (eol())
                    return mCodeEmitter->emit<RST_38>(mToken), AssemblerParser::OpcodeParseResult::Success;
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_sbc()
    {
        if (ident("a")) {
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (byteLiteral(&mLiteral1)) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_LPAREN)) {
                    if (ident("hl")) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SBC_A_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("ix")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SBC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<SBC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<SBC_A_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("iy")) {
                        if ((mLiteral1 = zero()), token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SBC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (token(T_PLUS)) {
                            if (byteLiteral(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<SBC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if ((mMinusToken = mToken), token(T_MINUS)) {
                            if (byteLiteralNegative(&mLiteral1)) {
                                if (token(T_RPAREN)) {
                                    if (eol())
                                        return mCodeEmitter->emit<SBC_A_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixh")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyh")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("ixl")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("iyl")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_A_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("hl")) {
            if (token(T_COMMA)) {
                if (ident("bc")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_HL_BC>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("de")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_HL_DE>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("hl")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_HL_HL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("sp")) {
                    if (eol())
                        return mCodeEmitter->emit<SBC_HL_SP>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_scf()
    {
        if (eol())
            return mCodeEmitter->emit<SCF>(mToken), AssemblerParser::OpcodeParseResult::Success;
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_set()
    {
        if (byteConstant()) {
            if (mByteConstant == 0) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_0_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_0_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_0_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_0_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 1) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_1_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_1_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_1_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_1_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 2) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_2_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_2_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_2_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_2_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 3) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_3_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_3_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_3_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_3_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 4) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_4_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_4_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_4_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_4_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 5) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_5_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_5_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_5_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_5_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 6) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_6_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_6_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_6_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_6_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (mByteConstant == 7) {
                if (token(T_COMMA)) {
                    if (ident("a")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("b")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("c")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("d")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("e")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("h")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (ident("l")) {
                        if (eol())
                            return mCodeEmitter->emit<SET_7_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    if (token(T_LPAREN)) {
                        if (ident("hl")) {
                            if (token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_7_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("ix")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_7_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        if (ident("iy")) {
                            if ((mLiteral1 = zero()), token(T_RPAREN)) {
                                if (eol())
                                    return mCodeEmitter->emit<SET_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if (token(T_PLUS)) {
                                if (byteLiteral(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            if ((mMinusToken = mToken), token(T_MINUS)) {
                                if (byteLiteralNegative(&mLiteral1)) {
                                    if (token(T_RPAREN)) {
                                        if (eol())
                                            return mCodeEmitter->emit<SET_7_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                                    }
                                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                                }
                                return AssemblerParser::OpcodeParseResult::SyntaxError;
                            }
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_sla()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<SLA_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<SLA_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<SLA_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<SLA_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<SLA_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<SLA_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<SLA_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLA_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_sll()
    {
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<SLL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<SLL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<SLL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<SLL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<SLL_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<SLL_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLL_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SLL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SLL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<SLL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_sra()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<SRA_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<SRA_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<SRA_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<SRA_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<SRA_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<SRA_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<SRA_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRA_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRA_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRA_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_srl()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<SRL_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<SRL_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<SRL_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<SRL_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<SRL_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<SRL_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<SRL_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRL_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRL_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SRL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SRL_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_sub()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<SUB_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<SUB_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<SUB_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<SUB_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<SUB_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<SUB_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<SUB_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (byteLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<SUB_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SUB_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SUB_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<SUB_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SUB_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<SUB_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<SUB_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<SUB_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<SUB_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<SUB_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }

    AssemblerParser::OpcodeParseResult opcode_xor()
    {
        if (ident("a")) {
            if (eol())
                return mCodeEmitter->emit<XOR_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
            if (token(T_COMMA)) {
                if (ident("a")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_A>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("b")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("c")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("d")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("e")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("h")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (ident("l")) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_A_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("b")) {
            if (eol())
                return mCodeEmitter->emit<XOR_B>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("c")) {
            if (eol())
                return mCodeEmitter->emit<XOR_C>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("d")) {
            if (eol())
                return mCodeEmitter->emit<XOR_D>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("e")) {
            if (eol())
                return mCodeEmitter->emit<XOR_E>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("h")) {
            if (eol())
                return mCodeEmitter->emit<XOR_H>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("l")) {
            if (eol())
                return mCodeEmitter->emit<XOR_L>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (byteLiteral(&mLiteral1)) {
            if (eol())
                return mCodeEmitter->emit<XOR_n>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (token(T_LPAREN)) {
            if (ident("hl")) {
                if (token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_mHL>(mToken), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("ix")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<XOR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<XOR_mIXn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            if (ident("iy")) {
                if ((mLiteral1 = zero()), token(T_RPAREN)) {
                    if (eol())
                        return mCodeEmitter->emit<XOR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if (token(T_PLUS)) {
                    if (byteLiteral(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<XOR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                if ((mMinusToken = mToken), token(T_MINUS)) {
                    if (byteLiteralNegative(&mLiteral1)) {
                        if (token(T_RPAREN)) {
                            if (eol())
                                return mCodeEmitter->emit<XOR_mIYn>(mToken, std::move(mLiteral1)), AssemblerParser::OpcodeParseResult::Success;
                            return AssemblerParser::OpcodeParseResult::SyntaxError;
                        }
                        return AssemblerParser::OpcodeParseResult::SyntaxError;
                    }
                    return AssemblerParser::OpcodeParseResult::SyntaxError;
                }
                return AssemblerParser::OpcodeParseResult::SyntaxError;
            }
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixh")) {
            if (eol())
                return mCodeEmitter->emit<XOR_IXH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyh")) {
            if (eol())
                return mCodeEmitter->emit<XOR_IYH>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("ixl")) {
            if (eol())
                return mCodeEmitter->emit<XOR_IXL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        if (ident("iyl")) {
            if (eol())
                return mCodeEmitter->emit<XOR_IYL>(mToken), AssemblerParser::OpcodeParseResult::Success;
            return AssemblerParser::OpcodeParseResult::SyntaxError;
        }
        return AssemblerParser::OpcodeParseResult::SyntaxError;
    }
};

using Func = AssemblerParser::OpcodeParseResult (Z80OpcodeParser::*)();
static std::unordered_map<std::string, Func> opcodes = {
        { "adc", &Z80OpcodeParser::opcode_adc },
        { "add", &Z80OpcodeParser::opcode_add },
        { "and", &Z80OpcodeParser::opcode_and },
        { "bit", &Z80OpcodeParser::opcode_bit },
        { "call", &Z80OpcodeParser::opcode_call },
        { "ccf", &Z80OpcodeParser::opcode_ccf },
        { "cp", &Z80OpcodeParser::opcode_cp },
        { "cpd", &Z80OpcodeParser::opcode_cpd },
        { "cpdr", &Z80OpcodeParser::opcode_cpdr },
        { "cpi", &Z80OpcodeParser::opcode_cpi },
        { "cpir", &Z80OpcodeParser::opcode_cpir },
        { "cpl", &Z80OpcodeParser::opcode_cpl },
        { "daa", &Z80OpcodeParser::opcode_daa },
        { "dec", &Z80OpcodeParser::opcode_dec },
        { "di", &Z80OpcodeParser::opcode_di },
        { "djnz", &Z80OpcodeParser::opcode_djnz },
        { "ei", &Z80OpcodeParser::opcode_ei },
        { "ex", &Z80OpcodeParser::opcode_ex },
        { "exx", &Z80OpcodeParser::opcode_exx },
        { "halt", &Z80OpcodeParser::opcode_halt },
        { "im", &Z80OpcodeParser::opcode_im },
        { "in", &Z80OpcodeParser::opcode_in },
        { "inc", &Z80OpcodeParser::opcode_inc },
        { "ind", &Z80OpcodeParser::opcode_ind },
        { "indr", &Z80OpcodeParser::opcode_indr },
        { "ini", &Z80OpcodeParser::opcode_ini },
        { "inir", &Z80OpcodeParser::opcode_inir },
        { "jp", &Z80OpcodeParser::opcode_jp },
        { "jr", &Z80OpcodeParser::opcode_jr },
        { "ld", &Z80OpcodeParser::opcode_ld },
        { "ldd", &Z80OpcodeParser::opcode_ldd },
        { "lddr", &Z80OpcodeParser::opcode_lddr },
        { "ldi", &Z80OpcodeParser::opcode_ldi },
        { "ldir", &Z80OpcodeParser::opcode_ldir },
        { "neg", &Z80OpcodeParser::opcode_neg },
        { "nop", &Z80OpcodeParser::opcode_nop },
        { "or", &Z80OpcodeParser::opcode_or },
        { "otdr", &Z80OpcodeParser::opcode_otdr },
        { "otir", &Z80OpcodeParser::opcode_otir },
        { "out", &Z80OpcodeParser::opcode_out },
        { "outd", &Z80OpcodeParser::opcode_outd },
        { "outi", &Z80OpcodeParser::opcode_outi },
        { "pop", &Z80OpcodeParser::opcode_pop },
        { "push", &Z80OpcodeParser::opcode_push },
        { "res", &Z80OpcodeParser::opcode_res },
        { "ret", &Z80OpcodeParser::opcode_ret },
        { "reti", &Z80OpcodeParser::opcode_reti },
        { "retn", &Z80OpcodeParser::opcode_retn },
        { "rl", &Z80OpcodeParser::opcode_rl },
        { "rla", &Z80OpcodeParser::opcode_rla },
        { "rlc", &Z80OpcodeParser::opcode_rlc },
        { "rlca", &Z80OpcodeParser::opcode_rlca },
        { "rld", &Z80OpcodeParser::opcode_rld },
        { "rr", &Z80OpcodeParser::opcode_rr },
        { "rra", &Z80OpcodeParser::opcode_rra },
        { "rrc", &Z80OpcodeParser::opcode_rrc },
        { "rrca", &Z80OpcodeParser::opcode_rrca },
        { "rrd", &Z80OpcodeParser::opcode_rrd },
        { "rst", &Z80OpcodeParser::opcode_rst },
        { "sbc", &Z80OpcodeParser::opcode_sbc },
        { "scf", &Z80OpcodeParser::opcode_scf },
        { "set", &Z80OpcodeParser::opcode_set },
        { "sla", &Z80OpcodeParser::opcode_sla },
        { "sll", &Z80OpcodeParser::opcode_sll },
        { "sra", &Z80OpcodeParser::opcode_sra },
        { "srl", &Z80OpcodeParser::opcode_srl },
        { "sub", &Z80OpcodeParser::opcode_sub },
        { "xor", &Z80OpcodeParser::opcode_xor },
    };

auto AssemblerParser::parseOpcode_generated(const std::string& opcode) -> OpcodeParseResult
{
    auto it = opcodes.find(opcode);
    if (it != opcodes.end()) {
        Z80OpcodeParser parser(this);
        return (parser.*(it->second))();
    }
    return OpcodeParseResult::UnknownOpcode;
}
