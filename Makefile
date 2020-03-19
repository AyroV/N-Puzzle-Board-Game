output: Main.o BoardVector.o AbstractBoard.o
	g++ Main.o BoardVector.o AbstractBoard.o -o output
	
Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

BoardVector.o: BoardVector.cpp
	g++ -std=c++11 -c BoardVector.cpp

AbstractBoard.o: AbstractBoard.cpp
	g++ -std=c++11 -c AbstractBoard.cpp
	
clean:
	rm *.o output
