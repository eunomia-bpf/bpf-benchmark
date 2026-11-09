#!/bin/bash
# Step 4: the 38-case x86 safety suite.
OUT=/var/tmp/kprog-tmp/CK/run/safety
. /workspaces/repository/kprog/stock-path/guest/common.sh
python3 $R/kprog/stock-path/run_safety.py check --out "$OUT"
echo "safety rc=$?"
dmesg > "$OUT/dmesg" 2>&1 || true
