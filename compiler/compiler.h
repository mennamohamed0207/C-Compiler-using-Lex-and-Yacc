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
#define INTEGER 258
#define FLOAT 259
#define STRING 260
#define CHARACTER 261
#define TRUE 262
#define FALSE 263
#define BOOL 264
#define IDENTIFIER 265

// Data types
#define INT_TYPE 270
#define FLOAT_TYPE 271
#define BOOL_TYPE 272
#define STRING_TYPE 273
#define VOID 274
#define CHAR 275

// Other tokens
#define CONST 280
#define DECLARE_ONLY 281
#define FUNCTION 282
#define PRINT 283
#define RETURN 284
#define BLOCK 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define DO 289
#define FOR 290
#define BREAK 291
#define CONTINUE 292
#define SWITCH 293
#define CASE 294
#define DEFAULT 295

// Operators
#define ASSIGNMENT 1
#define STATEMENT_LIST 2
#define COMMA 3
#define CALL 4
#define NEGATIVE 10
#define NOT 11
#define OR 12
#define AND 13
#define GREATER_EQUAL 14
#define LESS_EQUAL 15
#define EQUAL 16
#define NOT_EQUAL 17
#define LTE 18
#define GTE 19
#define EQ 20
#define NEQ 21

typedef enum { CONSTANT, IDENTIFIER, OPERATION } NodeType;

struct ValueType {
    union {
        int intVal;
        double floatVal;
        bool boolVal;
        char* strVal;
    };
};

typedef struct {
    ValueType value;
    int dataType;
} ConstantNode;
typedef struct {
    char* name;
    int dataType;
    int qualifier;
} IdentifierNode;

typedef struct {
    int symbol;
    int nops;
    struct NodeTypeTag* op[1];
} OperationNode;

typedef struct NodeTypeTag {
    NodeType type;
    union {
        ConstantNode con;
        IdentifierNode id;
        OperationNode opr;
    };
} Node;

// Symbol table structure
struct SymbolTable {
    std::string name;
    int type;
    int symbolType;
    int scope;
    int timestamp;
    bool used;
    bool isInitialized;
    bool isFunction;
    SymbolTable(std::string nm, int ty, int sty, int sc, int ts, bool init, bool func = false);
};

// Global symbol table
extern vector<map<string, SymbolTable*> > symbol;
extern vector<SymbolTable*> symbolTable;
extern int level;
// Function declarations
extern Node* create_constant(int type, int dataType, ...);
extern Node* create_identifier(char* name, int dataType = -1, int qualifier = -1);
extern Node* create_operation(int oper, int nops, ...);
extern void free_node(Node* p);
extern int execute_all(Node* p, int cont = -1, int brk = -1, int args = 0, ...);
extern void yyerror(const char* emsg);
extern void check_unused_variables();
extern void log_symbol_table();
extern void log_errors(int line, const char* msg);

#endif
