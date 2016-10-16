#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);
int test(void);
int main(){
	int a,f;
	a= 0 ;
	f= 0;
	//minprintf("asdqwe %d",12);
	scanf("%d\n%d",&a,&f);

	printf("a = %d\n f = %d",a,f);
	return 0;
}

void minprintf(char *fmt, ...){
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start (ap, fmt);
	for(p = fmt; *p; p++){
		if (*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
int test(void){
	int s=1;
	goto sd;
	return 123;
	sd:
	s =2;
}