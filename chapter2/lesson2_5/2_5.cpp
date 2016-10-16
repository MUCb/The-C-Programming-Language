#include<stdio.h>

int any(char s1[], char s2[]);

int main(){
	char s1[5]={'1','2','3','4','\0'};
	char s2[3]={'4','\0'};

	printf("%d\n",any(s1,s2) );
	return 0;
} 

int any (char s1[], char s2[]){
	int i = 0;
	int j = 0;
	bool find = false;
	for (i = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j]) {find = true; break;}
		if(find) break;
	}
	if(find) return i;
	else return -1;

}