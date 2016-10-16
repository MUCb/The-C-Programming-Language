#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "tnode.h"

#define MAXWORD 100

struct tnode *tree_add(struct tnode *p, char *w);
//void treeprint(struct tnode *p);
void tree_process1(struct tnode *p, printnd func );
void tree_process(struct tnode *begin, struct tnode *p , strcompare f_cmp, printnd f_proc);
int getword(char *word, int lim);


int tree_search(struct tnode *p, strcompare f_cmp, char *w, printnd f_proc,int counter);

void printnode(struct tnode *p);
int compword(const char *s1,const char *s2);


int main(int argc, char *argv[]){
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
//	if (argc != 2)
	//	printf("error give me a number!!!\n");
	//else{
		while( getword (word, MAXWORD) != EOF )
			if ( isalpha(word[0]) ) 
				root = tree_add(root, word);
		//tree_process1(root, printnode);
		//tree_search(root, strcmp, "qwe", printnode); //tree_search with standart function strcmp
			//tree_search(root, compword, "qwe", printnode);
			//tree_search(root, compword, "qwe", printnode);
			tree_process(root, root , compword,  printnode);
	//}
	return 0;
}

int compword(const char *s1,const char *s2){
	//return strcmp(s1,s2);
	size_t count = 3;
	return memcmp(s1, s2,count);
}

void printnode(struct tnode *p){
	if(p->count)
	printf("%4d %4s\n", p->count, p->word);
}
