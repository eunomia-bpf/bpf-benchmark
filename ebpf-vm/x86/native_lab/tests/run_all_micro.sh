#!/bin/sh
# Drive every micro benchmark through three runtimes in VM:
#
#   1. native_lab: clang-emitted x86 .text -> native-link -> bpf_x86_native_lab
#      kinsn -> splatted into BPF JIT image.
#   2. kernel BPF JIT (baseline): the stock .bpf.o through libbpf +
#      BPF_PROG_TEST_RUN.
#
# Writes one JSON line per (program, runtime) tuple to stdout. Each line is
# the raw micro_exec sample_result with a leading {"program": ..., "runtime": ...}
# wrapper so the downstream consumer can group by (program, runtime).
set -eu

REPO=/home/yunwei37/workspace/bpf-benchmark
LINKER="$REPO/ebpf-vm/x86/native_lab/native_link/target/release/native-link"
MICRO_EXEC="$REPO/runner/build-llvmbpf/micro_exec"
KO="$REPO/.cache/repo-build/host/kinsn/x86_64/bpf_x86_native_lab.ko"
PROGRAMS_DIR="$REPO/micro/programs"
GENERATED_DIR="$REPO/micro/generated-inputs"
YAML="$REPO/micro/config/micro_pure_jit.yaml"
INNER_REPEAT="${INNER_REPEAT:-1000}"

echo "[vm] kernel: $(uname -r)" >&2
mount -t debugfs none /sys/kernel/debug 2>/dev/null || true
if ! lsmod | grep -q '^bpf_x86_native_lab\b'; then
    insmod "$KO"
fi

# Extract (name, base_name, kernel_input_size, expected_result, io_mode)
# tuples from the micro yaml. We rely on the file's stable indentation:
# each benchmark begins with `  - name: NAME` and adjacent lines carry the
# other fields. Programs with io_mode==packet have only ctx->data input
# (no 8-byte result prefix); io_mode==staged adds the 8-byte prefix.
python3 - <<PYEOF
import json
import os
import re
import subprocess
import sys

REPO = "$REPO"
LINKER = "$LINKER"
MICRO_EXEC = "$MICRO_EXEC"
PROGRAMS_DIR = "$PROGRAMS_DIR"
GENERATED_DIR = "$GENERATED_DIR"
YAML = "$YAML"
INNER_REPEAT = "$INNER_REPEAT"

import yaml as pyyaml  # type: ignore

with open(YAML) as f:
    cfg = pyyaml.safe_load(f)

bench_default = cfg.get("benchmark_defaults", {})
default_retval = bench_default.get("expected_retval", 2)

def run_native_lab(name, base_name, input_size, expected_retval):
    so_path = os.path.join(PROGRAMS_DIR, base_name + ".native.so")
    if not os.path.exists(so_path):
        return {"error": f"missing {so_path}"}
    sym = base_name + "_xdp"
    blob = f"/tmp/{base_name}.native.bin"
    link = subprocess.run(
        [LINKER, "--input", so_path, "--symbol", sym, "--output", blob],
        capture_output=True, text=True
    )
    if link.returncode != 0:
        return {"error": "linker_failed", "stderr": link.stderr.strip()}

    mem = os.path.join(GENERATED_DIR, base_name + ".mem")
    cmd = [
        MICRO_EXEC, "run-native-lab",
        "--program", blob,
        "--memory", mem,
        "--input-size", str(input_size),
        "--inner-repeat", INNER_REPEAT,
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    if proc.returncode != 0:
        return {"error": "run_failed", "stderr": proc.stderr.strip()[-2000:]}
    last = [ln for ln in proc.stdout.splitlines() if ln.startswith("{")]
    if not last:
        return {"error": "no_json", "stdout": proc.stdout[-500:]}
    return json.loads(last[-1])

def run_kernel_baseline(name, base_name, input_size, io_mode, expected_retval):
    bpf_o = os.path.join(PROGRAMS_DIR, base_name + ".bpf.o")
    if not os.path.exists(bpf_o):
        return {"error": f"missing {bpf_o}"}
    mem = os.path.join(GENERATED_DIR, base_name + ".mem")
    cmd = [
        MICRO_EXEC, "test-run",
        "--program", bpf_o,
        "--memory", mem,
        "--input-size", str(input_size),
        "--inner-repeat", INNER_REPEAT,
        "--io-mode", io_mode,
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    if proc.returncode != 0:
        return {"error": "run_failed", "stderr": proc.stderr.strip()[-2000:]}
    last = [ln for ln in proc.stdout.splitlines() if ln.startswith("{")]
    if not last:
        return {"error": "no_json", "stdout": proc.stdout[-500:]}
    return json.loads(last[-1])

# Skip non-xdp benchmarks (tc / cgroup_skb need different stub).
for b in cfg["benchmarks"]:
    name = b["name"]
    base = b["base_name"]
    isize = int(b.get("kernel_input_size", 0))
    io_mode = b.get("io_mode", bench_default.get("io_mode", "staged"))
    er = int(b.get("expected_retval", default_retval))
    tags = b.get("tags", [])

    # Skip programs whose stub-type doesn't match (tc / cgroup_skb).
    if "non-xdp" in tags:
        sys.stdout.write(json.dumps({
            "program": name, "runtime": "native_lab", "skip": "non-xdp"
        }) + "\n")
        sys.stdout.write(json.dumps({
            "program": name, "runtime": "kernel_jit", "skip": "non-xdp"
        }) + "\n")
        continue

    print(f"[run] {name} (base={base}, input={isize}, io={io_mode}, expected_retval={er})", file=sys.stderr)

    nl = run_native_lab(name, base, isize, er)
    sys.stdout.write(json.dumps({"program": name, "runtime": "native_lab", **nl}) + "\n")
    sys.stdout.flush()

    kj = run_kernel_baseline(name, base, isize, io_mode, er)
    sys.stdout.write(json.dumps({"program": name, "runtime": "kernel_jit", **kj}) + "\n")
    sys.stdout.flush()
PYEOF
