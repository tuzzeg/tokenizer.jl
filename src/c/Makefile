CC=cc
CFLAGS=-I.
DEPS=tokenizer.h
OBJ=tokenizer.o test_cli.o

tokenizer.c: tokenizer.re
	re2c -o $@ $<

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_cli: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
	rm -f test_cli

all: test_cli
