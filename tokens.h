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
# define ELIF 268
# define ELSE 269
# define EQ 270
# define FLOAT 271
# define GE 272
# define GT 273
# define ID 274
# define IF 275
# define INT 276
# define LBRACE 277
# define LBRACK 278
# define LE 279
# define LOOP 280
# define LPAREN 281
# define LT 282
# define MINUS 283
# define NEQ 284
# define NIL 285
# define NOT 286
# define OR 287
# define PLUS 288
# define RBRACE 289
# define RBRACK 290
# define RETURN 291
# define RPAREN 292
# define SEMICOLON 293
# define STRING 294
# define TIMES 295
