/*program detab */
#include <stdio.h>
#include <stdlib.h>

#define STOP 4

int main(int argc, char *argv[]){
	char c;
	int j,i;

	j=0;
	if(argc < 2) printf("Используйте в find образец\n");
	else
	while((c = getchar()) != EOF){
		if(c == '\t'){
			for(i = j; i < atoi(argv[1]); i++){
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
					if(j == atoi(argv[1])) j = 0;
				}
	}
	return 0;
}