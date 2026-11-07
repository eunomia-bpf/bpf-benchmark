ROOT := $(abspath ../../../../..)
SOURCE := $(ROOT)/kprog/fidelity/build-shift-published/source
BUILD := $(SOURCE)/kprog/fidelity/build-cpu
OUT ?= $(CURDIR)
.PHONY: source build cpu reference
source:
	install -d $(SOURCE)
	tar -xzf producer-source.tar.gz -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
build: source
	python3 -c 'import sys;sys.path.insert(0,"$(SOURCE)/kprog/fidelity");import generate;old=generate.x86_forms;generate.x86_forms=lambda aux:[x for x in old(aux) if x.split()[0] in {"shl","shr","sar","rol"}];sys.argv=["generate.py","--arch","x86","--out","$(BUILD)"];generate.main()'
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(SOURCE)/kprog/fidelity/driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $(BUILD)/cpu-differential
cpu:
	install -d $(OUT)
	$(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
reference: reference.bin
	python3 $(SOURCE)/kprog/fidelity/reference_check.py --reuse-trace --opcode X86_OP_ALU_IMM --opcode X86_OP_ALU_REG --trace $(OUT)/cpu-states.bin --binary $(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(OUT) --reference $(CURDIR)/reference.bin
reference.bin: reference.gz
	gzip -dc $< > $@
	chmod +x $@
