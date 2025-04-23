#include "compiler.h"
#include <stdio.h>
#include <stdarg.h>
#include <vector>
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

void open_assembly_file(const char *filename)
{
    assemblyOutFile = fopen(filename, "w");
    if (!assemblyOutFile)
    {
        fprintf(stderr, "Error opening assembly file: %s\n", filename);
        exit(1);
    }
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
                st->name.c_str(), get_data_type(st->type), st->symbolType == CONST ? "Constant" : "Variable", st->timestamp, st->scope, st->isInitialized == true ? "True" : "False", st->used == true ? "True" : "False", st->isFunction == true ? "True" : "False");
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
