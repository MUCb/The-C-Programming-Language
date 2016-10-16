#include<stdio.h>

void squeeze(char s1[],char s2[]);

int main(){
	char s1[5]={'1','2','3','4','\0'};
	char s2[3]={'2','4','\0'};
	squeeze(s1,s2);
	printf("%s\n",s1 );
	return 0;
}

void squeeze(char s1[], char s2[]){
	int i, j, g;
	bool accord;
	accord = false;
	for ( i = j = 0; s1[i] != '\0'; ++i){
		for(g = 0; s2[g] != '\0'; g++ )
			if (s2[g] == s1[i]) { accord = true; break;}
		if(!accord)	s1[j++] = s1[i];
		else accord = false;
	}
	s1[j] = '\0';
}
