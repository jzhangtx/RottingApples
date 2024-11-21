RottingApples: RottingApples.o
	g++ -g -o RottingApples.exe RottingApples.o -pthread    

RottingApples.o: RottingApples/RottingApples.cpp
	g++ -g  -c -pthread RottingApples/RottingApples.cpp
