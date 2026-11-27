#!/bin/bash
set -eu
cd /workspaces/repository
exec 9>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 9
exec 8>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 8
D=/workspaces/kprog-raw/perf/x86-otel-perf-20261127/link-integration-20261127
mkdir -p "$D"
python3 - <<'PY'
import hashlib,tarfile,subprocess
from pathlib import Path
root=Path('/workspaces/repository');raw=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127/link-integration-20261127');part=root/'kprog/results/x86-otel-perf-20261127/profile-20261127T192332Z/evidence.tar.zst.part-aa'
p=subprocess.Popen(['zstd','-dc',str(part)],stdout=subprocess.PIPE)
with tarfile.open(fileobj=p.stdout,mode='r|') as t:
 for m in t:
  if 'fd110add9b43bd6b' in m.name and m.name.endswith('.link-plan.json'):
   (raw/'captured.link-plan.json').write_bytes(t.extractfile(m).read())
for block in iter(lambda:p.stdout.read(1048576),b''):pass
assert p.wait()==0 and (raw/'captured.link-plan.json').exists()
PY
# Execute the actual CLI with its existing runtime compiler at its real path.
taskset -c 16,18 docker run --rm --cpuset-cpus 16,18 -v /workspaces:/workspaces --entrypoint prlimit bpf-benchmark/kprog:current --as=51539607552 -- sh -c '
set -eu
R=/workspaces/repository
D=/workspaces/kprog-raw/perf/x86-otel-perf-20261127/link-integration-20261127
L=$R/kprog/x86/native_lab/native_link/target/release/native-link
$L --input $R/vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o --symbol perf_unwind_native --mode proof --output $D/input.proof.o
$L --input $D/input.proof.o --symbol perf_unwind_native --mode kernel --link-plan $D/captured.link-plan.json --output $D/native.blob.bin --output-relocs $D/native.relocs.bin --output-map-patches $D/native.map-patches.tsv --output-abi $D/native.abi.tsv
'
llvm-nm-18 --undefined-only "$D/native.blob.frozen.proof.o" > "$D/optimized-undefined.txt"
wc -c "$D/native.blob.bin"
