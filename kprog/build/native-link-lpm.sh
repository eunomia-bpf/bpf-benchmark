#!/usr/bin/env bash
set -euo pipefail
here=$(cd -- "$(dirname -- "$0")" && pwd)
lpm=(--runtime-lpm-layout "$here/runtime-lpm-layout.json"); abi=()
[[ ${0##*/} != native-link-off ]] || lpm=()
present=0
for arg in "$@"; do
    case $arg in --abi-load-sites|--abi-load-sites=*) present=1;; esac
done
(( present )) || abi=(--abi-load-sites true)
exec "$here/native-link.real" --runtime-map-lookups --runtime-known-map-lookups --local-memory-routines \
    --runtime-probe-read-layout "$here/runtime-probe-read-layout.json" \
    --runtime-hash-layout "$here/runtime-hash-layout.json" "${lpm[@]}" "${abi[@]}" "$@"
