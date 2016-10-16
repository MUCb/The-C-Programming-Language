#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int getop(char s[]){
	int i, c;
	int sign = 1;
	
	while((s[0] = c = getch()) == ' ' || c == '\t' )
		;
	i = 0;
	if (c == '-' && (!isdigit(s[++i] = c = getch()))) {
		//printf("ne\n" );
		ungetch(c);
		c = '-';
		i--;
	}
	 
	 

	s[i+1] = '\0';
	//printf("s = %s\n",s );

	if (!isdigit(c) && c != '.'){
		//printf ("dd= %c\n",c);
		return c;// not number;
	}
	//i = 0;
	if (isdigit(c)){
		while ( isdigit(s[++i] = c = getch() ) )
			;
	}
	//printf("s = %s\n",s );
	if (c == '.')
		while ( isdigit(s[++i] = c = getch() ) )
			;
	s[i] = '\0';

	if (c != EOF )
		ungetch(c);
	//printf("s = %s\n",s );
	//printf("number\n");
	return NUMBER;
}

