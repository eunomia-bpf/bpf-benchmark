# LTO configuration (checked-sim-c) timing for one app, the recipe of native-cohort-timing-20261119 with the app
# as a parameter: run_lto.sh, 3 x 180 s per arm, stats on, CPUs 0-7, 8 vCPUs, 64 GiB, frozen kvm-host-cpu step.
ROOT := /workspaces/repository
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
LOADER := /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
COMPILER := /workspaces/.agent-state/kprog-ck/verified-compiler
GUEST_BUILD := /var/tmp/kprog-tmp/verified/lto-config
APP ?= tracee/monitor

.PHONY: checked-timing
checked-timing:
	install -d $(OUT) $(OUT)/loader-inputs $(OUT)/bounds-inputs $(GUEST_BUILD)
	$(MAKE) -C $(ROOT) kvm-host-cpu
	taskset -c 0-7 prlimit --as=103079215104 -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUT) --rwdir /var/tmp=$(GUEST_BUILD) \
		--rodir $(OUT)/loader-inputs=$(dir $(LOADER)) --rodir $(OUT)/bounds-inputs=$(COMPILER) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(ROOT)/kprog/results/lto-config-20261119/run_lto.sh $(OUT) $(APP) $(OUT)/loader-inputs/$(notdir $(LOADER)) $(OUT)/bounds-inputs/packet-bounds 3 180 1'
	rm -f $(GUEST_BUILD)/bpf-benchmark-docker.img
