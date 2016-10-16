#include <stdio.h>

bool strend(char s[], char t[]);

int main(){

	char str1[100] = "abcdef";
	char str2[100] = "def";
	
	printf("%d\n",strend(str1, str2) );

	return 0;
}

bool strend(char s[], char t[]){
	char *r = t;
	while (*s++ != '\0') 
		;
	while (*t++ != '\0') 
		;
	while (*--s == *--t && t != r) /* копируем t */
		;
	if (t == r) return 1;
	else return 0;

} 