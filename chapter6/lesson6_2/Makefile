all:wordcounter

wordcounter: 6_2.obj tnode.obj strdup.obj getword.obj inout.obj
	link  6_2.obj tnode.obj strdup.obj getword.obj inout.obj
6_2.obj: 6_2.cpp tnode.h
	cl /c 6_2.cpp 
tnode.obj: tnode.cpp tnode.h
	cl /c tnode.cpp
strdup.obj: strdup.cpp
	cl /c strdup.cpp
getword.obj: getword.cpp 
	cl /c getword.cpp
inout.obj: inout.cpp inout.h
	cl /c inout.cpp
clean:
	rm -rf *.o textsearch