#include<stdio.h>
void main(){
	int cl, c;
	while((c=getchar())!=EOF){
		if ( c=='\n' ) { putchar('\\'); c='n'; }
		if ( c=='\b' ) { putchar('\\'); c='b'; }
		if ( c=='\t' ) { putchar('\\'); c='t'; }
		if ( c=='\\' ) { putchar('\\'); c='\\'; }
		putchar(c);
	}
}