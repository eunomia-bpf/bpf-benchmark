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
