BUILD_DIR ?= build
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86
SERVICE_RUN ?= $(abspath $(BUILD_DIR))/trusted-service-client $(abspath $(BUILD_DIR))/trusted-native.o
VM_MEM ?= 2G
VM_CPUS ?= 2
VNG_FLAGS ?=

.PHONY: all clean

.PHONY: native-image-handoff native-image-handoff-kvm guest-native-image-handoff
native-image-handoff:
	install -d "$(BUILD_DIR)"
	$(CC) -O2 -Wall -Wextra -Werror -D__EXPORTED_HEADERS__ \
		-I"$(REPO_ROOT)/vendor/linux-framework/include/uapi" \
		-I"$(LIBBPF_PREFIX)/include" \
		../test/native_image_handoff.c "$(LIBBPF_LIBRARY)" -lelf -lz -pthread \
		-o "$(BUILD_DIR)/native-image-handoff"

# NATIVE_MODULE selects the coordinator-built direct-native module.
native-image-handoff-kvm: native-image-handoff
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(abspath $(BUILD_DIR))" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-native-image-handoff BUILD_DIR=$(abspath $(BUILD_DIR)) NATIVE_MODULE=$(NATIVE_MODULE)'

guest-native-image-handoff:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod "$(NATIVE_MODULE)"
	"$(BUILD_DIR)/native-image-handoff"

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
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(BUILD_DIR)/trusted-submission" "$(REPO_ROOT)/vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o"

.PHONY: trusted-service trusted-service-kvm guest-trusted-service
trusted-service: all
	cmake --build "$(BUILD_DIR)" --target trusted-native-loader trusted-service-client
	$(CC) -O2 -fPIC -mno-red-zone -mgeneral-regs-only -fno-stack-protector \
		-fno-asynchronous-unwind-tables -c ../test/trusted_native.c -o "$(BUILD_DIR)/trusted-native.o"

SAFETY_INPUTS ?= /workspaces/.agent-state/kprog-ck/verified-safety
.PHONY: trusted-safety-inputs
trusted-safety-inputs: all
	KPROG_STOCK_LOADER="$(abspath $(BUILD_DIR))" python3 ../stock-path/run_safety.py build \
		--out "$(SAFETY_INPUTS)" --inputs "$(SAFETY_INPUTS)"

.PHONY: trusted-safety-kvm guest-trusted-safety
trusted-safety-kvm: trusted-service trusted-safety-inputs
	$(MAKE) -C ../stock-path/module
	install -d "$(OUTPUT)"
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-safety BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT) SAFETY_INPUTS=$(SAFETY_INPUTS)'

guest-trusted-safety:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_STOCK_LOADER="$(abspath $(BUILD_DIR))" \
		python3 ../stock-path/run_safety.py check --out "$(OUTPUT)" --inputs "$(SAFETY_INPUTS)"

trusted-service-kvm: trusted-service
	$(MAKE) -C ../stock-path/module
	install -d "$(OUTPUT)"
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor $(VNG_FLAGS) --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-service BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT) SERVICE_RUN="$(SERVICE_RUN)"'

guest-trusted-service:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../trusted_service.py --arch 1 \
		--endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(OUTPUT)/state" --results "$(OUTPUT)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/x86/native_lab/native_link/target/release/native-link" \
		--loader "$(BUILD_DIR)/trusted-native-loader" \
		--run $(SERVICE_RUN)

.PHONY: trusted-lifecycle-check guest-trusted-lifecycle
trusted-lifecycle-check: all
	$(MAKE) -C ../stock-path/module
	install -d "$(OUTPUT)"
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-lifecycle BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT)'

guest-trusted-lifecycle:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	python3 ../test/pending_native_snapshot.py "$(OUTPUT)" \
		"$(REPO_ROOT)/bpfopt/shim/build-x86/libbpfrejit_shim.so" "$(BUILD_DIR)/libnative_loader.so"
