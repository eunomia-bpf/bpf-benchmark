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
HERE := $(ROOT)/kprog/perf/one-image
KINSN_OUT := $(ROOT)/kinsn/module/x86/build
IMAGE := bpf-benchmark/kprog:current
JOBS ?= 20
# micro/programs/build-x86/kernel_offsets.h is frozen (chattr +i). The one kernel gives the same
# offsets (pahole body identical, 2026-11-11), so the frozen header serves as the input as it is.
OFFSETS := $(ROOT)/micro/programs/build-x86/kernel_offsets.h
OVERRIDES := HOST_KERNEL_BUILD_DIR_X86=$(KDIR) X86_RUNNER_RUNTIME_IMAGE=$(IMAGE) JOBS=$(JOBS) KERNEL_OFFSETS_INPUT=$(OFFSETS)

.PHONY: kernel module image

kernel:
	$(MAKE) -C $(ROOT) host-kernel-x86 $(OVERRIDES)

module: kernel
	rm -rf $(KINSN_OUT) && install -d $(KINSN_OUT)
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/perf/direct-native MO=$(KINSN_OUT) ARCH=x86 modules

image: module
	$(MAKE) -C $(ROOT) x86-runner-runtime-image-tar $(OVERRIDES) -o host-kinsn-x86

# Timing on the one image and the one kernel, with the guest settings of the 2026-11-10
# reproduction of the 2026-05-29 system (kprog/perf/may29-image at 713762fd9): the native lab
# module, the stats sysctl, the unbound shim path, SKIP_REJIT=norejit. STATE holds only the image
# tar link and the guest's docker disk; results land in corpus/results, logs in LOGS.
STATE ?= /var/tmp/kprog-tmp/one-image
LOGS ?= /workspaces/kprog-raw/one-image-runs
IMAGE_TAR := $(ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar
GUEST_IMAGE_TAR := /var/tmp/runtime.image.tar
APPS ?= katran
APP_DIR = $(firstword $(subst /, ,$(APPS)))
CPUS ?= 0-7
VM_CPUS ?= 8
VM_MEM ?= 64G
BPFREJIT_CORPUS_BPF_STATS ?= 0
SAMPLES ?= 3
WORKLOAD_DURATION ?= 180
# Breadth first (operator 2026-11-11: "每个应用跑3次之后换下一个应用这样, 广度优先"):
# one run of three samples per application, then the next application; stats off, then on.
ORDER ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
STATS ?= 0 1

.PHONY: corpus guest rotate

corpus:
	install -d $(STATE)/var-tmp $(LOGS)
	ln -f $(IMAGE_TAR) $(STATE)/var-tmp/runtime.image.tar 2>/dev/null || cp $(IMAGE_TAR) $(STATE)/var-tmp/runtime.image.tar
	cp $(KINSN_OUT)/bpf_x86_native_lab.ko $(STATE)/var-tmp/bpf_x86_native_lab.ko
	taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest APPS=$(APPS) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS)'
	rm -f $(STATE)/var-tmp/bpf-benchmark-docker.img

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /var/tmp/bpf_x86_native_lab.ko
	echo $(if $(filter 0,$(BPFREJIT_CORPUS_BPF_STATS)),0,1) > /proc/sys/kernel/bpf_stats_enabled
	env -u BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF PATH=/usr/lib/llvm-18/bin:$$PATH \
	  BPFREJIT_CORPUS_APPS=$(APPS) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) \
	  BPFREJIT_SHIM_NATIVE_LOADER=post \
	  BPFREJIT_SHIM_NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/$(APP_DIR)/manifest.json \
	  BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so \
	  KEEP_WORKDIRS=all BPFREJIT_KEEP_ALL_WORKDIRS=1 SKIP_REJIT=norejit \
	  $(MAKE) -C $(ROOT) __runtime-vm-corpus PLATFORM=kvm ARCH=x86 \
	  X86_RUNNER_RUNTIME_IMAGE=$(IMAGE) X86_RUNNER_RUNTIME_IMAGE_TAR=$(GUEST_IMAGE_TAR) \
	  SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION)

# LOGS/progress.log names each run's start, end and artifact_run_dir; touch LOGS/STOP to stop
# after the current run.
rotate:
	install -d $(LOGS)
	for s in $(STATS); do for a in $(ORDER); do \
	  [ -e $(LOGS)/STOP ] && exit 0; \
	  echo "$$(date -u +%FT%TZ) start $$a stats=$$s" >> $(LOGS)/progress.log; \
	  log=$(LOGS)/$$(date -u +%Y%m%dT%H%M%SZ)-$$(echo $$a | tr / _)-stats$$s.log; \
	  $(MAKE) -f $(HERE)/Makefile corpus APPS=$$a BPFREJIT_CORPUS_BPF_STATS=$$s > $$log 2>&1 && rc=0 || rc=$$?; \
	  echo "$$(date -u +%FT%TZ) end $$a stats=$$s rc=$$rc run=$$(grep -o '"artifact_run_dir": "[^"]*"' $$log | tail -1 | cut -d'"' -f4)" >> $(LOGS)/progress.log; \
	done; done
