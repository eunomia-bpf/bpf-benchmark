ROOT := $(abspath ../../../../..)
BUILD := build-x86-lea-sp-after
.PHONY: check
check:
	python3 -c "import sys; sys.path.insert(0,'$(ROOT)/kprog/fidelity'); import generate; generate.x86_forms=lambda: ['lea rsp, [rsp+16]']; sys.argv=['generate.py','--arch','x86','--out','$(ROOT)/kprog/fidelity/$(BUILD)']; generate.main()"
	$(MAKE) -C $(ROOT)/kprog/fidelity -o $(BUILD)/generated.c -o $(BUILD)/native.S build BUILD=$(BUILD)
	$(MAKE) -C $(ROOT)/kprog/fidelity run-built BUILD=$(BUILD) OUT=$(CURDIR)
