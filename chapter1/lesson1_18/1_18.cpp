#include<stdio.h>

#define MAXLEN 1000

int getline(char str[], int len);
void copy(char sourse[], char dest[]);

int main(){

	char str1[MAXLEN]={0};
	int i, v, len;
	len = 0;
	while((len = getline(str1, MAXLEN)) != 0){
		--len;
		v= len;
		
		for (i= len - 1; i >= 0; --i){
			if(str1[i] == '\t' || str1[i] == ' ') {--len;  }
			else i = 0;
		}
		
		if (len != 0) {
			for (i = 0; i < len ; i++)
				printf("s= %c", str1[i]);
			printf("\n");
		}
	}
	return 0;
}

int getline(char str[], int len){
	int i, c;
	for(i = 0; i < len - 1  && (c = getchar()) != EOF && c != '\n'; ++i){
				
		str[i] = c;

	}
	if(c == '\n'){
	//	printf ("c= %c\n", c);		
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return i;
}

void copy(char sourse[], char dest[]){
	int i=0;
	while((dest[i] = sourse[i]) != '/0') ++i;
}