#include<stdio.h>

#define IN 1
#define OUT 0
#define ABC 26
void main(){
	int i, c, flag, tab, other;
	int alf[ABC*2]={0};
	int ALF[ABC*2]={0};
	int num[10]={0};
	flag = IN;

	other = 0;
	tab = 0;

	while((c = getchar()) != EOF){
		if (c == '`') break;
		if(c == '\t' || c == '\n' || c == ' '){
			flag = OUT;
			++tab;
		}
		else {
			flag = IN;
			if( c <= '9' && c >= '0') ++num[c - '0'];
			if(	c <= 'Z' && c >= 'A') ++ALF[c - 'A'];
			if(	c <= 'z' && c >= 'a') ++alf[c - 'a'];
			else ++other;
		}
	}
	for (int i = 0; i < ABC ; i++)
	{
		printf("%c= ",(i+'a'));
		for (int j = 0; j < alf[i] ; ++j) printf("#");
		printf("\n");
		printf("%c= ",(i+'A'));
		for (int j = 0; j < ALF[i] ; ++j) printf("#");
		printf("\n");
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d= ",i);
		for (int j = 0; j < num[i] ; ++j) printf("#");
		printf("\n");
	}
}