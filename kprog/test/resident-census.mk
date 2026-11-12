SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/verified/20261112-resident-census
RUN_OUTPUT ?= $(OUTPUT)/control
INPUTS := /workspaces/kprog-raw/var-tmp/CL/census-inputs/inputs/run-inventory.json
RESOURCES := /workspaces/kprog-raw/var-tmp/CL/census-inputs/inputs/resource-index.json
STAGE := $(ROOT)/vendor/build/native-bpf/x86/stage
STATS_RUNS ?= x86_kvm_corpus_20261111_184428_882758 x86_kvm_corpus_20261111_191024_348289 x86_kvm_corpus_20261111_193648_926655 x86_kvm_corpus_20261111_200309_471678 x86_kvm_corpus_20261111_202934_974828 x86_kvm_corpus_20261111_205641_469520

.PHONY: prepare run
prepare:
	install -d $(OUTPUT)/source-resources
	tar --skip-old-files -xzf $(ROOT)/corpus/results/kprog_app_coverage_20261109/resident-census/stock-resource-inputs.tar.gz -C $(OUTPUT)/source-resources
	taskset -c 8-19 python3 $(ROOT)/kprog/test/resident_verified_census.py prepare --output $(OUTPUT) \
		--inputs $(INPUTS) --resources $(RESOURCES) --retained-root /workspaces/kprog-raw/var-tmp \
		--source-resources $(OUTPUT)/source-resources \
		--producer bcc/set=$(STAGE)/bcc --producer katran=$(STAGE)/katran \
		--producer cilium/agent=$(STAGE)/cilium --producer otelcol-ebpf-profiler/profiling=$(STAGE)/otelcol-ebpf-profiler \
		--producer tetragon/observer=$(ROOT)/corpus/results/verified-tetragon-probe/tetragon \
		--producer tracee/monitor=$(ROOT)/corpus/results/verified-tracee-core-reg/tracee \
		$(foreach run,$(STATS_RUNS),--stats-run $(ROOT)/corpus/results/$(run))

run:
	$(MAKE) -C $(ROOT)/kprog/libnativeloader -o trusted-service trusted-service-kvm \
		BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader OUTPUT=$(RUN_OUTPUT) VM_CPUS=8 VM_MEM=64G \
		SERVICE_RUN='python3 $(ROOT)/kprog/test/resident_verified_census.py guest --output $(OUTPUT) --service-state $(RUN_OUTPUT)/state --loader-directory /workspaces/.agent-state/kprog-ck/verified-loader'
