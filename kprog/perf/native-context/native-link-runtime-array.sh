#!/usr/bin/env bash
set -euo pipefail
payload_dir=$(cd -- "$(dirname -- "$0")" && pwd)
case "$(basename -- "$0")" in
    native-link-array-on) array=(--runtime-array-layout "$payload_dir/runtime-array-layout.json") ;;
    native-link-array-off) array=() ;;
    *) echo 'install as native-link-array-on or native-link-array-off' >&2; exit 1 ;;
esac
exec "$payload_dir/native-link.real" --runtime-map-lookups --runtime-known-map-lookups \
    --local-memory-routines "${array[@]}" "$@"
