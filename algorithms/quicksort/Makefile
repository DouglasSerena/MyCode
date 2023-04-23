all: clean build

build:
	clang++ -include quicksort.h -c quicksort.cpp
	clang++ -o main main.cpp quicksort.o

run: all
	./main

clean:
	rm -f *.o main
