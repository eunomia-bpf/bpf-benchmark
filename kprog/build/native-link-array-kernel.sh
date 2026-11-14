#!/usr/bin/env bash
# Called through the existing frame wrapper, which selects runtime-map lookups.
set -euo pipefail
abi=()
present=0
for arg in "$@"; do
    case $arg in --abi-load-sites|--abi-load-sites=*) present=1;; esac
done
(( present )) || abi=(--abi-load-sites true)
exec "${KPROG_ARRAY_LINKER:?}" --runtime-array-layout "${KPROG_ARRAY_LAYOUT:?}" \
    --runtime-array-shared "${abi[@]}" "$@"
