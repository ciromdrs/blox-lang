typedef union  {
	int pos;
	int ival;
	string sval;
    float fval;
	} YYSTYPE;
extern YYSTYPE yylval;

//  258 <= tok <= 299
# define AND 258
# define ARRAY 259
# define ASSIGN 260
# define BLOCK 261
# define BREAK 262
# define COLON 263
# define COMMA 264
# define CONTINUE 265
# define DIVIDE 266
# define DOT 267
# define ELSE 268
# define EQ 269
# define FLOAT 270
# define GE 271
# define GT 272
# define ID 273
# define IF 274
# define INT 275
# define LBRACE 276
# define LBRACK 277
# define LE 278
# define LOOP 279
# define LPAREN 280
# define LT 281
# define MINUS 282
# define NEQ 283
# define NIL 284
# define NOT 285
# define OR 286
# define PLUS 287
# define RBRACE 288
# define RBRACK 289
# define RETURN 290
# define RPAREN 291
# define SEMICOLON 292
# define STRING 293
# define TIMES 294
