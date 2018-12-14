#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include <string.h>
// #include "symbol.h"
#include "ast_printer.h"
#include "y.tab.h"

extern int yyparse(void);
int yylex(void);
extern A_Block* absyn_root;

void tokenize(char* fname);
A_Block* parse(char* fname);
void parse_test(char* fname);

int main(int argc, char **argv) {
    if ((argc > 3) || (argc < 2)) {fprintf(stderr,"usage: blox [-test|-tok] filename\n"); exit(1);}
        if ((argc == 3) && (strcmp(argv[1],"-test")==0)) {
            parse_test(argv[2]);
        } else if ((argc == 3) && (strcmp(argv[1],"-tok")==0)) {
            tokenize(argv[2]);
        } else {
            parse(argv[1]);
            Print_Block(absyn_root);
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

