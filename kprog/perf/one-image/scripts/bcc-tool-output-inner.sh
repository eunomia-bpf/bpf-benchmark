#!/bin/bash
# The eight bcc/set tools against the frozen workload, for one arm, with each
# tool's full stdout and stderr kept. Runs inside the runtime container.
#
# Why this exists: the corpus driver keeps only tail_text(40 lines, 8000 chars)
# of each tool in BccSetRunner.process_output and never persists it, so a timed
# run says nothing about whether the two arms made the tools print the same
# events. This runs the same tools, with the same environment the runner gives
# them (runner/libs/app_runners/bcc_set.py:_spawn_child), and keeps everything.
#
# Usage: bcc-tool-output-inner.sh <baseline|post> <out-dir> [seconds]
set -euo pipefail

ARM=${1:?baseline or post}
OUT=${2:?output directory}
SECONDS_N=${3:-20}
ROOT=/workspaces/repository
# BCC_SET_TOOL_SPECS, runner/libs/app_runners/bcc_set.py:33-42.
TOOLS="capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat"

install -d "$OUT/$ARM"
cd "$ROOT"

# The runner's per-tool environment, bcc_set.py:135-141: the shim is attached to
# every child so the tool registers its own per-pid socket, and the native
# loader switch reaches each child. The baseline arm leaves the loader unset
# (corpus/driver.py:697-698 sets it only for the post arm).
SHIM_ENV=(
  LD_PRELOAD=/usr/local/lib/bpfrejit/libbpfrejit_shim.so
  BPFREJIT_SHIM_SOCK_DIR=/var/run/bpfrejit
  BPFREJIT_SHIM_LOG="$OUT/$ARM/shim.log"
)
if [ "$ARM" = post ]; then
  SHIM_ENV+=(
    BPFREJIT_SHIM_NATIVE_LOADER=1
    BPFREJIT_SHIM_NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/bcc/manifest.json
    BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so
  )
fi

pids=()
for tool in $TOOLS; do
  args=""
  [ "$tool" = syscount ] && args="-L -i 1"
  # shellcheck disable=SC2086 # syscount's -L -i 1 is two words on purpose
  env "${SHIM_ENV[@]}" /usr/local/bin/$tool $args \
    >"$OUT/$ARM/$tool.out" 2>"$OUT/$ARM/$tool.err" &
  pids+=("$!")
done

# Let every tool attach before the workload starts, as wait_for_app_shim_programs
# does for the timed runs.
sleep 3

python3 - "$SECONDS_N" "$OUT/$ARM/workload.out" <<'PY'
import sys
from runner.libs.workload import run_named_workload

seconds, out_path = int(sys.argv[1]), sys.argv[2]
result = run_named_workload("stress_ng_bcc_hook_hot", seconds)
with open(out_path, "w", encoding="utf-8") as handle:
    handle.write(result.stdout)
    handle.write(result.stderr)
PY

# SIGINT is how the runner stops each tool (runner/libs/agent.py:stop_agent),
# and BCC tools flush their final output on it -- except vfsstat, which ignores
# it and keeps printing a row a second. Escalate to SIGTERM so one stubborn
# tool does not hold the arm open.
for pid in "${pids[@]}"; do
  kill -INT "$pid" 2>/dev/null || true
done
for _ in $(seq 10); do
  running=0
  for pid in "${pids[@]}"; do
    kill -0 "$pid" 2>/dev/null && running=1
  done
  [ "$running" -eq 0 ] && break
  sleep 1
done
for pid in "${pids[@]}"; do
  kill -0 "$pid" 2>/dev/null && kill -TERM "$pid" 2>/dev/null || true
done
for pid in "${pids[@]}"; do
  wait "$pid" || true
done

wc -l "$OUT/$ARM"/*.out "$OUT/$ARM"/*.err