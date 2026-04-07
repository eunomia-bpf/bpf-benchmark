#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
CORPUS_BINARY="${REPO_ROOT}/corpus/build/tracee/bin/tracee"
EXPLICIT_TRACEE_BINARY="${TRACEE_BINARY:-}"

append_required_tool() {
  local tool="$1"
  local existing
  for existing in "${required_tools[@]:-}"; do
    [[ "${existing}" == "${tool}" ]] && return 0
  done
  required_tools+=("${tool}")
}

binary_matches_host_arch() {
  local candidate="$1"
  local file_output
  file_output="$(file "${candidate}")"
  case "${file_output}" in
    *"shell script"*|*"Python script"*|*"Perl script"*|*"text executable"*)
      return 0
      ;;
  esac
  case "$(uname -m)" in
    aarch64|arm64)
      grep -F "ARM aarch64" <<<"${file_output}" >/dev/null
      ;;
    x86_64|amd64)
      grep -F "x86-64" <<<"${file_output}" >/dev/null
      ;;
    *)
      return 0
      ;;
  esac
}

pick_binary() {
  local candidate
  for candidate in "$@"; do
    [[ -n "${candidate}" ]] || continue
    [[ -x "${candidate}" ]] || continue
    if binary_matches_host_arch "${candidate}"; then
      printf '%s\n' "${candidate}"
      return 0
    fi
  done
  return 1
}

required_tools=("curl")
if [[ -n "${RUN_WORKLOAD_TOOLS_CSV:-}" ]]; then
  IFS=',' read -r -a _requested_tools <<<"${RUN_WORKLOAD_TOOLS_CSV}"
  for tool in "${_requested_tools[@]}"; do
    [[ -n "${tool}" ]] || continue
    case "${tool}" in
      curl|fio|hackbench|stress-ng|wrk)
        append_required_tool "${tool}"
        ;;
    esac
  done
else
  for tool in stress-ng fio wrk hackbench; do
    append_required_tool "${tool}"
  done
fi

missing_tools=()
for tool in "${required_tools[@]}"; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    missing_tools+=("${tool}")
  fi
done
if [[ "${#missing_tools[@]}" -gt 0 ]]; then
  echo "missing required Tracee workload tools: ${missing_tools[*]}" >&2
  exit 1
fi

tracee_bin=""
if tracee_bin="$(pick_binary \
  "${EXPLICIT_TRACEE_BINARY}" \
  "${CORPUS_BINARY}")"; then
  :
else
  echo "missing repo-managed Tracee binary; checked ${EXPLICIT_TRACEE_BINARY:-<unset>} and ${CORPUS_BINARY}" >&2
  exit 1
fi

echo "TRACEE_BINARY=${tracee_bin}"
if ! "${tracee_bin}" --version >/dev/null 2>&1; then
  "${tracee_bin}" version >/dev/null 2>&1
fi
