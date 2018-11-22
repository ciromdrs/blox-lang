typedef union  {
	int pos;
	int ival;
	string sval;
    float fval;
	} YYSTYPE;
extern YYSTYPE yylval;

//  257 <= tok <= 299
# define AND 257
# define ARRAY 258
# define ASSIGN 259
# define BLOCK 260
# define BREAK 261
# define COLON 262
# define COMMA 263
# define CONTINUE 264
# define DIVIDE 265
# define DOT 266
# define ELSE 267
# define EQ 268
# define FLOAT 269
# define GE 270
# define GT 271
# define ID 272
# define IF 273
# define INT 274
# define LBRACE 275
# define LBRACK 276
# define LE 277
# define LOOP 278
# define LPAREN 279
# define LT 280
# define MINUS 281
# define NEQ 282
# define NIL 283
# define NOT 284
# define OR 285
# define PLUS 286
# define RBRACE 287
# define RBRACK 288
# define RETURN 289
# define RPAREN 290
# define SEMICOLON 291
# define STRING 292
# define TIMES 293
