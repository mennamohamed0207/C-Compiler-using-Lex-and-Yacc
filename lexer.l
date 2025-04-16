%option case-insensitive
%{
    #include "parser.tab.h"
    #include <ctype.h>   
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

"int"        { printf("\nKeyword: %s\n", yytext); return INT; }
"return"     { printf("\nKeyword: %s\n", yytext); return RETURN; }
"and"        {printf("\nKeyword: %s\n", yytext); return AND;}
"bool"       {printf("\nKeyword: %s\n", yytext); return BOOL;}
"break"      {printf("\nKeyword: %s\n", yytext); return BREAK;}
"char"       {printf("\nKeyword: %s\n", yytext); return CHAR;}
"continue"   {printf("\nKeyword: %s\n", yytext); return CONTINUE;}
"do"         {printf("\nKeyword: %s\n", yytext); return DO;}
"else"       {printf("\nKeyword: %s\n", yytext); return ELSE;}
"float"      {printf("\nKeyword: %s\n", yytext); return FLOAT;}
"for"        {printf("\nKeyword: %s\n", yytext); return FOR;}
"if"         {printf("\nKeyword: %s\n", yytext); return IF;}
"void"       { printf("\nKeyword: %s\n", yytext); return VOID; }
"while"      { printf("\nKeyword: %s\n", yytext); return WHILE; }
"or"         {printf("\nKeyword: %s\n", yytext); return OR;}
"const"      {printf("\nKeyword: %s\n", yytext); return CONST;}
"false"      {printf("\nKeyword: %s\n", yytext); return FALSE;}
"true"       {printf("\nKeyword: %s\n", yytext); return TRUE;}
"and_eq"     |  
"bitand"     |  
"bitor"      |  
"case"       |  
"catch"      |  
"class"      |  
"compl"      |  
"default"    |  
"delete"     |  
"double"     |  
"enum"       |  
"friend"     |  
"goto"       |  
"long"       |  
"namespace"  |  
"new"        |   
"or_eq"      |  
"private"    |  
"protected"  |  
"public"     |  
"short"      |  
"signed"     |  
"sizeof"     |  
"static"     |  
"Specifies"  |  
"struct"     |  
"switch"     |  
"template"   |  
"this"       |  
"throw"      |  
"try"        |  
"typedef"    |  
"unsigned"   |  
"using"      |  
"virtual"    |  
"xor"        |  
"xor_eq"     |     
"cerr"       |   
"clog"       |   
"cin"        |   
"cout"       |   
"wcerr"      |   
"wclog"      |       
"wcin"       |       
"wcout"      |                  
"filebuf"    |               
"fstream"    |               
"ifstream"   |           
"ofstream"   |               
"abs"        |           
"acos"       |           
"acosh"      |           
"asin"       |      
"asinh"      |      
"atan"       |        
"atan2"      |      
"atanh"      |        
"cbrt"       |      
"ceil"       |       
"copysign"   |      
"cos"        |       
"cosh"       |      
"exp"        |               
"exp2"       |       
"expm1"      |       
"erf"        |       
"erfc"       |       
"fabs"       |       
"fdim"       |           
"floor"      |           
"fma"        |           
"fmax"       |           
"fmin"       |           
"fmod"       |           
"frexp"      |           
"hypot"      |           
"ilogb"      |       
"ldexp"      |       
"lgamma"     |           
"llrint"     |       
"llround"    |       
"log"        |
"log10"      |           
"log1p"      |       
"log2"       |       
"logb"       |               
"lrint"      |       
"lround"     |               
"modf"       |
"nan"        |                       
"nearbyint"  |               
"nextafter"  |               
"nexttoward" |               
"pow"        |               
"remainder"  |               
"remquo"     |           
"rint"       |           
"round"      |           
"scalbln"    |           
"scalbn"     |       
"sin"        |                       
"sinh"       |               
"sqrt"       |           
"tan"        |               
"tanh"       |       
"tgamma"     |           
"trunc"      {yytext = to_upper(yytext);printf("\nKeyword: %s\n", yytext);return *yytext;}   

    /************/
    /* Operators */
"++"      |              
"--"      |              
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
"%"       |              
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
{DIGIT}+                                        {printf("\nInteger: %s\n", yytext); return INTEGER;}
{DIGIT}+\.{DIGIT}+((e|E|e-|E-){DIGIT}+)?        {printf("\nFloat: %s\n", yytext); return FLOAT;}
'.'                                      {printf("\nChar : %s\n", yytext);return CHARACTER;}
\"([^"\\]|\\.)*\"                               { printf("\nString: %s\n", yytext); return STRING; }
'([^'\\]|\\.)*'                                 { printf("\nString: %s\n", yytext); return STRING; }
{ID}                                            {printf("\nIdentifier: %s\n", yytext); return IDENTIFIER;}
{WS}+                                           {/* Ignore whitespace*/}
.                                               {printf("\nUnknown character: %s\n", yytext); return *yytext;}

%%
int yywrap() {
    return 1;
}

int main(int argc, char** argv) {
    while (yylex()) {
        if (yytext[0] == '\0') {
            break; // End of input
        }
    }
    return 0;
}