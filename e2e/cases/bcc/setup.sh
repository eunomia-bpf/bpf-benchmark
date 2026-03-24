#!/usr/bin/env bash
# BCC libbpf-tools setup script.
# Compiles the libbpf-tools binaries from runner/repos/bcc/libbpf-tools/ and
# prints the output directory as BCC_TOOLS_DIR=<path>.
#
# The script is idempotent: if the binaries already exist in the output
# directory, no rebuild is performed.
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
LIBBPF_TOOLS_SRC="${REPO_ROOT}/runner/repos/bcc/libbpf-tools"
BUILD_OUTPUT="${LIBBPF_TOOLS_SRC}/.output"
# Binaries we actually need — must match config.yaml tool names
REQUIRED_TOOLS=(tcplife biosnoop runqlat execsnoop opensnoop capable vfsstat tcpconnect)

# ── Helpers ────────────────────────────────────────────────────────────────────

apt_install() {
  if ! command -v apt-get >/dev/null 2>&1; then
    return 0
  fi
  DEBIAN_FRONTEND=noninteractive apt-get install -y -qq "$@" >/dev/null 2>&1 || true
}

need_tool() {
  local tool="$1"
  command -v "${tool}" >/dev/null 2>&1
}

# ── Validate source tree ───────────────────────────────────────────────────────
if [[ ! -d "${LIBBPF_TOOLS_SRC}" ]]; then
  echo "ERROR: libbpf-tools source not found at ${LIBBPF_TOOLS_SRC}" >&2
  echo "Run: git submodule update --init --recursive" >&2
  exit 1
fi

if [[ ! -f "${LIBBPF_TOOLS_SRC}/Makefile" ]]; then
  echo "ERROR: no Makefile in ${LIBBPF_TOOLS_SRC}" >&2
  exit 1
fi

# ── Install missing build tools ────────────────────────────────────────────────
missing_build_tools=()
for tool in make clang llvm-strip pkg-config; do
  if ! need_tool "${tool}"; then
    missing_build_tools+=("${tool}")
  fi
done
if [[ "${#missing_build_tools[@]}" -gt 0 ]]; then
  apt_install clang llvm make pkg-config libelf-dev zlib1g-dev || true
fi

# ── Install missing runtime workload tools ─────────────────────────────────────
missing_workload_tools=()
for tool in stress-ng fio curl dd; do
  if ! need_tool "${tool}"; then
    missing_workload_tools+=("${tool}")
  fi
done
if [[ "${#missing_workload_tools[@]}" -gt 0 ]]; then
  apt_install stress-ng fio curl coreutils || true
fi

# ── Check if rebuild is needed ─────────────────────────────────────────────────
all_present=true
for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if [[ ! -x "${LIBBPF_TOOLS_SRC}/${tool_name}" ]] && [[ ! -x "${BUILD_OUTPUT}/${tool_name}" ]]; then
    all_present=false
    break
  fi
done

if "${all_present}"; then
  # Prefer binaries in BUILD_OUTPUT directory (standard libbpf-tools output location)
  # Fall back to top-level LIBBPF_TOOLS_SRC
  if [[ -x "${BUILD_OUTPUT}/tcplife" ]]; then
    echo "BCC_TOOLS_DIR=${BUILD_OUTPUT}"
  else
    echo "BCC_TOOLS_DIR=${LIBBPF_TOOLS_SRC}"
  fi
  exit 0
fi

# ── Build ──────────────────────────────────────────────────────────────────────
if ! need_tool clang; then
  echo "ERROR: clang is required to build libbpf-tools but was not found" >&2
  exit 1
fi
if ! need_tool make; then
  echo "ERROR: make is required to build libbpf-tools but was not found" >&2
  exit 1
fi

NPROC=1
if command -v nproc >/dev/null 2>&1; then
  NPROC="$(nproc)"
fi

build_log="/tmp/bcc-libbpf-tools-build.log"
echo "Building libbpf-tools in ${LIBBPF_TOOLS_SRC} (this may take a few minutes)..." >&2
if ! make -C "${LIBBPF_TOOLS_SRC}" \
      -j"${NPROC}" \
      CLANG="${CLANG:-clang}" \
      LLVM_STRIP="${LLVM_STRIP:-llvm-strip}" \
      "${REQUIRED_TOOLS[@]}" \
      >"${build_log}" 2>&1; then
  echo "ERROR: libbpf-tools build failed; last 60 lines of build log:" >&2
  tail -n 60 "${build_log}" >&2
  exit 1
fi

# Verify the expected binaries are present
for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if [[ ! -x "${LIBBPF_TOOLS_SRC}/${tool_name}" ]] && [[ ! -x "${BUILD_OUTPUT}/${tool_name}" ]]; then
    echo "ERROR: expected binary '${tool_name}' not found after build" >&2
    exit 1
  fi
done

if [[ -x "${BUILD_OUTPUT}/tcplife" ]]; then
  echo "BCC_TOOLS_DIR=${BUILD_OUTPUT}"
else
  echo "BCC_TOOLS_DIR=${LIBBPF_TOOLS_SRC}"
fi
