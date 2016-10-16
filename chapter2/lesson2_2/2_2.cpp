#include<stdio.h>

int main(){
	int i =0;
	int c= 0;
	int lim = 20;
	for(i = 0; i < lim; i++){
			c = getchar();
			if (c == '\n') break;
			if (c == EOF ) break;
			putchar(c);
 	}

	return 0;
}