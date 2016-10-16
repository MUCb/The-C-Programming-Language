#include<stdio.h>

void main(){
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite=nother=0;
	for (i = 0; i < 10; ++i) ndigit[i]=0;
	while ((c = getchar()) != EOF){
		if(c == 'q') break;
		if (c >= '0' && c <= '9') ++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else 
			++nother;
	}
		printf("number=");
		for (i = 0; i < 10; ++i) printf(" %d",ndigit[i] );
			printf(" , tab = %d , others = %d\n",  nwhite, nother);
}