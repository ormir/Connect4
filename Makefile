connect: connect4.o board.o player.o
	g++ -std=c++11 connect4.o board.o player.o -o connect4

connect4.o: connect4.cpp 
	g++ -std=c++11 -c connect4.cpp

board.o: board.cpp board.hpp
	g++ -std=c++11 -c board.cpp

player.o: player.cpp player.hpp
	g++ -std=c++11 -c player.cpp

start: connect4
	./connect4

clean:
	rm *.o connect4

compress: 
	tar czf connect4.tar.gz *