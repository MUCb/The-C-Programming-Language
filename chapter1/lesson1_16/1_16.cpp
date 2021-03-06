#include<stdio.h>

#define MAXLINE 1000

int getline(char line[],int  maxline);
void copy(char to[], char from[]);

int main(){
	int len=0;
	int max=0;
	char line[MAXLINE]={0};
	char longest[MAXLINE]={0};

	while((len = getline(line, MAXLINE)) > 0){
		if (len == MAXLINE) {
			while(len == MAXLINE){
				max+=len;
				len = getline(line, MAXLINE);
			}
			max+=len;
		}
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) printf("%s", longest);

	return 0;
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

void copy(char to[], char from[]){
	int i=0;
	while((to[i] = from[i]) != '\0') ++i;
}