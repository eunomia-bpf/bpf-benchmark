CFLAGS := -Wall -Wextra -O2 -g -target bpf -I/usr/include/x86_64-linux-gnu

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,%.bpf.o,$(BPF_SRCS))
BPF_BINS := $(patsubst %.bpf.c,%.bpf.bin,$(BPF_SRCS))

.PHONY: all clean

all: $(BPF_OBJS)

%.bpf.o: %.bpf.c
	clang $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BPF_OBJS) $(BPF_BINS)
