.PHONY: host micro
host micro:
	PYTHONDONTWRITEBYTECODE=1 python3 kprog/results/s8-current-contract-20261121/check.py $@
.PHONY: safety safety-guest
RAW := /workspaces/kprog-raw/S8/20261121
CK := /workspaces/.agent-state/kprog-ck
GUEST ?= safety-guest
safety:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image vng \
		--run $(CK)/build-x86/arch/x86/boot/bzImage --cwd /workspaces/repository \
		--rwdir /workspaces/repository --rwdir $(RAW) --disable-monitor --cpus 2 --memory 2G \
		--overlay-rwdir /tmp --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'KPROG_S8_LINKER=$(RAW)/tc-inputs/native-link make -f kprog/results/s8-current-contract-20261121/Makefile $(GUEST)'
safety-guest:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(CK)/verified-module/bpf_x86_native_lab.ko
	KPROG_STOCK_LOADER=$(CK)/verified-loader PYTHONDONTWRITEBYTECODE=1 \
		CLANG=/workspaces/repository/kprog/stock-path/bin/clang \
		python3 kprog/results/s8-current-contract-20261121/check.py safety-guest
.PHONY: tc-build tc
TMP := /var/tmp/kprog-tmp/S8
tc-build:
	clang-18 -O2 -g -target bpf -Ivendor/libbpf/include/uapi -Ivendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu -c kprog/results/s8-current-contract-20261121/tc.bpf.c -o $(TMP)/tc.bpf.o
	cc -c kprog/results/s8-current-contract-20261121/tc.native.S -o $(TMP)/tc.native.o
	c++ -std=c++20 -O2 -Wall -Wextra -Werror -Irunner/build-llvmbpf/vendor/libbpf/prefix/include \
		kprog/test/tail_call_frame/client.cpp $(CK)/verified-loader/libnative_loader.a \
		runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(TMP)/tc-client

.PHONY: tc-guest
tc-guest:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(CK)/verified-module/bpf_x86_native_lab.ko
	KPROG_S8_INPUTS=$(RAW)/tc-inputs PYTHONDONTWRITEBYTECODE=1 CLANG=/workspaces/repository/kprog/stock-path/bin/clang \
		python3 kprog/results/s8-current-contract-20261121/check.py tc-guest
