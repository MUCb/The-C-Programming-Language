#include<stdio.h>
int day_of_year(int year, int month, int day) ;

int month_day(int year, int yearday, int *pmonth, int *pday);


/*static char daytab1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char daytab2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[2] = {	daytab1, daytab2};*/

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main(){
	printf("%d\n", day_of_year(1,2,3));	

	return 0;
}



int day_of_year(int year, int month, int day) 
{		
	int i, leap;
	if(year < 0 || month < 0 || day < 0  || month > 12 || day > 31) return -1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += *(daytab[0] +(leap* 13) + i);
	return day;
}

/*int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	if(year < 0 || yearday > 366) return -1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 1;
}*/