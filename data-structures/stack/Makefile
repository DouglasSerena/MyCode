all: clean build

build:
	clang++ -include stack.h -c stack.cpp
	clang++ -o main main.cpp stack.o

run: all
	./main

clean:
	rm -f *.o main
