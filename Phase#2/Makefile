all: main.exe main.cpp Users.cpp

main.exe: main.o Users.o
	 g++ -o main.exe main.o Users.o 

main.cpp: main.cpp
	 g++ -c main.cpp

Users.cpp: Users.cpp
	 g++ -c Users.cpp
     
clean:
	 del main.o main.exe Users.o 	
