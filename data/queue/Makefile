all: clean dirs build

build:
	g++ src/main.cpp src/queue.cpp -o bin/main

run: all
	./bin/main

dirs:
	mkdir bin

clean:
	rm -rf bin build
