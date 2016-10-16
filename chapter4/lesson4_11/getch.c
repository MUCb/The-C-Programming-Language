#include<stdio.h>

#define BUFSIZE 100


char buf[BUFSIZE]; //буфер для ungetch
int bufp = 0;      //свободная позицыя в буфере

int getch(void){
	return (bufp == 1 ) ? buf[0] : getchar();
}

void ungetch(int c){
	if (bufp >= 1)
		printf("to many characters\n");
	else 
		buf[0] = c;
}

void ungets(char s[]){
	int i = 0;
	while (s[i] != '\0'){
		ungetch(s[i++]);
	}
}