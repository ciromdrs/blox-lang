#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include <string.h>
// #include "symbol.h"
// #include "absyn.h"
#include "parser.h"

extern int yyparse(void);
// extern A_exp absyn_root;

int main(int argc, char **argv) {
 if (argc!=3) {fprintf(stderr,"usage: a.out [OPTION] filename\n"); exit(1);}
     if (strcmp(argv[1],"test")==0) {
        parse_test(argv[2]);
     } //else {
        // parse(argv[2]);
     // }
 return 0;
}

/* parse source file fname; 
   return abstract syntax data structure */
// A_block parse(string fname) 
// {EM_reset(fname);
 // if (yyparse() == 0) /* parsing worked */
   // return absyn_root;
 // else return NULL;
// }

void parse_test(string fname) 
{EM_reset(fname);
 if (yyparse() == 0) /* parsing worked */
   fprintf(stderr,"Parsing successful!\n");
 else fprintf(stderr,"Parsing failed\n");
}
