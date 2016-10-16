#include <stdio.h>

#include "table.h"
#include "getword.h"


#define MAXWORD 100
int main(){
	char word[MAXWORD]= {0};
	char defn[MAXWORD]= {0};
	
	
	printf("please enter the word: ");
	getword(word, MAXWORD);
	printf("please enter the defn: ");
	getword(defn, MAXWORD);
	if(table_install(word, defn) != NULL) 
		printf("value is added\n");
	if(table_undef(word)) 
		printf("value is added\n");

	return 0;
}

