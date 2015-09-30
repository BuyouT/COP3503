all: WQU

WQU: UnionFind.o
	g++ UnionFind.o -o WQU

UnionFind.o: UnionFind.cpp 
	g++ UnionFind.cpp

clean:
	rm -rf *.o
	rm -rf UnionFind
