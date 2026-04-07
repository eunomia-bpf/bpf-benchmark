#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="${1:?usage: install_guest_prereqs.sh <workspace> <manifest_path>}"
MANIFEST_PATH="${2:?usage: install_guest_prereqs.sh <workspace> <manifest_path>}"

[[ -d "$WORKSPACE" ]] || {
    printf '[install-guest-prereqs][ERROR] workspace is missing: %s\n' "$WORKSPACE" >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[install-guest-prereqs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$MANIFEST_PATH"
source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/prereq_contract.sh"

REMOTE_WORKLOAD_TOOL_BIN="${RUN_REMOTE_WORKLOAD_TOOL_BIN:-$WORKSPACE/.cache/workload-tools/bin}"
if [[ -d "$REMOTE_WORKLOAD_TOOL_BIN" ]]; then
    export PATH="$REMOTE_WORKLOAD_TOOL_BIN:$PATH"
fi

die() {
    printf '[install-guest-prereqs][ERROR] %s\n' "$*" >&2
    exit 1
}

have_cmd() {
    command -v "$1" >/dev/null 2>&1
}

workload_tool_is_bundled() {
    local tool="$1"
    case ",${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}," in
        *,"${tool}",*) return 0 ;;
    esac
    return 1
}

python_module_available() {
    local python_bin="$1"
    local import_name="$2"
    "$python_bin" -c "import ${import_name}" >/dev/null 2>&1
}

require_sudo() {
    if [[ "${EUID}" -eq 0 ]]; then
        return 0
    fi
    have_cmd sudo || die "guest package installation requires sudo or root"
}

install_python_modules() {
    local package_csv="$1"
    local package_name
    [[ -n "$package_csv" ]] || return 0
    IFS=',' read -r -a _run_python_packages <<<"$package_csv"
    [[ "${#_run_python_packages[@]}" -gt 0 ]] || return 0
    if [[ "${EUID}" -eq 0 ]]; then
        "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" -m pip install --quiet "${_run_python_packages[@]}"
    else
        sudo "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" -m pip install --quiet "${_run_python_packages[@]}"
    fi
}

ensure_python_pip() {
    local python_bin="${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    "$python_bin" -m pip --version >/dev/null 2>&1 && return 0
    if [[ "${EUID}" -eq 0 ]]; then
        "$python_bin" -m ensurepip --upgrade >/dev/null 2>&1 || die "python pip is unavailable for ${python_bin}"
    else
        sudo "$python_bin" -m ensurepip --upgrade >/dev/null 2>&1 || die "python pip is unavailable for ${python_bin}"
    fi
    "$python_bin" -m pip --version >/dev/null 2>&1 || die "python pip is unavailable for ${python_bin}"
}

main() {
    local required_commands=() missing_commands=() packages=() missing_python_packages=() command_name package_name pkg_manager="" import_name=""
    cd "$WORKSPACE"
    prereq_collect_required_commands required_commands
    for command_name in "${required_commands[@]}"; do
        if have_cmd "$command_name"; then
            continue
        fi
        if workload_tool_is_bundled "$command_name"; then
            die "required bundled workload tool is missing from the guest tool bin: ${command_name}"
        fi
        missing_commands+=("$command_name")
    done

    if [[ -n "${RUN_REMOTE_PYTHON_MODULES_CSV:-}" ]]; then
        if have_cmd "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"; then
            IFS=',' read -r -a _run_python_packages <<<"${RUN_REMOTE_PYTHON_MODULES_CSV}"
            for package_name in "${_run_python_packages[@]}"; do
                [[ -n "$package_name" ]] || continue
                import_name="$(prereq_python_import_for_package "$package_name")"
                python_module_available "${RUN_REMOTE_PYTHON_BIN}" "$import_name" || prereq_append_unique missing_python_packages "$package_name"
            done
        else
            prereq_append_unique missing_commands "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
            IFS=',' read -r -a _run_python_packages <<<"${RUN_REMOTE_PYTHON_MODULES_CSV}"
            for package_name in "${_run_python_packages[@]}"; do
                [[ -n "$package_name" ]] || continue
                prereq_append_unique missing_python_packages "$package_name"
            done
        fi
    fi
    if [[ "${#missing_commands[@]}" -eq 0 && "${#missing_python_packages[@]}" -eq 0 ]]; then
        return 0
    fi

    require_sudo
    pkg_manager="${RUN_GUEST_PACKAGE_MANAGER:?RUN_GUEST_PACKAGE_MANAGER is required for guest provisioning}"
    case "$pkg_manager" in
        apt|dnf) ;;
        *) die "unsupported guest package manager contract: ${pkg_manager}" ;;
    esac

    for command_name in "${missing_commands[@]}"; do
        if [[ "$pkg_manager" == "apt" ]]; then
            while IFS= read -r package_name; do
                [[ -n "$package_name" ]] || continue
                prereq_append_unique packages "$package_name"
            done < <(prereq_map_tool_packages apt "$command_name")
        else
            while IFS= read -r package_name; do
                [[ -n "$package_name" ]] || continue
                prereq_append_unique packages "$package_name"
            done < <(prereq_map_tool_packages dnf "$command_name")
        fi
    done

    if [[ "${#packages[@]}" -gt 0 ]]; then
        if [[ "$pkg_manager" == "apt" ]]; then
            if [[ "${EUID}" -eq 0 ]]; then
                apt-get update
                DEBIAN_FRONTEND=noninteractive apt-get install -y "${packages[@]}"
            else
                sudo apt-get update
                sudo env DEBIAN_FRONTEND=noninteractive apt-get install -y "${packages[@]}"
            fi
        else
            if [[ "${EUID}" -eq 0 ]]; then
                dnf -y install "${packages[@]}"
            else
                sudo dnf -y install "${packages[@]}"
            fi
        fi
    fi
    if [[ "${#missing_python_packages[@]}" -gt 0 ]]; then
        ensure_python_pip
        install_python_modules "$(IFS=,; printf '%s' "${missing_python_packages[*]}")"
    fi
}

main "$@"
