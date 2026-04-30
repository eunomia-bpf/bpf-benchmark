# SPDX-License-Identifier: GPL-2.0
# Out-of-tree build for BpfReJIT ARM64 kinsn modules

KDIR ?= $(CURDIR)/../../vendor/linux-framework

ccflags-y += -I$(src)/../include

obj-m += bpf_rotate.o
obj-m += bpf_select.o
obj-m += bpf_ccmp.o
obj-m += bpf_extract.o
obj-m += bpf_endian.o
obj-m += bpf_ldp.o
obj-m += bpf_bulk_memory.o

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all clean
