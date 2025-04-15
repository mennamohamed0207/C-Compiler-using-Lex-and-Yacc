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

"and"        |  
"and_eq"     |  
"bitand"     |  
"bitor"      |  
"bool"       |  
"break"      |  
"case"       |  
"catch"      |  
"char"       |  
"class"      |  
"compl"      |  
"const"      |  
"continue"   |  
"default"    |  
"delete"     |  
"do"         |  
"double"     |  
"else"       |  
"enum"       |  
"false"      |  
"float"      |  
"for"        |  
"friend"     |  
"goto"       |  
"if"         |  
"int"        |  
"long"       |  
"namespace"  |  
"new"        |  
"not"        |  
"not_eq"     |  
"or"         |  
"or_eq"      |  
"private"    |  
"protected"  |  
"public"     |  
"return"     |  
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
"true"       |  
"try"        |  
"typedef"    |  
"unsigned"   |  
"using"      |  
"virtual"    |  
"void"       |  
"while"      |  
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
"<="      |              
">="      |              
"=="      |              
"!="      |              
"<<"      |              
">>"      |              
"&&"      |              
"||"      |              
"+="      |              
"-="      |              
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
"<"       |              
">"       |              
"!"       |              
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

{COMMENT}               {printf("\nCommend: { %s }\n", yytext);/*ignore further*/}
{DIGIT}+{LETTER}+       {fprintf(stderr, "\nError at line %d: Invalid number '%s'\n", yylineno, yytext);}
{DIGIT}+                {printf("\nInteger: %s\n", yytext); return INTEGER;}
{ID}                    {printf("\nIdentifier: %s\n", yytext); return IDENTIFIER;}
{WS}+                   {/* Ignore whitespace*/}
.                       {printf("\nUnknown character: %s\n", yytext); return *yytext;}

%%
int yywrap() {
    return 1;
}