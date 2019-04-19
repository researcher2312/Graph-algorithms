CXX = g++
CPPFLAGS = -Wall -pedantic -std=c++14 -I ./inc
OBJECTS = src/main.o

graf: $(OBJECTS)
	g++ $(CPPFLAGS) $(OBJECTS) -o graf

main.o: 

.PHONY: clean
clean:
	-rm -f $(OBJECTS) graf