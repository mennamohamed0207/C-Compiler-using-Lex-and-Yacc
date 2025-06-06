# C-Like Language Compiler

A robust compiler implementation for a C-like programming language, built using Lex and Yacc (Flex and Bison). This project demonstrates the implementation of a complete compiler pipeline, from lexical analysis to code generation.

## 🚀 Features

- **Lexical Analysis**: Token recognition and processing using Flex (lexer.l)
- **Syntax Analysis**: Grammar parsing using Yacc/Bison (parser.y)
- **Semantic Analysis**: Type checking and symbol table management
- **Code Generation**: Assembly code generation
- **Error Handling**: Comprehensive error detection and reporting
- **GUI Interface**: Python-based GUI for easier interaction (gui.py)

### Supported Language Features

- Multiple data types (int, float, char, bool, string)
- Control structures:
  - If-else statements
  - While loops
  - Do-while loops
  - For loops
  - Switch statements
- Function declarations and calls
- Variable scoping
- Increment/Decrement operations
- Expression evaluation
- Semantic error checking

## 📋 Prerequisites

- Flex (Lex)
- Bison (Yacc)
- C++ Compiler (g++ recommended)
- Python 3.x (for GUI)
- PowerShell (for running tests)

## 🛠️ Building the Project

1. Compile the lexer:

```sh
flex lexer.l
```

2. Compile the parser:

```sh
bison -d parser.y
```

3. Compile the compiler:

```sh
g++ -o mycompiler compiler.cpp lex.yy.c parser.tab.c
```

## 🎮 Usage

### Running the Compiler

1. Using the GUI:

```sh
python gui.py
```

2. Using the command line:

```sh
./mycompiler < input_file
```

### Running Tests

The project includes a comprehensive test suite. To run all tests:

```sh
.\run_tests.ps1
```

To save test results to a file while still showing errors in the terminal:

```sh
.\run_tests.ps1 >> results.txt
```

## 📁 Project Structure

- `lexer.l` - Lexical analyzer definition
- `parser.y` - Grammar and parser rules
- `compiler.cpp` - Main compiler implementation
- `compiler.h` - Header file with data structures and declarations
- `gui.py` - Graphical user interface
- `testcases/` - Directory containing test cases
- `outputs/` - Directory for compiler output
- `run_tests.ps1` - PowerShell script for running tests

### Test Files

The project includes various test files for different language features:

- Basic syntax tests (`assembly_test*.txt`)
- Symbol table tests (`symbol_table_test*.txt`)
- Error handling tests (`errors.txt`)
- Feature-specific tests (if, while, for, functions, etc.)

## 🔍 Error Handling

The compiler provides detailed error reporting for:

- Syntax errors
- Semantic errors
- Type mismatches
- Undefined variables
- Scope violations
- Function call errors

Errors are logged to `errors.txt` and displayed in the terminal.


---

_Built with ❤️ for Compiler Design Course_
