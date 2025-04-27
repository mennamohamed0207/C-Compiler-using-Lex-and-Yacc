Write-Host "Generating compiler..."
flex lexer.l
bison -d parser.y 
g++ parser.tab.c lex.yy.c compiler.cpp -o mycompiler 2> error.txt 






# Write-Host "`n-----------------------------------Running test_function.c-----------------------------------"
# Get-Content testcases\test_function.c | .\mycompiler 
# Write-Host "`n-----------------------------------Running test_function.c-----------------------------------"
# Get-Content testcases\test_function_declare.c | .\mycompiler 




########Shaghalllllllllllll
# Write-Host "`n-----------------------------------Running test_types.c-----------------------------------"
# Get-Content testcases\test_types.c | .\mycompiler
# Write-Host "`n-----------------------------------Running test_while.c-----------------------------------"
# Get-Content testcases\test_while.c | .\mycompiler 
# Write-Host "`n-----------------------------------Running test_valid.c-----------------------------------"
# Get-Content testcases\test_valid.c | .\mycompiler 
# Write-Host "-----------------------------------Running test_switch.c-----------------------------------"
# Get-Content testcases\test_switch.c | .\mycompiler
# Write-Host "`n-----------------------------------Running test_inc_dec.c-----------------------------------"
# Get-Content testcases\test_inc_dec.c | .\mycompiler 
# Write-Host "`n-----------------------------------Running test_dowhile.c-----------------------------------"
# Get-Content testcases\test_dowhile.c | .\mycompiler 
Write-Host "`n-----------------------------------Running test_if.c-----------------------------------"
Get-Content testcases\test_if.c | .\mycompiler 
# Write-Host "`n-----------------------------------Running test_for.c-----------------------------------"
# Get-Content testcases\test_for.c | .\mycompiler 





# Write-Host "`n-----------------------------------Running test_expression.c-----------------------------------"
# Get-Content testcases\test_expr.c | .\mycompiler 

# Write-Host "`n-----------------------------------Running test_error.c-----------------------------------"
# Get-Content testcases\test_error.c | .\mycompiler 
