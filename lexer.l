%{
    #include "parser.tab.h"
%}
%option yylineno  

DIGIT    [0-9]

LETTER  [a-zA-Z]
ID       [a-zA-Z_][a-zA-Z0-9_]*
WS       [ \t\n]
COMMENT  "//".*|"/"\*(.|\n)*?\*"/"


%%

{COMMENT}               {printf("Commend: { %s }\n", yytext);/*ignore further*/}
{DIGIT}+{LETTER}+       {fprintf(stderr, "Error at line %d: Invalid number '%s'\n", yylineno, yytext);}
{DIGIT}+                {printf("Integer: %s\n", yytext); return INTEGER;}
"++"                    {printf("PlusPLus: %s\n", yytext); return PLUSPLUS;}
"+"                     {printf("Plus: %s\n", yytext); return PLUS;}    
{ID}                    {printf("Identifier: %s\n", yytext); return INDETIFIER;}
{WS}+                   {/* Ignore whitespace*/}


%%
int yywrap() {
    return 1;
}
int main(int argc, char **argv) {
    while (yylex() != 0) {
        // Continue lexing until end of input
    }
    return 0;
}
