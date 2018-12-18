/*
 * Adapted from A. W. Appel. Modern Compiler Implementation in C (1997)
 * https://www.cs.princeton.edu/~appel/modern/c/
 *
 */
 

#include <assert.h>

typedef char *string;
typedef char bool;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {bool head; U_boolList tail;};
U_boolList U_BoolList(bool head, U_boolList tail);

