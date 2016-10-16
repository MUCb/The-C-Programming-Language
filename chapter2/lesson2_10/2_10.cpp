#include<stdio.h>
int lower(int c);

int main(){
	printf("%c\n",lower('c'));
	return 0;
}

int lower(int c){
	return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}