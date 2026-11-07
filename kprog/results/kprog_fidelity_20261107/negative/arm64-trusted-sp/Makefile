ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp
.PHONY: build qemu
build:
	python3 $(OUT)/replay.py build
qemu:
	python3 $(OUT)/replay.py host
