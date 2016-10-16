all: textsearch

textsearch: 6_1.obj binsearch.obj getword.obj inout.obj
	link  6_1.obj binsearch.obj getword.obj inout.obj
	@echo linking textsearch
6_1.obj: 6_1.cpp key.h
	cl /c 6_1.cpp
binsearch.obj: binsearch.cpp key.h
	cl /c binsearch.cpp
getword.obj: getword.cpp
	cl /c getword.cpp
inout.obj: inout.cpp inout.h
	cl /c inout.cpp
clean:
	rm -rf *.o textsearch