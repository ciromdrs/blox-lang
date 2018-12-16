/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include "util.h"
// #include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */
#include <stdio.h>


A_Block* A_NewBlock(A_Pos pos, void* ast_node){
    A_Block* p = checked_malloc(sizeof(*p));
    p->value = ast_node;
    p->pos=pos;
    return p;
}

A_Atom* A_NewIdAtom(A_Pos pos, char* id){//, A_Atom* next){
    A_Atom* p = checked_malloc(sizeof(*p));
    p->value.id = id;
    p->next = NULL;
    p->pos=pos;
    p->kind = A_id_atom;
    return p;
}

A_Expression* A_NewAtomExpression(A_Pos pos, A_Atom* a){
    A_Expression* p = checked_malloc(sizeof(*p));
    p->pos=pos;
    p->kind = A_atom_expression;
    p->value.atom=a;
    return p;
}

A_Expression* A_NewLiteralExpression(A_Pos pos, A_Literal* lit){
    A_Expression* p = checked_malloc(sizeof(*p));
    p->pos=pos;
    p->kind = A_literal_expression;
    p->value.literal=lit;
    return p;
}

A_Literal* A_NewIntLiteral(A_Pos pos, int i){
    A_Literal* p = checked_malloc(sizeof(*p));
    p->kind=A_int_literal;
    p->pos=pos;
    p->value.intval=i;
    return p;
}

A_Literal* A_NewStringLiteral(A_Pos pos, char* s){
    A_Literal* p = checked_malloc(sizeof(*p));
    p->kind=A_string_literal;
    p->pos=pos;
    p->value.stringval=s;
    return p;
}

A_Literal* A_NewFloatLiteral(A_Pos pos, float f){
    A_Literal* p = checked_malloc(sizeof(*p));
    p->kind=A_float_literal;
    p->pos=pos;
    p->value.floatval=f;
    return p;
}

A_Literal* A_NewBoolLiteral(A_Pos pos, int b){
    A_Literal* p = checked_malloc(sizeof(*p));
    p->kind=A_bool_literal;
    p->pos=pos;
    p->value.boolval=b;
    return p;
}

