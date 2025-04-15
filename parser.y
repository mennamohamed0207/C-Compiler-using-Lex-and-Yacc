/* ... definitions ...  */
%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

/* %token VARIABLE */

%% 
/* ... rules ...  */
%% 
/* ... subroutines ... */

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}