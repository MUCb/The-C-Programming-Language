#include<stdio.h>

void escape(char s[], char t[]);
void nescape(char s[], char t[]);

int main(){
	char s[10] = {'\0'};
	char t[6] = {'0', '1', '2', '\n','\0'};
	escape(s, t);
	printf("%s\n", s);
	nescape(t, s);
	printf("%s\n", t);
	return 0;
}

void escape(char s[], char t[]){
	int i = 0;
	int j = 0;
	while(t[i] != '\0'){
		switch(t[i]){
			case '\n' : 
				s[j] = '\\';
				j++; 
				s[j] = 'n';
				break;
			case '\t' :
				s[j] = '\\';
				j++; 
				s[j] = 't';
				break;
			case '\v' :
				s[j] = '\\';
				j++; 
				s[j] = 'v';
				break;
			default : 
				s[j] = t[i];
				break;
		}
		i++;
		j++;
	}
}

void nescape(char s[], char t[]){
	int i = 0;
	int j = 0;
	while(t[i] != '\0'){
		if (t[i] == '\\'){
			switch(t[i+1]){
				case 'n' : 
					s[j] = '\n';
					i++; 
					break;
				case 't' :
					s[j] = '\t';
					i++; 
					break;
				case 'v' :
					s[j] = '\v';
					i++; 
					break;
				default : 
					s[j] = t[i];
					break;
			}
		}
		i++;
		j++;
	}
}