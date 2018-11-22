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
real                {number}\.{number}
string              ("\'".*"\'")
alpha               [a-zA-Z]
id                  ({alpha}|_)({alpha}|{digit}|_)*
invalid_id          {digit}+({alpha}|_)+

%%
{ws}                {adjust(); continue;}
{comment}           {adjust(); continue;}
"\n"                {adjust(); EM_newline(); continue;}
"if"                {adjust(); return IF;}
"else"              {adjust(); return ELSE;}
"block"             {adjust(); return BLOCK;}
"loop"              {adjust(); return LOOP;}
"="                 {adjust(); return ASSIGN;}
";"                 {adjust(); return COLON;}
","                 {adjust(); return COMMA;}
"+"                 {adjust(); return PLUS;}
"-"                 {adjust(); return MINUS;}
"*"                 {adjust(); return TIMES;}
"/"                 {adjust(); return DIVIDE;}
"=="                {adjust(); return EQ;}
"!="                {adjust(); return NEQ;}
">"                 {adjust(); return GT;}
"<"                 {adjust(); return LT;}
">="                {adjust(); return GE;}
"<="                {adjust(); return LE;}
\{                  {adjust(); return LBRACK;}
\}                  {adjust(); return RBRACK;}
\(                  {adjust(); return LPAREN;}
\)                  {adjust(); return RPAREN;}
{number}            {adjust(); yylval.ival=atoi(yytext); return INT;}
{real}              {adjust(); yylval.ival=atof(yytext); return FLOAT;}
{string}            {adjust(); yylval.sval=String(yytext); return STRING;}
{id}                {adjust(); yylval.sval=String(yytext); return ID;}

