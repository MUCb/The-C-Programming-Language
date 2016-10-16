#include<stdio.h>




int itoa (int n, char s[]);



int main(){

	char s[100]={'\0'};
	char s1[100]={'\0'};
	itoa(141,s);
	printf("%s\n", s);
	itoa(1,s1);
	printf("%s\n", s1);
	return 0;
}

int  itoa (int n, char s[])
{
	int i, sign;
	int level =0;

	//printf("level = %d\n",level );
	
	i = 0;
	
	if(n / 10)
		level = itoa(n/10, s); 
	s[level++] = n % 10 + '0';
	return level;
	
}

