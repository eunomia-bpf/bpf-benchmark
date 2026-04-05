#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RUNNER_DIR="$ROOT_DIR/runner"
MANIFEST_PATH="${1:?usage: prepare_run_inputs.sh <manifest_path>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[prepare-run-inputs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

die() {
    printf '[prepare-run-inputs][ERROR] %s\n' "$*" >&2
    exit 1
}

prepare_kvm_inputs() {
    local native_repos="${RUN_NATIVE_REPOS_CSV:-}"
    local benchmark_repos="${RUN_BENCHMARK_REPOS_CSV:-}"
    case "$RUN_SUITE_NAME" in
        test)
            make -C "$RUNNER_DIR" scx-artifacts daemon-binary kernel-image upstream-selftests-build unittest-build negative-build kinsn-modules-build
            ;;
        micro)
            make -C "$RUNNER_DIR" micro_exec micro-programs kernel-image
            ;;
        corpus)
            if [[ -n "$benchmark_repos" ]]; then
                make -C "$RUNNER_DIR" corpus-build daemon-binary kernel-image kinsn-modules-build REPOS="${benchmark_repos//,/ }"
            else
                make -C "$RUNNER_DIR" corpus-build daemon-binary kernel-image kinsn-modules-build
            fi
            ;;
        e2e)
            if [[ -n "$benchmark_repos" ]]; then
                make -C "$RUNNER_DIR" corpus-fetch REPOS="${benchmark_repos//,/ }"
            fi
            if [[ -n "$native_repos" ]]; then
                make -C "$RUNNER_DIR" corpus-build-native REPOS="${native_repos//,/ }"
            fi
            make -C "$RUNNER_DIR" e2e-prep e2e-tracee-setup e2e-tetragon-setup micro_exec daemon-binary kernel-image kinsn-modules-build
            ;;
        *)
            die "unsupported KVM suite: ${RUN_SUITE_NAME}"
            ;;
    esac
}

case "${RUN_EXECUTOR}" in
    kvm)
        prepare_kvm_inputs
        ;;
    *)
        die "prepare_run_inputs.sh only supports canonical KVM preflight; got executor: ${RUN_EXECUTOR}"
        ;;
esac
