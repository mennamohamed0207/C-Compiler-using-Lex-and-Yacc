#include "compiler.h"
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include "compiler.h"
#include "parser.tab.h"
#include <sstream>
#include <fstream>
using std::vector;

// Global variables
static int label = 0, timestep = 0;
vector<map<string, SymbolTable *>> symbol(1, map<string, SymbolTable *>());
vector<SymbolTable *> symbolTable;
int level = 0;
FILE *assemblyOutFile = NULL;
extern int line;

void open_assembly_file()
{
    if (assemblyOutFile == NULL)
    {
        assemblyOutFile = fopen("assembly.txt", "w");
    }
}
void add_block_scope()
{
    symbol.push_back(map<string, SymbolTable *>());
    level++;
}
void remove_block_scope()
{
    symbol.pop_back();
    level--;
}

void check_unused_variables()
{
    // Create an iterator for the symbol table
    string unused_variables = "";
    for (int i = 0; i < symbolTable.size(); i++)
    {
        SymbolTable *st = symbolTable[i];

        if (st->used == false && st->isFunction == false)
        {
            printf("=======================================checking variable===========\n");
            printf(st->name.c_str());
            unused_variables += st->name + ", ";
        }
    }
    if (unused_variables.length() > 0)
    {
        char errorMsg[2048];
        sprintf(errorMsg, "Unused variables: %s", unused_variables.c_str());
        yyerror(errorMsg);
    }
}

const char *get_data_type(int type)
{
    switch (type)
    {
    case INTEGER:
    case INT_TYPE:
        return "int";
    case FLOAT:
    case FLOAT_TYPE:
        return "float";
    case BOOL:
    case BOOL_TYPE:
        return "bool";
    case STRING:
    case STRING_TYPE:
        return "string";
    case CHARACTER:
    case CHAR_TYPE:
        return "char";
    case VOID:
        return "void";
    default:
        return "";
    }
}
SymbolTable *get_function_variable(Node *p)
{
    if (!p || p->type != VARIABLE)
        return NULL;
    for (int i = 0; i < symbolTable.size(); i++)
    {
        if (symbolTable[i]->name == p->id.name)
        {
            return symbolTable[i];
        }
    }

    return NULL;
}
SymbolTable *check_variable(Node *p, bool isRHS = false)
{
    if (p->type != VARIABLE)
        return NULL;

    // print symbol table
    printf("Symbol table:\n");
    for (int i = 0; i < symbolTable.size(); i++)
    {
        printf("%s\n", symbolTable[i]->name.c_str());
    }

    // Search from current scope outward
    for (int i = level; i >= 0; i--)
    {
        if (symbol[i].find(p->id.name) != symbol[i].end())
        {
            SymbolTable *entry = symbol[i][p->id.name];
            if (!isRHS && entry->isParam)
            {
                printf("=======================================variable %s\n", p->id.name);
                symbol[i][p->id.name]->used = true;
                return entry;
            }
            // Error as the variable is already declared
            if (isRHS && entry->type == CONSTANT)
            {
                char errorMsg[1024];
                sprintf(errorMsg, "Semantic Error: can't assign values to constant variable '%s'", p->id.name);
                yyerror(errorMsg, p->line_number);
                return NULL;
            }
            if (!isRHS && entry->isFunction == false && entry->isInitialized == false && entry->isParam == false)
            {
                char errorMsg[1024];
                sprintf(errorMsg, "Semantic Error: variable '%s' must be initialized before use", p->id.name);
                yyerror(errorMsg, p->line_number);
                return NULL;
            }
            if (!isRHS && !entry->isInitialized && !entry->isParam)
            {
                yyerror("Variable used before initialization", p->line_number);
            }
            printf("=======================================variable %s\n", p->id.name);

            symbol[i][p->id.name]->used = true;
            return symbol[i][p->id.name];
        }
    }

    return NULL;
}

