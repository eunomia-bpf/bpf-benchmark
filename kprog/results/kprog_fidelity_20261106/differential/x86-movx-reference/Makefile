ROOT := $(abspath ../../../../..)
.PHONY: reference freeze
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --control-paths --trace ../x86-full-conditions/cpu-states.bin --binary $(ROOT)/kprog/fidelity/build-x86-full-conditions/cpu-differential --arch x86 --cases 1024 --out . --reference $(CURDIR)/reference
freeze:
	python3 freeze.py
