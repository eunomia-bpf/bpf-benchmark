#!/usr/bin/env python3
"""Traces driver.py execution to find where hang occurs."""
import time, sys
sys.path.insert(0, '/home/yunwei37/workspace/bpf-benchmark')

import micro.driver as d

orig_run_command = d.run_command
orig_parse = d.parse_runner_sample

def timed_run_command(command, cpu):
    print(f"  run_command starting: {' '.join(str(c) for c in command[-8:])}", flush=True)
    t = time.time()
    result = orig_run_command(command, cpu)
    print(f"  run_command done: {time.time()-t:.2f}s rc={result.returncode}", flush=True)
    return result

def timed_parse(stdout):
    print(f"  parse starting (stdout_len={len(stdout)})", flush=True)
    t = time.time()
    result = orig_parse(stdout)
    print(f"  parse done: {time.time()-t:.2f}s", flush=True)
    return result

d.run_command = timed_run_command
d.parse_runner_sample = timed_parse

print("Starting driver.py main...", flush=True)
t = time.time()
ret = d.main(['suite', '--runtime', 'kernel-rejit',
              '--daemon-path', 'daemon/target/release/bpfrejit-daemon',
              '--iterations', '1', '--warmups', '1', '--repeat', '100',
              '--bench', 'cmov_select', '--output', '/dev/null'])
print(f"main returned: {ret}, elapsed={time.time()-t:.2f}s", flush=True)
