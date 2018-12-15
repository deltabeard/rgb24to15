CFLAGS = -std=c99 -Og -g -Wall
LDLIBS = -lm

all: rgb24_15
rgb24_15: rgb24_15.c
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

clean:
	rm -f rgb24_15
