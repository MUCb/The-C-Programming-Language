#include<stdio.h>

#define MAXLINE 10000

void itoa (int n, char s[]);


int main(){

	char s[100]={'\0'};
	char s1[100]={'\0'};
	itoa(141,s);
	printf("%s\n", s);
	itoa(1,s1);
	printf("%s\n", s1);
	return 0;
}

void reverse(char s[]){
	char copy[MAXLINE] = {0};
	int i=0;
	int n=0;
	int j=0;



	while ( s[i] != '\0') 
		i++;
	n=i;
	
	
	//printf("i=%c\n",s[i-1] );

	for(j=0; j <= n; j++){
		--i;
		copy[j]=s[i];
		
	}
	for(j=0; j <= n; j++){
		s[j]=copy[j];
		//printf("%s\n",s[j] );
	}
	
	//s[j]='\n';
	s[j]='\0';
}