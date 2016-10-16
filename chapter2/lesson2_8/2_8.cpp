#include<stdio.h>

int rightrot(int x, int n);

int main(){
	printf("%d\n",rightrot(1073741824,1));
	return 0;
}

int rightrot(int x, int n){
	int c = 0;
	int tail = 0;
	c = ~c;
	c = c << n;
	c = ~c;
	tail = c & x;
	tail = tail << sizeof(int)*8 - n; 
	x = x >> n;
	return x | tail;
}