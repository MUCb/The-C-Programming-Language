#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tnode.h"



struct tnode *tree_alloc(void);
char *strdup(char *s);
int tree_search(struct tnode *p, strcompare f_cmp, char *w, printnd f_proc,int counter);


struct tnode *tree_add(struct tnode *p, char *w){
	int cond;
	if (p == NULL){
		p = tree_alloc();
		if (p != NULL){
			p->word = strdup(w);
			p->count = 1;
			p->left = p->right = NULL;
		}
		else {
			printf("Insufficient memory available\n");
		}
	} 
	else if ( (cond = strcmp(w, p->word) ) == 0)
		p->count++;
	else if (cond < 0)
		p->left = tree_add(p->left, w);
	else 
		p->right = tree_add(p->right, w);
	return p;
}


void tree_process1(struct tnode *p, printnd func ){
	if (p != NULL){
		tree_process1(p->left,func );
		func(p);
		tree_process1(p->right,func);
	}
}

struct tnode *tree_alloc(void){
		return (struct tnode *) malloc( sizeof( struct tnode ) );
	}

void tree_process(struct tnode *begin, struct tnode *p , strcompare f_cmp, printnd f_proc){
	int counter=0;
	if (p != NULL){
		tree_process(begin, p->left, f_cmp, f_proc );
		if(p->count != 0){
			p->count = 0;
			counter= tree_search(begin, f_cmp, p->word, f_proc,0);
			printf("counter = %d\n", counter);
			if(counter > 0) {p->count = 1;f_proc(p);p->count = 0;}
			
		}
		//printf("%4d     %4s\n", p->count, p->word);
		tree_process(begin, p->right, f_cmp, f_proc);
	}
}

int tree_search(struct tnode *p, strcompare f_cmp, char *w, printnd f_proc,int counter){
	int c = 0;
	struct tnode *lcur = NULL, *rcur = NULL;
	
	// printf("%4d %4s\n", p->count, p->word);

	c = f_cmp(p->word,w);
	printf("word = %s with node = %s comp = %4d\n",w, p->word, c);
	if(c == 0)
	{	
		if(strcmp(p->word,w)!=0)
		{counter++;
		/*if(pfind->count != 0){
			f_proc(pfind);
			pfind->count = 0;
		}*/
		f_proc(p);}
		p->count = 0;
		//printf("count = %4d\n", p->count);
		lcur = p->left;
		rcur = p->right;
	}
	else if(c > 0)
	{
		lcur = p->left;
	}
	else if(c < 0)
	{
		rcur = p->right;
	}

	if(lcur) counter = tree_search(lcur, f_cmp, w, f_proc,counter);
	if(rcur) counter = tree_search(rcur, f_cmp, w, f_proc,counter);

	// if(c = f_cmp(p->word,w) == NULL) {
	// 	tree_process(p->left, f_cmp, w);
	// 	tree_process(p->right, f_cmp, w);
	// }
	// else if (c < 0) 
	// 	tree_process(p->left, f_cmp, w);
	// else 
	// 	tree_process(p->right, f_cmp, w);
	return counter;
}