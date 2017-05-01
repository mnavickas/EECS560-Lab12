Lab12:main.o Dijkstra.o
	g++ -std=c++11 -Wall -g main.o Dijkstra.o -o Lab12

main.o: main.cpp Dijkstra.hpp
	g++ -std=c++11 -Wall -g -c main.cpp

Dijkstra.o: Dijkstra.hpp
	g++ -std=c++11 -Wall -g -c Dijkstra.cpp

clean:
	rm *.o  Lab12

remake:
	make clean && make

test:
	make && ./Lab12
