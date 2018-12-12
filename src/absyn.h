/*
 * absyn.h - Abstract Syntax Header (Chapter 4)
 *
 * All types and functions declared in this header file begin with "A_"
 * Linked list types end with "..list"
 */

/* Type Definitions */
typedef int A_pos;

typedef struct {
    A_pos pos;
    enum {A_intLiteral, A_stringLiteral} kind;
    union {
        /* nil; - needs only the pos */
        int intlit;
        char* stringlit;
    } value;
} A_literal;

// struct A_int {
    // A_pos pos;
    // int value;
// };

// struct A_char*{
    // A_pos pos;
    // char* value;
// };


typedef A_literal A_block;

/* Function Prototypes */
A_literal* A_IntLiteral(A_pos pos, int i);
A_literal* A_StringLiteral(A_pos pos, char* s);
// A_literal A_Literal(A_pos pos, char* s);
A_block* A_Block(A_pos pos, A_literal* lit);
