#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 2 ]]; then
    echo "usage: $0 <katran|cilium/agent> <session-token>" >&2
    exit 2
fi

app=$1
session_token=$2
root=$(cd "$(dirname "$0")/../../.." && pwd)

common=(
    -C "$root"
    -o x86-runner-runtime-image-tar
    corpus
    PLATFORM=aws
    ARCH=x86
    AWS_X86_BENCH_INSTANCE_TYPE=c7i.2xlarge
    AWS_X86_REGION=us-east-1
    AWS_X86_PROFILE=codex-ec2
    RUN_TOKEN="$session_token"
    BPFREJIT_CORPUS_APPS="$app"
    WORKLOAD_DURATION=60
    WARMUPS=0
    TIMEOUT=3600
)

terminate() {
    make -C "$root" terminate PLATFORM=aws ARCH=x86 RUN_TOKEN="$session_token" \
        AWS_X86_REGION=us-east-1 AWS_X86_PROFILE=codex-ec2 || true
}
trap terminate EXIT INT TERM

if [[ "$app" == "cilium/agent" ]]; then
    echo "PREFLIGHT app=$app start=$(date -u +%FT%TZ)"
    BPFREJIT_AWS_KEEP_INSTANCE=1 make "${common[@]}" \
        WORKLOAD_DURATION=5 SAMPLES=1 BPFREJIT_CORPUS_BPF_STATS=0 \
        BPFREJIT_SHIM_NATIVE_LOADER=post
    python3 "$root/corpus/results/aws_katran_cilium_outcomes_20261009/validate-cilium-preflight.py" \
        "$root/corpus/results"
    echo "PREFLIGHT app=$app end=$(date -u +%FT%TZ)"
fi

run_case() {
    local stats=$1
    local arm=$2
    local round=$3
    shift 3
    echo "CASE app=$app stats=$stats arm=$arm round=$round start=$(date -u +%FT%TZ)"
    BPFREJIT_AWS_KEEP_INSTANCE=1 make "${common[@]}" \
        SAMPLES=1 BPFREJIT_CORPUS_BPF_STATS="$stats" "$@"
    echo "CASE app=$app stats=$stats arm=$arm round=$round end=$(date -u +%FT%TZ)"
}

for stats in 0 1; do
    for round in 1 2 3 4 5; do
        run_case "$stats" native "$round" BPFREJIT_SHIM_NATIVE_LOADER=post
        run_case "$stats" kinsn "$round" BPFREJIT_BENCH_PASSES=default
    done
    echo "CASE app=$app stats=$stats arm=jit-restart-control round=1-5 start=$(date -u +%FT%TZ)"
    BPFREJIT_AWS_KEEP_INSTANCE=1 make "${common[@]}" \
        SAMPLES=5 BPFREJIT_CORPUS_BPF_STATS="$stats" SKIP_REJIT=norejit
    echo "CASE app=$app stats=$stats arm=jit-restart-control round=1-5 end=$(date -u +%FT%TZ)"
done

trap - EXIT INT TERM
terminate
