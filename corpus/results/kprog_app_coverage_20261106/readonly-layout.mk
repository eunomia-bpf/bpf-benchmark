SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
LINK_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target-c-readonly
RO_SOURCE := /workspaces/.agent-state/kprog-lanes/C/readonly-check-source

build:
	taskset -c 12-15 cargo build --release -j2 --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)

test:
	taskset -c 12-15 cargo test -j2 --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)
	python3 $(HERE)/check_readonly_layout.py

formal:
	taskset -c 20-23 $(MAKE) -C $(RO_SOURCE)/kprog/formal check

micro:
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(RO_SOURCE)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build MICRO_CONFIG=../test/kprog_negative_stage2.yaml PROOF_BUILD_DIR=$(HERE)/readonly-layout/micro-negative MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(RO_SOURCE)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build PROOF_BUILD_DIR=$(HERE)/readonly-layout/micro MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'

PHASE ?= bcc-real-11
PAIRED := /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86
bcc-verify:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest-verify PHASE=$(PHASE)'

census:
	python3 $(HERE)/prepare_finite.py prepare readonly-census
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/readonly-census/input --report-dir $(HERE)/readonly-census --output-dir $(ROOT)/kprog/x86/app-coverage-readonly --generator $(HERE)/readonly-census/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

artifacts:
	tar -czf $(HERE)/readonly-artifacts.tar.gz --exclude=__pycache__ --exclude=.lake --exclude=target --exclude=build -C $(HERE) readonly-layout bcc-real-11 -C $(RO_SOURCE) kprog/formal kprog/x86/x86_sim_local_bpf.h kprog/x86/micro-prog/generate_micro_sim_proofs.py kprog/x86/native_lab/native_link/src/main.rs kprog/x86/native_lab/native_link/src/x86.rs
