%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *s);
    extern int yylex();
    extern int yylineno;
%}

%token INTEGER IDENTIFIER

/* Define tokens for keywords (example subset) */
%token INT FLOAT CHAR VOID IF ELSE WHILE RETURN FOR

/* Define operator tokens */
%token PLUS MINUS MULT DIV ASSIGN EQ NEQ LT GT LTE GTE AND OR NOT

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left MULT DIV
%right NOT

%%

program:
    | program function_def
    ;

function_def:
    type IDENTIFIER '(' params ')' block
    ;

type:
    INT
    | FLOAT
    | CHAR
    | VOID
    ;

params:
    | param_list
    ;

param_list:
    param
    | param_list ',' param
    ;

param:
    type IDENTIFIER
    ;

block:
    '{' statements '}'
    ;

statements:
    | statements statement
    ;

statement:
    expr ';'
    | declaration ';'
    | IF '(' expr ')' block ELSE block
    | WHILE '(' expr ')' block
    | RETURN expr ';'
    ;

declaration:
    type IDENTIFIER
    | type IDENTIFIER ASSIGN expr
    ;

expr:
    expr PLUS expr
    | expr MINUS expr
    | expr MULT expr
    | expr DIV expr
    | expr EQ expr
    | expr NEQ expr
    | expr LT expr
    | expr GT expr
    | expr LTE expr
    | expr GTE expr
    | expr AND expr
    | expr OR expr
    | NOT expr
    | IDENTIFIER ASSIGN expr
    | IDENTIFIER '(' args ')'
    | INTEGER
    | IDENTIFIER
    | '(' expr ')'
    ;

args:
    | arg_list
    ;

arg_list:
    expr
    | arg_list ',' expr
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