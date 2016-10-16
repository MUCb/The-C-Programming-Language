#ifndef TABLE
#define TABLE 

struct nlist table_lookup(char *s);
struct nlist *table_install(char *name, char *defn);
bool table_undef(char *s);
#endif