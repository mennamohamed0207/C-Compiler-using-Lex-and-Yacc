
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
#line 4 "parser.y"


    #include <stdio.h>
    #include <stdlib.h>
    #include "compiler.h"
    extern void log_symbol_table(const char* filename);
    extern void log_errors(int line, const char *msg,const char* filename);
    extern void check_unused_variables();
    extern void open_assembly_file(const char* filename="x.txt");
    extern FILE *assemblyOutFile;


    Node* create_operation(int oper, int line_number,int nops,...);
    Node* create_constant(int type ,int line_number,int dataType);
    Node* create_identifier(char* i, int line_number, int dataType, int qualifier);
    void free_node(Node *p);

    int write_to_assembly(Node *p, Node *parent=NULL, int cont = -1, int brk = -1, int args = 0, ...);
    extern int yylex();
    extern void yyerror(const char *emsg, int line_number,const char* filename);
    extern int yylineno;



/* Line 189 of yacc.c  */
#line 98 "parser.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 "parser.y"

    #include "compiler.h"  



/* Line 209 of yacc.c  */
#line 128 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT = 259,
     STRING = 260,
     CHARACTER = 261,
     TRUE = 262,
     FALSE = 263,
     BOOL = 264,
     IDENTIFIER = 265,
     CHAR_TYPE = 266,
     VOID = 267,
     ELSE = 268,
     WHILE = 269,
     RETURN = 270,
     FOR = 271,
     BREAK = 272,
     CONTINUE = 273,
     DO = 274,
     CONST = 275,
     STRING_TYPE = 276,
     BOOL_TYPE = 277,
     INT_TYPE = 278,
     FLOAT_TYPE = 279,
     SWITCH = 280,
     CASE = 281,
     DEFAULT = 282,
     EQ = 283,
     NEQ = 284,
     LTE = 285,
     GTE = 286,
     NOT = 287,
     IF = 288,
     BLOCK = 289,
     FUNCTION = 290,
     DECLARATION = 291,
     NOT_LOG = 292,
     AND_LOG = 293,
     SHIFTR_LOG = 294,
     SHIFTL_LOG = 295,
     OR_LOG = 296,
     XOR_LOG = 297,
     OR = 298,
     AND = 299,
     SUB_ASSIGN = 300,
     PLUS_ASSIGN = 301,
     MOD_ASSIGN = 302,
     DIV_ASSIGN = 303,
     MUL_ASSIGN = 304,
     MOD = 305,
     POST_DEC = 306,
     POST_INC = 307,
     BITWISE_OR_ASSIGN = 308,
     BITWISE_XOR_ASSIGN = 309,
     BITWISE_AND_ASSIGN = 310,
     SHIFTR_ASSIGN = 311,
     SHIFTL_ASSIGN = 312,
     PRE_DEC = 313,
     PRE_INC = 314,
     NEGATIVE = 315,
     LOWER_THAN_ELSE = 316,
     FUNC = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 27 "parser.y"

  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer



