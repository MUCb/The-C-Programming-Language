#include<stdio.h>
void main(){
	long mc=0;
	while(getchar()!=EOF)
		++mc;
	printf("%ld\n",mc);
}