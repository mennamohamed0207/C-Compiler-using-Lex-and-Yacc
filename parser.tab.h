
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

/* Line 1676 of yacc.c  */
#line 21 "parser.y"

  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char* charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer



/* Line 1676 of yacc.c  */
#line 106 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


