
all: bin/mrowka

.PHONY: all test clean

bin/gauss: $(wildcard src/*.c) | bin
	gcc -Wall -ggdb --pedantic src/*.c -o bin/mrowka

bin:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/mrowka
