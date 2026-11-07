ROOT := $(abspath ../../../../..)
BUILD := build-x86/divide-fault
OUT := ../results/kprog_fidelity_20261106/negative/x86-divide-fault
.PHONY: build run
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=x86 NEGATIVE_BUILD=$(BUILD)
run:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=$(BUILD) NEGATIVE_BOUND_OUT=$(OUT)
