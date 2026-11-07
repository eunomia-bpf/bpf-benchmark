ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp
.PHONY: build guest kvm
build:
	python3 $(OUT)/check.py build
guest:
	bash $(OUT)/guest.sh
kvm:
	bash $(OUT)/run.sh
