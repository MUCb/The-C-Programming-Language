#include<stdio.h>

#define swap(t,  x,  y) t z = x; x = y;  y = z;

int main (){
	int x,y;
	x= 5;
	y = 6;
	swap(int , x, y);
	printf("x = %d\ny = %d\n",x,y );

	return 0; 
}