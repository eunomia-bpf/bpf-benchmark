ROOT := /workspaces/repository
BUILD := $(ROOT)/kprog/fidelity/build-x86-leave64
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-leave64
.PHONY: run
$(BUILD)/leave64: $(ROOT)/kprog/fidelity/leave64.c $(ROOT)/kprog/fidelity/leave64.S
	install -d $(BUILD)
	cc -O2 -g -Wall -Wextra -Werror -std=gnu11 -static $^ -o $@
run: $(BUILD)/leave64
	$(BUILD)/leave64 $(OUT)
