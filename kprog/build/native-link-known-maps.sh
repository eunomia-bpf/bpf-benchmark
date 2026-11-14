#!/usr/bin/env bash
# Explicit candidate configurations; the image and active peer binaries stay put.
set -euo pipefail
payload_dir=$(cd -- "$(dirname -- "$0")" && pwd)
case "$(basename -- "$0")" in
    native-link-known-on) known=(--runtime-known-map-lookups) ;;
    native-link-known-off) known=() ;;
    *) echo 'install as native-link-known-on or native-link-known-off' >&2; exit 1 ;;
esac
exec "$payload_dir/native-link.real" --runtime-map-lookups --local-memory-routines "${known[@]}" "$@"
