#include <stdio.h>

#define MAXLENGTH 8

int main(){
	char c;
	char str[MAXLENGTH+1]={0};	
	int i = 0;
	int count = 0;
	int j = 0;
	while ((c = getchar()) != EOF){
		count++;
		if (c == '\n') {
			str[count]=c;
			//printf("count = %d\n", count);
			for(i=1; i <= count; i++)
				putchar(str[i]);

			for(i=0; i < MAXLENGTH; i++) 
				str[i]=0;
			count =0;
			continue;
		}
		else {
			//printf("count = %d\n", count);
			str[count] = c;
		}
		if(count == MAXLENGTH){
			//printf("vosem\n");
			while( count > 0 && str[count] != ' ' && str[count] != '\t'  ){
				count--;
				//printf("count = %d\n", count);
			}
			//printf("count=%d\n", count);
			if (count == 0 ) {
				for(i = 1;i <= MAXLENGTH; i++) 
					putchar(str[i]); 
				putchar('\n');
			}
			else {
				//printf("count=%d\n",count); 
				while (str[count] == ' ' || str[count] == '\t'){
					count--;
				}
				count++;
				//printf("count=%d\n",count); 
				for(i = 1;i <= count; i++) 
					putchar(str[i]);
				putchar('\n');
				j=1;
				for(i = count+1;i <=MAXLENGTH; i++){
					str[j]=str[i];
					//printf("j=%d   ",j);
					//printf("str[j]=%c\n",str[j]);
						j++;
				} 
				count = j-1;
				//printf("count=%d\n",count);
				for(i = j;i <=MAXLENGTH; i++){
					//	printf("i=%d   ",i);
					str[i]=0;
				} 
				// for (int i = 0; i < MAXLENGTH; ++i)
				// {
				// 	printf("str[j]=%c\n",str[i]);
				// }
				// printf("count=%d\n",count);
					
			}

		}
	}
	return 0;
}
