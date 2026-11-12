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

# Existing service wire, on the sole kernel/base; does not execute native code.
.PHONY: trusted-submission-check guest-trusted-submission-check
trusted-submission-check: all
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 \
		-I"$(LIBBPF_PREFIX)/include" ../test/trusted_submission.cpp \
		"$(BUILD_DIR)/libnative_loader.a" "$(LIBBPF_LIBRARY)" -lelf -lz -ldl \
		-o "$(BUILD_DIR)/trusted-submission"
	$(MAKE) -C ../stock-path/module
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-submission-check BUILD_DIR=$(abspath $(BUILD_DIR))'

guest-trusted-submission-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.ko
	"$(BUILD_DIR)/trusted-submission" "$(REPO_ROOT)/vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o"
