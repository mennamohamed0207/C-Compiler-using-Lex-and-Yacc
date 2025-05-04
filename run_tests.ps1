# Step 1: Generate the compiler
Write-Host "Generating compiler..."
flex lexer.l
bison -d parser.y 
g++ parser.tab.c lex.yy.c compiler.cpp -o mycompiler 2> error.txt 

# Step 2: Define your test files
$testFiles = @(
    "test_for.c",
    "test_expr.c",
    "test_error.c",
    "test_if.c",
    "test_dowhile.c",
    "test_scopes.c",
    "test_semantic_errors.c",
    "test_types.c",
    "test_valid.c",
    "test_function_declare.c",
    "test_while.c",
    "test_function.c",
    "test_switch.c",
    "test_inc_dec.c"
)

$deliver_files=@(
    "test1.txt",
    "test2.txt",
    "test3.txt",
    "test4.txt",
    "test5.txt"
)

# Step 3: Run each test
foreach ($testFile in $testFiles) {
    $testName = [System.IO.Path]::GetFileNameWithoutExtension($testFile)

    Write-Host "`n-----------------------------------Running $testFile-----------------------------------"

    # Pipe the content and pass the test name to the compiler
    # Get-Content ".\testcases\$testFile" | ./mycompiler.exe $testName
    Get-Content ".\testcases\$testFile" | ./mycompiler.exe $testName
}