/* Line 214 of yacc.c  */
#line 220 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 232 "parser.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   866

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      74,    75,    55,    48,    73,    49,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    70,
      46,    43,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      50,    51,    52,    53,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    18,
      20,    24,    27,    30,    32,    35,    38,    41,    44,    46,
      48,    50,    52,    54,    56,    57,    59,    63,    67,    70,
      73,    81,    88,   100,   111,   112,   114,   117,   120,   123,
     126,   127,   129,   130,   132,   138,   146,   152,   160,   168,
     177,   181,   189,   197,   205,   212,   219,   226,   229,   234,
     240,   244,   248,   252,   256,   260,   264,   268,   272,   276,
     280,   284,   288,   292,   296,   300,   304,   308,   312,   316,
     320,   324,   328,   333,   335,   337,   339,   341,   343,   345,
     348,   351,   354,   357,   360,   364,   368,   372,   376,   380,
     384,   388,   392,   396,   400,   404,   408,   412,   416,   420,
     424,   428,   432,   435,   438,   440,   442,   444,   446,   448,
     450,   452,   456,   460,   462
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      78,     0,    -1,    79,    -1,    -1,    79,    81,    -1,    81,
      -1,    80,    81,    -1,    70,    -1,    82,    -1,    83,    -1,
      71,    80,    72,    -1,    97,    70,    -1,   101,    70,    -1,
      85,    -1,    17,    70,    -1,    18,    70,    -1,    98,    70,
      -1,    99,    70,    -1,    87,    -1,    91,    -1,    93,    -1,
      92,    -1,    86,    -1,    94,    -1,    -1,   101,    -1,    84,
      73,   101,    -1,    15,   101,    70,    -1,    15,    70,    -1,
      15,    99,    -1,    97,    74,   102,    75,    71,    80,    72,
      -1,    97,    74,   102,    75,    71,    72,    -1,    16,    74,
      90,    70,    89,    70,    88,    75,    71,    80,    72,    -1,
      16,    74,    90,    70,    89,    70,    88,    75,    71,    72,
      -1,    -1,    98,    -1,   101,    59,    -1,   101,    58,    -1,
      66,   101,    -1,    65,   101,    -1,    -1,   101,    -1,    -1,
      97,    -1,    14,    74,   101,    75,    81,    -1,    19,    81,
      14,    74,   101,    75,    70,    -1,    33,    74,   101,    75,
      81,    -1,    33,    74,   101,    75,    81,    13,    81,    -1,
      25,    74,    10,    75,    71,    96,    72,    -1,    25,    74,
      10,    75,    71,    96,    95,    72,    -1,    27,    76,    81,
      -1,    26,     3,    76,    81,    17,    70,    96,    -1,    26,
       5,    76,    81,    17,    70,    96,    -1,    26,     6,    76,
      81,    17,    70,    96,    -1,    26,     3,    76,    81,    17,
      70,    -1,    26,     5,    76,    81,    17,    70,    -1,    26,
       6,    76,    81,    17,    70,    -1,   100,    10,    -1,   100,
      10,    43,   101,    -1,    20,   100,    10,    43,   101,    -1,
      10,    43,   101,    -1,    10,    43,    99,    -1,    10,    51,
      99,    -1,    10,    50,    99,    -1,    10,    54,    99,    -1,
      10,    53,    99,    -1,    10,    52,    99,    -1,    10,    51,
     101,    -1,    10,    50,   101,    -1,    10,    54,   101,    -1,
      10,    53,   101,    -1,    10,    52,   101,    -1,    10,    62,
      99,    -1,    10,    60,    99,    -1,    10,    61,    99,    -1,
      10,    64,    99,    -1,    10,    63,    99,    -1,    10,    62,
     101,    -1,    10,    60,   101,    -1,    10,    61,   101,    -1,
      10,    64,   101,    -1,    10,    63,   101,    -1,    10,    74,
      84,    75,    -1,    23,    -1,    24,    -1,    11,    -1,    12,
      -1,    22,    -1,    21,    -1,   101,    59,    -1,   101,    58,
      -1,    66,   101,    -1,    65,   101,    -1,    37,   101,    -1,
     101,    48,   101,    -1,   101,    49,   101,    -1,   101,    55,
     101,    -1,   101,    56,   101,    -1,   101,    28,   101,    -1,
     101,    29,   101,    -1,   101,    46,   101,    -1,   101,    57,
     101,    -1,   101,    47,   101,    -1,   101,    30,   101,    -1,
     101,    31,   101,    -1,   101,    45,   101,    -1,   101,    41,
     101,    -1,   101,    38,   101,    -1,   101,    42,   101,    -1,
     101,    39,   101,    -1,   101,    40,   101,    -1,   101,    44,
     101,    -1,    32,   101,    -1,    49,   101,    -1,     3,    -1,
       4,    -1,     7,    -1,     8,    -1,     5,    -1,     6,    -1,
      10,    -1,    74,   101,    75,    -1,   102,    73,    97,    -1,
      97,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,    99,   102,   103,   106,   107,   108,
     109,   114,   115,   116,   117,   118,   119,   120,   124,   125,
     126,   127,   128,   129,   136,   137,   138,   142,   143,   144,
     147,   152,   156,   157,   162,   163,   164,   165,   166,   167,
     170,   171,   174,   175,   181,   185,   189,   190,   193,   194,
     198,   201,   202,   203,   204,   205,   206,   210,   211,   212,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   229,   230,   231,   232,   233,   235,   236,   237,
     238,   239,   243,   246,   247,   248,   249,   250,   251,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   274,   275,   276,   277,
     278,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   297,   298,   299
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "STRING",
  "CHARACTER", "TRUE", "FALSE", "BOOL", "IDENTIFIER", "CHAR_TYPE", "VOID",
  "ELSE", "WHILE", "RETURN", "FOR", "BREAK", "CONTINUE", "DO", "CONST",
  "STRING_TYPE", "BOOL_TYPE", "INT_TYPE", "FLOAT_TYPE", "SWITCH", "CASE",
  "DEFAULT", "EQ", "NEQ", "LTE", "GTE", "NOT", "IF", "BLOCK", "FUNCTION",
  "DECLARATION", "NOT_LOG", "AND_LOG", "SHIFTR_LOG", "SHIFTL_LOG",
  "OR_LOG", "XOR_LOG", "'='", "OR", "AND", "'<'", "'>'", "'+'", "'-'",
  "SUB_ASSIGN", "PLUS_ASSIGN", "MOD_ASSIGN", "DIV_ASSIGN", "MUL_ASSIGN",
  "'*'", "'/'", "MOD", "POST_DEC", "POST_INC", "BITWISE_OR_ASSIGN",
  "BITWISE_XOR_ASSIGN", "BITWISE_AND_ASSIGN", "SHIFTR_ASSIGN",
  "SHIFTL_ASSIGN", "PRE_DEC", "PRE_INC", "NEGATIVE", "LOWER_THAN_ELSE",
  "FUNC", "';'", "'{'", "'}'", "','", "'('", "')'", "':'", "$accept",
  "root", "program", "statement_list", "statement", "single_statement",
  "compound_statement", "params", "return_statement",
  "function_definition", "for_statement", "for_assignment",
  "multiple_expr", "for_init", "while_statement", "do_while_statement",
  "if_statement", "switch_statement", "default_statement", "switch_cases",
  "declaration", "assignment_statement", "function_call", "type", "expr",
  "args", 0
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
     295,   296,   297,    61,   298,   299,    60,    62,    43,    45,
     300,   301,   302,   303,   304,    42,    47,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      59,   123,   125,    44,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    91,    92,    93,    93,    94,    94,
      95,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       3,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     3,     2,     2,
       7,     6,    11,    10,     0,     1,     2,     2,     2,     2,
       0,     1,     0,     1,     5,     7,     5,     7,     7,     8,
       3,     7,     7,     7,     6,     6,     6,     2,     4,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,   114,   115,   118,   119,   116,   117,
     120,    85,    86,     0,     0,     0,     0,     0,     0,     0,
      88,    87,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     4,     8,     9,    13,    22,    18,
      19,    21,    20,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,   120,    28,    29,     0,    42,    14,    15,     0,
       0,     0,   120,   112,     0,    93,   113,    92,    91,     0,
       5,     0,    11,   124,    16,    17,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    89,    12,    61,    60,
      63,    68,    62,    67,    66,    71,    65,    70,    64,    69,
      73,    78,    74,    79,    72,    77,    76,    81,    75,    80,
       0,    25,     0,    27,     0,    43,     0,     0,     0,     0,
      10,     6,   121,   123,     0,     0,    98,    99,   103,   104,
     107,   109,   110,   106,   108,   111,   105,   100,   102,    94,
      95,    96,    97,   101,     0,    82,     0,    40,     0,     0,
       0,     0,     0,     0,    58,    26,    44,     0,    41,     0,
      59,     0,    46,   122,     0,    34,     0,     0,     0,     0,
      31,     0,   120,     0,     0,     0,    35,     0,    45,     0,
       0,     0,     0,    48,     0,    47,    30,    92,    91,     0,
      90,    89,     0,     0,     0,     0,    49,     0,     0,     0,
       0,    50,    33,     0,     0,     0,     0,    32,    54,    55,
      56,    51,    52,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    79,    80,    35,    36,   130,    37,    38,
      39,   195,   177,   134,    40,    41,    42,    43,   204,   188,
      44,    45,    46,    47,    48,   144
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
    -183,     8,   356,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
     743,  -183,  -183,   -59,   392,   -51,   -32,    -5,   356,   127,
    -183,  -183,  -183,  -183,    -7,   403,     0,   403,   403,   403,
     403,  -183,   356,   403,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,   -38,    31,    33,    58,   601,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     403,   403,     4,  -183,  -183,   634,    49,  -183,  -183,    90,
      95,    96,  -183,  -183,   403,    -6,  -183,  -183,  -183,   108,
    -183,   487,  -183,    49,  -183,  -183,    65,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,  -183,  -183,  -183,  -183,   667,
    -183,   667,  -183,   667,  -183,   667,  -183,   667,  -183,   667,
    -183,   667,  -183,   667,  -183,   667,  -183,   667,  -183,   667,
     -49,   667,   525,  -183,    39,  -183,    36,    74,    46,   547,
    -183,  -183,  -183,  -183,    27,   403,   780,   780,   792,   792,
      -6,  -183,  -183,   -35,    24,   711,   733,   792,   792,   -28,
     -28,    17,    17,    17,   403,  -183,   356,   403,   403,   403,
      63,   356,    49,    64,   667,   667,  -183,    66,   667,   579,
     667,   116,   130,  -183,   212,   475,    76,    34,   -18,   356,
    -183,   248,   802,   403,   403,    69,  -183,   689,  -183,    71,
      77,    78,    82,  -183,    80,  -183,  -183,    87,    88,    94,
      91,    92,   356,   356,   356,   356,  -183,   284,   151,   153,
     154,  -183,  -183,   320,   102,   105,   106,  -183,   116,   116,
     116,  -183,  -183,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -182,    -2,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -131,
     -65,    -4,   141,   164,    -8,  -183
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
      34,   135,   191,    91,    92,    93,    65,    95,     3,   202,
      91,    92,    93,    94,    95,    61,    69,    73,   143,    75,
      76,    77,    78,    66,   164,    81,   165,   102,   103,   104,
     105,   106,    82,    92,    93,   223,    83,   199,    67,   200,
     201,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   132,   203,    91,    92,    93,    94,    95,
      11,    12,    91,    92,    93,    68,   139,    71,    86,    19,
      20,    21,    22,    23,    74,   105,   106,   141,    60,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   231,   232,   233,
     172,    84,   173,    85,   136,   137,   138,   183,   145,   167,
     168,     4,     5,     6,     7,     8,     9,   169,    10,    11,
      12,   170,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   181,   184,   185,   174,    11,    12,
      25,    26,   187,   189,   209,    27,   198,   212,    20,    21,
      22,    23,   216,   213,   214,    64,   175,    28,   215,   178,
     179,   180,   -39,   -38,   176,   217,   -37,   -36,   224,   182,
     225,   226,   228,    29,    30,   229,   230,   197,    31,    32,
     140,   196,    33,    70,     0,   207,   208,   205,     0,   141,
     108,   110,   112,   114,   116,   118,   120,   122,   124,   126,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   219,   220,   221,     0,     4,     5,     6,     7,     8,
       9,   141,    10,    11,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    27,
       0,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    28,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,    29,    30,     0,
      25,    26,    31,    32,   190,    27,    33,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,    28,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,    29,    30,     0,    25,    26,    31,    32,
     206,    27,    33,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,    28,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,    29,
      30,     0,    25,    26,    31,    32,   222,    27,    33,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,    28,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,    29,    30,     0,    25,    26,
      31,    32,   227,    27,    33,     4,     5,     6,     7,     8,
       9,     0,    62,     0,     0,    28,     4,     5,     6,     7,
       8,     9,     0,    72,     0,     0,     0,     0,     0,     0,
       0,    29,    30,     0,    25,     0,    31,    32,     0,    27,
      33,     0,     0,     0,     0,    25,     0,     0,     0,     0,
      27,    28,     4,     5,     6,     7,     8,     9,     0,    62,
       0,     0,    28,     0,     0,     0,     0,    29,    30,     0,
       0,     0,    63,     0,     0,     0,    33,     0,    29,    30,
       0,    25,     0,     0,     0,     0,    27,    33,     4,     5,
       6,     7,     8,     9,     0,   192,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,     0,    25,     0,     0,
       0,     0,    27,    33,     0,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    28,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,   100,   101,     0,     0,     0,
     193,   194,   102,   103,   104,   105,   106,     0,     0,    33,
       0,     0,     0,    87,    88,    89,    90,     0,     0,     0,
       0,     0,   142,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,   100,   101,    87,    88,    89,    90,     0,
     102,   103,   104,   105,   106,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,   100,   101,     0,     0,     0,
     166,     0,   102,   103,   104,   105,   106,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,   171,    96,    97,    98,    99,   100,   101,    87,
      88,    89,    90,     0,   102,   103,   104,   105,   106,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,   100,
     101,     0,     0,     0,   186,     0,   102,   103,   104,   105,
     106,     0,    87,    88,    89,    90,     0,     0,     0,     0,
       0,   107,    91,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,     0,    87,    88,    89,    90,     0,
       0,     0,     0,     0,   133,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,   100,   101,    87,    88,    89,
      90,     0,   102,   103,   104,   105,   106,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,   100,   101,    87,
      88,    89,    90,     0,   102,   103,   104,   210,   211,    91,
      92,    93,    94,    95,     0,     0,    97,    98,    99,   100,
     101,    87,    88,    89,    90,     0,   102,   103,   104,   105,
     106,    91,    92,    93,    94,    95,     0,     0,     0,    98,
      99,   100,   101,     0,     0,     0,    49,     0,   102,   103,
     104,   105,   106,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,     0,     0,
      89,    90,     0,     0,     0,     0,     0,    60,    91,    92,
      93,    94,    95,     0,     0,     0,    98,    99,   100,   101,
      91,    92,    93,    94,    95,   102,   103,   104,   105,   106,
     100,   101,     0,     0,     0,    49,     0,   102,   103,   104,
     105,   106,    50,    51,    52,    53,    54,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
       2,    66,   184,    38,    39,    40,    14,    42,     0,    27,
      38,    39,    40,    41,    42,    74,    18,    25,    83,    27,
      28,    29,    30,    74,    73,    33,    75,    55,    56,    57,
      58,    59,    70,    39,    40,   217,    74,     3,    70,     5,
       6,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    72,    38,    39,    40,    41,    42,
      11,    12,    38,    39,    40,    70,    74,    74,    10,    20,
      21,    22,    23,    24,    74,    58,    59,    79,    74,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   228,   229,   230,
      73,    70,    75,    70,    14,    10,    10,   172,    43,    70,
      74,     3,     4,     5,     6,     7,     8,    43,    10,    11,
      12,    75,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    71,    71,    70,   145,    11,    12,
      32,    33,    26,    13,    75,    37,    70,    76,    21,    22,
      23,    24,    72,    76,    76,    14,   164,    49,    76,   167,
     168,   169,    75,    75,   166,    71,    75,    75,    17,   171,
      17,    17,    70,    65,    66,    70,    70,   185,    70,    71,
      72,   185,    74,    19,    -1,   193,   194,   189,    -1,   191,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,    -1,     3,     4,     5,     6,     7,
       8,   223,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    49,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    65,    66,    -1,
      32,    33,    70,    71,    72,    37,    74,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    49,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    65,    66,    -1,    32,    33,    70,    71,
      72,    37,    74,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    49,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    65,
      66,    -1,    32,    33,    70,    71,    72,    37,    74,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    49,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    65,    66,    -1,    32,    33,
      70,    71,    72,    37,    74,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    49,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    32,    -1,    70,    71,    -1,    37,
      74,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      37,    49,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    65,    66,
      -1,    32,    -1,    -1,    -1,    -1,    37,    74,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    32,    -1,    -1,
      -1,    -1,    37,    74,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    49,    38,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      65,    66,    55,    56,    57,    58,    59,    -1,    -1,    74,
      -1,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    75,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    28,    29,    30,    31,    -1,
      55,    56,    57,    58,    59,    38,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      75,    -1,    55,    56,    57,    58,    59,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    75,    44,    45,    46,    47,    48,    49,    28,
      29,    30,    31,    -1,    55,    56,    57,    58,    59,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    75,    -1,    55,    56,    57,    58,
      59,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    70,    38,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    70,    38,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    28,    29,    30,
      31,    -1,    55,    56,    57,    58,    59,    38,    39,    40,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    28,
      29,    30,    31,    -1,    55,    56,    57,    58,    59,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    28,    29,    30,    31,    -1,    55,    56,    57,    58,
      59,    38,    39,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    43,    -1,    55,    56,
      57,    58,    59,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    74,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      38,    39,    40,    41,    42,    55,    56,    57,    58,    59,
      48,    49,    -1,    -1,    -1,    43,    -1,    55,    56,    57,
      58,    59,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,    79,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    32,    33,    37,    49,    65,
      66,    70,    71,    74,    81,    82,    83,    85,    86,    87,
      91,    92,    93,    94,    97,    98,    99,   100,   101,    43,
      50,    51,    52,    53,    54,    60,    61,    62,    63,    64,
      74,    74,    10,    70,    99,   101,    74,    70,    70,    81,
     100,    74,    10,   101,    74,   101,   101,   101,   101,    80,
      81,   101,    70,    74,    70,    70,    10,    28,    29,    30,
      31,    38,    39,    40,    41,    42,    44,    45,    46,    47,
      48,    49,    55,    56,    57,    58,    59,    70,    99,   101,
      99,   101,    99,   101,    99,   101,    99,   101,    99,   101,
      99,   101,    99,   101,    99,   101,    99,   101,    99,   101,
      84,   101,   101,    70,    90,    97,    14,    10,    10,   101,
      72,    81,    75,    97,   102,    43,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,    73,    75,    75,    70,    74,    43,
      75,    75,    73,    75,   101,   101,    81,    89,   101,   101,
     101,    71,    81,    97,    71,    70,    75,    26,    96,    13,
      72,    80,    10,    65,    66,    88,    98,   101,    70,     3,
       5,     6,    27,    72,    95,    81,    72,   101,   101,    75,
      58,    59,    76,    76,    76,    76,    72,    71,    81,    81,
      81,    81,    72,    80,    17,    17,    17,    72,    70,    70,
      70,    96,    96,    96
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
#line 94 "parser.y"
    {check_unused_variables();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {write_to_assembly((yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {(yyval.nodePtr)=create_operation(';',yylineno,2,(yyvsp[(1) - (2)].nodePtr),(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyval.nodePtr)=create_operation(';',yylineno,2,NULL,NULL);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {(yyval.nodePtr)=create_operation(BLOCK,yylineno,1,(yyvsp[(2) - (3)].nodePtr));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyval.nodePtr)=create_operation(BREAK,yylineno,1,NULL);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {(yyval.nodePtr)=create_operation(CONTINUE,yylineno,1,NULL);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,yylineno,1,(yyvsp[(2) - (3)].nodePtr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,yylineno,1,NULL);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {
        (yyval.nodePtr) = create_operation(FUNCTION, yylineno, 4, (yyvsp[(1) - (7)].nodePtr), (yyvsp[(3) - (7)].nodePtr), (yyvsp[(6) - (7)].nodePtr), NULL);
        // printf("Parsed function %s\n", $2);  // Debug
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {(yyval.nodePtr)=create_operation(FUNCTION,yylineno,4,(yyvsp[(1) - (6)].nodePtr),(yyvsp[(3) - (6)].nodePtr),NULL,NULL);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval.nodePtr)=create_operation(FOR,yylineno,4,(yyvsp[(3) - (11)].nodePtr),(yyvsp[(5) - (11)].nodePtr),(yyvsp[(7) - (11)].nodePtr),(yyvsp[(10) - (11)].nodePtr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.nodePtr)=create_operation(FOR,yylineno,4,(yyvsp[(3) - (10)].nodePtr),(yyvsp[(5) - (10)].nodePtr),(yyvsp[(7) - (10)].nodePtr),NULL);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { (yyval.nodePtr) = create_operation(';', yylineno, 2, NULL, NULL); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_INC,yylineno,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_DEC,yylineno,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_INC,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_DEC,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval.nodePtr)=create_operation(';',yylineno,2,NULL,NULL);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {(yyval.nodePtr)=create_operation(';',yylineno,2,NULL,NULL);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {(yyval.nodePtr)=create_operation(WHILE,yylineno,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {(yyval.nodePtr)=create_operation(DO,yylineno,2,(yyvsp[(2) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,yylineno,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,yylineno,3,(yyvsp[(3) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,yylineno,2,create_identifier((yyvsp[(3) - (7)].sIndex),yylineno),(yyvsp[(6) - (7)].nodePtr));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,yylineno,3,create_identifier((yyvsp[(3) - (8)].sIndex),yylineno),(yyvsp[(6) - (8)].nodePtr),(yyvsp[(7) - (8)].nodePtr));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.nodePtr)=create_operation(DEFAULT,yylineno,1,(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,4,create_constant(INTEGER,yylineno,INT_TYPE,(yyvsp[(2) - (7)].intValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,yylineno,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,4,create_constant(STRING,yylineno,STRING_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,yylineno,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,4,create_constant(CHARACTER,yylineno,CHAR_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,yylineno,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,3,create_constant(INTEGER,yylineno,INT_TYPE,(yyvsp[(2) - (6)].intValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,yylineno,0));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,3,create_constant(STRING,yylineno,STRING_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,yylineno,0));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,yylineno,3,create_constant(CHARACTER,yylineno,CHAR_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,yylineno,0));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval.nodePtr)=create_operation(DECLARATION,yylineno,1,create_identifier((yyvsp[(2) - (2)].sIndex),yylineno,(yyvsp[(1) - (2)].intValue),0));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.nodePtr)=create_operation(DECLARATION,yylineno,2,create_identifier((yyvsp[(2) - (4)].sIndex),yylineno,(yyvsp[(1) - (4)].intValue),0),(yyvsp[(4) - (4)].nodePtr));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {(yyval.nodePtr)=create_operation(DECLARATION,yylineno,2,create_identifier((yyvsp[(3) - (5)].sIndex),yylineno,(yyvsp[(2) - (5)].intValue),1),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.nodePtr)=create_operation('=',yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {(yyval.nodePtr)=create_operation('=',yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {(yyval.nodePtr)=create_operation(PLUS_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {(yyval.nodePtr)=create_operation(SUB_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.nodePtr)=create_operation(MUL_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.nodePtr)=create_operation(DIV_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {(yyval.nodePtr)=create_operation(MOD_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {(yyval.nodePtr)=create_operation(PLUS_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {(yyval.nodePtr)=create_operation(SUB_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {(yyval.nodePtr)=create_operation(MUL_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval.nodePtr)=create_operation(DIV_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {(yyval.nodePtr)=create_operation(MOD_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {(yyval.nodePtr)=create_operation(BITWISE_AND_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {(yyval.nodePtr)=create_operation( BITWISE_OR_ASSIGN ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {(yyval.nodePtr)=create_operation(BITWISE_XOR_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTL_ASSIGN      ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTR_ASSIGN      ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {(yyval.nodePtr)=create_operation(BITWISE_AND_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {(yyval.nodePtr)=create_operation( BITWISE_OR_ASSIGN ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {(yyval.nodePtr)=create_operation(BITWISE_XOR_ASSIGN,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTL_ASSIGN      ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTR_ASSIGN      ,yylineno,2,create_identifier((yyvsp[(1) - (3)].sIndex),yylineno),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {(yyval.nodePtr)=create_operation(CALL,yylineno,2,create_identifier((yyvsp[(1) - (4)].sIndex),yylineno),(yyvsp[(3) - (4)].nodePtr));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {(yyval.intValue)=INT_TYPE;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval.intValue)=FLOAT_TYPE;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {(yyval.intValue)=CHAR_TYPE;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {(yyval.intValue)=VOID;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {(yyval.intValue)=BOOL_TYPE;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {(yyval.intValue)=STRING_TYPE;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_INC,yylineno,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_DEC,yylineno,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_INC,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_DEC,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {(yyval.nodePtr)=create_operation(NOT_LOG,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {(yyval.nodePtr)=create_operation('+',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {(yyval.nodePtr)=create_operation('-',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {(yyval.nodePtr)=create_operation('*',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {(yyval.nodePtr)=create_operation('/',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {(yyval.nodePtr)=create_operation(EQ,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {(yyval.nodePtr)=create_operation(NEQ,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {(yyval.nodePtr)=create_operation('<',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {(yyval.nodePtr)=create_operation(MOD,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    {(yyval.nodePtr)=create_operation('>',yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {(yyval.nodePtr)=create_operation(LTE,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    {(yyval.nodePtr)=create_operation(GTE,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {(yyval.nodePtr)=create_operation(AND,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    {(yyval.nodePtr)=create_operation(OR_LOG,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {(yyval.nodePtr)=create_operation(AND_LOG,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {(yyval.nodePtr)=create_operation(XOR_LOG,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTR_LOG,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {(yyval.nodePtr)=create_operation(SHIFTR_LOG,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {(yyval.nodePtr)=create_operation(OR,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 281 "parser.y"
    {(yyval.nodePtr)=create_operation(NOT,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {(yyval.nodePtr)=create_operation(NEGATIVE,yylineno,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {(yyval.nodePtr)=create_constant(INTEGER,yylineno,INT_TYPE,(yyvsp[(1) - (1)].intValue));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {(yyval.nodePtr)=create_constant(FLOAT,yylineno,FLOAT_TYPE,(yyvsp[(1) - (1)].floatValue));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,yylineno,BOOL_TYPE,1);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,yylineno,BOOL_TYPE,0);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {(yyval.nodePtr)=create_constant(STRING,yylineno,STRING_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {(yyval.nodePtr)=create_constant(CHARACTER,yylineno,CHAR_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {(yyval.nodePtr)=create_identifier((yyvsp[(1) - (1)].sIndex),yylineno);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(2) - (3)].nodePtr);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,yylineno,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;



/* Line 1455 of yacc.c  */
#line 2642 "parser.tab.c"
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
#line 302 "parser.y"

// Node construction functions
// Create operation nodes
Node* create_operation(int oper, int line_number,int nops,...) {
    va_list ap;
    Node *p;
    size_t nodeSize;
    int i;
    
    
    nodeSize = sizeof(Node) + sizeof(OperationNode) + (nops - 1) * sizeof(Node*);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory", line_number);

    p->type = OPERATION;
    p->opr.symbol = oper;
    p->opr.nops = nops;
    p->line_number = line_number;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

// Create constant nodes

Node* create_constant(int type, int line_number, int dataType, ...) {
    va_list ap;
    Node *p;
    size_t nodeSize;

    nodeSize = sizeof(Node) + sizeof(ConstantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory", line_number);

    p->type = CONSTANT;
    p->con.dataType = dataType;
    p->line_number = line_number;
    va_start(ap, dataType);
    
    switch(dataType) {
        case INT_TYPE:
            p->con.value.intVal = va_arg(ap, int);
            break;
        case FLOAT_TYPE:
            p->con.value.floatVal = (float)va_arg(ap, double);
            break;
        case STRING_TYPE:
        case CHAR_TYPE:
            p->con.value.strVal = va_arg(ap, char*);
            break;
        case BOOL_TYPE:
            p->con.value.boolVal = va_arg(ap, int);
            break;
        default:
            memset(&p->con.value, 0, sizeof(ValueType));
    }
    va_end(ap);
    return p;
}
// Create identifier nodes
Node* create_identifier(char* i, int line_number, int dataType, int qualifier) {
    Node *p;
    size_t nodeSize;
    nodeSize = sizeof(Node) + sizeof(VariableNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        {
            printf("out of memory\n");
            yyerror("out of memory",line_number);}
    if(i == NULL)
    {

        printf("data %d\n", dataType);
        printf("qual %d\n", qualifier);
    }
    p->type = VARIABLE;
    p->line_number = line_number;
    p->id.name =  strdup(i) ;  // Handle null case
    p->id.dataType = dataType;
    p->id.qualifier = qualifier;
    
    return p;
}

void free_node(Node *p) {
    int i;
    if (!p) return;
    if (p->type == OPERATION) {
        for (i = 0; i < p->opr.nops; i++)
        free_node(p->opr.op[i]);
    }
    free(p);
}
    
 void yyerror(const char *emsg, int line_number ,const char* filename)
 {
    log_errors(line_number, emsg,filename);
    log_symbol_table("symbol_table.txt");
    /* exit(0); */
}
/* 
int main() {
    printf("Starting compilation...\n");
    
    try {
        open_assembly_file();  // Open this early to catch errors
        
        printf("Starting parsing...\n");
        int parse_result = yyparse();
        
        if (parse_result == 0) {
            printf("Parsing completed successfully\n");
            
            // Add flush to ensure output isn't buffered
            fflush(stdout);
            fflush(assemblyOutFile);
            
            printf("Generating symbol table...\n");
            log_symbol_table();
            
            printf("Compilation completed successfully\n");
        } else {

            fprintf(stderr, "Syntax Error at line %d\n",yylineno);
        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        return 1;
    }
    
    if (assemblyOutFile) {
        fclose(assemblyOutFile);
    }
    
    return 0;
} */
/* int main() {
    // Add these extern declarations
    extern char* yytext;    // Current token text (from lexer)

    printf("Starting compilation...\n");
    
    try {
        printf("Attempting to open assembly output file...\n");
        open_assembly_file();  // Open this early to catch errors
        printf("Assembly file opened successfully\n");
        
        printf("Starting parsing... (lexer/parser initialization)\n");
        int parse_result = yyparse();
        
        if (parse_result == 0) {
            printf("Parsing completed successfully\n");
            
            // Add flush to ensure output isn't buffered
            printf("Flushing output buffers...\n");
            fflush(stdout);
            fflush(assemblyOutFile);
            
            printf("Generating symbol table...\n");
            log_symbol_table("s.txt");
            
            printf("Compilation completed successfully\n");
        } else {
   
            char msg[1024];
            sprintf(msg,"Syntax error near %s ",yytext);
            yyerror(msg,yylineno);

        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        fprintf(stderr, "Error occurred at line %d\n", yylineno);
        return 1;
    }
    
    if (assemblyOutFile) {
        printf("Closing assembly output file...\n");
        fclose(assemblyOutFile);
    }
    
    printf("Exiting with return code 0\n");
    return 0;
} */

int main(int argc, char *argv[]) {
    extern char* yytext;
    char error_filename[256];
    char symbol_table_filename[256];
    char assembly_filename[256];

    if (argc < 2) {
        printf("Usage: %s <script_name>\n", argv[0]);
        return 1;
    }

    const char *script_name = argv[1];
    // Global filenames for output

    // Set filenames based on script name
    snprintf(error_filename, sizeof(error_filename), "errors_%s.txt", script_name);
    snprintf(symbol_table_filename, sizeof(symbol_table_filename), "symbol_table_%s.txt", script_name);
    snprintf(assembly_filename, sizeof(assembly_filename), "assembly_%s.txt", script_name);

    printf("Starting compilation for script: %s\n", script_name);
    char msg[1024];
    sprintf(msg,"===============================================%s=========================\n",script_name);
    yyerror(msg);

    try {
        printf("Attempting to open assembly output file...\n");
        open_assembly_file(assembly_filename);
        printf("Assembly file opened successfully\n");

        printf("Starting parsing... (lexer/parser initialization)\n");
        int parse_result = yyparse();

        if (parse_result == 0) {
            printf("Parsing completed successfully\n");

            printf("Flushing output buffers...\n");
            fflush(stdout);
            fflush(assemblyOutFile);

            printf("Generating symbol table...\n");
            log_symbol_table(symbol_table_filename);
            
            printf("Compilation completed successfully\n");
        } else {
            char msg[1024];
            sprintf(msg, "Syntax error near %s", yytext);
            yyerror(msg, yylineno); // Simple call, no filenames passed
        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        fprintf(stderr, "Error occurred at line %d\n", yylineno);
        return 1;
    }

    if (assemblyOutFile) {
        printf("Closing assembly output file...\n");
        fclose(assemblyOutFile);
    }

    printf("Exiting with return code 0\n");
    return 0;
}

