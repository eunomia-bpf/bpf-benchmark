#!/usr/bin/env python3
import subprocess, sys, time, threading

cmd = [
    "/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec",
    "run-kernel",
    "--program", "/home/yunwei37/workspace/bpf-benchmark/micro/programs/cmov_select.bpf.o",
    "--io-mode", "staged",
    "--repeat", "100",
    "--memory", "/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/cmov_select.mem",
    "--input-size", "3464",
    "--rejit",
    "--daemon-path", "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
]
print("Starting process...", flush=True)
proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print("Process PID:", proc.pid, flush=True)
stdout_data = []
stderr_data = []

def drain(pipe, store, name):
    for line in pipe:
        decoded = line.decode(errors="replace")
        store.append(decoded)
        print(f"{name}[{len(store)}]: {decoded[:100]}", flush=True)

t1 = threading.Thread(target=drain, args=(proc.stdout, stdout_data, "STDOUT"))
t2 = threading.Thread(target=drain, args=(proc.stderr, stderr_data, "STDERR"))
t1.start()
t2.start()

for i in range(55):
    time.sleep(1)
    if proc.poll() is not None:
        print(f"Done at {i+1}s, ret={proc.returncode}", flush=True)
        break
    print(f"Running: {i+1}s, stdout={len(stdout_data)}, stderr={len(stderr_data)}", flush=True)

t1.join(timeout=2)
t2.join(timeout=2)
if proc.poll() is None:
    proc.kill()
    print("KILLED", flush=True)
print(f"Final: stdout={len(stdout_data)}, stderr={len(stderr_data)}")
