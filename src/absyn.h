/*
 * absyn.h - Abstract Syntax Header (Chapter 4)
 *
 * All types and functions declared in this header file begin with "A_"
 * Linked list types end with "..list"
 */

/* Type Definitions */
typedef int A_Pos;

typedef struct{
    A_Pos pos;
    void* value;
}
A_Block;


typedef enum {
    A_id_atom, A_subscript_atom, A_call_atom
}
A_Atom_kind;


typedef struct A_Atom_ {
    A_Pos pos;
    A_Atom_kind kind;
    struct A_Atom_* next;
    union {
        char* id;
        //subscript;
        //call;
    }
    value;
}
A_Atom;


typedef struct {
    struct A_Expression_* left;
    struct A_Expression_* right;
    enum {
        A_plus
    }
    operator;
}
A_BinOpExpression;


typedef enum {
     A_atom_expression, A_bool_expression, A_float_expression, 
     A_int_expression, A_plus_expression, A_string_expression
}
A_Expression_kind;

typedef struct A_Expression_ {
    A_Pos pos;
    A_Expression_kind kind;
    union {
        /* nil; - needs only the pos */
        int int_literal;
        float float_literal;
        char* string_literal;
        int bool_literal;
        A_Atom* atom;
        A_BinOpExpression* binop;
    }
    value;
}
A_Expression;



/* Function Prototypes */
A_Expression* A_NewAtomExpression(A_Pos pos, A_Atom* a);
A_Atom* A_NewIdAtom(A_Pos, char* id);
A_Expression* A_NewIntExpression(A_Pos pos, int i);
A_Expression* A_NewStringExpression(A_Pos pos, char* s);
A_Expression* A_NewFloatExpression(A_Pos pos, float f);
A_Expression* A_NewBoolExpression(A_Pos pos, int b);
A_Expression* A_NewPlusExpression(A_Pos pos, A_Expression* left, A_Expression* right);
A_Block* A_NewBlock(A_Pos pos, void* ast_node);
