SHELL := /bin/bash
.PHONY: package image corpus
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
PACKAGE := bcc-runtime-13
IMAGE := bpf-benchmark/kprog-bcc:c-20261106-13
IMAGE_TAR := /workspaces/.agent-state/kprog-lanes/C/bcc-runtime-13.image.tar
PAIRED := /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86

package:
	python3 $(HERE)/package_bcc.py bcc-real-13 $(PACKAGE)

image:
	docker build -f $(HERE)/bcc-strict.Dockerfile -t $(IMAGE) $(HERE)/$(PACKAGE)
	docker save -o $(IMAGE_TAR) $(IMAGE)

corpus:
	install -d /workspaces/.agent-state/kprog-lanes/C/var-tmp-bcc-11 /workspaces/.agent-state/kprog-lanes/C/tmp-bcc-11 /workspaces/.agent-state/kprog-lanes/C/modules-bcc-11
	trap 'rm -rf /workspaces/.agent-state/kprog-lanes/C/var-tmp-bcc-11 /workspaces/.agent-state/kprog-lanes/C/tmp-bcc-11 /workspaces/.agent-state/kprog-lanes/C/modules-bcc-11' EXIT; BPFREJIT_CORPUS_APPS=bcc/set BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 BPFREJIT_KEEP_ALL_WORKDIRS=1 KEEP_WORKDIRS=all $(MAKE) -C $(ROOT) -o runtime-kernel-image corpus RUNTIME_CONTAINER_IMAGE=$(IMAGE) RUNTIME_IMAGE_TAR=$(IMAGE_TAR) BZIMAGE=$(PAIRED)/bzImage VNG='taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --disable-monitor --verbose --cpus 8 --memory 4G --rwdir $(ROOT) --rwdir /var/tmp=/workspaces/.agent-state/kprog-lanes/C/var-tmp-bcc-11 --rwdir /tmp=/workspaces/.agent-state/kprog-lanes/C/tmp-bcc-11 --rwdir /lib/modules=/workspaces/.agent-state/kprog-lanes/C/modules-bcc-11 --append "loglevel=4 panic=30 oops=panic"' VM_CPU_PIN=12-15 VM_CPUS=8 VM_MEM=4G SAMPLES=1 WORKLOAD_DURATION=2 TIMEOUT=900

capture-image:
	install -d $(HERE)/bcc-capture-12
	docker build -f $(HERE)/bcc-capture.Dockerfile -t bpf-benchmark/kprog-bcc:c-20261106-12 $(HERE)/$(PACKAGE)
	docker save -o /workspaces/.agent-state/kprog-lanes/C/bcc-runtime-12.image.tar bpf-benchmark/kprog-bcc:c-20261106-12
