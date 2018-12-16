#include <stdio.h>
#include "ast_printer.h"
#include "util.h"

void Print_Block(A_Block* b){
    printf("{\n");
    printf("type: A_Block, \n");
    printf("value: ");
    Print_Expression((A_Expression*) b->value);
    printf("\n}");
}

void Print_Expression(A_Expression* e){
    printf("{\n");
    printf("type: A_Expression, \n");
    printf("kind: %d,\n",e->kind);
    printf("value: ");
    if (e->kind == A_literal_expression) {
        Print_Literal(e->value.literal);
    } else if (e->kind == A_atom_expression) {
        Print_Atom(e->value.atom);
    } else {
        printf("Unrecognized expression: %p", e);
    }
    printf("\n}");
}

void Print_Atom(A_Atom* a){
    printf("{\n");
    printf("type: A_Atom, \n");
    printf("kind: %d,\n", a->kind);
    if (a->kind == A_id_atom) {
        printf("value: %s", a->value.id);
    } else {
        printf("Unrecognized atom: %p", a);
    }
    printf("\n}");
}

void Print_Literal(A_Literal* l){
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
