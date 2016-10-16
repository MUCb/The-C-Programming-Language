#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXOP 100

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




