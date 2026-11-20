ROOT := /workspaces/repository
PERF_BUILD := /workspaces/.agent-state/kprog-ck/perf
JOBS ?= 4

.PHONY: dependencies perf inspect
dependencies:
	DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends python3-dev libdw-dev libunwind-dev

perf:
	install -d $(PERF_BUILD)
	$(MAKE) -C $(ROOT)/vendor/linux-framework/tools/perf O=$(PERF_BUILD)/ JOBS=$(JOBS) \
		NO_LIBTRACEEVENT=1 NO_LIBPYTHON=1 NO_LIBPERL=1 NO_LIBBABELTRACE=1 \
		NO_LIBBPF=1 NO_LIBPFM4=1 WERROR=0 PYTHON=/usr/bin/python3

inspect:
	$(PERF_BUILD)/perf version --build-options

.PHONY: capture
capture:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/capture.py $(OUT) $(APP)

.PHONY: analyze
analyze:
	DEBUGINFOD_URLS= python3 $(ROOT)/kprog/results/runtime-profile-20261120/analyze.py $(OUT)

PRIVATE_BUILD := /var/tmp/kprog-tmp/perf/runtime-profile-private
.PHONY: private
private:
	install -d $(PRIVATE_BUILD) $(OUT)
	$(CC) -O3 -fsanitize=undefined -fno-sanitize-recover=all -I$(ROOT)/vendor/libbpf/src \
		$(ROOT)/kprog/results/runtime-profile-20261120/private.c -o $(PRIVATE_BUILD)/private
	$(PRIVATE_BUILD)/private
	clang-18 -O1 -S -emit-llvm -I$(ROOT)/vendor/libbpf/src \
		$(ROOT)/kprog/results/runtime-profile-20261120/private.c -o $(OUT)/private.ll

.PHONY: inline-private
inline-private:
	install -d $(PRIVATE_BUILD) $(OUT)
	$(CC) -O3 -fsanitize=undefined -fno-sanitize-recover=all -I$(ROOT)/vendor/libbpf/src \
		$(ROOT)/kprog/results/sparse-stack-cache-20261119/oracle.c -o $(PRIVATE_BUILD)/inline-private
	$(PRIVATE_BUILD)/inline-private
	clang-18 -O1 -S -emit-llvm -I$(ROOT)/vendor/libbpf/src \
		$(ROOT)/kprog/results/sparse-stack-cache-20261119/oracle.c -o $(OUT)/inline-private.ll

.PHONY: inline-private-receipt
inline-private-receipt:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/inline_private_receipt.py

.PHONY: kernel-probe-receipt
kernel-probe-receipt:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/kernel-source-report.py

USER_BUILD := /var/tmp/kprog-tmp/perf/runtime-profile-user
.PHONY: source-probes
source-probes:
	install -d $(USER_BUILD) $(OUT)
	clang-18 -O3 -g -mgeneral-regs-only -mno-red-zone -fomit-frame-pointer -fno-stack-protector \
		-c $(ROOT)/kprog/results/runtime-profile-20261120/user.c -o $(USER_BUILD)/user.o
	$(CC) -O3 -fsanitize=undefined -fno-sanitize-recover=all \
		$(ROOT)/kprog/results/runtime-profile-20261120/source-driver.c \
		$(ROOT)/kprog/results/runtime-profile-20261120/source-provider.c $(USER_BUILD)/user.o -o $(USER_BUILD)/execute
	$(USER_BUILD)/execute
	llvm-objdump-18 -dr $(USER_BUILD)/user.o > $(OUT)/user.asm

.PHONY: source-links branches
source-links:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/link.py $(OUT)

branches:
	install -d $(OUT)
	$(PERF_BUILD)/perf record -a -C 20-23 -e cycles:G -F 199 -j any_call,any_ret \
		-o $(OUT)/branches.data -- sleep 5

.PHONY: branch-decode
branch-decode:
	DEBUGINFOD_URLS= $(PERF_BUILD)/perf script -i $(OUT)/branches.data --guestkallsyms $(SYMBOLS) \
		-F time,misc,ip,brstack --no-inline --hide-call-graph --ns > $(OUT)/branches.txt

.PHONY: archive
archive:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/archive.py

.PHONY: source-generation
source-generation:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/source-generation.py $(OUT)

.PHONY: source-generation-archive
source-generation-archive:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/source-generation-archive.py $(OUT)

.PHONY: probe-pipeline-report
probe-pipeline-report:
	python3 $(ROOT)/kprog/results/runtime-profile-20261120/probe-pipeline-report.py
