SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := /workspaces/repository/corpus/results/kprog_app_coverage_20261109/katran-regression-current
STATE := /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-regression-runtime
KDIR := /var/tmp/kprog-tmp/C/master-x86-runtime/kernel-build
IMAGE := bpf-benchmark/kprog-katran-restored:c-20261109
IMAGE_TAR := $(STATE)/runtime.image.tar
CPUS ?= 20-23
VM_MEM ?= 12G
VM_CPUS ?= 4
BPFREJIT_CORPUS_BPF_STATS ?= 1
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
APPS ?= katran
.PHONY: corpus guest
corpus:
	install -d $(STATE)/var-tmp
	@cleanup() { for path in "$(STATE)/var-tmp/bpf-benchmark-docker.img" "$(IMAGE_TAR)"; do if test -e "$$path"; then if fuser -s "$$path"; then printf "retaining open experiment file: %s\n" "$$path" >&2; else rm -f -- "$$path"; fi; fi; done; }; trap cleanup EXIT; \
	  test -f "$(IMAGE_TAR)" || docker save -o "$(IMAGE_TAR)" "$(IMAGE)"; \
	  taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(STATE) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'CLANG=/usr/lib/llvm-18/bin/clang BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) make -f $(HERE)/Makefile guest STATE=$(STATE) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) APPS=$(APPS)'
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	PATH=/usr/lib/llvm-18/bin:$$PATH python3 $(HERE)/guest.py --samples $(SAMPLES) --duration $(WORKLOAD_DURATION) --apps $(APPS) --state $(STATE)

.PHONY: generation
generation:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(STATE)/retry-first-generation.py

.PHONY: image
image:
	docker build -f /workspaces/repository/corpus/results/kprog_app_coverage_20261109/katran-regression-current/Dockerfile -t bpf-benchmark/kprog-katran-restored:c-20261109 /var/tmp/kprog-tmp/C/katran-regression-runtime/image

.PHONY: producer
producer:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(ROOT)/corpus/results/kprog_app_coverage_20261109/katran-caller-registers/producer.py
