SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
SOURCE := /workspaces/.agent-state/kprog-lanes/C/anonymous-source
LIBBPF := $(ROOT)/runner/build-llvmbpf/vendor/libbpf
PAIRED := /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86

build:
	cmake -S $(SOURCE)/kprog/libnativeloader -B $(SOURCE)/build -DNATIVE_LOADER_REPO_ROOT=$(ROOT) -DNATIVE_LOADER_LIBBPF_PREFIX=$(LIBBPF)/prefix -DNATIVE_LOADER_LIBBPF_LIBRARY=$(LIBBPF)/pic-obj/libbpf.a -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-x86
	taskset -c 12-15 cmake --build $(SOURCE)/build -j2 --target native_loader native_loader_shared
	cc -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE -I$(ROOT)/vendor/libbpf/include/uapi -shared $(SOURCE)/bpfopt/shim-before/libbpfrejit_shim.c -o $(SOURCE)/shim-before.so -ldl -lpthread
	cc -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE -I$(ROOT)/vendor/libbpf/include/uapi -shared $(SOURCE)/bpfopt/shim/libbpfrejit_shim.c -o $(SOURCE)/shim-after.so -ldl -lpthread
	$(MAKE) -f $(HERE)/Makefile anonymous-startup-build

host:
	$(MAKE) -f $(HERE)/Makefile anonymous-manifest-host

kvm:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/anonymous.mk guest'

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(PAIRED)/bpf_x86_native_lab.ko
	python3 $(HERE)/check_anonymous_startup.py

helper-contract:
	python3 $(ROOT)/kprog/formal/tools/generate_x86_helper_dispatch_spec.py

helper-host:
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal $(ROOT)/kprog/formal/oracles/test_x86_helper_dispatch_host.c -o $(HERE)/anonymous-helper-host
	$(HERE)/anonymous-helper-host
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/test_x86_helper_dispatch_route_host.c -o $(HERE)/anonymous-helper-route-host
	$(HERE)/anonymous-helper-route-host

helper-oracle:
	python3 $(ROOT)/kprog/formal/tools/generate_helper_oracle.py

coarse-proof:
	python3 $(HERE)/lift_startup_proofs.py coarse_call $(HERE)/context-runtime/flags-zero/bpfrejit_1038_39f82ae52884c235.bpf socket

HELPER_SOURCE := /workspaces/.agent-state/kprog-lanes/C/helper-check-source
helper-micro:
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(HELPER_SOURCE)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build MICRO_CONFIG=../test/kprog_negative_stage2.yaml PROOF_BUILD_DIR=$(HERE)/helper-micro-negative MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(HELPER_SOURCE)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build PROOF_BUILD_DIR=$(HERE)/helper-micro MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'

object-startup-proofs:
	python3 $(HERE)/lift_startup_proofs.py object_coarse $(HERE)/context-runtime/flags-zero/bpfrejit_1038_39f82ae52884c235.bpf socket
	python3 $(HERE)/lift_startup_proofs.py object_arg_ctx $(HERE)/context-runtime/flags-zero/bpfrejit_1038_3ae725ddb7d69e19.bpf kprobe
	python3 $(HERE)/lift_startup_proofs.py object_sock $(HERE)/context-runtime/flags-zero/bpfrejit_1038_58255400910d7827.bpf cgroup/sock

object-kvm:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/anonymous.mk object-guest'

OBJECT_PHASE ?= object-startup-results-3
object-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(PAIRED)/bpf_x86_native_lab.ko
	python3 $(HERE)/check_object_startup.py $(OBJECT_PHASE)

source-call-proofs:
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -I$(ROOT)/vendor/libbpf/include/uapi $(HERE)/source_call_fixtures.cpp -o $(HERE)/source-call-fixtures
	$(HERE)/source-call-fixtures $(HERE)/source-call-inputs
	for name in five_args saved_r6 backwards; do python3 $(HERE)/lift_startup_proofs.py $$name $(HERE)/source-call-inputs/$$name.bpf.bin socket; done

source-call-cpu:
	python3 $(HERE)/check_source_calls.py cpu

source-call-kvm:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/anonymous.mk source-call-guest'

source-call-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(PAIRED)/bpf_x86_native_lab.ko
	python3 $(HERE)/check_source_calls.py bound

helper-census:
	python3 $(HERE)/prepare_finite.py prepare startup-helper-census
	python3 $(HERE)/pin_helper_census.py
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/startup-helper-census/input --report-dir $(HERE)/startup-helper-census --output-dir $(ROOT)/kprog/x86/app-coverage-startup-helpers --generator $(HERE)/startup-helper-census/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

artifacts:
	python3 $(HERE)/archive_startup_helpers.py
