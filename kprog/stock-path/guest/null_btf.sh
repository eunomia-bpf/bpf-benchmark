#!/bin/bash
# Step 3: LSM file_open native program called with a valid and a NULL file.
OUT=/var/tmp/kprog-tmp/CK/run/null_btf
. /workspaces/repository/kprog/stock-path/guest/common.sh
start_service
F=$CK/fixture
BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 $F/probe $F/native.o $F/module/native_load_fault_module.ko > "$OUT/probe.out" 2> "$OUT/probe.err"
echo "probe rc=$?" | tee "$OUT/probe.rc"
cat "$OUT/probe.out" "$OUT/probe.err"
stop_service
echo guest-alive-after-null
