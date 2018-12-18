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

void open_brace(){
    printf("[");
    tabc++;
}

void close_brace(){
    printf("\n");
    tabc--;
    tabs();
    printf("]");
}


void Print_Block(A_Block* b){
    open();
    tabs(); printf("type: A_Block, \n");
    tabs(); printf("value: ");
    Print_StmtList((A_Stmt*) b->value);
    close();
}


void Print_BinOpExp(A_BinOpExp* e){
    open();
    tabs(); printf("operator: %d,\n", e->operator);
    tabs(); printf("left: "); Print_Exp(e->left);
    printf(",\n");
    tabs(); printf("right: "); Print_Exp(e->right);
    close();
}

void Print_Exp(A_Exp* e){
    open();
    tabs(); printf("type: A_Exp, \n");
    tabs(); printf("kind: %d,\n",e->kind);
    tabs(); printf("value: ");
    switch(e->kind){
        case A_int_exp:
            printf("%d", e->value.int_literal); break;
        case A_bool_exp:
            printf("%d", e->value.bool_literal); break;
        case A_float_exp:
            printf("%f", e->value.float_literal); break;
        case A_string_exp:
            printf("%s", e->value.string_literal); break;
        case A_atom_exp:
            Print_Atom(e->value.atom); break;
        case A_plus_exp:
            Print_BinOpExp(e->value.binop); break;
        default:
            printf("Unrecognized expression: %p", e);
    };
    close();
}

void Print_ExpList(A_Exp* e){
    open_brace();
    while(e != NULL){
        Print_Exp(e);
        if (e->next != NULL) printf(",\n"); tabs();
        e = e->next;
    }
    close_brace();
}


void Print_CallAtom(A_Atom* p){
    open();
    tabs(); printf("id: %s,\n", p->value.call.id);
    tabs(); printf("params: "); Print_ExpList(p->value.call.params);
    close();
}

void Print_Atom(A_Atom* a){
    open();
    tabs(); printf("type: A_Atom, \n");
    tabs(); printf("kind: %d,\n", a->kind);
    tabs(); printf("value: ");
    switch (a->kind) {
        case A_id_atom:
            printf("%s", a->value.id); break;
        case A_call_atom:
            Print_CallAtom(a); break;
        default:
            printf("Unrecognized atom: %p", a);
    };
    close();
}


void Print_Stmt(A_Stmt* p){
    open();
    tabs(); printf("type: A_Stmt, \n");
    tabs(); printf("kind: %d,\n",p->kind);
    tabs(); printf("value: ");
    switch(p->kind){
        case A_call_stmt:
            Print_CallAtom(p->value.call); break;
        default:
            printf("Unrecognized stmt: %p", p);
    };
    close();
}

void Print_StmtList(A_Stmt* p){
    open_brace();
    while(p != NULL){
        Print_Stmt(p);
        if (p->next != NULL) printf(",\n"); tabs();
        p = p->next;
    }
    close_brace();
}
