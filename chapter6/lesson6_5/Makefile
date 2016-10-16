all:wordtable

wordtable: main.obj table.obj hash.obj strdup.obj getword.obj inout.obj
	link main.obj table.obj hash.obj strdup.obj getword.obj inout.obj
	@echo linking word table
main.obj: main.cpp table.h getword.h
	cl /c main.cpp
table.obj: table.cpp nlist.h strdup.h hash_func.h
	cl /c table.cpp
hash.obj: hash.cpp hash_func.h
	cl /c hash.cpp 
strdup.obj: strdup.cpp
	cl /c strdup.cpp
getword.obj: getword.cpp inout.h
	cl /c getword.cpp
inout.obj: inout.cpp
	cl /c inout.cpp
clean:
	rm -rf *.o textsearch