CFLAGS = -std=c99 -pedantic -Og -g -Wall

all: test
test: test.c ../rgb24_15.h
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f test
