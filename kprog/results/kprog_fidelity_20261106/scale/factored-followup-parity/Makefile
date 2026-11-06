ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86/scale-factored-followup-parity
NAMES := n10000_ptr_indirect n100000_scalar_indirect
.PHONY: build kvm guest
build: $(BUILD)/scale-probe $(addprefix $(BUILD)/,$(NAMES))
$(BUILD)/scale-probe: $(ROOT)/kprog/fidelity/scale_probe.c
	install -d $(BUILD)
	$(CC) -Wall -Wextra -Werror -O2 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $< $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@
$(BUILD)/%: $(ROOT)/kprog/fidelity/build-x86/scale/%.native.o $(ROOT)/kprog/fidelity/scale_native_probe.c
	install -d $(BUILD)
	$(CC) -Wall -Wextra -Werror -O2 -static $(ROOT)/kprog/fidelity/scale_native_probe.c $< -o $@
kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'make -C $(CURDIR) guest'
guest:
	python3 check.py $(BUILD)
