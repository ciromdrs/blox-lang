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
extern A_block* absyn_root;

void tokenize(char* fname);
A_block* parse(char* fname);
void parse_test(char* fname);
void print_block(A_block* b);


int main(int argc, char **argv) {
    if ((argc > 3) || (argc < 2)) {fprintf(stderr,"usage: blox [-test|-tok] filename\n"); exit(1);}
        if ((argc == 3) && (strcmp(argv[1],"-test")==0)) {
            parse_test(argv[2]);
        } else if ((argc == 3) && (strcmp(argv[1],"-tok")==0)) {
            tokenize(argv[2]);
        } else {
            parse(argv[1]);
            // printf("Parsing worked, returning %p\n",absyn_root);
            print_block(absyn_root);
        }
    return 0;
}

/* parse source file fname; 
   return abstract syntax data structure */
A_block* parse(char* fname){
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

void print_block(A_block* b){
    if (b->kind == A_intLiteral)
        printf("%d", b->value.intlit);
    else if (b->kind == A_stringLiteral)
        printf("%s", b->value.stringlit);
    else if (b->kind == A_floatLiteral)
        printf("%f", b->value.floatlit);
    else if (b->kind == A_boolLiteral) {
        if (b->value.boollit == TRUE) 
            printf("true");
        else
            printf("false");
    } else
        printf("Unrecognized: %p", b);
    printf("\n");
}
