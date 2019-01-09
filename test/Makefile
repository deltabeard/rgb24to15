CFLAGS = -std=c99 -Og -g -Wall
LDLIBS = -lm

all: test
test: test.c
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

clean:
	rm -f test
