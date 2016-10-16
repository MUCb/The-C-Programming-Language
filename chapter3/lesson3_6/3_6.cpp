#include<stdio.h.>
#include<string.h>
#define MAXLINE 10000

void itoa (int n, char s[], int m);

void reverse(char s[]);

int main(){
	char s[100] = {'\0'};
	int n = 646;
	itoa(n, s,10);
	printf("%s\n", s);
	return 0;
}

void itoa (int n, char s[], int m)
{
int i, sign;
	if ((sign = n) < 0) 
		n = -n; 
	i = 0;
	do { 
		s[i++] = n % 10 + '0'; 
	} while ((n /= 10) > 0); 
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	sign = sizeof(s);
	printf("%d\n", sign);
	if(sign-1 < m) for(i = sign -1;i <= m; i++) s[i] = ' ';
	s[i] = '\0';
	reverse(s);
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