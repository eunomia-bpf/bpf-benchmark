ROOT := $(abspath ../../../../..)
SOURCE := $(ROOT)/kprog/fidelity/build-rotate-replay/source
BUILD := $(SOURCE)/kprog/fidelity/build-cpu
OUT ?= $(CURDIR)/fresh-run
REF := $(abspath ../x86-multiply-xchg/reference.bin)
.PHONY: build cpu reference
build:
	install -d $(SOURCE)
	tar -xzf producer-source.tar.gz -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
	python3 -c 'import sys;sys.path.insert(0,"$(SOURCE)/kprog/fidelity");import generate;old=generate.x86_forms;generate.x86_forms=lambda aux:[x for x in old(aux) if x.split()[0] in {"rol","ror"}];sys.argv=["generate.py","--arch","x86","--out","$(BUILD)"];generate.main()'
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(SOURCE)/kprog/fidelity/driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $(BUILD)/cpu-differential
cpu:
	install -d $(OUT)
	$(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
reference: $(REF)
	python3 -c 'import json,subprocess,sys;from pathlib import Path;b=Path("$(BUILD)");ops=sorted({x["opcode"] for x in json.loads((b/"coverage.json").read_text()) if x["assembly"].split()[0] in {"rol","ror"}});args=[sys.executable,"$(SOURCE)/kprog/fidelity/reference_check.py","--reuse-trace","--binary",str(b/"cpu-differential"),"--reference","$(REF)","--arch","x86","--cases","1024","--out","$(OUT)"];sys.exit(subprocess.run(args+[item for op in ops for item in ["--opcode",op]]).returncode)'
$(REF):
	$(MAKE) -C $(CURDIR)/../x86-multiply-xchg reference.bin
