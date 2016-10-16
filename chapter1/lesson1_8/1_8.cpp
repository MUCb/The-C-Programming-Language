#include<stdio.h>
void main(){
	int c ,nl,tab,ns;
	nl=0; tab=0; ns=0;
	while((c=getchar())!=EOF){
		if(c=='\n') ++nl;
		if(c==' ') ++ns;
		if(c=='\t') ++tab;
		if(c=='q') break;
	}
	printf("space=%d\n",ns);
	printf("new string=%d\n",nl);
	printf("tab=%d\n",tab);
}