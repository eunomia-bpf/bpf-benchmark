ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86-six-flags
.PHONY: freeze reference
freeze:
	python3 freeze.py $(BUILD)
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(BUILD)/cpu-differential --arch x86 --cases 1024 --out . --reference $(BUILD)/reference
