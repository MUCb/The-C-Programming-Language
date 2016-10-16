#include<stdio.h>

#define IN 1
#define OUT 0

void main(){
	int flag,c;
	flag=IN;

	while((c=getchar()) != EOF){
		while(c == '\t' || c == ' ' || c == '\n') {
			flag = OUT;
			c = getchar();
		}
		if(flag == OUT){
			putchar('\n');
			putchar(c);
			flag = IN;
		}
		else if(flag == IN){
			putchar(c);
		}
	}
}