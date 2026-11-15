#!/bin/bash
# Host side of the bcc/set tool-output comparison: one guest, both arms, the
# eight tools' full stdout and stderr kept per arm.
#
# The timed runs cannot answer this: the corpus driver keeps only a 40-line,
# 8000-char tail of each tool and never writes it to the run directory
# (BccSetRunner.process_output, runner/libs/app_runners/bcc_set.py:117-121 and
# :211-228; corpus/driver.py reads only artifacts["result_details"], which no
# runner sets). So this runs the tools against the same frozen workload with
# the same environment and keeps everything.
#
# Usage: bcc-tool-output.sh <out-dir> [seconds] [cpus] [manifest-dir]
set -eu
OUT=${1:?output directory under /workspaces}
SECONDS_N=${2:-20}
CPUS_N=${3:-0-7}
MANIFEST=${4:-/opt/bpf-benchmark/native-bpf/x86_64/bcc/manifest.json}
STATE=${STATE:-/var/tmp/kprog-tmp/C/state/bcc-tools}
ROOT=/workspaces/repository
KDIR=/workspaces/.agent-state/kprog-ck/build-x86

install -d "$OUT" "$STATE/var-tmp"
cp -f /var/tmp/runtime.image.tar "$STATE/var-tmp/runtime.image.tar"
cp -f "$ROOT/kinsn/module/x86/build/bpf_x86_native_lab.ko" "$STATE/var-tmp/bpf_x86_native_lab.ko"

taskset -c "$CPUS_N" vng --run "$KDIR/arch/x86/boot/bzImage" \
  --cwd "$ROOT" --rwdir "$ROOT" --rwdir "$OUT" \
  --rwdir /var/tmp="$STATE/var-tmp" \
  --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
  --disable-monitor --cpus "${VM_CPUS:-8}" --memory "${VM_MEM:-32G}" \
  --append 'loglevel=4 panic=30 oops=panic' \
  --exec "bash $ROOT/kprog/perf/one-image/scripts/bcc-tool-output-guest.sh $OUT $SECONDS_N $MANIFEST"

rm -f "$STATE/var-tmp/bpf-benchmark-docker.img"