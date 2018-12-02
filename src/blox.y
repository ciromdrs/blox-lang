%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

int yylex(void); /* function prototype */

//A_block absyn_root;

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
  LPAREN NEQ RBRACE RBRACK RETURN RPAREN SEMICOLON THIS ADDRESS IMPORT
  GOTO AS
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
     ;
                    
bracketed_block: LBRACK block RBRACK
               ;

defs_opt: defs_opt def
        | %empty
        ;

colon_opt: COLON
         | %empty
         ;

def: BLOCK ID block_header
   | IMPORT identifier
   | IMPORT STRING
   ;

identifier: ID id_chain
          ;

id_chain: DOT identifier id_chain
        | %empty
        ;

lhs: ID lhs2
   ;
lhs2: DOT identifier lhs2
    | LBRACE exp RBRACE lhs2
    | DOT call lhs2
    | %empty
    ;

block_header: formal_params_opt return_type_opt block_body_opt
            ;
            
block_body_opt: bracketed_block
              | dec_init
              | %empty
              ;

return_type_opt: return_type
               | %empty
               ;

return_type: type  ;

dec: ID type dec_init_opt ;

type: ID ;

dec_opt: dec
        | %empty
        ;

dec_init_opt: dec_init
             | %empty
             ;

dec_init: ASSIGN exp ;

formal_params_opt: LPAREN formal_params RPAREN
                 | %empty
                 ;

formal_params: more_formal_params param ;

more_formal_params: formal_params COMMA 
                  | %empty
                  ;

param: dec
     ;

stmt_block: LBRACK stmts RBRACK ;

stmts: stmts colon_opt stmt
     | %empty
     ;

stmt: call
    | assign
    | dec
    | if
    | loop
    | continue
    | break
    | return
    | stmt_block
    ;

return: RETURN exp ;

loop: LOOP dec_opt condition stmt_block
    | LOOP dec_opt stmt_block condition
    ;

continue: CONTINUE ;

break: BREAK ;

if: IF dec_opt condition stmt_block %prec IFX
  | IF dec_opt condition stmt_block elseif
  ;

elseif: ELSEIF dec_opt condition stmt_block %prec ELSIFX
      | ELSEIF dec_opt condition stmt_block else
      ;

else: ELSE stmt_block ;

condition: LPAREN exp RPAREN ;

assign: lhs ASSIGN exp
      ;

call: ID LPAREN actual_params_opt RPAREN ;

actual_params_opt: exp more_actual_params_opt
                 | address more_actual_params_opt
                 | %empty
                 ;

address: ADDRESS ID ;

more_actual_params_opt: COMMA actual_params_opt
                      | %empty
                      ;

exp: literal
   | ID
   | LPAREN exp RPAREN
   | exp binop exp
   | unop exp
   | call
   ;

binop: PLUS | MINUS | TIMES | DIVIDE | EQ | NEQ | GT | GE | LT | LE | AND | OR ;

unop: MINUS | NOT ;

literal: STRING
       | INT
       | FLOAT
       ;
