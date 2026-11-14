#!/usr/bin/env bash
set -euo pipefail
here=$(cd -- "$(dirname -- "$0")" && pwd)
linker=${KPROG_HASH_LINKER:-$here/native-link.real}
layout=${KPROG_HASH_LAYOUT:-$here/runtime-hash-layout.json}
probe=${KPROG_PROBE_LAYOUT:-$here/runtime-probe-read-layout.json}
hash=(--runtime-hash-layout "$layout"); abi=()
[[ ${0##*/} != native-link-off ]] || hash=()
present=0
for arg in "$@"; do
    case $arg in --abi-load-sites|--abi-load-sites=*) present=1;; esac
done
(( present )) || abi=(--abi-load-sites true)
exec "$linker" --runtime-map-lookups --runtime-known-map-lookups --local-memory-routines \
    --runtime-probe-read-layout "$probe" "${hash[@]}" "${abi[@]}" "$@"
