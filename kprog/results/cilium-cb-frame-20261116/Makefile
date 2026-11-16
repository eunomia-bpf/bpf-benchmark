ROOT := /workspaces/repository
TMP := /var/tmp/kprog-tmp/perf/cilium-cb-frame
RAW := /workspaces/kprog-raw/perf/20261116-cilium-cb-frame
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
RELEASE := $(shell cat $(KDIR)/include/config/kernel.release)
ANSWERS := $(ROOT)/vendor/build/native-bpf/x86/$(RELEASE)/answers/cilium.h

.PHONY: host dry-run
host:
	install -d $(TMP) $(RAW)
	date -u +%FT%TZ > $(RAW)/started
	$(MAKE) -C $(ROOT)/vendor/bpf $(ANSWERS) > $(RAW)/core-answers.log 2>&1
	clang-18 -O2 -I$(ROOT)/vendor/bpf/cilium/bpf/include -include $(ROOT)/vendor/bpf/core-compat.h \
		-D__KPROG_CORE_ANSWERS='"$(ANSWERS)"' -c $(ROOT)/kprog/results/cilium-cb-frame-20261116/layout.c -o $(TMP)/native-view.o
	clang-18 -O2 -DKERNEL_VIEW -I$(ROOT)/vendor/bpf/targets/x86/$(RELEASE) \
		$(ROOT)/kprog/results/cilium-cb-frame-20261116/layout.c $(TMP)/native-view.o -o $(TMP)/layout
	$(TMP)/layout > $(RAW)/layout.json
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo test --release -- --test-threads=1 > $(RAW)/native-link-tests.log 2>&1
	$(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/loader-build.log 2>&1
	$(MAKE) -B -C $(ROOT)/vendor/bpf native-cilium > $(RAW)/native-cilium-build.log 2>&1
	date -u +%FT%TZ > $(RAW)/finished

dry-run:
	$(MAKE) -n -C $(ROOT)/vendor/bpf $(ANSWERS)
	$(MAKE) -n -B -C $(ROOT)/vendor/bpf native-cilium
