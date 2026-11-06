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
