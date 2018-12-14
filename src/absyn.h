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


typedef struct {
    A_Pos pos;
    A_Literal* literal;
}
A_LiteralExpression;


typedef enum {
    A_literal_expression
} A_Expression_kind;

typedef struct{
    A_Pos pos;
    A_Expression_kind kind;
    union {
        A_LiteralExpression* literal_expression;
    }
    value;
}
A_Expression;

/* Function Prototypes */
A_Expression* A_NewExpression(A_Pos pos, A_Expression_kind kind, void* exp);
A_LiteralExpression* A_NewLiteralExpression(A_Pos pos, A_Literal* lit);
A_Literal* A_NewIntLiteral(A_Pos pos, int i);
A_Literal* A_NewStringLiteral(A_Pos pos, char* s);
A_Literal* A_NewFloatLiteral(A_Pos pos, float f);
A_Literal* A_NewBoolLiteral(A_Pos pos, int b);
A_Block* A_NewBlock(A_Pos pos, void* ast_node);
