#!/usr/bin/env bash
# Run with setsid nohup: run_verified_make.sh OUTPUT [make arguments...]
set -eu
run_dir=$1
shift
install -d "$run_dir"
printf '%s\n' "$$" > "$run_dir/launcher.pid"
command=(taskset -c "${VERIFIED_BUILD_CPUS:-8-19}" make "$@")
printf '%q ' "${command[@]}" > "$run_dir/make-command.txt"
printf '\n' >> "$run_dir/make-command.txt"
date -u +%FT%TZ > "$run_dir/started"
status=0
"${command[@]}" > "$run_dir/make.log" 2>&1 || status=$?
printf '%s\n' "$status" > "$run_dir/exit-code"
date -u +%FT%TZ > "$run_dir/finished"
exit "$status"
