#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="${1:?usage: execute_workspace.sh <workspace> <manifest_path> [archive_path]}"
MANIFEST_PATH="${2:?usage: execute_workspace.sh <workspace> <manifest_path> [archive_path]}"
ARCHIVE_PATH="${3:-}"

[[ -d "$WORKSPACE" ]] || {
    printf '[execute-workspace][ERROR] workspace is missing: %s\n' "$WORKSPACE" >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[execute-workspace][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

resolve_python_launcher() {
    local candidate
    for candidate in python3 python; do
        if command -v "$candidate" >/dev/null 2>&1; then
            printf '%s\n' "$candidate"
            return 0
        fi
    done
    printf '[execute-workspace][ERROR] no Python launcher is available\n' >&2
    exit 1
}

PYTHON_BIN="$(resolve_python_launcher)"
export PYTHONPATH="$WORKSPACE${PYTHONPATH:+:$PYTHONPATH}"
exec "$PYTHON_BIN" -m runner.libs.execute_workspace "$WORKSPACE" "$MANIFEST_PATH" "$ARCHIVE_PATH"
