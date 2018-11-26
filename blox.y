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

%token AND ASSIGN BLOCK BREAK COLON COMMA CONTINUE DIVIDE DOT ELIF ELSE
  EQ GE GT IF LBRACE LBRACK LE LOOP LPAREN LT MINUS NEQ NIL NOT OR PLUS
  RBRACE RBRACK RETURN RPAREN SEMICOLON TIMES
%token <fval> FLOAT
%token <sval> ID
%token <ival> INT
%token <sval> STRING
  
%start block

%%

block: defs_opt stmts

bracketed_block: LBRACK block RBRACK

bracketed_block_opt: bracketed_block
    | %empty

defs_opt: def defs_opt
    | %empty

colon_opt: COLON
    | %empty

def: BLOCK ID formal_params_opt return_type_opt bracketed_block_opt

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

formal_params: param more_formal_params

more_formal_params: COMMA formal_params
    | %empty

param: decl

stmt_block: LBRACK stmts RBRACK

stmts: stmt colon_opt stmts
    | %empty

stmt: func_call
    | assign
    | decl
    | if
    | loop
    | continue
    | break
    | return
    | stmt_block

return: RETURN exp

loop: LOOP decl_opt condition stmt
    | LOOP decl_opt stmt condition

continue: CONTINUE

break: BREAK

if: IF decl_opt condition stmt elif_opt

condition: LPAREN exp RPAREN

elif_opt: ELIF decl_opt condition stmt elif_opt
    | else_opt

else_opt: ELSE stmt
    | %empty

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
