#include<stdio.h>
#include "calc.h"
#define MAVAL 100

int sp = 0; // свободная позиция в стеке
double val[MAVAL]; //стек
double last =0;


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