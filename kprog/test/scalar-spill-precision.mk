SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/perf/20261114-scalar-spill-precision
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
LIBBPF := $(ROOT)/runner/build-llvmbpf/vendor/libbpf
OPTIMIZATION ?= O3
CODEGEN_ARGS ?=
REPLAY_ARGS ?=
REPLAY_BUILD ?= /var/tmp/kprog-tmp/perf/retained-proof-replay
BACKEND_ARGS ?=

.PHONY: build run analyze codegen whole-word replay values-build values-run backend-check checked-corpus
checked-corpus:
	install -d $(OUTPUT) $(REPLAY_BUILD)
	date -u +%FT%TZ > $(OUTPUT)/started
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c 16-17 prlimit --as=85899345920 -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir /var/tmp=$(REPLAY_BUILD) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 2 --memory 48G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(ROOT)/kprog/test/run_checked_otel.sh $(OUTPUT)' || status=$$?; \
	printf '%s\n' "$$status" > $(OUTPUT)/exit-code; date -u +%FT%TZ > $(OUTPUT)/finished; exit $$status

backend-check:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_whole_word_backend.py --output $(OUTPUT) --clang $(ROOT)/kprog/stock-path/bin/clang $(BACKEND_ARGS)

values-build:
	install -d $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_values.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(OUTPUT)/values-client
	llc-18 -O3 -march=bpf -mcpu=v4 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(ROOT)/kprog/test/scalar_spill_values.mir -o $(OUTPUT)/original.o
	python3 $(ROOT)/kprog/x86/whole_word_spills.py $(ROOT)/kprog/test/scalar_spill_values.mir $(OUTPUT)/lowered.mir
	llc-18 -O3 -march=bpf -mcpu=v4 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(OUTPUT)/lowered.mir -o $(OUTPUT)/lowered.o

values-run: values-build
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(OUTPUT)/values-client $(OUTPUT)/original.o $(OUTPUT)/lowered.o'

replay:
	install -d $(OUTPUT) $(REPLAY_BUILD)
	printf '%s\n' --native '$(NATIVE)' --metadata '$(METADATA)' --context '$(CONTEXT)' --source '$(SOURCE)' --proof '$(PROOF)' --symbol '$(SYMBOL)' --linker '$(LINKER)' --output '$(OUTPUT)' $(REPLAY_ARGS) > $(OUTPUT)/arguments
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir /var/tmp=$(REPLAY_BUILD) --overlay-rwdir /tmp --disable-monitor --verbose --cpus 1 --memory 8G --append 'loglevel=4 panic=30 oops=panic' --exec 'mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; mount -t bpf bpffs /sys/fs/bpf; insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko; CLANG=$(ROOT)/kprog/stock-path/bin/clang python3 $(ROOT)/kprog/test/verify_retained_proof.py @$(OUTPUT)/arguments'

whole-word:
	install -d $(OUTPUT)
	taskset -c 18-19 python3 $(ROOT)/kprog/x86/whole_word_spills.py $(MIR) $(OUTPUT)/whole.mir --low $(LOW) --high $(HIGH)
	taskset -c 18-19 llc-18 -O3 -march=bpf -mcpu=v4 -bpf-stack-size=4096 -verify-machineinstrs -start-before=prologepilog -stop-after=prologepilog $(OUTPUT)/whole.mir -o $(OUTPUT)/after.mir
	taskset -c 18-19 llc-18 -O3 -march=bpf -mcpu=v4 -bpf-stack-size=4096 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(OUTPUT)/whole.mir -o $(OUTPUT)/whole.o

codegen:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/spill_codegen_probe.py $(BITCODE) $(OUTPUT) --optimization $(OPTIMIZATION) $(CODEGEN_ARGS)

analyze:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/analyze_spill_lifetimes.py $(MIR) $(REPORT)

build:
	install -d $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_precision.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(OUTPUT)/client

run: build
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(OUTPUT)/client $(OUTPUT)'
