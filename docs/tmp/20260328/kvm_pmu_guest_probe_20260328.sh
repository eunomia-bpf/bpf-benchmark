#!/bin/bash
set -euo pipefail

run_cmd() {
    local label="$1"
    shift
    echo "=== BEGIN ${label} ==="
    set +e
    bash -lc "$*"
    local rc=$?
    set -e
    echo "=== END ${label} (rc=${rc}) ==="
    echo
}

run_python_probe() {
    local label="$1"
    echo "=== BEGIN ${label} ==="
    set +e
    python3 - <<'PY'
import ctypes
import os
import struct

libc = ctypes.CDLL("libc.so.6", use_errno=True)
SYS_perf_event_open = 298

def probe(config: int, desc: str) -> None:
    attr = bytearray(112)
    struct.pack_into("I", attr, 0, 0)      # PERF_TYPE_HARDWARE
    struct.pack_into("I", attr, 4, 112)    # sizeof(perf_event_attr)
    struct.pack_into("Q", attr, 8, config)
    fd = libc.syscall(SYS_perf_event_open, ctypes.c_char_p(bytes(attr)), -1, 0, -1, 0)
    err = ctypes.get_errno()
    print(f"{desc}: fd={fd}, errno={err}")
    if fd >= 0:
        os.close(fd)

probe(5, "branch-misses default attr")

attr = bytearray(112)
struct.pack_into("I", attr, 0, 0)          # PERF_TYPE_HARDWARE
struct.pack_into("I", attr, 4, 112)        # sizeof(perf_event_attr)
struct.pack_into("Q", attr, 8, 5)          # PERF_COUNT_HW_BRANCH_MISSES
flags = (1 << 0) | (1 << 5) | (1 << 6)     # disabled, exclude_kernel, exclude_hv
struct.pack_into("Q", attr, 40, flags)
fd = libc.syscall(SYS_perf_event_open, ctypes.c_char_p(bytes(attr)), -1, 0, -1, 0)
err = ctypes.get_errno()
print(f"branch-misses exclude_kernel=1 exclude_hv=1: fd={fd}, errno={err}")
if fd >= 0:
    os.close(fd)
PY
    local rc=$?
    set -e
    echo "=== END ${label} (rc=${rc}) ==="
    echo
}

run_cmd "whoami" "whoami"
run_cmd "uname -a" "uname -a"
run_cmd "which perf" "command -v perf || echo 'perf not found in PATH'"
run_cmd "perf_event_paranoid initial" "cat /proc/sys/kernel/perf_event_paranoid"
run_cmd "cpuinfo model name" "grep 'model name' /proc/cpuinfo"
run_cmd "perf stat initial" "perf stat -e branches,branch-misses ls 2>&1"
run_cmd "perf list hw initial" "perf list hw 2>&1"
run_cmd "dmesg pmu" "dmesg | grep -i pmu 2>&1"
run_cmd "ls /sys/devices/cpu/events" "ls /sys/devices/cpu/events/ 2>&1"
run_cmd "ls /sys/devices/cpu_core/events" "ls /sys/devices/cpu_core/events/ 2>&1"
run_cmd "ls /sys/devices/cpu_atom/events" "ls /sys/devices/cpu_atom/events/ 2>&1"
run_python_probe "perf_event_open initial"

run_cmd "lower perf_event_paranoid" "echo -1 > /proc/sys/kernel/perf_event_paranoid && cat /proc/sys/kernel/perf_event_paranoid"
run_cmd "perf stat after perf_event_paranoid=-1" "perf stat -e branches,branch-misses ls 2>&1"
run_cmd "perf list hw after perf_event_paranoid=-1" "perf list hw 2>&1"
run_python_probe "perf_event_open after perf_event_paranoid=-1"
