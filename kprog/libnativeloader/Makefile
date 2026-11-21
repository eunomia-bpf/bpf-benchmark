BUILD_DIR ?= build
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86

.PHONY: all clean

all:
	cmake -S . -B "$(BUILD_DIR)" \
		-DNATIVE_LOADER_REPO_ROOT="$(REPO_ROOT)" \
		-DNATIVE_LOADER_LIBBPF_PREFIX="$(LIBBPF_PREFIX)" \
		-DNATIVE_LOADER_LIBBPF_LIBRARY="$(LIBBPF_LIBRARY)" \
		-DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE="$(KERNEL_OFFSETS_INCLUDE)"
	cmake --build "$(BUILD_DIR)" --target native_loader native_loader_shared trusted-native-loader

clean:
	rm -rf "$(BUILD_DIR)"

# Checked verification uses the same kernel, image and compiler/loader base.
KDIR ?= /workspaces/.agent-state/kprog-ck/build-x86
CHECKED_COMPILER_BASE ?= /workspaces/.agent-state/kprog-ck/verified-compiler
CHECKED_LOADER ?= /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
CHECKED_APP ?= otelcol-ebpf-profiler/profiling
CHECKED_APPS ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
CHECKED_STAMP := $(shell date -u +%Y%m%dT%H%M%S%NZ)
CHECKED_OUTPUT ?= /workspaces/kprog-raw/verified/checked-corpus-$(CHECKED_STAMP)
CHECKED_GUEST_BUILD ?= /var/tmp/kprog-tmp/one-image
CHECKED_HOST_CPUS ?= 20-23

.PHONY: checked-corpus checked-corpus-all
checked-corpus:
	install -d "$(CHECKED_OUTPUT)" "$(CHECKED_OUTPUT)/loader-inputs" "$(CHECKED_OUTPUT)/bounds-inputs" "$(CHECKED_GUEST_BUILD)"
	date -u +%FT%TZ > "$(CHECKED_OUTPUT)/started"
	set -e; exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8; \
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c $(CHECKED_HOST_CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(REPO_ROOT) --rwdir $(REPO_ROOT) --rwdir $(CHECKED_OUTPUT) --rwdir /var/tmp=$(CHECKED_GUEST_BUILD) \
		--rodir $(CHECKED_OUTPUT)/loader-inputs=$(dir $(CHECKED_LOADER)) --rodir $(CHECKED_OUTPUT)/bounds-inputs=$(CHECKED_COMPILER_BASE) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(REPO_ROOT)/kprog/test/run_checked_otel.sh $(CHECKED_OUTPUT) $(CHECKED_APP) $(CHECKED_OUTPUT)/loader-inputs/$(notdir $(CHECKED_LOADER)) $(CHECKED_OUTPUT)/bounds-inputs/packet-bounds' || status=$$?; \
	printf '%s\n' "$$status" > "$(CHECKED_OUTPUT)/exit-code"; date -u +%FT%TZ > "$(CHECKED_OUTPUT)/finished"; \
	exit $$status

checked-corpus-all:
	install -d "$(CHECKED_OUTPUT)"
	failed=0; for app in $(CHECKED_APPS); do \
		$(MAKE) checked-corpus CHECKED_OUTPUT=$(CHECKED_OUTPUT)/$${app%%/*} CHECKED_APP=$$app \
			CHECKED_HOST_CPUS=$(CHECKED_HOST_CPUS) CHECKED_LOADER=$(CHECKED_LOADER) \
			> $(CHECKED_OUTPUT)/$${app%%/*}.log 2>&1 && rc=0 || rc=$$?; \
		printf '%s\t%s\n' "$$app" "$$rc" >> $(CHECKED_OUTPUT)/run-codes.tsv; \
		if test $$rc -ne 0; then failed=1; fi; \
	done; exit $$failed
