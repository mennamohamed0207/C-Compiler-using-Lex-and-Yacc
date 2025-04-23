%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *s);
    extern int yylex();
    extern int yylineno;
%}
%union {
  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char* charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer
}

/* Tokens */
%token <intValue> INTEGER
%token <floatValue> FLOAT
%token <stringValue> STRING CHARACTER
%token <boolValue> TRUE FALSE
%token <sIndex> IDENTIFIER



/* Tokens */
%token CHAR_TYPE VOID ELSE WHILE RETURN FOR BREAK CONTINUE DO CONST STRING_TYPE BOOL_TYPE INT_TYPE FLOAT_TYPE 
%token SWITCH CASE DEFAULT
%token EQ NEQ LTE GTE NOT IF

/* Precedence (lowest to highest) */
%right '='
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LTE GTE
%left '+' '-'
%left '*' '/'
%left POST_INC POST_DEC
%right PRE_INC PRE_DEC
%right NOT
%nonassoc LOWER_THAN_ELSE  /* For dangling-else resolution */
%nonassoc ELSE
/* Non-terminal types */
%type <nodePtr> program statement single_statement compound_statement expr
%type <nodePtr> break_statement continue_statement params function_definition
%type <nodePtr> for_statement while_statement do_while_statement if_statement
%type <nodePtr> switch_statement switch_cases switch_case declaration
%type <nodePtr> multiple_expr for_init declarations args arg
%type <intValue> type
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
    INT_TYPE
    | FLOAT_TYPE
    | CHAR_TYPE
    | VOID
    | BOOL_TYPE
    | STRING_TYPE
    ;

expr:
    expr '=' expr
    | expr POST_INC
    | expr POST_DEC
    | PRE_INC expr
    | PRE_DEC expr
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
    | TRUE
    | FALSE
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
// Node construction functions
// Create operation nodes
Node* create_operation(int oper, int nops,...) {
    va_list ap;
    Node *p;
    size_t nodeSize;
    int i;
    
    nodeSize = sizeof(Node) + sizeof(OperationNode) + (nops - 1) * sizeof(Node*);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = OPERATION;
    p->opr.symbol = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

// Create constant nodes
Node* create_constant(int type ,int dataType) {
    va_list ap;
    Node *p;
    size_t nodeSize;

    nodeSize = sizeof(Node) + sizeof(ConstantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = CONSTANT;
    p->con.dataType = dataType;
    va_start(ap, dataType);
    p->con.value = va_arg(ap, ValueType);
    va_end(ap);

    return p;
}

// Create identifier nodes
Node* create_identifier(char* i, int dataType, int qualifier) {
    Node *p;
    size_t nodeSize;
    nodeSize = sizeof(Node) + sizeof(IdentifierNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = IDENTIFIER;
    p->id.name = strdup(i);
    p->id.dataType = dataType;
    p->id.qualifier = qualifier;
    return p;
}

void free_node(Node *p) {
    int i;
    if (!p) return;
    if (p->type == OPERATION) {
        for (i = 0; i < p->opr.nops; i++)
        free_node(p->opr.op[i]);
    }
    free(p);
}
    
void yyerror(const char *s) {
    fprintf(stderr, "Parser Error at line %d: %s\n", yylineno, s);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}