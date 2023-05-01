cc      = g++
sources = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
objects = $(sources:.cpp=.o)
bin     = bin/main

all: clean dirs build 

%.o: %.cpp
	$(cc) -c $< -o $@

build: $(objects)
	$(cc) $(objects) -o $(bin)
	mv $(objects) bin/objects/
	
run: all
	./$(bin)

dirs:
	mkdir -p bin/ bin/objects/

clean:
	rm -rf bin
