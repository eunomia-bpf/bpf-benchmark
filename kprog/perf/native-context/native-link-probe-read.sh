#!/usr/bin/env bash
set -euo pipefail
exec "${KPROG_PROBE_LINKER:?}" --runtime-probe-read-layout "${KPROG_PROBE_LAYOUT:?}" "$@"
