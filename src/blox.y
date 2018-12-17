%{
#include <stdio.h>
#include "absyn.h"
#include "util.h"
#include "errormsg.h"

int yylex(void); /* function prototype */

A_Block* absyn_root = NULL;

void yyerror(char *s) {
    EM_error(EM_tokPos, "%s", s);
}
%}

%union {
    int           ival;
    string        sval;
    float         fval;
    A_Atom*       atom;
    A_Exp* exp;
    char*         id;
    A_Block*      program;
}

%define parse.error verbose

%token BLOCK BREAK COLON COMMA CONTINUE DOT IF ELSEIF LBRACE LBRACK LOOP
  RBRACE RBRACK RETURN SEMICOLON THIS ADDRESS IMPORT GOTO AS TRUE_TOK
  FALSE_TOK LPAREN RPAREN
  
  
%token <fval> FLOAT
%token <ival> INT
%token <sval> STRING

%token <id> ID

%nonassoc IFX
%nonassoc ELSIFX
%nonassoc ELSE

%right ASSIGN

%left DIVIDE TIMES

%left MINUS PLUS

%nonassoc EQ NEQ GE GT LE LT

%left NOT
%left AND
%left OR

%type <program> program
%type <exp> exp literal
%type <atom> atom
  
%start program

%%

program : exp {absyn_root = A_NewBlock(EM_tokPos, $1);} ;

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

stmt: ID LPAREN actual_params_opt RPAREN ;
    | assign
    | dec
    | if
    | loop
    | continue
    | break
    | return
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

assign: atom ASSIGN exp
      ;

actual_params_opt: exp more_actual_params_opt
                 | addressed_id more_actual_params_opt
                 | %empty
                 ;

addressed_id: ADDRESS ID ;

more_actual_params_opt: COMMA actual_params_opt | %empty ;

atom: ID trailer        {$$ = A_NewIdAtom(EM_tokPos, $1);} ;

trailer: LPAREN actual_params_opt RPAREN trailer
    | DOT ID trailer
    | LBRACE exp RBRACE trailer
    | %empty
    ;
    
exp: literal            {$$ = $1;}
   | atom               {$$ = A_NewAtomExp(EM_tokPos, $1);}
   | LPAREN exp RPAREN
   | exp PLUS   exp     {$$ = A_NewPlusExp(EM_tokPos,$1,$3);}
   | exp MINUS  exp
   | exp TIMES  exp
   | exp DIVIDE exp
   | exp EQ  exp
   | exp NEQ exp
   | exp GT  exp
   | exp GE  exp
   | exp LT  exp
   | exp LE  exp
   | exp AND exp
   | exp OR  exp
   | MINUS exp
   | NOT exp
   ;

literal: INT       {$$ = A_NewIntExp(EM_tokPos, $1); }
       | STRING    {$$ = A_NewStringExp(EM_tokPos, $1); }
       | FLOAT     {$$ = A_NewFloatExp(EM_tokPos, $1); }
       | TRUE_TOK  {$$ = A_NewBoolExp(EM_tokPos, TRUE);}
       | FALSE_TOK {$$ = A_NewBoolExp(EM_tokPos, FALSE);}
       ;


%%
