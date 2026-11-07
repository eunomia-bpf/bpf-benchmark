ROOT := $(abspath ../../../../..)
BUILD := build-x86-lea-addressing-fixed
REFERENCE := $(abspath ../x86-lea-published/reference.bin)
.PHONY: build cpu reference
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity build ARCH=x86 BUILD=$(BUILD)
cpu:
	$(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential 1024 $(CURDIR) $(CURDIR)/cpu-states.bin
reference: $(REFERENCE)
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --opcode X86_OP_LEA --trace $(CURDIR)/cpu-states.bin --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(CURDIR) --reference $(REFERENCE)
$(REFERENCE):
	$(MAKE) -C $(CURDIR)/../x86-lea-published reference.bin

.PHONY: proof
proof:
	cd $(ROOT)/kprog/formal && lake env lean KProgFormal/Refinement/X86Lea.lean
