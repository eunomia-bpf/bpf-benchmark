#!/bin/bash
# Fix /tmp/claude-1000 permissions and run corpus rerun
# This needs to be run as root or with sudo if /tmp/claude-1000 is owned by root

# Option 1: Fix /tmp/claude-1000 directory if owned by root
if [ -d /tmp/claude-1000 ]; then
    # Check ownership
    OWNER=$(stat -c '%U' /tmp/claude-1000 2>/dev/null || echo "unknown")
    echo "Owner of /tmp/claude-1000: $OWNER"
    if [ "$OWNER" != "$(whoami)" ]; then
        echo "Need to fix permissions: sudo chmod a+rwx /tmp/claude-1000"
        sudo chmod a+rwx /tmp/claude-1000 2>/dev/null || echo "sudo failed, try manually"
    fi
fi

# Option 2: Just run the corpus rerun directly
cd /home/yunwei37/workspace/bpf-benchmark
bash run_corpus_rerun.sh
