/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include "util.h"
// #include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */
#include <stdio.h>

A_literal* A_IntLiteral(A_pos pos, int i){
    A_literal* p = checked_malloc(sizeof(*p));
    p->kind=A_intLiteral;
    p->pos=pos;
    p->value.intlit=i;
    return p;
}

A_literal* A_StringLiteral(A_pos pos, char* s){
    A_literal* p = checked_malloc(sizeof(*p));
    p->kind=A_stringLiteral;
    p->pos=pos;
    p->value.stringlit=s;
    return p;
}

A_literal* A_FloatLiteral(A_pos pos, float f){
    A_literal* p = checked_malloc(sizeof(*p));
    p->kind=A_floatLiteral;
    p->pos=pos;
    p->value.floatlit=f;
    return p;
}

A_literal* A_BoolLiteral(A_pos pos, int b){
    A_literal* p = checked_malloc(sizeof(*p));
    p->kind=A_boolLiteral;
    p->pos=pos;
    p->value.boollit=b;
    return p;
}

A_block* A_Block(A_pos pos, A_literal* lit){
    A_block* p = checked_malloc(sizeof(*p));
    p->kind=lit->kind;
    p->pos=pos;
    p->value = lit->value;
    return p;
}

