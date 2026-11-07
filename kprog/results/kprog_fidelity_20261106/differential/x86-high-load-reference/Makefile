ROOT := $(abspath ../../../../..)
.PHONY: reference
reference: reference.bin
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --control-paths --trace ../x86-full-conditions/cpu-states.bin --binary $(ROOT)/kprog/fidelity/build-x86-full-conditions/cpu-differential --arch x86 --cases 1024 --out . --reference $(CURDIR)/reference.bin
reference.bin: reference.gz
	gzip -dc $< > $@
	chmod +x $@
