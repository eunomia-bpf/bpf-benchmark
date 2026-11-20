ROOT := /workspaces/repository
PERF_BUILD := /workspaces/.agent-state/kprog-ck/perf
JOBS ?= 4

.PHONY: perf
perf:
	install -d $(PERF_BUILD)
	$(MAKE) -C $(ROOT)/vendor/linux-framework/tools/perf O=$(PERF_BUILD)/ -j$(JOBS) \
		NO_LIBTRACEEVENT=1 NO_LIBPYTHON=1 NO_LIBPERL=1 NO_LIBBABELTRACE=1 \
		NO_LIBBPF=1 NO_LIBPFM4=1 WERROR=0 PYTHON=/usr/bin/python3
