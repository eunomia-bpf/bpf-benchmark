#!/usr/bin/env python3
"""Test running cmov_select kernel-rejit twice sequentially."""
import subprocess, time, sys

RUNNER = '/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec'
DAEMON = '/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon'
PROG = '/home/yunwei37/workspace/bpf-benchmark/micro/programs/cmov_select.bpf.o'
MEM = '/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/cmov_select.mem'

cmd = ['sudo', '-n', RUNNER, 'run-kernel',
       '--program', PROG, '--io-mode', 'staged',
       '--repeat', '100',
       '--memory', MEM, '--input-size', '3464',
       '--rejit', '--daemon-path', DAEMON]

for run in range(3):
    t = time.time()
    print(f"Run {run+1}: starting...", flush=True)
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    elapsed = time.time() - t
    print(f"Run {run+1}: done in {elapsed:.2f}s, rc={r.returncode}", flush=True)
    lines = r.stdout.strip().splitlines()
    print(f"  stdout: {len(lines)} lines", flush=True)

print("All runs complete!", flush=True)
