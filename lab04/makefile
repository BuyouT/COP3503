all: graph
	./graph

graph: graphmenu.o graph.o
	g++ -o graph graphmenu.o graph.o

graphmenu.o: graphmenu.cpp graph.h
	g++ -c graphmenu.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

clean:
	rm -rf *.o
	rm -rf graph


