/*
 * absyn.h - Abstract Syntax Header (Chapter 4)
 *
 * All types and functions declared in this header file begin with "A_"
 * Linked list types end with "..list"
 */

/* Type Definitions */
typedef int A_Pos;
typedef char A_Id;

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
        struct {
            A_Id* id;
            struct A_Exp_* params;
        }
        call;
    }
    value;
}
A_Atom;



typedef struct A_Stmt_ {
    A_Pos pos;
    enum {
        A_call_stmt
    }
    kind;
    struct A_Stmt_* next;
    union {
        A_Atom* call;
    }
    value;
}
A_Stmt;


typedef struct {
    struct A_Exp_* left;
    struct A_Exp_* right;
    enum {
        A_plus
    }
    operator;
}
A_BinOpExp;


typedef enum {
     A_atom_exp, A_bool_exp, A_float_exp, A_int_exp, A_plus_exp,
     A_string_exp
}
A_Exp_kind;

typedef struct A_Exp_ {
    A_Pos pos;
    A_Exp_kind kind;
    struct A_Exp_* next;
    union {
        /* nil; - needs only the pos */
        int int_literal;
        float float_literal;
        char* string_literal;
        int bool_literal;
        A_Atom* atom;
        A_BinOpExp* binop;
    }
    value;
}
A_Exp;


/* Function Prototypes */
A_Block* A_NewBlock(A_Pos pos, void* ast_node);

A_Stmt* A_NewCallStmt(A_Pos pos, A_Atom* call, A_Stmt* next);

A_Atom* A_NewIdAtom(A_Pos, char* id);
A_Atom* A_NewCallAtom(A_Pos, char* id, A_Exp* params);

A_Exp* A_NewAtomExp(A_Pos pos, A_Atom* a);
A_Exp* A_NewIntExp(A_Pos pos, int i);
A_Exp* A_NewStringExp(A_Pos pos, char* s);
A_Exp* A_NewFloatExp(A_Pos pos, float f);
A_Exp* A_NewBoolExp(A_Pos pos, int b);
A_Exp* A_NewPlusExp(A_Pos pos, A_Exp* left, A_Exp* right);
