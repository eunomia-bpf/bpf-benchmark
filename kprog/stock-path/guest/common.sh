# Guest setup shared by the stock-path cases. Sourced; expects OUT.
R=/workspaces/repository
CK=${KPROG_STOCK_ROOT:-/mnt}
ARCH=${KPROG_STOCK_ARCH:-1}
ENDPOINT=${KPROG_STOCK_ENDPOINT:-bpf_x86_native_lab}
LOADER=${KPROG_STOCK_LOADER:-$CK/loader/build}
MODULE=${KPROG_STOCK_MODULE:-$CK/mod/bpf_kprog_stock.ko}
mkdir -p "$OUT"
mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
insmod "$MODULE" || exit 1
NATIVE_LINK=${KPROG_STOCK_NATIVE_LINK:-$R/kprog/x86/native_lab/native_link/target/release/native-link}
export KPROG_STOCK_DUMP_DIR=$OUT PATH=/usr/lib/llvm-18/bin:$PATH CLANG=$R/kprog/stock-path/bin/clang PYTHONDONTWRITEBYTECODE=1 BPFREJIT_NATIVE_LINK_BINARY=$NATIVE_LINK
start_service() {
    python3 $R/kprog/trusted_service.py --arch "$ARCH" \
        --endpoint /sys/kernel/debug/$ENDPOINT/specializer \
        --state "$OUT/requests" \
        --native-link "$NATIVE_LINK" \
        --loader "$LOADER/trusted-native-loader" > "$OUT/service.log" 2>&1 &
    SERVICE=$!
    for i in $(seq 1 240); do grep -q '"ready"' "$OUT/service.log" 2>/dev/null && return 0; sleep 0.5; done
    echo "service did not become ready"; cat "$OUT/service.log"; exit 1
}
stop_service() {
    while compgen -G "$OUT/requests/request-*" >/dev/null && kill -0 "$SERVICE" 2>/dev/null; do sleep 0.1; done
    kill "$SERVICE" 2>/dev/null || true
    wait "$SERVICE" 2>/dev/null || true
    dmesg > "$OUT/dmesg" 2>&1 || true
}
