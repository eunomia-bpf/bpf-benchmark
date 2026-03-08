DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))

CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,%.bpf.o,$(BPF_SRCS))
BPF_DEPS := $(patsubst %.bpf.c,%.bpf.d,$(BPF_SRCS))

.PHONY: all clean

all: $(BPF_OBJS)

%.bpf.o: %.bpf.c
	clang $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.bpf.o *.bpf.d *.bpf.bin

-include $(BPF_DEPS)
