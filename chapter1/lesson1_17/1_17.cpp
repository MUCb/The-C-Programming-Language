#include<stdio.h>

#define MAXLEN 	10000
#define BORDER 80	

int getline(char string[], int size);
void copy(char sourse, char dest);

int  main(){
	int len;
	char str[MAXLEN]={0};
	char longest[MAXLEN]={0};
	len=0;
	while((len = getline(str, MAXLEN)) != 0){
		if (len > 30) printf("%s", str);	
	}
	return 0;
}

int getline(char s[], int size){
	int i,c;
	for(i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n'){
		s[i] = c; 
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char sourse[], char dest[]){
	int i=0;
	while((dest[i]=sourse[i]) != '\0')  
		++i; 
}