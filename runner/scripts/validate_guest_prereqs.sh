#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="${1:?usage: validate_guest_prereqs.sh <workspace> <manifest_path>}"
MANIFEST_PATH="${2:?usage: validate_guest_prereqs.sh <workspace> <manifest_path>}"

[[ -d "$WORKSPACE" ]] || {
    printf '[validate-guest-prereqs][ERROR] workspace is missing: %s\n' "$WORKSPACE" >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[validate-guest-prereqs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$MANIFEST_PATH"
source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/prereq_contract.sh"

die() {
    printf '[validate-guest-prereqs][ERROR] %s\n' "$*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "required guest command is missing: $1"
}

main() {
    local command_name package_name imports=() import_name required_commands=()
    cd "$WORKSPACE"
    require_cmd bash
    prereq_collect_required_commands required_commands
    for command_name in "${required_commands[@]}"; do
        [[ -n "$command_name" ]] || continue
        require_cmd "$command_name"
    done
    IFS=',' read -r -a _run_python_packages <<<"${RUN_REMOTE_PYTHON_MODULES_CSV:-}"
    for package_name in "${_run_python_packages[@]}"; do
        [[ -n "$package_name" ]] || continue
        import_name="$(prereq_python_import_for_package "$package_name")"
        imports+=("$import_name")
    done
    if (( ${#imports[@]} )); then
        "${RUN_REMOTE_PYTHON_BIN}" - "${imports[@]}" <<'PY'
import importlib
import sys

for module_name in sys.argv[1:]:
    importlib.import_module(module_name)
PY
    fi
}

main "$@"
