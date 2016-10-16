#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getdouble(double *pn);

int main(){
	int n;
	//getint(&n);
	
	double array[SIZE];
	for (n = 0; n < SIZE && getdouble (&array[n]) != EOF; n++)
		printf("n = %f\n", array[n]);
	return 0;
}


int getch (void);
void ungetch (int);
/* getint: читает следующее целое из ввода в *pn */

int getdouble(double *pn){
	int c, sign;
	double power;
	power = 1.0;
	//printf("p=%f\n", power);
	while (isspace(c = getch()))
		; /* пропуск символов-разделителей */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c); /* не число */
		return 0;
	}
	sign = (c == '-' ) ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	if(isdigit(c) || c == '.'){
		for (*pn = 0.0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0' ) ;
		//printf("f1=%f\n", *pn);
		if(c == '.') c = getch();
		for (power = 1.0; isdigit(c); c = getch()) {
			*pn = 10.0 * *pn + (c - '0');
			power *= 10.0;
		}
		//printf("f=%f\n", *pn);
	}
	else {ungetch(c); getdouble(pn);} 
	
	printf("p=%f\n", power);
	*pn *= sign ;
	printf("f=%f\n", *pn);
	*pn /=  power;
	printf("f=%f\n", *pn);
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
