CXX = g++

CPPFLAGS = -Wall -pedantic -std=c++17 -g -I ./inc
OBJECTS = main.o list.o graph.o graph_elements.o dijkstra.o heap.o


graf: $(OBJECTS)
	g++ -o graf $(CPPFLAGS) $(OBJECTS)


main.o: inc/list.h inc/graph.h
list.o: inc/list.h inc/graph_elements.h
graph.o: inc/graph.h inc/graph_elements.h inc/list.h
graph_elements.o: inc/graph_elements.h inc/list.h
dijkstra.o: inc/dijkstra.h inc/graph.h inc/list.h inc/heap.h
heap.o:inc/heap.h

.PHONY: clean
clean:
	rm -f $(OBJECTS) graf

%.o : src/%.cpp
	$(CXX) -c $(CPPFLAGS) $<