SymbolTable *declare_variable(Node *p, bool isRHS = false, bool isParam = false,bool isIntialized=false)
{

    if (p->type != VARIABLE)
        return NULL;

    // For parameters, we need to allow declaration even if it exists in outer scope
    if (!isParam && symbol[level].find(p->id.name) != symbol[level].end())
    {
        char errorMsg[1024];
        sprintf(errorMsg, "Semantic Error: variable '%s' already declared in this scope", p->id.name);
        yyerror(errorMsg, p->line_number);
        return NULL;
    }
    symbol[level][p->id.name] = new SymbolTable(strdup(p->id.name), p->id.dataType,
                                                p->id.qualifier, level, timestep++, isIntialized);
    symbolTable.push_back(symbol[level][p->id.name]);

    // Mark parameters as initialized
    if (isParam)
    {
        symbol[level][p->id.name]->isInitialized = true;
    }

    return symbol[level][p->id.name];
}

void log_symbol_table()
{
    printf("Logging symbol table...\n");
    FILE *symbolTableFile = fopen("symbol_table.txt", "w");
    if (symbolTableFile == NULL)
    {
        printf("Error opening symbol table file: symbol_table.txt\n");
        return;
    }

    // Print a header with column names, aligned
    fprintf(symbolTableFile, "----------------------------------------------------------------------------------------------\n");
    fprintf(symbolTableFile, "| %-20s | %-10s | %-10s | %-8s | %-6s | %-11s | %-6s | %-9s |\n",
            "Name", "DataType", "Qualifier", "TimeStep", "Scope", "Initialized", "Used", "Function");
    fprintf(symbolTableFile, "----------------------------------------------------------------------------------------------\n");

    // Print each symbol in a nicely aligned format
    for (int i = 0; i < symbolTable.size(); i++)
    {
        SymbolTable *st = symbolTable[i];
        fprintf(symbolTableFile, "| %-20s | %-10s | %-10s | %-8d | %-6d | %-11s | %-6s | %-9s |\n",
                st->name.c_str(),
                get_data_type(st->type),
                st->symbolType == 1 ? "Constant" : "Variable",
                st->timestamp,
                st->scope,
                st->isInitialized ? "True" : "False",
                st->used ? "True" : "False",
                st->isFunction ? "True" : "False");
    }

    fprintf(symbolTableFile, "----------------------------------------------------------------------------------------------\n");

    fclose(symbolTableFile);
}
SymbolTable *declare_parameter(Node *p)
{

    SymbolTable *param = declare_variable(p->opr.op[0], true, true,true);
    if (param)
    {
        param->isInitialized = true;
        param->isParam = true;
    }
    return param;
}
const char *get_type_from_name(const char *name)
{
    for (int i = 0; i < symbolTable.size(); i++)
    {
        if (symbolTable[i]->name == name)
        {
            return get_data_type(symbolTable[i]->type);
        }
    }
    return NULL;
}

void log_errors(int line, const char *msg)
{
    FILE *errorFile = fopen("errors.txt", "a");
    if (!errorFile)
    {
        fprintf(stderr, "Error opening error file: errors.txt\n");
        exit(1);
    }
    if (line != 0)
        fprintf(errorFile, "Error at line %d: %s\n", line, msg);
    else
        fprintf(errorFile, "Error: %s\n", msg);
}

