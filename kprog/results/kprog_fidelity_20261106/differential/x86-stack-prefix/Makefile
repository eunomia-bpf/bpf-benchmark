BUILD := ../../../../fidelity/build-x86-v-prefix
.PHONY: check
check:
	install -d $(BUILD)
	$(CC) -O2 cpu-prefix.c -o $(BUILD)/cpu-prefix
	$(BUILD)/cpu-prefix
