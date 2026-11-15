#!/usr/bin/env bash
# Called under image SH after the in-place package repair; no timing claim.
set -euo pipefail
base_smoke_output=$1
base_smoke_root=/workspaces/repository
base_smoke_state=/var/tmp/kprog-tmp/perf/base-consistency-smoke
install -d "$base_smoke_output"
if [[ -n ${KPROG_TIMING_CAPTURE_DIR:-} ]]; then
    install -d "$KPROG_TIMING_CAPTURE_DIR"
fi

finish_base_smoke() {
    base_smoke_status=$?
    trap - EXIT
    for base_smoke_product in runtime.image.tar bpf-benchmark-docker.img bpf_x86_native_lab.ko; do
        base_smoke_path="$base_smoke_state/var-tmp/$base_smoke_product"
        if [[ -f $base_smoke_path ]]; then
            stat --printf='%s bytes %n\n' "$base_smoke_path" >> "$base_smoke_output/removed-build-copies.txt"
            rm -f "$base_smoke_path"
        fi
    done
    printf -- '- %s PERF base-consistency smoke: removed only completed scratch image/module copies in %s; raw logs/results kept in %s.\n' \
        "$(date -u +%FT%TZ)" "$base_smoke_state" "$base_smoke_output" >> "$base_smoke_root/kprog/docs/cleanup-log.md"
    exit "$base_smoke_status"
}
trap finish_base_smoke EXIT

base_smoke_command=(make -r -f "$base_smoke_root/kprog/perf/one-image/Makefile" corpus
    APPS=katran CPUS=16-19 VM_CPUS=8 VM_MEM=64G SAMPLES=1 WORKLOAD_DURATION=10
    BPFREJIT_CORPUS_BPF_STATS=1 SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE=post
    NATIVE_MANIFEST="$base_smoke_root/corpus/results/katran-c-hdr-20261115/objects/manifest.json"
    STATE="$base_smoke_state" LOGS="$base_smoke_output/logs" VNG_FLAGS=--verbose)
printf '%q ' "${base_smoke_command[@]}" > "$base_smoke_output/corpus-command.txt"
printf '\n' >> "$base_smoke_output/corpus-command.txt"
"${base_smoke_command[@]}"
