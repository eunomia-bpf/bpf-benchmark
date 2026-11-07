ROOT := $(abspath ../../../../..)
SOURCE := $(ROOT)/kprog/fidelity/build-sp-entry-replay/source
BUILD := $(SOURCE)/kprog/fidelity/build-cpu
OUT ?= $(CURDIR)/fresh-run
REF := $(abspath ../x86-multiply-xchg/reference.bin)
.PHONY: source build cpu reference
source:
	install -d $(SOURCE)
	tar -xzf producer-source.tar.gz -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
build: source
	python3 -c 'import sys;sys.path.insert(0,"$(SOURCE)/kprog/fidelity");import generate;generate.x86_forms=lambda aux:["mov rax, rsp","mov eax, esp","lea rax, [rsp+16]","cmp rsp, 0","mov rsp, rax","mov esp, eax","lea rsp, [rsp+16]","add rsp, 16","push rsp","pop rsp","push sp","pop sp"];sys.argv=["generate.py","--arch","x86","--out","$(BUILD)"];generate.main()'
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(SOURCE)/kprog/fidelity/driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $(BUILD)/cpu-differential
cpu:
	install -d $(OUT)
	$(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
reference: $(REF)
	python3 -c 'import json,subprocess,sys;from pathlib import Path;b=Path("$(BUILD)");ops=sorted({x["opcode"] for x in json.loads((b/"coverage.json").read_text())[:12]});args=[sys.executable,"$(SOURCE)/kprog/fidelity/reference_check.py","--reuse-trace","--binary",str(b/"cpu-differential"),"--reference","$(REF)","--arch","x86","--cases","1024","--out","$(OUT)"];sys.exit(subprocess.run(args+[item for op in ops for item in ["--opcode",op]]).returncode)'
$(REF):
	$(MAKE) -C $(CURDIR)/../x86-multiply-xchg reference.bin
