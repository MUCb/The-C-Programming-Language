#include<stdio.h>

#define MAXLINE 10000

void reverse(char s[]);
int getline(char str[], int s);

int main(){
	int size;
	char str[MAXLINE] = {0};
	size=0;
	while ((size = getline(str, MAXLINE)) != 0){
		reverse(str);
		printf("%s", str);
	}
	return 0;
}

void reverse(char s[]){
	char copy[MAXLINE] = {0};
	int i=0;
	int n=0;
	int j=0;

	while ( s[i] != '\n') 
		i++;
	n=i;
	for(j=0; j <= n; j++){
		copy[j]=s[i];
		--i;
	}
	for(j=0; j <= n; j++){
		s[j]=copy[j];
	}
	
	s[j]='\n';
	s[j+1]='\0';


}
int getline(char str[], int size){
	int i,c;
	for (i=0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; i++)
		str[i] = c;
	if( c == '\n'){
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return i;
}