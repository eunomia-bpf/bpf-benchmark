#!/bin/bash
# Step 2: one native program through submit, kernel copy, service, verifier, JIT.
OUT=/mnt/run/small
. /workspaces/repository/kprog/stock-path/guest/common.sh
start_service
$CK/loader/build/trusted-service-client $R/kprog/libnativeloader/build/trusted-native.o > "$OUT/client.out" 2> "$OUT/client.err"
echo "client rc=$?" | tee "$OUT/client.rc"
cat "$OUT/client.out" "$OUT/client.err"
stop_service
ls "$OUT/requests" | head
