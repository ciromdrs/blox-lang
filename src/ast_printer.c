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
    switch(e->kind){
        case A_int_expression:
            printf("%d", e->value.int_literal); break;
        case A_bool_expression:
            printf("%d", e->value.bool_literal); break;
        case A_float_expression:
            printf("%f", e->value.float_literal); break;
        case A_string_expression:
            printf("%s", e->value.string_literal); break;
        case A_atom_expression:
            Print_Atom(e->value.atom); break;
        default:
            printf("Unrecognized expression: %p", e);
    };
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
