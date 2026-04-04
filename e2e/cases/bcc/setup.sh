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
RUNNER_DIR="${REPO_ROOT}/runner"
VENDOR_LIBBPF_SRC="${REPO_ROOT}/vendor/libbpf/src"
VENDOR_LIBBPF_OBJ="${REPO_ROOT}/runner/build/vendor/libbpf/obj/libbpf.a"
VENDOR_BPFTOOL="${REPO_ROOT}/runner/build/vendor/bpftool/bootstrap/bpftool"
VENDOR_INCLUDES="-I${BUILD_OUTPUT} -I${REPO_ROOT}/vendor/libbpf/include -I${REPO_ROOT}/vendor/libbpf/include/uapi -I${REPO_ROOT}/vendor/libbpf/src"
# Binaries we actually need — must match config.yaml tool names
REQUIRED_TOOLS=(tcplife biosnoop runqlat syscount execsnoop opensnoop capable vfsstat tcpconnect bindsnoop fsdist)
REQUIRE_BUNDLED_TOOLS="${BCC_REQUIRE_BUNDLED_TOOLS:-0}"

# ── Helpers ────────────────────────────────────────────────────────────────────

apt_install() {
  if ! command -v apt-get >/dev/null 2>&1; then
    return 0
  fi
  DEBIAN_FRONTEND=noninteractive apt-get install -y -qq "$@" >/dev/null 2>&1
}

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

# ── Check if rebuild is needed ─────────────────────────────────────────────────
all_present=true
for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if [[ ! -x "${BUILD_OUTPUT}/${tool_name}" ]]; then
    all_present=false
    break
  fi
done

if "${all_present}"; then
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
    if [[ "${REQUIRE_BUNDLED_TOOLS}" == "1" ]]; then
      echo "ERROR: missing required workload tools for bundled BCC benchmark: ${missing_workload_tools[*]}" >&2
      exit 1
    fi
    apt_install stress-ng fio curl coreutils util-linux
  fi
  echo "BCC_TOOLS_DIR=${BUILD_OUTPUT}"
  exit 0
fi

if [[ "${REQUIRE_BUNDLED_TOOLS}" == "1" ]]; then
  echo "ERROR: bundled BCC libbpf-tools are missing; expected prebuilt artifacts under ${BUILD_OUTPUT}" >&2
  exit 1
fi

# ── Build ──────────────────────────────────────────────────────────────────────
# Install missing build tools only when a rebuild is actually required.
missing_build_tools=()
for tool in make clang llvm-strip pkg-config; do
  if ! need_tool "${tool}"; then
    missing_build_tools+=("${tool}")
  fi
done
if [[ "${#missing_build_tools[@]}" -gt 0 ]]; then
  apt_install clang llvm make pkg-config libelf-dev zlib1g-dev
fi

missing_workload_tools=()
for tool in stress-ng fio curl dd setpriv; do
  if ! need_tool "${tool}"; then
    missing_workload_tools+=("${tool}")
  fi
done
if [[ "${#missing_workload_tools[@]}" -gt 0 ]]; then
  apt_install stress-ng fio curl coreutils util-linux
fi

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
if ! make -C "${RUNNER_DIR}" \
      -j"${NPROC}" \
      JOBS="${NPROC}" \
      vendor_libbpf vendor_bpftool \
      >"${build_log}" 2>&1; then
  echo "ERROR: vendor libbpf/bpftool build failed; last 60 lines of build log:" >&2
  tail -n 60 "${build_log}" >&2
  exit 1
fi
if [[ ! -f "${VENDOR_LIBBPF_OBJ}" ]]; then
  echo "ERROR: expected vendor libbpf archive not found at ${VENDOR_LIBBPF_OBJ}" >&2
  exit 1
fi
if [[ ! -x "${VENDOR_BPFTOOL}" ]]; then
  echo "ERROR: expected vendor bpftool not found at ${VENDOR_BPFTOOL}" >&2
  exit 1
fi
if ! make -C "${LIBBPF_TOOLS_SRC}" \
      -j"${NPROC}" \
      CLANG="${CLANG:-clang}" \
      LLVM_STRIP="${LLVM_STRIP:-llvm-strip}" \
      USE_BLAZESYM=0 \
      BPFTOOL="${VENDOR_BPFTOOL}" \
      LIBBPF_SRC="${VENDOR_LIBBPF_SRC}" \
      LIBBPF_OBJ="${VENDOR_LIBBPF_OBJ}" \
      INCLUDES="${VENDOR_INCLUDES}" \
      "${REQUIRED_TOOLS[@]}" \
      >"${build_log}" 2>&1; then
  echo "ERROR: libbpf-tools build failed; last 60 lines of build log:" >&2
  tail -n 60 "${build_log}" >&2
  exit 1
fi

# Verify the expected binaries are present
for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if [[ ! -x "${BUILD_OUTPUT}/${tool_name}" ]]; then
    echo "ERROR: expected binary '${tool_name}' not found after build" >&2
    exit 1
  fi
done

for tool_name in "${REQUIRED_TOOLS[@]}"; do
  if ! binary_matches_host_arch "${BUILD_OUTPUT}/${tool_name}"; then
    echo "ERROR: built BCC tool has the wrong architecture: ${BUILD_OUTPUT}/${tool_name}" >&2
    exit 1
  fi
done

echo "BCC_TOOLS_DIR=${BUILD_OUTPUT}"
