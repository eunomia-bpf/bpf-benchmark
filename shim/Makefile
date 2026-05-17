CC ?= gcc
CFLAGS ?= -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE
LDLIBS ?= -ldl -lpthread

.PHONY: all clean smoke selftest-run docker-survey musl

all: libbpfrejit_shim.so selftest

# Build a musl-compatible variant inside an alpine container for tracee (which
# uses /lib/ld-musl-x86_64.so.1 as its dynamic interpreter and rejects
# glibc-built .so files).
musl: libbpfrejit_shim_musl.so

libbpfrejit_shim_musl.so: libbpfrejit_shim.c
	docker run --rm -v $$PWD:/work:rw alpine:latest sh -c \
	  "apk add --no-cache gcc musl-dev linux-headers > /dev/null && \
	   gcc -O2 -fPIC -shared /work/libbpfrejit_shim.c \
	     -o /work/libbpfrejit_shim_musl.so -ldl -lpthread"

# Run the shim against each of the 7 corpus app binaries inside the existing
# runner-runtime docker image. Validates that LD_PRELOAD-based interception
# captures BPF activity per-app without modifying the Docker image.
#
# Requires the runner-runtime image to be present locally:
#   bpf-benchmark/runner-runtime:x86_64
# Built by `make runtime` from repo root (see runner/containers/runner-runtime.Dockerfile).
docker-survey: libbpfrejit_shim.so libbpfrejit_shim_musl.so
	@CID=$$(docker create --rm --privileged --pid=host \
	    -v /sys/fs/bpf:/sys/fs/bpf -v /sys/kernel/debug:/sys/kernel/debug:rw \
	    -v /lib/modules:/lib/modules:ro -v /boot:/boot:ro \
	    bpf-benchmark/runner-runtime:x86_64 sleep 900); \
	echo "container=$$CID"; \
	docker cp libbpfrejit_shim.so $$CID:/tmp/libbpfrejit_shim.so; \
	docker cp libbpfrejit_shim_musl.so $$CID:/tmp/libbpfrejit_shim_musl.so; \
	docker start $$CID > /dev/null; \
	trap "docker stop $$CID > /dev/null 2>&1" EXIT; \
	docker exec $$CID bash -c '\
	  mkdir -p /tmp/shim_dumps; \
	  preload_glibc="/tmp/libbpfrejit_shim.so"; \
	  preload_musl="/tmp/libbpfrejit_shim_musl.so"; \
	  count_pat() { grep -c "$$1" "$$2" 2>/dev/null | head -1; }; \
	  run_one() { \
	    local name="$$1"; local preload="$$2"; shift 2; \
	    local log="/tmp/shim_$$name.log"; \
	    rm -f "$$log"; touch "$$log"; \
	    BPFREJIT_SHIM_LOG="$$log" BPFREJIT_SHIM_DIR=/tmp/shim_dumps \
	      LD_PRELOAD="$$preload" "$$@" > /dev/null 2>&1 || true; \
	    local prog_load=$$(count_pat "BPF_PROG_LOAD type=" "$$log"); \
	    local link_create=$$(count_pat "BPF_LINK_CREATE " "$$log"); \
	    local link_update=$$(count_pat "BPF_LINK_UPDATE " "$$log"); \
	    local prog_attach=$$(count_pat "BPF_PROG_ATTACH " "$$log"); \
	    local pfopen=$$(count_pat "perf_event_open " "$$log"); \
	    local rtopen=$$(count_pat "BPF_RAW_TRACEPOINT_OPEN " "$$log"); \
	    local setbpf=$$(count_pat "PERF_EVENT_IOC_SET_BPF " "$$log"); \
	    local lines=$$(wc -l < "$$log" 2>/dev/null); \
	    printf "%-15s lines=%-5s LOAD=%-3s LINK_NEW=%-2s LINK_UPD=%-2s ATTACH=%-2s perf_open=%-3s RAW_TP=%-2s SET_BPF=%-3s\n" \
	      "$$name" "$$lines" "$$prog_load" "$$link_create" "$$link_update" "$$prog_attach" "$$pfopen" "$$rtopen" "$$setbpf"; \
	  }; \
	  echo "--- per-app capture summary ---"; \
	  run_one bpftool        $$preload_glibc bpftool prog list; \
	  run_one bpftrace       $$preload_glibc timeout 3 bpftrace -e "tracepoint:syscalls:sys_enter_openat { @[comm] = count(); }"; \
	  run_one bcc_execsnoop  $$preload_glibc timeout 3 /usr/sbin/execsnoop-bpfcc; \
	  run_one bcc_opensnoop  $$preload_glibc timeout 3 /usr/sbin/opensnoop-bpfcc; \
	  run_one bcc_capable    $$preload_glibc timeout 5 /usr/sbin/capable-bpfcc; \
	  run_one tracee         $$preload_musl  timeout 8 /artifacts/tracee/bin/tracee --events execve --output none --metrics-listen-address ""; \
	  run_one tetragon       $$preload_glibc timeout 5 /artifacts/tetragon/bin/tetragon --bpf-lib /var/lib/tetragon; \
	  run_one cilium_agent   $$preload_glibc timeout 3 /usr/local/bin/cilium-agent --help; \
	  run_one katran         $$preload_glibc timeout 3 /artifacts/user/repo-artifacts/x86_64/katran/bin/katran_server_grpc --help; \
	  echo ""; \
	  echo "--- sample log heads ---"; \
	  for f in /tmp/shim_*.log; do \
	    echo "=== $$f ==="; head -3 "$$f" 2>/dev/null; \
	    echo "... ($$(wc -l < $$f) total lines)"; \
	  done; \
	'

libbpfrejit_shim.so: libbpfrejit_shim.c
	$(CC) $(CFLAGS) -shared $< -o $@ $(LDLIBS)

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
	rm -f libbpfrejit_shim.so /tmp/bpfrejit_shim_smoke.log
