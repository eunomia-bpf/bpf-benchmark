#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
CORPUS_BINARY="${REPO_ROOT}/corpus/build/tracee/bin/tracee"
EXPLICIT_TRACEE_BINARY="${TRACEE_BINARY:-}"

binary_matches_host_arch() {
  local candidate="$1"
  case "$(uname -m)" in
    aarch64|arm64)
      file "${candidate}" | grep -F "ARM aarch64" >/dev/null
      ;;
    x86_64|amd64)
      file "${candidate}" | grep -F "x86-64" >/dev/null
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

missing_pkgs=()
for tool in stress-ng fio curl; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    missing_pkgs+=("${tool}")
  fi
done
if ! command -v wrk >/dev/null 2>&1; then
  missing_pkgs+=("wrk")
fi
if ! command -v hackbench >/dev/null 2>&1; then
  missing_pkgs+=("rt-tests")
fi
if [[ "${#missing_pkgs[@]}" -gt 0 ]]; then
  echo "missing required Tracee workload tools: ${missing_pkgs[*]}" >&2
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
