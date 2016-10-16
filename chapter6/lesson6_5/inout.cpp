#include <stdio.h>
#include "inout.h"

#define BUFSIZE 100 

char buf[BUFSIZE];
int bufp;

int getch(void){
	return (bufp > 0) ? buf[ --bufp ] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE )
		printf("ungetch: to many characters\n");
	else 
		buf[bufp++] = c;
}