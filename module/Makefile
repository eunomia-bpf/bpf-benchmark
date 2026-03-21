# SPDX-License-Identifier: GPL-2.0
# Top-level Makefile for BpfReJIT kinsn kernel modules

SUBDIRS := x86

all clean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d $@; done

.PHONY: all clean
