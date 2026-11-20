# SPDX-License-Identifier: GPL-2.0
# arm64 counterpart of kprog/perf/one-image (operator 2026-11-20: "你要确保弄好, 需要支持"): the
# 2026-05-29 arm64 runtime image recipe (runner/mk/build.mk arm64-runner-runtime-image-tar) built on the
# one kernel line in the one base. The recipe's host-kinsn-arm64 step builds the kinsn modules, which
# need the kinsn kernel; on this line its output directory holds the stock-line native lab module from
# kprog/perf/direct-native instead, built for arm64 (the module the shim uploads blob<N> chunks to).
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
KDIR := /workspaces/.agent-state/kprog-ck/build-arm64
KINSN_OUT := $(ROOT)/kinsn/module/arm64/build
JOBS ?= 16
KRELEASE = $(shell cat $(KDIR)/include/config/kernel.release)
# The frozen recipe leaves native-bpf/arm64 empty; vendor/bpf builds the six apps' arm64 natives.
NATIVE_STAGE := $(ROOT)/vendor/build/native-bpf/arm64/stage
OVERRIDES := HOST_KERNEL_BUILD_DIR_ARM64=$(KDIR) JOBS=$(JOBS) NATIVE_BPF_ARTIFACTS_ARM64=$(NATIVE_STAGE)
# The OTel recipe runs its builder with GOARCH=arm64 through binfmt; the cross toolchain's sysroot
# holds the loader it needs.
export QEMU_LD_PREFIX := /usr/aarch64-linux-gnu

.PHONY: kernel module negative native image corpus check

kernel:
	$(MAKE) -C $(ROOT) host-kernel-arm64 $(OVERRIDES)

module: kernel
	rm -rf $(KINSN_OUT) && install -d $(KINSN_OUT)
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/perf/direct-native MO=$(KINSN_OUT) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules

# Same two programs as kprog/perf/one-image's negative target, cross-built for arm64; the corpus never
# runs them.
NEG := $(ROOT)/tests/negative/build-arm64
negative:
	rm -rf /tmp/one-image-arm64-negative && install -d /tmp/one-image-arm64-negative/linux $(NEG)
	for f in adversarial_rejit.c fuzz_rejit.c common.h; do git -C $(ROOT) show 8a118e205^:tests/negative/$$f > /tmp/one-image-arm64-negative/$$f; done
	git -C $(ROOT)/vendor/linux-framework show 4d46ee60994b:include/uapi/linux/bpf.h > /tmp/one-image-arm64-negative/linux/bpf.h
	for t in adversarial_rejit fuzz_rejit; do aarch64-linux-gnu-gcc -O2 -g -Wall -Wno-cpp -I/tmp/one-image-arm64-negative -I$(ROOT)/vendor/linux-framework/include/uapi -o $(NEG)/$$t /tmp/one-image-arm64-negative/$$t.c -lpthread; done
	rm -rf /tmp/one-image-arm64-negative

native: kernel
	$(MAKE) -C $(ROOT)/vendor/bpf native-artifacts ARCH=arm64 VMLINUX_BTF=$(KDIR)/vmlinux KERNEL_RELEASE=$(KRELEASE)

image: module negative native
	$(MAKE) -C $(ROOT) arm64-runner-runtime-image-tar $(OVERRIDES) -o host-kinsn-arm64

