ROOT := $(abspath ../../../../..)
OLD := $(ROOT)/kprog/results/kprog_fidelity_20261106/differential/x86-high-load-cpu
BUILD := $(ROOT)/kprog/fidelity/build-x86-lea-reference
.PHONY: prepare reference
prepare:
	install -d $(BUILD)
	tar -xOzf $(OLD)/observer-source.tar.gz coverage.json > $(BUILD)/coverage.json
	gzip -dc $(OLD)/cpu-differential.gz > $(BUILD)/cpu-differential
	chmod +x $(BUILD)/cpu-differential
	cp $(OLD)/forms.tsv forms.tsv
	cp $(OLD)/native-code.json native-code.json
reference: prepare reference.bin
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --opcode X86_OP_LEA --trace $(OLD)/cpu-states.bin --binary $(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(CURDIR) --reference $(CURDIR)/reference.bin
reference.bin: reference.gz
	gzip -dc $< > $@
	chmod +x $@
