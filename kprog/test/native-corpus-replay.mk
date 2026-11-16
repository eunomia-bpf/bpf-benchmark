SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/perf/20261116-native-corpus-replay
PAYLOAD := $(ROOT)/vendor/build/native-bpf/x86/stage
CAPTURES ?= $(ROOT)/kprog/test/native-corpus-captures.json
LINKER := $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
CONTEXT_COMPILER := /var/tmp/kprog-tmp/perf/perf-context-lto/perf-context-lto
KERNEL_BTF := /workspaces/.agent-state/kprog-ck/build-x86/vmlinux
APPS ?=
REPLAY_ARGS ?=

.PHONY: replay inventory
inventory: REPLAY_ARGS += --inventory
inventory: replay

replay:
	install -d $(OUTPUT)
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 16 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/replay_native_corpus.py --payload $(PAYLOAD) --captures $(CAPTURES) --linker $(LINKER) --context-compiler $(CONTEXT_COMPILER) --kernel-btf $(KERNEL_BTF) --output $(OUTPUT) $(if $(APPS),--apps $(APPS)) $(REPLAY_ARGS)
