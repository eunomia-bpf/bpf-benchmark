#!/usr/bin/env bash
set -euo pipefail
here=$(cd -- "$(dirname -- "$0")" && pwd)
linker=${KPROG_PROBE_LINKER:-$here/native-link.real}
layout=${KPROG_PROBE_LAYOUT:-$here/runtime-probe-read-layout.json}
base=(); read=(--runtime-probe-read-layout "$layout"); abi=()
case ${0##*/} in
  native-link-on|native-link-off)
    base=(--runtime-map-lookups --runtime-known-map-lookups --local-memory-routines)
    [[ ${0##*/} != native-link-off ]] || read=()
    ;;
esac
present=0
for arg in "$@"; do
    case $arg in --abi-load-sites|--abi-load-sites=*) present=1;; esac
done
(( present )) || abi=(--abi-load-sites true)
exec "$linker" "${base[@]}" "${read[@]}" "${abi[@]}" "$@"
