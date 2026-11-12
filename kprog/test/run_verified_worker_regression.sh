#!/usr/bin/env bash
# Invoke with setsid nohup: run_verified_worker_regression.sh PREVIOUS_PID OUTPUT
# Serializes the canonical worker rebuild and existing controls after our guest.
set -eu
previous_pid=$1
run_dir=$2
repo_root=/workspaces/repository
build_dir=/workspaces/.agent-state/kprog-ck/verified-loader
install -d "$run_dir"
printf '%s\n' "$$" > "$run_dir/launcher.pid"
trap 'printf "%s\n" "$?" > "$run_dir/exit-code"' EXIT
printf 'Waiting for guest launcher %s\n' "$previous_pid"
tail --pid="$previous_pid" -f /dev/null
date -u +%FT%TZ > "$run_dir/started-after-guest"
git -C "$repo_root" log -1 --format='%H %s' -- \
    kprog/libnativeloader/src/native_loader.cpp > "$run_dir/worker-source.txt"

run_step() {
    local name=$1 status=0
    shift
    printf '%q ' taskset -c 8-19 "$@" > "$run_dir/$name-command.txt"
    printf '\n' >> "$run_dir/$name-command.txt"
    taskset -c 8-19 "$@" > "$run_dir/$name.log" 2>&1 || status=$?
    printf '%s\n' "$status" > "$run_dir/$name-exit-code"
    return "$status"
}

make_args=(-C "$repo_root/kprog/libnativeloader" "BUILD_DIR=$build_dir" -j1)
run_step build make "${make_args[@]}" trusted-service
run_step submission make "${make_args[@]}" -o all trusted-submission-check
run_step lifetime make "${make_args[@]}" -o all trusted-lifecycle-check \
    "OUTPUT=$run_dir/lifetime"
run_step service make "${make_args[@]}" -o trusted-service trusted-service-kvm \
    "OUTPUT=$run_dir/service"
run_step tracee "$repo_root/kprog/test/run_verified_corpus.sh" \
    "$run_dir/tracee" tracee/monitor -o trusted-service
