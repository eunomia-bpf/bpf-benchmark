ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86-division
REFERENCE ?= $(CURDIR)/reference.bin
.PHONY: build cpu reference
build:
	python3 $(ROOT)/kprog/fidelity/x86_division.py build $(BUILD)
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/kprog/fidelity -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $(BUILD)/fault-driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $(BUILD)/cpu-differential
cpu:
	$(BUILD)/cpu-differential 1024 $(CURDIR)
reference: reference.bin observations.jsonl
	python3 $(ROOT)/kprog/fidelity/x86_division.py reference $(CURDIR)/observations.jsonl $(REFERENCE) $(CURDIR)
reference.bin: reference.gz
	gzip -dc $< > $@
	chmod +x $@
observations.jsonl:
	gzip -dc observations.jsonl.gz > $@
