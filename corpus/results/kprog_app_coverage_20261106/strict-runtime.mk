SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
INPUT := $(HERE)/strict-runtime-input
PAIRED := /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86
LOADER := /workspaces/.agent-state/kprog-lanes/T/context-v2-func-ip/x86

build:
	install -d $(INPUT)
	cc -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE -I$(ROOT)/vendor/libbpf/include/uapi -shared $(ROOT)/bpfopt/shim/libbpfrejit_shim.c -o $(INPUT)/libbpfrejit_shim.so -ldl -lpthread
	install -m0644 $(LOADER)/libnative_loader.so $(INPUT)/libnative_loader.so
	install -m0644 $(PAIRED)/bpf_x86_native_lab.ko $(INPUT)/bpf_x86_native_lab.ko
	install -m0644 $(PAIRED)/bzImage $(INPUT)/bzImage

kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk guest'

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	KPROG_TEST_SHIM=$(INPUT)/libbpfrejit_shim.so KPROG_TEST_LOADER=$(INPUT)/libnative_loader.so python3 $(HERE)/check_object_startup.py object-startup-published

artifacts:
	tar -czf $(HERE)/strict-runtime-artifacts.tar.gz --exclude='sockets' -C $(HERE) strict-runtime-input object-startup-published

LINK_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target-c-tail
link-build:
	taskset -c 12-15 cargo build -j2 --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)

test-link:
	taskset -c 12-15 cargo test -j2 --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)

tail-build:
	python3 $(HERE)/check_tail_helpers.py build

tail-kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk tail-guest'

tail-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	python3 $(HERE)/check_tail_helpers.py bound

tail-negative:
	python3 $(HERE)/check_tail_helpers.py negative

tail-artifacts:
	tar -czf $(HERE)/tail-helper-artifacts.tar.gz --exclude='sockets' --exclude='target' -C $(HERE) tail-helper tail-object-direct tail-object-got tail-object-numeric tail-object-subprogram -C /workspaces/.agent-state/kprog-lanes/C/tail-check-source kprog/x86/native_lab/native_link
