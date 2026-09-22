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
ZIP="$OUT_DIR/$VERSION.zip"
STAGE="$(mktemp -d)"
VERIFY=""
trap 'rm -rf "$STAGE" "${VERIFY:-}"' EXIT
COMMIT="$(git -C "$ROOT_DIR" rev-parse HEAD)"
rm -f "$ZIP" "$ZIP.sha256"
echo "packaging $VERSION at $COMMIT"

# The parent repository is archived from HEAD, never from the working tree.
git -C "$ROOT_DIR" archive --format=tar HEAD -- . \
    ':(exclude)corpus/results' \
    ':(exclude)micro/results' \
    ':(exclude)tests/results' \
    ':(exclude)docs/tmp' \
    ':(exclude)docs/source-opt' \
    ':(exclude)docs/reference' \
    ':(exclude)docs/research' \
    ':(exclude)docs/ebpf27-bpfoptbench' \
    ':(exclude)docs/kprog-simulator-in-ebpf' \
    ':(exclude)docs/speculative-optimization' \
    ':(exclude)docs/paper' \
    ':(exclude)vendor/academic-writing-skills' \
    ':(exclude)vendor/libbpf' \
    ':(exclude)vendor/linux-framework' \
    ':(exclude)vendor/llvmbpf' \
    ':(exclude)vendor/repos' \
    ':(exclude)llvm-backend/llvm' \
    | tar -x -C "$STAGE"

pin_for() {
    git -C "$ROOT_DIR" ls-tree HEAD -- "$1" | awk '{print $3}'
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
    mkdir -p "$STAGE/$path"
    git -C "$ROOT_DIR/$path" archive --format=tar "$pinned" | tar -x -C "$STAGE/$path"
    echo "  embedded $path @ $pinned"
}

# Every source submodule required by the supported proof, microbenchmark, and
# six-application corpus paths is embedded at the exact superproject pin.
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

# Add only the five raw paper-result datasets consumed by the plotting scripts.
RESULTS=(
    micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json
    micro/results/x86_kvm_micro_20260526_210351_224315/details/result.json
    micro/results/aws_arm64_micro_20260606_001225_821028/details/result.json
    micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json
    micro/results/aws_arm64_micro_20260606_063319_954947/details/result.json
)
echo "embedding paper-result datasets:"
for rel in "${RESULTS[@]}"; do
    mkdir -p "$STAGE/$(dirname "$rel")"
    git -C "$ROOT_DIR" show "HEAD:$rel" > "$STAGE/$rel"
    echo "  $rel"
done

cat > "$STAGE/README-ARTIFACT.md" <<EOF
# BPF-Ext ATC 2026 artifact $VERSION

This is the single archival ZIP for accepted ATC 2026 paper #1160,
“BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native Operations.”
Start with [docs/atc26-artifact-evaluation.md](docs/atc26-artifact-evaluation.md).
The archive contains the exact source trees needed by the documented proof,
microbenchmark, and six-application KVM paths, plus the five raw paper-result
JSON datasets read by the included plotting scripts. ARTIFACT_MANIFEST.json
records the superproject commit and every submodule pin. Historical bulk result
trees are omitted; the guide gives the commands that regenerate them.
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
manifest = {
    'artifact': 'BPF-Ext ATC 2026 artifact for accepted paper #1160',
    'version': os.environ['VERSION_VALUE'],
    'superprojectCommit': os.environ['COMMIT_VALUE'],
    'entryPoint': 'docs/atc26-artifact-evaluation.md',
    'submodules': submodules,
    'paperResultFiles': [
        'micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json',
        'micro/results/x86_kvm_micro_20260526_210351_224315/details/result.json',
        'micro/results/aws_arm64_micro_20260606_001225_821028/details/result.json',
        'micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json',
        'micro/results/aws_arm64_micro_20260606_063319_954947/details/result.json',
    ],
    'omittedGeneratedData': ['corpus/results', 'micro/results (except listed files)', 'tests/results'],
}
(stage / 'ARTIFACT_MANIFEST.json').write_text(json.dumps(manifest, indent=2) + '\n')
(stage / '.submodules.tsv').unlink()
PY

( cd "$STAGE" && zip -q -r -X "$ZIP" . )
sha256sum "$ZIP" > "$ZIP.sha256"

VERIFY="$(mktemp -d)"
unzip -q "$ZIP" -d "$VERIFY"
required=(
    README-ARTIFACT.md ARTIFACT_MANIFEST.json LICENSE THIRD_PARTY_NOTICES.md
    CITATION.cff .zenodo.json CHANGELOG.md Makefile
    docs/atc26-artifact-evaluation.md docs/artifacts/render_claim_table.py
    docs/paper/scripts/plot_evaluation_koperation.py
    native-sim/formal/lean-toolchain vendor/llvmbpf/CMakeLists.txt
    vendor/libbpf/src/libbpf.c vendor/linux-framework/Makefile
    llvm-backend/llvm/llvm/CMakeLists.txt vendor/repos/katran/CMakeLists.txt
    vendor/repos/tracee/Makefile vendor/repos/tetragon/Makefile
    vendor/repos/cilium/Makefile vendor/repos/bcc/CMakeLists.txt
    vendor/repos/opentelemetry-ebpf-profiler/Makefile
    micro/results/x86_kvm_micro_20260519_114214_364050/details/result.json
)
for rel in "${required[@]}"; do
    [ -e "$VERIFY/$rel" ] || { echo "missing from ZIP: $rel" >&2; exit 1; }
done
if find "$VERIFY" -name .git -print -quit | grep -q .; then
    echo "ZIP unexpectedly contains .git metadata" >&2
    exit 1
fi
python3 "$VERIFY/docs/artifacts/render_claim_table.py" --self-test
python3 "$VERIFY/docs/artifacts/render_claim_table.py" "$VERIFY" > "$VERIFY/claim-table.txt"
python3 -m json.tool "$VERIFY/ARTIFACT_MANIFEST.json" >/dev/null
python3 -m json.tool "$VERIFY/.zenodo.json" >/dev/null

echo "clean-extraction verification OK"
echo "wrote $ZIP"
echo "wrote $ZIP.sha256"
