int decimal_value=0;

%%
"ONE" 	{decimal_value+=1;}
"TWO" 	{decimal_value+=2;}
"THREE" {decimal_value+=3;}
"FOUR" 	{decimal_value+=4;}
"FIVE" 	{decimal_value+=5;}
"SIX" 	{decimal_value+=6;}
"SEVEN" {decimal_value+=7;}
"EIGHT" {decimal_value+=8;}
"NINE" 	{decimal_value+=9;}
"TEN" 	{decimal_value+=10;}

"ELEVEN" 	{decimal_value+=11;}
"TWELVE"  	{decimal_value+=12;}
"THIRTEEN"    	{decimal_value+=13;}
"FOURTEEN"    	{decimal_value+=14;}
"FIFTEEN"	{decimal_value+=15;}
"SIXTEEN"     	{decimal_value+=16;}
"SEVENTEEN"	{decimal_value+=17;}
"EIGHTEEN"	{decimal_value+=18;}
"NINETEEN"	{decimal_value+=19;}

"TWENTY"	{decimal_value+=20;}
"THIRTY"    	{decimal_value+=30;}
"FORTY"     	{decimal_value+=40;}
"FIFTY"     	{decimal_value+=50;}
"SIXTY"     	{decimal_value+=60;}
"SEVENTY"   	{decimal_value+=70;}
"EIGHTY"    	{decimal_value+=80;}
"NINETY"    	{decimal_value+=90;}

"HUNDRED"   	{decimal_value*=100;}
%%

int main(){
	printf("Enter\n");
    	yylex();
    	printf("decimal_value = %d\n", decimal_value);
    	return 0;
}
int yywrap(){return(1);}
