#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 3 ]]; then
  echo "usage: $0 <daemon-socket> <batch-spec> <result-json>" >&2
  exit 2
fi

daemon_socket="$1"
batch_spec="$2"
result_json="$3"
repo_root="/home/yunwei37/workspace/bpf-benchmark"
daemon_bin="$repo_root/daemon/target/release/bpfrejit-daemon"
runner_bin="$repo_root/runner/build/micro_exec"

rm -f "$daemon_socket"
"$daemon_bin" serve --socket "$daemon_socket" &
daemon_pid=$!
trap 'kill "$daemon_pid" 2>/dev/null || true; rm -f "$daemon_socket"' EXIT
sleep 0.5
"$runner_bin" run-batch --spec "$batch_spec" --result-json "$result_json"
