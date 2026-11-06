#!/bin/sh
set -eu
if [ "$(uname -m)" != aarch64 ]; then
    echo 'run-arm64-control.sh requires an AArch64 hardware host' >&2
    exit 1
fi
cd "$(dirname "$0")"
exec make arm64-control-handoff CASES="${CASES:-1024}" ARM64_CONTROL_OUT="${OUT:-../results/kprog_fidelity_20261106/differential/arm64-control-hardware}"
