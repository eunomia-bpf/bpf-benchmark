#!/bin/bash
# =============================================================================
# Master fix + run script
# Run this from a TERMINAL (not via Claude Bash tool) since /tmp/claude-1000 is broken.
#
# Usage:
#   bash /home/yunwei37/workspace/bpf-benchmark/docs/tmp/fix-and-run-all.sh
# =============================================================================
set -euo pipefail

ROOT=/home/yunwei37/workspace/bpf-benchmark
VENV=/home/yunwei37/workspace/.venv
BZIMAGE="$ROOT/vendor/linux-framework/arch/x86/boot/bzImage"
cd "$ROOT"

echo "============================================================"
echo " Step 0: Fix /tmp/claude-1000 permissions"
echo "============================================================"
# This is the root cause of all Claude Bash tool failures
if [ -d /tmp/claude-1000 ]; then
    echo "Directory exists. Fixing permissions..."
    sudo chmod -R a+rwx /tmp/claude-1000 2>/dev/null && echo "  chmod succeeded" || {
        echo "  chmod failed, removing and recreating..."
        sudo rm -rf /tmp/claude-1000
        sudo mkdir -p /tmp/claude-1000
        sudo chmod 1777 /tmp/claude-1000
    }
else
    echo "Directory missing, creating..."
    sudo mkdir -p /tmp/claude-1000
    sudo chmod 1777 /tmp/claude-1000
fi
echo "  /tmp/claude-1000 perms: $(stat -c '%a %U:%G' /tmp/claude-1000)"
echo ""

source "$VENV/bin/activate"
echo "Python: $(which python3)"
echo ""

echo "============================================================"
echo " Step 1: Policy Status Check"
echo "============================================================"
echo "Dense regressor policies have been pre-set to empty (sites: []) by Claude."
echo "  cond_select_dense.yaml: $(wc -l < micro/policies/cond_select_dense.yaml) lines"
echo "  extract_dense.yaml: $(wc -l < micro/policies/extract_dense.yaml) lines"
echo "  endian_swap_dense.yaml: $(wc -l < micro/policies/endian_swap_dense.yaml) lines"
echo ""
echo "Positive benchmarks (unchanged):"
echo "  rotate_dense.yaml: $(wc -l < micro/policies/rotate_dense.yaml) lines (expected 1.167x)"
echo "  addr_calc_stride.yaml: $(wc -l < micro/policies/addr_calc_stride.yaml) lines (expected 1.401x)"
echo "  branch_flip_dense.yaml: $(wc -l < micro/policies/branch_flip_dense.yaml) lines (expected 1.052x)"
echo ""

echo "============================================================"
echo " Step 2: Policy Iteration (VM, 6 dense benchmarks)"
echo "============================================================"
if [ ! -f "$BZIMAGE" ]; then
    echo "ERROR: bzImage not found at $BZIMAGE"
    echo "Skipping VM benchmark."
else
    echo "Running policy iteration script..."
    bash docs/tmp/run-policy-iteration.sh
    echo "Policy iteration DONE."
fi
echo ""

echo "============================================================"
echo " Step 3: Corpus Post-Fix Rerun"
echo "============================================================"
echo "Removing old packet cache..."
rm -f micro/generated-inputs/corpus_dummy_packet_64.bin
echo "  Deleted."

echo "Running corpus post-fix rerun..."
bash run_corpus_rerun.sh
echo "Corpus rerun DONE."
echo ""

echo "============================================================"
echo " DONE"
echo "============================================================"
echo "Results:"
echo "  Policy iteration log: $ROOT/docs/tmp/policy-iteration-rounds.md"
echo "  Corpus JSON: $ROOT/corpus/results/corpus_post_fix_20260313.json"
echo "  Corpus MD: $ROOT/docs/tmp/corpus-post-fix-rerun-raw.md"
