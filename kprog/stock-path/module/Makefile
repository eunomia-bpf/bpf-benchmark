# SPDX-License-Identifier: GPL-2.0
# make KDIR=<O= build dir> MO=<object dir>
ifneq ($(KERNELRELEASE),)
obj-m += bpf_$(SRCARCH)_native_lab.o
bpf_$(SRCARCH)_native_lab-y := kprog_stock.o
else
KDIR ?= /workspaces/.agent-state/kprog-ck/build-x86
MO ?= /workspaces/.agent-state/kprog-ck/verified-module
all:
	install -d $(MO)
	$(MAKE) -C $(KDIR) M=$(CURDIR) MO=$(MO) modules
endif
