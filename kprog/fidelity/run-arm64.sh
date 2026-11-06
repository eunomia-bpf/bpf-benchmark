#!/bin/sh
set -eu
if [ "$(uname -m)" != aarch64 ]; then
    echo 'run-arm64.sh requires a real AArch64 host; emulation is not hardware evidence' >&2
    exit 1
fi
cd "$(dirname "$0")"
exec make ARCH=arm64 run-handoff CASES="${CASES:-1024}" OUT="${OUT:-../results/kprog_fidelity_20261106/differential/arm64-hardware}"
