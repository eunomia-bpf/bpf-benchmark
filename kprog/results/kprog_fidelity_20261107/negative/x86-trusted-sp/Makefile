ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp
RUN_OUT ?= $(OUT)
.PHONY: build guest kvm
build:
	python3 $(OUT)/check.py build
guest:
	bash $(OUT)/guest.sh $(RUN_OUT)
kvm:
	bash $(OUT)/run.sh $(RUN_OUT)
