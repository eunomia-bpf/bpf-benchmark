ROOT := /workspaces/repository
BUILD := $(ROOT)/kprog/fidelity/build-x86-leave64-boundaries
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries
.PHONY: run
$(BUILD)/leave64: $(ROOT)/kprog/fidelity/leave64.c $(ROOT)/kprog/fidelity/leave64.S
	install -d $(BUILD)
	cc -O2 -g -Wall -Wextra -Werror -std=gnu11 -static $^ -o $@
run: $(BUILD)/leave64
	$(BUILD)/leave64 $(OUT) --boundaries

.PHONY: control
$(BUILD)/address-control: $(OUT)/address_control.c
	install -d $(BUILD)
	cc -O2 -g -fomit-frame-pointer -Wall -Wextra -Werror -std=gnu11 -static $< -o $@
control: $(BUILD)/address-control
	$(BUILD)/address-control $(OUT)/control-inputs.tsv $(OUT)

.PHONY: kvm
kvm:
	taskset -c 16-19 vng --verbose --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic clearcpuid=lass' --exec 'bash $(OUT)/guest.sh'

.PHONY: default
default: $(BUILD)/leave64
	$(BUILD)/leave64 $(OUT)/baseline
