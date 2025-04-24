%option case-insensitive
%{
    #include "parser.tab.h"
    #include <ctype.h>   
    
    int check_postfix=0;

    char* to_upper(char* text) {
        for (int i = 0; text[i] != '\0'; i++) {
            text[i] = toupper(text[i]);
        }
        return text;    
    }
%}
%option yylineno  

DIGIT    [0-9]

LETTER  [a-zA-Z]
ID       [a-zA-Z_][a-zA-Z0-9_]*
WS       [ \t\n]
COMMENT  "//".*|"/"\*(.|\n)*?\*"/"




%%

    /* Keywords */

"int"        { printf("\nKeyword: %s\n", yytext); return INT_TYPE; }
"return"     { printf("\nKeyword: %s\n", yytext); return RETURN; }
"and"        {printf("\nKeyword: %s\n", yytext); return AND;}
"bool"       {printf("\nKeyword: %s\n", yytext); return BOOL_TYPE;}
"break"      {printf("\nKeyword: %s\n", yytext); return BREAK;}
"char"       {printf("\nKeyword: %s\n", yytext); return CHAR_TYPE;}
"continue"   {printf("\nKeyword: %s\n", yytext); return CONTINUE;}
"do"         {printf("\nKeyword: %s\n", yytext); return DO;}
"else"       {printf("\nKeyword: %s\n", yytext); return ELSE;}
"float"      {printf("\nKeyword: %s\n", yytext); return FLOAT_TYPE;}
"for"        {printf("\nKeyword: %s\n", yytext); return FOR;}
"if"         {printf("\nKeyword: %s\n", yytext); return IF;}
"void"       { printf("\nKeyword: %s\n", yytext); return VOID; }
"while"      { printf("\nKeyword: %s\n", yytext); return WHILE; }
"or"         {printf("\nKeyword: %s\n", yytext); return OR;}
"const"      {printf("\nKeyword: %s\n", yytext); return CONST;}
"false"      {printf("\nKeyword: %s\n", yytext); return FALSE;}
"true"       {printf("\nKeyword: %s\n", yytext); return TRUE;}
"string"     {printf("\nKeyword: %s\n", yytext); return STRING_TYPE;}
"switch"     {printf("\nKeyword: %s\n", yytext); return SWITCH;}
"case"       {printf("\nKeyword: %s\n", yytext); return CASE;}
"default"    {printf("\nKeyword: %s\n", yytext); return DEFAULT;}   

    /************/
    /* Operators */
"++"      {printf("\nOperator: %s\n", yytext); if(check_postfix) {check_postfix=0; return POST_INC;} else return PRE_INC;}              
"--"      {printf("\nOperator: %s\n", yytext); if(check_postfix) {check_postfix=0; return POST_DEC;} else return PRE_DEC;}              
"<<="     |              
">>="     |              
"<=>"     |              
"<="      {printf("\nOperator: %s\n", yytext); return LTE;}
">="      {printf("\nOperator: %s\n", yytext); return GTE;}
"=="      {printf("\nOperator: %s\n", yytext); return EQ;}
"!="      {printf("\nOperator: %s\n", yytext); return NEQ;}
"<<"      |              
">>"      |              
"&&"      {printf("\nOperator: %s\n", yytext); return AND;}             
"||"      {printf("\nOperator: %s\n", yytext); return OR;}              
"+="      |              
"*="      |              
"/="      |              
"%="      |              
"&="      |              
"|="      |              
"^="      |              
"->*"     |              
"->"      |              
"::"      |              
".*"      |              
"sizeof"  |              
"new"     |              
"delete"  |              
"+"       |              
"-"       |              
"*"       |              
"/"       |              
"%"       {printf("\nOperator: %s\n", yytext); return MOD;}                    
"<"       {printf("\nOperator: %s\n", yytext); return '<';}              
">"       {printf("\nOperator: %s\n", yytext); return '>';}
"!"       {printf("\nOperator: %s\n", yytext); return NOT;}                    
"not"       {printf("\nOperator: %s\n", yytext); return NOT;}                    
"&"       |              
"|"       |              
"^"       |              
"~"       |              
"="       |              
"."       |              
","       |              
"?"       |              
":"       |              
"("       |              
")"       |              
"["       |              
"]"       |              
"{"       |              
"}"       |              
";"                     {printf("\nOperator: %s\n", yytext); return *yytext;}
    /************/

{COMMENT}                                       {printf("\nCommend: { %s }\n", yytext);/*ignore further*/}
{DIGIT}+{LETTER}+                               {fprintf(stderr, "\nError at line %d: Invalid number '%s'\n", yylineno, yytext);}
{DIGIT}+                                        {printf("\nInteger: %s\n", yytext); yylval.intValue = atoi(yytext);  return INTEGER;}
{DIGIT}+\.{DIGIT}+((e|E|e-|E-){DIGIT}+)?        {printf("\nFloat: %s\n", yytext); char * x = strdup(yytext);  yylval.floatValue = atof(x); return FLOAT;}
'.'                                      {printf("\nChar : %s\n", yytext); return CHARACTER;}
\"([^"\\]|\\.)*\"                               { printf("\nString: %s\n", yytext); yylval.stringValue = strdup(yytext); return STRING; }
'([^'\\]|\\.)*'                                 { printf("\nString: %s\n", yytext); yylval.stringValue = strdup(yytext); return STRING; }
{ID}                                            {printf("\nIdentifier: %s\n", yytext); check_postfix=1;  yylval.sIndex = strdup(yytext); return IDENTIFIER;}
{WS}+                                           {/* Ignore whitespace*/ check_postfix=0;}
.                                               {printf("\nUnknown character: %s\n", yytext); return *yytext;}

%%
int yywrap() {
    return 1;
}
