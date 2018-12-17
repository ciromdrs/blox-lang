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

A_Exp* A_NewPlusExp(A_Pos pos, A_Exp* left, A_Exp* right){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->value.binop = checked_malloc(sizeof(*(p->value.binop)));
    p->kind=A_plus_exp;
    p->pos=pos;
    p->value.binop->left=left;
    p->value.binop->right=right;
    p->value.binop->operator=A_plus;
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

A_Exp* A_NewAtomExp(A_Pos pos, A_Atom* a){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->pos=pos;
    p->kind = A_atom_exp;
    p->value.atom=a;
    return p;
}

A_Exp* A_NewIntExp(A_Pos pos, int i){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->kind=A_int_exp;
    p->pos=pos;
    p->value.int_literal=i;
    return p;
}

A_Exp* A_NewStringExp(A_Pos pos, char* s){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->kind=A_string_exp;
    p->pos=pos;
    p->value.string_literal=s;
    return p;
}

A_Exp* A_NewFloatExp(A_Pos pos, float f){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->kind=A_float_exp;
    p->pos=pos;
    p->value.float_literal=f;
    return p;
}

A_Exp* A_NewBoolExp(A_Pos pos, int b){
    A_Exp* p = checked_malloc(sizeof(*p));
    p->kind=A_bool_exp;
    p->pos=pos;
    p->value.bool_literal=b;
    return p;
}

