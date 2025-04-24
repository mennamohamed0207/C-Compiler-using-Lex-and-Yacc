
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
    extern void log_symbol_table();
    extern void log_errors(int line, const char *msg);
    extern void check_unused_variables();
    extern void log_symbol_table();
    extern void open_assembly_file();
    extern FILE *assemblyOutFile;


    Node* create_operation(int oper, int nops,...);
    Node* create_constant(int type ,int dataType);
    Node* create_identifier(char* i, int dataType, int qualifier);
    void free_node(Node *p);

    int write_to_assembly(Node *p, Node *parent=NULL, int cont = -1, int brk = -1, int args = 0, ...);
    extern int yylex();
    void yyerror(const char *s);
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
     OR = 292,
     AND = 293,
     MOD = 294,
     POST_DEC = 295,
     POST_INC = 296,
     PRE_DEC = 297,
     PRE_INC = 298,
     NEGATIVE = 299,
     LOWER_THAN_ELSE = 300,
     FUNC = 301
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
#line 204 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 216 "parser.tab.c"

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
#define YYLAST   496

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    59,    44,    42,    57,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    54,
      40,    37,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      35,    36,    38,    39,    46,    47,    48,    49,    50,    51,
      52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    19,
      21,    25,    27,    29,    31,    34,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    54,    56,    60,    64,    67,
      76,    86,    87,    89,    93,    95,    96,    98,   104,   112,
     118,   126,   134,   143,   147,   155,   163,   171,   178,   185,
     192,   195,   200,   206,   210,   214,   219,   221,   223,   225,
     227,   229,   231,   234,   237,   240,   243,   247,   251,   255,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   295,
     298,   301,   303,   305,   307,   309,   311,   313,   315,   319,
     323,   325
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    -1,    -1,    63,    65,    -1,    65,
      -1,    64,    65,    -1,    54,    -1,    66,    54,    -1,    67,
      -1,    55,    64,    56,    -1,    81,    -1,    85,    -1,    69,
      -1,    17,    54,    -1,    18,    54,    -1,    82,    -1,    83,
      -1,    71,    -1,    75,    -1,    77,    -1,    76,    -1,    70,
      -1,    78,    -1,    -1,    85,    -1,    68,    57,    85,    -1,
      15,    85,    54,    -1,    15,    54,    -1,    81,    58,    86,
      59,    55,    64,    69,    56,    -1,    16,    58,    74,    54,
      73,    54,    72,    59,    65,    -1,    -1,    82,    -1,    85,
      57,    85,    -1,    85,    -1,    -1,    81,    -1,    14,    58,
      85,    59,    65,    -1,    19,    65,    14,    58,    85,    59,
      54,    -1,    33,    58,    85,    59,    65,    -1,    33,    58,
      85,    59,    65,    13,    65,    -1,    25,    58,    10,    59,
      55,    80,    56,    -1,    25,    58,    10,    59,    55,    80,
      79,    56,    -1,    27,    60,    65,    -1,    26,     3,    60,
      65,    17,    54,    80,    -1,    26,     5,    60,    65,    17,
      54,    80,    -1,    26,     6,    60,    65,    17,    54,    80,
      -1,    26,     3,    60,    65,    17,    54,    -1,    26,     5,
      60,    65,    17,    54,    -1,    26,     6,    60,    65,    17,
      54,    -1,    84,    10,    -1,    84,    10,    37,    85,    -1,
      20,    84,    10,    37,    85,    -1,    10,    37,    85,    -1,
      10,    37,    83,    -1,    10,    58,    68,    59,    -1,    23,
      -1,    24,    -1,    11,    -1,    12,    -1,    22,    -1,    21,
      -1,    85,    48,    -1,    85,    47,    -1,    50,    85,    -1,
      49,    85,    -1,    85,    42,    85,    -1,    85,    43,    85,
      -1,    85,    44,    85,    -1,    85,    45,    85,    -1,    85,
      28,    85,    -1,    85,    29,    85,    -1,    85,    40,    85,
      -1,    85,    46,    85,    -1,    85,    41,    85,    -1,    85,
      30,    85,    -1,    85,    31,    85,    -1,    85,    39,    85,
      -1,    85,    38,    85,    -1,    32,    85,    -1,    43,    85,
      -1,     3,    -1,     4,    -1,     7,    -1,     8,    -1,     5,
      -1,     6,    -1,    10,    -1,    58,    85,    59,    -1,    81,
      57,    86,    -1,    81,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    86,    87,    90,    91,    94,    95,    96,
      97,   102,   103,   104,   105,   106,   107,   108,   112,   113,
     114,   115,   116,   117,   124,   125,   126,   130,   131,   134,
     141,   145,   146,   149,   150,   153,   154,   160,   164,   168,
     169,   172,   173,   177,   180,   181,   182,   183,   184,   185,
     189,   190,   191,   194,   195,   198,   201,   202,   203,   204,
     205,   206,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   243,
     244,   245
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
  "DECLARATION", "'='", "OR", "AND", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "MOD", "POST_DEC", "POST_INC", "PRE_DEC", "PRE_INC", "NEGATIVE",
  "LOWER_THAN_ELSE", "FUNC", "';'", "'{'", "'}'", "','", "'('", "')'",
  "':'", "$accept", "root", "program", "statement_list", "statement",
  "single_statement", "compound_statement", "params", "return_statement",
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
     285,   286,   287,   288,   289,   290,   291,    61,   292,   293,
      60,    62,    43,    45,    42,    47,   294,   295,   296,   297,
     298,   299,   300,   301,    59,   123,   125,    44,    40,    41,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    77,
      77,    78,    78,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    82,    82,    83,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     1,
       3,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     3,     2,     8,
       9,     0,     1,     3,     1,     0,     1,     5,     7,     5,
       7,     7,     8,     3,     7,     7,     7,     6,     6,     6,
       2,     4,     5,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    81,    82,    85,    86,    83,    84,
      87,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      61,    60,    56,    57,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     4,     0,     9,    13,    22,    18,    19,
      21,    20,    23,    11,    16,    17,     0,    12,     0,    24,
       0,    87,    28,     0,    35,    14,    15,     0,     0,     0,
      79,     0,    80,    65,    64,     0,     5,     0,     8,    91,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    62,    87,    54,    53,     0,
      25,     0,    27,     0,    36,     0,     0,     0,     0,    10,
       6,    88,    90,     0,     0,    70,    71,    75,    76,    78,
      77,    72,    74,    66,    67,    68,    69,    73,     0,    55,
       0,     0,     0,     0,     0,     0,    91,     0,    51,    26,
      37,     0,    34,     0,    52,     0,    39,    89,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
      38,     0,     0,     0,     0,    41,     0,    40,    13,     0,
       0,     0,     0,     0,    42,    29,    30,     0,     0,     0,
      43,     0,     0,     0,    47,    48,    49,    44,    45,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    65,    66,    34,    35,    89,    36,    37,
      38,   147,   131,    93,    39,    40,    41,    42,   156,   143,
      43,    44,    45,    46,    47,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
    -144,     6,   215,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
     -34,  -144,  -144,   -24,    45,   -18,   -10,    -9,   215,    35,
    -144,  -144,  -144,  -144,     2,   246,     3,   246,   246,   246,
    -144,   215,   246,  -144,     8,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,    20,  -144,  -144,    69,   106,   276,   246,
     246,  -144,  -144,   408,    15,  -144,  -144,    72,    77,    79,
    -144,   246,  -144,  -144,  -144,   159,  -144,   299,  -144,    15,
      53,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,  -144,  -144,    33,  -144,   106,   -40,
     106,   321,  -144,    38,  -144,    40,    56,    41,   343,  -144,
    -144,  -144,    39,    42,   246,   448,   448,   -33,   -33,   270,
     429,   -33,   -33,    37,    37,   -19,   -19,   -19,   246,  -144,
     215,   246,   246,   246,    47,   215,    15,    49,   106,   106,
    -144,    51,   387,   365,   106,    80,    94,  -144,   215,    98,
     246,    55,    -1,   -26,   215,   215,    73,    54,  -144,   106,
    -144,    52,    57,    59,    60,  -144,    65,  -144,    66,   215,
     215,   215,   215,   215,  -144,  -144,  -144,   107,   108,   109,
    -144,    74,    75,    76,    80,    80,    80,  -144,  -144,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   -11,    -2,  -144,  -144,  -144,   -14,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -143,
     -46,     0,    84,   119,    -7,    14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,   154,   151,    48,   152,   153,     3,    53,    94,    79,
      80,    81,    82,    83,    84,    85,    57,   118,    60,   119,
      62,    63,    64,   102,    49,    67,    11,    12,    84,    85,
     155,   177,   178,   179,    50,    19,    20,    21,    22,    23,
      54,    88,    90,    91,    55,    56,    11,    12,     4,     5,
       6,     7,     8,     9,    98,    51,    20,    21,    22,    23,
      59,    61,    68,   100,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    25,    69,    70,
     102,    81,    82,    83,    84,    85,    95,    96,    27,    97,
     104,    49,   121,   123,    28,    29,   126,   128,   122,    52,
     124,   127,   135,    32,   138,   139,   142,   144,   146,   150,
      48,   129,   160,   159,   132,   133,   134,   161,   130,   162,
     163,   164,   165,   136,   171,   172,   173,   145,   174,   175,
     176,   158,    87,   149,    71,    72,    73,    74,    58,   148,
     137,     0,   157,   100,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,   166,   167,   168,
     169,   170,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,     0,     0,    30,    31,    99,     0,    32,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     4,
       5,     6,     7,     8,     9,     0,    51,     0,    27,     0,
       0,     0,     0,     0,    28,    29,     0,     0,     0,    30,
      31,     0,     0,    32,     0,     0,     0,     0,    25,     4,
       5,     6,     7,     8,     9,     0,    86,     0,     0,    27,
       0,     0,     0,     0,     0,    28,    29,     0,    71,    72,
      73,    74,     0,     0,    32,     0,     0,     0,    25,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    27,
       0,     0,     0,     0,     0,    28,    29,    71,    72,    73,
      74,     0,     0,     0,    32,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    71,
      72,    73,    74,     0,     0,     0,     0,     0,   101,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    71,    72,    73,    74,     0,     0,     0,     0,     0,
     120,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,   125,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,   141,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    71,    72,    73,    74,
       0,     0,     0,     0,   140,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    71,    72,    73,
      74,     0,    92,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       2,    27,     3,    37,     5,     6,     0,    14,    54,    42,
      43,    44,    45,    46,    47,    48,    18,    57,    25,    59,
      27,    28,    29,    69,    58,    32,    11,    12,    47,    48,
      56,   174,   175,   176,    58,    20,    21,    22,    23,    24,
      58,    48,    49,    50,    54,    54,    11,    12,     3,     4,
       5,     6,     7,     8,    61,    10,    21,    22,    23,    24,
      58,    58,    54,    65,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    32,    58,    10,
     126,    44,    45,    46,    47,    48,    14,    10,    43,    10,
      37,    58,    54,    37,    49,    50,    57,   104,    58,    54,
      59,    59,    55,    58,    55,    54,    26,    13,    10,    54,
      37,   118,    60,    59,   121,   122,   123,    60,   120,    60,
      60,    56,    56,   125,    17,    17,    17,   138,    54,    54,
      54,   145,    48,   140,    28,    29,    30,    31,    19,   139,
     126,    -1,   144,   145,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,   159,   160,   161,
     162,   163,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    32,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    28,    29,
      30,    31,    -1,    -1,    58,    -1,    -1,    -1,    32,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    43,
      -1,    -1,    -1,    -1,    -1,    49,    50,    28,    29,    30,
      31,    -1,    -1,    -1,    58,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    59,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      59,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    59,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    59,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    57,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    28,    29,    30,
      31,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    32,    33,    43,    49,    50,
      54,    55,    58,    65,    66,    67,    69,    70,    71,    75,
      76,    77,    78,    81,    82,    83,    84,    85,    37,    58,
      58,    10,    54,    85,    58,    54,    54,    65,    84,    58,
      85,    58,    85,    85,    85,    64,    65,    85,    54,    58,
      10,    28,    29,    30,    31,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    10,    83,    85,    68,
      85,    85,    54,    74,    81,    14,    10,    10,    85,    56,
      65,    59,    81,    86,    37,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    57,    59,
      59,    54,    58,    37,    59,    59,    57,    59,    85,    85,
      65,    73,    85,    85,    85,    55,    65,    86,    55,    54,
      57,    59,    26,    80,    13,    64,    10,    72,    82,    85,
      54,     3,     5,     6,    27,    56,    79,    65,    69,    59,
      60,    60,    60,    60,    56,    56,    65,    65,    65,    65,
      65,    17,    17,    17,    54,    54,    54,    80,    80,    80
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
#line 82 "parser.y"
    {check_unused_variables();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    {write_to_assembly((yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {(yyval.nodePtr)=create_operation(';',2,(yyvsp[(1) - (2)].nodePtr),(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {(yyval.nodePtr)=create_operation(';',2,NULL,NULL);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval.nodePtr)=create_operation(BLOCK,1,(yyvsp[(2) - (3)].nodePtr));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {(yyval.nodePtr)=create_operation(BREAK,1,NULL);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyval.nodePtr)=create_operation(CONTINUE,1,NULL);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,1,(yyvsp[(2) - (3)].nodePtr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,1,NULL);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {
        (yyval.nodePtr) = create_operation(FUNCTION, 4, (yyvsp[(1) - (8)].nodePtr), (yyvsp[(3) - (8)].nodePtr), (yyvsp[(6) - (8)].nodePtr), (yyvsp[(7) - (8)].nodePtr));
        // printf("Parsed function %s\n", $2);  // Debug
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {(yyval.nodePtr)=create_operation(FOR,4,(yyvsp[(3) - (9)].nodePtr),(yyvsp[(5) - (9)].nodePtr),(yyvsp[(7) - (9)].nodePtr),(yyvsp[(9) - (9)].nodePtr));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval.nodePtr) = create_operation(';', 2, NULL, NULL); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {(yyval.nodePtr)=create_operation(',',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval.nodePtr)=create_operation(';',2,NULL,NULL);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {(yyval.nodePtr)=create_operation(WHILE,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.nodePtr)=create_operation(DO,2,(yyvsp[(2) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,3,(yyvsp[(3) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,2,create_identifier((yyvsp[(3) - (7)].sIndex)),(yyvsp[(6) - (7)].nodePtr));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,2,create_identifier((yyvsp[(3) - (8)].sIndex)),(yyvsp[(6) - (8)].nodePtr),(yyvsp[(7) - (8)].nodePtr));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {(yyval.nodePtr)=create_operation(DEFAULT,1,(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(INTEGER,INT_TYPE,(yyvsp[(2) - (7)].intValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(CHARACTER,CHAR_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(INTEGER,INT_TYPE,(yyvsp[(2) - (6)].intValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,3,create_constant(CHARACTER,CHAR_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval.nodePtr)=create_operation(DECLARATION,1,create_identifier((yyvsp[(2) - (2)].sIndex),(yyvsp[(1) - (2)].intValue),0));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(2) - (4)].sIndex),(yyvsp[(1) - (4)].intValue)),(yyvsp[(4) - (4)].nodePtr));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(3) - (5)].sIndex),(yyvsp[(2) - (5)].intValue),1),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(1) - (3)].sIndex)),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(1) - (3)].sIndex)),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.nodePtr)=create_operation(CALL,2,create_identifier((yyvsp[(1) - (4)].sIndex)),(yyvsp[(3) - (4)].nodePtr));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval.intValue)=INT_TYPE;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {(yyval.intValue)=FLOAT_TYPE;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {(yyval.intValue)=CHAR_TYPE;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {(yyval.intValue)=VOID;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {(yyval.intValue)=BOOL_TYPE;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval.intValue)=STRING_TYPE;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_INC,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_DEC,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_INC,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_DEC,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {(yyval.nodePtr)=create_operation('+',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {(yyval.nodePtr)=create_operation('-',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.nodePtr)=create_operation('*',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {(yyval.nodePtr)=create_operation('/',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {(yyval.nodePtr)=create_operation(EQ,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {(yyval.nodePtr)=create_operation(NEQ,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.nodePtr)=create_operation('<',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.nodePtr)=create_operation(MOD,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {(yyval.nodePtr)=create_operation('>',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {(yyval.nodePtr)=create_operation(LTE,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {(yyval.nodePtr)=create_operation(GTE,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {(yyval.nodePtr)=create_operation(AND,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval.nodePtr)=create_operation(OR,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {(yyval.nodePtr)=create_operation(NOT,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {(yyval.nodePtr)=create_operation(NEGATIVE,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {(yyval.nodePtr)=create_constant(INTEGER,INT_TYPE,(yyvsp[(1) - (1)].intValue));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {(yyval.nodePtr)=create_constant(FLOAT,FLOAT_TYPE,(yyvsp[(1) - (1)].floatValue));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,BOOL_TYPE,1);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,BOOL_TYPE,0);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {(yyval.nodePtr)=create_constant(STRING,STRING_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {(yyval.nodePtr)=create_constant(CHARACTER,CHAR_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {(yyval.nodePtr)=create_identifier((yyvsp[(1) - (1)].sIndex));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(2) - (3)].nodePtr);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;



/* Line 1455 of yacc.c  */
#line 2271 "parser.tab.c"
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
#line 248 "parser.y"

// Node construction functions
// Create operation nodes
Node* create_operation(int oper, int nops,...) {
    va_list ap;
    Node *p;
    size_t nodeSize;
    int i;
    
    
    nodeSize = sizeof(Node) + sizeof(OperationNode) + (nops - 1) * sizeof(Node*);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = OPERATION;
    p->opr.symbol = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

// Create constant nodes

Node* create_constant(int type, int dataType, ...) {
    va_list ap;
    Node *p;
    size_t nodeSize;

    nodeSize = sizeof(Node) + sizeof(ConstantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = CONSTANT;
    p->con.dataType = dataType;
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
Node* create_identifier(char* i, int dataType, int qualifier) {
    Node *p;
    size_t nodeSize;
    nodeSize = sizeof(Node) + sizeof(VariableNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        {
            printf("out of memory\n");
            yyerror("out of memory");}
    if(i == NULL)
    {

        printf("data %d\n", dataType);
        printf("qual %d\n", qualifier);
    }
    p->type = VARIABLE;
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
    
void yyerror(const char *s) {
    fprintf(stderr, "Parser Error at line %d: %s\n", yylineno, s);
    log_errors(yylineno, s);
    log_symbol_table();
}

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
            fprintf(stderr, "Parsing failed with errors\n");
        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        return 1;
    }
    
    if (assemblyOutFile) {
        fclose(assemblyOutFile);
    }
    
    return 0;
}
