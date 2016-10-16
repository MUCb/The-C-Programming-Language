#include<stdio.h>

int invert(int x, int p, int n);

int main(){
	printf("%d\n", invert(12,5,2));
	return 0;
}

int invert(int x, int p, int n){
	int c = 0;
	c = ~c;
	c = c << n;
	c = ~c;
	c = c << (p - n);
	return x = x ^ c; 
}