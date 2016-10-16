#include <stdio.h>

int main(){
	int i;
	char c, c1;
	bool block_comment_on = false;
	bool single_comment_on = false;

	while ((c = getchar()) != EOF){
		if (single_comment_on){
			if (c == '\n'){
				putchar(c);
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
			if (c == '/'){
				c1 = getchar();

				if (c1 == '/') single_comment_on = true;
				else if (c1 == '*') block_comment_on = true;
				else {putchar(c); putchar(c1);}
			}
			else putchar(c);
		}
	}
	return 0;
}	