#include <stdio.h>

void strncpy (char s[], char t[], int n);
void strncat (char s[], char t[], int n);
int strncmp(char *s, char *t, int n);

int main(){
	char str1[100] = "ac";
	char str2[100] = "abc";
	//strncpy(str1, str2,2);
	//strncat(str1, str2,2);
	
	//printf("%s\n",str1 );
	printf("%d\n",strncmp(str1, str2,2) );
	return 0;
}

void strncpy(char *s, char *t, int n)
{
	while ((*s++ = *t++) &&(--n) )
		;
	//if(n == 0) *s = '\0';
}

void strncat (char s[], char t[], int n)
{
	while (*s++ != '\0') 
		;
	s--;
	while ((*s++ = *t++)&&(--n) )
		;
}

int strncmp(char *s, char *t, int n)
{
	for ( ; (*s == *t) && (--n) ; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
} 