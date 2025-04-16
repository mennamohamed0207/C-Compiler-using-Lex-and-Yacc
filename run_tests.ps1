Write-Host "Generating compiler..."
flex lexer.l
bison -d parser.y 
gcc parser.tab.c lex.yy.c -o compiler


Write-Host "-----------------------------------Running test_switch.c-----------------------------------"
Get-Content testcases\test_switch.c | .\compiler

Write-Host "`n-----------------------------------Running test_valid.c-----------------------------------"
Get-Content testcases\test_valid.c | .\compiler 

Write-Host "`n-----------------------------------Running test_types.c-----------------------------------"
Get-Content testcases\test_types.c | .\compiler

Write-Host "`n-----------------------------------Running test_error.c-----------------------------------"
Get-Content testcases\test_error.c | .\compiler 

Write-Host "`n-----------------------------------Running test_expression.c-----------------------------------"
Get-Content testcases\test_expr.c | .\compiler 

Write-Host "`n-----------------------------------Running test_if.c-----------------------------------"
Get-Content testcases\test_if.c | .\compiler 

Write-Host "`n-----------------------------------Running test_while.c-----------------------------------"
Get-Content testcases\test_while.c | .\compiler 

Write-Host "`n-----------------------------------Running test_for.c-----------------------------------"
Get-Content testcases\test_for.c | .\compiler 

Write-Host "`n-----------------------------------Running test_dowhile.c-----------------------------------"
Get-Content testcases\test_dowhile.c | .\compiler 

Write-Host "`n-----------------------------------Running test_function.c-----------------------------------"
Get-Content testcases\test_function.c | .\compiler 







