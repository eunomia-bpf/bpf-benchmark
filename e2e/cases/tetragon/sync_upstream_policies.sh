#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
POLICY_DIR="${SCRIPT_DIR}/policies"
UPSTREAM_REF="${TETRAGON_UPSTREAM_REF:-38a65437a875246d31e13347ebf6a3c0184d4b6b}"
BASE_URL="https://raw.githubusercontent.com/cilium/tetragon/${UPSTREAM_REF}"

rm -rf "${POLICY_DIR}"
mkdir -p "${POLICY_DIR}"

count=0
while IFS= read -r relpath; do
    [ -n "${relpath}" ] || continue
    target="${POLICY_DIR}/${relpath#examples/tracingpolicy/}"
    mkdir -p "$(dirname -- "${target}")"
    curl --fail --location --silent --show-error "${BASE_URL}/${relpath}" -o "${target}"
    count=$((count + 1))
done <<'EOF'
examples/tracingpolicy/bpf.yaml
examples/tracingpolicy/datagram-with-sock-tracking.yaml
examples/tracingpolicy/datagram_518.yaml
examples/tracingpolicy/fd_install_cap_changes.yaml
examples/tracingpolicy/filename_monitoring.yaml
examples/tracingpolicy/host-changes/monitor-kernel-modules.yaml
examples/tracingpolicy/list-syscalls-tracepoint.yaml
examples/tracingpolicy/process-credentials/process-creds-changed.yaml
examples/tracingpolicy/process-exec/process-exec-elf-begin.yaml
examples/tracingpolicy/raw_syscalls.yaml
examples/tracingpolicy/rawtp.yaml
examples/tracingpolicy/security-socket-connect.yaml
examples/tracingpolicy/security_inode_follow_link.yaml
examples/tracingpolicy/stack_traces.yaml
examples/tracingpolicy/sys_mount.yaml
examples/tracingpolicy/tcp-accept.yaml
examples/tracingpolicy/tcp-connect-with-selectors.yaml
examples/tracingpolicy/tty.yaml
EOF

find "${POLICY_DIR}" -type f \( -name '*.yaml' -o -name '*.yml' \) | grep -q .
printf 'synced %d upstream Tetragon policies from %s\n' "${count}" "${UPSTREAM_REF}"
