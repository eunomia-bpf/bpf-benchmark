# SPDX-License-Identifier: GPL-2.0
# make KDIR=<O= build dir> MO=<object dir>
ifneq ($(KERNELRELEASE),)
obj-m += bpf_kprog_stock.o
bpf_kprog_stock-y := kprog_stock.o
else
KDIR ?= /var/tmp/kprog-tmp/CK/build
MO ?= /var/tmp/kprog-tmp/CK/mod
all:
	mkdir -p $(MO)
	$(MAKE) -C $(KDIR) M=$(CURDIR) MO=$(MO) modules
endif
