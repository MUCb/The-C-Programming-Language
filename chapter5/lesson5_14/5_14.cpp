#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 

char *lineptr[MAXLINES]; 

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,int (*comp)(void *, void *));
int numcmp(char *s, char *s1);


int main(int argc, char *argv[])
{
	int nlines; 
	int numeric = 0; 
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
			qsort((void **) lineptr, 0, nlines-1,( int (*)(void*, void*) ) (numeric? numcmp:strcmp));
			writelines(lineptr, nlines);
			return 0;
	} else {
		printf("Введено слишком много строк\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right) /* ничего не делается, если */
		return; /* в массиве менее двух элементов */
	swap(v, left, (left + right )/2); 
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

#include <stdlib.h>
/* numcmp: сравнивает s1 и s2 как числа */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{ 
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}