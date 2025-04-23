
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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "compiler.h"
    extern void log_symbol_table();
    extern void log_errors(int line, const char *msg);
    extern void check_unused_variables();


    Node* create_operation(int oper, int nops,...);
    Node* create_constant(int type ,int dataType);
    Node* create_identifier(char* i, int dataType, int qualifier);
    void free_node(Node *p);

    int write_to_assembly(Node *p, int cont = -1, int brk = -1, int args = 0, ...);
    extern int yylex();
    void yyerror(const char *s);
    extern int yylineno;



/* Line 189 of yacc.c  */
#line 95 "parser.tab.c"

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
     INTEGER = 258,
     FLOAT = 259,
     STRING = 260,
     CHARACTER = 261,
     TRUE = 262,
     FALSE = 263,
     IDENTIFIER = 264,
     CHAR_TYPE = 265,
     VOID = 266,
     ELSE = 267,
     WHILE = 268,
     RETURN = 269,
     FOR = 270,
     BREAK = 271,
     CONTINUE = 272,
     DO = 273,
     CONST = 274,
     STRING_TYPE = 275,
     BOOL_TYPE = 276,
     INT_TYPE = 277,
     FLOAT_TYPE = 278,
     SWITCH = 279,
     CASE = 280,
     DEFAULT = 281,
     EQ = 282,
     NEQ = 283,
     LTE = 284,
     GTE = 285,
     NOT = 286,
     IF = 287,
     OR = 288,
     AND = 289,
     POST_DEC = 290,
     POST_INC = 291,
     PRE_DEC = 292,
     PRE_INC = 293,
     NEGATIVE = 294,
     LOWER_THAN_ELSE = 295,
     FUNC = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "parser.y"

  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char* charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer



