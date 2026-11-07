SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261107
SOURCE := /workspaces/.agent-state/kprog-lanes/C/readonly-source

readonly-loader-build:
	cmake -S $(SOURCE)/kprog/libnativeloader -B $(SOURCE)/build -DNATIVE_LOADER_REPO_ROOT=$(ROOT) -DNATIVE_LOADER_LIBBPF_PREFIX=$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix -DNATIVE_LOADER_LIBBPF_LIBRARY=$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-x86
	taskset -c 12-15 cmake --build $(SOURCE)/build -j2 --target native_loader_shared native_loader

IMAGE := bpf-benchmark/kprog-readonly:c-20261107
IMAGE_TAR := /workspaces/.agent-state/kprog-lanes/C/readonly-runtime.image.tar
KERNEL := /workspaces/.agent-state/kprog-lanes/C/frozen-kernel/bzImage
APP ?= tracee/monitor
CPUS ?= 12-15
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
MAP_LOWERING_DISABLED ?= 0
SCRATCH ?= readonly

readonly-image: readonly-loader-build
	install -m0644 $(SOURCE)/build/libnative_loader.so $(HERE)/readonly-runtime/libnative_loader.so
	docker tag sha256:4853a1a52b6a436693df471a237939755f5513abdd0f8baf2acaec483452b03a bpf-benchmark/kprog-corpus-base:c-20261107
	docker build -f $(HERE)/readonly.Dockerfile -t $(IMAGE) $(HERE)/readonly-runtime
	docker save -o $(IMAGE_TAR) $(IMAGE)

readonly-corpus:
	install -d /workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-var-tmp /workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-tmp /workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-modules
	BPFREJIT_CORPUS_APPS=$(APP) BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=0 BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so BPFREJIT_NATIVE_DISABLE_MAP_LOWERING=$(MAP_LOWERING_DISABLED) BPFREJIT_KEEP_ALL_WORKDIRS=1 KEEP_WORKDIRS=all $(MAKE) -C $(ROOT) -o runtime-kernel-image corpus RUNTIME_CONTAINER_IMAGE=$(IMAGE) RUNTIME_IMAGE_TAR=$(IMAGE_TAR) RUN_RUNTIME_PYTHON_BIN=/usr/local/bin/kprog-capture-python BZIMAGE=$(KERNEL) VNG='taskset -c $(CPUS) vng --run $(KERNEL) --cwd $(ROOT) --disable-monitor --verbose --cpus 8 --memory 8G --rwdir $(ROOT) --rwdir /var/tmp=/workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-var-tmp --rwdir /tmp=/workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-tmp --rwdir /lib/modules=/workspaces/.agent-state/kprog-lanes/C/$(SCRATCH)-modules --append "loglevel=4 panic=30 oops=panic"' VM_CPU_PIN=$(CPUS) VM_CPUS=8 VM_MEM=8G SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION)

native-option-inputs:
	install -d $(HERE)/baseline/katran $(HERE)/baseline/tetragon
	container=$$(docker create bpf-benchmark/kprog-corpus-base:c-20261107 /bin/true); trap 'docker rm "$$container" >/dev/null' EXIT; docker cp -L "$$container:/usr/local/bin/native-link" $(HERE)/baseline/native-link; docker cp "$$container:/artifacts/user/native-bpf/x86_64/katran/balancer.native.o" $(HERE)/baseline/katran/balancer.native.o; docker cp "$$container:/artifacts/user/native-bpf/x86_64/tetragon/bpf_generic_kprobe_v61.native.o" $(HERE)/baseline/tetragon/bpf_generic_kprobe_v61.native.o

native-options-build: native-option-inputs
	taskset -c 20-23 prlimit --as=12884901888 --core=0 -- python3 $(HERE)/native-options.py

tail-frame-build:
	taskset -c 20-23 cargo test -j2 --manifest-path /workspaces/.agent-state/kprog-lanes/C/tail-frame-source/kprog/x86/native_lab/native_link/Cargo.toml --target-dir /workspaces/.agent-state/kprog-lanes/C/tail-frame-target
	taskset -c 20-23 cargo build -j2 --release --manifest-path /workspaces/.agent-state/kprog-lanes/C/tail-frame-source/kprog/x86/native_lab/native_link/Cargo.toml --target-dir /workspaces/.agent-state/kprog-lanes/C/tail-frame-target

native-options-retry:
	taskset -c 20-23 prlimit --as=12884901888 --core=0 -- python3 $(HERE)/native-options.py native-options-v2

tail-frame-image:
	install -m0755 /workspaces/.agent-state/kprog-lanes/C/tail-frame-target/release/native-link $(HERE)/readonly-runtime/native-link
	docker build -f $(HERE)/tail-frame.Dockerfile -t bpf-benchmark/kprog-tail-frame:c-20261107 $(HERE)/readonly-runtime
	docker save -o /workspaces/.agent-state/kprog-lanes/C/tail-frame-runtime.image.tar bpf-benchmark/kprog-tail-frame:c-20261107

capture-image:
	docker build -f $(HERE)/capture.Dockerfile -t bpf-benchmark/kprog-map-capture:c-20261107 $(HERE)/readonly-runtime
	docker save -o /workspaces/.agent-state/kprog-lanes/C/map-capture-runtime.image.tar bpf-benchmark/kprog-map-capture:c-20261107

frozen-kernel:
	install -d /workspaces/.agent-state/kprog-lanes/C/frozen-kernel
	container=$$(docker create bpf-benchmark/kprog-corpus-base:c-20261107 /bin/true); trap 'docker rm "$$container" >/dev/null' EXIT; docker cp "$$container:/artifacts/manifest.json" /workspaces/.agent-state/kprog-lanes/C/frozen-kernel/manifest.json; docker cp "$$container:/artifacts/kernel/bzImage" /workspaces/.agent-state/kprog-lanes/C/frozen-kernel/bzImage

perf-tool:
	install -d /workspaces/.agent-state/kprog-lanes/C/perf-build
	taskset -c 20-23 make -C $(ROOT)/vendor/linux-framework/tools/perf O=/workspaces/.agent-state/kprog-lanes/C/perf-build -j2 NO_JEVENTS=1 NO_LIBPERL=1 NO_LIBPYTHON=1 NO_LIBBABELTRACE=1 NO_LIBTRACEEVENT=1

perf-profile-build:
	gcc -O2 -Wall -Wextra -o $(HERE)/per-run-profile/fixed-run $(HERE)/per-run-profile/fixed-run.c

perf-profile:
	python3 -u $(HERE)/per-run-profile/host.py baseline

perf-tables-profile:
	python3 -u $(HERE)/per-run-profile/host.py tables
