all: DynamicArray

DynamicArray: DynamicArray.o main.o
	g++ -g DynamicArray.o main.o -o DynamicArray

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	g++ -c -g -std=c++0x DynamicArray.cpp

main.o: main.cpp DynamicArray.h
	g++ -c -g main.cpp

clean:
	rm -rf *.o
	rm -rf DynamicArray
