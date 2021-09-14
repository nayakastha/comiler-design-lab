%%
[a-zA-Z_][a-zA-Z0-9_]* 	{printf("is a valid identifier\n");}
.*			{printf("is not a valid identifier\n");}
%%

int main(){
	printf("Enter\n");
    	yylex();
    	return 0;
}
int yywrap(){return(1);}
