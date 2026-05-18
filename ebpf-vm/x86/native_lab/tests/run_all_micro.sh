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
INNER_REPEAT="${INNER_REPEAT:-100000}"
SAMPLES="${SAMPLES:-15}"

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
SAMPLES = int("$SAMPLES")

import yaml as pyyaml  # type: ignore

with open(YAML) as f:
    cfg = pyyaml.safe_load(f)

bench_default = cfg.get("benchmark_defaults", {})
default_retval = bench_default.get("expected_retval", 2)

def native_symbol_for(base_name, tags):
    """Match the SEC name the .bpf.c macro emits (xdp / tc / cgroup_skb).
    For non-xdp programs the symbol is whatever the bench yaml's
    `program_name` overrides spell out -- we treat unknown bases as xdp.
    """
    if "non-xdp" in tags:
        # tc / cgroup_skb benchmarks set `program_name` in yaml to the
        # actual function name; we receive `base_name` here which IS that
        # function name when io_mode != staged or expected_retval != 2.
        return base_name + "_prog"
    return base_name + "_xdp"


def native_lab_prog_type_for(tags, expected_retval):
    if "tc" in tags:
        return "sched_cls"
    if "cgroup-skb" in tags or "cgroup_skb" in tags:
        return "cgroup_skb"
    return "xdp"


def _median_exec_ns(samples):
    """Sort the per-sample dicts by exec_ns and return the median entry.
    A sample with an error has no exec_ns -> sorts last; if all samples
    errored we just return the first one so the caller sees the error."""
    valid = [s for s in samples if isinstance(s.get("exec_ns"), int)]
    if not valid:
        return samples[0]
    valid.sort(key=lambda s: s["exec_ns"])
    return valid[len(valid) // 2]


def run_native_lab(name, base_name, input_size, expected_retval, tags, input_generator):
    so_path = os.path.join(PROGRAMS_DIR, base_name + ".native.so")
    if not os.path.exists(so_path):
        return {"error": f"missing {so_path}"}
    sym = native_symbol_for(base_name, tags)
    blob = f"/tmp/{base_name}.native.bin"
    link = subprocess.run(
        [LINKER, "--input", so_path, "--symbol", sym, "--output", blob],
        capture_output=True, text=True
    )
    if link.returncode != 0:
        return {"error": "linker_failed", "stderr": link.stderr.strip()}

    # input_generator names the .mem file -- multiple benchmarks (e.g.
    # tc_packet_checksum_fold and packet_checksum_fold) share one input.
    mem = os.path.join(GENERATED_DIR, input_generator + ".mem")
    pt = native_lab_prog_type_for(tags, expected_retval)
    cmd = [
        MICRO_EXEC, "run-native-lab",
        "--program", blob,
        "--memory", mem,
        "--input-size", str(input_size),
        "--inner-repeat", INNER_REPEAT,
        "--native-lab-prog-type", pt,
    ]
    samples = []
    for _ in range(SAMPLES):
        proc = subprocess.run(cmd, capture_output=True, text=True)
        if proc.returncode != 0:
            samples.append({"error": "run_failed", "stderr": proc.stderr.strip()[-2000:]})
            continue
        last = [ln for ln in proc.stdout.splitlines() if ln.startswith("{")]
        if not last:
            samples.append({"error": "no_json", "stdout": proc.stdout[-500:]})
            continue
        samples.append(json.loads(last[-1]))
    return _median_exec_ns(samples)

def run_kernel_baseline(name, base_name, input_size, io_mode, expected_retval, input_generator):
    bpf_o = os.path.join(PROGRAMS_DIR, base_name + ".bpf.o")
    if not os.path.exists(bpf_o):
        return {"error": f"missing {bpf_o}"}
    # input_generator names the .mem file -- multiple benchmarks (e.g.
    # tc_packet_checksum_fold and packet_checksum_fold) share one input.
    mem = os.path.join(GENERATED_DIR, input_generator + ".mem")
    cmd = [
        MICRO_EXEC, "test-run",
        "--program", bpf_o,
        "--memory", mem,
        "--input-size", str(input_size),
        "--inner-repeat", INNER_REPEAT,
        "--io-mode", io_mode,
    ]
    samples = []
    for _ in range(SAMPLES):
        proc = subprocess.run(cmd, capture_output=True, text=True)
        if proc.returncode != 0:
            samples.append({"error": "run_failed", "stderr": proc.stderr.strip()[-2000:]})
            continue
        last = [ln for ln in proc.stdout.splitlines() if ln.startswith("{")]
        if not last:
            samples.append({"error": "no_json", "stdout": proc.stdout[-500:]})
            continue
        samples.append(json.loads(last[-1]))
    return _median_exec_ns(samples)

# Each (prog, runtime) result is written to its own file under
# /tmp/stage1-sweep-out/ as raw JSON. At the end we concatenate them.
# This avoids vng's serial-console stdout race that occasionally
# corrupts JSON boundaries when two writes land in the same VT buffer.
OUTDIR = "/tmp/stage1-sweep-out"
os.makedirs(OUTDIR, exist_ok=True)
manifest = []

# Skip non-xdp benchmarks (tc / cgroup_skb need different stub).
for b in cfg["benchmarks"]:
    name = b["name"]
    base = b["base_name"]
    isize = int(b.get("kernel_input_size", 0))
    io_mode = b.get("io_mode", bench_default.get("io_mode", "staged"))
    er = int(b.get("expected_retval", default_retval))
    tags = b.get("tags", [])

    print(f"[run] {name} (base={base}, input={isize}, io={io_mode}, expected_retval={er}, tags={tags})", file=sys.stderr)

    ig = b.get("input_generator", base)
    nl = run_native_lab(name, base, isize, er, tags, ig)
    nl_path = os.path.join(OUTDIR, f"{name}.native_lab.json")
    with open(nl_path, "w") as f:
        json.dump({"program": name, "runtime": "native_lab", **nl}, f)
    manifest.append(nl_path)

    kj = run_kernel_baseline(name, base, isize, io_mode, er, ig)
    kj_path = os.path.join(OUTDIR, f"{name}.kernel_jit.json")
    with open(kj_path, "w") as f:
        json.dump({"program": name, "runtime": "kernel_jit", **kj}, f)
    manifest.append(kj_path)

# Concatenate every per-entry JSON to stdout as proper JSONL (one
# object per line, separated by '\n'). Read each whole file, strip
# trailing whitespace, write + newline. Robust against any VT
# interleaving since we're now flushing one well-formed unit at a
# time, not a mid-write fragment.
for p in manifest:
    with open(p) as f:
        sys.stdout.write(f.read().strip() + "\n")
sys.stdout.flush()
PYEOF
