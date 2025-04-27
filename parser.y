%code requires {
    #include "compiler.h"  
}
%{

    #include <stdio.h>
    #include <stdlib.h>
    #include "compiler.h"
    extern void log_symbol_table(const char* filename);
    extern void log_errors(int line, const char *msg,const char* filename);
    extern void check_unused_variables();
    extern void open_assembly_file(const char* filename="x.txt");
    extern FILE *assemblyOutFile;


    Node* create_operation(int oper, int line_number,int nops,...);
    Node* create_constant(int type ,int line_number,int dataType);
    Node* create_identifier(char* i, int line_number, int dataType, int qualifier);
    void free_node(Node *p);

    int write_to_assembly(Node *p, Node *parent=NULL, int cont = -1, int brk = -1, int args = 0, ...);
    extern int yylex();
    extern void yyerror(const char *s, int line_number);
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
%left '*' '/' MOD
%left POST_INC POST_DEC
%right PRE_INC PRE_DEC
%right NOT
%nonassoc NEGATIVE

%nonassoc LOWER_THAN_ELSE  /* For dangling-else resolution */
%nonassoc ELSE
%nonassoc FUNC
/* Non-terminal types */
%type <nodePtr> program statement single_statement compound_statement expr assignment_statement function_call for_assignment
%type <nodePtr>  params function_definition return_statement statement_list
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
statement_list:
    statement {$$=$1;}
    | statement_list statement {$$=create_operation(';',yylineno,2,$1,$2);}
    ;
statement:
    ';' {$$=create_operation(';',yylineno,2,NULL,NULL);}
    |single_statement  { $$=$1;}
    | compound_statement {$$=$1;}
    | '{' statement_list '}' {$$=create_operation(BLOCK,yylineno,1,$2);}

    ;

single_statement:
    declaration ';' {$$=$1;}
    | expr ';' {$$=$1;}
    | return_statement {$$=$1;}
    | BREAK ';' {$$=create_operation(BREAK,yylineno,1,NULL);}
    | CONTINUE ';' {$$=create_operation(CONTINUE,yylineno,1,NULL);}
    | assignment_statement ';'{$$=$1;}
    | function_call ';' {$$=$1;}
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
    | params ',' expr {$$=create_operation(COMMA,yylineno,2,$1,$3);}
    ;

return_statement:
    RETURN expr ';' {$$=create_operation(RETURN,yylineno,1,$2);}
    | RETURN ';' {$$=create_operation(RETURN,yylineno,1,NULL);}
    ;
function_definition:
    declaration '(' args ')' '{' statement_list return_statement '}'  {
        $$ = create_operation(FUNCTION, yylineno, 4, $1, $3, $6, $7);
        // printf("Parsed function %s\n", $2);  // Debug
    }
    | declaration '(' args ')' '{'  return_statement '}'  {$$=create_operation(FUNCTION,yylineno,3,$1,$3,$6);}
    | declaration '(' args ')' '{'  '}'  {$$=create_operation(FUNCTION,yylineno,2,$1,$3);}
    ;

for_statement:
    FOR '(' for_init ';' multiple_expr ';' for_assignment ')' '{' statement_list '}'  {$$=create_operation(FOR,yylineno,4,$3,$5,$7,$10);}
    |FOR '(' for_init ';' multiple_expr ';' for_assignment ')' '{'  '}'  {$$=create_operation(FOR,yylineno,4,$3,$5,$7,NULL);}
 
    ;

for_assignment:
     { $$ = create_operation(';', yylineno, 2, NULL, NULL); }
  | assignment_statement { $$ = $1; }
   |expr POST_INC {$$=create_operation(POST_INC,yylineno,1,$1);}
    | expr POST_DEC {$$=create_operation(POST_DEC,yylineno,1,$1);}
    | PRE_INC expr {$$=create_operation(PRE_INC,yylineno,1,$2);}
    | PRE_DEC expr {$$=create_operation(PRE_DEC,yylineno,1,$2);}
  ;
multiple_expr:
    {$$=create_operation(';',yylineno,2,NULL,NULL);}
    | expr {$$=$1;}
    ;
for_init:
    {$$=create_operation(';',yylineno,2,NULL,NULL);}
    | declaration {$$=$1;}
    ;



while_statement:
    WHILE '(' expr ')' statement {$$=create_operation(WHILE,yylineno,2,$3,$5);}
    ;

do_while_statement:
    DO statement WHILE '(' expr ')' ';' {$$=create_operation(DO,yylineno,2,$2,$5);}
    ;

if_statement:
    IF '(' expr ')' statement %prec LOWER_THAN_ELSE {$$=create_operation(IF,yylineno,2,$3,$5);}
    | IF '(' expr ')' statement ELSE statement {$$=create_operation(IF,yylineno,3,$3,$5,$7);}
    ;
switch_statement:
    SWITCH '(' IDENTIFIER ')' '{' switch_cases '}' {$$=create_operation(SWITCH,yylineno,2,create_identifier($3,yylineno),$6);}
    | SWITCH '(' IDENTIFIER ')' '{' switch_cases  default_statement '}' {$$=create_operation(SWITCH,yylineno,3,create_identifier($3,yylineno),$6,$7);}
    ;

default_statement:
    DEFAULT ':' statement {$$=create_operation(DEFAULT,yylineno,1,$3);}
    ;
switch_cases:
    CASE INTEGER ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,yylineno,4,create_constant(INTEGER,yylineno,INT_TYPE,$2),$4,create_operation(BREAK,yylineno,0),$7);}
    | CASE STRING ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,yylineno,4,create_constant(STRING,yylineno,STRING_TYPE,$2),$4,create_operation(BREAK,yylineno,0),$7);}
    | CASE CHARACTER ':' statement BREAK ';' switch_cases {$$=create_operation(CASE,yylineno,4,create_constant(CHARACTER,yylineno,CHAR_TYPE,$2),$4,create_operation(BREAK,yylineno,0),$7);}
    | CASE INTEGER ':' statement BREAK ';' {$$=create_operation(CASE,yylineno,3,create_constant(INTEGER,yylineno,INT_TYPE,$2),$4,create_operation(BREAK,yylineno,0));}
    | CASE STRING ':' statement BREAK ';' {$$=create_operation(CASE,yylineno,3,create_constant(STRING,yylineno,STRING_TYPE,$2),$4,create_operation(BREAK,yylineno,0));}
    | CASE CHARACTER ':' statement BREAK ';' {$$=create_operation(CASE,yylineno,3,create_constant(CHARACTER,yylineno,CHAR_TYPE,$2),$4,create_operation(BREAK,yylineno,0));}
    ;

