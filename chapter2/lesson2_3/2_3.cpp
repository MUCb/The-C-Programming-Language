#include<stdio.h>

int htol(char s[]);

int main(void){
	htol("0xff");
	return 0;
}

int htol(char s[]){
	int i,n;
	int value = 0;
	n = 0;
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		printf("hex = ");
		for (int i = 2; (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= '0' && s[i] <= '9'); ++i)
		{
			printf("%c", s[i]);
			if (s[i] == 'A' || s[i] == 'a') value = 10; 
			if (s[i] == 'B' || s[i] == 'b') value = 11; 
			if (s[i] == 'C' || s[i] == 'c') value = 12; 
			if (s[i] == 'D' || s[i] == 'd') value = 13;
			if (s[i] == 'E' || s[i] == 'e') value = 14;
			if (s[i] == 'F' || s[i] == 'f') value = 15;
			if(s[i] >= '0' && s[i] <= '9') value = s[i] - '0';   
			
			n = n * 16 + value;
		}

		printf("\ndex = %d\n", n);
	}
	else {
		printf("error\n");
		return 0; }
}