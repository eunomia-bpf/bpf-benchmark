# SPDX-License-Identifier: GPL-2.0
# Out-of-tree build for BpfReJIT ARM64 kinsn modules

KDIR ?= $(CURDIR)/../../vendor/linux-framework

ccflags-y += -I$(src)/../include

obj-m += bpf_arm64_extr.o
obj-m += bpf_arm64_csel.o
obj-m += bpf_arm64_ccmp.o
obj-m += bpf_arm64_ubfm.o
obj-m += bpf_arm64_ldr.o
obj-m += bpf_arm64_str.o
obj-m += bpf_arm64_mov.o
obj-m += bpf_arm64_rev.o
obj-m += bpf_arm64_ldp.o
obj-m += bpf_arm64_prfm.o
obj-m += bpf_arm64_native_lab.o

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all clean
