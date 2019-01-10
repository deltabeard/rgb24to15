CFLAGS = -std=c99 -pedantic -Ofast -s -Wall -Wextra
LDLIBS = -lm

all: rgb24_15
rgb24_15: rgb24_15.c rgb24_15.h
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

clean:
	rm -f rgb24_15
