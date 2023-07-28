all: myProgram

myProgram: main.o libfilesearcher.a
	g++ -static main.cpp -L. ./build/lib/libfilesearcher.a -o  ./build/main.exe

main.o: main.cpp
	gcc -o .\build\main.o  -c main.cpp

FileSearcher.o: FileSearcher.cpp FileSearcher.h
	gcc -o ./build/lib/FileSearcher.o  -c FileSearcher.cpp

libfilesearcher.a: FileSearcher.o
	ar rcs ./build/lib/libfilesearcher.a ./build/lib/FileSearcher.o 

libs: ./build/lib/libfilesearcher.a