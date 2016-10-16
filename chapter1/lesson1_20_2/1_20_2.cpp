/*program detab */
#include<stdio.h>

#define STOP 4

int main(){
	char c;
	int j,i;

	j=0;

	while((c = getchar()) != EOF){
		if(c == '\t'){
			for(i = j; i < STOP; i++){
				putchar(' ');
			}
			j=0;
		}
			else if(c == '\n'){
				j=0;
				putchar(c);
			}
				else {
					putchar(c);
					j++; 
					if(j == STOP) j = 0;
				}
	}
	return 0;
}