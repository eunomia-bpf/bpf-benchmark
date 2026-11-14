#!/usr/bin/env bash
# Add the existing shared ARRAY opt-in to the pinned read/hash/LPM wrapper.
set -euo pipefail
here=$(cd -- "$(dirname -- "$0")" && pwd)
array=()
[[ ${0##*/} == native-link-off ]] || array=(--runtime-array-layout "$here/runtime-array-layout.json" --runtime-array-shared)
exec "$here/native-link-base" "${array[@]}" "$@"
