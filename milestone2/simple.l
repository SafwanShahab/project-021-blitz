%{
#include <stdio.h>
%}

%%
.  { printf("TOKEN: %s\n", yytext); }
%%
int yywrap() {
    return 1;
}
