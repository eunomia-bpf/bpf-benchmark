#!/bin/bash
# Corpus post-fix rerun script (2026-03-13)
#
# Prerequisites:
#   - bzImage already at vendor/linux-framework/arch/x86/boot/bzImage (build #38, BEXTR fix)
#   - vng available at ~/.local/bin/vng
#   - Python venv at /home/yunwei37/workspace/.venv
#
# This script runs corpus v5-vm-batch with:
#   - Fixed valid IPv4+TCP packet (correct checksum, from corpus.py)
#   - --use-policy: apply v3 policy files from corpus/policies/
#     (these auto-generated policies skip CMOV, keep rotate/lea/extract/endian/bflip)
#   - --skip-build: use existing bzImage from build #38
#
set -euo pipefail

REPO=/home/yunwei37/workspace/bpf-benchmark
cd "$REPO"

# Activate venv
source /home/yunwei37/workspace/.venv/bin/activate

echo "=== Step 1: Remove old packet cache ==="
rm -f micro/generated-inputs/corpus_dummy_packet_64.bin
echo "Deleted old packet cache"

echo "=== Step 2: Build micro ==="
make -C micro 2>&1 | tail -10

echo "=== Step 3: Build scanner ==="
cmake --build scanner/build --target bpf-jit-scanner -j 2>&1 | tail -5

echo "=== Step 4: Run corpus v5-vm-batch (use-policy mode) ==="
# Output will be timestamped by results_layout.py automatically as corpus_v5_vm_batch_authoritative_20260313.json
# But we override to our specific name for clarity
OUTPUT_JSON="corpus/results/corpus_post_fix_20260313.json"
OUTPUT_MD="docs/tmp/corpus-post-fix-rerun-raw.md"

python3 micro/driver.py corpus v5-vm-batch \
    --kernel-image vendor/linux-framework/arch/x86/boot/bzImage \
    --btf-custom-path vendor/linux-framework/vmlinux \
    --skip-build \
    --use-policy \
    --repeat 200 \
    --output-json "$OUTPUT_JSON" \
    --output-md "$OUTPUT_MD" \
    2>&1 | tee /tmp/corpus_rerun_20260313.log

echo ""
echo "=== Done ==="
echo "JSON output: $REPO/$OUTPUT_JSON"
echo "MD output:   $REPO/$OUTPUT_MD"
echo "Log:         /tmp/corpus_rerun_20260313.log"
