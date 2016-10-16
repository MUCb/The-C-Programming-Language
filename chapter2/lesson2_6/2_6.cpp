#include<stdio.h>
int setbits(int x, int p, int n, int y);
int main(){

	printf("%d\n",setbits(192,6,4,85));
	return 0;
}

int setbits(int x, int p, int n, int y){
	int s = 0;
	s = ~s;
	s = s << n;
	s = ~s;
	s = s << (p - n);
	s = ~s;
	x = x & s;

	s = 0;
	s = ~s;
	s = s << n;
	s = ~s;
	y = y & s;
	y = y << (p - n);

	return x = x | y;

}