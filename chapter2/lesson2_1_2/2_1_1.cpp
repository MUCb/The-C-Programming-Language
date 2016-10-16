#include<stdio.h>

int lower(int c);

int main(){
	printf("lower fi=unc = %c\n", lower('D') );
	return 0;
}

int lower(int c){
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else return c;
}