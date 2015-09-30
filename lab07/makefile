all: sort

Mergesort: Mergesort.o main.o
	g++ -g Mergesort.o main.o -o sort

Mergesort.o: Mergesort.cpp Mergesort.h
	g++ -c -g -std=c++0x Mergesort.cpp

main1.o:main.cpp Mergesort.h
	g++ -c -g main.cpp

clean:
	rm -rf *.o
	rm -rf Mergesort
