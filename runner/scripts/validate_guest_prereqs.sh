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

die() {
    printf '[validate-guest-prereqs][ERROR] %s\n' "$*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "required guest command is missing: $1"
}

python_import_for_package() {
    case "$1" in
        PyYAML) printf '%s\n' yaml ;;
        pyelftools) printf '%s\n' elftools ;;
        *) die "unsupported python package contract: $1" ;;
    esac
}

main() {
    local command_name tool_name package_name imports=() import_name
    cd "$WORKSPACE"
    require_cmd bash
    require_cmd "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    require_cmd "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
    IFS=',' read -r -a _run_remote_required <<<"${RUN_REMOTE_COMMANDS_CSV:-}"
    for command_name in "${_run_remote_required[@]}"; do
        [[ -n "$command_name" ]] || continue
        require_cmd "$command_name"
    done
    IFS=',' read -r -a _run_workload_tools <<<"${RUN_WORKLOAD_TOOLS_CSV:-}"
    for tool_name in "${_run_workload_tools[@]}"; do
        [[ -n "$tool_name" ]] || continue
        require_cmd "$tool_name"
    done
    IFS=',' read -r -a _run_python_packages <<<"${RUN_REMOTE_PYTHON_MODULES_CSV:-}"
    for package_name in "${_run_python_packages[@]}"; do
        [[ -n "$package_name" ]] || continue
        import_name="$(python_import_for_package "$package_name")"
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
