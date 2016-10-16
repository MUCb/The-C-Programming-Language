#include<stdio.h>

#define IN 1
#define OUT 0

void main(){
	int i, c, count, flag;
	flag=IN;
	count=0;
	while((c=getchar()) != EOF){
		if(c == '\n' || c == '\t' || c == ' '){
			flag = OUT;
			for (int i = 0; i < count; ++i) printf("#");
			printf("\n");
			count=0;
		}
		else if(flag == OUT){
			flag = IN;
			++count;
		}
		else {
			++count;
		}
	}
}