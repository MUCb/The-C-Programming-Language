#include <stdio.h>

void strcat (char s[], char t[]);

int main(){
	char str1[100] = "abc";
	char str2[100] = "def";
	strcat(str1, str2);
	printf("%s\n",str1 );
	return 0;
}


void strcat (char s[], char t[])
{
	while (*s++ != '\0') /* находим конец s */
		;
	s--;
	while (*s++ = *t++) /* копируем t */
		;
}