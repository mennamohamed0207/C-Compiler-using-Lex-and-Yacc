%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *s);
    extern int yylex();
    extern int yylineno;
%}

%token INTEGER IDENTIFIER

/* Tokens */
%token FLOAT CHAR VOID ELSE WHILE RETURN FOR BREAK CONTINUE DO INT BOOL CONST TRUE FALSE STRING_TYPE
%token SWITCH CASE DEFAULT
%token EQ NEQ LTE GTE NOT IF STRING CHARACTER

/* Precedence (lowest to highest) */
%right '='
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LTE GTE
%left '+' '-'
%left '*' '/'
%right NOT
%nonassoc LOWER_THAN_ELSE  /* For dangling-else resolution */
%nonassoc ELSE

%%

root:
    program
    ;

program:
    | program statement
    ;

statement:
    single_statement ';'
    | compound_statement
    | '{' program '}'
    ;

single_statement:
    declaration
    | expr
    | RETURN expr
    | break_statement
    | continue_statement
    ;
break_statement:
    BREAK 
    ;
continue_statement:
    CONTINUE 
    ;


params:
    /* empty */
    | expr
    | params ',' expr
    ;

compound_statement:
    for_statement
    | while_statement
    | if_statement
    | do_while_statement
    | function_definition
    | switch_statement
    ;

function_definition:
    type IDENTIFIER '(' args ')' '{' program '}'
    ;

for_statement:
    FOR '(' for_init ';' multiple_expr ';' multiple_expr ')' statement
    ;
multiple_expr:
    expr ',' expr
    | expr
    ;
for_init:
    declarations
    | multiple_expr
    ;

declarations:
    declarations ',' declaration
    | declaration
    ;

while_statement:
    WHILE '(' expr ')' statement
    ;

do_while_statement:
    DO statement WHILE '(' expr ')' ';'
    ;

if_statement:
    IF '(' expr ')' statement %prec LOWER_THAN_ELSE
    | IF '(' expr ')' statement ELSE statement
    ;
switch_statement:
    SWITCH '(' expr ')' '{' switch_cases '}'
    ;
switch_cases:
    switch_case
    | switch_case switch_cases
    ;
switch_case:
    CASE expr ':' program
    | DEFAULT ':' program
    ;
declaration:
    type IDENTIFIER
    | type IDENTIFIER '=' expr
    | CONST type IDENTIFIER '=' expr
    ;

type:
    INT
    | FLOAT
    | CHAR
    | VOID
    | BOOL
    | STRING_TYPE
    ;

expr:
    expr '=' expr
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr EQ expr
    | expr NEQ expr
    | expr '<' expr
    | expr '>' expr
    | expr LTE expr
    | expr GTE expr
    | expr AND expr
    | expr OR expr
    | NOT expr
    | INTEGER
    | FLOAT
    | CHAR
    | TRUE
    | FALSE
    | BOOL
    | STRING
    | CHARACTER
    | IDENTIFIER
    | IDENTIFIER '(' params ')'
    | '(' expr ')'
    
    ;


args:
    /* empty */
    | arg
    | args ',' arg
    ;
arg :
    type IDENTIFIER
    | type IDENTIFIER '=' expr
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