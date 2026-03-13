#!/bin/bash
# Master script: fix permissions, run policy iteration, run corpus rerun, summarize
# Run as: bash docs/tmp/run-all-pending-tasks.sh
set -euo pipefail

ROOT=/home/yunwei37/workspace/bpf-benchmark
VENV=/home/yunwei37/workspace/.venv
cd "$ROOT"
source "$VENV/bin/activate"

echo "=== Step 0: Fix /tmp/claude-1000 permissions ==="
# The /tmp/claude-1000 directory has bad permissions blocking Claude's Bash tool.
# Fix it so subsequent Claude sessions work.
if [ -d /tmp/claude-1000 ]; then
    sudo chmod -R a+rwx /tmp/claude-1000 2>/dev/null && echo "Fixed /tmp/claude-1000" || {
        echo "chmod failed, trying rm+mkdir"
        sudo rm -rf /tmp/claude-1000
        sudo mkdir -p /tmp/claude-1000
        sudo chmod 1777 /tmp/claude-1000
        echo "Recreated /tmp/claude-1000"
    }
else
    sudo mkdir -p /tmp/claude-1000
    sudo chmod 1777 /tmp/claude-1000
    echo "Created /tmp/claude-1000"
fi
echo "Current perms: $(stat -c '%a %U %G' /tmp/claude-1000)"

echo ""
echo "=== Step 1: Policy iteration (dense benchmark optimization) ==="
echo "Running docs/tmp/run-policy-iteration.sh ..."
bash docs/tmp/run-policy-iteration.sh
echo "Policy iteration DONE."

echo ""
echo "=== Step 2: Corpus post-fix rerun ==="
echo "Running run_corpus_rerun.sh ..."
bash run_corpus_rerun.sh
echo "Corpus rerun DONE."

echo ""
echo "=== Step 3: Summary ==="
echo "All tasks completed."
echo "Results:"
echo "  - Policy iteration log: docs/tmp/policy-iteration-rounds.md"
echo "  - Corpus rerun: corpus/results/corpus_post_fix_20260313.json"
echo "  - Corpus MD: docs/tmp/corpus-post-fix-rerun-raw.md"
