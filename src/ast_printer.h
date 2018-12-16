/*
 * ast_printer.h - Abstract Syntax Tree Printer
 *
 * All functions declared in this header file begin with "Print_"
 */

#include <stdio.h>
#include "absyn.h"

void Print_Atom(A_Atom* a);
void Print_Block(A_Block* b);
void Print_Expression(A_Expression* e);
void Print_Literal(A_Literal* l);
