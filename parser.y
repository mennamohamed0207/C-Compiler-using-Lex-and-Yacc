%code requires {
    #include "compiler.h"  
}
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "compiler.h"
    extern void log_symbol_table();
    extern void log_errors(int line, const char *msg);
    extern void check_unused_variables();


    Node* create_operation(int oper, int nops,...);
    Node* create_constant(int type ,int dataType);
    Node* create_identifier(char* i, int dataType, int qualifier);
    void free_node(Node *p);

    int write_to_assembly(Node *p, int cont = -1, int brk = -1, int args = 0, ...);
    extern int yylex();
    void yyerror(const char *s);
    extern int yylineno;

%}
%union {
  int intValue;            // integer
  float floatValue;        // float
  char* stringValue;       // string
  char charValue;         // character
  bool boolValue;          // boolean
  char *sIndex;            // symbol table index
  char *varType;           // variable type
  Node *nodePtr;           // node pointer
}

/* Tokens */
%token <intValue> INTEGER
%token <floatValue> FLOAT
%token <stringValue> STRING CHARACTER
%token <boolValue> TRUE FALSE BOOL
%token <sIndex> IDENTIFIER



/* Tokens */
%token CHAR_TYPE VOID ELSE WHILE RETURN FOR BREAK CONTINUE DO CONST STRING_TYPE BOOL_TYPE INT_TYPE FLOAT_TYPE 
%token SWITCH CASE DEFAULT
%token EQ NEQ LTE GTE NOT IF
%token BLOCK
%token FUNCTION
%token DECLARATION


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
%nonassoc NEGATIVE

%nonassoc LOWER_THAN_ELSE  /* For dangling-else resolution */
%nonassoc ELSE
%nonassoc FUNC
/* Non-terminal types */
%type <nodePtr> program statement single_statement compound_statement expr assignment_statement function_call
%type <nodePtr>  params function_definition return_statement
%type <nodePtr> for_statement while_statement do_while_statement if_statement
%type <nodePtr> switch_statement switch_cases declaration default_statement
%type <nodePtr> multiple_expr for_init args
%type <intValue> type
%%

root:
    program    {check_unused_variables();}
    ;

program:
{$$=NULL;}
    | program statement  {write_to_assembly($2);}
    ;

statement:
    single_statement ';'  {$$=$1;}
    | compound_statement {$$=$1;}
    | '{' program '}' {$$=create_operation(BLOCK,1,NULL);}
    ;

single_statement:
    declaration {$$=$1;}
    | expr {$$=$1;}
    | return_statement {$$=$1;}
    | BREAK ';' {$$=create_operation(BREAK,1,NULL);}
    | CONTINUE ';' {$$=create_operation(CONTINUE,1,NULL);}
    | assignment_statement {$$=$1;}
    | function_call {$$=$1;}
    ;

compound_statement:
    for_statement {$$=$1;}
    | while_statement {$$=$1;}
    | if_statement {$$=$1;}
    | do_while_statement {$$=$1;}
    | function_definition {$$=$1;}
    | switch_statement {$$=$1;}
    ;



params:
    /* empty */
    {$$=NULL;}
    | expr {$$=$1;}
    | params ',' expr {$$=create_operation(COMMA,2,$1,$3);}
    ;

return_statement:
    RETURN statement {$$=create_operation(RETURN,1,$2);}
    ;
function_definition:
    type IDENTIFIER '(' args ')' '{' program return_statement '}' {$$=create_operation(FUNCTION,4,$2,$4,$7,$8);}
    ;

for_statement:
    FOR '(' for_init ';' multiple_expr ';' multiple_expr ')' statement  {$$=create_operation(FOR,4,$3,$5,$7,$9);}
    ;
multiple_expr:
    expr ',' expr {$$=create_operation(',',2,$1,$3);}
    | expr {$$=$1;}
    ;
for_init:
    {$$=create_operation(';',2,NULL,NULL);}
    | declaration {$$=$1;}
    ;



while_statement:
    WHILE '(' expr ')' statement {$$=create_operation(WHILE,2,$3,$5);}
    ;

do_while_statement:
    DO statement WHILE '(' expr ')' ';' {$$=create_operation(DO,2,$2,$5);}
    ;

if_statement:
    IF '(' expr ')' statement %prec LOWER_THAN_ELSE {$$=create_operation(IF,2,$3,$5);}
    | IF '(' expr ')' statement ELSE statement {$$=create_operation(IF,3,$3,$5,$7);}
    ;
switch_statement:
    SWITCH '(' IDENTIFIER ')' '{' switch_cases '}' {$$=create_operation(SWITCH,2,create_identifier($3),$6);}
    | SWITCH '(' IDENTIFIER ')' '{' switch_cases  default_statement '}' {$$=create_operation(SWITCH,2,create_identifier($3),$6,$7);}
    ;

