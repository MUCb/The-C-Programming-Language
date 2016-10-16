#include<stdio.h>
void main(){
	int c, nl;

	while((c=getchar())!=EOF){
		nl=0;
		putchar(c);
		while(c==' ') {c=getchar(); nl=1;}
 		if(nl==1) putchar(c);
	}
}