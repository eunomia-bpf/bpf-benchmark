#!/bin/bash
# Run this app's stages one after another under one timing-lock lease.
# WAIT_PID defers the start until another lane's timing job exits; the lock is
# taken before the first guest boot so samples never overlap another lane's.
set -eu
runner=$(dirname "$(readlink -f "$0")")
stage_dir=$1; shift
here=$runner/$stage_dir
out=${QUEUE_OUT:-/workspaces/kprog-raw/C/queue-$stage_dir}
install -d "$out"
printf '%s\n' "$$" > "$out/launcher.pid"
if [ -n "${WAIT_PID:-}" ]; then
  printf '%s\n' "$WAIT_PID" > "$out/waiting-for.pid"
  tail --pid="$WAIT_PID" -f /dev/null
fi
exec 9>>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -w 7200 9
date -u +%FT%TZ > "$out/started"
for stage in "$@"; do
  echo "$(date -u +%FT%TZ) stage $stage"
  bash "$here/run.sh" "$stage" || { echo "$(date -u +%FT%TZ) stage $stage rc=$?"; }
done
date -u +%FT%TZ > "$out/finished"