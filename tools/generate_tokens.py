tokens = ["AND",
"ARRAY",
"ASSIGN",
"BLOCK",
"BREAK",
"COLON",
"COMMA",
"CONTINUE",
"DIVIDE",
"DOT",
"ELSE",
"EQ",
"FLOAT",
"GE",
"GT",
"ID",
"IF",
"INT",
"LBRACE",
"LBRACK",
"LE",
"LOOP",
"LPAREN",
"LT",
"MINUS",
"NEQ",
"NIL",
"NOT",
"OR",
"PLUS",
"RBRACE",
"RBRACK",
"RETURN",
"RPAREN",
"SEMICOLON",
"STRING",
"TIMES"
]

tokens.sort()

for tok in tokens[:-1]:
    print('"'+tok+'",', end=' ')
print('"'+tokens[-1]+'"')

for i, tok in enumerate (tokens):
    print("# define", tok, i+257)
