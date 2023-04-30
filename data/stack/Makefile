all: clean dirs build

build:
	g++ src/main.cpp src/stack.cpp -o bin/main

run: all
	./bin/main

dirs:
	mkdir bin

clean:
	rm -rf bin build
