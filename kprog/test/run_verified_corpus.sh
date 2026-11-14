#!/usr/bin/env bash
# Invoke with setsid nohup and a fresh persistent result directory:
# run_verified_corpus.sh OUTPUT APP [extra make arguments...]
# Existing SAMPLES/WORKLOAD_DURATION/BPFREJIT_CORPUS_BPF_STATS select the sample.
set -euo pipefail
run_dir=$1
app=$2
shift 2
repo_root=/workspaces/repository
install -d "$run_dir" /var/tmp/kprog-tmp/verified/corpus-state
printf '%s\n' "$$" > "$run_dir/launcher.pid"
make_args=(
    -C "$repo_root/kprog/libnativeloader" "$@" trusted-service-kvm
    BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader
    "OUTPUT=$run_dir/control" VM_CPUS=8 VM_MEM=64G
    'VNG_FLAGS=--overlay-rwdir /run --overlay-rwdir /usr/local --rwdir /var/tmp=/var/tmp/kprog-tmp/verified/corpus-state'
    "SERVICE_RUN=python3 $repo_root/kprog/test/verified_corpus.py $app ${SAMPLES:-1} ${WORKLOAD_DURATION:-10} ${BPFREJIT_CORPUS_BPF_STATS:-1}"
    -j1
)
printf '%q ' taskset -c 8-15 make "${make_args[@]}" > "$run_dir/make-command.txt"
printf '\n' >> "$run_dir/make-command.txt"
status=0
taskset -c 8-15 make "${make_args[@]}" 2>&1 | tee "$run_dir/corpus.log" >/dev/null || status=$?
printf '%s\n' "$status" > "$run_dir/exit-code"
exit "$status"
