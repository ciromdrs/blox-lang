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
    GE = 270,
    GT = 271,
    IF = 272,
    LBRACE = 273,
    LBRACK = 274,
    LE = 275,
    LOOP = 276,
    LPAREN = 277,
    LT = 278,
    MINUS = 279,
    NEQ = 280,
    NIL = 281,
    NOT = 282,
    OR = 283,
    PLUS = 284,
    RBRACE = 285,
    RBRACK = 286,
    RETURN = 287,
    RPAREN = 288,
    SEMICOLON = 289,
    TIMES = 290,
    FLOAT = 291,
    ID = 292,
    INT = 293,
    STRING = 294
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
#define GE 270
#define GT 271
#define IF 272
#define LBRACE 273
#define LBRACK 274
#define LE 275
#define LOOP 276
#define LPAREN 277
#define LT 278
#define MINUS 279
#define NEQ 280
#define NIL 281
#define NOT 282
#define OR 283
#define PLUS 284
#define RBRACE 285
#define RBRACK 286
#define RETURN 287
#define RPAREN 288
#define SEMICOLON 289
#define TIMES 290
#define FLOAT 291
#define ID 292
#define INT 293
#define STRING 294

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
