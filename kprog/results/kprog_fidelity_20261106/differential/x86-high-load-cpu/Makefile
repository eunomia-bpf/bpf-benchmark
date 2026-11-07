ROOT := $(abspath ../../../../..)
BUILD := build-x86-native-extension
.PHONY: build cpu
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity build ARCH=x86 BUILD=$(BUILD)
cpu:
	$(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential 1024 $(CURDIR) $(CURDIR)/cpu-states.bin

.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --control-paths --trace $(CURDIR)/cpu-states.bin --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(CURDIR) --reference $(CURDIR)/../x86-divide-cpu/reference.bin
