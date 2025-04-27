#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <string>
#include <stdarg.h>

#include <iostream>

#include <vector>
#include <map>

using namespace std;

// Operators
#define ASSIGNMENT 1
#define STATEMENT_LIST 2
#define COMMA 3
#define CALL 4
// #define INTEGER 258   // For integer literals (e.g., 42)
// #define FLOAT 259     // For float literals (e.g., 3.14)
// #define STRING 260     // For string literals (e.g., "hello")
// #define CHARACTER 261 // For character literals (e.g., 'a')
// #define TRUE 262      // Boolean true
// #define FALSE 263     // Boolean false
// #define BOOL 264      // Boolean type specifier

// Data types

// #define INT_TYPE 270
// #define FLOAT_TYPE 271
// #define BOOL_TYPE 272
// #define STRING_TYPE 273
// #define VOID 266
// #define CHAR 275

#define SIZEOFNODE ((char *)&p->con - (char *)p)

typedef enum
{
    CONSTANT,
    VARIABLE,
    OPERATION
} NodeType;

struct ValueType
{

    union
    {
        int intVal;
        float floatVal;
        bool boolVal;
        char *strVal;
        char charVal;
    };
};

typedef struct
{
    ValueType value;
    int dataType;
} ConstantNode;
typedef struct
{
    char *name;
    int dataType;
    int qualifier;
} VariableNode;

typedef struct
{
    int symbol;
    int nops;
    struct NodeTypeTag *op[1];
} OperationNode;

typedef struct NodeTypeTag
{
    NodeType type;
    int line_number;
    union
    {
        ConstantNode con;
        VariableNode id;
        OperationNode opr;
    };
} Node;

// Symbol table structure
struct SymbolTable
{
    std::string name;
    int type;
    int symbolType;
    int scope;
    int timestamp;
    bool used;
    bool isInitialized;
    vector<int> paramTypes;
    bool isFunction;
    bool isParam;
    SymbolTable(std::string nm, int ty, int sty, int sc, int ts, bool init, bool func = false, bool param = false)
    {
        name = nm;
        type = ty;
        symbolType = sty;
        scope = sc;
        timestamp = ts;
        isFunction = func;
        isParam = param;
        used = false;
        isInitialized = init;
    }
};

// Global symbol table
extern vector<map<string, SymbolTable *>> symbol;
extern vector<SymbolTable *> symbolTable;
extern int level;
// Function declarations
extern Node *create_constant(int type, int line_number, int dataType, ...);
extern Node *create_identifier(char *name, int line_number, int dataType = 0, int qualifier = 0);
extern Node *create_operation(int oper, int line_number, int nops, ...);
extern void free_node(Node *p);
extern int execute_all(Node *p, int cont = -1, int brk = -1, int args = 0, ...);
extern void yyerror(const char *emsg=NULL, int line_number = 0);
extern void check_unused_variables();
extern void log_symbol_table(const char* filename);
extern void log_errors(int line, const char *msg,const char * filename);

#endif