declaration:
    type IDENTIFIER {$$=create_operation(DECLARATION,yylineno,1,create_identifier($2,yylineno,$1,0));}
    | type IDENTIFIER '=' expr {$$=create_operation(DECLARATION,yylineno,2,create_identifier($2,yylineno,$1,0),$4);}
    | CONST type IDENTIFIER '=' expr {$$=create_operation(DECLARATION,yylineno,2,create_identifier($3,yylineno,$2,1),$5);}
    /* | type IDENTIFIER '=' function_call  %prec FUNC {$$=create_operation('=',2,create_identifier($2,$1),$4);} */
    ;
assignment_statement:
    IDENTIFIER '=' expr {$$=create_operation('=',yylineno,2,create_identifier($1,yylineno),$3);}
    | IDENTIFIER '=' function_call %prec FUNC {$$=create_operation('=',yylineno,2,create_identifier($1,yylineno),$3);}
    ;
function_call:
    IDENTIFIER '(' params ')' {$$=create_operation(CALL,yylineno,2,create_identifier($1,yylineno),$3);}
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
    expr POST_INC {$$=create_operation(POST_INC,yylineno,1,$1);}
    | expr POST_DEC {$$=create_operation(POST_DEC,yylineno,1,$1);}
    | PRE_INC expr {$$=create_operation(PRE_INC,yylineno,1,$2);}
    | PRE_DEC expr {$$=create_operation(PRE_DEC,yylineno,1,$2);}
    | expr '+' expr {$$=create_operation('+',yylineno,2,$1,$3);}
    | expr '-' expr {$$=create_operation('-',yylineno,2,$1,$3);}
    | expr '*' expr {$$=create_operation('*',yylineno,2,$1,$3);}
    | expr '/' expr {$$=create_operation('/',yylineno,2,$1,$3);}
    | expr EQ expr {$$=create_operation(EQ,yylineno,2,$1,$3);}
    | expr NEQ expr {$$=create_operation(NEQ,yylineno,2,$1,$3);}
    | expr '<' expr {$$=create_operation('<',yylineno,2,$1,$3);}
    | expr MOD expr {$$=create_operation(MOD,yylineno,2,$1,$3);}
    | expr '>' expr {$$=create_operation('>',yylineno,2,$1,$3);}
    | expr LTE expr {$$=create_operation(LTE,yylineno,2,$1,$3);}
    | expr GTE expr {$$=create_operation(GTE,yylineno,2,$1,$3);}
    | expr AND expr {$$=create_operation(AND,yylineno,2,$1,$3);}
    | expr OR expr {$$=create_operation(OR,yylineno,2,$1,$3);}
    | NOT expr {$$=create_operation(NOT,yylineno,1,$2);}
    | '-' expr %prec NEGATIVE {$$=create_operation(NEGATIVE,yylineno,1,$2);}
    | INTEGER {$$=create_constant(INTEGER,yylineno,INT_TYPE,$1);}
    | FLOAT {$$=create_constant(FLOAT,yylineno,FLOAT_TYPE,$1);}
    | TRUE {$$=create_constant(BOOL,yylineno,BOOL_TYPE,1);}
    | FALSE {$$=create_constant(BOOL,yylineno,BOOL_TYPE,0);}
    | STRING {$$=create_constant(STRING,yylineno,STRING_TYPE,$1);}
    | CHARACTER {$$=create_constant(CHARACTER,yylineno,CHAR_TYPE,$1);}
    | IDENTIFIER {$$=create_identifier($1,yylineno);}
    | '(' expr ')' {$$=$2;}
    
    ;



