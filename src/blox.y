%{
#include <stdio.h>
#include "absyn.h"
#include "util.h"
#include "errormsg.h"

int yylex(void); /* function prototype */

A_block* absyn_root = NULL;

void yyerror(char *s) {
    EM_error(EM_tokPos, "%s", s);
}
%}

%union {
    int         ival;
    string      sval;
    float       fval;
    A_block*    program;
    A_literal*  literal;
}

%define parse.error verbose

%token BLOCK BREAK COLON COMMA CONTINUE DOT IF ELSEIF LBRACE LBRACK LOOP
  LPAREN NEQ RBRACE RBRACK RETURN RPAREN SEMICOLON THIS ADDRESS IMPORT
  GOTO AS TRUE_TOK FALSE_TOK
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

%type <literal> literal
%type <program> program

  
%start program

%%

program : block {/*absyn_root = A_Block(EM_tokPos, $1);*/} ;

block: defs_opt stmts
     ;
                    
defs_opt: defs_opt def
        | %empty
        ;

def: BLOCK ID block_header
   ;

block_header: formal_params_opt return_type_opt block_body_opt
            ;

formal_params_opt: LPAREN formal_params RPAREN
                 | %empty
                 ;

formal_params: param COMMA formal_params
             | param
             ;

param: dec
     ;

return_type_opt: return_type
               | %empty
               ;

return_type: type ;

block_body_opt: LBRACK block RBRACK
              | %empty
              ;

type: ID braces ;

braces : LBRACE RBRACE braces
       | %empty
       ;

dec: ID type dec_init_opt ;

dec_opt: dec | %empty ;

dec_init_opt: ASSIGN exp | %empty ;

stmt_block: LBRACK stmts RBRACK ;

stmts: stmts stmt
     | %empty
     ;

stmt: func_call
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

func_call: lhs call
         ;

lhs: ID
   | ID DOT ID
   | ID array_access
   ;

call: LPAREN actual_params_opt RPAREN ;

array_access: LBRACE exp RBRACE ;

actual_params_opt: exp more_actual_params_opt
                 | addressed_id more_actual_params_opt
                 | %empty
                 ;

addressed_id: ADDRESS ID ;

more_actual_params_opt: COMMA actual_params_opt
                      | %empty
                      ;

exp: literal
   | lhs
   | func_call
   | LPAREN exp RPAREN
   | exp binop exp
   | unop exp
   ;

binop: PLUS | MINUS | TIMES | DIVIDE | EQ | NEQ | GT | GE | LT | LE
     | AND | OR
     ;

unop: MINUS | NOT ;

literal: INT       {$$ = A_IntLiteral(EM_tokPos, $1); }
       | STRING    {$$ = A_StringLiteral(EM_tokPos, $1); }
       | FLOAT     {$$ = A_FloatLiteral(EM_tokPos, $1); }
       | TRUE_TOK  {$$ = A_BoolLiteral(EM_tokPos, TRUE);}
       | FALSE_TOK {$$ = A_BoolLiteral(EM_tokPos, FALSE);}
       ;


%%
