#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop( char[] );
void push( double );
double pop( void );
double ost(double c, double f);
double see_top(void);
void duplicate_top(void);
void interchange(void);
void clear(void);

/*калькулятор с обратной польской записью*/

int main(){
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF){
		switch(type){
		case NUMBER : 
			push(atof(s));
			break;
		case '+' :
			push(pop() + pop());
			break;
		case '*' :
			push(pop() * pop());
			break;
		case '-' :
			op2 = pop();
			push(pop() - op2);
			break;
		case '%' :
			op2 = pop();
			push(ost(pop(),op2));
			break;
		case '/' :
			op2 = pop();
			if (op2 != 0.0) 
				push(pop() / op2);
			else 
				printf("error null number\n");
			break;
		case 's' :
			push(sin(pop()));
			break;	
		case 'e' :
			push(exp(pop()));
			break;
		case '^' :
			op2 = pop();
			push(pow(pop(),op2));
			break;			
		case '\n' :
			printf("\t%.8g\n",pop() );
			break;
		default : 
			printf("error unknown opration %s\n", s);
			break;
		}
	}
	return 0;
}





#define MAVAL 100

int sp = 0; // свободная позиция в стеке
double val[MAVAL]; //стек
duble last =0;


void push(double f){
	if (sp < MAVAL)
		val[sp++] = f;
	else
		printf("error stack is full, %g can't be written\n", f);
}



double pop(void){
	if (sp > 0 ){
		last = val[--sp];
		return last;
	}
	else {
		printf("error: stack is empty\n");
		last = 0;
		return 0.0;
	}
}

double ost(double c, double f){

	while (c > f) 
		c -= f;
	return c;
}

double see_top(void){
	if (sp > 0 ){
		return val[sp-1];
	}
	return -1.0;
}

void duplicate_top(void){
	if (sp > 0 ){
		val[sp] = val[sp-1];
		sp++; 
	}
}

void interchange(void){
	double b = 0;
	if (sp > 1 ){
		b = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = b;
	}
}

void clear(void){
	sp = 0;
}



#include<ctype.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);


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


#define BUFSIZE 100

char buf[BUFSIZE]; //буфер для ungetch
int bufp = 0;      //свободная позицыя в буфере

int getch(void){
	return (bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("to many characters\n");
	else 
		buf[bufp++] = c;
}

void ungets(char s[]){
	int i = 0;
	while (s[i] != '\0'){
		ungetch(s[i++]);
	}
}