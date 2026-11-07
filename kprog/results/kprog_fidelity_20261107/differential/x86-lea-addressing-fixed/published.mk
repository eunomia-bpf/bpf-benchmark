ROOT := $(abspath ../../../../..)
SOURCE := $(ROOT)/kprog/fidelity/build-lea-final-published/source
BUILD := $(SOURCE)/kprog/fidelity/build-cpu
OUT := $(CURDIR)/published
REFERENCE := $(abspath ../x86-lea-published/reference.bin)
.PHONY: source build cpu reference
source:
	install -d $(SOURCE) $(OUT)
	tar -xzf published-producer-source.tar.gz -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
build: source
	python3 -c 'import sys;sys.path.insert(0,"$(SOURCE)/kprog/fidelity");import generate;old=generate.x86_forms;generate.x86_forms=lambda aux:[x for x in old(aux) if x.startswith("lea ")];sys.argv=["generate.py","--arch","x86","--out","$(BUILD)"];generate.main()'
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(SOURCE)/kprog/fidelity/driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $(BUILD)/cpu-differential
cpu:
	$(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
reference: $(REFERENCE)
	python3 $(SOURCE)/kprog/fidelity/reference_check.py --reuse-trace --opcode X86_OP_LEA --trace $(OUT)/cpu-states.bin --binary $(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(OUT) --reference $(REFERENCE)
$(REFERENCE):
	$(MAKE) -C $(CURDIR)/../x86-lea-published reference.bin
