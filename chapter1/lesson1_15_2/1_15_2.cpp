#include<stdio.h>

int temp(int fahr);

void main(){
	int i;
	for(i=0;i<=300;i=i+20) printf("%3d %6d\n", i, temp(i));
}

int temp(int fahr){
	 return (5.0/9.0)*(fahr-32.0);
}