/* Line 214 of yacc.c  */
#line 185 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "parser.tab.c"

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
#define YYLAST   402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,    40,    38,    52,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    49,
      36,    33,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      42,    43,    44,    45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    14,    18,    20,
      22,    24,    27,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    47,    49,    53,    56,    66,    76,    80,    82,
      83,    85,    91,    99,   105,   113,   121,   130,   134,   142,
     150,   158,   165,   172,   179,   182,   187,   193,   197,   201,
     206,   208,   210,   212,   214,   216,   218,   221,   224,   227,
     230,   234,   238,   242,   246,   250,   254,   258,   262,   266,
     270,   274,   278,   281,   284,   286,   288,   290,   292,   294,
     296,   298,   302,   306,   308
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    -1,    58,    59,    -1,    60,
      49,    -1,    61,    -1,    50,    58,    51,    -1,    74,    -1,
      78,    -1,    63,    -1,    16,    49,    -1,    17,    49,    -1,
      75,    -1,    76,    -1,    65,    -1,    68,    -1,    70,    -1,
      69,    -1,    64,    -1,    71,    -1,    -1,    78,    -1,    62,
      52,    78,    -1,    14,    59,    -1,    77,     9,    53,    79,
      54,    50,    58,    63,    51,    -1,    15,    53,    67,    49,
      66,    49,    66,    54,    59,    -1,    78,    52,    78,    -1,
      78,    -1,    -1,    74,    -1,    13,    53,    78,    54,    59,
      -1,    18,    59,    13,    53,    78,    54,    49,    -1,    32,
      53,    78,    54,    59,    -1,    32,    53,    78,    54,    59,
      12,    59,    -1,    24,    53,     9,    54,    50,    73,    51,
      -1,    24,    53,     9,    54,    50,    73,    72,    51,    -1,
      26,    55,    59,    -1,    25,     3,    55,    59,    16,    49,
      73,    -1,    25,     5,    55,    59,    16,    49,    73,    -1,
      25,     6,    55,    59,    16,    49,    73,    -1,    25,     3,
      55,    59,    16,    49,    -1,    25,     5,    55,    59,    16,
      49,    -1,    25,     6,    55,    59,    16,    49,    -1,    77,
       9,    -1,    77,     9,    33,    78,    -1,    19,    77,     9,
      33,    78,    -1,     9,    33,    78,    -1,     9,    33,    76,
      -1,     9,    53,    62,    54,    -1,    22,    -1,    23,    -1,
      10,    -1,    11,    -1,    21,    -1,    20,    -1,    78,    43,
      -1,    78,    42,    -1,    45,    78,    -1,    44,    78,    -1,
      78,    38,    78,    -1,    78,    39,    78,    -1,    78,    40,
      78,    -1,    78,    41,    78,    -1,    78,    27,    78,    -1,
      78,    28,    78,    -1,    78,    36,    78,    -1,    78,    37,
      78,    -1,    78,    29,    78,    -1,    78,    30,    78,    -1,
      78,    35,    78,    -1,    78,    34,    78,    -1,    31,    78,
      -1,    39,    78,    -1,     3,    -1,     4,    -1,     7,    -1,
       8,    -1,     5,    -1,     6,    -1,     9,    -1,    53,    78,
      54,    -1,    74,    52,    79,    -1,    74,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    76,    77,    81,    82,    83,    87,    88,
      89,    90,    91,    92,    93,    97,    98,    99,   100,   101,
     102,   109,   110,   111,   115,   118,   122,   125,   126,   129,
     130,   136,   140,   144,   145,   148,   149,   153,   156,   157,
     158,   159,   160,   161,   165,   166,   167,   170,   171,   174,
     177,   178,   179,   180,   181,   182,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   218,   219,   220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "STRING",
  "CHARACTER", "TRUE", "FALSE", "IDENTIFIER", "CHAR_TYPE", "VOID", "ELSE",
  "WHILE", "RETURN", "FOR", "BREAK", "CONTINUE", "DO", "CONST",
  "STRING_TYPE", "BOOL_TYPE", "INT_TYPE", "FLOAT_TYPE", "SWITCH", "CASE",
  "DEFAULT", "EQ", "NEQ", "LTE", "GTE", "NOT", "IF", "'='", "OR", "AND",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "POST_DEC", "POST_INC",
  "PRE_DEC", "PRE_INC", "NEGATIVE", "LOWER_THAN_ELSE", "FUNC", "';'",
  "'{'", "'}'", "','", "'('", "')'", "':'", "$accept", "root", "program",
  "statement", "single_statement", "compound_statement", "params",
  "return_statement", "function_definition", "for_statement",
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
     285,   286,   287,    61,   288,   289,    60,    62,    43,    45,
      42,    47,   290,   291,   292,   293,   294,   295,   296,    59,
     123,   125,    44,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    64,    65,    66,    66,    67,
      67,    68,    69,    70,    70,    71,    71,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    76,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     3,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     2,     9,     9,     3,     1,     0,
       1,     5,     7,     5,     7,     7,     8,     3,     7,     7,
       7,     6,     6,     6,     2,     4,     5,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    74,    75,    78,    79,    76,    77,
      80,    52,    53,     0,     0,     0,     0,     0,     0,     0,
      55,    54,    50,    51,     0,     0,     0,     0,     0,     0,
       3,     0,     4,     0,     6,    10,    19,    15,    16,    18,
      17,    20,     8,    13,    14,     0,     9,     0,    21,     0,
      24,    29,    11,    12,     0,     0,     0,    80,    72,     0,
      73,    59,    58,     0,     0,     5,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      56,    80,    48,    47,     0,    22,     0,     0,    30,     0,
       0,     0,     0,     0,     7,    81,     0,    84,    64,    65,
      68,    69,    71,    70,    66,    67,    60,    61,    62,    63,
       0,    49,     0,     0,    44,     0,     0,     0,     0,    45,
      83,     0,    23,    31,     0,    28,     0,    46,     0,    33,
      84,     0,     0,     0,     0,     0,     0,     0,    82,     3,
       0,    27,    32,     0,     0,     0,     0,    35,     0,    34,
       0,     0,     0,     0,     0,     0,    36,    10,    26,     0,
       0,     0,    37,    25,     0,     0,     0,    41,    42,    43,
      38,    39,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    32,    33,    34,    84,    35,    36,    37,
     124,    87,    38,    39,    40,    41,   148,   136,    42,    43,
      44,    45,    46,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -131
