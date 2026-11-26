ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/cmov-branches-20261126
RESULT ?= $(HERE)
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
KRELEASE := $(shell cat $(KDIR)/include/config/kernel.release)

.PHONY: produce offline
produce:
	$(MAKE) -C $(ROOT)/vendor/bpf native-artifacts ARCH=x86 KERNEL_RELEASE=$(KRELEASE) VMLINUX_BTF=$(KDIR)/vmlinux -j2
offline:
	python3 $(ROOT)/kprog/results/restore-529-20261121/offline_link.py $(ROOT)/vendor/build/native-bpf/x86/stage x86 > $(RESULT)/offline-x86.log
