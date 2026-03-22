#!/usr/bin/env python3
"""Test if other subprog programs also hang."""
import subprocess, time

RUNNER = '/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec'
DAEMON = '/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon'
INPUTS = '/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs'

programs = [
    ('bpf_call_chain', '/home/yunwei37/workspace/bpf-benchmark/micro/programs/bpf_call_chain.bpf.o', 64),
    ('local_call_fanout', '/home/yunwei37/workspace/bpf-benchmark/micro/programs/local_call_fanout.bpf.o', 64),
]

for name, prog, input_size in programs:
    mem = f'{INPUTS}/{name}.mem'
    cmd_rejit = ['sudo', '-n', RUNNER, 'run-kernel',
                 '--program', prog, '--io-mode', 'staged',
                 '--repeat', '1', '--memory', mem, '--input-size', str(input_size),
                 '--rejit', '--daemon-path', DAEMON]
    cmd_load = ['sudo', '-n', RUNNER, 'run-kernel',
                '--program', prog, '--io-mode', 'staged',
                '--repeat', '1', '--memory', mem, '--input-size', str(input_size),
                '--compile-only']

    print(f"\n=== {name} ===", flush=True)

    # Check if mem file exists
    import os
    if not os.path.exists(mem):
        print(f"  No input file: {mem}, skipping", flush=True)
        continue

    t = time.time()
    r = subprocess.run(cmd_rejit, capture_output=True, text=True, timeout=30)
    elapsed = time.time() - t
    print(f"  Run 1 (rejit): {elapsed:.2f}s, rc={r.returncode}", flush=True)

    time.sleep(0.5)

    t = time.time()
    try:
        r = subprocess.run(cmd_load, capture_output=True, text=True, timeout=30)
        elapsed = time.time() - t
        print(f"  Run 2 (load): {elapsed:.2f}s, rc={r.returncode}", flush=True)
    except subprocess.TimeoutExpired:
        print(f"  Run 2: TIMEOUT after {time.time()-t:.2f}s", flush=True)

print("\nDone!", flush=True)
