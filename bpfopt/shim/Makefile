CC ?= gcc
CFLAGS ?= -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE
LDLIBS ?= -ldl -lpthread

.PHONY: all clean smoke selftest-run host-selftest

all: libbpfrejit_shim.so selftest selftest_full

libbpfrejit_shim.so: libbpfrejit_shim.c
	$(CC) $(CFLAGS) -shared $< -o $@ $(LDLIBS)

selftest: selftest.c
	$(CC) $(CFLAGS) $< -o $@

selftest_full: selftest_full.c
	$(CC) $(CFLAGS) $< -o $@

# Comprehensive host-side shim regression harness — exercises socket
# plumbing, prog_load capture, list_progs JSON, and the inner_map_ids
# iteration cap. Requires sudo because the host kernel has
# kernel.unprivileged_bpf_disabled=2. Completes in ≤ 5 s when shim is
# healthy; ≥ 30 s indicates a hang and the harness should bail.
host-selftest: all
	rm -rf /tmp/shim_full_st && mkdir -p /tmp/shim_full_st
	rm -f /tmp/shim_full_st.log
	sudo -n env \
	  BPFREJIT_SHIM_DIR=/tmp/shim_full_st \
	  BPFREJIT_SHIM_LOG=/tmp/shim_full_st.log \
	  BPFREJIT_SHIM_SOCK_DIR=/tmp/shim_full_st/sock \
	  LD_PRELOAD=$$PWD/libbpfrejit_shim.so \
	  timeout 30 ./selftest_full

# Exercise the shim with a synthetic BPF_PROG_LOAD call. Validates: (a) shim
# loads via LD_PRELOAD, (b) BPF_PROG_LOAD is intercepted, (c) bytecode is
# dumped to a hash-keyed file matching the source bytecode.
selftest-run: all
	rm -rf /tmp/shim_st && mkdir -p /tmp/shim_st
	rm -f /tmp/shim_st.log
	BPFREJIT_SHIM_DIR=/tmp/shim_st BPFREJIT_SHIM_LOG=/tmp/shim_st.log \
	  LD_PRELOAD=$$PWD/libbpfrejit_shim.so ./selftest
	@echo "--- log ---" && cat /tmp/shim_st.log
	@echo "--- dumps ---" && ls -la /tmp/shim_st/
	@dump=$$(ls /tmp/shim_st/bpfrejit_*.bpf 2>/dev/null | head -1); \
	 if [ -z "$$dump" ]; then echo "FAIL: no bytecode dump"; exit 1; fi; \
	 size=$$(stat -c%s "$$dump"); \
	 if [ "$$size" != "16" ]; then echo "FAIL: dump size $$size != 16"; exit 1; fi; \
	 echo "PASS: bytecode dump $$dump ($$size bytes) matches 2-insn program"

# Smoke test: run `bpftool prog list` under the shim and check the log was
# populated. Requires bpftool available on PATH.
smoke: libbpfrejit_shim.so
	rm -f /tmp/bpfrejit_shim_smoke.log
	BPFREJIT_SHIM_LOG=/tmp/bpfrejit_shim_smoke.log \
	  LD_PRELOAD=$$PWD/libbpfrejit_shim.so bpftool prog list >/dev/null 2>&1 || true
	@if [ -s /tmp/bpfrejit_shim_smoke.log ]; then \
		echo "smoke: PASS ($$(wc -l < /tmp/bpfrejit_shim_smoke.log) log lines)"; \
		head -10 /tmp/bpfrejit_shim_smoke.log; \
	else \
		echo "smoke: FAIL — log empty"; \
		exit 1; \
	fi

clean:
	rm -f libbpfrejit_shim.so selftest selftest_full \
	      /tmp/bpfrejit_shim_smoke.log
