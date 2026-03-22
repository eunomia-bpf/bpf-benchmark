#!/usr/bin/env python3
"""Test how long after REJIT run the next load hangs for."""
import subprocess, time

RUNNER = '/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec'
DAEMON = '/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon'
PROG = '/home/yunwei37/workspace/bpf-benchmark/micro/programs/cmov_select.bpf.o'
MEM = '/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/cmov_select.mem'

cmd_rejit = ['sudo', '-n', RUNNER, 'run-kernel',
             '--program', PROG, '--io-mode', 'staged',
             '--repeat', '1', '--memory', MEM, '--input-size', '3464',
             '--rejit', '--daemon-path', DAEMON]

cmd_load = ['sudo', '-n', RUNNER, 'run-kernel',
            '--program', PROG, '--io-mode', 'staged',
            '--repeat', '1', '--memory', MEM, '--input-size', '3464',
            '--compile-only']

for sleep_time in [0, 1, 2, 5, 10, 20]:
    print(f"\n=== Test with sleep={sleep_time}s ===", flush=True)

    # Run rejit
    t = time.time()
    r1 = subprocess.run(cmd_rejit, capture_output=True, text=True, timeout=30)
    print(f"Run 1 (rejit): {time.time()-t:.2f}s, rc={r1.returncode}", flush=True)

    # Sleep
    if sleep_time > 0:
        print(f"Sleeping {sleep_time}s...", flush=True)
        time.sleep(sleep_time)

    # Try second load
    t = time.time()
    try:
        r2 = subprocess.run(cmd_load, capture_output=True, text=True, timeout=60)
        print(f"Run 2 (load): {time.time()-t:.2f}s, rc={r2.returncode}", flush=True)
        if r2.returncode == 0:
            print("SUCCESS after sleep!", flush=True)
    except subprocess.TimeoutExpired:
        print(f"Run 2: TIMEOUT after {time.time()-t:.2f}s", flush=True)
