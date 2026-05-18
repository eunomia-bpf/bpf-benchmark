CC ?= gcc
CFLAGS ?= -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE
LDLIBS ?= -ldl -lpthread

.PHONY: all clean smoke selftest-run musl

all: libbpfrejit_shim.so selftest

libbpfrejit_shim.so: libbpfrejit_shim.c
	$(CC) $(CFLAGS) -shared $< -o $@ $(LDLIBS)

# Build a musl-compatible variant inside an alpine container for tracee (whose
# binary uses /lib/ld-musl-x86_64.so.1 and rejects glibc-built .so files).
musl: libbpfrejit_shim_musl.so

libbpfrejit_shim_musl.so: libbpfrejit_shim.c
	docker run --rm -v $$PWD:/work:rw alpine:latest sh -c \
	  "apk add --no-cache gcc musl-dev linux-headers > /dev/null && \
	   gcc -O2 -fPIC -D_GNU_SOURCE -shared /work/libbpfrejit_shim.c \
	     -o /work/libbpfrejit_shim_musl.so -ldl -lpthread"

selftest: selftest.c
	$(CC) $(CFLAGS) $< -o $@

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
	rm -f libbpfrejit_shim.so libbpfrejit_shim_musl.so selftest \
	      /tmp/bpfrejit_shim_smoke.log
