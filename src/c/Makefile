CC=cc
CFLAGS=-I.
DEPS=tokenizer.h
OBJ=tokenizer.o test_cli.o
OS = $(shell uname)

tokenizer.c: tokenizer.re
	re2c -o $@ $<

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_cli: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

libtokenizer: tokenizer.o
	if [ "$(OS)" = "Darwin" ]; then \
		LIBEXT=".dylib"; \
		SHARED_LIB_FLAG="-dynamiclib -install_name $(PREFIX)/lib/libtokenizer$${LIBEXT}"; \
	else \
		LIBEXT=".so.$(SHVER)"; \
		SHARED_LIB_FLAG="-shared -Wl,-soname,libtokenizer$${LIBEXT}"; \
	fi; \
	$(CXX) $${SHARED_LIB_FLAG} tokenizer.o -o libtokenizer$${LIBEXT}

clean:
	rm -f *.o test_cli libtokenizer.*

all: libtokenizer
