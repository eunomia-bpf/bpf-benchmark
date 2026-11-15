#!/usr/bin/env bash
# Use actual-pointer map dispatch while its remaining selector is consolidated.
set -euo pipefail
exec "${KPROG_FRAME_LINKER:?set by the frame test Make target}" \
    --runtime-map-lookups "$@"
