#!/bin/bash
set -eu
cd /workspaces/repository
exec 9>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 9
exec 8>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 8
D=/workspaces/kprog-raw/perf/x86-otel-perf-20261127/shared-call-anchor-20261127
mkdir -p "$D"
python3 - <<'PY'
from pathlib import Path
raw=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127/20261127T200824Z');cache=raw/'linkcache/native_kernel_link_cache';out=raw.parent/'shared-call-anchor-20261127';(out/'entry.link-plan.json').write_bytes(next(cache.glob('dd3ff44ce0c19652*.link-plan.json')).read_bytes());(out/'kallsyms.txt').write_bytes((raw/'kallsyms.txt').read_bytes());p=max(raw.glob('kallsyms-bpf-*.txt'),key=lambda p:float(p.stem[len('kallsyms-bpf-'):]));(out/p.name).write_bytes(p.read_bytes())
PY
taskset -c 16,18 docker run --rm --cpuset-cpus 16,18 -v /workspaces:/workspaces --entrypoint prlimit bpf-benchmark/kprog:current --as=51539607552 -- sh -c '
set -eu
R=/workspaces/repository
D=/workspaces/kprog-raw/perf/x86-otel-perf-20261127/shared-call-anchor-20261127
L=$R/kprog/x86/native_lab/native_link/target/release/native-link
$L --input $R/vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o --symbol native_tracer_entry --mode proof --output $D/entry.proof.o
$L --input $D/entry.proof.o --symbol native_tracer_entry --mode kernel --link-plan $D/entry.link-plan.json --output $D/entry.blob.bin --output-relocs $D/entry.relocs.bin --output-map-patches $D/entry.map-patches.tsv --output-abi $D/entry.abi.tsv
'
# Actual fixed blob, populated native program array and counter initialized0.
ulimit -v 50331648
ulimit -c 0
taskset -c 16 python3 kprog/results/x86-otel-perf-20261127/entry_blob_trace.py "$D/host" "$D"
