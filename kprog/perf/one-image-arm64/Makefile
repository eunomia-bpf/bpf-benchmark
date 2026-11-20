# SPDX-License-Identifier: GPL-2.0
# arm64 counterpart of kprog/perf/one-image (operator 2026-11-20: "你要确保弄好, 需要支持"): the
# 2026-05-29 arm64 runtime image recipe (runner/mk/build.mk arm64-runner-runtime-image-tar) built on the
# one kernel line in the one base. The recipe's host-kinsn-arm64 step builds the kinsn modules, which
# need the kinsn kernel; on this line its output directory holds the stock-line native lab module from
# kprog/stock-path/module instead.
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
KDIR := /workspaces/.agent-state/kprog-ck/build-arm64
KINSN_OUT := $(ROOT)/kinsn/module/arm64/build
JOBS ?= 16
OVERRIDES := HOST_KERNEL_BUILD_DIR_ARM64=$(KDIR) JOBS=$(JOBS)
# The OTel recipe runs its builder with GOARCH=arm64 through binfmt; the cross toolchain's sysroot
# holds the loader it needs.
export QEMU_LD_PREFIX := /usr/aarch64-linux-gnu

.PHONY: kernel module negative image

kernel:
	$(MAKE) -C $(ROOT) host-kernel-arm64 $(OVERRIDES)

module: kernel
	rm -rf $(KINSN_OUT) && install -d $(KINSN_OUT)
	$(MAKE) -C $(ROOT)/kprog/stock-path/module KDIR=$(KDIR) MO=$(KINSN_OUT) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-

# Same two programs as kprog/perf/one-image's negative target, cross-built for arm64; the corpus never
# runs them.
NEG := $(ROOT)/tests/negative/build-arm64
negative:
	rm -rf /tmp/one-image-arm64-negative && install -d /tmp/one-image-arm64-negative/linux $(NEG)
	for f in adversarial_rejit.c fuzz_rejit.c common.h; do git -C $(ROOT) show 8a118e205^:tests/negative/$$f > /tmp/one-image-arm64-negative/$$f; done
	git -C $(ROOT)/vendor/linux-framework show 4d46ee60994b:include/uapi/linux/bpf.h > /tmp/one-image-arm64-negative/linux/bpf.h
	for t in adversarial_rejit fuzz_rejit; do aarch64-linux-gnu-gcc -O2 -g -Wall -Wno-cpp -I/tmp/one-image-arm64-negative -I$(ROOT)/vendor/linux-framework/include/uapi -o $(NEG)/$$t /tmp/one-image-arm64-negative/$$t.c -lpthread; done
	rm -rf /tmp/one-image-arm64-negative

image: module negative
	$(MAKE) -C $(ROOT) arm64-runner-runtime-image-tar $(OVERRIDES) -o host-kinsn-arm64
