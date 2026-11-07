ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-arm-control-canonical-replay
OUT ?= $(CURDIR)/fresh-run
.PHONY: frozen cpu cpu-hardware reference
frozen:
	install -d $(BUILD)
	gzip -dc cpu-differential.gz > $(BUILD)/cpu-differential
	chmod +x $(BUILD)/cpu-differential
	cp coverage.json $(BUILD)/coverage.json
	gzip -dc reference.gz > $(BUILD)/reference
	chmod +x $(BUILD)/reference
cpu: frozen
	install -d $(OUT)
	taskset -c 16-19 qemu-aarch64-static -cpu cortex-a72 $(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
cpu-hardware:
	test "$$(uname -m)" = aarch64
	install -d $(BUILD) $(OUT)
	gzip -dc cpu-differential.gz > $(BUILD)/cpu-differential
	chmod +x $(BUILD)/cpu-differential
	cp coverage.json $(BUILD)/coverage.json
	$(BUILD)/cpu-differential 1024 $(OUT) $(OUT)/cpu-states.bin
reference:
	taskset -c 16-19 python3 $(ROOT)/kprog/fidelity/arm64_reference_path.py --binary $(BUILD)/cpu-differential --reference $(BUILD)/reference --out $(OUT) --cases 1024
