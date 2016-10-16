#include<stdio.h>
int bitcount(unsigned x);

int main(){
	
	printf("%d\n", bitcount(5));
	return 0;
}
int bitcount(unsigned x){
	int b = 0;
	
	for (b = 0; x != 0 ; x &= (x -1))
		b++;
	return b;
}