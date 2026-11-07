ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-dshift-cl16
BUILD := build-x86-dshift-cl16
REFERENCE := /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen
.PHONY: build reference
build:
	python3 $(OUT)/select.py
	$(MAKE) -C $(ROOT)/kprog/fidelity ARCH=x86 BUILD=$(BUILD) $(BUILD)/generated.o
	cc -O1 -g -std=gnu11 -static -I$(ROOT)/kprog/fidelity $(ROOT)/kprog/fidelity/$(BUILD)/driver-sample.c $(ROOT)/kprog/fidelity/$(BUILD)/generated.o $(ROOT)/kprog/fidelity/$(BUILD)/native.S -o $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential
reference: build
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(OUT) --reference $(REFERENCE)
