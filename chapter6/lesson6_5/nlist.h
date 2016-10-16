#ifndef TTY
#define TTY
struct nlist{/*элемент таблицы*/
		struct nlist *next;/* уеазатель на следующий элемент*/
		char *name;/*определенное имя*/
		char *defn;
};


#endif