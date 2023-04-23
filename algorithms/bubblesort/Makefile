all: clean build

build:
	clang++ -include bubblesort.h -c bubblesort.cpp
	clang++ -o main main.cpp bubblesort.o

run: all
	./main

clean:
	rm -f *.o main
