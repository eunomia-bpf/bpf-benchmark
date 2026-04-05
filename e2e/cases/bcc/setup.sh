#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
EXPLICIT_BUILD_OUTPUT="${BCC_TOOLS_DIR:-}"
BUNDLED_BUILD_OUTPUT="${REPO_ROOT}/corpus/build/bcc/libbpf-tools/.output"
REQUIRED_TOOLS=(tcplife biosnoop runqlat syscount execsnoop opensnoop capable vfsstat tcpconnect bindsnoop fsdist)

need_tool() {
  local tool="$1"
  command -v "${tool}" >/dev/null 2>&1
}

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

BUILD_OUTPUT=""
for candidate in "${EXPLICIT_BUILD_OUTPUT}" "${BUNDLED_BUILD_OUTPUT}"; do
  [[ -n "${candidate}" ]] || continue
  [[ -d "${candidate}" ]] || continue
  BUILD_OUTPUT="${candidate}"
  break
done
if [[ -z "${BUILD_OUTPUT}" ]]; then
  echo "ERROR: missing bundled BCC libbpf-tools output; checked ${EXPLICIT_BUILD_OUTPUT:-<unset>} and ${BUNDLED_BUILD_OUTPUT}" >&2
  exit 1
fi

for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if [[ ! -x "${BUILD_OUTPUT}/${tool_name}" ]]; then
    echo "ERROR: missing repo-managed BCC libbpf-tools under ${BUILD_OUTPUT}; prepare them before running the suite" >&2
    exit 1
  fi
done

for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if ! binary_matches_host_arch "${BUILD_OUTPUT}/${tool_name}"; then
    echo "ERROR: bundled BCC tool has the wrong architecture: ${BUILD_OUTPUT}/${tool_name}" >&2
    exit 1
  fi
done

missing_workload_tools=()
for tool in stress-ng fio curl dd setpriv; do
  if ! need_tool "${tool}"; then
    missing_workload_tools+=("${tool}")
  fi
done
if [[ "${#missing_workload_tools[@]}" -gt 0 ]]; then
  echo "ERROR: missing required workload tools for BCC benchmark: ${missing_workload_tools[*]}" >&2
  exit 1
fi

echo "BCC_TOOLS_DIR=${BUILD_OUTPUT}"
