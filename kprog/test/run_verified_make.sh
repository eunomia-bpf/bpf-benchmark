#!/usr/bin/env bash
# Run with setsid nohup: run_verified_make.sh OUTPUT [make arguments...]
# VERIFIED_WAIT_PID defers the Make job until that owned guest launcher exits.
# VERIFIED_WAIT_JOB propagates the completed dependency's recorded Make status.
# VERIFIED_IMAGE_LOCK takes its shared image lock after the dependency exits.
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
if [[ -n ${VERIFIED_WAIT_JOB:-} ]]; then
    dependency_status=$(cat "$VERIFIED_WAIT_JOB/exit-code")
    if [[ $dependency_status != 0 ]]; then
        printf 'Dependency %s failed with status %s; Make was not started.\n' \
            "$VERIFIED_WAIT_JOB" "$dependency_status" >&2
        printf '%s\n' "$dependency_status" > "$run_dir/exit-code"
        date -u +%FT%TZ > "$run_dir/finished"
        exit "$dependency_status"
    fi
fi
if [[ -n ${VERIFIED_IMAGE_LOCK:-} ]]; then
    printf '%s\n' "$VERIFIED_IMAGE_LOCK" > "$run_dir/image-lock"
    exec 9>>"$VERIFIED_IMAGE_LOCK"
    flock -s 9
fi
date -u +%FT%TZ > "$run_dir/started"
status=0
"${command[@]}" 2>&1 | tee "$run_dir/make.log" >/dev/null || status=$?
printf '%s\n' "$status" > "$run_dir/exit-code"
date -u +%FT%TZ > "$run_dir/finished"
exit "$status"
