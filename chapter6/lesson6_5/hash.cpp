#include <stdio.h>

#include "hash_func.h"

unsigned to_hash(char *s){
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}