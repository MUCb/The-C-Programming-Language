
#ifndef HDR
#define HDR
struct tnode
{
	char *word;
	int count;
	struct tnode *left; 
	struct tnode *right;
};

typedef void printnd(struct tnode *p);
typedef int strcompare(const char *,const char *);
#endif