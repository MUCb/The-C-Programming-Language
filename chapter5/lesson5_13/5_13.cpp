#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int kol);

int main(int argc, char *argv[]){
	int n = 10;
	int nlines; 
	if(argc < 2) ;
	else { n = atoi(++argv[1]);}
	printf("%d\n",n );
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

		writelines(lineptr, nlines,n);
	}

	return 0;
}

#define MAXLEN 1000 /* максимальная длина строки */

int getline(char *, int);
char *alloc(int);

/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN]; 
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* убираем символ \n */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int kol){
	int i;
	for (i = nlines-kol; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

int getline(char s[], int lim){
	int i ,c;
	for(i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) 
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 10000 
static char allocbuf[ALLOCSIZE]; 
static char *allocp = allocbuf; 

char *alloc(int n) 
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n; 
		return allocp - n; 
	} 
	else 
		return 0;
}