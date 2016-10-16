#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "nlist.h"
//#include "hash.h"
#include "hash_func.h"
#include "strdup.h"
						
static struct nlist *hashtab[HASHSIZE];

struct nlist *table_lookup(char *s){
	struct nlist *np;
	unsigned idx = to_hash(s);
	to_hash(s);
	np = hashtab[idx];
	for (; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *table_install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;

	if ((np = table_lookup(name)) == NULL){
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = to_hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} 
	else 
		free((void *) np->defn);
	if( (np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

bool table_undef(char *s){
	struct nlist *np, *np_prev;
	unsigned hashval;
	np_prev=NULL;
	if ((np = table_lookup(s)) == NULL){
		return false;
	}
	else{
		hashval = to_hash(s);
		for (np = hashtab[to_hash(s)]; np != NULL; np = np->next){
			if(strcmp(s, np->name) == 0) break;
				np_prev = np;
		}
			if(np_prev != NULL) np_prev->next = np->next;
			else hashtab[to_hash(s)]= NULL;
		return true;
	}
}