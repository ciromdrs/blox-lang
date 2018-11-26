/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ASSIGN = 259,
    BLOCK = 260,
    BREAK = 261,
    COLON = 262,
    COMMA = 263,
    CONTINUE = 264,
    DIVIDE = 265,
    DOT = 266,
    ELIF = 267,
    ELSE = 268,
    EQ = 269,
    FLOAT = 270,
    GE = 271,
    GT = 272,
    ID = 273,
    IF = 274,
    INT = 275,
    LBRACE = 276,
    LBRACK = 277,
    LE = 278,
    LOOP = 279,
    LPAREN = 280,
    LT = 281,
    MINUS = 282,
    NEQ = 283,
    NIL = 284,
    NOT = 285,
    OR = 286,
    PLUS = 287,
    RBRACE = 288,
    RBRACK = 289,
    RETURN = 290,
    RPAREN = 291,
    SEMICOLON = 292,
    STRING = 293,
    TIMES = 294
  };
#endif
/* Tokens.  */
#define AND 258
#define ASSIGN 259
#define BLOCK 260
#define BREAK 261
#define COLON 262
#define COMMA 263
#define CONTINUE 264
#define DIVIDE 265
#define DOT 266
#define ELIF 267
#define ELSE 268
#define EQ 269
#define FLOAT 270
#define GE 271
#define GT 272
#define ID 273
#define IF 274
#define INT 275
#define LBRACE 276
#define LBRACK 277
#define LE 278
#define LOOP 279
#define LPAREN 280
#define LT 281
#define MINUS 282
#define NEQ 283
#define NIL 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RBRACK 289
#define RETURN 290
#define RPAREN 291
#define SEMICOLON 292
#define STRING 293
#define TIMES 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "blox.y" /* yacc.c:1909  */

	int pos;
	int ival;
    double fval;
	string sval;
	

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
