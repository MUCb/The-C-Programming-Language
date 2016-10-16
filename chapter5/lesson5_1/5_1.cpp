#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getint(int *pn);

int main(){
	int n;
	//getint(&n);
	
	int array[SIZE];
	for (n = 0; n < SIZE && getint (&array[n]) != EOF; n++)
		printf("n = %d\n", array[n]);
	return 0;
}


int getch (void);
void ungetch (int);
/* getint: читает следующее целое из ввода в *pn */

int getint(int *pn){
	int c, sign;
	while (isspace(c = getch()))
		; /* пропуск символов-разделителей */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); /* не число */
		return 0;
	}
	sign = (c == '-' ) ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if(isdigit(c)){
		for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0' ) ;
	}
	else {ungetch(c); getint(pn);} 
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

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
