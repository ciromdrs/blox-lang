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
"OR",
"PLUS",
"RBRACE",
"RBRACK",
"RPAREN",
"SEMICOLON",
"STRING",
"TIMES"
]

for tok in tokens[:-1]:
    print('"'+tok+'",', end=' ')
print('"'+tokens[-1]+'"')

for i, tok in enumerate (tokens):
    print("# define", tok, i+257)
