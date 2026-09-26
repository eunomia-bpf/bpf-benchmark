#!/usr/bin/env bash
# Build the single ZIP uploaded for the ATC 2026 artifact deposit.
# Usage: docs/artifacts/package-atc26.sh [OUTPUT_DIR]
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
OUT_DIR="${1:-$ROOT_DIR/docs/artifacts/dist}"
VERSION="$(sed -n 's/^version: *"\{0,1\}\([^"]*\)"\{0,1\}$/\1/p' "$ROOT_DIR/CITATION.cff" | head -1)"
[ -n "$VERSION" ] || { echo "cannot read version from CITATION.cff" >&2; exit 1; }
for command in git tar zip unzip python3 sha256sum; do
    command -v "$command" >/dev/null || { echo "missing command: $command" >&2; exit 1; }
done

mkdir -p "$OUT_DIR"
OUT_DIR="$(cd "$OUT_DIR" && pwd)"
STAGE="$(mktemp -d)"
PACKAGE_DIR="$(mktemp -d)"
ZIP="$PACKAGE_DIR/$VERSION.zip"
FINAL_ZIP="$OUT_DIR/$VERSION.zip"
VERIFY=""
trap 'rm -rf "$STAGE" "$PACKAGE_DIR" "${VERIFY:-}"' EXIT
COMMIT="$(git -C "$ROOT_DIR" rev-parse HEAD)"
echo "packaging $VERSION at $COMMIT"

# Archive the frozen commit, never the working tree or a later moving HEAD.
git -C "$ROOT_DIR" archive --format=tar "$COMMIT" -- . \
    ':(exclude)corpus/results' \
    ':(exclude)micro/results' \
    ':(exclude)tests/results' \
    ':(exclude)docs/tmp' \
    ':(exclude)tmp-*' \
    ':(exclude)docs/source-opt' \
    ':(exclude)docs/reference' \
    ':(exclude)docs/research' \
    ':(exclude)docs/ebpf27-bpfoptbench' \
    ':(exclude)docs/kprog-simulator-in-ebpf' \
    ':(exclude)docs/speculative-optimization' \
    ':(exclude)docs/paper' \
    ':(exclude).agents' \
    ':(exclude).codex' \
    ':(exclude).claude' \
    ':(exclude)vendor/academic-writing-skills' \
    ':(exclude)vendor/libbpf' \
    ':(exclude)vendor/linux-framework' \
    ':(exclude)vendor/llvmbpf' \
    ':(exclude)vendor/repos' \
    ':(exclude)llvm-backend/llvm' \
    | tar -x -C "$STAGE"

pin_for() {
    git -C "$ROOT_DIR" ls-tree "$COMMIT" -- "$1" | awk '{print $3}'
}

: > "$STAGE/.nested-submodules.tsv"
embed_repo_tree() {
    local repo_dir="$1" archive_prefix="$2" revision="$3"
    local modules_file key name nested_path nested_url nested_revision nested_repo
    mkdir -p "$STAGE/$archive_prefix"
    git -C "$repo_dir" archive --format=tar "$revision" |
        tar -x -C "$STAGE/$archive_prefix"

    modules_file="$(mktemp)"
    if git -C "$repo_dir" show "$revision:.gitmodules" > "$modules_file" 2>/dev/null; then
        while read -r key nested_path; do
            name="$(printf '%s' "$key" | sed 's/^submodule\.//;s/\.path$//')"
            nested_url="$(git config -f "$modules_file" --get "submodule.$name.url")"
            nested_revision="$(git -C "$repo_dir" ls-tree "$revision" -- "$nested_path" | awk '{print $3}')"
            [ -n "$nested_revision" ] || {
                echo "no pinned nested revision for $archive_prefix/$nested_path" >&2
                rm -f "$modules_file"
                exit 1
            }
            nested_repo="$repo_dir/$nested_path"
            git -C "$nested_repo" cat-file -e "$nested_revision^{commit}" 2>/dev/null || {
                echo "nested submodule object unavailable: $archive_prefix/$nested_path @ $nested_revision" >&2
                echo "initialize recursively before packaging: git submodule update --init --recursive" >&2
                rm -f "$modules_file"
                exit 1
            }
            printf '%s\t%s\t%s\n' "$archive_prefix/$nested_path" "$nested_revision" "$nested_url" >> "$STAGE/.nested-submodules.tsv"
            echo "    nested $archive_prefix/$nested_path @ $nested_revision"
            embed_repo_tree "$nested_repo" "$archive_prefix/$nested_path" "$nested_revision"
        done < <(git config -f "$modules_file" --get-regexp 'submodule\..*\.path' || true)
    fi
    rm -f "$modules_file"
}

embed_submodule() {
    local path="$1" pinned
    pinned="$(pin_for "$path")"
    [ -n "$pinned" ] || { echo "no pinned revision for $path" >&2; exit 1; }
    git -C "$ROOT_DIR/$path" cat-file -e "$pinned^{commit}" 2>/dev/null || {
        echo "submodule object unavailable: $path @ $pinned" >&2
        echo "initialize it before packaging: git submodule update --init --recursive" >&2
        exit 1
    }
    embed_repo_tree "$ROOT_DIR/$path" "$path" "$pinned"
    echo "  embedded $path @ $pinned"
}

# Embed every source submodule required by the documented proof,
# microbenchmark, and six-application corpus paths. This makes the archival ZIP
# independent of the continued availability of mutable upstream hosting while
# preserving every exact superproject pin in ARTIFACT_MANIFEST.json.
EMBEDDED_SUBMODULES=(
    vendor/llvmbpf
    vendor/libbpf
    vendor/linux-framework
    llvm-backend/llvm
    vendor/repos/bcc
    vendor/repos/opentelemetry-ebpf-profiler
    vendor/repos/cilium
    vendor/repos/tetragon
    vendor/repos/katran
    vendor/repos/tracee
    docs/paper
)
echo "embedding artifact submodules:"
for path in "${EMBEDDED_SUBMODULES[@]}"; do embed_submodule "$path"; done

# Add the raw paper-result datasets consumed by the plotting scripts and the
# renderer's 62-case/fresh load-time and exec rows.
RESULTS=(
    micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json
    micro/results/x86_kvm_micro_20260526_210351_224315/details/result.json
    micro/results/aws_arm64_micro_20260606_001225_821028/details/result.json
    micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json
    micro/results/aws_arm64_micro_20260606_063319_954947/details/result.json
    micro/results/x86_kvm_micro_20260514_031744_210343/details/result.json
    micro/results/x86_kvm_micro_20260514_181806_133778/details/result.json
    micro/results/x86_kvm_micro_20260429_035938_203074/details/result.json
    micro/results/x86_kvm_micro_20260924_231824_136293/details/result.json
    micro/results/x86_kvm_micro_20260925_002201_525373/details/result.json
)
echo "embedding paper-result datasets:"
for rel in "${RESULTS[@]}"; do
    mkdir -p "$STAGE/$(dirname "$rel")"
    git -C "$ROOT_DIR" show "$COMMIT:$rel" > "$STAGE/$rel"
    echo "  $rel"
done
# Keep status and environment provenance with each selected result.json.
for rel in "${RESULTS[@]}"; do
    run_dir="${rel%/details/result.json}"
    for extra in metadata.json details/progress.json; do
        path="$run_dir/$extra"
        mkdir -p "$STAGE/$(dirname "$path")"
        git -C "$ROOT_DIR" show "$COMMIT:$path" > "$STAGE/$path"
    done
done

# Retain the compact Cilium/Katran RQ2/RQ3/RQ4 records used by
# render_claim_table.py. The paper's 4086-site and loader-count claims still
# lack their original per-pass logs; do not infer them from these app records.
# The x86_kvm_corpus_20260924_* runs are fresh-generation reruns of the
# RQ3 Cilium single-pass policies that DO retain details/loadtime-reports, from
# which render_claim_table.py derives applied-site counts, plus the fresh
# native-post run whose run record gates the derived RQ4 native-loader row (its
# shim log and manifest ship under docs/artifacts/evidence/, since
# details/shim-logs/ is git-ignored). The
# arm64_qemu_corpus_19700101_* runs are the equivalent fresh local-QEMU reruns
# of the two RQ3 Katran ARM64 policies, retained with details/loadtime-reports
# and details/apps/katran.json so those counts are derived too.
CORPUS_RUNS=(
    x86_kvm_corpus_20260604_070210_639497
    x86_kvm_corpus_20260604_100557_313063
    x86_kvm_corpus_20260529_033517_489159
    x86_kvm_corpus_20260529_040554_604387
    x86_kvm_corpus_20260529_043720_016160
    x86_kvm_corpus_20260605_145112_835705
    x86_kvm_corpus_20260605_141420_746952
    x86_kvm_corpus_20260605_164411_317423
    x86_kvm_corpus_20260605_160715_129437
    x86_kvm_corpus_20260924_064817_392000
    x86_kvm_corpus_20260924_074900_275227
    x86_kvm_corpus_20260924_085901_647044
    x86_kvm_corpus_20260924_095500_223221
    x86_kvm_corpus_20260924_114427_040291
    x86_kvm_corpus_20260924_164153_955835
    aws_arm64_corpus_20260605_080836_924256
    aws_arm64_corpus_20260605_094729_221231
    arm64_qemu_corpus_19700101_000011_781867
    arm64_qemu_corpus_19700101_000011_741370
)

for run in "${CORPUS_RUNS[@]}"; do
    for extra in metadata.json details/progress.json details/result.json \
                 details/apps/cilium__agent.json details/apps/katran.json \
                 details/loadtime-reports/cilium__agent.jsonl \
                 details/loadtime-reports/katran.jsonl; do
        path="corpus/results/$run/$extra"
        git -C "$ROOT_DIR" ls-tree "$COMMIT" -- "$path" | grep -q . || continue
        mkdir -p "$STAGE/$(dirname "$path")"
        git -C "$ROOT_DIR" show "$COMMIT:$path" > "$STAGE/$path"
    done
done

# The controlled per-pass throughput-causality rows read, for each of the six
# applications, one `map_inline`-only run plus two same-batch no-pass
# `loadtime` runs from the tracked May 2026 matched batch. Each run needs its
# own single app record alongside the status files the renderer gates on;
# `corpus/results` is excluded above, so stage them explicitly here.
CAUSALITY_RUNS=(
    "x86_kvm_corpus_20260522_042759_209148 bcc__set.json"
    "x86_kvm_corpus_20260522_040414_983443 bcc__set.json"
    "x86_kvm_corpus_20260522_041848_461647 bcc__set.json"
    "x86_kvm_corpus_20260522_050233_401368 otelcol-ebpf-profiler__profiling.json"
    "x86_kvm_corpus_20260522_044521_899895 otelcol-ebpf-profiler__profiling.json"
    "x86_kvm_corpus_20260522_045359_622598 otelcol-ebpf-profiler__profiling.json"
    "x86_kvm_corpus_20260522_054834_450402 cilium__agent.json"
    "x86_kvm_corpus_20260522_052646_166503 cilium__agent.json"
    "x86_kvm_corpus_20260522_053738_559124 cilium__agent.json"
    "x86_kvm_corpus_20260522_070721_604229 tetragon__observer.json"
    "x86_kvm_corpus_20260522_064657_150013 tetragon__observer.json"
    "x86_kvm_corpus_20260522_065609_372274 tetragon__observer.json"
    "x86_kvm_corpus_20260522_074136_764813 katran.json"
    "x86_kvm_corpus_20260522_072319_967424 katran.json"
    "x86_kvm_corpus_20260522_073158_210866 katran.json"
    "x86_kvm_corpus_20260522_081529_738968 tracee__monitor.json"
    "x86_kvm_corpus_20260522_075613_925659 tracee__monitor.json"
    "x86_kvm_corpus_20260522_080555_505608 tracee__monitor.json"
)
echo "embedding May causality runs:"
for spec in "${CAUSALITY_RUNS[@]}"; do
    set -- $spec
    run="$1"; app="$2"
    for extra in metadata.json details/progress.json "details/apps/$app"; do
        path="corpus/results/$run/$extra"
        git -C "$ROOT_DIR" ls-tree "$COMMIT" -- "$path" | grep -q . || continue
        mkdir -p "$STAGE/$(dirname "$path")"
        git -C "$ROOT_DIR" show "$COMMIT:$path" > "$STAGE/$path"
    done
    echo "  $run ($app)"
done

# docs/tmp holds the engineering log and the analysis scripts several shipped
# documents cite, but the bulk result trees under it are excluded above.
# Re-add only the cited files so no shipped reference dangles.
CITED_DOCS=(
    docs/tmp/20260906-bpf-development-todo.md
    docs/tmp/arm64_kop_micro_20260606_summary.md
    docs/tmp/kop_ablation_20260605_summary.md
    docs/tmp/kop_all_force_eval_20260603.py
    docs/tmp/kop_arm64_eval_20260605.py
    docs/tmp/kop_arm64_eval_20260605_summary.md
    docs/tmp/kop_eval_20260602.py
    docs/tmp/kop_eval_20260604.py
    docs/tmp/kop_eval_20260604_summary.md
    docs/tmp/micro-bench-status-20260520-archive.md
    docs/tmp/micro_characterization_20260606_summary.md
    docs/tmp/native_eval_20260529.py
    docs/tmp/native_eval_20260614.py
    docs/tmp/native_eval_20260614_summary.md
    docs/tmp/plot_arm64_kop_micro_20260605.py
    docs/tmp/plot_arm64_kop_micro_20260606.py
    docs/tmp/plot_kop_micro_20260527.py
    docs/tmp/plot_micro_characterization_20260606.py
    docs/tmp/q5_widemem_kernel_panic_20260507.md
)
for path in "${CITED_DOCS[@]}"; do
    git -C "$ROOT_DIR" ls-tree "$COMMIT" -- "$path" | grep -q . || {
        echo "cited doc missing from commit: $path" >&2; exit 1; }
    mkdir -p "$STAGE/$(dirname "$path")"
    git -C "$ROOT_DIR" show "$COMMIT:$path" > "$STAGE/$path"
done

cat > "$STAGE/README-ARTIFACT.md" <<EOF
# BPF-Ext ATC 2026 artifact $VERSION

This is the single archival ZIP for accepted ATC 2026 paper #1160,
“BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native Operations.”
Start with [docs/atc26-artifact-evaluation.md](docs/atc26-artifact-evaluation.md).
The archive contains the exact source trees needed by the documented proof,
microbenchmark, and six-application KVM paths, plus the five raw paper-result
JSON datasets read by the included plotting scripts, historical load-time and 62-name population
JSON datasets whose pairing remains weaker than the paper's 0.99x claim,
plus selected Cilium, Katran and Tracee RQ2/RQ3/RQ4 raw app records and run-status
provenance read by the claim renderer. Compact retained evidence
records the complete formal check, the six-application ReJIT coverage run, the
fresh Katran KVM smoke, and the fresh Cilium native-loader run whose shim log
derives the RQ4 loader and manifest-object counts, plus the fresh Cilium
single-pass \`map_inline\` run, the fresh Katran \`map_inline\` run over the
overlay/hint policy path, the fresh Tracee \`map_inline\` run over the
hint-free default policy path, the fresh Tetragon \`map_inline\` run over the
hint-free default policy path across six array maps, and the fresh arm64 Katran
\`qemu-system-aarch64\` executor, all retaining per-step before/after bytecode so
the RQ2 rewrite can be re-derived per application. A tracked May 2026 matched
batch of eighteen single-application runs (six apps × one \`map_inline\`-only run
plus two same-batch no-pass \`loadtime\` nulls at the identical 60 s duration)
lets the renderer derive controlled per-pass throughput-causality ratios whose
restart drift is subtracted by the no-pass controls. The archive additionally
carries fresh, provenance-complete Katran, Cilium, Tetragon, Tracee, BCC, and
otelcol-ebpf-profiler \`map_inline\` causality triplets — for each, one optimized
run plus two matched no-pass controls, each with its own make-console log —
whose retained per-step bytecode binds the derived applied-site rewrite (16
sites for Katran, 3787 for Cilium, 148 for Tetragon, 12 for Tracee, 83 for BCC,
1078 for otelcol-ebpf-profiler) to the measured
control-corrected throughput ratio.
ARTIFACT_MANIFEST.json records
the superproject commit and every direct and nested submodule pin. Historical bulk
result trees are omitted; the guide gives the commands that regenerate them.
EOF

# Build a machine-readable manifest without scanning submodule working trees.
: > "$STAGE/.submodules.tsv"
while read -r key path; do
    name="${key#submodule.}"; name="${name%.path}"
    url="$(git -C "$ROOT_DIR" config -f .gitmodules --get "submodule.$name.url")"
    pin="$(pin_for "$path")"
    embedded=false
    for selected in "${EMBEDDED_SUBMODULES[@]}"; do
        [ "$path" = "$selected" ] && embedded=true
    done
    printf '%s\t%s\t%s\t%s\n' "$path" "$pin" "$url" "$embedded" >> "$STAGE/.submodules.tsv"
done < <(git -C "$ROOT_DIR" config -f .gitmodules --get-regexp 'submodule\..*\.path')

STAGE_DIR="$STAGE" VERSION_VALUE="$VERSION" COMMIT_VALUE="$COMMIT" python3 - <<'PY'
import json, os
from pathlib import Path
stage = Path(os.environ['STAGE_DIR'])
submodules = []
for line in (stage / '.submodules.tsv').read_text().splitlines():
    path, revision, url, embedded = line.split('\t')
    submodules.append({
        'path': path, 'revision': revision, 'url': url,
        'embedded': embedded == 'true'
    })
nested_submodules = []
for line in (stage / '.nested-submodules.tsv').read_text().splitlines():
    path, revision, url = line.split('	')
    nested_submodules.append({
        'path': path, 'revision': revision, 'url': url, 'embedded': True
    })
manifest = {
    'artifact': 'BPF-Ext ATC 2026 artifact for accepted paper #1160',
    'version': os.environ['VERSION_VALUE'],
    'superprojectCommit': os.environ['COMMIT_VALUE'],
    'entryPoint': 'docs/atc26-artifact-evaluation.md',
    'submodules': submodules,
    'nestedSubmodules': nested_submodules,
    'paperResultFiles': [
        str(path.relative_to(stage))
        for pattern in ('micro/results/*/metadata.json',
                        'micro/results/*/details/progress.json',
                        'micro/results/*/details/result.json')
        for path in sorted(stage.glob(pattern))
    ],
    'corpusResultFiles': [
        str(path.relative_to(stage))
        for pattern in ('corpus/results/*/metadata.json',
                        'corpus/results/*/details/progress.json',
                        'corpus/results/*/details/result.json',
                        'corpus/results/*/details/apps/cilium__agent.json',
                        'corpus/results/*/details/apps/katran.json')
        for path in sorted(stage.glob(pattern))
    ],
    'validationEvidence': [
        'docs/artifacts/evidence/formal-check.json',
        'docs/artifacts/evidence/formal-check.log',
        'docs/artifacts/evidence/kvm-six-app-coverage/receipt.json',
        'docs/artifacts/evidence/kvm-six-app-success/receipt.json',
        'docs/artifacts/evidence/kvm-six-app-success/make-corpus.log',
        'docs/artifacts/evidence/kvm-katran-smoke/receipt.json',
        'docs/artifacts/evidence/kvm-katran-smoke/make-corpus.log',
        'docs/artifacts/evidence/rq4-cilium-native-loader/receipt.json',
        'docs/artifacts/evidence/rq4-cilium-native-loader/manifest.json',
        'docs/artifacts/evidence/rq4-cilium-native-loader/make-corpus.log',
        'docs/artifacts/evidence/rq4-cilium-native-loader/details/shim-logs/cilium__agent.post_rejit.log',
        'docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/receipt.json',
        'docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/make-corpus.log',
        'docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/details/loadtime-reports/cilium__agent.jsonl',
        'docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/receipt.json',
        'docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/make-corpus.log',
        'docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/details/loadtime-reports/katran.jsonl',
        'docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/receipt.json',
        'docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/make-corpus.log',
        'docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/details/loadtime-reports/tracee__monitor.jsonl',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/receipt.json',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/make-corpus.log',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/details/loadtime-reports/tetragon__observer.jsonl',
        'docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/receipt.json',
        'docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/make-corpus.log',
        'docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/details/loadtime-reports/cilium__agent.jsonl',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/details/loadtime-reports/tetragon__observer.jsonl',
        'docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/details/loadtime-reports/tracee__monitor.jsonl',
        'docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/details/loadtime-reports/bcc__set.jsonl',
        'docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/receipt.json',
        'docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/make-corpus.log',
        'docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl',
        'docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/details/loadtime-reports/katran.jsonl',
    ],
    'omittedGeneratedData': ['corpus/results', 'micro/results (except listed files)', 'tests/results'],
}
(stage / 'ARTIFACT_MANIFEST.json').write_text(json.dumps(manifest, indent=2) + '\n')
(stage / '.submodules.tsv').unlink()
(stage / '.nested-submodules.tsv').unlink()
PY

( cd "$STAGE" && zip -q -r -X "$ZIP" . )
( cd "$PACKAGE_DIR" && sha256sum "$(basename "$ZIP")" > "$(basename "$ZIP").sha256" )
( cd "$PACKAGE_DIR" && sha256sum -c "$(basename "$ZIP").sha256" )

VERIFY="$(mktemp -d)"
unzip -q "$ZIP" -d "$VERIFY"
required=(
    README-ARTIFACT.md ARTIFACT_MANIFEST.json LICENSE THIRD_PARTY_NOTICES.md
    CITATION.cff .zenodo.json CHANGELOG.md Makefile
    docs/atc26-artifact-evaluation.md docs/artifacts/render_claim_table.py
    docs/paper/scripts/plot_evaluation_koperation.py
    docs/paper/scripts/plot_rq3_policy_probes.py
    docs/paper/scripts/plot_app_case_studies.py
    native-sim/formal/lean-toolchain vendor/llvmbpf/CMakeLists.txt
    vendor/libbpf/src/libbpf.c vendor/linux-framework/Makefile
    llvm-backend/llvm/llvm/CMakeLists.txt vendor/repos/katran/CMakeLists.txt
    vendor/repos/tracee/Makefile vendor/repos/tetragon/Makefile
    vendor/repos/cilium/Makefile vendor/repos/bcc/CMakeLists.txt
    vendor/repos/bcc/src/cc/libbpf/src/libbpf.c
    vendor/repos/bcc/libbpf-tools/bpftool/src/main.c
    vendor/repos/bcc/libbpf-tools/bpftool/libbpf/src/libbpf.c
    vendor/repos/bcc/libbpf-tools/blazesym/Cargo.toml
    vendor/repos/tracee/3rdparty/libbpf/src/libbpf.c
    vendor/repos/opentelemetry-ebpf-profiler/Makefile
    docs/artifacts/evidence/formal-check.json
    docs/artifacts/evidence/formal-check.log
    docs/artifacts/evidence/kvm-six-app-coverage/receipt.json
    docs/artifacts/evidence/kvm-six-app-coverage/details/progress.json
    docs/artifacts/evidence/kvm-six-app-coverage/details/apps/tracee__monitor.json
    docs/artifacts/evidence/kvm-six-app-success/receipt.json
    docs/artifacts/evidence/kvm-six-app-success/make-corpus.log
    docs/artifacts/evidence/kvm-six-app-success/details/progress.json
    docs/artifacts/evidence/kvm-six-app-success/details/apps/tracee__monitor.json
    docs/artifacts/evidence/kvm-katran-smoke/receipt.json
    docs/artifacts/evidence/kvm-katran-smoke/make-corpus.log
    docs/artifacts/evidence/kvm-katran-smoke/details/progress.json
    docs/artifacts/evidence/kvm-katran-smoke/details/apps/katran.json
    docs/artifacts/evidence/rq4-cilium-native-loader/receipt.json
    docs/artifacts/evidence/rq4-cilium-native-loader/manifest.json
    docs/artifacts/evidence/rq4-cilium-native-loader/make-corpus.log
    docs/artifacts/evidence/rq4-cilium-native-loader/details/shim-logs/cilium__agent.post_rejit.log
    corpus/results/x86_kvm_corpus_20260522_042759_209148/metadata.json
    corpus/results/x86_kvm_corpus_20260522_042759_209148/details/progress.json
    corpus/results/x86_kvm_corpus_20260522_042759_209148/details/apps/bcc__set.json
    corpus/results/x86_kvm_corpus_20260522_040414_983443/details/apps/bcc__set.json
    corpus/results/x86_kvm_corpus_20260522_041848_461647/details/apps/bcc__set.json
    corpus/results/x86_kvm_corpus_20260522_050233_401368/details/apps/otelcol-ebpf-profiler__profiling.json
    corpus/results/x86_kvm_corpus_20260522_044521_899895/details/apps/otelcol-ebpf-profiler__profiling.json
    corpus/results/x86_kvm_corpus_20260522_045359_622598/details/apps/otelcol-ebpf-profiler__profiling.json
    corpus/results/x86_kvm_corpus_20260522_054834_450402/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260522_052646_166503/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260522_053738_559124/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260522_070721_604229/details/apps/tetragon__observer.json
    corpus/results/x86_kvm_corpus_20260522_064657_150013/details/apps/tetragon__observer.json
    corpus/results/x86_kvm_corpus_20260522_065609_372274/details/apps/tetragon__observer.json
    corpus/results/x86_kvm_corpus_20260522_074136_764813/metadata.json
    corpus/results/x86_kvm_corpus_20260522_074136_764813/details/progress.json
    corpus/results/x86_kvm_corpus_20260522_074136_764813/details/apps/katran.json
    corpus/results/x86_kvm_corpus_20260522_072319_967424/details/apps/katran.json
    corpus/results/x86_kvm_corpus_20260522_073158_210866/details/apps/katran.json
    corpus/results/x86_kvm_corpus_20260522_081529_738968/details/apps/tracee__monitor.json
    corpus/results/x86_kvm_corpus_20260522_075613_925659/details/apps/tracee__monitor.json
    corpus/results/x86_kvm_corpus_20260522_080555_505608/details/apps/tracee__monitor.json
    docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/receipt.json
    docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/make-corpus.log
    docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/details/loadtime-reports/cilium__agent.jsonl
    docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/details/loadtime-workdirs/loadtime_3525_30/input.step.0.bin
    docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/receipt.json
    docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/make-corpus.log
    docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/details/loadtime-reports/katran.jsonl
    docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/details/loadtime-workdirs/loadtime_2879_5/input.step.0.bin
    docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/receipt.json
    docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/make-corpus.log
    docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/details/loadtime-reports/tracee__monitor.jsonl
    docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/details/loadtime-workdirs/loadtime_19520_10/input.step.0.bin
    docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/receipt.json
    docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/make-corpus.log
    docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/details/loadtime-reports/tetragon__observer.jsonl
    docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/details/loadtime-workdirs/loadtime_2060_103/input.step.0.bin
    docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/receipt.json
    docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/make-corpus.log
    docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/details/loadtime-reports/katran.jsonl
    docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/details/loadtime-workdirs/loadtime_1017_5/input.step.0.bin
    micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json
    micro/results/x86_kvm_micro_20260924_231824_136293/details/result.json
    micro/results/x86_kvm_micro_20260925_002201_525373/details/result.json
    corpus/results/x86_kvm_corpus_20260604_100557_313063/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260529_033517_489159/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260605_145112_835705/details/apps/cilium__agent.json
    corpus/results/x86_kvm_corpus_20260605_160715_129437/details/apps/cilium__agent.json
    corpus/results/aws_arm64_corpus_20260605_080836_924256/details/apps/katran.json
    corpus/results/aws_arm64_corpus_20260605_094729_221231/details/apps/katran.json
    corpus/results/x86_kvm_corpus_20260529_040554_604387/details/apps/cilium__agent.json
    docs/tmp/kop_ablation_20260605_summary.md
    corpus/results/x86_kvm_corpus_20260924_064817_392000/details/loadtime-reports/cilium__agent.jsonl
    corpus/results/x86_kvm_corpus_20260924_074900_275227/details/loadtime-reports/cilium__agent.jsonl
    corpus/results/x86_kvm_corpus_20260924_085901_647044/details/loadtime-reports/cilium__agent.jsonl
    corpus/results/x86_kvm_corpus_20260924_095500_223221/details/loadtime-reports/cilium__agent.jsonl
    corpus/results/x86_kvm_corpus_20260924_114427_040291/details/loadtime-reports/cilium__agent.jsonl
    corpus/results/arm64_qemu_corpus_19700101_000011_781867/details/loadtime-reports/katran.jsonl
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/details/loadtime-reports/katran.jsonl
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_3080_5/input.step.0.bin
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/controls/nullB/metadata.json
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/details/loadtime-reports/cilium__agent.jsonl
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_3653_37/input.step.0.bin
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/controls/nullB/metadata.json
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/details/loadtime-reports/tetragon__observer.jsonl
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/details/loadtime-reports/tracee__monitor.jsonl
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_6620_10/input.step.0.bin
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/controls/nullB/metadata.json
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/details/loadtime-reports/bcc__set.jsonl
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_2183_4/input.step.0.bin
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/controls/nullB/metadata.json
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/receipt.json
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/make-corpus.log
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_2086_2/input.step.0.bin
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/controls/nullB/metadata.json
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/details/loadtime-workdirs/loadtime_2109_103/input.step.0.bin
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/controls/nullA/metadata.json
    docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/controls/nullB/metadata.json
    corpus/results/arm64_qemu_corpus_19700101_000011_741370/details/loadtime-reports/katran.jsonl
)
for rel in "${required[@]}"; do
    [ -e "$VERIFY/$rel" ] || { echo "missing from ZIP: $rel" >&2; exit 1; }
done
if find "$VERIFY" -name .git -print -quit | grep -q .; then
    echo "ZIP unexpectedly contains .git metadata" >&2
    exit 1
fi
# Check project Python and the evaluator entrypoint from the clean extraction.
make -C "$VERIFY" lint
python3 -m py_compile "$VERIFY/docs/artifacts/render_claim_table.py"
python3 "$VERIFY/docs/artifacts/render_claim_table.py" --self-test
python3 "$VERIFY/docs/artifacts/render_claim_table.py" "$VERIFY" > "$VERIFY/claim-table.txt"
python3 -m json.tool "$VERIFY/ARTIFACT_MANIFEST.json" >/dev/null
python3 -m json.tool "$VERIFY/.zenodo.json" >/dev/null

echo "clean-extraction verification OK"
# SeaweedFS may remove an empty output directory during the long staging step.
# Publish the checked archive only after it is complete, recreating that path.
mkdir -p "$OUT_DIR"
cp "$ZIP" "$FINAL_ZIP"
cp "$ZIP.sha256" "$FINAL_ZIP.sha256"
( cd "$OUT_DIR" && sha256sum -c "$(basename "$FINAL_ZIP").sha256" )
echo "wrote $FINAL_ZIP"
echo "wrote $FINAL_ZIP.sha256"
