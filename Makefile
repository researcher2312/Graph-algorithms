CXX = g++
CPPFLAGS = -Wall -pedantic -std=c++14 -I ./inc
OBJECTS = src/main.o src/list.o

graf: $(OBJECTS)
	g++ $(CPPFLAGS) $(OBJECTS) -o graf

main.o:
list.o: list.h

.PHONY: clean
clean:
	-rm -f $(OBJECTS) graf