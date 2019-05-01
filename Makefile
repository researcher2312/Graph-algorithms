CXX = g++

CPPFLAGS = -Wall -pedantic -std=c++17 -I ./inc
OBJECTS = main.o list.o graph.o graph_elements.o


graf: $(OBJECTS)
	g++ -o graf $(CPPFLAGS) $(OBJECTS)


main.o: inc/list.h inc/graph.h
list.o: inc/list.h
graph.o: inc/graph.h inc/graph_elements.h
graph_elements.o: inc/graph_elements.h


.PHONY: clean
clean:
	rm -f $(OBJECTS) graf

%.o : src/%.cpp
	$(CXX) -c $(CPPFLAGS) $<
