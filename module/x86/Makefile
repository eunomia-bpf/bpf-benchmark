# SPDX-License-Identifier: GPL-2.0
# Out-of-tree build for BpfReJIT x86 kinsn modules

KDIR ?= $(CURDIR)/../../vendor/linux-framework

obj-m += bpf_rotate.o
obj-m += bpf_select.o
obj-m += bpf_extract.o

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all clean
