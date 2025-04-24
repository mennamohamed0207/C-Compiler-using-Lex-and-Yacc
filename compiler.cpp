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
    printf("Entering scope level %d\n", level); // Debug
}

void remove_block_scope()
{
    if (level > 0)
    {                                              // Never remove global scope
        printf("Leaving scope level %d\n", level); // Debug
        symbol.pop_back();
        level--;
    }
}

void check_unused_variables()
{
    // Create an iterator for the symbol table
    std::map<std::string, SymbolTable *>::iterator it;
    std::string unused_variables = "";
    for (it = symbol[level].begin(); it != symbol[level].end(); it++)
    {
        if (it->second->used == false && it->second->isFunction == false)
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

    // Search from current scope outward
    for (int i = level; i >= 0; i--)
    {
        if (symbol[i].find(p->id.name) != symbol[i].end())
        {
            SymbolTable *entry = symbol[i][p->id.name];
            if (!isRHS && !entry->isInitialized && !entry->isFunction)
            {
                yyerror("Variable used before initialization");
            }
            entry->used = true;
            return entry;
        }
    }

    char errorMsg[1024];
    sprintf(errorMsg, "Variable '%s' not declared", p->id.name);
    yyerror(errorMsg);
    return NULL;
}
// SymbolTable *declare_variable(Node *p, bool isRHS = false)
// {
//     if (p->type != VARIABLE)
//         return NULL;
//     if (p->id.dataType == -1)
//     {
//         return check_variable(p, isRHS);
//     }
//     bool isConst = (p->id.qualifier == 1);

//     if (symbol[level].find(p->id.name) != symbol[level].end())
//     {
//         char errorMsg[1024];
//         sprintf(errorMsg, "Semantic Error: variable '%s' already declared in this scope", p->id.name);
//         yyerror(errorMsg);
//         return NULL;
//     }
//     symbol[level][p->id.name] = new SymbolTable(
//         strdup(p->id.name),
//         p->id.dataType,
//         isConst ? CONSTANT : VARIABLE, // Set symbolType properly
//         level,
//         timestep++,
//         false);
//     symbolTable.push_back(symbol[level][p->id.name]);
//     return symbol[level][p->id.name];
// }
SymbolTable *declare_variable(Node *p, bool isRHS = false) {
    if (p->type != VARIABLE) return NULL;

    // Check if already declared in current scope
    if (symbol[level].find(p->id.name) != symbol[level].end()) {
        if (!isRHS) { // Only error if not RHS usage
            char errorMsg[1024];
            sprintf(errorMsg, "Variable '%s' already declared in this scope", p->id.name);
            yyerror(errorMsg);
            return NULL;
        }
        return symbol[level][p->id.name];
    }

    // Create new entry
    SymbolTable *entry = new SymbolTable(
        p->id.name,
        p->id.dataType,
        p->id.qualifier == 1 ? CONSTANT : VARIABLE,
        level,
        timestep++,
        isRHS); // Mark as initialized if this is a declaration with initialization
    
    symbol[level][p->id.name] = entry;
    symbolTable.push_back(entry);
    return entry;
}
void log_symbol_table()
{
    printf("Loggin symbol table\n");
    FILE *symbolTableFile = fopen("symbol_table.txt", "w");
    if (symbolTableFile == NULL)
    {
        printf("Error opening symbol table file: symbol_table.txt\n");
        return;
    }
    fprintf(symbolTableFile, "Name,\tDataType,\tQualifier,\tTimeStep,\tScope,\tInitialized,\tUsed,\t Function\n");
    fflush(symbolTableFile);
    for (int i = 0; i < symbolTable.size(); i++)
    {
        SymbolTable *st = symbolTable[i];
        fprintf(symbolTableFile, "%s,\t\t%s, \t\t%s, \t\t%d, \t\t%d, \t\t%s, \t\t%s, \t\t%s \n",
                st->name.c_str(), get_data_type(st->type), st->symbolType == 1 ? "Constant" : "Variable", st->timestamp, st->scope, st->isInitialized == true ? "True" : "False", st->used == true ? "True" : "False", st->isFunction == true ? "True" : "False");
        fflush(symbolTableFile);
    }
    fclose(symbolTableFile);
}
void log_errors(int line, const char *msg)
{
    FILE *errorFile = fopen("errors.txt", "a");
    if (errorFile == NULL)
    {
        fprintf(stderr, "Error opening error file: errors.txt\n");
        fflush(stderr);
    }

    fprintf(errorFile, "Error at line %d: %s\n", line, msg);
    // fclose(errorFile);
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
        symoblTableEntry = check_variable(p);
        if (!symoblTableEntry)
        {
            char errorMsg[1024];
            sprintf(errorMsg, "Semantic Error: variable '%s' not declared", p->id.name);
            yyerror(errorMsg);
            return 0;
        }
        printf("\tpush\t%s\n", p->id.name);
        fprintf(assemblyOutFile, "\tpush\t%s\n", p->id.name);
        fflush(assemblyOutFile);
        return symoblTableEntry->type;

    case OPERATION:
        // printf("imppppppppppppppppppppppppppppppppportant%s\n", p->opr.symbol);
        // fflush(stdout);
        switch (p->opr.symbol)
        {
        case DECLARATION:
        {
            SymbolTable *entry = declare_variable(p->opr.op[0], true);
            if (entry != NULL)
            { // Only write to assembly if declaration was successful
                printf("\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
                open_assembly_file();
                fprintf(assemblyOutFile, "\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
                fflush(assemblyOutFile);
            }
        }
        break;
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
                yyerror("while condition must be a boolean expression");
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
                yyerror("if condition must be a boolean expression");
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
            add_block_scope(); // Create scope for entire FOR

            // Process initialization
            write_to_assembly(p->opr.op[0], p);

            printf("L%03d:\n", l1 = label++);
            // Process condition
            type1 = write_to_assembly(p->opr.op[1], p);
            if (type1 != BOOL_TYPE)
                yyerror("for condition must be boolean");
            printf("\tjz\tL%03d\n", l2 = label++);

            // Process body
            write_to_assembly(p->opr.op[3], p, l3 = label++, l2);

            printf("L%03d:\n", l3);
            // Process increment
            write_to_assembly(p->opr.op[2], p);

            printf("\tjmp\tL%03d\n", l1);
            printf("L%03d:\n", l2);

            remove_block_scope(); // Exit FOR scope
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
                yyerror("switch variable must be a variable");
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
                    break;
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
                yyerror("do while condition must be a boolean expression");
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
            // Put the entire case in a block
            open_assembly_file();

            // First check if LHS is valid
            if (p->opr.op[0]->type != VARIABLE)
            {
                yyerror("Left side of assignment must be a variable");
                return 0;
            }

            // Check for constant assignment
            SymbolTable *lhs = check_variable(p->opr.op[0]);
            if (lhs && lhs->symbolType == CONSTANT)
            {
                char errorMsg[1024];
                sprintf(errorMsg, "Cannot assign to constant variable '%s'",
                        p->opr.op[0]->id.name);
                yyerror(errorMsg);
                return 0;
            }

            // Process RHS
            int rhs_type = write_to_assembly(p->opr.op[1], p);

            // Type checking
            if (rhs_type != lhs->type)
            {
                char msg[1024];
                sprintf(msg, "Type mismatch: cannot assign %s to %s",
                        get_data_type(rhs_type),
                        get_data_type(lhs->type));
                yyerror(msg);
                return 0;
            }

            // Generate assignment code
            printf("\tpop %s\t%s\n", get_data_type(lhs->type), p->opr.op[0]->id.name);
            return lhs->type;
        } // End of case block
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
        case BREAK:
            open_assembly_file();
            if (brk == -1)
            {
                yyerror("Semantic ERROR: No loop to Break from");
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
                yyerror("Semantic ERROR: No loop to Continue from");
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
                                        parent->opr.symbol == FOR)));

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

            break;
        }
        case FUNCTION:
            // Properly handle function declaration
            symoblTableEntry = declare_variable(p->opr.op[0]->opr.op[0], true);
            if (!symoblTableEntry)
            {
                yyerror("Failed to declare function");
                break;
            }
            symoblTableEntry->isFunction = true;

            // Start function in assembly
            fprintf(assemblyOutFile, "\tproc\t%s\n", p->opr.op[0]->opr.op[0]->id.name);

            // Handle parameters (currently in p->opr.op[1])
            if (p->opr.op[1])
            {
                // Need to properly process parameters here
                // Currently just writing them without proper handling
                write_to_assembly(p->opr.op[1], p);
            }

            // Function body
            write_to_assembly(p->opr.op[2], p);

            // Handle return statement if present
            if (p->opr.op[3])
            {
                write_to_assembly(p->opr.op[3], p);
            }

            fprintf(assemblyOutFile, "\tendproc\t\n");
            remove_block_scope();
            break;
        case CALL:
            open_assembly_file();
            write_to_assembly(p->opr.op[1]);
            printf("\tcall\t%s\n", p->opr.op[0]->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tcall\t%s\n", p->opr.op[0]->opr.op[0]->id.name);
            fflush(assemblyOutFile);
            return 274;
            break;
        case COMMA:
            open_assembly_file();
            write_to_assembly(p->opr.op[0]);
            write_to_assembly(p->opr.op[1]);
            break;
        case RETURN:
            printf("\tret\t\n");
            fprintf(assemblyOutFile, "\tret\t\n");
            fflush(assemblyOutFile);

            write_to_assembly(p->opr.op[0]);
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
                yyerror(msg);
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
            case POST_DEC:
                printf("\tdec\t%s\n", p->opr.op[0]->id.name);
                fprintf(assemblyOutFile, "\tdec\t%s\n", p->opr.op[0]->id.name);
                fflush(assemblyOutFile);
                return type1;
            case POST_INC:
                printf("\tinc\t%s\n", p->opr.op[0]->id.name);
                fprintf(assemblyOutFile, "\tinc\t%s\n", p->opr.op[0]->id.name);
                fflush(assemblyOutFile);
                return type1;
            }
        }
    }
    return 0;
}
