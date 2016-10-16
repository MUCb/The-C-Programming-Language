#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 
#define MAXLINES 5000 


char *lineptr[MAXLINES]; 
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
char mas[MAXLINES*MAXLEN];

int main(){
	int nlines; 
	

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} 
	else {
		printf("ошибка: слишком много строк\n");
		return 1;
	}
}



int getline(char line[],int  maxline);
char *alloc(int n);

int readlines(char *lineptr[], int maxlines){

	int len, nlines, len_z;
	char *p, line[MAXLEN]; 
	nlines = 0;
	len_z = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines /*|| (p = alloc(len)) == NULL*/)
			return -1;
		else {
			line[len-1] = '\0'; 

			strcpy(&mas[len_z], line);
			
			 //printf("%s\n", &mas[nlines][0]);
			 lineptr[nlines] = &mas[len_z];
			 len_z += len;
			 nlines++;
			// printf("%s\n", &mas[nlines-1][0]);
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void swap(char *v[], int i, int j);

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right) 
		return; 
	swap(v, left, (left+ right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
	swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
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