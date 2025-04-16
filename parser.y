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
    | function_call
    | expr
    | RETURN expr
    | BREAK
    | CONTINUE
    ;

function_call:
    IDENTIFIER '(' args ')'
    ;

compound_statement:
    for_statement
    | while_statement
    | if_statement
    | do_while_statement
    | function_definition
    ;

function_definition:
    type IDENTIFIER '(' args ')' '{' program '}'
    ;

for_statement:
    FOR '(' for_init ';' expr ';' expr ')' statement
    ;

for_init:
    declaration
    | expr
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
    | '(' expr ')'
    ;


args:
    /* empty */
    | expr
    | args ',' expr
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