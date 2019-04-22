CXX = g++

CPPFLAGS = -Wall -pedantic -std=c++17 -I ./inc
OBJECTS = main.o list.o graph.o


graf: $(OBJECTS)
	g++ -o graf $(CPPFLAGS) $(OBJECTS)


main.o: inc/list.h
list.o: inc/list.h
graph.o: inc/graph.h


.PHONY: clean
clean:
	rm -f $(OBJECTS) graf

%.o : src/%.cpp
	$(CXX) -c $(CPPFLAGS) $<
