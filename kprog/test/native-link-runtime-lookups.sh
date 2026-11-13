#!/usr/bin/env bash
# Selected payload: keep kernel lookup dispatch opt-in without changing the image.
set -euo pipefail
payload_dir=$(cd -- "$(dirname -- "$0")" && pwd)
exec "$payload_dir/native-link.real" --runtime-map-lookups "$@"
