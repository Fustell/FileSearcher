all: myProgram

myProgram: main.o libfilesearcher.a
	g++ -static main.o -o main -L. -lfilesearcher

main.o: main.cpp
	gcc -O -c main.cpp

FileSearcher.o: FileSearcher.cpp FileSearcher.h
	gcc -O -c FileSearcher.cpp

libfilesearcher.a: FileSearcher.o
	ar rcs libfilesearcher.a FileSearcher.o 

libs: libfilesearcher.a

clean:
	del libfilesearcher.a
	del -f main.o
	del -f FileSearcher.o
	del -f main.exe