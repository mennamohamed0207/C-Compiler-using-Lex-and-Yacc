%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token INTEGER IDENTIFIER

%left '+' '-'
%left '*' '/' '%'
%right '='
%left '>' '<' '>=' '<=' '==' '!='
%left '&&' '||'

%%

root
    : program
    ;

program
    : declarations
    | program declarations
    ;

declarations
    : type_specifier declarator_list ';'
    | function_definition
    | statement
    ;

type_specifier
    : 'integer'     /* INT */
    | 'float'       /* FLOAT */
    | 'double'      /* DOUBLE */
    | 'character'   /* CHAR */
    | 'boolean'     /* BOOL */
    | 'void'        /* VOID */
    ;

declarator_list
    : declarator
    | declarator_list ',' declarator
    ;

declarator
    : IDENTIFIER
    | IDENTIFIER '=' expression
    | IDENTIFIER '[' INTEGER ']'
    ;

function_definition
    : type_specifier IDENTIFIER '(' parameter_list ')' compound_statement
    ;

parameter_list
    : parameter_declaration
    | parameter_list ',' parameter_declaration
    | /* empty */
    ;

parameter_declaration
    : type_specifier declarator
    ;

compound_statement
    : '{' '}'
    | '{' statement_list '}'
    ;

statement_list
    : statement
    | statement_list statement
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | declarations
    ;

expression_statement
    : expression ';'
    | ';'
    ;

selection_statement
    : 'if' '(' expression ')' statement  /* IF */
    | 'if' '(' expression ')' statement 'else' statement  /* IF-ELSE */
    | 'switch' '(' expression ')' statement  /* SWITCH */
    ;

iteration_statement
    : 'while' '(' expression ')' statement  /* WHILE */
    | 'do' statement 'while' '(' expression ')' ';'  /* DO-WHILE */
    | 'for' '(' expression_statement expression_statement expression ')' statement  /* FOR */
    ;

jump_statement
    : 'break' ';'      /* break */
    | 'continue' ';'   /* continue */
    | 'return' expression ';'  /* return */
    ;

expression
    : INTEGER
    | IDENTIFIER
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression
    | expression '=' expression
    | expression '>' expression
    | expression '<' expression
    | expression '>=' expression
    | expression '<=' expression
    | expression '==' expression
    | expression '!=' expression
    | expression '&&' expression
    | expression '||' expression
    | '(' expression ')'
    | IDENTIFIER '(' argument_list ')'
    ;

argument_list
    : expression
    | argument_list ',' expression
    | /* empty */
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}