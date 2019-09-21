
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 24 "SDCC.y"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "SDCCglobl.h"
#include "SDCCsymt.h"
#include "SDCChasht.h"
#include "SDCCval.h"
#include "SDCCmem.h"
#include "SDCCast.h"
#include "port.h"
#include "newalloc.h"
#include "SDCCerr.h"
#include "SDCCutil.h"
#include "SDCCbtree.h"
#include "SDCCopt.h"

extern int yyerror (char *);
/*extern FILE     *yyin;*/
long NestLevel = 0;     /* current NestLevel       */
int stackPtr  = 1;      /* stack pointer           */
int xstackPtr = 0;      /* xstack pointer          */
int reentrant = 0;
int blockNo   = 0;      /* sequential block number  */
int currBlockno=0;
int inCriticalFunction = 0;
int inCriticalBlock = 0;
int seqPointNo= 1;      /* sequence point number */
int ignoreTypedefType=0;
extern int yylex();
int yyparse(void);
extern int noLineno;
char lbuff[1024];       /* local buffer */
char function_name[256] = {0};

/* break & continue stacks */
STACK_DCL(continueStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(breakStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(forStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(swStk   ,ast   *,MAX_NEST_LEVEL)
STACK_DCL(blockNum,int,MAX_NEST_LEVEL*3)

value *cenum = NULL;        /* current enumeration  type chain*/
bool uselessDecl = TRUE;

#define YYDEBUG 1



/* Line 189 of yacc.c  */
#line 123 "SDCCy.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 454 "SDCCy.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 466 "SDCCy.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  117
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNRULES -- Number of states.  */
#define YYNSTATES  552

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   395

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   153,     2,     2,     2,   155,   148,     2,
     141,   142,   149,   150,   143,   151,   144,   154,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   147,   162,
     156,   161,   157,   160,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   145,     2,   146,   158,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   163,   159,   164,   152,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      18,    22,    23,    28,    30,    33,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    62,
      64,    69,    76,    81,    83,    86,    88,    89,    94,    99,
     101,   103,   105,   109,   111,   118,   120,   124,   128,   132,
     134,   136,   141,   145,   150,   151,   156,   157,   162,   165,
     168,   170,   174,   176,   179,   182,   185,   188,   193,   198,
     201,   208,   210,   212,   214,   216,   218,   220,   222,   227,
     229,   233,   237,   241,   243,   247,   251,   253,   257,   261,
     263,   267,   271,   275,   279,   281,   285,   289,   291,   295,
     297,   301,   303,   307,   309,   310,   315,   317,   318,   323,
     325,   326,   333,   335,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   364,   369,   371,
     374,   378,   381,   383,   385,   388,   390,   393,   395,   398,
     400,   403,   405,   409,   411,   415,   416,   418,   421,   423,
     426,   430,   433,   435,   437,   439,   441,   443,   445,   447,
     452,   457,   459,   462,   464,   466,   468,   470,   472,   474,
     476,   478,   480,   482,   484,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   514,   516,
     518,   520,   522,   524,   526,   528,   531,   533,   535,   536,
     543,   546,   548,   550,   552,   553,   555,   557,   560,   564,
     566,   570,   572,   575,   579,   580,   585,   591,   594,   596,
     599,   603,   606,   609,   610,   612,   615,   617,   619,   621,
     624,   626,   629,   631,   635,   639,   644,   649,   655,   661,
     668,   675,   679,   680,   686,   691,   693,   696,   699,   703,
     705,   707,   709,   712,   714,   718,   720,   724,   726,   730,
     733,   735,   737,   740,   742,   744,   747,   751,   754,   758,
     762,   767,   770,   774,   778,   779,   785,   787,   791,   796,
     799,   804,   811,   816,   818,   820,   822,   824,   826,   828,
     830,   832,   834,   837,   840,   843,   846,   850,   851,   855,
     857,   859,   862,   866,   869,   871,   873,   876,   878,   881,
     882,   885,   888,   890,   892,   895,   897,   900,   902,   905,
     908,   909,   910,   918,   919,   926,   928,   930,   932,   933,
     940,   948,   958,   959,   969,   970,   972,   976,   979,   982,
     985,   989,   991,   997,  1000,  1005,  1011
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,    -1,   167,    -1,   168,    -1,   167,   168,
      -1,   169,    -1,   208,    -1,   292,    -1,    -1,   241,   170,
     174,    -1,    -1,   209,   241,   171,   174,    -1,   173,    -1,
     173,   172,    -1,    48,   207,    -1,    47,    -1,    54,    -1,
      90,    -1,    91,    -1,    92,    -1,    55,    -1,    57,    -1,
      58,    -1,    56,    -1,   220,    -1,    93,    -1,   130,    -1,
     132,    -1,   133,    -1,   136,   141,   207,   142,    -1,   135,
     141,   207,   143,   207,   142,    -1,   131,   141,   250,   142,
      -1,   269,    -1,   275,   269,    -1,   293,    -1,    -1,   175,
     144,   176,   293,    -1,   175,   145,   205,   146,    -1,   293,
      -1,     6,    -1,   181,    -1,   141,   205,   142,    -1,   178,
      -1,   137,   141,   203,   143,   179,   142,    -1,   180,    -1,
     179,   143,   180,    -1,   254,   147,   203,    -1,    79,   147,
     203,    -1,    94,    -1,   177,    -1,   182,   145,   205,   146,
      -1,   182,   141,   142,    -1,   182,   141,   185,   142,    -1,
      -1,   182,   144,   183,   293,    -1,    -1,   182,    11,   184,
     293,    -1,   182,    12,    -1,   182,    13,    -1,   203,    -1,
     203,   143,   185,    -1,   182,    -1,    12,   186,    -1,    13,
     186,    -1,   187,   188,    -1,     7,   186,    -1,     7,   141,
     254,   142,    -1,     8,   141,   254,   142,    -1,     9,   186,
      -1,    10,   141,   254,   143,   175,   142,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     186,    -1,   141,   254,   142,   188,    -1,   188,    -1,   189,
     149,   188,    -1,   189,   154,   188,    -1,   189,   155,   188,
      -1,   189,    -1,   190,   150,   189,    -1,   190,   151,   189,
      -1,   190,    -1,   191,    14,   190,    -1,   191,    15,   190,
      -1,   191,    -1,   192,   156,   191,    -1,   192,   157,   191,
      -1,   192,    16,   191,    -1,   192,    17,   191,    -1,   192,
      -1,   193,    18,   192,    -1,   193,    19,   192,    -1,   193,
      -1,   194,   148,   193,    -1,   194,    -1,   195,   158,   194,
      -1,   195,    -1,   196,   159,   195,    -1,   196,    -1,    -1,
     197,    20,   198,   196,    -1,   197,    -1,    -1,   199,    21,
     200,   197,    -1,   199,    -1,    -1,   199,   160,   202,   205,
     147,   201,    -1,   201,    -1,   188,   204,   203,    -1,   161,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,   203,    -1,    -1,   205,   143,   206,   203,    -1,   201,
      -1,   209,   162,    -1,   209,   211,   162,    -1,   260,   162,
      -1,   210,    -1,   217,    -1,   217,   210,    -1,   223,    -1,
     223,   210,    -1,   218,    -1,   218,   210,    -1,   219,    -1,
     219,   210,    -1,   212,    -1,   211,   143,   212,    -1,   239,
      -1,   239,   161,   258,    -1,    -1,   214,    -1,   215,   161,
      -1,   216,    -1,   215,   216,    -1,   145,   207,   146,    -1,
     144,   293,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,   127,    -1,   128,    -1,   134,   141,   254,
     142,    -1,   134,   141,   207,   142,    -1,    39,    -1,    39,
     207,    -1,    69,    -1,   129,    -1,    70,    -1,     5,    -1,
      49,    -1,    37,    -1,    38,    -1,    50,    -1,    51,    -1,
      52,    -1,   221,    -1,   222,   221,    -1,   221,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    71,    -1,    66,    -1,    68,    -1,    72,
      -1,    45,   207,    -1,   226,    -1,   235,    -1,     4,    -1,
     224,    -1,    46,    -1,   225,    -1,    40,    -1,    40,    56,
      -1,    41,    -1,    42,    -1,    -1,   228,   229,   227,   163,
     231,   164,    -1,   228,   230,    -1,    73,    -1,    74,    -1,
     230,    -1,    -1,   293,    -1,   232,    -1,   231,   232,    -1,
     248,   233,   162,    -1,   234,    -1,   233,   143,   234,    -1,
     239,    -1,   147,   207,    -1,   239,   147,   207,    -1,    -1,
      75,   163,   236,   164,    -1,    75,   293,   163,   236,   164,
      -1,    75,   293,    -1,   237,    -1,   236,   143,    -1,   236,
     143,   237,    -1,   293,   238,    -1,   161,   207,    -1,    -1,
     240,    -1,   246,   240,    -1,   242,    -1,   243,    -1,   242,
      -1,   246,   242,    -1,   244,    -1,   244,   172,    -1,   293,
      -1,   141,   239,   142,    -1,   240,   145,   146,    -1,   240,
     145,   222,   146,    -1,   240,   145,   207,   146,    -1,   240,
     145,    34,   207,   146,    -1,   240,   145,   222,   207,   146,
      -1,   240,   145,    34,   222,   207,   146,    -1,   240,   145,
     222,    34,   207,   146,    -1,   243,   141,   142,    -1,    -1,
     243,   141,   245,   251,   142,    -1,   243,   141,   250,   142,
      -1,   247,    -1,   247,   248,    -1,   247,   246,    -1,   247,
     248,   246,    -1,   149,    -1,   249,    -1,   223,    -1,   249,
     223,    -1,   293,    -1,   250,   143,   293,    -1,   252,    -1,
     252,   143,    53,    -1,   253,    -1,   252,   143,   253,    -1,
     209,   239,    -1,   254,    -1,   209,    -1,   209,   255,    -1,
     246,    -1,   256,    -1,   246,   256,    -1,   141,   255,   142,
      -1,   145,   146,    -1,   145,   207,   146,    -1,   256,   145,
     146,    -1,   256,   145,   207,   146,    -1,   141,   142,    -1,
     141,   251,   142,    -1,   256,   141,   142,    -1,    -1,   256,
     141,   257,   251,   142,    -1,   203,    -1,   163,   259,   164,
      -1,   163,   259,   143,   164,    -1,   213,   258,    -1,   259,
     143,   213,   258,    -1,    44,   141,   207,   143,    94,   142,
      -1,    44,   141,   207,   142,    -1,   264,    -1,   269,    -1,
     277,    -1,   279,    -1,   285,    -1,   289,    -1,   263,    -1,
     291,    -1,    54,    -1,   262,   261,    -1,   265,   261,    -1,
     265,   164,    -1,   293,   147,    -1,    78,   207,   147,    -1,
      -1,    79,   266,   147,    -1,   163,    -1,   164,    -1,   267,
     268,    -1,   267,   270,   268,    -1,     1,   162,    -1,   271,
      -1,   275,    -1,   275,   271,    -1,   276,    -1,   276,   274,
      -1,    -1,   273,   275,    -1,   272,   271,    -1,   272,    -1,
     208,    -1,   275,   208,    -1,   261,    -1,   276,   261,    -1,
     162,    -1,   205,   162,    -1,    81,   261,    -1,    -1,    -1,
      80,   141,   205,   142,   280,   261,   278,    -1,    -1,    82,
     141,   205,   142,   281,   261,    -1,    83,    -1,    84,    -1,
      85,    -1,    -1,   282,   141,   205,   142,   286,   261,    -1,
     283,   261,    83,   141,   205,   142,   162,    -1,   284,   141,
     288,   162,   288,   162,   288,   142,   261,    -1,    -1,   284,
     141,   208,   288,   162,   288,   142,   287,   261,    -1,    -1,
     205,    -1,    86,   293,   162,    -1,    87,   162,    -1,    88,
     162,    -1,    89,   162,    -1,    89,   205,   162,    -1,    94,
      -1,   140,   141,   290,   142,   162,    -1,    95,   162,    -1,
      43,   293,   293,   162,    -1,    43,   293,    69,   293,   162,
      -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   153,   157,   158,   162,   166,   187,   195,
     194,   209,   208,   234,   235,   239,   243,   246,   249,   252,
     255,   258,   264,   267,   270,   276,   282,   288,   291,   294,
     297,   306,   330,   348,   349,   357,   358,   358,   365,   372,
     373,   374,   375,   376,   380,   384,   385,   389,   390,   394,
     421,   422,   423,   425,   429,   429,   436,   436,   443,   445,
     450,   451,   455,   456,   457,   458,   467,   468,   469,   470,
     471,   475,   476,   477,   478,   479,   480,   484,   485,   489,
     490,   491,   492,   496,   497,   498,   502,   503,   504,   508,
     509,   510,   511,   512,   516,   517,   518,   522,   523,   527,
     528,   532,   533,   537,   538,   538,   543,   544,   544,   549,
     550,   550,   558,   559,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   618,   619,   619,   623,   627,
     651,   686,   692,   695,   696,   701,   702,   707,   708,   713,
     714,   722,   723,   727,   728,   732,   733,   737,   741,   742,
     746,   768,   772,   776,   780,   784,   788,   795,   799,   806,
     812,   827,   828,   843,   847,   851,   855,   859,   863,   867,
     871,   875,   879,   886,   887,   894,   895,   900,   905,   910,
     915,   920,   925,   930,   935,   940,   945,   953,   960,   965,
     971,   980,   984,   992,   996,  1004,  1015,  1026,  1039,  1038,
    1131,  1161,  1162,  1166,  1167,  1178,  1197,  1198,  1211,  1236,
    1237,  1245,  1246,  1256,  1270,  1274,  1279,  1300,  1316,  1317,
    1318,  1326,  1346,  1359,  1373,  1374,  1382,  1383,  1387,  1393,
    1403,  1404,  1436,  1437,  1438,  1447,  1466,  1495,  1530,  1569,
    1611,  1656,  1661,  1660,  1694,  1704,  1705,  1718,  1724,  1764,
    1771,  1774,  1776,  1784,  1785,  1793,  1794,  1798,  1799,  1807,
    1824,  1834,  1842,  1868,  1869,  1870,  1877,  1878,  1883,  1889,
    1895,  1903,  1904,  1905,  1918,  1917,  1948,  1949,  1950,  1954,
    1955,  1964,  1972,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1996,  2007,  2016,  2017,  2030,  2032,  2039,  2039,  2049,
    2060,  2068,  2069,  2074,  2078,  2079,  2080,  2084,  2085,  2094,
    2094,  2105,  2112,  2122,  2135,  2161,  2162,  2166,  2167,  2171,
    2172,  2177,  2177,  2185,  2185,  2210,  2224,  2239,  2264,  2264,
    2273,  2283,  2309,  2308,  2348,  2349,  2353,  2363,  2376,  2386,
    2395,  2407,  2411,  2421,  2434,  2445,  2463
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_NAME",
  "ADDRSPACE_NAME", "CONSTANT", "SIZEOF", "ALIGNOF", "TYPEOF", "OFFSETOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CODE", "EEPROM", "INTERRUPT", "SFR", "SFR16",
  "SFR32", "ADDRESSMOD", "STATIC_ASSERT", "AT", "SBIT", "REENTRANT",
  "USING", "XDATA", "DATA", "IDATA", "PDATA", "VAR_ARGS", "CRITICAL",
  "NONBANKED", "BANKED", "SHADOWREGS", "SD_WPARAM", "SD_BOOL", "SD_CHAR",
  "SD_SHORT", "SD_INT", "SD_LONG", "SIGNED", "UNSIGNED", "SD_FLOAT",
  "DOUBLE", "FIXED16X16", "SD_CONST", "VOLATILE", "SD_VOID", "BIT",
  "STRUCT", "UNION", "ENUM", "RANGE", "SD_FAR", "CASE", "DEFAULT", "IF",
  "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK",
  "RETURN", "NAKED", "JAVANATIVE", "OVERLAY", "TRAP", "STRING_LITERAL",
  "INLINEASM", "IFX", "ADDRESS_OF", "GET_VALUE_AT_ADDRESS",
  "SET_VALUE_AT_ADDRESS", "SPIL", "UNSPIL", "GETHBIT", "GETABIT",
  "GETBYTE", "GETWORD", "BITWISEAND", "UNARYMINUS", "IPUSH", "IPOP",
  "PCALL", "ENDFUNCTION", "JUMPTABLE", "RRC", "RLC", "CAST", "CALL",
  "PARAM", "NULLOP", "BLOCK", "LABEL", "RECEIVE", "SEND", "ARRAYINIT",
  "DUMMY_READ_VOLATILE", "ENDCRITICAL", "SWAP", "INLINE", "NORETURN",
  "RESTRICT", "SMALLC", "PRESERVES_REGS", "Z88DK_FASTCALL", "Z88DK_CALLEE",
  "ALIGNAS", "Z88DK_SHORTCALL", "Z88DK_PARAMS_OFFSET", "GENERIC",
  "GENERIC_ASSOC_LIST", "GENERIC_ASSOCIATION", "ASM", "'('", "')'", "','",
  "'.'", "'['", "']'", "':'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "'{'",
  "'}'", "$accept", "file", "program", "external_definition",
  "function_definition", "$@1", "$@2", "function_attribute",
  "function_attributes", "function_body", "offsetof_member_designator",
  "$@3", "primary_expr", "generic_selection", "generic_assoc_list",
  "generic_association", "string_literal_val", "postfix_expr", "$@4",
  "$@5", "argument_expr_list", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "and_expr", "exclusive_or_expr", "inclusive_or_expr",
  "logical_and_expr", "$@6", "logical_or_expr", "$@7", "conditional_expr",
  "$@8", "assignment_expr", "assignment_operator", "expr", "$@9",
  "constant_expr", "declaration", "declaration_specifiers",
  "declaration_specifiers_", "init_declarator_list", "init_declarator",
  "designation_opt", "designation", "designator_list", "designator",
  "storage_class_specifier", "function_specifier", "alignment_specifier",
  "Interrupt_storage", "type_qualifier", "type_qualifier_list",
  "type_specifier", "sfr_reg_bit", "sfr_attributes",
  "struct_or_union_specifier", "$@10", "struct_or_union", "opt_stag",
  "stag", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "opt_assign_expr", "declarator",
  "declarator3", "function_declarator", "declarator2_function_attributes",
  "declarator2", "function_declarator2", "$@11", "pointer",
  "unqualified_pointer", "type_specifier_list", "type_specifier_list_",
  "identifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "abstract_declarator2", "$@12", "initializer", "initializer_list",
  "static_assert_declaration", "statement", "critical",
  "critical_statement", "labeled_statement", "label", "@13", "start_block",
  "end_block", "compound_statement", "block_item_list",
  "statements_and_implicit", "declaration_after_statement", "$@14",
  "implicit_block", "declaration_list", "statement_list",
  "expression_statement", "else_statement", "selection_statement", "$@15",
  "@16", "while", "do", "for", "iteration_statement", "$@17", "$@18",
  "expr_opt", "jump_statement", "asm_string_literal", "asm_statement",
  "addressmod", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,    40,    41,    44,    46,    91,    93,    58,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   166,   167,   167,   168,   168,   168,   170,
     169,   171,   169,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   174,   175,   176,   175,   175,   177,
     177,   177,   177,   177,   178,   179,   179,   180,   180,   181,
     182,   182,   182,   182,   183,   182,   184,   182,   182,   182,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   187,   187,   187,   188,   188,   189,
     189,   189,   189,   190,   190,   190,   191,   191,   191,   192,
     192,   192,   192,   192,   193,   193,   193,   194,   194,   195,
     195,   196,   196,   197,   198,   197,   199,   200,   199,   201,
     202,   201,   203,   203,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   205,   206,   205,   207,   208,
     208,   208,   209,   210,   210,   210,   210,   210,   210,   210,
     210,   211,   211,   212,   212,   213,   213,   214,   215,   215,
     216,   216,   217,   217,   217,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   222,   222,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   224,   224,   225,   225,   225,   225,   227,   226,
     226,   228,   228,   229,   229,   230,   231,   231,   232,   233,
     233,   234,   234,   234,   234,   235,   235,   235,   236,   236,
     236,   237,   238,   238,   239,   239,   240,   240,   241,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   244,   245,   244,   244,   246,   246,   246,   246,   247,
     248,   249,   249,   250,   250,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   257,   256,   258,   258,   258,   259,
     259,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   262,   263,   264,   264,   265,   265,   266,   265,   267,
     268,   269,   269,   269,   270,   270,   270,   271,   271,   273,
     272,   274,   274,   275,   275,   276,   276,   277,   277,   278,
     278,   280,   279,   281,   279,   282,   283,   284,   286,   285,
     285,   285,   287,   285,   288,   288,   289,   289,   289,   289,
     289,   290,   291,   291,   292,   292,   293
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     0,
       3,     0,     4,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     1,     2,     1,     0,     4,     4,     1,
       1,     1,     3,     1,     6,     1,     3,     3,     3,     1,
       1,     4,     3,     4,     0,     4,     0,     4,     2,     2,
       1,     3,     1,     2,     2,     2,     2,     4,     4,     2,
       6,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     0,     4,     1,     0,     4,     1,
       0,     6,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     2,
       3,     2,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     3,     1,     3,     0,     1,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     0,     6,
       2,     1,     1,     1,     0,     1,     1,     2,     3,     1,
       3,     1,     2,     3,     0,     4,     5,     2,     1,     2,
       3,     2,     2,     0,     1,     2,     1,     1,     1,     2,
       1,     2,     1,     3,     3,     4,     4,     5,     5,     6,
       6,     3,     0,     5,     4,     1,     2,     2,     3,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     3,     2,
       1,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     0,     5,     1,     3,     4,     2,
       4,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     0,     3,     1,
       1,     2,     3,     2,     1,     1,     2,     1,     2,     0,
       2,     2,     1,     1,     2,     1,     2,     1,     2,     2,
       0,     0,     7,     0,     6,     1,     1,     1,     0,     6,
       7,     9,     0,     9,     0,     1,     3,     2,     2,     2,
       3,     1,     5,     2,     4,     5,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,   346,   190,   166,   152,   153,   154,   155,   156,   168,
     169,   194,   196,   197,     0,     0,     0,   192,   167,   170,
     171,   172,   176,   177,   178,   179,   180,   181,   182,   184,
     185,   163,   165,   183,   186,   201,   202,     0,   157,   158,
     164,     0,     0,   249,     0,     3,     4,     6,     7,     0,
     132,   133,   137,   139,   175,   135,   191,   193,   188,   204,
     189,     0,     9,   228,   227,   230,     0,   245,     0,     8,
     232,   195,     0,     0,    40,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    71,    72,    73,    74,    75,    76,
      50,    43,    41,    62,    77,     0,    79,    83,    86,    89,
      94,    97,    99,   101,   103,   106,   109,   128,   187,    39,
       0,   217,     0,     0,   224,   226,     0,     1,     5,   129,
       0,   141,   143,    11,     0,   134,   138,   140,   136,   198,
     200,   205,     0,     0,   242,   161,    16,     0,    17,    21,
      24,    22,    23,    18,    19,    20,    26,    27,     0,    28,
      29,     0,     0,   231,    13,    25,   229,   251,   247,   246,
     250,   131,     0,     0,     0,     0,    66,     0,     0,    69,
       0,    63,    64,     0,    79,   112,   125,     0,   261,     0,
      56,    58,    59,     0,    54,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   107,   110,     0,   218,   223,     0,
       0,     0,   233,   225,     0,   130,     0,     0,     0,     0,
     234,     0,   173,     0,     0,   299,    10,   313,     0,     0,
      33,     0,   241,     0,     0,   253,   162,    15,     0,     0,
       0,    14,   248,   252,     0,   344,   282,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   114,     0,    42,   126,     0,     0,   263,   262,
     264,     0,     0,    52,     0,    60,     0,     0,    80,    81,
      82,    84,    85,    87,    88,    92,    93,    90,    91,    95,
      96,    98,   100,   102,     0,     0,     0,   219,   215,     0,
     221,     0,   160,   159,   142,   145,   276,   144,    12,     0,
       0,     0,   236,     0,   235,     0,   174,   303,   291,     0,
     297,     0,     0,   325,   326,   327,     0,     0,     0,     0,
       0,     0,   317,   300,     0,   315,     0,   289,   283,     0,
     301,   284,     0,   304,     0,     0,   285,   286,     0,     0,
       0,   287,   288,   290,    39,   314,    34,   261,     0,   255,
     257,   260,   244,     0,     0,     0,     0,   345,     0,    67,
      68,     0,     0,   113,     0,   271,     0,     0,   267,     0,
     265,   274,     0,    78,    57,    53,     0,    55,    51,   105,
     108,     0,   220,   222,   216,     0,     0,     0,   146,     0,
     148,     0,     0,   206,   214,   237,     0,     0,   238,     0,
       0,     0,     0,     0,   337,   338,   339,     0,   343,     0,
     318,   292,   294,   293,   302,   306,   316,     0,     0,   308,
       0,     0,   334,   295,     0,   259,   263,   243,     0,   254,
      32,     0,    30,   281,     0,    35,     0,     0,    45,     0,
     127,   272,   266,   268,   273,     0,   269,     0,    61,     0,
     151,     0,   279,   147,   149,   145,   277,   199,   207,     0,
       0,   209,   211,   239,   240,   296,   298,     0,     0,   336,
     340,   341,     0,   311,   310,     0,     0,   335,   334,     0,
     256,   258,     0,    70,    36,     0,     0,    44,     0,     0,
       0,   270,   111,   150,   278,     0,   212,   214,   208,     0,
     321,   323,     0,   328,     0,     0,   334,    31,     0,     0,
      48,    46,    47,   275,   280,   210,   213,     0,     0,   342,
       0,     0,   334,     0,    37,    38,   320,   324,   329,     0,
       0,   334,     0,   322,   330,   332,     0,   319,     0,     0,
     333,   331
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,    45,    46,    47,   133,   217,   153,   154,   226,
     444,   518,    90,    91,   447,   448,    92,    93,   276,   272,
     274,    94,    95,   174,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   294,   106,   295,   175,   296,   176,   263,
     334,   374,   108,   227,   228,    50,   120,   121,   397,   398,
     399,   400,    51,    52,    53,   155,    54,   223,    55,    56,
      57,    58,   218,    59,   129,   130,   402,   403,   470,   471,
      60,   206,   207,   300,   122,   114,    62,   115,    64,    65,
     233,   116,    67,   404,   160,   234,   376,   359,   360,   361,
     269,   270,   455,   307,   401,    68,   335,   336,   337,   338,
     339,   410,   229,   340,   341,   342,   343,   427,   428,   429,
     231,   345,   346,   543,   347,   527,   528,   348,   349,   350,
     351,   530,   548,   489,   352,   482,   353,    69,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -457
static const yytype_int16 yypact[] =
{
    2027,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,   -15,  -457,  -457,    36,   -74,  1972,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,    12,  -457,  -457,
    -457,   -64,    24,  -457,    82,  2027,  -457,  -457,  -457,    14,
    -457,  2625,  2625,  2625,  -457,  2625,  -457,  -457,  -457,    36,
    -457,    -8,  -457,   -56,    11,   813,    28,  2321,   -18,  -457,
    -457,  -457,    26,  1972,  -457,  1990,    31,  2043,    42,  2043,
    2043,  -457,    47,  1637,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,    67,  -457,  1972,  -457,   -16,   -57,    89,
      39,   100,     2,    52,    18,   193,    -1,  -457,  -457,  -457,
      36,    58,  1637,    73,    -8,  -457,    28,  -457,  -457,  -457,
     -72,  -457,    69,  -457,    28,  -457,  -457,  -457,  -457,  -457,
      74,  -457,  1710,  1239,    19,  1972,  -457,  1972,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,    98,  -457,
    -457,   102,   111,  -457,   813,  -457,   -56,  -457,  -457,   106,
    2572,  -457,    36,   101,    51,  1637,  -457,  2625,  1972,  -457,
    2625,  -457,  -457,  1972,   265,  -457,  -457,    63,    -9,   131,
    -457,  -457,  -457,  1587,  -457,  1972,  -457,  1972,  1972,  1972,
    1972,  1972,  1972,  1972,  1972,  1972,  1972,  1972,  1972,  1972,
    1972,  1972,  1972,  -457,  -457,  -457,  -113,  -457,   114,    36,
     139,   141,  -457,    -8,    24,  -457,   556,  1239,   121,  1872,
    -457,   152,  -457,  1803,   153,  -457,  -457,  -457,    14,   597,
    -457,  1239,  -457,  2625,    84,  -457,  -457,  -457,    36,  1972,
    1972,  -457,  -457,  -457,   154,  -457,  -457,   191,   176,   177,
     178,   180,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  1972,  -457,  -457,  2215,  1821,     6,  -457,
      37,  1972,    36,  -457,   182,   184,    36,   -96,  -457,  -457,
    -457,   -16,   -16,   -57,   -57,    89,    89,    89,    89,    39,
      39,   100,     2,    52,  1972,  1972,  1972,    36,  -457,  1972,
    -457,   -99,  -457,  -457,  -457,    88,  -457,  -457,  -457,  2572,
     174,  1872,  -457,  1972,  -457,   179,  -457,  -457,  -457,  1972,
    -457,   187,   188,  -457,  -457,  -457,    36,   168,   170,  1198,
     172,   196,  -457,  -457,   -62,  -457,  1321,  -457,  -457,  1015,
    -457,  -457,   186,  -457,   761,   925,  -457,  -457,   199,  1321,
     202,  -457,  -457,  -457,   201,  -457,  -457,    15,   204,   211,
    -457,  -457,  -457,    36,    93,   212,   214,  -457,   218,  -457,
    -457,    36,  2370,  -457,  1972,  -457,   219,   220,  -457,   221,
      37,   224,  1892,  -457,  -457,  -457,  1972,  -457,  -457,    18,
     193,    10,  -457,  -457,  -457,    36,  1972,   556,  -457,   -47,
    -457,   -95,  1380,  -457,    40,  -457,   226,   228,  -457,   223,
     229,  1972,  1972,   213,  -457,  -457,  -457,   -41,  -457,   283,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  1105,  2473,  -457,
    1972,   295,  1486,  -457,  2166,  -457,    13,  -457,  2522,  -457,
    -457,  1972,  -457,  -457,    75,  -457,   233,    99,  -457,   235,
    -457,  -457,  -457,  -457,  -457,  2625,  -457,   239,  -457,  1972,
    -457,   242,  -457,  -457,  -457,   -37,  -457,  -457,  -457,  1972,
     -32,  -457,   244,  -457,  -457,  -457,  -457,   103,   115,  -457,
    -457,  -457,   251,  -457,  2473,   118,   255,   254,  1972,   236,
    -457,  -457,   257,  -457,  -457,  1972,  1972,  -457,  2370,  1972,
     258,  -457,  -457,  -457,  -457,   556,  -457,    40,  -457,  1972,
    -457,  -457,   240,  -457,  1972,   241,  1972,  -457,    36,   -82,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  1321,  1321,  -457,
    1321,   123,  1972,   243,  -457,  -457,   320,  -457,  -457,   246,
     267,  1972,  1321,  -457,  -457,  -457,   268,  -457,  1321,  1321,
    -457,  -457
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -457,  -457,  -457,   367,  -457,  -457,  -457,   259,  -457,   197,
    -457,  -457,  -457,  -457,  -457,   -83,  -457,  -457,  -457,  -457,
      30,    66,  -457,   112,    78,    85,     3,    81,   217,   227,
     222,   125,   126,  -457,  -457,  -457,   119,  -457,  -115,  -457,
     -43,  -457,   -49,     9,     1,   -17,  -457,   208,   -36,  -457,
    -457,    34,  -457,  -457,  -457,  -457,  -127,   225,   -61,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,    35,  -457,   -67,
    -457,   237,   150,  -457,   -40,     7,   400,    25,  -457,  -457,
    -457,     8,  -457,   383,  -457,   215,  -230,  -457,    16,   -50,
    -255,  -256,  -457,  -376,  -457,  -457,  -326,  -457,  -457,  -457,
    -457,  -457,  -457,   109,  -105,  -457,  -318,  -457,  -457,  -457,
    -225,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -456,  -457,  -457,  -457,  -457,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -313
static const yytype_int16 yytable[] =
{
      70,    49,   113,   358,   344,   222,   157,    61,    66,    48,
     421,   377,   380,   423,    72,     1,     1,     1,     1,   426,
     204,   462,     1,   431,   164,    63,   425,     1,   230,     1,
     297,     1,   515,   179,   125,   126,   127,   111,   128,     1,
     177,    71,    70,     1,   297,    70,    49,   265,   465,    70,
     388,   298,    61,    66,    48,   194,   195,   124,   251,   131,
     533,   265,   211,   210,   535,   394,    70,    73,   275,   466,
      63,   214,   163,    61,    63,   158,   540,   112,   180,   181,
     182,   265,   117,   221,   178,   546,   236,  -226,   237,  -226,
     215,   156,   222,   190,   191,   162,   316,   395,   396,   243,
     420,   306,   265,   192,   193,  -226,  -226,   395,   396,   483,
     208,   507,   230,   178,   463,   248,    70,   249,   198,   199,
     250,   480,   177,   213,    70,   177,   356,   504,    96,   524,
     508,   213,   266,   187,   235,   107,   267,   132,   188,   189,
      43,   166,   277,   169,   161,   171,   172,   266,   373,   156,
     200,   267,   134,   265,   434,    42,   434,   459,   267,   205,
     267,   232,   244,    43,    43,    42,   178,   242,   178,    42,
     310,   178,   167,    43,   315,   110,   119,   202,   381,   377,
     380,    42,   382,   170,   316,    96,   268,   469,   173,    43,
     365,   366,   107,   246,   247,   196,   197,   285,   286,   287,
     288,   536,   537,   484,   538,   264,   265,   186,   183,   208,
     201,   184,   185,   203,    70,   212,   547,   493,   379,   494,
     495,   209,   550,   551,    96,   500,   362,   363,    70,   354,
     216,   107,   395,   396,   357,   440,   363,  -203,   235,   238,
     355,   497,   498,   239,    96,   510,   265,    96,   157,    96,
     393,   107,   240,   391,   107,    43,   107,   511,   265,   450,
     513,   265,   406,   245,   407,   539,   265,   357,   281,   282,
     409,   275,   384,   271,   268,   299,   387,   283,   284,   289,
     290,   302,   306,   303,   309,   368,   417,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   208,   312,   278,
     279,   280,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,   317,   367,   435,   369,   370,
     405,   371,   449,   372,   385,   408,   413,   386,   411,   412,
     414,    96,   415,   457,   418,    96,   354,   419,   107,   354,
     430,   157,   107,   432,   354,   354,   437,   461,   433,   354,
     333,    96,    96,   355,   438,   441,   442,    70,   107,   107,
     443,   451,   452,   439,   472,   436,   454,   453,   477,   478,
     475,   445,   473,   178,   474,   479,   476,   481,   486,    96,
     496,   520,   499,   383,   522,   501,   107,   485,   503,   487,
     306,   509,   492,   512,   113,   460,   514,   265,   516,   517,
     523,   542,   529,   532,    70,   541,    96,    96,   544,   545,
     549,    96,   118,   241,   308,   521,   458,   291,   107,   389,
     506,   390,   304,    96,   293,    96,   262,   354,   292,   505,
     107,    96,   107,   464,    70,   357,    70,   468,   107,   357,
     525,   488,   436,   213,   311,   487,   301,   392,   449,   123,
     159,   424,   519,   364,   491,     0,   357,     0,     0,     0,
     526,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,   531,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   355,    96,     0,     0,     0,   487,   178,
       0,   107,     0,     0,     0,     0,     0,    70,    96,     0,
       0,     0,     0,     0,     0,   107,     0,     0,   534,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   354,     0,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,     0,     0,     0,     0,     0,   354,   354,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     1,
     107,     0,    74,    75,    76,    77,    78,     0,    79,    80,
       0,    96,     0,     0,     0,     0,     0,     0,   502,     0,
       0,    96,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       1,     2,     3,    74,    75,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,   107,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      81,   318,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,   319,   320,   321,     0,   322,
     323,   324,   325,   326,   327,   328,   329,     0,     0,     0,
       0,    81,   330,    82,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,     0,     0,    38,    39,    40,     0,     0,     0,
       0,    41,     0,     0,    82,     0,     0,   331,    83,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     225,   333,   224,     0,     1,     2,     3,    74,    75,    76,
      77,    78,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,     0,    15,    16,    17,     0,     0,
      18,    19,    20,    21,     0,   318,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     0,   319,
     320,   321,     0,   322,   323,   324,   325,   326,   327,   328,
     329,     0,   135,     0,     0,    81,   330,     0,     0,     0,
     136,   137,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,     0,     0,     0,     0,    41,     0,     0,    82,     0,
       0,   331,    83,   143,   144,   145,   146,     0,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   332,   225,  -305,   224,     0,     1,  -309,
    -309,    74,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,   147,   148,   149,   150,     0,   151,   152,
       0,     0,     0,     0,     0,     0,     0,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,     0,  -309,  -309,  -309,     0,  -309,
    -309,  -309,     0,     0,  -309,  -309,  -309,  -309,     0,   318,
       0,     0,     0,     0,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,     0,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,     0,     0,   319,   320,   321,     0,   322,   323,   324,
     325,   326,   327,   328,   329,     0,   224,     0,     1,    81,
     330,    74,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -309,  -309,  -309,     0,     0,     0,     0,  -309,
       0,     0,    82,     0,     0,   331,    83,     0,     0,   318,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,   332,   225,  -307,
       0,     0,     0,   319,   320,   321,     0,   322,   323,   324,
     325,   326,   327,   328,   329,     0,   224,     0,     1,    81,
     330,    74,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,   331,    83,     0,     0,   318,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,   332,   225,   422,
       0,     0,     0,   319,   320,   321,     0,   322,   323,   324,
     325,   326,   327,   328,   329,     0,     0,     0,     0,    81,
     330,     1,     0,     0,    74,    75,    76,    77,    78,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,    82,     2,     3,   331,    83,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,   332,   225,  -312,
       0,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    81,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     1,     0,     0,    74,    75,    76,
      77,    78,     0,    79,    80,    82,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,    38,    39,    40,     0,
       0,     0,     0,    41,     0,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     320,   321,   225,   322,   323,   324,   325,   326,   327,   328,
     329,     0,     0,     0,     0,    81,   330,     9,    10,     0,
      11,    12,    13,     0,     0,    16,    17,     0,     0,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     0,    82,     0,
       0,   331,    83,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   332,   225,     0,     0,     0,     0,     1,
       2,     3,    74,    75,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,    13,     0,
      15,    16,    17,     0,     0,    18,    19,    20,    21,     0,
       0,     0,     0,     0,   467,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,    74,    75,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,     0,     0,
      41,     0,     0,    82,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
       1,     2,     3,    74,    75,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
       0,    81,    16,    17,     0,     0,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,     1,     0,     3,    74,    75,    76,    77,
      78,     0,    79,    80,    82,     0,     0,     0,    83,   273,
       0,    81,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,     0,     0,   219,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,     0,    38,    39,    40,     0,     0,     0,
       0,    41,     0,     0,    82,     0,     0,     0,    83,    31,
      32,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     1,     0,     3,    74,
      75,    76,    77,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,    74,    75,    76,
      77,    78,     0,    79,    80,     0,     0,   313,     0,    40,
       9,    10,     0,     0,     0,     0,     0,    82,     0,     0,
       0,    83,    18,    19,    20,    21,   220,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     1,     0,     3,    74,    75,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,    81,    74,    75,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     9,
      10,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
      82,    31,    32,     0,    83,     0,     0,     0,     0,   314,
       0,    84,    85,    86,    87,    88,    89,     0,    82,     0,
       0,     0,    83,     0,     0,     0,    81,   378,     0,    84,
      85,    86,    87,    88,    89,     1,     0,     0,    74,    75,
      76,    77,    78,     0,    79,    80,    81,     0,     0,     0,
       0,     0,     0,     1,     0,     0,    74,    75,    76,    77,
      78,    40,    79,    80,     0,     0,     0,     0,     0,    82,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    82,
       1,     2,     3,    83,     0,     0,     0,     0,   456,     0,
      84,    85,    86,    87,    88,    89,     1,     0,     0,    74,
      75,    76,    77,    78,     0,    79,    80,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    81,    11,    12,    13,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
       0,     0,     0,     0,    81,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,     0,    82,     0,     0,
       0,   165,     0,     0,     0,     0,     0,    81,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    42,     1,
       2,     3,     0,     0,     0,     0,    43,     0,     0,     0,
      82,     0,     0,     0,   168,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,     0,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,    13,     0,
       0,    16,    17,     0,     0,    18,    19,    20,    21,     2,
       3,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,     0,
      16,    17,     0,     0,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,     0,     0,    38,    39,    40,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,   434,   375,     0,
       0,   267,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,   266,   375,     9,    10,
     267,    11,    12,    13,    43,     0,    16,    17,     0,     0,
      18,    19,    20,    21,     2,     3,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,     0,     0,    16,    17,     0,     0,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     0,     0,   446,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
       0,     0,     0,     0,    41,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,    15,    16,    17,
       0,     0,    18,    19,    20,    21,     2,     3,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,     0,     0,    16,    17,     0,
       0,    18,    19,    20,    21,   490,     2,     3,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,     0,     0,
      38,    39,    40,     0,     0,     0,     0,    41,     0,     9,
      10,     0,    11,    12,    13,     0,     0,    16,    17,     0,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     2,
       3,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,     0,    38,
      39,    40,     0,     0,     0,     0,    41,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,     0,
      16,    17,     0,     0,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,     0,     0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       0,     0,    42,   233,   229,   132,    67,     0,     0,     0,
     336,   266,   268,   339,    14,     3,     3,     3,     3,   345,
      21,   397,     3,   349,    73,     0,   344,     3,   133,     3,
     143,     3,   488,    83,    51,    52,    53,    37,    55,     3,
      83,    56,    42,     3,   143,    45,    45,   143,   143,    49,
     146,   164,    45,    45,    45,    16,    17,    49,   173,    59,
     516,   143,   112,   112,   146,   164,    66,   141,   183,   164,
      45,   143,    72,    66,    49,    67,   532,   141,    11,    12,
      13,   143,     0,   132,    83,   541,   135,   143,   137,   145,
     162,    66,   219,   150,   151,    69,   223,   144,   145,   160,
     162,   216,   143,    14,    15,   161,   162,   144,   145,   427,
     110,   143,   217,   112,   161,   165,   116,   167,    18,    19,
     170,   162,   165,   116,   124,   168,   231,   164,    16,   505,
     162,   124,   141,   149,   134,    16,   145,   145,   154,   155,
     149,    75,   185,    77,   162,    79,    80,   141,   263,   124,
     148,   145,   141,   143,   141,   141,   141,   147,   145,   160,
     145,   142,   162,   149,   149,   141,   165,   159,   167,   141,
     219,   170,   141,   149,   223,   163,   162,   159,   141,   434,
     436,   141,   145,   141,   311,    73,   178,   147,   141,   149,
     239,   240,    73,   142,   143,   156,   157,   194,   195,   196,
     197,   527,   528,   428,   530,   142,   143,    95,   141,   209,
     158,   144,   145,    20,   214,   142,   542,   142,   267,   144,
     145,   163,   548,   549,   112,   455,   142,   143,   228,   229,
     161,   112,   144,   145,   233,   142,   143,   163,   238,   141,
     231,   142,   143,   141,   132,   142,   143,   135,   309,   137,
     299,   132,   141,   296,   135,   149,   137,   142,   143,   374,
     142,   143,   311,   162,   313,   142,   143,   266,   190,   191,
     319,   386,   272,   142,   266,   161,   276,   192,   193,   198,
     199,   142,   397,   142,   163,    94,   329,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   297,   146,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   162,   162,   357,   142,   142,
     146,   143,   372,   143,   142,   146,   326,   143,   141,   141,
     162,   219,   162,   382,   162,   223,   336,   141,   219,   339,
     141,   402,   223,   141,   344,   345,   142,   396,   147,   349,
     164,   239,   240,   344,   143,   143,   142,   357,   239,   240,
     142,   142,   142,   363,   404,   357,   142,   146,   411,   412,
     147,   371,   146,   372,   146,   162,   147,    94,    83,   267,
     147,   496,   147,   271,   499,   146,   267,   430,   146,   432,
     505,   147,   441,   142,   434,   395,   141,   143,   162,   142,
     142,    81,   162,   162,   404,   162,   294,   295,   162,   142,
     142,   299,    45,   154,   217,   498,   386,   200,   299,   294,
     469,   295,   214,   311,   202,   313,   161,   427,   201,   465,
     311,   319,   313,   399,   434,   434,   436,   402,   319,   438,
     507,   432,   434,   436,   219,   488,   209,   297,   498,    49,
      67,   342,   495,   238,   438,    -1,   455,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,
      -1,   514,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,   484,   382,    -1,    -1,    -1,   541,   498,
      -1,   382,    -1,    -1,    -1,    -1,    -1,   507,   396,    -1,
      -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    -1,
     530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,   548,   549,
      -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,     3,
     441,    -1,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,
      -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,   509,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      -1,    44,    45,    46,    -1,    -1,    49,    50,    51,    52,
      94,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,   137,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,   137,    -1,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    -1,    44,    45,    46,    -1,    -1,
      49,    50,    51,    52,    -1,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    78,
      79,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    39,    -1,    -1,    94,    95,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,    -1,    -1,    -1,    -1,   134,    -1,    -1,   137,    -1,
      -1,   140,   141,    90,    91,    92,    93,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,    -1,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    -1,    44,
      45,    46,    -1,    -1,    49,    50,    51,    52,    -1,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,     1,    -1,     3,    94,
      95,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,   134,
      -1,    -1,   137,    -1,    -1,   140,   141,    -1,    -1,    54,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,     1,    -1,     3,    94,
      95,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,   140,   141,    -1,    -1,    54,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,     3,    -1,    -1,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,   137,     4,     5,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    -1,    44,    45,    46,    -1,    -1,    49,    50,
      51,    52,    94,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,   137,    -1,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,   134,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,   163,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    37,    38,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,   137,    -1,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    -1,
      44,    45,    46,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,   164,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      -1,    94,    45,    46,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,   137,    -1,    -1,    -1,   141,   142,
      -1,    94,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,   127,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,   141,    69,
      70,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    34,    -1,   129,
      37,    38,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   141,    49,    50,    51,    52,   146,    -1,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    94,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    69,    70,    -1,   141,    -1,    -1,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,   137,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    94,   146,    -1,   148,
     149,   150,   151,   152,   153,     3,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    12,    13,    94,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,     9,
      10,   129,    12,    13,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,   137,
       3,     4,     5,   141,    -1,    -1,    -1,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,     3,    -1,    -1,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    94,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    94,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   137,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    94,   148,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,     3,
       4,     5,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     137,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    52,     4,
       5,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,    -1,
      -1,   145,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,    37,    38,
     145,    40,    41,    42,   149,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,     4,     5,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
      -1,    -1,    -1,    -1,   134,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    -1,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,     4,     5,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    -1,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,     4,     5,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,    -1,   134,    -1,    37,
      38,    -1,    40,    41,    42,    -1,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,     4,
       5,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,   127,
     128,   129,    -1,    -1,    -1,    -1,   134,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,   134
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,    32,    33,    34,    35,    36,    37,
      38,    40,    41,    42,    43,    44,    45,    46,    49,    50,
      51,    52,    59,    60,    61,    62,    63,    64,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    75,   127,   128,
     129,   134,   141,   149,   166,   167,   168,   169,   208,   209,
     210,   217,   218,   219,   221,   223,   224,   225,   226,   228,
     235,   240,   241,   242,   243,   244,   246,   247,   260,   292,
     293,    56,   293,   141,     6,     7,     8,     9,    10,    12,
      13,    94,   137,   141,   148,   149,   150,   151,   152,   153,
     177,   178,   181,   182,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   199,   201,   207,   293,
     163,   293,   141,   239,   240,   242,   246,     0,   168,   162,
     211,   212,   239,   241,   246,   210,   210,   210,   210,   229,
     230,   293,   145,   170,   141,    39,    47,    48,    54,    55,
      56,    57,    58,    90,    91,    92,    93,   130,   131,   132,
     133,   135,   136,   172,   173,   220,   242,   223,   246,   248,
     249,   162,    69,   293,   207,   141,   186,   141,   141,   186,
     141,   186,   186,   141,   188,   201,   203,   205,   209,   254,
      11,    12,    13,   141,   144,   145,   188,   149,   154,   155,
     150,   151,    14,    15,    16,    17,   156,   157,    18,    19,
     148,   158,   159,    20,    21,   160,   236,   237,   293,   163,
     207,   254,   142,   240,   143,   162,   161,   171,   227,    34,
     146,   207,   221,   222,     1,   163,   174,   208,   209,   267,
     269,   275,   142,   245,   250,   293,   207,   207,   141,   141,
     141,   172,   246,   223,   293,   162,   142,   143,   254,   254,
     254,   203,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   161,   204,   142,   143,   141,   145,   246,   255,
     256,   142,   184,   142,   185,   203,   183,   205,   188,   188,
     188,   189,   189,   190,   190,   191,   191,   191,   191,   192,
     192,   193,   194,   195,   198,   200,   202,   143,   164,   161,
     238,   236,   142,   142,   212,   163,   203,   258,   174,   163,
     207,   222,   146,    34,   146,   207,   221,   162,    54,    78,
      79,    80,    82,    83,    84,    85,    86,    87,    88,    89,
      95,   140,   162,   164,   205,   261,   262,   263,   264,   265,
     268,   269,   270,   271,   275,   276,   277,   279,   282,   283,
     284,   285,   289,   291,   293,   208,   269,   209,   251,   252,
     253,   254,   142,   143,   250,   207,   207,   162,    94,   142,
     142,   143,   143,   203,   206,   142,   251,   255,   146,   207,
     256,   141,   145,   188,   293,   142,   143,   293,   146,   196,
     197,   205,   237,   207,   164,   144,   145,   213,   214,   215,
     216,   259,   231,   232,   248,   146,   207,   207,   146,   207,
     266,   141,   141,   293,   162,   162,   162,   205,   162,   141,
     162,   261,   164,   261,   268,   271,   261,   272,   273,   274,
     141,   261,   141,   147,   141,   239,   246,   142,   143,   293,
     142,   143,   142,   142,   175,   293,    79,   179,   180,   254,
     203,   142,   142,   146,   142,   257,   146,   207,   185,   147,
     293,   207,   258,   161,   216,   143,   164,   164,   232,   147,
     233,   234,   239,   146,   146,   147,   147,   205,   205,   162,
     162,    94,   290,   271,   275,   205,    83,   205,   208,   288,
      53,   253,   207,   142,   144,   145,   147,   142,   143,   147,
     251,   146,   201,   146,   164,   213,   207,   143,   162,   147,
     142,   142,   142,   142,   141,   288,   162,   142,   176,   205,
     203,   180,   203,   142,   258,   234,   207,   280,   281,   162,
     286,   205,   162,   288,   293,   146,   261,   261,   261,   142,
     288,   162,    81,   278,   162,   142,   288,   261,   287,   142,
     261,   261
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 150 "SDCC.y"
    {
          werror(W_EMPTY_SOURCE_FILE);
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 163 "SDCC.y"
    {
          // blockNo = 0;
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 167 "SDCC.y"
    {
          ignoreTypedefType = 0;
          if ((yyvsp[(1) - (1)].sym) && (yyvsp[(1) - (1)].sym)->type && IS_FUNC((yyvsp[(1) - (1)].sym)->type))
            {
              /* The only legal storage classes for
               * a function prototype (declaration)
               * are extern and static. extern is the
               * default. Thus, if this function isn't
               * explicitly marked static, mark it
               * extern.
               */
              if ((yyvsp[(1) - (1)].sym)->etype && IS_SPEC((yyvsp[(1) - (1)].sym)->etype) && !SPEC_STAT((yyvsp[(1) - (1)].sym)->etype))
                {
                  SPEC_EXTR((yyvsp[(1) - (1)].sym)->etype) = 1;
                }
            }
          addSymChain (&(yyvsp[(1) - (1)].sym));
          allocVariables ((yyvsp[(1) - (1)].sym));
          cleanUpLevel (SymbolTab, 1);
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 188 "SDCC.y"
    {
          /* These empty braces here are apparently required by some version of GNU bison on MS Windows. See bug #2858. */
        }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 195 "SDCC.y"
    {   /* function type not specified */
            /* assume it to be 'int'       */
            addDecl((yyvsp[(1) - (1)].sym),0,newIntLink());
            (yyvsp[(1) - (1)].sym) = createFunctionDecl((yyvsp[(1) - (1)].sym));
            if ((yyvsp[(1) - (1)].sym) && FUNC_ISCRITICAL ((yyvsp[(1) - (1)].sym)->type))
                inCriticalFunction = 1;
        }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 203 "SDCC.y"
    {
            (yyval.asts) = createFunction((yyvsp[(1) - (3)].sym),(yyvsp[(3) - (3)].asts));
            if ((yyvsp[(1) - (3)].sym) && FUNC_ISCRITICAL ((yyvsp[(1) - (3)].sym)->type))
                inCriticalFunction = 0;
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 209 "SDCC.y"
    {
            sym_link *p = copyLinkChain((yyvsp[(1) - (2)].lnk));
            pointerTypes((yyvsp[(2) - (2)].sym)->type,p);
            addDecl((yyvsp[(2) - (2)].sym),0,p);
            (yyvsp[(2) - (2)].sym) = createFunctionDecl((yyvsp[(2) - (2)].sym));
            if ((yyvsp[(2) - (2)].sym) && FUNC_ISCRITICAL ((yyvsp[(2) - (2)].sym)->type))
                inCriticalFunction = 1;
            /* warn for loss of calling convention for inlined functions. */
            if ((yyvsp[(2) - (2)].sym) && FUNC_ISINLINE ((yyvsp[(2) - (2)].sym)->type) &&
                ( FUNC_ISZ88DK_CALLEE ((yyvsp[(2) - (2)].sym)->type) || FUNC_ISZ88DK_FASTCALL ((yyvsp[(2) - (2)].sym)->type) ||
                  FUNC_BANKED ((yyvsp[(2) - (2)].sym)->type)         || FUNC_REGBANK ((yyvsp[(2) - (2)].sym)->type)          ||
                  FUNC_ISOVERLAY ((yyvsp[(2) - (2)].sym)->type)      || FUNC_ISISR ((yyvsp[(2) - (2)].sym)->type) ))
              {
                werror (W_INLINE_FUNCATTR, (yyvsp[(2) - (2)].sym)->name);
              }
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 226 "SDCC.y"
    {
            (yyval.asts) = createFunction((yyvsp[(2) - (4)].sym),(yyvsp[(4) - (4)].asts));
            if ((yyvsp[(2) - (4)].sym) && FUNC_ISCRITICAL ((yyvsp[(2) - (4)].sym)->type))
                inCriticalFunction = 0;
        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 235 "SDCC.y"
    { (yyval.lnk) = mergeSpec((yyvsp[(1) - (2)].lnk),(yyvsp[(2) - (2)].lnk),"function_attribute"); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 239 "SDCC.y"
    {
                        (yyval.lnk) = newLink(SPECIFIER);
                        FUNC_REGBANK((yyval.lnk)) = (int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts),TRUE));
                     }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 243 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISREENT((yyval.lnk))=1;
                     }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 246 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISCRITICAL((yyval.lnk)) = 1;
                     }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 249 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISNAKED((yyval.lnk))=1;
                     }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 252 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISJAVANATIVE((yyval.lnk))=1;
                     }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 255 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISOVERLAY((yyval.lnk))=1;
                     }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 258 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_NONBANKED((yyval.lnk)) = 1;
                        if (FUNC_BANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 264 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSHADOWREGS((yyval.lnk)) = 1;
                     }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 267 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISWPARAM((yyval.lnk)) = 1;
                     }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 270 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_BANKED((yyval.lnk)) = 1;
                        if (FUNC_NONBANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 277 "SDCC.y"
    {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = (yyvsp[(1) - (1)].yyint);
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 283 "SDCC.y"
    {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = INTNO_TRAP;
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 288 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSMALLC((yyval.lnk)) = 1;
                     }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 291 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_FASTCALL((yyval.lnk)) = 1;
                     }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 294 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_CALLEE((yyval.lnk)) = 1;
                     }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 298 "SDCC.y"
    {
                        value *offset_v = constExprValue ((yyvsp[(3) - (4)].asts), TRUE);
                        int    offset = 0;
                        (yyval.lnk) = newLink(SPECIFIER);
                        if  ( offset_v ) 
                          offset = ulFromVal(offset_v);
                        (yyval.lnk)->funcAttrs.z88dk_params_offset = offset;
                     }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 307 "SDCC.y"
    {
                        value *rst_v = constExprValue ((yyvsp[(3) - (6)].asts), TRUE);
                        value *value_v = constExprValue ((yyvsp[(5) - (6)].asts), TRUE);
                        int rst = -1, value = -1;
                        (yyval.lnk) = newLink(SPECIFIER);

                        if  ( rst_v ) 
                          rst = ulFromVal(rst_v);
                        if  ( value_v ) 
                          value = ulFromVal(value_v);
          
                        if ( rst < 0 || rst > 56 || ( rst % 8 ) )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "rst", rst);
                          }
                        if ( value < 0 || value > 0xfff )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "value", value);
                          }
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_rst = rst;
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_val = value;
                        FUNC_ISZ88DK_SHORTCALL((yyval.lnk)) = 1;
                     }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 331 "SDCC.y"
    {
                        const struct symbol *regsym;
                        (yyval.lnk) = newLink (SPECIFIER);

                        for(regsym = (yyvsp[(3) - (4)].sym); regsym; regsym = regsym->next)
                          {
                            int regnum;

                            if (!port->getRegByName || ((regnum = port->getRegByName(regsym->name)) < 0))
                              werror (W_UNKNOWN_REG, regsym->name);
                            else
                              (yyval.lnk)->funcAttrs.preserved_regs[regnum] = TRUE;
                          }
                     }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 350 "SDCC.y"
    {
                       werror (E_OLD_STYLE, ((yyvsp[(1) - (2)].sym) ? (yyvsp[(1) - (2)].sym)->name: ""));
                       /*exit (1)*/sdcc_fatal_exit();
                     }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 357 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[(1) - (1)].sym))); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 358 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 359 "SDCC.y"
    {
                       ignoreTypedefType = 0;
                       (yyvsp[(4) - (4)].sym) = newSymbol ((yyvsp[(4) - (4)].sym)->name, NestLevel);
                       (yyvsp[(4) - (4)].sym)->implicit = 1;
                       (yyval.asts) = newNode ('.', (yyvsp[(1) - (4)].asts), newAst_VALUE (symbolVal ((yyvsp[(4) - (4)].sym))));
                     }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 366 "SDCC.y"
    {
                       (yyval.asts) = newNode ('[', (yyvsp[(1) - (4)].asts), (yyvsp[(3) - (4)].asts));
                     }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 372 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[(1) - (1)].sym))); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 373 "SDCC.y"
    { (yyval.asts) = newAst_VALUE ((yyvsp[(1) - (1)].val)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 375 "SDCC.y"
    { (yyval.asts) = (yyvsp[(2) - (3)].asts); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 380 "SDCC.y"
    { (yyval.asts) = newNode (GENERIC, (yyvsp[(3) - (6)].asts), (yyvsp[(5) - (6)].asts)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 384 "SDCC.y"
    { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, NULL, (yyvsp[(1) - (1)].asts)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 385 "SDCC.y"
    { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, (yyvsp[(1) - (3)].asts), (yyvsp[(3) - (3)].asts)); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 389 "SDCC.y"
    { (yyval.asts) = newNode  (GENERIC_ASSOCIATION, newAst_LINK((yyvsp[(1) - (3)].lnk)), (yyvsp[(3) - (3)].asts)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 390 "SDCC.y"
    { (yyval.asts) = newNode  (GENERIC_ASSOCIATION,NULL,(yyvsp[(3) - (3)].asts)); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 394 "SDCC.y"
    {
                       int cnt = 1;
                       int max = 253, min = 1;
                       char fb[256];
                       /* refer to support/cpp/libcpp/macro.c for details */
                       while ((((int) ((yyvsp[(1) - (1)].yystr)[cnt] & 0xff)) & 0xff) == 0xff)
                         cnt++;

                       if (cnt <= max)
                         {
                           (yyval.asts) = newAst_VALUE (strVal ((yyvsp[(1) - (1)].yystr)));
                         }
                       else
                         {
                           memset (fb, 0x00, sizeof (fb));
                           fb[0] = '"';
                           strncpy (fb + 1, function_name, max - min + 1);
                           fb[max + 1] = '"';
                           fb[max + 2] = 0;
                           fb[strlen (fb)] = '"';
                           fb[strlen (fb) + 1] = 0;
                           (yyval.asts) = newAst_VALUE (strVal (fb));
                         }
                     }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 422 "SDCC.y"
    { (yyval.asts) = newNode  ('[', (yyvsp[(1) - (4)].asts), (yyvsp[(3) - (4)].asts)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 423 "SDCC.y"
    { (yyval.asts) = newNode  (CALL,(yyvsp[(1) - (3)].asts),NULL);
                                          (yyval.asts)->left->funcName = 1;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 426 "SDCC.y"
    {
            (yyval.asts) = newNode  (CALL,(yyvsp[(1) - (4)].asts),(yyvsp[(3) - (4)].asts)); (yyval.asts)->left->funcName = 1;
          }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 429 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 430 "SDCC.y"
    {
                        ignoreTypedefType = 0;
                        (yyvsp[(4) - (4)].sym) = newSymbol((yyvsp[(4) - (4)].sym)->name,NestLevel);
                        (yyvsp[(4) - (4)].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,newNode('&',(yyvsp[(1) - (4)].asts),NULL),newAst_VALUE(symbolVal((yyvsp[(4) - (4)].sym))));
                      }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 436 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 437 "SDCC.y"
    {
                        ignoreTypedefType = 0;
                        (yyvsp[(4) - (4)].sym) = newSymbol((yyvsp[(4) - (4)].sym)->name,NestLevel);
                        (yyvsp[(4) - (4)].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,(yyvsp[(1) - (4)].asts),newAst_VALUE(symbolVal((yyvsp[(4) - (4)].sym))));
                      }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 444 "SDCC.y"
    { (yyval.asts) = newNode(INC_OP,(yyvsp[(1) - (2)].asts),NULL);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 446 "SDCC.y"
    { (yyval.asts) = newNode(DEC_OP,(yyvsp[(1) - (2)].asts),NULL); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 451 "SDCC.y"
    { (yyval.asts) = newNode(PARAM,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 456 "SDCC.y"
    { (yyval.asts) = newNode (INC_OP, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 457 "SDCC.y"
    { (yyval.asts) = newNode (DEC_OP, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 459 "SDCC.y"
    {
         if ((yyvsp[(1) - (2)].yyint) == '&' && IS_AST_OP ((yyvsp[(2) - (2)].asts)) && (yyvsp[(2) - (2)].asts)->opval.op == '*' && (yyvsp[(2) - (2)].asts)->right == NULL)
           (yyval.asts) = (yyvsp[(2) - (2)].asts)->left;
         else if ((yyvsp[(1) - (2)].yyint) == '*' && IS_AST_OP ((yyvsp[(2) - (2)].asts)) && (yyvsp[(2) - (2)].asts)->opval.op == '&' && (yyvsp[(2) - (2)].asts)->right == NULL)
           (yyval.asts) = (yyvsp[(2) - (2)].asts)->left;
         else
           (yyval.asts) = newNode ((yyvsp[(1) - (2)].yyint), (yyvsp[(2) - (2)].asts), NULL);
       }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 467 "SDCC.y"
    { (yyval.asts) = newNode (SIZEOF, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 468 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (sizeofOp ((yyvsp[(3) - (4)].lnk))); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 469 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (alignofOp ((yyvsp[(3) - (4)].lnk))); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 470 "SDCC.y"
    { (yyval.asts) = newNode (TYPEOF, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 471 "SDCC.y"
    { (yyval.asts) = offsetofOp((yyvsp[(3) - (6)].lnk), (yyvsp[(5) - (6)].asts)); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 475 "SDCC.y"
    { (yyval.yyint) = '&';}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 476 "SDCC.y"
    { (yyval.yyint) = '*';}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 477 "SDCC.y"
    { (yyval.yyint) = '+';}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 478 "SDCC.y"
    { (yyval.yyint) = '-';}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 479 "SDCC.y"
    { (yyval.yyint) = '~';}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 480 "SDCC.y"
    { (yyval.yyint) = '!';}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 485 "SDCC.y"
    { (yyval.asts) = newNode(CAST,newAst_LINK((yyvsp[(2) - (4)].lnk)),(yyvsp[(4) - (4)].asts)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 490 "SDCC.y"
    { (yyval.asts) = newNode('*',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 491 "SDCC.y"
    { (yyval.asts) = newNode('/',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 492 "SDCC.y"
    { (yyval.asts) = newNode('%',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 497 "SDCC.y"
    { (yyval.asts)=newNode('+',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 498 "SDCC.y"
    { (yyval.asts)=newNode('-',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 503 "SDCC.y"
    { (yyval.asts) = newNode(LEFT_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 504 "SDCC.y"
    { (yyval.asts) = newNode(RIGHT_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 509 "SDCC.y"
    { (yyval.asts) = newNode('<',  (yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 510 "SDCC.y"
    { (yyval.asts) = newNode('>',  (yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 511 "SDCC.y"
    { (yyval.asts) = newNode(LE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 512 "SDCC.y"
    { (yyval.asts) = newNode(GE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 517 "SDCC.y"
    { (yyval.asts) = newNode(EQ_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 518 "SDCC.y"
    { (yyval.asts) = newNode(NE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 523 "SDCC.y"
    { (yyval.asts) = newNode('&',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 528 "SDCC.y"
    { (yyval.asts) = newNode('^',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 533 "SDCC.y"
    { (yyval.asts) = newNode('|',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 538 "SDCC.y"
    { seqPointNo++;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 539 "SDCC.y"
    { (yyval.asts) = newNode(AND_OP,(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 544 "SDCC.y"
    { seqPointNo++;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 545 "SDCC.y"
    { (yyval.asts) = newNode(OR_OP,(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts)); }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 550 "SDCC.y"
    { seqPointNo++;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 551 "SDCC.y"
    {
                        (yyval.asts) = newNode(':',(yyvsp[(4) - (6)].asts),(yyvsp[(6) - (6)].asts));
                        (yyval.asts) = newNode('?',(yyvsp[(1) - (6)].asts),(yyval.asts));
                     }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 560 "SDCC.y"
    {

                             switch ((yyvsp[(2) - (3)].yyint)) {
                             case '=':
                                     (yyval.asts) = newNode((yyvsp[(2) - (3)].yyint),(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));
                                     break;
                             case MUL_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '*', (yyvsp[(3) - (3)].asts));
                                     break;
                             case DIV_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '/', (yyvsp[(3) - (3)].asts));
                                     break;
                             case MOD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '%', (yyvsp[(3) - (3)].asts));
                                     break;
                             case ADD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '+', (yyvsp[(3) - (3)].asts));
                                     break;
                             case SUB_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '-', (yyvsp[(3) - (3)].asts));
                                     break;
                             case LEFT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), LEFT_OP, (yyvsp[(3) - (3)].asts));
                                     break;
                             case RIGHT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), RIGHT_OP, (yyvsp[(3) - (3)].asts));
                                     break;
                             case AND_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '&', (yyvsp[(3) - (3)].asts));
                                     break;
                             case XOR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '^', (yyvsp[(3) - (3)].asts));
                                     break;
                             case OR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '|', (yyvsp[(3) - (3)].asts));
                                     break;
                             default :
                                     (yyval.asts) = NULL;
                             }

                     }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 604 "SDCC.y"
    { (yyval.yyint) = '=';}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 619 "SDCC.y"
    { seqPointNo++;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 619 "SDCC.y"
    { (yyval.asts) = newNode(',',(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts));}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 628 "SDCC.y"
    {
         /* Special case: if incomplete struct/union declared without name, */
         /* make sure an incomplete type for it exists in the current scope */
         if (IS_STRUCT((yyvsp[(1) - (2)].lnk)))
           {
             structdef *sdef = SPEC_STRUCT((yyvsp[(1) - (2)].lnk));
             structdef *osdef;
             osdef = findSymWithBlock (StructTab, sdef->tagsym, currBlockno, NestLevel);
             if (osdef && osdef->block != currBlockno)
               {
                 sdef = newStruct(osdef->tagsym->name);
                 sdef->level = NestLevel;
                 sdef->block = currBlockno;
                 sdef->tagsym = newSymbol (osdef->tagsym->name, NestLevel);
                 addSym (StructTab, sdef, sdef->tag, sdef->level, currBlockno, 0);
                 uselessDecl = FALSE;
               }
           }
         if (uselessDecl)
           werror(W_USELESS_DECL);
         uselessDecl = TRUE;
         (yyval.sym) = NULL;
      }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 652 "SDCC.y"
    {
         /* add the specifier list to the id */
         symbol *sym , *sym1;

         for (sym1 = sym = reverseSyms((yyvsp[(2) - (3)].sym));sym != NULL;sym = sym->next) {
             sym_link *lnk = copyLinkChain((yyvsp[(1) - (3)].lnk));
             sym_link *l0 = NULL, *l1 = NULL, *l2 = NULL;
             /* check illegal declaration */
             for (l0 = sym->type; l0 != NULL; l0 = l0->next)
               if (IS_PTR (l0))
                 break;
             /* check if creating intances of structs with flexible arrays */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_STRUCT (l1) && SPEC_STRUCT (l1)->b_flexArrayMember)
                 break;
             if (!options.std_c99 && l0 == NULL && l1 != NULL && SPEC_EXTR((yyvsp[(1) - (3)].lnk)) != 1)
               werror (W_FLEXARRAY_INSTRUCT, sym->name);
             /* check if creating intances of function type */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_FUNC (l1))
                 break;
             for (l2 = lnk; l2 != NULL; l2 = l2->next)
               if (IS_PTR (l2))
                 break;
             if (l0 == NULL && l2 == NULL && l1 != NULL)
               werrorfl(sym->fileDef, sym->lineDef, E_TYPE_IS_FUNCTION, sym->name);
             /* do the pointer stuff */
             pointerTypes(sym->type,lnk);
             addDecl (sym,0,lnk);
         }

         uselessDecl = TRUE;
         (yyval.sym) = sym1;
      }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 687 "SDCC.y"
    {
         (yyval.sym) = NULL;
      }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 692 "SDCC.y"
    { (yyval.lnk) = finalizeSpec((yyvsp[(1) - (1)].lnk)); }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 695 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 696 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "storage_class_specifier declaration_specifiers - skipped");
   }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 701 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 702 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "type_specifier declaration_specifiers - skipped");
   }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 707 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 708 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "function_specifier declaration_specifiers - skipped");
   }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 713 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 714 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "alignment_specifier declaration_specifiers - skipped");
   }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 723 "SDCC.y"
    { (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym); (yyval.sym) = (yyvsp[(3) - (3)].sym);}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 727 "SDCC.y"
    { (yyvsp[(1) - (1)].sym)->ival = NULL; }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 728 "SDCC.y"
    { (yyvsp[(1) - (3)].sym)->ival = (yyvsp[(3) - (3)].ilist); seqPointNo++; }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 732 "SDCC.y"
    { (yyval.dsgn) = NULL; }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 737 "SDCC.y"
    { (yyval.dsgn) = revDesignation((yyvsp[(1) - (2)].dsgn)); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 742 "SDCC.y"
    { (yyvsp[(2) - (2)].dsgn)->next = (yyvsp[(1) - (2)].dsgn); (yyval.dsgn) = (yyvsp[(2) - (2)].dsgn); }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 747 "SDCC.y"
    {
            value *tval;
            int elemno;

            tval = constExprValue((yyvsp[(2) - (3)].asts), TRUE);
            /* if it is not a constant then Error  */
            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror (E_CONST_EXPECTED);
                elemno = 0; /* arbitrary fixup */
              }
            else
              {
                if ((elemno = (int) ulFromVal(tval)) < 0)
                  {
                    werror (E_BAD_DESIGNATOR);
                    elemno = 0; /* arbitrary fixup */
                  }
              }
            (yyval.dsgn) = newDesignation(DESIGNATOR_ARRAY, &elemno);
         }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 768 "SDCC.y"
    { (yyval.dsgn) = newDesignation(DESIGNATOR_STRUCT,(yyvsp[(2) - (2)].sym)); }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 772 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_TYPEDEF((yyval.lnk)) = 1;
               }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 776 "SDCC.y"
    {
                  (yyval.lnk) = newLink(SPECIFIER);
                  SPEC_EXTR((yyval.lnk)) = 1;
               }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 780 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_STAT((yyval.lnk)) = 1;
               }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 784 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_AUTO;
               }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 788 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_REGISTER;
               }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 795 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_INLINE((yyval.lnk)) = 1;
               }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 799 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_NORETURN((yyval.lnk)) = 1;
               }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 807 "SDCC.y"
    {
                 checkTypeSanity ((yyvsp[(3) - (4)].lnk), "(_Alignas)");
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 1;
              }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 813 "SDCC.y"
    {
                 value *val = constExprValue ((yyvsp[(3) - (4)].asts), TRUE);
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 0;
                 if (!val)
                   werror (E_CONST_EXPECTED);
                 else if (ulFromVal (val) == 0 || isPowerOf2 (ulFromVal (val)) && ulFromVal (val) <= port->mem.maxextalign)
                   SPEC_ALIGNAS((yyval.lnk)) = ulFromVal(val);
                 else
                   werror (E_ALIGNAS, ulFromVal(val));
              }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 827 "SDCC.y"
    { (yyval.yyint) = INTNO_UNSPEC; }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 829 "SDCC.y"
    { 
          value *val = constExprValue((yyvsp[(2) - (2)].asts),TRUE);
          int intno = (int) ulFromVal(val);
          if (val && (intno >= 0) && (intno <= INTNO_MAX))
            (yyval.yyint) = intno;
          else
            {
              werror(E_INT_BAD_INTNO, intno);
              (yyval.yyint) = INTNO_UNSPEC;
            }
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 843 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_CONST((yyval.lnk)) = 1;
               }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 847 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_RESTRICT((yyval.lnk)) = 1;
               }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 851 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_VOLATILE((yyval.lnk)) = 1;
               }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 855 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_ADDRSPACE((yyval.lnk)) = findSym (AddrspaceTab, 0, (yyvsp[(1) - (1)].yychar));
               }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 859 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_XDATA;
               }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 863 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_CODE;
               }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 867 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_EEPROM;
               }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 871 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_DATA;
               }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 875 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_IDATA;
               }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 879 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_PDATA;
               }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 888 "SDCC.y"
    {
                 (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "type_qualifier_list type_qualifier skipped");
               }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 894 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 895 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BOOL;
                  ignoreTypedefType = 1;
               }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 900 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_CHAR;
                  ignoreTypedefType = 1;
               }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 905 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_SHORT((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 910 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_INT;
                  ignoreTypedefType = 1;
               }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 915 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_LONG((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 920 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  (yyval.lnk)->select.s.b_signed = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 925 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_USIGN((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 930 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_VOID;
                  ignoreTypedefType = 1;
               }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 935 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FLOAT;
                  ignoreTypedefType = 1;
               }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 940 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FIXED16X16;
                  ignoreTypedefType = 1;
               }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 945 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BIT;
                  SPEC_SCLS((yyval.lnk)) = S_BIT;
                  SPEC_BLEN((yyval.lnk)) = 1;
                  SPEC_BSTR((yyval.lnk)) = 0;
                  ignoreTypedefType = 1;
               }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 953 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  /* add this to the storage class specifier  */
                  SPEC_ABSA((yyval.lnk)) = 1;   /* set the absolute addr flag */
                  /* now get the abs addr from value */
                  SPEC_ADDR((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts),TRUE));
               }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 960 "SDCC.y"
    {
                                   uselessDecl = FALSE;
                                   (yyval.lnk) = (yyvsp[(1) - (1)].lnk);
                                   ignoreTypedefType = 1;
                                }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 965 "SDCC.y"
    {
                           cenum = NULL;
                           uselessDecl = FALSE;
                           ignoreTypedefType = 1;
                           (yyval.lnk) = (yyvsp[(1) - (1)].lnk);
                        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 972 "SDCC.y"
    {
            symbol *sym;
            sym_link *p;
            sym = findSym(TypedefTab,NULL,(yyvsp[(1) - (1)].yychar));
            (yyval.lnk) = p = copyLinkChain(sym ? sym->type : NULL);
            SPEC_TYPEDEF(getSpec(p)) = 0;
            ignoreTypedefType = 1;
         }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 984 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               SPEC_NOUN((yyval.lnk)) = V_SBIT;
               SPEC_SCLS((yyval.lnk)) = S_SBIT;
               SPEC_BLEN((yyval.lnk)) = 1;
               SPEC_BSTR((yyval.lnk)) = 0;
               ignoreTypedefType = 1;
            }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 996 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1004 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 1;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1015 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1026 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_LONG((yyval.lnk))    = 1;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1039 "SDCC.y"
    {
          structdef *sdef;

          if (! (yyvsp[(2) - (2)].sdef)->tagsym)
            {
              /* no tag given, so new struct def for current scope */
              addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
            }
          else
            {
              sdef = findSymWithBlock (StructTab, (yyvsp[(2) - (2)].sdef)->tagsym, currBlockno, NestLevel);
              if (sdef)
                {
                  /* Error if a complete type already defined in this scope */
                  if (sdef->block == currBlockno)
                    {
                      if (sdef->fields)
                        {
                          werror(E_STRUCT_REDEF, (yyvsp[(2) - (2)].sdef)->tag);
                          werrorfl(sdef->tagsym->fileDef, sdef->tagsym->lineDef, E_PREVIOUS_DEF);
                        }
                      else
                        {
                          (yyvsp[(2) - (2)].sdef) = sdef; /* We are completing an incomplete type */
                        }
                    }
                  else
                    {
                      /* There is an existing struct def in an outer scope. */
                      /* Create new struct def for current scope */
                      addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
                    }
                }
              else
               {
                 /* There is no existing struct def at all. */
                 /* Create new struct def for current scope */
                 addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
               }
            }

          if (!(yyvsp[(2) - (2)].sdef)->type)
            {
              (yyvsp[(2) - (2)].sdef)->type = (yyvsp[(1) - (2)].yyint);
            }
          else
            {
              if ((yyvsp[(2) - (2)].sdef)->type != (yyvsp[(1) - (2)].yyint))
                  werror(E_BAD_TAG, (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(1) - (2)].yyint)==STRUCT ? "struct" : "union");
            }
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1091 "SDCC.y"
    {
          structdef *sdef;
          symbol *sym, *dsym;

          // check for errors in structure members
          for (sym=(yyvsp[(5) - (6)].sym); sym; sym=sym->next)
            {
              if (IS_ABSOLUTE(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "'at'");
                  SPEC_ABSA(sym->etype) = 0;
                }
              if (IS_SPEC(sym->etype) && SPEC_SCLS(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "storage class");
                  printTypeChainRaw (sym->type, NULL);
                  SPEC_SCLS(sym->etype) = 0;
                }
              for (dsym=sym->next; dsym; dsym=dsym->next)
                {
                  if (*dsym->name && strcmp(sym->name, dsym->name)==0)
                    {
                      werrorfl(sym->fileDef, sym->lineDef, E_DUPLICATE_MEMBER,
                               (yyvsp[(1) - (6)].yyint)==STRUCT ? "struct" : "union", sym->name);
                      werrorfl(dsym->fileDef, dsym->lineDef, E_PREVIOUS_DEF);
                    }
                }
            }

          /* Create a structdef   */
          sdef = (yyvsp[(2) - (6)].sdef);
          sdef->fields = reverseSyms((yyvsp[(5) - (6)].sym));        /* link the fields */
          sdef->size = compStructSize((yyvsp[(1) - (6)].yyint), sdef); /* update size of  */
          promoteAnonStructs ((yyvsp[(1) - (6)].yyint), sdef);

          /* Create the specifier */
          (yyval.lnk) = newLink (SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk))= sdef;
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1132 "SDCC.y"
    {
          structdef *sdef;

          sdef = findSymWithBlock (StructTab, (yyvsp[(2) - (2)].sdef)->tagsym, currBlockno, NestLevel);

          if (sdef)
            (yyvsp[(2) - (2)].sdef) = sdef;
          else
            {
              /* new struct def for current scope */
              addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
            }
          (yyval.lnk) = newLink(SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk)) = (yyvsp[(2) - (2)].sdef);

          if (!(yyvsp[(2) - (2)].sdef)->type)
            {
              (yyvsp[(2) - (2)].sdef)->type = (yyvsp[(1) - (2)].yyint);
            }
          else
            {
              if ((yyvsp[(2) - (2)].sdef)->type != (yyvsp[(1) - (2)].yyint))
                  werror(E_BAD_TAG, (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(1) - (2)].yyint)==STRUCT ? "struct" : "union");
            }
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1161 "SDCC.y"
    { (yyval.yyint) = STRUCT; ignoreTypedefType = 1; }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1162 "SDCC.y"
    { (yyval.yyint) = UNION; ignoreTypedefType = 1; }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1167 "SDCC.y"
    {  /* synthesize a name add to structtable */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct(genSymName(NestLevel));
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = NULL;
          //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1179 "SDCC.y"
    {  /* add name to structure table */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct((yyvsp[(1) - (1)].sym)->name);
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = (yyvsp[(1) - (1)].sym);
          //$$ = findSymWithBlock (StructTab, $1, currBlockno);
          //if (! $$ )
          //  {
          //    $$ = newStruct($1->name);
          //    $$->level = NestLevel;
          //    $$->tagsym = $1;
          //    //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
          //  }
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1199 "SDCC.y"
    {
          symbol *sym = (yyvsp[(2) - (2)].sym);

          /* go to the end of the chain */
          while (sym->next) sym = sym->next;
          sym->next = (yyvsp[(1) - (2)].sym);

           (yyval.sym) = (yyvsp[(2) - (2)].sym);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1212 "SDCC.y"
    {
          /* add this type to all the symbols */
          symbol *sym;
          for ( sym = (yyvsp[(2) - (3)].sym); sym != NULL; sym = sym->next )
            {
              sym_link *btype = copyLinkChain((yyvsp[(1) - (3)].lnk));

              pointerTypes(sym->type, btype);
              if (!sym->type)
                {
                  sym->type = btype;
                  sym->etype = getSpec(sym->type);
                }
              else
                  addDecl (sym, 0, btype);
              /* make sure the type is complete and sane */
              checkTypeSanity(sym->etype, sym->name);
            }
          ignoreTypedefType = 0;
          (yyval.sym) = (yyvsp[(2) - (3)].sym);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1238 "SDCC.y"
    {
          (yyvsp[(3) - (3)].sym)->next  = (yyvsp[(1) - (3)].sym);
          (yyval.sym) = (yyvsp[(3) - (3)].sym);
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1247 "SDCC.y"
    {
          unsigned int bitsize;
          (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts), TRUE));
          if (!bitsize)
              bitsize = BITVAR_PAD;
          (yyval.sym)->bitVar = bitsize;
          (yyval.sym)->bitUnnamed = 1;
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1257 "SDCC.y"
    {
          unsigned int bitsize;
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[(3) - (3)].asts), TRUE));

          if (!bitsize)
            {
              (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
              (yyval.sym)->bitVar = BITVAR_PAD;
              werror(W_BITFLD_NAMED);
            }
          else
              (yyvsp[(1) - (3)].sym)->bitVar = bitsize;
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1270 "SDCC.y"
    { (yyval.sym) = newSymbol ("", NestLevel); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1275 "SDCC.y"
    {
          (yyval.lnk) = newEnumType ((yyvsp[(3) - (4)].sym));
          SPEC_SCLS(getSpec((yyval.lnk))) = 0;
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1280 "SDCC.y"
    {
          symbol *csym;
          sym_link *enumtype;

          csym = findSymWithLevel(enumTab, (yyvsp[(2) - (5)].sym));
          if ((csym && csym->level == (yyvsp[(2) - (5)].sym)->level))
            {
              werrorfl((yyvsp[(2) - (5)].sym)->fileDef, (yyvsp[(2) - (5)].sym)->lineDef, E_DUPLICATE_TYPEDEF, csym->name);
              werrorfl(csym->fileDef, csym->lineDef, E_PREVIOUS_DEF);
            }

          enumtype = newEnumType ((yyvsp[(4) - (5)].sym));
          SPEC_SCLS(getSpec(enumtype)) = 0;
          (yyvsp[(2) - (5)].sym)->type = enumtype;

          /* add this to the enumerator table */
          if (!csym)
              addSym (enumTab, (yyvsp[(2) - (5)].sym), (yyvsp[(2) - (5)].sym)->name, (yyvsp[(2) - (5)].sym)->level, (yyvsp[(2) - (5)].sym)->block, 0);
          (yyval.lnk) = copyLinkChain(enumtype);
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1301 "SDCC.y"
    {
          symbol *csym;

          /* check the enumerator table */
          if ((csym = findSymWithLevel(enumTab, (yyvsp[(2) - (2)].sym))))
              (yyval.lnk) = copyLinkChain(csym->type);
          else
            {
              (yyval.lnk) = newLink(SPECIFIER);
              SPEC_NOUN((yyval.lnk)) = V_INT;
            }
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1319 "SDCC.y"
    {
          (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym);
          (yyval.sym) = (yyvsp[(3) - (3)].sym);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1327 "SDCC.y"
    {
          symbol *sym;

          // check if the symbol at the same level already exists
          if ((sym = findSymWithLevel (SymbolTab, (yyvsp[(1) - (2)].sym))) && sym->level == (yyvsp[(1) - (2)].sym)->level)
            {
              werrorfl ((yyvsp[(1) - (2)].sym)->fileDef, (yyvsp[(1) - (2)].sym)->lineDef, E_DUPLICATE_MEMBER, "enum", (yyvsp[(1) - (2)].sym)->name);
              werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
            }
          (yyvsp[(1) - (2)].sym)->type = copyLinkChain ((yyvsp[(2) - (2)].val)->type);
          (yyvsp[(1) - (2)].sym)->etype = getSpec ((yyvsp[(1) - (2)].sym)->type);
          SPEC_ENUM ((yyvsp[(1) - (2)].sym)->etype) = 1;
          (yyval.sym) = (yyvsp[(1) - (2)].sym);
          // do this now, so we can use it for the next enums in the list
          addSymChain (&(yyvsp[(1) - (2)].sym));
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1347 "SDCC.y"
    {
          value *val;

          val = constExprValue((yyvsp[(2) - (2)].asts), TRUE);
          if (!IS_INT(val->type) && !IS_CHAR(val->type) && !IS_BOOL(val->type))
            {
              werror(E_ENUM_NON_INTEGER);
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(val));
              val = constVal(lbuff);
            }
          (yyval.val) = cenum = val;
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1359 "SDCC.y"
    {
          if (cenum)
            {
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(cenum)+1);
              (yyval.val) = cenum = constVal(lbuff);
            }
          else
            {
              (yyval.val) = cenum = constCharVal(0);
            }
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1373 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1375 "SDCC.y"
    {
             addDecl ((yyvsp[(2) - (2)].sym),0,reverseLink((yyvsp[(1) - (2)].lnk)));
             (yyval.sym) = (yyvsp[(2) - (2)].sym);
         }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1382 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1383 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1388 "SDCC.y"
    {
             (yyval.sym) = (yyvsp[(1) - (1)].sym);
             strncpy (function_name, (yyval.sym)->name, sizeof (function_name) - 4);
             memset (function_name + sizeof (function_name) - 4, 0x00, 4);
         }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1394 "SDCC.y"
    {
             addDecl ((yyvsp[(2) - (2)].sym),0,reverseLink((yyvsp[(1) - (2)].lnk)));
             (yyval.sym) = (yyvsp[(2) - (2)].sym);
             strncpy (function_name, (yyval.sym)->name, sizeof (function_name) - 4);
             memset (function_name + sizeof (function_name) - 4, 0x00, 4);
         }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1403 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1404 "SDCC.y"
    {
           // copy the functionAttributes (not the args and hasVargs !!)
           struct value *args;
           unsigned hasVargs;
           sym_link *funcType=(yyvsp[(1) - (2)].sym)->type;

           while (funcType && !IS_FUNC(funcType))
             funcType = funcType->next;

           if (!funcType)
             werror (E_FUNC_ATTR);
           else
             {
               args=FUNC_ARGS(funcType);
               hasVargs=FUNC_HASVARARGS(funcType);

               memcpy (&funcType->funcAttrs, &(yyvsp[(2) - (2)].lnk)->funcAttrs,
                   sizeof((yyvsp[(2) - (2)].lnk)->funcAttrs));

               FUNC_ARGS(funcType)=args;
               FUNC_HASVARARGS(funcType)=hasVargs;

               // just to be sure
               memset (&(yyvsp[(2) - (2)].lnk)->funcAttrs, 0,
                   sizeof((yyvsp[(2) - (2)].lnk)->funcAttrs));

               addDecl ((yyvsp[(1) - (2)].sym),0,(yyvsp[(2) - (2)].lnk));
             }
   }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1437 "SDCC.y"
    { (yyval.sym) = (yyvsp[(2) - (3)].sym); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1439 "SDCC.y"
    {
            sym_link   *p;

            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;
            DCL_ELEM(p) = 0;
            addDecl((yyvsp[(1) - (3)].sym),0,p);
         }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1448 "SDCC.y"
    {
            sym_link *p, *n;

            if (!options.std_c99)
              werror (E_QUALIFIED_ARRAY_PARAM_C99);

            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;
            DCL_ELEM(p) = 0;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[(3) - (4)].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[(3) - (4)].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[(3) - (4)].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[(3) - (4)].lnk));
            addDecl((yyvsp[(1) - (4)].sym),0,p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[(1) - (4)].sym),0,n);
         }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1467 "SDCC.y"
    {
            sym_link *p;
            value *tval;
            int size;

            tval = constExprValue((yyvsp[(3) - (4)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (4)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            addDecl((yyvsp[(1) - (4)].sym), 0, p);
         }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1496 "SDCC.y"
    {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              werror (E_STATIC_ARRAY_PARAM_C99);

            tval = constExprValue((yyvsp[(4) - (5)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (5)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            addDecl((yyvsp[(1) - (5)].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[(1) - (5)].sym),0,n);
         }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1531 "SDCC.y"
    {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              werror (E_QUALIFIED_ARRAY_PARAM_C99);

            tval = constExprValue((yyvsp[(4) - (5)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (5)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[(3) - (5)].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[(3) - (5)].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[(3) - (5)].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[(3) - (5)].lnk));
            addDecl((yyvsp[(1) - (5)].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[(1) - (5)].sym),0,n);
         }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1570 "SDCC.y"
    {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              {
                werror (E_STATIC_ARRAY_PARAM_C99);
                werror (E_QUALIFIED_ARRAY_PARAM_C99);
              }

            tval = constExprValue((yyvsp[(5) - (6)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (6)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[(4) - (6)].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[(4) - (6)].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[(4) - (6)].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[(4) - (6)].lnk));
            addDecl((yyvsp[(1) - (6)].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[(1) - (6)].sym),0,n);
         }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1612 "SDCC.y"
    {
            sym_link *p, *n;
            value *tval;
            int size;

            if (!options.std_c99)
              {
                werror (E_QUALIFIED_ARRAY_PARAM_C99);
                werror (E_STATIC_ARRAY_PARAM_C99);
              }

            tval = constExprValue((yyvsp[(5) - (6)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (6)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[(3) - (6)].lnk));
            DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[(3) - (6)].lnk));
            DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[(3) - (6)].lnk));
            DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[(3) - (6)].lnk));
            addDecl((yyvsp[(1) - (6)].sym), 0, p);
            n = newLink (SPECIFIER);
            SPEC_NEEDSPAR(n) = 1;
            addDecl((yyvsp[(1) - (6)].sym),0,n);
         }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1657 "SDCC.y"
    {
          addDecl ((yyvsp[(1) - (3)].sym), FUNCTION, NULL);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1661 "SDCC.y"
    {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          seqPointNo++; /* not a true sequence point, but helps resolve scope */
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1669 "SDCC.y"
    {
          sym_link *funcType;

          addDecl ((yyvsp[(1) - (5)].sym), FUNCTION, NULL);

          funcType = (yyvsp[(1) - (5)].sym)->type;
          while (funcType && !IS_FUNC(funcType))
              funcType = funcType->next;

          assert (funcType);

          FUNC_HASVARARGS(funcType) = IS_VARG((yyvsp[(4) - (5)].val));
          FUNC_ARGS(funcType) = reverseVal((yyvsp[(4) - (5)].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          seqPointNo++; /* not a true sequence point, but helps resolve scope */

          // if this was a pointer (to a function)
          if (!IS_FUNC((yyvsp[(1) - (5)].sym)->type))
              cleanUpLevel(SymbolTab, NestLevel + LEVEL_UNIT);

          (yyval.sym) = (yyvsp[(1) - (5)].sym);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1695 "SDCC.y"
    {
          werror(E_OLD_STYLE,(yyvsp[(1) - (4)].sym)->name);
          /* assume it returns an int */
          (yyvsp[(1) - (4)].sym)->type = (yyvsp[(1) - (4)].sym)->etype = newIntLink();
          (yyval.sym) = (yyvsp[(1) - (4)].sym);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1704 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1706 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (2)].lnk);
             if (IS_SPEC((yyvsp[(2) - (2)].lnk))) {
                 DCL_TSPEC((yyvsp[(1) - (2)].lnk)) = (yyvsp[(2) - (2)].lnk);
                 DCL_PTR_CONST((yyvsp[(1) - (2)].lnk)) = SPEC_CONST((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_VOLATILE((yyvsp[(1) - (2)].lnk)) = SPEC_VOLATILE((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_RESTRICT((yyvsp[(1) - (2)].lnk)) = SPEC_RESTRICT((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[(1) - (2)].lnk)) = SPEC_ADDRSPACE((yyvsp[(2) - (2)].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);
         }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1719 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (2)].lnk);
             (yyval.lnk)->next = (yyvsp[(2) - (2)].lnk);
             DCL_TYPE((yyvsp[(2) - (2)].lnk))=port->unqualified_pointer;
         }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1725 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (3)].lnk);
             if (IS_SPEC((yyvsp[(2) - (3)].lnk)) && DCL_TYPE((yyvsp[(3) - (3)].lnk)) == UPOINTER) {
                 DCL_PTR_CONST((yyvsp[(1) - (3)].lnk)) = SPEC_CONST((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_VOLATILE((yyvsp[(1) - (3)].lnk)) = SPEC_VOLATILE((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_RESTRICT((yyvsp[(1) - (3)].lnk)) = SPEC_RESTRICT((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[(1) - (3)].lnk)) = SPEC_ADDRSPACE((yyvsp[(2) - (3)].lnk));
                 switch (SPEC_SCLS((yyvsp[(2) - (3)].lnk))) {
                 case S_XDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = FPOINTER;
                     break;
                 case S_IDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = IPOINTER;
                     break;
                 case S_PDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = PPOINTER;
                     break;
                 case S_DATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = POINTER;
                     break;
                 case S_CODE:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = CPOINTER;
                     break;
                 case S_EEPROM:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = EEPPOINTER;
                     break;
                 default:
                   // this could be just "constant"
                   // werror(W_PTR_TYPE_INVALID);
                     ;
                 }
             }
             else
                 werror (W_PTR_TYPE_INVALID);
             (yyval.lnk)->next = (yyvsp[(3) - (3)].lnk);
         }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1765 "SDCC.y"
    {
        (yyval.lnk) = newLink(DECLARATOR);
        DCL_TYPE((yyval.lnk))=UPOINTER;
      }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1771 "SDCC.y"
    { (yyval.lnk) = finalizeSpec((yyvsp[(1) - (1)].lnk)); }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1776 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "type_specifier_list type_specifier skipped");
   }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1786 "SDCC.y"
    {
           (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym);
           (yyval.sym) = (yyvsp[(3) - (3)].sym);
         }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1794 "SDCC.y"
    { (yyvsp[(1) - (3)].val)->vArgs = 1;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1800 "SDCC.y"
    {
            (yyvsp[(3) - (3)].val)->next = (yyvsp[(1) - (3)].val);
            (yyval.val) = (yyvsp[(3) - (3)].val);
         }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1808 "SDCC.y"
    {
          symbol *loop;

          if (IS_SPEC ((yyvsp[(1) - (2)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (2)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, (yyvsp[(2) - (2)].sym)->name);
            }
          pointerTypes ((yyvsp[(2) - (2)].sym)->type, (yyvsp[(1) - (2)].lnk));
          if (IS_SPEC ((yyvsp[(2) - (2)].sym)->etype))
            SPEC_NEEDSPAR((yyvsp[(2) - (2)].sym)->etype) = 0;
          addDecl ((yyvsp[(2) - (2)].sym), 0, (yyvsp[(1) - (2)].lnk));
          for (loop = (yyvsp[(2) - (2)].sym); loop; loop->_isparm = 1, loop = loop->next)
            ;
          (yyval.val) = symbolVal ((yyvsp[(2) - (2)].sym));
          ignoreTypedefType = 0;
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1825 "SDCC.y"
    {
          (yyval.val) = newValue ();
          (yyval.val)->type = (yyvsp[(1) - (1)].lnk);
          (yyval.val)->etype = getSpec ((yyval.val)->type);
          ignoreTypedefType = 0;
         }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1835 "SDCC.y"
    {
          if (IS_SPEC ((yyvsp[(1) - (1)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (1)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          (yyval.lnk) = (yyvsp[(1) - (1)].lnk); ignoreTypedefType = 0;
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1843 "SDCC.y"
    {
          /* go to the end of the list */
          sym_link *p;

          if (IS_SPEC ((yyvsp[(1) - (2)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (2)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          pointerTypes ((yyvsp[(2) - (2)].lnk),(yyvsp[(1) - (2)].lnk));
          for (p = (yyvsp[(2) - (2)].lnk); p && p->next; p = p->next)
            ;
          if (!p)
            {
              werror(E_SYNTAX_ERROR, yytext);
            }
          else
            {
              p->next = (yyvsp[(1) - (2)].lnk);
            }
          (yyval.lnk) = (yyvsp[(2) - (2)].lnk);
          ignoreTypedefType = 0;
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1868 "SDCC.y"
    { (yyval.lnk) = reverseLink((yyvsp[(1) - (1)].lnk)); }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1870 "SDCC.y"
    { (yyvsp[(1) - (2)].lnk) = reverseLink((yyvsp[(1) - (2)].lnk)); (yyvsp[(2) - (2)].lnk)->next = (yyvsp[(1) - (2)].lnk); (yyval.lnk) = (yyvsp[(2) - (2)].lnk);
          if (IS_PTR((yyvsp[(1) - (2)].lnk)) && IS_FUNC((yyvsp[(2) - (2)].lnk)))
            DCL_TYPE((yyvsp[(1) - (2)].lnk)) = CPOINTER;
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1877 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(2) - (3)].lnk); }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1878 "SDCC.y"
    {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                    }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1883 "SDCC.y"
    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[(2) - (3)].asts),TRUE));
                                    }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1889 "SDCC.y"
    {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                       (yyval.lnk)->next = (yyvsp[(1) - (3)].lnk);
                                    }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1896 "SDCC.y"
    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[(3) - (4)].asts),TRUE));
                                       (yyval.lnk)->next = (yyvsp[(1) - (4)].lnk);
                                    }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1903 "SDCC.y"
    { (yyval.lnk) = NULL;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1904 "SDCC.y"
    { (yyval.lnk) = NULL;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1905 "SDCC.y"
    {
     // $1 must be a pointer to a function
     sym_link *p=newLink(DECLARATOR);
     DCL_TYPE(p) = FUNCTION;
     if (!(yyvsp[(1) - (3)].lnk)) {
       // ((void (code *) ()) 0) ()
       (yyvsp[(1) - (3)].lnk)=newLink(DECLARATOR);
       DCL_TYPE((yyvsp[(1) - (3)].lnk))=CPOINTER;
       (yyval.lnk) = (yyvsp[(1) - (3)].lnk);
     }
     (yyvsp[(1) - (3)].lnk)->next=p;
   }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1918 "SDCC.y"
    {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
        }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1925 "SDCC.y"
    {
          sym_link *p = newLink(DECLARATOR), *q;
          DCL_TYPE(p) = FUNCTION;

          FUNC_HASVARARGS(p) = IS_VARG((yyvsp[(4) - (5)].val));
          FUNC_ARGS(p) = reverseVal((yyvsp[(4) - (5)].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          if (!(yyvsp[(1) - (5)].lnk))
            {
              /* ((void (code *) (void)) 0) () */
              (yyvsp[(1) - (5)].lnk) = newLink(DECLARATOR);
              DCL_TYPE((yyvsp[(1) - (5)].lnk)) = CPOINTER;
              (yyval.lnk) = (yyvsp[(1) - (5)].lnk);
            }
          for (q = (yyvsp[(1) - (5)].lnk); q && q->next; q = q->next);
          q->next = p;
        }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1948 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_NODE,(yyvsp[(1) - (1)].asts)); }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1949 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[(2) - (3)].ilist))); }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1950 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[(2) - (4)].ilist))); }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1954 "SDCC.y"
    { (yyvsp[(2) - (2)].ilist)->designation = (yyvsp[(1) - (2)].dsgn); (yyval.ilist) = (yyvsp[(2) - (2)].ilist); }
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1956 "SDCC.y"
    {
                                       (yyvsp[(4) - (4)].ilist)->designation = (yyvsp[(3) - (4)].dsgn);
                                       (yyvsp[(4) - (4)].ilist)->next = (yyvsp[(1) - (4)].ilist);
                                       (yyval.ilist) = (yyvsp[(4) - (4)].ilist);
                                    }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1965 "SDCC.y"
    {
                                       value *val = constExprValue ((yyvsp[(3) - (6)].asts), TRUE);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ulFromVal(val))
                                         werror (W_STATIC_ASSERTION, (yyvsp[(5) - (6)].yystr));
                                    }
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1973 "SDCC.y"
    {
                                       value *val = constExprValue ((yyvsp[(3) - (4)].asts), TRUE);
                                       if (!options.std_c2x)
                                         werror (E_STATIC_ASSERTION_C2X);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ulFromVal(val))
                                         werror (W_STATIC_ASSERTION_2);
                                    }
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1996 "SDCC.y"
    {
                   if (inCriticalFunction || inCriticalBlock)
                     werror(E_INVALID_CRITICAL);
                   inCriticalBlock = 1;
                   STACK_PUSH(continueStack,NULL);
                   STACK_PUSH(breakStack,NULL);
                   (yyval.sym) = NULL;
                }
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2007 "SDCC.y"
    {
                   STACK_POP(breakStack);
                   STACK_POP(continueStack);
                   (yyval.asts) = newNode(CRITICAL,(yyvsp[(2) - (2)].asts),NULL);
                   inCriticalBlock = 0;
                }
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2016 "SDCC.y"
    { if ((yyvsp[(1) - (2)].asts)) {(yyval.asts) = (yyvsp[(1) - (2)].asts); (yyvsp[(1) - (2)].asts)->right = (yyvsp[(2) - (2)].asts);} else (yyval.asts) = newNode (BLOCK, NULL, NULL); }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2018 "SDCC.y"
    { /* Support a label without a statement at the end of a */
       /* compound statement as a SDCC extension. Include the */
       /* closing brace as part of the rule to avoid an */
       /* unacceptably large number of shift/reduce conflicts */
       /* and then reinsert it to be parsed a second time. */
       werror(W_LABEL_WITHOUT_STATEMENT);
       (yyval.asts) = (yyvsp[(1) - (2)].asts);
       yychar = '}';
     }
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2030 "SDCC.y"
    {  (yyval.asts) = createLabel((yyvsp[(1) - (2)].sym),NULL);
                                          (yyvsp[(1) - (2)].sym)->isitmp = 0;  }
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2033 "SDCC.y"
    {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createCase(NULL,(yyvsp[(2) - (3)].asts),NULL);
       else
         (yyval.asts) = createCase(STACK_PEEK(swStk),(yyvsp[(2) - (3)].asts),NULL);
     }
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2039 "SDCC.y"
    { (yyval.asts) = newNode(DEFAULT,NULL,NULL); }
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2040 "SDCC.y"
    {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createDefault(NULL,(yyvsp[(2) - (3)].asts),NULL);
       else
         (yyval.asts) = createDefault(STACK_PEEK(swStk),(yyvsp[(2) - (3)].asts),NULL);
     }
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2050 "SDCC.y"
    {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          ignoreTypedefType = 0;
        }
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2061 "SDCC.y"
    {
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
        }
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2068 "SDCC.y"
    { (yyval.asts) = createBlock(NULL, NULL); }
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2070 "SDCC.y"
    {
       (yyval.asts) = (yyvsp[(2) - (3)].asts);
       cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
     }
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2074 "SDCC.y"
    { (yyval.asts) = NULL; }
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2078 "SDCC.y"
    { (yyval.asts) = createBlock(NULL, (yyvsp[(1) - (1)].asts)); }
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2079 "SDCC.y"
    { (yyval.asts) = createBlock((yyvsp[(1) - (1)].sym), NULL); }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2080 "SDCC.y"
    { (yyval.asts) = createBlock((yyvsp[(1) - (2)].sym), (yyvsp[(2) - (2)].asts)); }
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2086 "SDCC.y"
    {
       (yyval.asts) = newNode(NULLOP, (yyvsp[(1) - (2)].asts), (yyvsp[(2) - (2)].asts));
       if (!options.std_c99)
         werror(E_DECL_AFTER_STATEMENT_C99);
     }
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2094 "SDCC.y"
    {
       NestLevel += SUBLEVEL_UNIT;
       STACK_PUSH(blockNum, currBlockno);
       btree_add_child(currBlockno, ++blockNo);
       currBlockno = blockNo;
       ignoreTypedefType = 0;
     }
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2101 "SDCC.y"
    { (yyval.sym) = (yyvsp[(2) - (2)].sym); }
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2106 "SDCC.y"
    {
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[(1) - (2)].sym), (yyvsp[(2) - (2)].asts));
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2113 "SDCC.y"
    {
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[(1) - (1)].sym), NULL);
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2123 "SDCC.y"
    {
       /* if this is typedef declare it immediately */
       if ( (yyvsp[(1) - (1)].sym) && IS_TYPEDEF((yyvsp[(1) - (1)].sym)->etype)) {
         allocVariables ((yyvsp[(1) - (1)].sym));
         (yyval.sym) = NULL;
       }
       else
         (yyval.sym) = (yyvsp[(1) - (1)].sym);
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[(1) - (1)].sym));
     }
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2136 "SDCC.y"
    {
       symbol   *sym;

       /* if this is a typedef */
       if ((yyvsp[(2) - (2)].sym) && IS_TYPEDEF((yyvsp[(2) - (2)].sym)->etype)) {
         allocVariables ((yyvsp[(2) - (2)].sym));
         (yyval.sym) = (yyvsp[(1) - (2)].sym);
       }
       else {
         /* get to the end of the previous decl */
         if ( (yyvsp[(1) - (2)].sym) ) {
           (yyval.sym) = sym = (yyvsp[(1) - (2)].sym);
           while (sym->next)
             sym = sym->next;
           sym->next = (yyvsp[(2) - (2)].sym);
         }
         else
           (yyval.sym) = (yyvsp[(2) - (2)].sym);
       }
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[(2) - (2)].sym));
     }
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2162 "SDCC.y"
    {  (yyval.asts) = newNode(NULLOP,(yyvsp[(1) - (2)].asts),(yyvsp[(2) - (2)].asts));}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 2166 "SDCC.y"
    { (yyval.asts) = NULL;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 2167 "SDCC.y"
    { (yyval.asts) = (yyvsp[(1) - (2)].asts); seqPointNo++;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2171 "SDCC.y"
    { (yyval.asts) = (yyvsp[(2) - (2)].asts); }
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2172 "SDCC.y"
    { (yyval.asts) = NULL; }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2177 "SDCC.y"
    { seqPointNo++;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2178 "SDCC.y"
    {
                              noLineno++;
                              (yyval.asts) = createIf ((yyvsp[(3) - (7)].asts), (yyvsp[(6) - (7)].asts), (yyvsp[(7) - (7)].asts) );
                              (yyval.asts)->lineno = (yyvsp[(3) - (7)].asts)->lineno;
                              (yyval.asts)->filename = (yyvsp[(3) - (7)].asts)->filename;
                              noLineno--;
                           }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2185 "SDCC.y"
    {
                              ast *ex;
                              static   int swLabel = 0;

                              seqPointNo++;
                              /* create a node for expression  */
                              ex = newNode(SWITCH,(yyvsp[(3) - (4)].asts),NULL);
                              STACK_PUSH(swStk,ex);   /* save it in the stack */
                              ex->values.switchVals.swNum = swLabel;

                              /* now create the label */
                              SNPRINTF(lbuff, sizeof(lbuff),
                                       "_swBrk_%d",swLabel++);
                              (yyval.sym)  =  newSymbol(lbuff,NestLevel);
                              /* put label in the break stack  */
                              STACK_PUSH(breakStack,(yyval.sym));
                           }
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2202 "SDCC.y"
    {
                              /* get back the switch form the stack  */
                              (yyval.asts) = STACK_POP(swStk);
                              (yyval.asts)->right = newNode (NULLOP,(yyvsp[(6) - (6)].asts),createLabel((yyvsp[(5) - (6)].sym),NULL));
                              STACK_POP(breakStack);
                           }
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2210 "SDCC.y"
    {  /* create and push the continue , break & body labels */
                  static int Lblnum = 0;
                  /* continue */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilecontinue_%d",Lblnum);
                  STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
                  /* break */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebreak_%d",Lblnum);
                  STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
                  /* body */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebody_%d",Lblnum++);
                  (yyval.sym) = newSymbol(lbuff,NestLevel);
               }
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2224 "SDCC.y"
    {  /* create and push the continue , break & body Labels */
           static int Lblnum = 0;

           /* continue */
           SNPRINTF(lbuff, sizeof(lbuff), "_docontinue_%d",Lblnum);
           STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
           /* break */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobreak_%d",Lblnum);
           STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
           /* do body */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobody_%d",Lblnum++);
           (yyval.sym) = newSymbol (lbuff,NestLevel);
        }
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2239 "SDCC.y"
    { /* create & push continue, break & body labels */
            static int Lblnum = 0;

           NestLevel += LEVEL_UNIT;
           STACK_PUSH(blockNum, currBlockno);
           btree_add_child(currBlockno, ++blockNo);
           currBlockno = blockNo;
           ignoreTypedefType = 0;

            /* continue */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcontinue_%d",Lblnum);
            STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
            /* break    */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbreak_%d",Lblnum);
            STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
            /* body */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbody_%d",Lblnum);
            (yyval.sym) = newSymbol(lbuff,NestLevel);
            /* condition */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcond_%d",Lblnum++);
            STACK_PUSH(forStack,newSymbol(lbuff,NestLevel));
          }
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2264 "SDCC.y"
    { seqPointNo++;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2265 "SDCC.y"
    {
                           noLineno++;
                           (yyval.asts) = createWhile ( (yyvsp[(1) - (6)].sym), STACK_POP(continueStack),
                                              STACK_POP(breakStack), (yyvsp[(3) - (6)].asts), (yyvsp[(6) - (6)].asts) );
                           (yyval.asts)->lineno = (yyvsp[(1) - (6)].sym)->lineDef;
                           (yyval.asts)->filename = (yyvsp[(1) - (6)].sym)->fileDef;
                           noLineno--;
                         }
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2274 "SDCC.y"
    {
                          seqPointNo++;
                          noLineno++;
                          (yyval.asts) = createDo ( (yyvsp[(1) - (7)].sym) , STACK_POP(continueStack),
                                          STACK_POP(breakStack), (yyvsp[(5) - (7)].asts), (yyvsp[(2) - (7)].asts));
                          (yyval.asts)->lineno = (yyvsp[(1) - (7)].sym)->lineDef;
                          (yyval.asts)->filename = (yyvsp[(1) - (7)].sym)->fileDef;
                          noLineno--;
                        }
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2284 "SDCC.y"
    {
                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[(9) - (9)].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[(1) - (9)].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = (yyvsp[(3) - (9)].asts);
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[(5) - (9)].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[(7) - (9)].asts);
                          
                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL));
                          noLineno--;

                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2309 "SDCC.y"
    {
                          if (!options.std_c99)
                            werror (E_FOR_INITAL_DECLARATION_C99);

                          if ( (yyvsp[(3) - (7)].sym) && IS_TYPEDEF((yyvsp[(3) - (7)].sym)->etype))
                            allocVariables ((yyvsp[(3) - (7)].sym));
                          ignoreTypedefType = 0;
                          addSymChain(&(yyvsp[(3) - (7)].sym));
                        }
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2319 "SDCC.y"
    {

                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[(9) - (9)].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[(1) - (9)].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = 0;
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[(4) - (9)].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[(6) - (9)].asts);

                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = createBlock((yyvsp[(3) - (9)].sym), newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL)));
                          cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
                          noLineno--;

                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2348 "SDCC.y"
    { (yyval.asts) = NULL; seqPointNo++; }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2349 "SDCC.y"
    { (yyval.asts) = (yyvsp[(1) - (1)].asts); seqPointNo++; }
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2353 "SDCC.y"
    {
                              if (inCriticalBlock) {
                                werror(E_INVALID_CRITICAL);
                                (yyval.asts) = NULL;
                              } else {
                                (yyvsp[(2) - (3)].sym)->islbl = 1;
                                (yyval.asts) = newAst_VALUE(symbolVal((yyvsp[(2) - (3)].sym)));
                                (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
                              }
                           }
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2363 "SDCC.y"
    {
       /* make sure continue is in context */
       if (STACK_EMPTY(continueStack) || STACK_PEEK(continueStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       }
       else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(continueStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           /* mark the continue label as referenced */
           STACK_PEEK(continueStack)->isref = 1;
       }
   }
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2376 "SDCC.y"
    {
       if (STACK_EMPTY(breakStack) || STACK_PEEK(breakStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(breakStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           STACK_PEEK(breakStack)->isref = 1;
       }
   }
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2386 "SDCC.y"
    {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,NULL);
       }
   }
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2395 "SDCC.y"
    {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,(yyvsp[(2) - (3)].asts));
       }
   }
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2412 "SDCC.y"
    {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup(copyStr ((yyvsp[(3) - (5)].yystr), NULL));
        seqPointNo++;
        (yyval.asts) = ex;
     }
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2422 "SDCC.y"
    {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup((yyvsp[(1) - (2)].yystr));
        seqPointNo++;
        (yyval.asts) = ex;
      }
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2434 "SDCC.y"
    {
     symbol *sym;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[(3) - (4)].sym))) && sym->level == (yyvsp[(3) - (4)].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[(2) - (4)].sym)))
       werror (E_ID_UNDEF, (yyvsp[(2) - (4)].sym)->name);
     addSym (AddrspaceTab, (yyvsp[(3) - (4)].sym), (yyvsp[(3) - (4)].sym)->name, (yyvsp[(3) - (4)].sym)->level, (yyvsp[(3) - (4)].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[(3) - (4)].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[(2) - (4)].sym));
     sym->addressmod[1] = 0;
   }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2445 "SDCC.y"
    {
     symbol *sym;
     sym_link *type;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[(4) - (5)].sym))) && sym->level == (yyvsp[(4) - (5)].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[(2) - (5)].sym)))
       werror (E_ID_UNDEF, (yyvsp[(2) - (5)].sym)->name);
     addSym (AddrspaceTab, (yyvsp[(4) - (5)].sym), (yyvsp[(4) - (5)].sym)->name, (yyvsp[(4) - (5)].sym)->level, (yyvsp[(4) - (5)].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[(4) - (5)].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[(2) - (5)].sym));
     sym->addressmod[1] = 0;
     type = newLink (SPECIFIER);
     SPEC_CONST(type) = 1;
     sym->type = sym->etype = type;
   }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2463 "SDCC.y"
    { (yyval.sym) = newSymbol ((yyvsp[(1) - (1)].yychar), NestLevel); }
    break;



/* Line 1455 of yacc.c  */
#line 6227 "SDCCy.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2465 "SDCC.y"


