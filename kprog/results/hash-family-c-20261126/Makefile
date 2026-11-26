ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/hash-family-c-20261126
LOCKS := /workspaces/.agent-state/kprog-lanes/locks

.PHONY: check offline module-arm64 loaders
check:
	$(MAKE) -C $(ROOT)/kprog/results/hash-c-lto-20261120 check OUT=$(HERE)/host
offline:
	python3 $(ROOT)/kprog/results/restore-529-20261121/offline_link.py $(ROOT)/vendor/build/native-bpf/x86/stage x86 > $(HERE)/offline-x86.log
	python3 $(ROOT)/kprog/results/restore-529-20261121/offline_link.py $(ROOT)/vendor/build/native-bpf/arm64/stage arm64 > $(HERE)/offline-arm64.log
module-arm64:
	$(MAKE) -C /workspaces/.agent-state/kprog-ck/build-arm64 M=$(ROOT)/kprog/perf/direct-native MO=$(ROOT)/kinsn/module/arm64/build ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
loaders:
	$(MAKE) -C $(ROOT)/runner/build-llvmbpf native_loader_shared -j2
	$(MAKE) -C $(ROOT)/runner/build-arm64-llvmbpf native_loader_shared -j2
