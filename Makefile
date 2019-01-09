CFLAGS = -std=c99 -Ofast -s -Wall
LDLIBS = -lm

all: rgb24_15
rgb24_15: rgb24_15.c rgb24_15.h
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

clean:
	rm -f rgb24_15