default_statement:
    DEFAULT ':' statement {$$=create_operation(DEFAULT,1,$3);}
    ;
switch_cases:
    CASE INTEGER ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,4,create_constant(INTEGER,INT_TYPE,$2),$4,create_operation(BREAK,0),$7);}
    | CASE STRING ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,$2),$4,create_operation(BREAK,0),$7);}
    | CASE CHARACTER ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,4,create_constant(CHARACTER,CHAR_TYPE,$2),$4,create_operation(BREAK,0),$7);}
    | CASE INTEGER ':' statement BREAK ';' {$$=create_operation(CASE,4,create_constant(INTEGER,INT_TYPE,$2),$4,create_operation(BREAK,0));}
    | CASE STRING ':' statement BREAK ';' {$$=create_operation(CASE,4,create_constant(STRING,STRING_TYPE,$2),$4,create_operation(BREAK,0));}
    | CASE CHARACTER ':' statement BREAK ';' {$$=create_operation(CASE,3,create_constant(CHARACTER,CHAR_TYPE,$2),$4,create_operation(BREAK,0));}
    ;

declaration:
    type IDENTIFIER {$$=create_operation(DECLARATION,1,create_identifier($2,$1,0));}
    | type IDENTIFIER '=' expr {$$=create_operation('=',2,create_identifier($2,$1),$4);}
    | CONST type IDENTIFIER '=' expr {$$=create_operation('=',2,create_identifier($3,$2,CONST),$5);}
    ;
assignment_statement:
    IDENTIFIER '=' expr {$$=create_operation('=',2,create_identifier($1),$3);}
    | IDENTIFIER '=' function_call %prec FUNC {$$=create_operation('=',2,create_identifier($1),$3);}
    ;
function_call:
    IDENTIFIER '(' params ')' {$$=create_operation(CALL,2,create_identifier($1),$3);}
    ;
type:
    INT_TYPE  {$$=INT_TYPE;}
    | FLOAT_TYPE {$$=FLOAT_TYPE;}
    | CHAR_TYPE {$$=CHAR_TYPE;}
    | VOID {$$=VOID;}
    | BOOL_TYPE {$$=BOOL_TYPE;}
    | STRING_TYPE {$$=STRING_TYPE;}
    ;

expr:
    expr POST_INC {$$=create_operation(POST_INC,1,$1);}
    | expr POST_DEC {$$=create_operation(POST_DEC,1,$1);}
    | PRE_INC expr {$$=create_operation(PRE_INC,1,$2);}
    | PRE_DEC expr {$$=create_operation(PRE_DEC,1,$2);}
    | expr '+' expr {$$=create_operation('+',2,$1,$3);}
    | expr '-' expr {$$=create_operation('-',2,$1,$3);}
    | expr '*' expr {$$=create_operation('*',2,$1,$3);}
    | expr '/' expr {$$=create_operation('/',2,$1,$3);}
    | expr EQ expr {$$=create_operation('==',2,$1,$3);}
    | expr NEQ expr {$$=create_operation('!=',2,$1,$3);}
    | expr '<' expr {$$=create_operation('<',2,$1,$3);}
    | expr '>' expr {$$=create_operation('>',2,$1,$3);}
    | expr LTE expr {$$=create_operation('<=',2,$1,$3);}
    | expr GTE expr {$$=create_operation('>=',2,$1,$3);}
    | expr AND expr {$$=create_operation('&&',2,$1,$3);}
    | expr OR expr {$$=create_operation('||',2,$1,$3);}
    | NOT expr {$$=create_operation('!',1,$2);}
    | '-' expr %prec NEGATIVE {$$=create_operation(NEGATIVE,1,$2);}
    | INTEGER {$$=create_constant(INTEGER,INT_TYPE,$1);}
    | FLOAT {$$=create_constant(FLOAT,FLOAT_TYPE,$1);}
    | TRUE {$$=create_constant(BOOL,BOOL_TYPE,1);}
    | FALSE {$$=create_constant(BOOL,BOOL_TYPE,0);}
    | STRING {$$=create_constant(STRING,STRING_TYPE,$1);}
    | CHARACTER {$$=create_constant(CHARACTER,CHAR_TYPE,$1);}
    | IDENTIFIER {$$=create_identifier($1);}
    | '(' expr ')' {$$=$2;}
    
    ;



args :
    declaration ',' args {$$=create_operation(COMMA,2,$1,$3);}
    | declaration {$$=$1;}
    | {$$=NULL;}
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
Node* create_constant(int type ,int dataType,...) {
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
    nodeSize = sizeof(Node) + sizeof(VariableNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = VARIABLE;
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