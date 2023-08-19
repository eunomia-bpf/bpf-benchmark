ALL_EBPF_PROGS = $(patsubst %.bpf.c,%.bpf.bin,$(shell ls *.bpf.c))
ALL_NATIVE_PROGS = $(patsubst %.bpf.c,%.native,$(shell ls *.bpf.c))

all: $(ALL_EBPF_PROGS) $(ALL_NATIVE_PROGS)

%.bpf.o: %.bpf.c
	clang -Wall -O3 -target bpf -c -o $@ $<
%.bpf.bin: %.bpf.o
	llvm-objcopy -j .text -O binary $< $@
%.native: %.bpf.c native_wrapper.c
	clang -Wall -O3 -o $@ $^

clean:
	rm -rf *.bpf.o *.bpf.bin *.native
