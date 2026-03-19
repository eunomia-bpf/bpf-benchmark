#!/usr/bin/env bash
set -euo pipefail

find_binary() {
  local name="$1"
  shift
  if command -v "${name}" >/dev/null 2>&1; then
    command -v "${name}"
    return 0
  fi
  local candidate
  for candidate in "$@"; do
    if [[ -x "${candidate}" ]]; then
      printf '%s\n' "${candidate}"
      return 0
    fi
  done
  return 1
}

require_tool() {
  local tool="$1"
  if ! command -v "${tool}" >/dev/null 2>&1; then
    echo "missing required tool: ${tool}" >&2
    exit 1
  fi
}

require_tool bpftool
require_tool ip

katran_server_bin="$(find_binary katran_server_grpc \
  "$(pwd)/e2e/cases/katran/bin/katran_server_grpc" \
  /usr/local/bin/katran_server_grpc \
  /usr/local/sbin/katran_server_grpc \
  /opt/katran/bin/katran_server_grpc \
  "$(pwd)/third_party/katran-src/build/example_grpc/katran_server_grpc" \
  "$(pwd)/tmp/katran-src/build/example_grpc/katran_server_grpc" || true)"

echo "KATRAN_SERVER_BINARY=${katran_server_bin}"
echo "BPFTOOL_BINARY=$(command -v bpftool)"
echo "IP_BINARY=$(command -v ip)"
