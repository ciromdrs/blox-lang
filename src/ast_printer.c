#include <stdio.h>
#include "ast_printer.h"
#include "util.h"

int tabc;
#define TAB "   "

void tabs(){
    int i;
    for (i = 0; i < tabc; i++) {
        printf(TAB);
    }
}

void open(){
    printf("{\n");
    tabc++;
}

void close(){
    printf("\n");
    tabc--;
    tabs();
    printf("}");
}

void Print_Block(A_Block* b){
    open();
    tabs(); printf("type: A_Block, \n");
    tabs(); printf("value: ");
    Print_Expression((A_Expression*) b->value);
    close();
}

void Print_BinOpExpression(A_BinOpExpression* e){
    open();
    tabs(); printf("operator: %d,\n", e->operator);
    tabs(); printf("left: "); Print_Expression(e->left);
    printf(",\n");
    tabs(); printf("right: "); Print_Expression(e->right);
    close();
}

void Print_Expression(A_Expression* e){
    open();
    tabs(); printf("type: A_Expression, \n");
    tabs(); printf("kind: %d,\n",e->kind);
    tabs(); printf("value: ");
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
        case A_plus_expression:
            Print_BinOpExpression(e->value.binop); break;
        default:
            printf("Unrecognized expression: %p", e);
    };
    close();
}

void Print_Atom(A_Atom* a){
    open();
    tabs(); printf("type: A_Atom, \n");
    tabs(); printf("kind: %d,\n", a->kind);
    if (a->kind == A_id_atom) {
        tabs(); printf("value: %s", a->value.id);
    } else {
        tabs(); printf("Unrecognized atom: %p", a);
    }
    close();
}
