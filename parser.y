%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *s);
    extern int yylex();
    extern int yylineno;
%}

%token INTEGER IDENTIFIER

/* Define tokens for keywords (example subset) */
%token FLOAT CHAR VOID if else while return for break continue do

/* Define operator tokens */
%token EQ NEQ LTE GTE NOT

%right '='
%left '||'
%left '&&'
%left '<' '>' LTE GTE EQ NEQ
%left '+' '-'
%left '*' '/'   
%right NOT

%%

root:
    | program
    ;

program:
    | statement
    | program statement
    ;
statement:
    single_statement
    | compound_statement
    | '{' program '}'
    ;

single_statement:
    assignment_statement
    | declaration
    | expr
    | function
    | return_statement
    | break_statement
    | continue_statement
    ;
return_statement:
    return expr ';'
    ;
break_statement:
    break ';'
    ;
continue_statement:
    continue ';'
    ;

assignment_statement:
    IDENTIFIER '=' expr
    ;
    
    


function :
    IDENTIFIER '(' expr ')'
    ;


compound_statement:
    for_statement
    | while_statement
    | if_statement
    | do_while_statement
    ;

for_statement:
    for '(' declaration ';' expr ';' expr ')' statement
    ;
while_statement:
    while '(' expr ')' statement
    ;
do_while_statement:
    do statement while '(' expr ')' ';'
    ;
if_statement:
    if '(' expr ')' statement else statement
    ;


type:
    INTEGER
    | FLOAT
    | CHAR  
    | VOID
    ;



declaration:
    type IDENTIFIER
    | type IDENTIFIER '=' expr
    ;

expr:
    expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr EQ expr
    | expr NEQ expr
    | expr '<' expr
    | expr '>' expr
    | expr LTE expr
    | expr GTE expr
    | expr '&&' expr
    | expr '||' expr
    | NOT expr
    | INTEGER
    | IDENTIFIER
    | '(' expr ')'
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser Error at line %d: %s\n", yylineno, s);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}