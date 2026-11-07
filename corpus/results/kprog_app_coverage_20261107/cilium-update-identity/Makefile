SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261107/cilium-update-identity
STATE := /workspaces/.agent-state/kprog-lanes/C/cilium-update-identity
IMAGE := bpf-benchmark/kprog-cilium-identity:c-20261107
CPUS ?= 16-19
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
.PHONY: image corpus
image:
	install -d $(STATE)/package
	install -m0755 $(ROOT)/kprog/libnativeloader/build/libnative_loader.so $(STATE)/package/libnative_loader.so
	install -m0755 $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link $(STATE)/package/native-link
	install -m0755 $(HERE)/capture $(STATE)/package/capture
	docker tag sha256:401e818569d1e630c68e2f416d9a067199f248882421f76701e0f98558dd05bf bpf-benchmark/kprog-cilium-identity-base:c-20261107
	docker build -f $(HERE)/Dockerfile -t $(IMAGE) $(STATE)/package
	docker save -o $(STATE)/runtime.image.tar $(IMAGE)
corpus:
	install -d $(STATE)/var-tmp $(STATE)/tmp $(STATE)/modules
	@cleanup() { for path in "$(STATE)/var-tmp/bpf-benchmark-docker.img" "$(STATE)/runtime.image.tar"; do if test -e "$$path"; then if fuser -s -- "$$path"; then printf "retaining open experiment file: %s\n" "$$path" >&2; else rm -f -- "$$path"; fi; fi; done; }; trap cleanup EXIT; \
	  test -f "$(STATE)/runtime.image.tar" || docker save -o "$(STATE)/runtime.image.tar" "$(IMAGE)"; \
	  env -u BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_CORPUS_BPF_STATS=0 BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so BPFREJIT_NATIVE_LINK_BINARY=/usr/local/bin/native-link KEEP_WORKDIRS=all BPFREJIT_KEEP_ALL_WORKDIRS=1 $(MAKE) -C $(ROOT) -o runtime-kernel-image corpus RUNTIME_CONTAINER_IMAGE=$(IMAGE) RUNTIME_IMAGE_TAR=$(STATE)/runtime.image.tar RUN_NATIVE_REPOS_CSV=cilium BZIMAGE=$(STATE)/bzImage VNG='taskset -c $(CPUS) vng --run $(STATE)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --rwdir /tmp=$(STATE)/tmp --rwdir /lib/modules=$(STATE)/modules --disable-monitor --cpus 4 --memory 8G --append "loglevel=4 panic=30 oops=panic"' VM_CPU_PIN=$(CPUS) VM_CPUS=4 VM_MEM=8G SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION)
