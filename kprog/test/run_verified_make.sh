#!/usr/bin/env bash
# Run with setsid nohup: run_verified_make.sh OUTPUT [make arguments...]
# VERIFIED_WAIT_PID defers the Make job until that owned guest launcher exits.
set -euo pipefail
run_dir=$1
shift
install -d "$run_dir"
printf '%s\n' "$$" > "$run_dir/launcher.pid"
command=(taskset -c "${VERIFIED_BUILD_CPUS:-8-19}" make "$@")
printf '%q ' "${command[@]}" > "$run_dir/make-command.txt"
printf '\n' >> "$run_dir/make-command.txt"
if [[ -n ${VERIFIED_WAIT_PID:-} ]]; then
    printf '%s\n' "$VERIFIED_WAIT_PID" > "$run_dir/waiting-for.pid"
    date -u +%FT%TZ > "$run_dir/queued"
    tail --pid="$VERIFIED_WAIT_PID" -f /dev/null
fi
date -u +%FT%TZ > "$run_dir/started"
status=0
"${command[@]}" 2>&1 | tee "$run_dir/make.log" >/dev/null || status=$?
printf '%s\n' "$status" > "$run_dir/exit-code"
date -u +%FT%TZ > "$run_dir/finished"
exit "$status"
