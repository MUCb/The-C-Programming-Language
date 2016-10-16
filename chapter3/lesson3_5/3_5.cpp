#include<stdio.h>

void itob(int n, char s[], int b);

int main(){
	char s[10]= {0};
	itob(25,s,16);
	//int f = 9/10;
	//printf("%d\n",f );
	printf("%s\n", s);
	return 0;
}

void itob (int n, char s[], int b){
	int ost = 0;
	int i = 0;
	int m = 1;
	switch(b){
		case 16 :
		m = n;
			while (m > 0) { 
				m = m / 16;  
				//printf("m = %d\n", m );
				ost = n % 16;  
				//printf("%d\n", ost );
				if(ost <= 9 ) 
					s[i] = '0'+ost; 
				else  
					switch(ost){
						case 10 : s[i] = 'a'; break;
						case 11 : s[i] = 'b'; break;
						case 12 : s[i] = 'c'; break;
						case 13 : s[i] = 'd'; break;
						case 14 : s[i] = 'e'; break;
						case 15 : s[i] = 'f'; break;
						default : printf("error\n");
					}
				i++;

			}
			break;
		//case 8 :

		//case 10 :

		//case 2 :
	}	
}