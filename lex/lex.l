%{
#include <stdio.h>
%}
%%
#.* {printf("Pre-Processor directive");}

if|else|while|for|do|break|continue|int|double|float|switch|float|char|return   {printf("Keyword");}

[a-z]([a-z]|[0-9])*    {printf("Identifier");}

[0-9]*        {printf("Number");}

"+"|"-"|"*"|"/"|"<="|">="|"!="|"=="|"<"|">"|"="    {printf("Operator");}

"//".*" "* {printf("Comment");}

.*    {printf("Invalid");}
%%

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	yylex();
    return 0; 
}
int yywrap(){}