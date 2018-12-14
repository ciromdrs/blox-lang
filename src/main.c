#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include <string.h>
// #include "symbol.h"
#include "absyn.h"
#include "y.tab.h"

extern int yyparse(void);
int yylex(void);
extern A_Block* absyn_root;

void tokenize(char* fname);
A_Block* parse(char* fname);
void parse_test(char* fname);
void print_Block(A_Block* b);
void print_Expression(A_Expression* e);
void print_LiteralExpression(A_LiteralExpression* l);
void print_Literal(A_Literal* l);


int main(int argc, char **argv) {
    if ((argc > 3) || (argc < 2)) {fprintf(stderr,"usage: blox [-test|-tok] filename\n"); exit(1);}
        if ((argc == 3) && (strcmp(argv[1],"-test")==0)) {
            parse_test(argv[2]);
        } else if ((argc == 3) && (strcmp(argv[1],"-tok")==0)) {
            tokenize(argv[2]);
        } else {
            parse(argv[1]);
            print_Block(absyn_root);
        }
    return 0;
}

/* parse source file fname; 
   return abstract syntax data structure */
A_Block* parse(char* fname){
    EM_reset(fname);
    if (yyparse() == 0) /* parsing worked */
        return absyn_root;
    else return NULL;
}

void tokenize(char* fname){
    // NOT WORKING!
    int tok;
    EM_reset(fname);
    for(;;) {
        tok=yylex();
        if (tok==0) break;
        printf("%d %d\n",tok,EM_tokPos);
    }
}

void parse_test(char* fname) {
    EM_reset(fname);
    if (yyparse() == 0) /* parsing worked */
        fprintf(stderr,"Parsing successful!\n");
    else fprintf(stderr,"Parsing failed\n");
}

void print_Block(A_Block* b){
    printf("{\n");
    printf("type: A_Block, \n");
    printf("value: ");
    print_Expression((A_Expression*) b->value);
    printf("\n}");
}

void print_Expression(A_Expression* e){
    printf("{\n");
    printf("type: A_Expression, \n");
    printf("kind: %d,\n",e->kind);
    printf("value: ");
    if (e->kind == A_literal_expression) {
        print_LiteralExpression(e->value.literal_expression); 
    } else
        printf("Unrecognized expression: %p", e);
    printf("\n}");
}

void print_LiteralExpression(A_LiteralExpression* e){
    printf("{\n");
    printf("type: A_LiteralExpression, \n");
    printf("value: ");
    print_Literal(e->literal); 
    printf("\n}");
}

void print_Literal(A_Literal* l){
    printf("{\n");
    printf("type: A_Literal, \n");
    if (l->kind == A_int_literal) {
        printf("kind: int,\n");
        printf("value: %d", l->value.intval);
    } else if (l->kind == A_string_literal) {
        printf("kind: string,\n");
        printf("value: %s", l->value.stringval);
    } else if (l->kind == A_float_literal) {
        printf("kind: float,\n");
        printf("value: %f", l->value.floatval);
    } else if (l->kind == A_bool_literal) {
        printf("kind: bool,\n");
        if (l->value.boolval == TRUE) 
            printf("value: true");
        else
            printf("value: false");
    } else
        printf("Unrecognized literal: %p", l);
    printf("\n}");
}

