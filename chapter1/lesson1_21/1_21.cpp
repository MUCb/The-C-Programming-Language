/*program entab*/
#include<stdio.h>

#define TAB 5

int main(){

	char c;
	int count=0;
	int i=0;

	while((c = getchar()) != EOF){
		
		if(c == ' ') {
			count++;
			if(count == TAB){
				putchar('\t');
				count = 0;
			}
		}
		else{
			if (count != 0){
				for(i = 0; i < count; i++) putchar(' ');
				count = 0;
			}
			putchar(c);		
		}
	}

	return 0;
}