args :
    args ','  declaration {$$=create_operation(COMMA,yylineno,2,$1,$3);}
    | declaration {$$=$1;}
    | {$$=NULL;}
    ;

%%
// Node construction functions
// Create operation nodes
Node* create_operation(int oper, int line_number,int nops,...) {
    va_list ap;
    Node *p;
    size_t nodeSize;
    int i;
    
    
    nodeSize = sizeof(Node) + sizeof(OperationNode) + (nops - 1) * sizeof(Node*);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory", line_number);

    p->type = OPERATION;
    p->opr.symbol = oper;
    p->opr.nops = nops;
    p->line_number = line_number;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

// Create constant nodes

Node* create_constant(int type, int line_number, int dataType, ...) {
    va_list ap;
    Node *p;
    size_t nodeSize;

    nodeSize = sizeof(Node) + sizeof(ConstantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        yyerror("out of memory", line_number);

    p->type = CONSTANT;
    p->con.dataType = dataType;
    p->line_number = line_number;
    va_start(ap, dataType);
    
    switch(dataType) {
        case INT_TYPE:
            p->con.value.intVal = va_arg(ap, int);
            break;
        case FLOAT_TYPE:
            p->con.value.floatVal = (float)va_arg(ap, double);
            break;
        case STRING_TYPE:
        case CHAR_TYPE:
            p->con.value.strVal = va_arg(ap, char*);
            break;
        case BOOL_TYPE:
            p->con.value.boolVal = va_arg(ap, int);
            break;
        default:
            memset(&p->con.value, 0, sizeof(ValueType));
    }
    va_end(ap);
    return p;
}
// Create identifier nodes
Node* create_identifier(char* i, int line_number, int dataType, int qualifier) {
    Node *p;
    size_t nodeSize;
    nodeSize = sizeof(Node) + sizeof(VariableNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
        {
            printf("out of memory\n");
            yyerror("out of memory",line_number);}
    if(i == NULL)
    {

        printf("data %d\n", dataType);
        printf("qual %d\n", qualifier);
    }
    p->type = VARIABLE;
    p->line_number = line_number;
    p->id.name =  strdup(i) ;  // Handle null case
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
    
void yyerror(const char *s, int line_number) {
    log_errors(line_number, s,"errors.txt");
    log_symbol_table("symbol_table.txt");
    open_assembly_file("assembly.txt");
    /* exit(0); */
}
/* 
int main() {
    printf("Starting compilation...\n");
    
    try {
        open_assembly_file();  // Open this early to catch errors
        
        printf("Starting parsing...\n");
        int parse_result = yyparse();
        
        if (parse_result == 0) {
            printf("Parsing completed successfully\n");
            
            // Add flush to ensure output isn't buffered
            fflush(stdout);
            fflush(assemblyOutFile);
            
            printf("Generating symbol table...\n");
            log_symbol_table();
            
            printf("Compilation completed successfully\n");
        } else {

            fprintf(stderr, "Syntax Error at line %d\n",yylineno);
        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        return 1;
    }
    
    if (assemblyOutFile) {
        fclose(assemblyOutFile);
    }
    
    return 0;
} */
int main() {
    // Add these extern declarations
    extern char* yytext;    // Current token text (from lexer)

    printf("Starting compilation...\n");
    
    try {
        printf("Attempting to open assembly output file...\n");
        open_assembly_file();  // Open this early to catch errors
        printf("Assembly file opened successfully\n");
        
        printf("Starting parsing... (lexer/parser initialization)\n");
        int parse_result = yyparse();
        
        if (parse_result == 0) {
            printf("Parsing completed successfully\n");
            
            // Add flush to ensure output isn't buffered
            printf("Flushing output buffers...\n");
            fflush(stdout);
            fflush(assemblyOutFile);
            
            printf("Generating symbol table...\n");
            log_symbol_table("s.txt");
            
            printf("Compilation completed successfully\n");
        } else {
   
            char msg[1024];
            sprintf(msg,"Syntax error near %s ",yytext);
            yyerror(msg,yylineno);

        }
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        fprintf(stderr, "Error occurred at line %d\n", yylineno);
        return 1;
    }
    
    if (assemblyOutFile) {
        printf("Closing assembly output file...\n");
        fclose(assemblyOutFile);
    }
    
    printf("Exiting with return code 0\n");
    return 0;
}