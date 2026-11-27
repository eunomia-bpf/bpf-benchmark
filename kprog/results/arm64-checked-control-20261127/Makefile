ROOT := $(abspath ../../..)
BASE := /workspaces/.agent-state/kprog-ck
ARM_BUILD := $(ROOT)/runner/build-arm64-llvmbpf
ARM_LIB := $(ARM_BUILD)/native_loader
SYSROOT := $(ROOT)/.cache/aarch64-sysroot
LINKER := $(ROOT)/kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link
.PHONY: capture loader-build module-build programs layouts
capture:
	python3 capture.py
loader-build:
	flock $(BASE)/../kprog-lanes/locks/image cmake --build $(ARM_BUILD) --target native_loader_shared native_loader trusted-native-loader -j 2
	aarch64-linux-gnu-g++ -std=gnu++20 -O2 -I$(ROOT)/kprog/libnativeloader/include -I$(ARM_BUILD)/vendor/libbpf/prefix/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi -I$(SYSROOT)/usr/include $(ROOT)/kprog/test/trusted_service_client.cpp $(ARM_LIB)/libnative_loader.a $(ARM_BUILD)/vendor/libbpf/pic-obj/libbpf.a -L$(SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(SYSROOT)/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -pthread -o $(ARM_LIB)/trusted-service-client
module-build:
	$(MAKE) -C $(ROOT)/kprog/stock-path/module KDIR=$(BASE)/build-arm64 MO=$(BASE)/verified-module/arm64 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
programs:
	install -d /var/tmp/kprog-tmp/perf/arm64-checked-control
	clang-18 --target=aarch64-linux-gnu -O3 -mtune=neoverse-n1 -mgeneral-regs-only -mno-outline-atomics -ffixed-x26 -fPIC -fomit-frame-pointer -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/trusted_native.c -o /var/tmp/kprog-tmp/perf/arm64-checked-control/control.o
layouts:
	install -d $(BASE)/verified-compiler/arm64
	clang-18 -O2 -I$(ROOT)/vendor/bpf/targets/arm64/7.0.0-rc2+ $(ROOT)/kprog/build/packet-public-layout.c -o $(BASE)/verified-compiler/arm64/public-layout
	$(BASE)/verified-compiler/arm64/public-layout > $(BASE)/verified-compiler/arm64/public-layout.json
	clang-18 -O2 -I$(ROOT)/vendor/bpf/targets/arm64/7.0.0-rc2+ $(ROOT)/kprog/build/packet-physical-layout.c -o $(BASE)/verified-compiler/arm64/physical-layout
	$(BASE)/verified-compiler/arm64/physical-layout > $(BASE)/verified-compiler/arm64/physical-layout.json
.PHONY: smoke
smoke:
	python3 smoke.py
.PHONY: guest
# Host compiler jobs stay capped; the guest retains the ARM entry's 4vCPU/8GiB.
guest:
	python3 guest_controller.py
.PHONY: broker-lookup
broker-lookup:
	prlimit --as=17179869184 taskset -c 16 python3 broker_lookup.py
.PHONY: report
report:
	python3 report.py
