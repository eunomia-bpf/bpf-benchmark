SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
AUDIT := /workspaces/repository/corpus/results/cilium_native_lab_20261009
PAPER := /workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree
KBUILD := /tmp/cilium-paper-build-20261009/x86/linux
LOADER_BUILD := /tmp/cilium-paper-loader-release-20261009
BASE_IMAGE := bpf-benchmark/cilium-audit-base:20261009
PAPER_IMAGE := bpf-benchmark/cilium-audit-paper:20261009

.PHONY: paper-loader paper-image paper-bpftool
paper-bpftool:
	install -d /tmp/cilium-paper-bpftool-20261009
	$(MAKE) -C "$(PAPER)/vendor/linux-framework/tools/bpf/bpftool" OUTPUT=/tmp/cilium-paper-bpftool-20261009/ LLVM_CONFIG=llvm-config-18 -j8
paper-loader:
	cmake -S "$(PAPER)/native-sim/libnativeloader" -B "$(LOADER_BUILD)" -DCMAKE_BUILD_TYPE=Release -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=/tmp/cilium-paper-offsets-20261009 -DNATIVE_LOADER_LIBBPF_PREFIX=/tmp/cilium-lab-own-libbpf-prefix/usr -DNATIVE_LOADER_LIBBPF_LIBRARY=/tmp/cilium-lab-own-libbpf-prefix/usr/lib64/libbpf.a
	$(MAKE) -C "$(LOADER_BUILD)" native_loader_shared -j4

paper-image: paper-loader paper-bpftool
	docker tag sha256:6afe89fa2407929de4744a60b37a1df13586e1a6d984449d094b6195852c98c3 "$(BASE_IMAGE)"
	docker build --build-context paper="$(PAPER)" --build-context modules="$(KBUILD)/modules-install/lib/modules" --build-context boot="$(KBUILD)/arch/x86/boot" --build-context kinsn="$(PAPER)/module/x86/build" --build-context loader="$(LOADER_BUILD)" --build-context bpftool=/tmp/cilium-paper-bpftool-20261009 --build-context offsets=/tmp/cilium-paper-offsets-20261009 --build-arg BASE_IMAGE="$(BASE_IMAGE)" -f "$(AUDIT)/paper-image.Dockerfile" -t "$(PAPER_IMAGE)" "$(AUDIT)"
	docker save -o /tmp/cilium-paper-runtime-20261009.tar "$(PAPER_IMAGE)"

.PHONY: current-loader current-image
current-loader:
	cmake -S /workspaces/repository/kprog/libnativeloader -B /tmp/cilium-current-loader-release-20261009 -DCMAKE_BUILD_TYPE=Release -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=/workspaces/repository/micro/programs/build-x86 -DNATIVE_LOADER_LIBBPF_PREFIX=/workspaces/repository/runner/build-llvmbpf/vendor/libbpf/prefix -DNATIVE_LOADER_LIBBPF_LIBRARY=/workspaces/repository/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
	$(MAKE) -C /tmp/cilium-current-loader-release-20261009 native_loader_shared -j4

current-image: current-loader paper-bpftool
	docker build --build-context current=/workspaces/repository --build-context modules=/workspaces/repository/vendor/build/x86/linux/modules-install/lib/modules --build-context boot=/workspaces/repository/vendor/build/x86/linux/arch/x86/boot --build-context kinsn=/workspaces/repository/kinsn/module/x86/build --build-context shim=/workspaces/repository/bpfopt/shim/build-x86 --build-context loader=/tmp/cilium-current-loader-release-20261009 --build-context bpftool=/tmp/cilium-paper-bpftool-20261009 --build-context offsets=/workspaces/repository/micro/programs/build-x86 --build-arg BASE_IMAGE="$(BASE_IMAGE)" -f "$(AUDIT)/current-image.Dockerfile" -t bpf-benchmark/cilium-audit-current:20261009 "$(AUDIT)"
	docker save -o /tmp/cilium-current-runtime-20261009.tar bpf-benchmark/cilium-audit-current:20261009
