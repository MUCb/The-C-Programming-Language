#include <stdio.h>

int main(){
	int i;
	char c, c1;
	int single_quotes_count = 0;
	int double_quotes_count = 0;
	bool block_comment_on = false;
	bool single_comment_on = false;

	while ((c = getchar()) != EOF){
		if (single_comment_on){
			if (c == '\n'){
				//putchar(c);
				single_comment_on = false;
			}
		}
		else if (block_comment_on){
			if (c == '*'){
				if ((c = getchar()) == '/')
					block_comment_on = false;
			}
		}
		else {
			if (c == '*'){   
				c1 = getchar();
				if (c1 == '/') printf("error1\n");
			}
			if (c == '\''){ 
				single_comment_on++;
				c1 = getchar();
				if (c1 == '\\') {
					c1 = getchar();
					if (c1 == '\''){
						printf("error1\n");
						single_quotes_count++;
					}
				}
			}
			if(c == '\"') double_quotes_count++;
			if (c == '/'){
				c1 = getchar();

				if (c1 == '/') single_comment_on = true;
				else if (c1 == '*') block_comment_on = true;
				else {/*putchar(c); putchar(c1);*/}
			}
			//else //putchar(c);
		}
	}
	if ((single_quotes_count % 2) > 0) printf("error \'\n");
	if ((double_quotes_count % 2) > 0) printf("error \"\n");
 	return 0;
}