Node *create_label_node(int label)
{
    Node *p;
    size_t nodeSize;

    nodeSize = SIZEOFNODE + sizeof(ConstantNode);
    if ((p = (Node *)malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = CONSTANT;
    p->con.value.intVal = label;
    return p;
}
bool is_constant(Node *p)
{
    for (int i = 0; i < symbolTable.size(); i++)
    {
        SymbolTable *st = symbolTable[i];
        if (st->name == p->id.name)
        {
            if (st->symbolType == 1)
            {
                return true;
            }
        }
    }
    return false;
}

void mark_used(Node *p)
{
    if (p->type == VARIABLE)
    {
        for (int i = 0; i < symbolTable.size(); i++)
        {
            if (symbolTable[i]->name == p->id.name)
            {
                symbolTable[i]->used = true;
                break;
            }
        }
    }
}

int write_to_assembly(Node *p, Node *parent = NULL, int cont = -1, int brk = -1, int args = 0, ...)
{
    printf("write_to_assembly %d\n", p->opr.symbol);

    fflush(stdout);
    va_list ap;
    int l1, l2, l3, type1, type2;
    Node *lblNode;
    vector<Node *> argsVector;
    va_start(ap, args);
    for (int i = 0; i < args; i++)
    {
        argsVector.push_back(va_arg(ap, Node *));
    }
    va_end(ap);
    SymbolTable *symoblTableEntry = NULL;
    Node *n;
    Node *switch_var;
    int endLabel, defaultLabel;
    if (!p)
    {
        // fprintf(stderr,"write_to_assembly: NULL pointer\n");
        return 0;
    }
    switch (p->type)
    {
    case CONSTANT:
        switch (p->con.dataType)
        {
        case INT_TYPE:
            printf("\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
            open_assembly_file();
            fprintf(assemblyOutFile, "\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
            fflush(assemblyOutFile);
            return INT_TYPE;
        case BOOL_TYPE:
            printf("\tpush %s\t%d\n", get_data_type(BOOL_TYPE), p->con.value.boolVal);
            open_assembly_file();
            fprintf(assemblyOutFile, "\tpush %s\t%d\n", get_data_type(BOOL_TYPE), p->con.value.boolVal);
            fflush(assemblyOutFile);
            return BOOL_TYPE;
        case FLOAT_TYPE:
            printf("\tpush %s\t%f\n", get_data_type(FLOAT_TYPE), p->con.value.floatVal);
            open_assembly_file();
            fprintf(assemblyOutFile, "\tpush %s\t%f\n", get_data_type(FLOAT_TYPE), p->con.value.floatVal);
            fflush(assemblyOutFile);
            return FLOAT_TYPE;
        case STRING_TYPE:
            printf("\tpush %s\t%s\n", get_data_type(STRING_TYPE), p->con.value.strVal);
            open_assembly_file();
            fprintf(assemblyOutFile, "\tpush %s\t%s\n", get_data_type(STRING_TYPE), p->con.value.strVal);
            fflush(assemblyOutFile);
            return STRING_TYPE;
        case CHAR_TYPE:
            printf("\tpush %s\t%c\n", get_data_type(CHAR_TYPE), p->con.value.charVal);
            open_assembly_file();
            fprintf(assemblyOutFile, "\tpush %s\t%c\n", get_data_type(CHAR_TYPE), p->con.value.charVal);
            fflush(assemblyOutFile);
            return CHAR_TYPE;
        }
        break;
    case VARIABLE:
        // printf("=======================================variable %s\n", p->id.name);
        symoblTableEntry = check_variable(p);
        if (!symoblTableEntry)
        {
            char errorMsg[1024];
            sprintf(errorMsg, "Semantic Error: variable '%s' not declared", p->id.name);
            yyerror(errorMsg, p->line_number);
            return 0;
        }
        printf("\tpush\t%s\n", p->id.name);
        fprintf(assemblyOutFile, "\tpush\t%s\n", p->id.name);
        fflush(assemblyOutFile);
        return symoblTableEntry->type;

    case OPERATION:

        switch (p->opr.symbol)
        {
        case DECLARATION:
        {

            if (p->opr.nops == 1) // declaration without initialization
            {
                SymbolTable *entry = declare_variable(p->opr.op[0], true,false,false);
                if (entry != NULL)
                { // Only write to assembly if declaration was successful
                    printf("\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
                    open_assembly_file();
                    fprintf(assemblyOutFile, "\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
                    fflush(assemblyOutFile);
                }
                else
                {
                    printf("Semantic Error: variable '%s' already declared\n", p->opr.op[0]->id.name);
                    yyerror("variable already declared", p->line_number);
                    return 0;
                }
                return entry->type;
            }
            else if (p->opr.nops == 2) // declaration with initialization
            {
                SymbolTable *entry = declare_variable(p->opr.op[0], true,false,true);
                if (entry == NULL)
                {
                    printf("Semantic Error: variable '%s' already declared\n", p->opr.op[0]->id.name);
                    yyerror("variable already declared", p->line_number);
                    return 0;
                }
                type1 = write_to_assembly(p->opr.op[1], p);
                if (type1 != entry->type)
                {
                    printf("Semantic Error: type mismatch in declaration and initialization\n");
                    yyerror("type mismatch in declaration and initialization", p->line_number);
                    return 0;
                }
                entry->isInitialized = true;
                printf("\tpop %s\t%s\n", get_data_type(entry->type), p->opr.op[0]->id.name);
                open_assembly_file();
                fprintf(assemblyOutFile, "\tpop %s\t%s\n", get_data_type(entry->type), p->opr.op[0]->id.name);
                fflush(assemblyOutFile);
                return entry->type;
            }

            break;
        }
        case WHILE:
            open_assembly_file();
            add_block_scope();
            printf("L%03d:\n", l1 = label++); // start
            fprintf(assemblyOutFile, "L%03d:\n", l1);
            fflush(assemblyOutFile);
            type1 = write_to_assembly(p->opr.op[0], p);
            if (type1 != BOOL_TYPE)
            {
                printf("Semantic Error: while condition must be a boolean expression\n");
                yyerror("while condition must be a boolean expression", p->line_number);
            }
            printf("\tjz\tL%03d\n", l2 = label++); // if false
            fprintf(assemblyOutFile, "\tjz\tL%03d\n", l2);
            fflush(assemblyOutFile);

            write_to_assembly(p->opr.op[1], p, l1, l2); // body
            printf("\tjmp\tL%03d\n", l1);               // continue
            fprintf(assemblyOutFile, "\tjmp\tL%03d\n", l1);
            fflush(assemblyOutFile);

            printf("L%03d:\n", l2); // end
            fprintf(assemblyOutFile, "L%03d:\n", l2);
            fflush(assemblyOutFile);

            remove_block_scope();
            break;
        case IF:
            open_assembly_file();
            add_block_scope();
            type1 = write_to_assembly(p->opr.op[0], p);
            if (type1 != BOOL_TYPE)
            {
                printf("Semantic Error: if condition must be a boolean expression\n");
                yyerror("if condition must be a boolean expression", p->line_number);
            }
            if (p->opr.nops > 2)
            {
                // else if
                printf("\tjz\tL%03d\n", l1 = label++);
                write_to_assembly(p->opr.op[1], p, cont, brk);
                printf("\tjmp\tL%03d\n", l2 = label++);
                printf("L%03d:\n", l1);
                write_to_assembly(p->opr.op[2], p, cont, brk);
                printf("L%03d:\n", l2);
            }
            else
            {
                // else
                printf("\tjz\tL%03d\n", l1 = label++);
                write_to_assembly(p->opr.op[1], p, cont, brk);
                printf("L%03d:\n", l1);
            }
            remove_block_scope();
            break;
        case FOR:
            open_assembly_file();
            add_block_scope();
            write_to_assembly(p->opr.op[0], p);
            printf("L%03d:\n", l1 = label++);
            fprintf(assemblyOutFile, "L%03d:\n", l1);
            fflush(assemblyOutFile);
            type1 = write_to_assembly(p->opr.op[1], p);
            if (type1 != BOOL_TYPE)
            {
                printf("Semantic Error: for condition must be a boolean expression\n");
                yyerror("for condition must be a boolean expression", p->line_number);
            }
            printf("\tjz\tL%03d\n", l2 = label++);
            fprintf(assemblyOutFile, "\tjz\tL%03d\n", l2);
            fflush(assemblyOutFile);

            write_to_assembly(p->opr.op[3], p, l3 = label++, l2); // body

            printf("L%03d:\n", l3); // continue if true
            fprintf(assemblyOutFile, "L%03d:\n", l3);
            fflush(assemblyOutFile);

            write_to_assembly(p->opr.op[2], p); // next iter inc/dec
            printf("\tjmp\tL%03d\n", l1);
            fprintf(assemblyOutFile, "\tjmp\tL%03d\n", l1);
            fflush(assemblyOutFile);
            printf("L%03d:\n", l2);
            fprintf(assemblyOutFile, "L%03d:\n", l2);
            fflush(assemblyOutFile);

            remove_block_scope();
            break;
        case SWITCH:
            open_assembly_file();
            label++;
            endLabel = 1111;
            defaultLabel = 999;
            switch_var = p->opr.op[0];
            if (switch_var->type != VARIABLE)
            {
                printf("Semantic Error: switch variable must be a variable\n");
                yyerror("switch variable must be a variable", p->line_number);
            }
            printf("\tpop %s\t\n", switch_var->id.name);
            fprintf(assemblyOutFile, "\tpop %s\t\n", switch_var->id.name);
            fflush(assemblyOutFile);
            n = p->opr.op[1];
            while (n->opr.symbol == CASE)
            {
                bool lastCase = false;
                if (n->opr.nops == 3)
                {
                    lastCase = true;
                }
                printf("L%03d:\n", l1 = label++);
                fprintf(assemblyOutFile, "L%03d:\n", l1);
                fflush(assemblyOutFile);
                printf("\tpush\t%s\n", switch_var->id.name);
                fprintf(assemblyOutFile, "\tpush\t%s\n", switch_var->id.name);
                fflush(assemblyOutFile);
                write_to_assembly(n->opr.op[0], p, cont, brk);
                printf("\tcompEQ\t\n");
                fprintf(assemblyOutFile, "\tcompEQ\t\n");
                fflush(assemblyOutFile);
                if (lastCase)
                {
                    if (p->opr.nops == 3)
                    {
                        printf("\tjz\tL%03d\n", l1 = defaultLabel);
                        fprintf(assemblyOutFile, "\tjz\tL%03d\n", l1);
                        fflush(assemblyOutFile);
                    }
                    else
                    {
                        printf("\tjz\tL%03d\n", l1 = endLabel);
                        fprintf(assemblyOutFile, "\tjz\tL%03d\n", l1);
                        fflush(assemblyOutFile);
                    }
                }
                else
                {
                    printf("\tjz\tL%03d\n", l1 = ++label);
                    fprintf(assemblyOutFile, "\tjz\tL%03d\n", l1);
                    fflush(assemblyOutFile);
                }
                write_to_assembly(n->opr.op[1], p, cont, brk);
                printf("\tjmp\tL%03d\n", endLabel);
                fprintf(assemblyOutFile, "\tjmp\tL%03d\n", endLabel);
                fflush(assemblyOutFile);
                if (lastCase)
                {
                    break;
                }
                else
                {
                    n = n->opr.op[3];
                }
            }
            // default case
            if (p->opr.nops == 3)
            {
                printf("L%03d:\n", l1 = defaultLabel);
                fprintf(assemblyOutFile, "L%03d:\n", l1);
                fflush(assemblyOutFile);
                write_to_assembly(p->opr.op[2]->opr.op[0], p, cont, brk);
                printf("\tjmp\tL%03d\n", endLabel);
                fprintf(assemblyOutFile, "\tjmp\tL%03d\n", endLabel);
                fflush(assemblyOutFile);
            }
            printf("L%03d:\n", endLabel);
            fprintf(assemblyOutFile, "L%03d:\n", endLabel);
            fflush(assemblyOutFile);
            break;
        case DO:
            open_assembly_file();
            add_block_scope();
            printf("L%03d:\n", l1 = label++);
            fprintf(assemblyOutFile, "L%03d:\n", l1);
            fflush(assemblyOutFile);
            write_to_assembly(p->opr.op[0], p, l1, l2 = label++);
            type1 = write_to_assembly(p->opr.op[1], p);
            if (type1 != BOOL_TYPE)
            {
                printf("Semantic Error: do while condition must be a boolean expression\n");
                yyerror("do while condition must be a boolean expression", p->line_number);
            }

            printf("\tjnz\tL%03d\n", l1); // if true repeat
            fprintf(assemblyOutFile, "\tjnz\tL%03d\n", l1);
            fflush(assemblyOutFile);

            printf("L%03d:\n", l2);
            fprintf(assemblyOutFile, "L%03d:\n", l2);
            fflush(assemblyOutFile);

            remove_block_scope();
            break;
        case '=':
        {
            open_assembly_file();

            type1 = write_to_assembly(p->opr.op[1], p);
            // check if it is constant
            printf("===========================p->opr.op[0]->id.qualifier = %d\n", p->opr.op[0]->id.qualifier);
            bool isConstant = is_constant(p->opr.op[0]);

            if (isConstant)
            {
                yyerror("Semantic ERROR: Assignment to constant", p->line_number);
            }

            if (get_data_type(type1) == get_type_from_name(p->opr.op[0]->id.name)) // variable assignment
            {
                mark_used(p->opr.op[0]);
                // check if it is constant
                if (p->opr.op[1]->type == CONSTANT)
                {
                    // printf("\tpush\t%s\t%d\n", get_data_type(type1), p->opr.op[1]->con.value);
                    // fflush(stdout);
                    // if (type1 == INT_TYPE)
                    // {
                    //     fprintf(assemblyOutFile, "\tpush\t%s\t%d\n", get_data_type(type1), p->opr.op[1]->con.value);
                    // }
                    // else if (type1 == STRING_TYPE)
                    // {
                    //     fprintf(assemblyOutFile, "\tpush\t%s\t%s\n", get_data_type(type1), p->opr.op[1]->con.value);
                    // }
                    // else if (type1 == FLOAT_TYPE)
                    // {
                    //     fprintf(assemblyOutFile, "\tpush\t%s\t%f\n", get_data_type(type1), p->opr.op[1]->con.value);
                    // }
                    // fflush(assemblyOutFile);
                }
                else
                {
                    // Call
                    fprintf(assemblyOutFile, "\tpush\t%s\n", "Call");
                    fflush(assemblyOutFile);
                }
            }

            printf("\tpop %s\t%s\t%s\n", get_type_from_name(p->opr.op[0]->id.name), p->opr.op[0]->id.qualifier == 1 ? "const" : "", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tpop %s\t%s %s\n", get_type_from_name(p->opr.op[0]->id.name), p->opr.op[0]->id.qualifier == 1 ? "const" : "", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return type1;
        }
        break;
        case NEGATIVE:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tneg\t\n");
            fprintf(assemblyOutFile, "\tneg\t\n");
            fflush(assemblyOutFile);
            return type1;
        case NOT:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tnot\t\n");
            fprintf(assemblyOutFile, "\tnot\t\n");
            fflush(assemblyOutFile);
            return BOOL_TYPE;
        case POST_DEC:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tdec\t%s\n", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tdec\t%s\n", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return type1;
        case POST_INC:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tinc\t%s\n", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tinc\t%s\n", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return type1;
        case PRE_DEC:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tdec\t%s\n", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tdec\t%s\n", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return type1;
        case PRE_INC:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p);
            printf("\tinc\t%s\n", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tinc\t%s\n", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return type1;
        case BREAK:
            open_assembly_file();
            if (brk == -1)
            {
                yyerror("Semantic ERROR: No loop to Break from", p->line_number);
                break;
            }
            printf("\tjmp\tL%03d\n", brk);
            fprintf(assemblyOutFile, "\tjmp\tL%03d\n", brk);
            fflush(assemblyOutFile);
            break;
        case CONTINUE:
            open_assembly_file();
            if (cont == -1)
            {
                yyerror("Semantic ERROR: No loop to Continue from", p->line_number);
                break;
            }
            printf("\tjmp\tL%03d\n", cont);
            fprintf(assemblyOutFile, "\tjmp\tL%03d\n", cont);
            fflush(assemblyOutFile);
            break;
        case DEFAULT:
            open_assembly_file();
            add_block_scope();
            write_to_assembly(p->opr.op[0], p, cont, brk);
            remove_block_scope();
            break;
        case BLOCK:
        {
            open_assembly_file();
            bool should_add_scope = !(parent &&
                                      (parent->type == OPERATION &&
                                       (parent->opr.symbol == IF ||
                                        parent->opr.symbol == WHILE ||
                                        parent->opr.symbol == FOR ||
                                        parent->opr.symbol == DO)));

            if (should_add_scope)
            {
                add_block_scope();
            }
            for (int i = 0; i < p->opr.nops; i++)
            {
                write_to_assembly(p->opr.op[i], p, cont, brk);
            }
            if (should_add_scope)
            {
                remove_block_scope();
            }
        }
        break;
        case FUNCTION:
        {

            open_assembly_file();
            add_block_scope();

            // Declare the function itself
            SymbolTable *funcEntry = declare_variable(p->opr.op[0]->opr.op[0], true,false,true);
            if (!funcEntry)
            {
                yyerror("Function declaration failed", p->line_number);
                return 0;
            }
            funcEntry->isFunction = true;

            printf("\tproc\t%s\n", p->opr.op[0]->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tproc\t%s\n", p->opr.op[0]->opr.op[0]->id.name);

            // Process parameters
            if (p->opr.op[1])
            {
                Node *paramList = p->opr.op[1];
                // Reverse the parameter list to process in declaration order
                vector<Node *> params;
                while (paramList && paramList->type == OPERATION && paramList->opr.symbol == COMMA)
                {
                    params.push_back(paramList->opr.op[1]);
                    paramList = paramList->opr.op[0];
                }
                if (paramList)
                    params.push_back(paramList);

                // Process parameters in reverse order (to match calling convention)
                for (int i = params.size() - 1; i >= 0; i--)
                {
                    // printf("=======================================================declare_variable a,b \n");
                    // fflush(stdout);
                    SymbolTable *param = declare_parameter(params[i]); // isParam=true
                    // printf("=======================================================declare_variable a,b \n");
                    // fflush(stdout);
                    if (param)
                    {
                        param->isInitialized = true; // Mark parameters as initialized
                        fprintf(assemblyOutFile, "\tpop %s\t%s\n",
                                get_data_type(param->type),
                                param->name.c_str());
                    }
                }
            }

            // Process function body
            write_to_assembly(p->opr.op[2], p);
            write_to_assembly(p->opr.op[3], p);

            remove_block_scope();
            return funcEntry->type;
        }

        case CALL:
        {

            // Print the function node
            if (p->opr.op[0])
                printf("Function Node OK\n");
            else
                printf("Function Node is NULL!\n");

            // Get the function entry
            SymbolTable *funcEntry = get_function_variable(p->opr.op[0]);
            printf("After get_function_variable\n");
            fflush(stdout);

            if (funcEntry == NULL)
            {
                printf("Function not declared\n");
                fflush(stdout);
                char errorMsg[1024];
                sprintf(errorMsg, "Semantic Error: function '%s' not declared",
                        p->opr.op[0]->id.name);
                yyerror(errorMsg, p->line_number);
            }

            printf("Function '%s' found in symbol table with type = %d\n",
                   p->opr.op[0]->id.name, funcEntry->type);

            // Process arguments
            if (p->opr.op[1])
            {
                printf("Arguments detected\n");
                Node *argList = p->opr.op[1];
                int argCount = 0;

                // First count the arguments
                while (argList && argList->type == OPERATION && argList->opr.symbol == COMMA)
                {
                    argCount++;
                    printf("Counting argument %d\n", argCount);
                    argList = argList->opr.op[0];
                }
                if (argList)
                    argCount++; // Last argument

                printf("Total arguments: %d\n", argCount);

                // Push arguments in reverse order
                if (argCount > 0)
                {
                    Node *args[argCount];
                    argList = p->opr.op[1];

                    // Store arguments in array (in original order)
                    for (int i = argCount - 1; i >= 0; i--)
                    {
                        if (argList->type == OPERATION && argList->opr.symbol == COMMA)
                        {
                            args[i] = argList->opr.op[1];
                            printf("args[%d] = COMMA right operand\n", i);
                            argList = argList->opr.op[0];
                        }
                        else
                        {
                            args[i] = argList;
                            printf("args[%d] = last or single argument\n", i);
                        }
                    }
                    printf("Pushing arguments in reverse order\n");
                    fflush(stdout);

                    // Push in reverse order
                    for (int i = argCount - 1; i >= 0; i--)
                    {
                        printf("Writing to assembly arg[%d]\n", i);
                        write_to_assembly(args[i], p);
                    }
                }
            }
            else
            {
                printf("No arguments provided.\n");
            }

            printf("Calling function: %s\n", p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tcall\t%s\n", p->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            // return funcEntry->type;
            printf("CALL DONE\n");
            fflush(stdout);
            return funcEntry->type;
        }
        break;

        case COMMA:
            open_assembly_file();
            // change to be parameter
            write_to_assembly(p->opr.op[0]);
            write_to_assembly(p->opr.op[1]);
            break;
        case RETURN:
            printf("\tret\t\n");
            fprintf(assemblyOutFile, "\tret\t\n");
            fflush(assemblyOutFile);
            if (p->opr.op[0])
            {
                write_to_assembly(p->opr.op[0]);
            }
            printf("\tendproc\t\n");
            fprintf(assemblyOutFile, "\tendproc\t\n");
            fflush(assemblyOutFile);
            break;
        case ';':
            for (int i = 0; i < p->opr.nops; i++)
                write_to_assembly(p->opr.op[i], p, cont, brk);
            break;
        default:
            open_assembly_file();
            type1 = write_to_assembly(p->opr.op[0], p, cont, brk);
            type2 = write_to_assembly(p->opr.op[1], p, cont, brk);
            if (type1 != type2)
            {
                char msg[1024];
                sprintf(msg, "Semantic Error: Type mismatch in operation %s and '%s' %s",
                        get_data_type(type1),
                        p->opr.op[0]->id.name,
                        get_data_type(type2));
                yyerror(msg, p->line_number);
            }

            switch (p->opr.symbol)
            {
            case '+':
                printf("\tadd\t\n");
                fprintf(assemblyOutFile, "\tadd\t\n");
                fflush(assemblyOutFile);
                return type1;
            case '-':
                printf("\tsub\t\n");
                fprintf(assemblyOutFile, "\tsub\t\n");
                fflush(assemblyOutFile);
                return type1;
            case '*':
                printf("\tmul\t\n");
                fprintf(assemblyOutFile, "\tmul\t\n");
                fflush(assemblyOutFile);
                return type1;
            case '/':
                printf("\tdiv\t\n");
                fprintf(assemblyOutFile, "\tdiv\t\n");
                fflush(assemblyOutFile);
            case MOD:
                printf("\tmod\t\n");
                fprintf(assemblyOutFile, "\tmod\t\n");
                fflush(assemblyOutFile);
                return type1;
            case '<':
                printf("\tcompLT\t\n");
                fprintf(assemblyOutFile, "\tcompLT\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case '>':
                printf("\tcompGT\t\n");
                fprintf(assemblyOutFile, "\tcompGT\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case LTE:
                printf("\tcompLTE\t\n");
                fprintf(assemblyOutFile, "\tcompLTE\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case GTE:
                printf("\tcompGTE\t\n");
                fprintf(assemblyOutFile, "\tcompGTE\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case EQ:
                printf("\tcompEQ\t\n");
                fprintf(assemblyOutFile, "\tcompEQ\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case NEQ:
                printf("\tcompNEQ\t\n");
                fprintf(assemblyOutFile, "\tcompNEQ\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case AND:
                printf("\tcompAND\t\n");
                fprintf(assemblyOutFile, "\tcompAND\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            case OR:
                printf("\tcompOR\t\n");
                fprintf(assemblyOutFile, "\tcompOR\t\n");
                fflush(assemblyOutFile);
                return BOOL_TYPE;
            }
        }
    }
    return 0;
}