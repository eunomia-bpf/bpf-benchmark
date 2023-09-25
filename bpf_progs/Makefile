ALL_EBPF_PROGS = $(patsubst %.bpf.c,%.bpf.bin,$(shell ls *.bpf.c))
ALL_NATIVE_PROGS = $(patsubst %.bpf.c,%.native,$(shell ls *.bpf.c))
ALL_WASM_PROGS = $(patsubst %.bpf.c,%.wasm,$(shell ls *.bpf.c))
all: $(ALL_EBPF_PROGS) $(ALL_NATIVE_PROGS) $(ALL_WASM_PROGS)

%.bpf.o: %.bpf.c
	clang -Wall -O3 -target bpf -c -o $@ $<
%.bpf.bin: %.bpf.o
	llvm-objcopy -j .text -O binary $< $@
%.native: %.bpf.c native_wrapper.c
	clang -Wall -O3 -o $@ $^

check-wasi-clang:
ifndef WASI_SDK_CLANG
	$(error Please set WASI_SDK_CLANG to the clang binary in WASI SDK)
endif

%.wasm: %.bpf.c check-wasi-clang
	$(WASI_SDK_CLANG) -O3 --target=wasm32-unknown-wasi -nostartfiles -Wl,--export-all -Wl,--no-entry -o $@ $< 
clean:
	rm -rf *.bpf.o *.bpf.bin *.native *.wasm
