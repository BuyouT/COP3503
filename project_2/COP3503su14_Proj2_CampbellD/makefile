all: proj2

proj2: main.o multiset.o
	g++ -o proj2 main.cpp multiset.cpp

main.o: main.cpp
	g++ -c main.cpp

multiset.o: multiset.cpp multiset.h
	g++ -c multiset.cpp

clean:
	rm -rf *.o
	rm -rf proj2