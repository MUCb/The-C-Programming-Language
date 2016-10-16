#include<stdio.h>

#define MAXLINE 1000 
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; 

int main() {
char line[MAXLINE] = {'q','o','u','l','d','a','s','o','u','l','d','\0'};
int found = 0;
int d = 0;

d = strindex(line, pattern);
printf ("%s", line);
printf("d = %d\n", d);
found++;
return found;
}

int strindex(char s[], char t[]){
		int i, j, k;
		int res = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
		//return i;
			res = i;
	}
	return res;
}

