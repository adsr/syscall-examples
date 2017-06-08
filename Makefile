SHELL=/bin/bash

my_cflags:=$(CFLAGS) -I./src/
all_sources:=$(wildcard src/*/*.c)
all_examples:=$(patsubst %.c,%,$(all_sources))
all_objects:=$(patsubst %.c,%.o,$(all_sources))

all: $(all_examples)

$(all_examples): %: %.o
	$(CC) $(my_cflags) $< -o $@

$(all_objects): %.o: %.c
	$(CC) -c $(my_cflags) $< -o $@

stubs:
	man 2 syscalls | \
	    grep -P '^\s+[^\(]+\(2\)\s+[0-9.]+' | \
	    awk '{print $1}' | \
	    cut -d'(' -f1 | \
	    xargs -rn1 -I@ sh -c \
	    "mkdir -p src/@/ && { [ -f src/@/@.c ] || ./src/stub.c.sh @ >src/@/@.c; }"

run: $(all_examples)
	@for p in $(all_examples); do $$p; done

clean:
	rm -f $(all_examples) $(all_objects)

.PHONY: all stubs run clean
