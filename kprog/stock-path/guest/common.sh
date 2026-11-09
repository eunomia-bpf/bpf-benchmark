# Guest setup shared by the stock-path cases. Sourced; expects OUT.
R=/workspaces/repository
CK=/mnt
mkdir -p "$OUT"
mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
insmod $CK/mod/kprog_stock.ko || exit 1
export KPROG_STOCK_DUMP_DIR=$OUT PATH=/usr/lib/llvm-18/bin:$PATH CLANG=$R/kprog/stock-path/bin/clang PYTHONDONTWRITEBYTECODE=1 BPFREJIT_NATIVE_LINK_BINARY=$R/kprog/x86/native_lab/native_link/target/release/native-link
start_service() {
    python3 $R/kprog/trusted_service.py --arch 1 \
        --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
        --state "$OUT/requests" \
        --native-link $R/kprog/x86/native_lab/native_link/target/release/native-link \
        --loader $CK/loader/build/trusted-native-loader > "$OUT/service.log" 2>&1 &
    SERVICE=$!
    for i in $(seq 1 240); do grep -q '"ready"' "$OUT/service.log" 2>/dev/null && return 0; sleep 0.5; done
    echo "service did not become ready"; cat "$OUT/service.log"; exit 1
}
stop_service() {
    kill "$SERVICE" 2>/dev/null || true
    wait "$SERVICE" 2>/dev/null || true
    dmesg > "$OUT/dmesg" 2>&1 || true
}
