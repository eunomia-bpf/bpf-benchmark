#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/../../.." && pwd)
BUNDLED_TETRAGON_BINARY="${REPO_ROOT}/corpus/build/tetragon/bin/tetragon"
BUNDLED_BPF_DIR="${REPO_ROOT}/corpus/build/tetragon"
EXPLICIT_TETRAGON_BINARY="${TETRAGON_BINARY:-}"
EXPLICIT_BPF_DIR="${TETRAGON_BPF_LIB_DIR:-}"

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

pick_bpf_lib_dir() {
  local candidate
  for candidate in "${EXPLICIT_BPF_DIR}" "${BUNDLED_BPF_DIR}"; do
    [[ -n "${candidate}" ]] || continue
    [[ -d "${candidate}" ]] || continue
    if find "${candidate}" -maxdepth 1 -type f \( -name '*.o' -o -name '*.bpf.o' \) | grep -q .; then
      printf '%s\n' "${candidate}"
      return 0
    fi
  done
  return 1
}

missing_pkgs=()
for tool in stress-ng fio curl tar; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    missing_pkgs+=("${tool}")
  fi
done
if [[ "${#missing_pkgs[@]}" -gt 0 ]]; then
  echo "missing required Tetragon workload tools: ${missing_pkgs[*]}" >&2
  exit 1
fi

if ! command -v stress-ng >/dev/null 2>&1; then
  echo "stress-ng is required for the tetragon benchmark" >&2
  exit 1
fi

tetragon_bin=""
tetragon_bin="$(pick_binary \
  "${EXPLICIT_TETRAGON_BINARY}" \
  "${BUNDLED_TETRAGON_BINARY}" || true)"
if [[ -z "${tetragon_bin}" ]]; then
  echo "missing repo-managed Tetragon binary; checked ${EXPLICIT_TETRAGON_BINARY:-<unset>} and ${BUNDLED_TETRAGON_BINARY}" >&2
  exit 1
fi

bpf_lib_dir=""
if bpf_lib_dir="$(pick_bpf_lib_dir)"; then
  :
else
  echo "missing bundled Tetragon .bpf.o files under ${BUNDLED_BPF_DIR}" >&2
  exit 1
fi

echo "TETRAGON_BINARY=${tetragon_bin}"
echo "TETRAGON_BPF_LIB_DIR=${bpf_lib_dir}"
echo "STRESS_NG_BINARY=$(command -v stress-ng)"

timeout 5s "${tetragon_bin}" --help >/dev/null 2>&1
