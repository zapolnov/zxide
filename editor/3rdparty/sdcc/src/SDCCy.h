
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_NAME = 259,
     ADDRSPACE_NAME = 260,
     CONSTANT = 261,
     SIZEOF = 262,
     ALIGNOF = 263,
     TYPEOF = 264,
     OFFSETOF = 265,
     PTR_OP = 266,
     INC_OP = 267,
     DEC_OP = 268,
     LEFT_OP = 269,
     RIGHT_OP = 270,
     LE_OP = 271,
     GE_OP = 272,
     EQ_OP = 273,
     NE_OP = 274,
     AND_OP = 275,
     OR_OP = 276,
     MUL_ASSIGN = 277,
     DIV_ASSIGN = 278,
     MOD_ASSIGN = 279,
     ADD_ASSIGN = 280,
     SUB_ASSIGN = 281,
     LEFT_ASSIGN = 282,
     RIGHT_ASSIGN = 283,
     AND_ASSIGN = 284,
     XOR_ASSIGN = 285,
     OR_ASSIGN = 286,
     TYPEDEF = 287,
     EXTERN = 288,
     STATIC = 289,
     AUTO = 290,
     REGISTER = 291,
     CODE = 292,
     EEPROM = 293,
     INTERRUPT = 294,
     SFR = 295,
     SFR16 = 296,
     SFR32 = 297,
     ADDRESSMOD = 298,
     STATIC_ASSERT = 299,
     AT = 300,
     SBIT = 301,
     REENTRANT = 302,
     USING = 303,
     XDATA = 304,
     DATA = 305,
     IDATA = 306,
     PDATA = 307,
     VAR_ARGS = 308,
     CRITICAL = 309,
     NONBANKED = 310,
     BANKED = 311,
     SHADOWREGS = 312,
     SD_WPARAM = 313,
     SD_BOOL = 314,
     SD_CHAR = 315,
     SD_SHORT = 316,
     SD_INT = 317,
     SD_LONG = 318,
     SIGNED = 319,
     UNSIGNED = 320,
     SD_FLOAT = 321,
     DOUBLE = 322,
     FIXED16X16 = 323,
     SD_CONST = 324,
     VOLATILE = 325,
     SD_VOID = 326,
     BIT = 327,
     STRUCT = 328,
     UNION = 329,
     ENUM = 330,
     RANGE = 331,
     SD_FAR = 332,
     CASE = 333,
     DEFAULT = 334,
     IF = 335,
     ELSE = 336,
     SWITCH = 337,
     WHILE = 338,
     DO = 339,
     FOR = 340,
     GOTO = 341,
     CONTINUE = 342,
     BREAK = 343,
     RETURN = 344,
     NAKED = 345,
     JAVANATIVE = 346,
     OVERLAY = 347,
     TRAP = 348,
     STRING_LITERAL = 349,
     INLINEASM = 350,
     IFX = 351,
     ADDRESS_OF = 352,
     GET_VALUE_AT_ADDRESS = 353,
     SET_VALUE_AT_ADDRESS = 354,
     SPIL = 355,
     UNSPIL = 356,
     GETHBIT = 357,
     GETABIT = 358,
     GETBYTE = 359,
     GETWORD = 360,
     BITWISEAND = 361,
     UNARYMINUS = 362,
     IPUSH = 363,
     IPOP = 364,
     PCALL = 365,
     ENDFUNCTION = 366,
     JUMPTABLE = 367,
     RRC = 368,
     RLC = 369,
     CAST = 370,
     CALL = 371,
     PARAM = 372,
     NULLOP = 373,
     BLOCK = 374,
     LABEL = 375,
     RECEIVE = 376,
     SEND = 377,
     ARRAYINIT = 378,
     DUMMY_READ_VOLATILE = 379,
     ENDCRITICAL = 380,
     SWAP = 381,
     INLINE = 382,
     NORETURN = 383,
     RESTRICT = 384,
     SMALLC = 385,
     PRESERVES_REGS = 386,
     Z88DK_FASTCALL = 387,
     Z88DK_CALLEE = 388,
     ALIGNAS = 389,
     Z88DK_SHORTCALL = 390,
     Z88DK_PARAMS_OFFSET = 391,
     GENERIC = 392,
     GENERIC_ASSOC_LIST = 393,
     GENERIC_ASSOCIATION = 394,
     ASM = 395
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPE_NAME 259
#define ADDRSPACE_NAME 260
#define CONSTANT 261
#define SIZEOF 262
#define ALIGNOF 263
#define TYPEOF 264
#define OFFSETOF 265
#define PTR_OP 266
#define INC_OP 267
#define DEC_OP 268
#define LEFT_OP 269
#define RIGHT_OP 270
#define LE_OP 271
#define GE_OP 272
#define EQ_OP 273
#define NE_OP 274
#define AND_OP 275
#define OR_OP 276
#define MUL_ASSIGN 277
#define DIV_ASSIGN 278
#define MOD_ASSIGN 279
#define ADD_ASSIGN 280
#define SUB_ASSIGN 281
#define LEFT_ASSIGN 282
#define RIGHT_ASSIGN 283
#define AND_ASSIGN 284
#define XOR_ASSIGN 285
#define OR_ASSIGN 286
#define TYPEDEF 287
#define EXTERN 288
#define STATIC 289
#define AUTO 290
#define REGISTER 291
#define CODE 292
#define EEPROM 293
#define INTERRUPT 294
#define SFR 295
#define SFR16 296
#define SFR32 297
#define ADDRESSMOD 298
#define STATIC_ASSERT 299
#define AT 300
#define SBIT 301
#define REENTRANT 302
#define USING 303
#define XDATA 304
#define DATA 305
#define IDATA 306
#define PDATA 307
#define VAR_ARGS 308
#define CRITICAL 309
#define NONBANKED 310
#define BANKED 311
#define SHADOWREGS 312
#define SD_WPARAM 313
#define SD_BOOL 314
#define SD_CHAR 315
#define SD_SHORT 316
#define SD_INT 317
#define SD_LONG 318
#define SIGNED 319
#define UNSIGNED 320
#define SD_FLOAT 321
#define DOUBLE 322
#define FIXED16X16 323
#define SD_CONST 324
#define VOLATILE 325
#define SD_VOID 326
#define BIT 327
#define STRUCT 328
#define UNION 329
#define ENUM 330
#define RANGE 331
#define SD_FAR 332
#define CASE 333
#define DEFAULT 334
#define IF 335
#define ELSE 336
#define SWITCH 337
#define WHILE 338
#define DO 339
#define FOR 340
#define GOTO 341
#define CONTINUE 342
#define BREAK 343
#define RETURN 344
#define NAKED 345
#define JAVANATIVE 346
#define OVERLAY 347
#define TRAP 348
#define STRING_LITERAL 349
#define INLINEASM 350
#define IFX 351
#define ADDRESS_OF 352
#define GET_VALUE_AT_ADDRESS 353
#define SET_VALUE_AT_ADDRESS 354
#define SPIL 355
#define UNSPIL 356
#define GETHBIT 357
#define GETABIT 358
#define GETBYTE 359
#define GETWORD 360
#define BITWISEAND 361
#define UNARYMINUS 362
#define IPUSH 363
#define IPOP 364
#define PCALL 365
#define ENDFUNCTION 366
#define JUMPTABLE 367
#define RRC 368
#define RLC 369
#define CAST 370
#define CALL 371
#define PARAM 372
#define NULLOP 373
#define BLOCK 374
#define LABEL 375
#define RECEIVE 376
#define SEND 377
#define ARRAYINIT 378
#define DUMMY_READ_VOLATILE 379
#define ENDCRITICAL 380
#define SWAP 381
#define INLINE 382
#define NORETURN 383
#define RESTRICT 384
#define SMALLC 385
#define PRESERVES_REGS 386
#define Z88DK_FASTCALL 387
#define Z88DK_CALLEE 388
#define ALIGNAS 389
#define Z88DK_SHORTCALL 390
#define Z88DK_PARAMS_OFFSET 391
#define GENERIC 392
#define GENERIC_ASSOC_LIST 393
#define GENERIC_ASSOCIATION 394
#define ASM 395




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 74 "SDCC.y"

    symbol     *sym;        /* symbol table pointer                   */
    structdef  *sdef;       /* structure definition                   */
    char       yychar[SDCC_NAME_MAX+1];
    sym_link   *lnk;        /* declarator  or specifier               */
    int        yyint;       /* integer value returned                 */
    value      *val;        /* for integer constant                   */
    initList   *ilist;      /* initial list                           */
    designation*dsgn;       /* designator                             */
    const char *yystr;      /* pointer to dynamicaly allocated string */
    ast        *asts;       /* expression tree                        */



/* Line 1676 of yacc.c  */
#line 347 "SDCCy.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


