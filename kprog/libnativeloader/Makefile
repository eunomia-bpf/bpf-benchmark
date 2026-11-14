BUILD_DIR ?= build
SUBPROCESS_BUILD ?= /var/tmp/kprog-tmp/verified/loader-subprocess
SUBPROCESS_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-loader-spawn/functional
TIMING_BUILD ?= /var/tmp/kprog-tmp/verified/loader-timings
TIMING_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-loader-timings/functional
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86
SERVICE_RUN ?= $(abspath $(BUILD_DIR))/trusted-service-client $(abspath $(BUILD_DIR))/trusted-native.o
HELPER_BUILD ?= /var/tmp/kprog-tmp/verified/helper-context
HELPER_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-helper-context/functional
HELPER_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-helper-context/kernel
HELPER_KERNEL_MODULE ?= /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
REFRESH_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-shared-refresh
REFRESH_OPERATION ?= full
IMAGE_INVENTORY_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-kfunc-refresh/native-inputs.json

DATA_LAYOUT_BUILD ?= /var/tmp/kprog-tmp/verified/data-layout
DATA_LAYOUT_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-data-layout/host
DATA_LAYOUT_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-data-layout/kernel
ENTRY_DATA_BUILD ?= /var/tmp/kprog-tmp/verified/entry-data
ENTRY_DATA_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-entry-data/host
ENTRY_DATA_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-entry-data/kernel
ENTRY_DATA_REAL_PROOF ?= /var/tmp/kprog-tmp/perf/cilium-config-symbols/bpf_lxc-roundtrip/tail_no_service_ipv4.proof.o
ENTRY_DATA_LINKER ?= $(REPO_ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
DIRECT_TAIL_BUILD ?= /var/tmp/kprog-tmp/verified/direct-tail
DIRECT_TAIL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-direct-tail/host
FRAME_BUILD ?= /var/tmp/kprog-tmp/verified/frame-pointer
FRAME_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-frame-pointer/kernel
FRAME_LINKER ?= $(DIRECT_TAIL_BUILD)/cargo/debug/native-link
KFUNC_BUILD ?= /var/tmp/kprog-tmp/verified/kfunc
KFUNC_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/host
KFUNC_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/kernel
KFUNC_BPF ?= /workspaces/kprog-raw/perf/20261113-tetragon-same-source/build-evidence/bpf_generic_kprobe_v61.direct.bpf.o
KFUNC_NATIVE ?= /var/tmp/kprog-tmp/perf/tetragon-same-source/bpf_generic_kprobe_v61.native.o
KERNEL_ELF_RESTORE_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kernel-elf-restore
KFUNC_MODEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/model

.PHONY: kfunc-model-check
kfunc-model-check:
	install -d "$(KFUNC_MODEL_OUTPUT)"
	clang-18 -O2 -fPIC -c ../test/kfunc_model_fixture.c -o "$(KFUNC_MODEL_OUTPUT)/fixture.native.o"
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../test/check_kfunc_model.py "$(KFUNC_MODEL_OUTPUT)/fixture.native.o" \
		/workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(KFUNC_MODEL_OUTPUT)"

# Invoke under the exclusive image/base lock; the unchanged boot is authoritative.
.PHONY: kernel-elf-from-boot
kernel-elf-from-boot:
	install -d "$(KERNEL_ELF_RESTORE_OUTPUT)"
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$(KERNEL_ELF_RESTORE_OUTPUT)/before.sha256"
	"$(REPO_ROOT)/vendor/linux-framework/scripts/extract-vmlinux" \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > /workspaces/.agent-state/kprog-ck/build-x86/vmlinux
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$(KERNEL_ELF_RESTORE_OUTPUT)/after.sha256"

.PHONY: kfunc-inputs kfunc-check kfunc-kernel-kvm guest-kfunc kfunc-model-kernel-kvm
kfunc-model-kernel-kvm:
	install -d "$(KFUNC_KERNEL_OUTPUT)"
	install -m 0644 "$(KFUNC_MODEL_OUTPUT)/generated/trusted_x86.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/model.bpf.o"
	install -m 0644 "$(KFUNC_MODEL_OUTPUT)/iterator/trusted_x86.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/iterator.bpf.o"
	$(MAKE) kfunc-kernel-kvm KFUNC_MODEL_PROOF="$(KFUNC_KERNEL_OUTPUT)/model.bpf.o $(KFUNC_KERNEL_OUTPUT)/iterator.bpf.o"

kfunc-inputs:
	install -d "$(KFUNC_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_kfunc_fixture.c -o "$(KFUNC_BUILD)/weak.o"
	clang-18 -O2 -fPIC -DKFUNC_PRESENT_STRONG -c ../test/native_kfunc_fixture.c -o "$(KFUNC_BUILD)/strong.o"
	clang-18 -target bpf -O2 -g -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		-I"$(REPO_ROOT)/vendor/libbpf/src" -I/usr/include/x86_64-linux-gnu \
		-c ../test/kfunc_proof_fixture.bpf.c -o "$(KFUNC_BUILD)/proof.bpf.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_kfunc.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(KFUNC_BUILD)/kfunc"

kfunc-check: kfunc-inputs
	install -d "$(KFUNC_OUTPUT)"
	"$(KFUNC_BUILD)/kfunc" host "$(KFUNC_BUILD)/weak.o" "$(KFUNC_BUILD)/strong.o" \
		"$(KFUNC_BPF)" "$(KFUNC_NATIVE)" /workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(KFUNC_OUTPUT)" "$(KFUNC_BUILD)/proof.bpf.o"

kfunc-kernel-kvm:
	install -d "$(KFUNC_KERNEL_OUTPUT)"
	install -m 0755 "$(KFUNC_BUILD)/kfunc" "$(KFUNC_KERNEL_OUTPUT)/kfunc"
	install -m 0644 "$(KFUNC_BUILD)/weak.o" "$(KFUNC_BUILD)/strong.o" "$(KFUNC_KERNEL_OUTPUT)/"
	install -m 0644 "$(KFUNC_BUILD)/proof.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/proof.bpf.o"
	install -m 0644 "$(KFUNC_BPF)" "$(KFUNC_KERNEL_OUTPUT)/source.bpf.o"
	install -m 0644 "$(KFUNC_NATIVE)" "$(KFUNC_KERNEL_OUTPUT)/source.native.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(KFUNC_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-kfunc KFUNC_KERNEL_OUTPUT=$(KFUNC_KERNEL_OUTPUT) KFUNC_MODEL_PROOF="$(KFUNC_MODEL_PROOF)"'

guest-kfunc:
	"$(KFUNC_KERNEL_OUTPUT)/kfunc" kernel "$(KFUNC_KERNEL_OUTPUT)/weak.o" "$(KFUNC_KERNEL_OUTPUT)/strong.o" \
		"$(KFUNC_KERNEL_OUTPUT)/source.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/source.native.o" \
		/sys/kernel/btf/vmlinux "$(KFUNC_KERNEL_OUTPUT)" "$(KFUNC_KERNEL_OUTPUT)/proof.bpf.o" $(KFUNC_MODEL_PROOF)

.PHONY: tail-frame-inputs tail-frame-kvm guest-tail-frame
tail-frame-inputs:
	install -d "$(FRAME_BUILD)"
	clang-18 -O2 -g -target bpf -I/usr/include/x86_64-linux-gnu -I"$(LIBBPF_PREFIX)/include/bpf" \
		-c ../test/tail_call_frame/program.c -o "$(FRAME_BUILD)/source.bpf.o"
	clang-18 -fPIC -c ../test/tail_call_frame/frame-pointer.S -o "$(FRAME_BUILD)/frame.native.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		src/native_loader.cpp ../test/tail_call_frame/client.cpp -Wl,--gc-sections \
		"$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread -o "$(FRAME_BUILD)/client"

tail-frame-kvm:
	install -d "$(FRAME_OUTPUT)"
	install -m 0755 "$(FRAME_BUILD)/client" "$(FRAME_OUTPUT)/client"
	install -m 0644 "$(FRAME_BUILD)/source.bpf.o" "$(FRAME_BUILD)/frame.native.o" "$(FRAME_OUTPUT)/"
	install -m 0755 "$(FRAME_LINKER)" "$(FRAME_OUTPUT)/native-link.real"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(FRAME_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-tail-frame FRAME_OUTPUT=$(FRAME_OUTPUT) FRAME_LINKER=$(FRAME_OUTPUT)/native-link.real'

guest-tail-frame:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_FRAME_LINKER="$(FRAME_LINKER)" \
		python3 ../trusted_service.py --arch 1 \
		--endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(FRAME_OUTPUT)/state" --results "$(FRAME_OUTPUT)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" \
		--loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader \
		--run "$(FRAME_OUTPUT)/client" "$(FRAME_OUTPUT)/source.bpf.o" "$(FRAME_OUTPUT)/frame.native.o" \
		"$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" "$(FRAME_OUTPUT)/native-image.bin"

.PHONY: direct-tail-check
direct-tail-check:
	install -d "$(DIRECT_TAIL_BUILD)" "$(DIRECT_TAIL_OUTPUT)"
	CARGO_TARGET_DIR="$(DIRECT_TAIL_BUILD)/cargo" CARGO_BUILD_JOBS=1 CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 \
		cargo test --manifest-path "$(REPO_ROOT)/kprog/x86/native_lab/native_link/Cargo.toml"
	CARGO_TARGET_DIR="$(DIRECT_TAIL_BUILD)/cargo" CARGO_BUILD_JOBS=1 CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 \
		cargo build --manifest-path "$(REPO_ROOT)/kprog/x86/native_lab/native_link/Cargo.toml"
	clang-18 -fPIC -c ../test/native_direct_tail_fixture.S -o "$(DIRECT_TAIL_OUTPUT)/fixture.o"
	clang-18 -shared "$(DIRECT_TAIL_OUTPUT)/fixture.o" -o "$(DIRECT_TAIL_OUTPUT)/control.so"
	python3 ../test/check_native_direct_tail.py "$(DIRECT_TAIL_BUILD)/cargo/debug/native-link" \
		"$(DIRECT_TAIL_OUTPUT)/fixture.o" "$(DIRECT_TAIL_OUTPUT)/control.so" "$(ENTRY_DATA_LINKER)" "$(DIRECT_TAIL_OUTPUT)"

.PHONY: entry-data-inputs entry-data-check entry-data-kernel-kvm guest-entry-data
entry-data-inputs:
	install -d "$(ENTRY_DATA_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_entry_data_fixture.c -o "$(ENTRY_DATA_BUILD)/fixture.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_entry_data.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(ENTRY_DATA_BUILD)/entry-data"

entry-data-check: entry-data-inputs
	install -d "$(ENTRY_DATA_OUTPUT)"
	install -m 0644 "$(ENTRY_DATA_REAL_PROOF)" "$(ENTRY_DATA_OUTPUT)/existing.proof.o"
	"$(ENTRY_DATA_BUILD)/entry-data" host "$(ENTRY_DATA_BUILD)/fixture.o" "$(ENTRY_DATA_LINKER)" \
		"$(ENTRY_DATA_OUTPUT)" "$(ENTRY_DATA_OUTPUT)/existing.proof.o"

entry-data-kernel-kvm:
	install -d "$(ENTRY_DATA_KERNEL_OUTPUT)"
	install -m 0755 "$(ENTRY_DATA_BUILD)/entry-data" "$(ENTRY_DATA_KERNEL_OUTPUT)/entry-data"
	install -m 0644 "$(ENTRY_DATA_BUILD)/fixture.o" "$(ENTRY_DATA_KERNEL_OUTPUT)/fixture.o"
	install -m 0644 "$(ENTRY_DATA_REAL_PROOF)" "$(ENTRY_DATA_KERNEL_OUTPUT)/existing.proof.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(ENTRY_DATA_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-entry-data ENTRY_DATA_KERNEL_OUTPUT=$(ENTRY_DATA_KERNEL_OUTPUT) ENTRY_DATA_LINKER=$(ENTRY_DATA_LINKER)'

guest-entry-data:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(ENTRY_DATA_KERNEL_OUTPUT)/entry-data" kernel "$(ENTRY_DATA_KERNEL_OUTPUT)/fixture.o" "$(ENTRY_DATA_LINKER)" \
		"$(ENTRY_DATA_KERNEL_OUTPUT)" "$(ENTRY_DATA_KERNEL_OUTPUT)/existing.proof.o"

.PHONY: data-layout-inputs data-layout-check data-layout-kernel-kvm guest-data-layout
data-layout-inputs:
	install -d "$(DATA_LAYOUT_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_data_layout_fixture.c -o "$(DATA_LAYOUT_BUILD)/fixture.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_data_layout.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(DATA_LAYOUT_BUILD)/data-layout"

data-layout-check: data-layout-inputs
	install -d "$(DATA_LAYOUT_OUTPUT)"
	"$(DATA_LAYOUT_BUILD)/data-layout" host "$(DATA_LAYOUT_BUILD)/fixture.o" "$(DATA_LAYOUT_OUTPUT)"

data-layout-kernel-kvm:
	install -d "$(DATA_LAYOUT_KERNEL_OUTPUT)"
	install -m 0755 "$(DATA_LAYOUT_BUILD)/data-layout" "$(DATA_LAYOUT_KERNEL_OUTPUT)/data-layout"
	install -m 0644 "$(DATA_LAYOUT_BUILD)/fixture.o" "$(DATA_LAYOUT_KERNEL_OUTPUT)/fixture.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(DATA_LAYOUT_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-data-layout DATA_LAYOUT_KERNEL_OUTPUT=$(DATA_LAYOUT_KERNEL_OUTPUT)'

guest-data-layout:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(DATA_LAYOUT_KERNEL_OUTPUT)/data-layout" kernel "$(DATA_LAYOUT_KERNEL_OUTPUT)/fixture.o" "$(DATA_LAYOUT_KERNEL_OUTPUT)"

.PHONY: shared-image-artifact-inventory shared-image-restore
shared-image-artifact-inventory:
	python3 ../test/image_native_inventory.py --image "$(REPO_ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar" \
		--stage "$(REPO_ROOT)/vendor/build/native-bpf/x86/stage" --output "$(IMAGE_INVENTORY_OUTPUT)"

# Restore the same saved image after a daemon restart, under the image writer lock.
shared-image-restore:
	docker image load -i "$(REPO_ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar"

.PHONY: shared-base-refresh shared-base-finalize shared-base-modules-repair shared-module-syntax
shared-base-refresh:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" "$(REFRESH_OPERATION)"

shared-base-finalize:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" --finalize

shared-base-modules-repair:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" --modules-only

shared-module-syntax:
	$(MAKE) -C ../stock-path/module syntax-check
	python3 ../test/module_syntax_check.py "$(REPO_ROOT)/kinsn/module/x86/build" .bpf_x86_native_lab.o.cmd

.PHONY: helper-context-kernel-input helper-context-kernel-kvm guest-helper-context-kernel
helper-context-kernel-input:
	install -d "$(HELPER_BUILD)"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_helper_kernel.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(HELPER_BUILD)/helper-kernel"

# Consume the prepared shared module; never rebuild it on a reader's startup.
helper-context-kernel-kvm:
	install -d "$(HELPER_KERNEL_OUTPUT)"
	install -m 0755 "$(HELPER_BUILD)/helper-kernel" "$(HELPER_KERNEL_OUTPUT)/helper-kernel"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(HELPER_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-helper-context-kernel HELPER_KERNEL_OUTPUT=$(HELPER_KERNEL_OUTPUT) HELPER_KERNEL_MODULE=$(HELPER_KERNEL_MODULE)'

guest-helper-context-kernel:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod "$(HELPER_KERNEL_MODULE)"
	"$(HELPER_KERNEL_OUTPUT)/helper-kernel" "$(HELPER_KERNEL_OUTPUT)"

.PHONY: helper-context-check
helper-context-check:
	install -d "$(HELPER_BUILD)" "$(HELPER_OUTPUT)"
	$(CXX) -std=c++20 -O2 -Wall -Wextra -Werror -fsanitize=address,undefined ../test/native_loader_helper_query.cpp -o "$(HELPER_BUILD)/helper-query"
	"$(HELPER_BUILD)/helper-query" "$(HELPER_OUTPUT)"
	$(CXX) -std=gnu++20 -fsyntax-only -Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" -I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" src/native_loader.cpp
	$(MAKE) -C ../stock-path/module syntax-check

.PHONY: subprocess-check
subprocess-check:
	install -d "$(SUBPROCESS_BUILD)" "$(SUBPROCESS_OUTPUT)"
	$(CXX) -std=c++20 -O2 -pthread -Wall -Wextra -Werror ../test/native_loader_subprocess.cpp -o "$(SUBPROCESS_BUILD)/child-boundary"
	"$(SUBPROCESS_BUILD)/child-boundary" "$(SUBPROCESS_OUTPUT)"

.PHONY: lifetime-probe
lifetime-probe:
	python3 ../test/native_loader_lifetime.py "$(abspath $(BUILD_DIR))/libnative_loader.so"

.PHONY: timings-check
timings-check:
	install -d "$(TIMING_BUILD)" "$(TIMING_OUTPUT)"
	$(CXX) -std=c++20 -O2 -pthread -Wall -Wextra -Werror ../test/native_loader_timings.cpp -o "$(TIMING_BUILD)/phase-log"
	python3 ../test/check_native_loader_timings.py "$(TIMING_BUILD)/phase-log" "$(TIMING_OUTPUT)"
	$(CXX) -std=gnu++20 -fsyntax-only -Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" -I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" src/native_loader.cpp
VM_MEM ?= 2G
VM_CPUS ?= 2
SERVICE_HOST_CPUS ?= 8-15
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
	taskset -c $(SERVICE_HOST_CPUS) vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
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

# The shared module is built explicitly under the image writer lock. Starting
# a service guest must not replace it while another guest uses the sole base.
trusted-service-kvm: trusted-service
	install -d "$(OUTPUT)"
	taskset -c $(SERVICE_HOST_CPUS) vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
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
