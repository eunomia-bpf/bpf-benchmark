# SPDX-License-Identifier: GPL-2.0
# Six applications on the 2026-05-29 native path, run from this tree, see README.md.
# Timing only: the native code runs on the unbound path without verification.
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/perf/may29-image
ART ?= /var/tmp/kprog-tmp/R/six
STATE ?= /var/tmp/kprog-tmp/R/may29-image
IMAGE ?= bpf-benchmark/kprog-may29-six:main
IMAGE_TAR := $(STATE)/var-tmp/runtime.image.tar
GUEST_IMAGE_TAR := /var/tmp/runtime.image.tar
ARTIFACTS := modules bzImage kernel.config kernel_offsets.h kinsn native-bpf libnative_loader.so libbpfrejit_shim.so native-link
FRAMEWORK := Makefile runner corpus/driver.py corpus/config corpus/inputs micro/config vendor/bpfrejit_x86_defconfig
FROZEN := 9f3855f6f
APPS ?= katran
APP_DIR = $(firstword $(subst /, ,$(APPS)))
CPUS ?= 0-7
VM_CPUS ?= 8
VM_MEM ?= 64G
BPFREJIT_CORPUS_BPF_STATS ?= 1
SAMPLES ?= 3
WORKLOAD_DURATION ?= 180
RUNS ?= otelcol-ebpf-profiler/profiling:0 bcc/set:1 bcc/set:0 cilium/agent:1 cilium/agent:0 tetragon/observer:1 tetragon/observer:0 tracee/monitor:1 tracee/monitor:0 katran:1 katran:0 otelcol-ebpf-profiler/profiling:1

.PHONY: image corpus guest six tetragon-manifest

# The 2026-05-29 build wrote Tetragon's manifest with these flags (9f3855f6f vendor/bpf/Makefile,
# native-tetragon); the frozen generator rewrites ART's Tetragon manifest the same way, so each
# kernel-version variant resolves to one object.
TETRAGON_NATIVE := $(ART)/native-bpf/x86_64/tetragon
tetragon-manifest:
	cd $(ROOT) && git show $(FROZEN):vendor/bpf/write_native_manifest.py | python3 - --app tetragon \
	  --llvm-nm /usr/lib/llvm-18/bin/llvm-nm --dedupe-program last \
	  --source-object-root $(ROOT)/vendor/build/x86/tetragon --helper-disambiguate 174 \
	  --output $(TETRAGON_NATIVE)/manifest.json $(addprefix --object ,$(sort $(wildcard $(TETRAGON_NATIVE)/*.native.o)))

# The framework files come from this repository's frozen commit through git archive,
# joined with the build outputs into one build context that is removed after the build.
image:
	install -d $(STATE)/var-tmp
	git -C $(ROOT) archive --format=tar -o $(STATE)/context.tar $(FROZEN) -- $(FRAMEWORK)
	tar -r -f $(STATE)/context.tar -C $(ART) $(ARTIFACTS) -C $(HERE) Dockerfile
	docker build -f Dockerfile -t $(IMAGE) - < $(STATE)/context.tar
	rm -f $(STATE)/context.tar $(IMAGE_TAR)
	docker save -o $(IMAGE_TAR) $(IMAGE)

corpus:
	install -d $(STATE)/var-tmp
	cp $(ART)/kinsn/bpf_x86_native_lab.ko $(STATE)/var-tmp/bpf_x86_native_lab.ko
	taskset -c $(CPUS) vng --run $(ART)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest IMAGE=$(IMAGE) APPS=$(APPS) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS)'
	rm -f $(STATE)/var-tmp/bpf-benchmark-docker.img

# The 2026-05-29 shim loads the native programs itself, so the guest starts no
# trusted service: the native lab module, the stats sysctl, and the unbound environment.
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

# One run at a time, in RUNS order; STATE/progress.log names each run's start and end.
six:
	install -d $(STATE)
	for r in $(RUNS); do \
	  [ -e $(STATE)/STOP ] && break; \
	  echo "$$(date -u +%FT%TZ) start $$r" >> $(STATE)/progress.log; \
	  $(MAKE) -f $(HERE)/Makefile corpus APPS=$${r%:*} BPFREJIT_CORPUS_BPF_STATS=$${r##*:} > $(STATE)/$$(echo $$r | tr /: __).log 2>&1 && rc=0 || rc=$$?; \
	  echo "$$(date -u +%FT%TZ) end $$r rc=$$rc run=$$(ls -dt $(ROOT)/corpus/results/x86_kvm_corpus_* | head -1)" >> $(STATE)/progress.log; \
	done
