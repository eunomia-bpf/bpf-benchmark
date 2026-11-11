# SPDX-License-Identifier: GPL-2.0
# The one image and the one base (AGENTS.md, first section): the 2026-05-29 runtime image
# recipe (runner/mk/build.mk, runner/containers/runner-runtime.Dockerfile, both at 9f3855f6f)
# built on the one kernel line in the one base. The frozen recipe's host-kinsn-x86 step builds
# the kinsn modules, which need the kinsn kernel; on this line its output directory holds the
# stock-line native lab module from kprog/perf/direct-native instead.
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
KINSN_OUT := $(ROOT)/kinsn/module/x86/build
IMAGE := bpf-benchmark/kprog:current
JOBS ?= 20
OVERRIDES := HOST_KERNEL_BUILD_DIR_X86=$(KDIR) X86_RUNNER_RUNTIME_IMAGE=$(IMAGE) JOBS=$(JOBS)

.PHONY: kernel module image

kernel:
	$(MAKE) -C $(ROOT) host-kernel-x86 $(OVERRIDES)

module: kernel
	rm -rf $(KINSN_OUT) && install -d $(KINSN_OUT)
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/perf/direct-native MO=$(KINSN_OUT) ARCH=x86 modules

image: module
	$(MAKE) -C $(ROOT) x86-runner-runtime-image-tar $(OVERRIDES) -o host-kinsn-x86
