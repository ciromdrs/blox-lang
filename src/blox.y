%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

int yylex(void); /* function prototype */

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}

%union {
	int pos;
	int ival;
    double fval;
	string sval;
	}

%define parse.error verbose

%token BLOCK BREAK COLON COMMA CONTINUE DOT IF ELSEIF LBRACE LBRACK LOOP
  LPAREN NEQ RBRACE RBRACK RETURN RPAREN SEMICOLON SELF
%token <fval> FLOAT
%token <sval> ID
%token <ival> INT
%token <sval> STRING
%nonassoc IFX
%nonassoc ELSIFX
%nonassoc ELSE
%left ASSIGN
%left MINUS PLUS
%left DIVIDE TIMES
%left EQ GE GT LE LT
%left NOT AND OR

  
%start block

%%

block: defs_opt stmts

bracketed_block: LBRACK block RBRACK

defs_opt: defs_opt def
        | %empty

colon_opt: COLON
         | %empty

def: BLOCK ID formal_params_opt return_type_opt bracketed_block

return_type_opt: return_type
               | %empty

return_type: type 

decl: ID type decl_init_opt

type: ID

decl_opt: decl
        | %empty

decl_init_opt: decl_init
             | %empty

decl_init: ASSIGN exp

formal_params_opt: LPAREN formal_params RPAREN
                 | %empty

formal_params: more_formal_params param

more_formal_params: formal_params COMMA
                  | %empty

param: decl

stmt_block: LBRACK stmts RBRACK

stmts: stmts colon_opt stmt
     | %empty

stmt: func_call
    | assign
    | decl
    | if
    | loop
    | continue
    | break
    | return

return: RETURN exp

loop: LOOP decl_opt condition stmt_block
    | LOOP decl_opt stmt_block condition

continue: CONTINUE

break: BREAK

if: IF decl_opt condition stmt_block %prec IFX
  | IF decl_opt condition stmt_block elseif

elseif: ELSEIF decl_opt condition stmt_block %prec ELSIFX
      | ELSEIF decl_opt condition stmt_block else

else: ELSE stmt_block

condition: LPAREN exp RPAREN

assign: ID ASSIGN exp

func_call: ID LPAREN actual_params RPAREN

actual_params: exps

exps: exp more_exps
    | %empty

more_exps: COMMA exps
         | %empty

exp: literal
   | ID
   | LPAREN exp RPAREN
   | exp binop exp
   | unop exp
   | func_call

binop: PLUS | MINUS | TIMES | DIVIDE | EQ | NEQ | GT | GE | LT | LE | AND | OR

unop: MINUS | NOT

literal: STRING
       | INT
       | FLOAT
