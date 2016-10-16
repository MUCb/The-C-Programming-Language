#include<stdio.h>
#include<string.h>

void expand(char s1[], char s2[]);

int main(){
	int j, i;

	char s1[5]={'-', 'a','-','f','\0'};
	char s2[20]={'\0'};
	expand(s1, s2);
	printf("s = %s\n", s2);
	return 0;
}

void expand(char s1[], char s2[]){
		int j, i;
		char c = 0;

		for (i = 0, j = 0 ; i < strlen(s1); i++, j++){
			printf("if = %d\n", i);
			if(s1[i] == '-'){
				//printf("i = %d\n",i);
				c = s1[i-1] + 1;
				if(s1[i-1] >= 'A' && s1[i-1] <= 'Z' && s1[i+1] >= 'A' && s1[i+1] <= 'Z' && s1[i+1] > s1[i-1]) 
					for ( ; c <= s1[i+1]; c++, j++)	s2[j] = c;
				else if(s1[i-1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z' && s1[i+1] > s1[i-1]){
					for ( ; c <= s1[i+1]; c++, j++){	s2[j] = c; /*printf("j for = %d\n",j);*/}}
				else if(s1[i-1] >= '0' && s1[i-1] <= '9' && s1[i+1] >= '0' && s1[i+1] <= '9' && s1[i+1] > s1[i-1])
					for ( ; c <= s1[i+1]; c++, j++)	s2[j] = c;
				else s2[j] = s1[i];
			}
			else {s2[j] = s1[i]; printf("c = %c\n", s2[j]);}
		}
		s2[j] = '\0';
}