static const yytype_int16 yypact[] =
{
    -131,     5,   190,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
     -30,  -131,  -131,   -40,   190,   -32,    -8,    -7,   190,    79,
    -131,  -131,  -131,  -131,   -27,    64,    12,    64,    64,    64,
    -131,    64,  -131,    17,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,    67,    91,   241,    64,    64,
    -131,    24,  -131,  -131,    92,    83,    97,  -131,  -131,    64,
    -131,  -131,  -131,   139,   224,  -131,   -26,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,  -131,
    -131,    54,  -131,    91,    26,    91,   261,    61,  -131,   106,
      63,    89,    70,   282,  -131,  -131,    64,    24,    45,    45,
     -23,   -23,   342,   359,   -23,   -23,    21,    21,   -11,   -11,
      64,  -131,   190,    64,   102,    64,    64,    86,   190,    91,
      99,   110,    91,  -131,   116,   324,   303,    91,   141,   155,
      24,   118,    64,    64,   120,    19,   -15,   190,  -131,  -131,
     119,    91,  -131,   117,   121,   122,   124,  -131,   123,  -131,
     190,   190,   190,   190,   190,   190,  -131,   129,  -131,   159,
     165,   166,  -131,  -131,   136,   137,   138,   141,   141,   141,
    -131,  -131,  -131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,   -28,   -14,  -131,  -131,  -131,    38,  -131,  -131,
      59,  -131,  -131,  -131,  -131,  -131,  -131,  -130,   -37,  -131,
     168,   -18,   -19,    72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,    55,    63,    47,    54,     3,    58,    96,    60,    61,
      62,   146,    64,    49,    88,    75,    76,    77,    78,    79,
      80,    51,   143,    48,   144,   145,    56,    97,    83,    85,
      86,    79,    80,    89,    11,    12,   147,   170,   171,   172,
      93,    52,    53,    19,    20,    21,    22,    23,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     120,    77,    78,    79,    80,    59,    65,     4,     5,     6,
       7,     8,     9,    57,    69,    70,    66,   119,   110,    89,
     111,    73,    74,    75,    76,    77,    78,    79,    80,    11,
      12,   122,    91,   120,   125,    25,   126,   127,   123,    20,
      21,    22,    23,    27,   129,    90,    92,    48,    28,    29,
     113,   150,    89,   125,   141,   114,   115,    31,    67,    68,
      69,    70,   116,   149,   117,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    96,   128,   158,   159,   160,
     161,   162,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   130,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   131,   132,   135,   137,   139,   142,
      25,    26,   152,   151,   156,   164,   153,   154,    27,   155,
     163,   165,   166,    28,    29,   167,   168,   169,   157,    30,
      94,   140,    31,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   138,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    82,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,    28,    29,     0,     0,     0,     0,
      30,     0,     0,    31,     4,     5,     6,     7,     8,     9,
      81,    67,    68,    69,    70,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    95,     0,
      27,     0,     0,     0,     0,    28,    29,     0,    67,    68,
      69,    70,     0,     0,    31,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,    67,
      68,    69,    70,     0,     0,   112,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
      67,    68,    69,    70,     0,     0,   118,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,    67,    68,    69,    70,     0,     0,   134,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    67,
      68,    69,    70,     0,     0,     0,   133,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    67,    68,    69,    70,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      14,    19,    30,    33,    18,     0,    25,    33,    27,    28,
      29,    26,    31,    53,    51,    38,    39,    40,    41,    42,
      43,    53,     3,    53,     5,     6,    53,    53,    47,    48,
      49,    42,    43,    51,    10,    11,    51,   167,   168,   169,
      59,    49,    49,    19,    20,    21,    22,    23,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      97,    40,    41,    42,    43,    53,    49,     3,     4,     5,
       6,     7,     8,     9,    29,    30,     9,    96,    52,    97,
      54,    36,    37,    38,    39,    40,    41,    42,    43,    10,
      11,   110,     9,   130,   113,    31,   115,   116,   112,    20,
      21,    22,    23,    39,   118,    13,     9,    53,    44,    45,
      49,   139,   130,   132,   133,     9,    53,    53,    27,    28,
      29,    30,    33,   137,    54,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    33,    50,   151,   152,   153,
     154,   155,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    52,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    54,    49,    25,    12,    50,    49,
      31,    32,    55,    54,    51,    16,    55,    55,    39,    55,
      51,    16,    16,    44,    45,    49,    49,    49,   150,    50,
      51,   132,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   130,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    47,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,     3,     4,     5,     6,     7,     8,
       9,    27,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    27,    28,
      29,    30,    -1,    -1,    53,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    54,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    54,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    54,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    27,
      28,    29,    30,    -1,    -1,    -1,    52,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    31,    32,    39,    44,    45,
      50,    53,    59,    60,    61,    63,    64,    65,    68,    69,
      70,    71,    74,    75,    76,    77,    78,    33,    53,    53,
      59,    53,    49,    49,    59,    77,    53,     9,    78,    53,
      78,    78,    78,    58,    78,    49,     9,    27,    28,    29,
      30,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     9,    76,    78,    62,    78,    78,    67,    74,    77,
      13,     9,     9,    78,    51,    54,    33,    53,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      52,    54,    54,    49,     9,    53,    33,    54,    54,    78,
      74,    79,    78,    59,    66,    78,    78,    78,    50,    59,
      52,    54,    49,    52,    54,    25,    73,    12,    79,    50,
      66,    78,    49,     3,     5,     6,    26,    51,    72,    59,
      58,    54,    55,    55,    55,    55,    51,    63,    59,    59,
      59,    59,    59,    51,    16,    16,    16,    49,    49,    49,
      73,    73,    73
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
#line 72 "parser.y"
    {check_unused_variables();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {write_to_assembly((yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (2)].nodePtr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {(yyval.nodePtr)=create_operation(BLOCK,1,NULL);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {(yyval.nodePtr)=create_operation(BREAK,1,NULL);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {(yyval.nodePtr)=create_operation(CONTINUE,1,NULL);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval.nodePtr)=create_operation(RETURN,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {(yyval.nodePtr)=create_operation(FUNCTION,4,(yyvsp[(2) - (9)].sIndex),(yyvsp[(4) - (9)].nodePtr),(yyvsp[(7) - (9)].nodePtr),(yyvsp[(8) - (9)].nodePtr));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval.nodePtr)=create_operation(FOR,4,(yyvsp[(3) - (9)].nodePtr),(yyvsp[(5) - (9)].nodePtr),(yyvsp[(7) - (9)].nodePtr),(yyvsp[(9) - (9)].nodePtr));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.nodePtr)=create_operation(',',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {(yyval.nodePtr)=create_operation(';',2,NULL,NULL);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {(yyval.nodePtr)=create_operation(WHILE,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {(yyval.nodePtr)=create_operation(DO_WHILE,2,(yyvsp[(2) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,2,(yyvsp[(3) - (5)].nodePtr),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {(yyval.nodePtr)=create_operation(IF,3,(yyvsp[(3) - (7)].nodePtr),(yyvsp[(5) - (7)].nodePtr),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,2,create_identifier((yyvsp[(3) - (7)].sIndex)),(yyvsp[(6) - (7)].nodePtr));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {(yyval.nodePtr)=create_operation(SWITCH,2,create_identifier((yyvsp[(3) - (8)].sIndex)),(yyvsp[(6) - (8)].nodePtr),(yyvsp[(7) - (8)].nodePtr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval.nodePtr)=create_operation(DEFAULT,1,(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(INTEGER,INTEGER_TYPE,(yyvsp[(2) - (7)].intValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(CHARACTER,CHARACTER_TYPE,(yyvsp[(2) - (7)].stringValue)),(yyvsp[(4) - (7)].nodePtr),create_operation(BREAK,0),(yyvsp[(7) - (7)].nodePtr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(INTEGER,INTEGER_TYPE,(yyvsp[(2) - (6)].intValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {(yyval.nodePtr)=create_operation(CASE,3,create_constant(CHARACTER,CHARACTER_TYPE,(yyvsp[(2) - (6)].stringValue)),(yyvsp[(4) - (6)].nodePtr),create_operation(BREAK,0));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyval.nodePtr)=create_operation(DECLARATION,1,create_identifier((yyvsp[(2) - (2)].sIndex),(yyvsp[(1) - (2)].intValue),0));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(2) - (4)].sIndex),(yyvsp[(1) - (4)].intValue)),(yyvsp[(4) - (4)].nodePtr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(3) - (5)].sIndex),(yyvsp[(2) - (5)].intValue),CONST),(yyvsp[(5) - (5)].nodePtr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(1) - (3)].sIndex)),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.nodePtr)=create_operation('=',2,create_identifier((yyvsp[(1) - (3)].sIndex)),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {(yyval.nodePtr)=create_operation(CALL,2,create_identifier((yyvsp[(1) - (4)].sIndex)),(yyvsp[(3) - (4)].nodePtr));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {(yyval.intValue)=INT_TYPE;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {(yyval.intValue)=FLOAT_TYPE;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {(yyval.intValue)=CHAR_TYPE;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {(yyval.intValue)=VOID;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {(yyval.intValue)=BOOL_TYPE;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {(yyval.intValue)=STRING_TYPE;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_INC,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {(yyval.nodePtr)=create_operation(POST_DEC,1,(yyvsp[(1) - (2)].nodePtr));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_INC,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval.nodePtr)=create_operation(PRE_DEC,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.nodePtr)=create_operation('+',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.nodePtr)=create_operation('-',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {(yyval.nodePtr)=create_operation('*',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval.nodePtr)=create_operation('/',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {(yyval.nodePtr)=create_operation('==',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {(yyval.nodePtr)=create_operation('!=',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {(yyval.nodePtr)=create_operation('<',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {(yyval.nodePtr)=create_operation('>',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.nodePtr)=create_operation('<=',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {(yyval.nodePtr)=create_operation('>=',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {(yyval.nodePtr)=create_operation('&&',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval.nodePtr)=create_operation('||',2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {(yyval.nodePtr)=create_operation('!',1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {(yyval.nodePtr)=create_operation(NEGATIVE,1,(yyvsp[(2) - (2)].nodePtr));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {(yyval.nodePtr)=create_constant(INTEGER,INTEGER_TYPE,(yyvsp[(1) - (1)].intValue));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {(yyval.nodePtr)=create_constant(FLOAT,FLOAT_TYPE,(yyvsp[(1) - (1)].floatValue));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,BOOL_TYPE,1);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {(yyval.nodePtr)=create_constant(BOOL,BOOL_TYPE,0);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {(yyval.nodePtr)=create_constant(STRING,STRING_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {(yyval.nodePtr)=create_constant(CHARACTER,CHARACTER_TYPE,(yyvsp[(1) - (1)].stringValue));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval.nodePtr)=create_identifier((yyvsp[(1) - (1)].sIndex));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(2) - (3)].nodePtr);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {(yyval.nodePtr)=create_operation(COMMA,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.nodePtr)=NULL;;}
    break;



/* Line 1455 of yacc.c  */
#line 2173 "parser.tab.c"
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
#line 223 "parser.y"

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
Node* create_constant(int type ,int dataType) {
    va_list ap;
    Node *p;
    size_t nodeSize;

    nodeSize = sizeof(Node) + sizeof(ConstantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = CONSTANT;
    p->con.dataType = dataType;
    va_start(ap, dataType);
    p->con.value = va_arg(ap, ValueType);
    va_end(ap);

    return p;
}

// Create identifier nodes
Node* create_identifier(char* i, int dataType, int qualifier) {
    Node *p;
    size_t nodeSize;
    nodeSize = sizeof(Node) + sizeof(IdentifierNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = IDENTIFIER;
    p->id.name = strdup(i);
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
    exit(1);
}

int main() {
    yyparse();
    return 0;
}
