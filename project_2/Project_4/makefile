CXX = g++
CXXFLAGS = -c -std=c++0x
LDFLAGS = 
SRCS = main.cpp multiset.cpp MainMenu.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = multiset.h main.h MainMenu.h
EXEC = Project2

all: $(EXEC)
	./Project2

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o Project2
