#!/usr/bin/env python3
"""Minimal test to reproduce the hang and identify which syscall hangs."""
import subprocess, time, ctypes, os, sys

LIBBPF = None  # We'll use raw subprocess to test

RUNNER = '/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec'
DAEMON = '/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon'
PROG = '/home/yunwei37/workspace/bpf-benchmark/micro/programs/cmov_select.bpf.o'
MEM = '/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/cmov_select.mem'

# First run: load + REJIT + run + exit
cmd = ['sudo', '-n', RUNNER, 'run-kernel',
       '--program', PROG, '--io-mode', 'staged',
       '--repeat', '1',  # repeat=1 to avoid test_run overhead
       '--memory', MEM, '--input-size', '3464',
       '--rejit', '--daemon-path', DAEMON]

print("Run 1 (repeat=1, --rejit):", flush=True)
t = time.time()
r = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
print(f"  done in {time.time()-t:.2f}s, rc={r.returncode}", flush=True)

# Wait a bit for kernel to clean up
print("Waiting 2s...", flush=True)
time.sleep(2)

# Second run: check if --compile-only hangs (just BPF_PROG_LOAD, no test_run)
cmd_compile = ['sudo', '-n', RUNNER, 'run-kernel',
               '--program', PROG, '--io-mode', 'staged',
               '--repeat', '1',
               '--memory', MEM, '--input-size', '3464',
               '--compile-only']

print("Run 2 (compile-only, no test_run):", flush=True)
t = time.time()
r = subprocess.run(cmd_compile, capture_output=True, text=True, timeout=30)
print(f"  done in {time.time()-t:.2f}s, rc={r.returncode}", flush=True)

# Third run: check if repeat=1 WITHOUT warmup_repeat hangs
print("Run 3 (repeat=1, --rejit, should trigger daemon+test_run):", flush=True)
t = time.time()
r = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
print(f"  done in {time.time()-t:.2f}s, rc={r.returncode}", flush=True)

print("All done!", flush=True)
