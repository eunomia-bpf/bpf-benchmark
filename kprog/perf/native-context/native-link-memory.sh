#!/usr/bin/env bash
# Two selected configurations of the same binary; default image stays in place.
set -euo pipefail
payload_dir=$(cd -- "$(dirname -- "$0")" && pwd)
case "$(basename -- "$0")" in
    native-link-on) memory=(--local-memory-routines) ;;
    native-link-off) memory=() ;;
    *) echo 'install as native-link-on or native-link-off' >&2; exit 1 ;;
esac
exec "$payload_dir/native-link.real" --runtime-map-lookups "${memory[@]}" "$@"
