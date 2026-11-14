#!/usr/bin/env bash
# Exercise existing optional runtime lookup and JIT frame relocations.
set -euo pipefail
exec "${KPROG_FRAME_LINKER:?set by the frame test Make target}" \
    --runtime-map-lookups --tail-count-relocs "$@"
