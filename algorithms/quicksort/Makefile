compiler       = g++
compiler_flags = -std=c++23
debug		   = true

executable   = main
sources      = $(wildcard src/*.cpp)
objects      = $(sources:.cpp=.o)
headers      = $(sources:.cpp=.h)
dependencies = $(sources:.cpp=.d)

ifeq ($(debug), true)
	compiler_flags += -g
endif

.PHONY: all
all: $(executable)

$(executable): $(objects)
	$(compiler) -o $@ $^ $(compiler_flags)

-include $(dependencies)

%.d: %.cpp
	@$(compiler) $(compiler_flags) $< -MM -MT $(@:.d=.o) >$@

%.o: %.cpp $(headers)
	$(compiler) $(compiler_flags) -c $< -o $@

run: all
	./$(executable)

.PHONY: clean
clean:
	rm -f $(objects) $(executable) $(dependencies)