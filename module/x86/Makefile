# SPDX-License-Identifier: GPL-2.0
# Out-of-tree build for BpfReJIT x86 kinsn modules

KDIR ?= $(CURDIR)/../../vendor/linux-framework

ccflags-y += -I$(src)/../include

obj-m += bpf_x86_rotate.o
obj-m += bpf_x86_cmov.o
obj-m += bpf_x86_alu_imm.o
obj-m += bpf_x86_alu_mem.o
obj-m += bpf_x86_mov_mem.o
obj-m += bpf_x86_mov_store.o
obj-m += bpf_x86_mov_reg.o
obj-m += bpf_x86_byteorder.o
obj-m += bpf_x86_lea.o
obj-m += bpf_x86_prefetch.o
obj-m += bpf_x86_mov_sib.o
obj-m += bpf_x86_movbe_sib.o
obj-m += bpf_x86_popcnt.o
obj-m += bpf_x86_bmi1.o
obj-m += bpf_x86_imul.o
obj-m += bpf_x86_not.o
obj-m += bpf_x86_shd.o

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all clean
