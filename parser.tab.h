
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "parser.y"

    #include "compiler.h"  



/* Line 1676 of yacc.c  */
#line 46 "parser.tab.h"

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
     POST_DEC = 294,
     POST_INC = 295,
     PRE_DEC = 296,
     PRE_INC = 297,
     NEGATIVE = 298,
     LOWER_THAN_ELSE = 299,
     FUNC = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 24 "parser.y"

  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char* charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer



/* Line 1676 of yacc.c  */
#line 121 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


