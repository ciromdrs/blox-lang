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
    A_int_literal, A_bool_literal, A_float_literal, A_string_literal
}
A_Literal_kind;

typedef struct {
    A_Pos pos;
    A_Literal_kind kind;
    union {
        /* nil; - needs only the pos */
        int intval;
        float floatval;
        char* stringval;
        int boolval;
    }
    value;
}
A_Literal;


typedef enum {
    A_id_atom, A_subscript_atom, A_call_atom
}
A_Atom_kind;

typedef char A_Id;

/*typedef struct {
    char* name;
    A_Expression index;
}
A_Subscript;

typedef struct {
    char* name;
    A_ParamList params;
}
A_Call;*/

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

typedef enum {
    A_literal_expression, A_atom_expression
}
A_Expression_kind;

typedef struct{
    A_Pos pos;
    A_Expression_kind kind;
    union {
        A_Literal* literal;
        A_Atom* atom;
    }
    value;
}
A_Expression;

/* Function Prototypes */
A_Expression* A_NewAtomExpression(A_Pos pos, A_Atom* a);
A_Expression* A_NewLiteralExpression(A_Pos pos, A_Literal* lit);
A_Atom* A_NewIdAtom(A_Pos, char* id);
A_Literal* A_NewIntLiteral(A_Pos pos, int i);
A_Literal* A_NewStringLiteral(A_Pos pos, char* s);
A_Literal* A_NewFloatLiteral(A_Pos pos, float f);
A_Literal* A_NewBoolLiteral(A_Pos pos, int b);
A_Block* A_NewBlock(A_Pos pos, void* ast_node);
