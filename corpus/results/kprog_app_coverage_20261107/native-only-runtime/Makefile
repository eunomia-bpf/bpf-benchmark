SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261107/native-only-runtime
STATE := /workspaces/.agent-state/kprog-lanes/C/native-only-runtime
KDIR := $(ROOT)/kprog/tv/build-kernel-x86
IMAGE := bpf-benchmark/kprog-native-only:x86-current
IMAGE_TAR := $(STATE)/runtime.image.tar
CPUS ?= 16-19
BPFREJIT_CORPUS_BPF_STATS ?= 1
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
APPS ?= bcc/set
.PHONY: modules package image corpus guest
modules:
	$(MAKE) -C $(KDIR) M=$(ROOT)/kinsn/module/x86 MO=$(ROOT)/kprog/tv/build-x86/corpus-modules ARCH=x86 modules
	$(MAKE) -C $(KDIR) INSTALL_MOD_PATH=$(STATE)/kernel-modules DEPMOD=true modules_install
package:
	python3 $(HERE)/package.py
image: modules package
	docker build -f $(HERE)/Dockerfile -t $(IMAGE) $(STATE)/package
	docker save -o $(IMAGE_TAR) $(IMAGE)
corpus:
	install -d $(STATE)/var-tmp
	@cleanup() { for path in "$(STATE)/var-tmp/bpf-benchmark-docker.img" "$(IMAGE_TAR)"; do if test -e "$$path"; then if fuser -s -- "$$path"; then printf "retaining open experiment file: %s\n" "$$path" >&2; else rm -f -- "$$path"; fi; fi; done; }; trap cleanup EXIT; \
	  test -f "$(IMAGE_TAR)" || docker save -o "$(IMAGE_TAR)" "$(IMAGE)"; \
	  taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(STATE) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor --cpus 4 --memory 8G --append 'loglevel=4 panic=30 oops=panic' --exec 'BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) make -f $(HERE)/Makefile guest SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) APPS=$(APPS)'
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	PATH=/usr/lib/llvm-18/bin:$$PATH python3 $(HERE)/guest.py --samples $(SAMPLES) --duration $(WORKLOAD_DURATION) --apps $(APPS)
