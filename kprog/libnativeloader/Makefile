BUILD_DIR ?= build
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86

.PHONY: all clean

all:
	cmake -S . -B "$(BUILD_DIR)" \
		-DNATIVE_LOADER_REPO_ROOT="$(REPO_ROOT)" \
		-DNATIVE_LOADER_LIBBPF_PREFIX="$(LIBBPF_PREFIX)" \
		-DNATIVE_LOADER_LIBBPF_LIBRARY="$(LIBBPF_LIBRARY)" \
		-DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE="$(KERNEL_OFFSETS_INCLUDE)"
	cmake --build "$(BUILD_DIR)" --target native_loader native_loader_shared

clean:
	rm -rf "$(BUILD_DIR)"

.PHONY: trusted-service
trusted-service: all
	cmake --build "$(BUILD_DIR)" --target trusted-native-loader

.PHONY: trusted-service-check
trusted-service-check: trusted-service
	PYTHONDONTWRITEBYTECODE=1 python3 "$(REPO_ROOT)/kprog/test/check_trusted_service.py"

.PHONY: trusted-worker-check
trusted-worker-check:
	PYTHONDONTWRITEBYTECODE=1 python3 "$(REPO_ROOT)/kprog/test/check_trusted_worker.py"

.PHONY: trusted-service-kvm trusted-service-guest
trusted-service-kvm: trusted-service-check
	cmake --build "$(BUILD_DIR)" --target trusted-service-client
	clang -O2 -fno-asynchronous-unwind-tables -c ../test/trusted_native.c -o "$(BUILD_DIR)/trusted-native.o"
	taskset -c 12-15 vng --run "$(REPO_ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -C kprog/libnativeloader trusted-service-guest'

trusted-service-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod ../tv/build-x86/bpf_x86_native_lab.ko
	PATH="/usr/lib/llvm-18/bin:$$PATH" PYTHONDONTWRITEBYTECODE=1 python3 ../test/run_trusted_service_guest.py
