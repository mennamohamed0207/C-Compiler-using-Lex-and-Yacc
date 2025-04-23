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
    assemblyOutFile = fopen("assembly.txt", "w");
    if (!assemblyOutFile)
    {
        fprintf(stderr, "Error opening assembly file: assembly.txt\n");
        exit(1);
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
    std::map<std::string, SymbolTable *>::iterator it;
    std::string unused_variables = "";
    for (it = symbol[level].begin(); it != symbol[level].end(); it++)
    {
        if (it->second->used == false)
        {
            unused_variables += it->second->name + ", ";
        }
    }
    if (unused_variables.length() > 0)
    {
        yyerror(("Unused variables:" + unused_variables).c_str());
    }
}
/*
type:
    INT_TYPE
    | FLOAT_TYPE
    | CHAR_TYPE
    | VOID
    | BOOL_TYPE
    | STRING_TYPE
    ;
*/
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
    case VOID:
        return "void";
    default:
        return "";
    }
}
SymbolTable *get_function_variable(Node *p)
{
    for (int i = level; i >= 0; i--)
    {
        if (symbol[i].find(p->id.name) != symbol[i].end())
        {
            SymbolTable *entry = symbol[i][p->id.name];
            if (entry->isFunction == true)
            {
                printf("www %s\n", entry->name);
                return entry;
            }
        }
    }
    return NULL;
}
SymbolTable *check_variable(Node *p, bool isRHS = false)
{
    if (p->type != VARIABLE)
        return NULL;
    for (int i = level; i >= 0; i--)
    {
        if (symbol[i].find(p->id.name) != symbol[i].end())
        {
            SymbolTable *entry = symbol[i][p->id.name];

            // Error as the variable is already declared
            if (isRHS && entry->type == CONSTANT)
            {
                char errorMsg[1024];
                sprintf(errorMsg, "Semantic Error: can't assign values to constant variable '%s'", p->id.name);
                yyerror(errorMsg);
                return NULL;
            }
            if (!isRHS && entry->isFunction == false && entry->isInitialized == false)
            {
                char errorMsg[1024];
                sprintf(errorMsg, "Semantic Error: variable '%s' must be initialized before use", p->id.name);
                yyerror(errorMsg);
                return NULL;
            }
            symbol[i][p->id.name]->used = true;
            return symbol[i][p->id.name];
        }
    }
    return NULL;
}
SymbolTable *declare_variable(Node *p, bool isRHS = false)
{
    if (p->type != VARIABLE)
        return NULL;
    if (p->id.dataType == -1)
    {
        return check_variable(p, isRHS);
    }
    if (symbol[level].find(p->id.name) != symbol[level].end())
    {
        char errorMsg[1024];
        sprintf(errorMsg, "Semantic Error: variable '%s' already declared in this scope", p->id.name);
        yyerror(errorMsg);
        return NULL;
    }
    symbol[level][p->id.name] = new SymbolTable(strdup(p->id.name), p->id.dataType, p->id.qualifier, level, timestep++, false);
    symbolTable.push_back(symbol[level][p->id.name]);
    return symbol[level][p->id.name];
}
void log_symbol_table()
{
    FILE *symbolTableFile = fopen("symbol_table.txt", "w");
    if (!symbolTableFile)
    {
        fprintf(stderr, "Error opening symbol table file: symbol_table.txt\n");
        exit(1);
    }
    fprintf(symbolTableFile, "Name,\tDataType,\tQualifier,\tTimeStep,\tScope,\tInitialized,\tUsed,\t Function\n");
    for (int i = 0; i < symbolTable.size(); i++)
    {
        SymbolTable *st = symbolTable[i];
        fprintf(symbolTableFile, "%s,\t\t%s, \t\t%s, \t\t%d, \t\t%d, \t\t%s, \t\t%s, \t\t%s \n",
                st->name.c_str(), get_data_type(st->type), st->symbolType == 1 ? "Constant" : "Variable", st->timestamp, st->scope, st->isInitialized == true ? "True" : "False", st->used == true ? "True" : "False", st->isFunction == true ? "True" : "False");
        free(st);
    }
    fclose(symbolTableFile);
}
void log_errors(int line, const char *msg)
{
    FILE *errorFile = fopen("errors.txt", "a");
    if (!errorFile)
    {
        fprintf(stderr, "Error opening error file: errors.txt\n");
        exit(1);
    }
    fprintf(errorFile, "Error at line %d: %s\n", line, msg);
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
int write_to_assembly(Node *p, int cont = -1, int brk = -1, int args = 0, ...)
{
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
    // switch (p->type)
    // {
    // case CONSTANT:
    //     switch (p->con.dataType)
    //     {
    //     case INT_TYPE:
    //     printf("\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
    //     open_assembly_file();
    //     fprintf(assemblyOutFile, "\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
    //     break;
    //     case BOOL_TYPE:
    //     case FLOAT_TYPE:
    //     case STRING_TYPE:
    //     }
    // }
}
