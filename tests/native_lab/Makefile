# SPDX-License-Identifier: GPL-2.0
CFLAGS  ?= -O2 -Wall -Wextra -g
LDLIBS  := -lbpf -lelf -lz

poc: poc.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f poc

.PHONY: clean
