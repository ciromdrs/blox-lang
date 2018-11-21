%{
#include <string.h>
#include "util.h"
#include <stdlib.h>
#include "tokens.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}

void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

ws                  [\t ]+
comment             #.*
ignore              ({ws}|{comment})
digit               [0-9]
number              {digit}+
string              ("\'".*"\'")
alpha               [a-zA-Z]
id                  ({alpha}|_)({alpha}|{digit}|_)*
invalid_id          {digit}+({alpha}|_)+

%%
{ws}                {adjust(); continue;}
"\n"                {adjust(); EM_newline(); continue;}
"block"             {adjust(); return BLOCK;}
\{                  {adjust(); return LBRACK;}
\}                  {adjust(); return RBRACK;}
\(                  {adjust(); return LPAREN;}
\)                  {adjust(); return RPAREN;}
{string}         {adjust(); yylval.sval=String(yytext); return STRING;}
{id}                {adjust(); yylval.sval=String(yytext); return ID;}

