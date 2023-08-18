ALL_PROGS = $(patsubst %.bpf.c,%.bpf.bin,$(shell ls *.bpf.c))

all: $(ALL_PROGS)

%.bpf.o: %.bpf.c
	clang -Wall -O2 -target bpf -c -o $@ $<
%.bpf.bin: %.bpf.o
	llvm-objcopy -j .text -O binary $< $@
clean:
	rm -rf *.bpf.o *.bpf.bin
