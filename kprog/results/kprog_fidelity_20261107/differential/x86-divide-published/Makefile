ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-div-published
SOURCE := $(BUILD)/source
CPU_BUILD := $(SOURCE)/kprog/fidelity/build-division
.PHONY: source build cpu reference
source:
	install -d $(SOURCE)
	tar -xzf producer-source.tar.gz -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
build: source
	python3 $(SOURCE)/kprog/fidelity/x86_division.py build $(CPU_BUILD)
	cc -O1 -g -std=gnu11 -static -I$(SOURCE)/kprog/fidelity -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(CPU_BUILD)/fault-driver.c $(CPU_BUILD)/generated.c $(CPU_BUILD)/native.S -o $(CPU_BUILD)/cpu-differential
cpu:
	$(CPU_BUILD)/cpu-differential 2048 $(CURDIR)
reference: reference.bin observations.jsonl
	python3 $(ROOT)/kprog/fidelity/x86_division.py reference $(CURDIR)/observations.jsonl $(CURDIR)/reference.bin $(CURDIR)
reference.bin: reference.gz
	gzip -dc $< > $@
	chmod +x $@
observations.jsonl:
	gzip -dc observations.jsonl.gz > $@
