# SPDX-License-Identifier: GPL-2.0
# The native lab module of the timing image. kprog/perf/one-image/Makefile builds it
# against the one kernel; `make module` does the same by hand.
ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/perf/direct-native
KDIR ?= /workspaces/.agent-state/kprog-ck/build-x86
OUT ?= $(ROOT)/kinsn/module/x86/build

.PHONY: module
module:
	install -d $(OUT)
	$(MAKE) -C $(KDIR) M=$(HERE) MO=$(OUT) ARCH=x86 modules
