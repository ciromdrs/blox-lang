/*
 * Adapted from A. W. Appel. Modern Compiler Implementation in C (1997)
 * https://www.cs.princeton.edu/~appel/modern/c/
 *
 */
 
extern bool EM_anyErrors;

void EM_newline(void);

extern int EM_tokPos;

void EM_error(int, string,...);
void EM_impossible(string,...);
void EM_reset(string filename);
