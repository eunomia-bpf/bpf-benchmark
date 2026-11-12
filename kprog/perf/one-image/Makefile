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
# Native x86 code keeps the struct layout it was compiled with, so vendor/bpf generates the vmlinux
# headers of its BCC and Tetragon native objects from the one kernel (by default it reads the build
# machine's /sys/kernel/btf/vmlinux). The committed Tetragon header carries another kernel's
# task_struct layout.
KRELEASE = $(shell cat $(KDIR)/include/config/kernel.release)
OVERRIDES := HOST_KERNEL_BUILD_DIR_X86=$(KDIR) X86_RUNNER_RUNTIME_IMAGE=$(IMAGE) JOBS=$(JOBS) KERNEL_OFFSETS_INPUT=$(OFFSETS) \
	VMLINUX_BTF=$(KDIR)/vmlinux KERNEL_RELEASE=$(KRELEASE)

.PHONY: kernel module negative tetragon-base image

kernel:
	$(MAKE) -C $(ROOT) host-kernel-x86 $(OVERRIDES)

module: kernel
	rm -rf $(KINSN_OUT) && install -d $(KINSN_OUT)
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/perf/direct-native MO=$(KINSN_OUT) ARCH=x86 modules

# The 2026-05-29 Dockerfile copies tests/negative/build/{adversarial_rejit,fuzz_rejit}. Their sources
# left the tree on 2026-05-17 (8a118e205), so the 2026-05-29 build used binaries left in that
# directory. They are built here from their last source against the ReJIT uapi they were written
# for (4d46ee60994b); the corpus never runs them.
NEG := $(ROOT)/tests/negative/build
negative:
	rm -rf /tmp/one-image-negative && install -d /tmp/one-image-negative/linux $(NEG)
	for f in adversarial_rejit.c fuzz_rejit.c common.h; do git -C $(ROOT) show 8a118e205^:tests/negative/$$f > /tmp/one-image-negative/$$f; done
	git -C $(ROOT)/vendor/linux-framework show 4d46ee60994b:include/uapi/linux/bpf.h > /tmp/one-image-negative/linux/bpf.h
	for t in adversarial_rejit fuzz_rejit; do cc -O2 -g -Wall -Wno-cpp -I/tmp/one-image-negative -I$(ROOT)/vendor/linux-framework/include/uapi -o $(NEG)/$$t /tmp/one-image-negative/$$t.c -lpthread; done
	rm -rf /tmp/one-image-negative

# Tetragon's bpf/Makefile has a rule for its base (unversioned) objects only under the literal
# objs/ directory, so the application recipe's OBJSDIR override builds just the kernel-version
# variants. The agent's startup needs base objects such as bpf_alignchecker.o; the 2026-05-29 image
# carried them from earlier builds. They are built here from the same 2026-05-29 source and compiler
# in the submodule's own objs/, copied next to the variants, and objs/ is removed again.
TETRAGON_BPF := $(ROOT)/vendor/repos/tetragon/bpf
tetragon-base:
	$(MAKE) -C $(ROOT) host-source-apps-x86 $(OVERRIDES)
	$(MAKE) -C $(TETRAGON_BPF) CLANG=clang-18 LLC=llc-18 BPF_TARGET_ARCH=x86 -j$(JOBS)
	for o in $(TETRAGON_BPF)/objs/*.o; do case $$(basename $$o) in *_v[0-9]*) ;; *) cp $$o $(ROOT)/vendor/build/x86/tetragon/;; esac; done
	rm -rf $(TETRAGON_BPF)/objs $(TETRAGON_BPF)/deps

image: module negative tetragon-base
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
# The native configuration switch. The default is the image's own manifest, the
# 2026-05-29 path with no load-time specialization. Pointing it at a directory
# built by vendor/bpf/native_specialize_objects.py selects the specialized
# objects (.rodata values as constants, array lookups as address arithmetic);
# the path must be one the runtime container sees (corpus/results is mounted).
NATIVE_MANIFEST ?= /opt/bpf-benchmark/native-bpf/x86_64/$(APP_DIR)/manifest.json
# The pass list for the load-time plan; empty keeps the frozen default. A capture
# run uses map-only so the driver writes each program's map snapshots.
BENCH_PASSES ?=
# Extra vng flags, for example --verbose to keep the guest kernel console in the log.
VNG_FLAGS ?=
# Breadth first (operator 2026-11-11: "每个应用跑3次之后换下一个应用这样, 广度优先"):
# one run of three samples per application, then the next application; stats off, then on.
ORDER ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
STATS ?= 0 1

.PHONY: corpus guest rotate check

corpus:
	install -d $(STATE)/var-tmp $(LOGS)
	ln -f $(IMAGE_TAR) $(STATE)/var-tmp/runtime.image.tar 2>/dev/null || cp $(IMAGE_TAR) $(STATE)/var-tmp/runtime.image.tar
	cp $(KINSN_OUT)/bpf_x86_native_lab.ko $(STATE)/var-tmp/bpf_x86_native_lab.ko
	taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor $(VNG_FLAGS) --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest APPS=$(APPS) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) NATIVE_MANIFEST=$(NATIVE_MANIFEST) BENCH_PASSES=$(BENCH_PASSES)'
	rm -f $(STATE)/var-tmp/bpf-benchmark-docker.img

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /var/tmp/bpf_x86_native_lab.ko
	echo $(if $(filter 0,$(BPFREJIT_CORPUS_BPF_STATS)),0,1) > /proc/sys/kernel/bpf_stats_enabled
	env -u BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF PATH=/usr/lib/llvm-18/bin:$$PATH \
	  BPFREJIT_CORPUS_APPS=$(APPS) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) \
	  BPFREJIT_SHIM_NATIVE_LOADER=post \
	  BPFREJIT_SHIM_NATIVE_MANIFEST=$(NATIVE_MANIFEST) \
	  BPFREJIT_BENCH_PASSES=$(BENCH_PASSES) \
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

# Functional pass before timing: one 10-second sample per application with stats on, so a
# native load that needs a change shows up before a 3x180 s baseline is spent on it.
check:
	install -d $(LOGS)
	for a in $(ORDER); do \
	  log=$(LOGS)/$$(date -u +%Y%m%dT%H%M%SZ)-check-$$(echo $$a | tr / _).log; \
	  $(MAKE) -f $(HERE)/Makefile corpus APPS=$$a SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1 > $$log 2>&1 && rc=0 || rc=$$?; \
	  echo "$$(date -u +%FT%TZ) check $$a rc=$$rc run=$$(grep -o '"artifact_run_dir": "[^"]*"' $$log | tail -1 | cut -d'"' -f4)" >> $(LOGS)/check.log; \
	done