# One application in QEMU with the guest settings of kprog/perf/one-image (native lab module, stats
# sysctl, unbound shim path, SKIP_REJIT=norejit) and the frozen qemu-arm64 machine (2 vCPUs, 2G).
# The frozen qemu-arm64-init enters /home/yunwei37/workspace/bpf-benchmark; the root carries a link
# from there to the image workspace.
APPS ?= bcc/set
APP_DIR = $(firstword $(subst /, ,$(APPS)))
SAMPLES ?= 3
WORKLOAD_DURATION ?= 180
BPFREJIT_CORPUS_BPF_STATS ?= 0
NATIVE_MANIFEST ?= /opt/bpf-benchmark/native-bpf/arm64/$(APP_DIR)/manifest.json
SKIP_REJIT_MODE ?= norejit
NATIVE_LOADER_MODE ?= post
# Four vCPUs: Katran's pktgen workload drives kpktgend_0..3.
VM_CPUS ?= 4
VM_MEM ?= 2G
RUN_TOKEN := $(shell od -An -N4 -tx1 /dev/urandom | tr -d " \n")
QROOT := $(ROOT)/.cache/qemu-arm64-root
IMAGE_TAR := $(ROOT)/.cache/container-images/arm64-runner-runtime.image.tar
LOGS ?= /workspaces/kprog-raw/one-image-arm64-runs
corpus:
	$(MAKE) -C $(ROOT) arm64-qemu-root PLATFORM=qemu ARCH=arm64 $(OVERRIDES)
	install -d $(QROOT)/home/yunwei37/workspace && ln -sfn $(ROOT) $(QROOT)/home/yunwei37/workspace/bpf-benchmark
	# As runner/scripts/bpfrejit-install does on an x86 host: the image keeps the kernel modules under
	# /artifacts/lib/modules (veth, bridge and pktgen are modules on arm64), and a Docker-exported root
	# has no localhost entry in /etc/hosts.
	ln -sfn /artifacts/lib/modules $(QROOT)/lib/modules
	printf '127.0.0.1 localhost\n::1 localhost ip6-localhost ip6-loopback\n' > $(QROOT)/etc/hosts
	printf '%s\n' '#!/bin/sh' 'set -eu' 'depmod' 'insmod /artifacts/kinsn/bpf_arm64_native_lab.ko' \
	  'echo $(if $(filter 0,$(BPFREJIT_CORPUS_BPF_STATS)),0,1) > /proc/sys/kernel/bpf_stats_enabled' \
	  'unset BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF' \
	  "export BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 HOME=/root PATH=/usr/lib/llvm-18/bin:\$$PATH TARGET=arm64-qemu RUN_TARGET_NAME=arm64-qemu RUN_TARGET_ARCH=arm64 RUN_EXECUTOR=kvm RUNTIME_CONTAINER_IMAGE=bpf-benchmark/runner-runtime:arm64 RUNTIME_IMAGE_TAR=$(IMAGE_TAR) RUN_REMOTE_PYTHON_BIN=python3 RUN_RUNTIME_PYTHON_BIN=python3 RUN_BPFTOOL_BIN=bpftool RUN_NATIVE_REPOS_CSV=bcc,katran,tracee,tetragon RUN_TOKEN=$(RUN_TOKEN) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) BPFREJIT_CORPUS_APPS=$(APPS) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) BPFREJIT_SHIM_NATIVE_LOADER=$(NATIVE_LOADER_MODE) BPFREJIT_SHIM_NATIVE_MANIFEST=$(NATIVE_MANIFEST) BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so KEEP_WORKDIRS=all BPFREJIT_KEEP_ALL_WORKDIRS=1 SKIP_REJIT=$(SKIP_REJIT_MODE)" \
	  'exec python3 -m corpus.driver' > $(QROOT)/qemu-run.sh
	chmod +x $(QROOT)/qemu-run.sh && : > $(QROOT)/qemu-status
	qemu-system-aarch64 -M virt -cpu cortex-a57 -smp $(VM_CPUS) -m $(VM_MEM) -nographic -no-reboot \
	  -kernel $(KDIR)/arch/arm64/boot/Image \
	  -fsdev local,id=rootfs,path=$(QROOT),security_model=none,multidevs=remap \
	  -device virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root \
	  -append 'console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=4 panic=30 oops=panic raid=noautodetect'
	test "$$(cat $(QROOT)/qemu-status)" = 0
	install -d $(ROOT)/corpus/results && cp -a $(QROOT)$(ROOT)/corpus/results/. $(ROOT)/corpus/results/

# Functional pass, as kprog/perf/one-image check: one 10-second sample per application, stats on.
ORDER ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
check:
	install -d $(LOGS)
	for a in $(ORDER); do \
	  log=$(LOGS)/$$(date -u +%Y%m%dT%H%M%SZ)-check-$$(echo $$a | tr / _).log; \
	  $(MAKE) -f $(ROOT)/kprog/perf/one-image-arm64/Makefile corpus APPS=$$a SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1 > $$log 2>&1 && rc=0 || rc=$$?; \
	  echo "$$(date -u +%FT%TZ) check $$a rc=$$rc run=$$(grep -o '"artifact_run_dir": "[^"]*"' $$log | tail -1 | cut -d'"' -f4)" >> $(LOGS)/check.log; \
	done
