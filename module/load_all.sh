#!/bin/bash
# Load all kinsn modules for the current architecture.
# Run inside VM after boot. Idempotent: skips already-loaded modules.
set -e
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
ARCH=$(uname -m)
case "$ARCH" in
    x86_64) MODULE_DIR="$SCRIPT_DIR/x86" ;;
    aarch64) MODULE_DIR="$SCRIPT_DIR/arm64" ;;
    *) echo "Unsupported arch: $ARCH"; exit 1 ;;
esac
loaded=0
total=0
for ko in "$MODULE_DIR"/*.ko; do
    [ -f "$ko" ] || continue
    mod=$(basename "$ko" .ko)
    if [ "$mod" = "bpf_barrier" ]; then
        continue
    fi
    total=$((total + 1))
    if ! lsmod | grep -q "^${mod} "; then
        if ! insmod "$ko"; then
            echo "ERROR: Failed to load $mod" >&2
            exit 1
        fi
        echo "Loaded $mod"
    fi
    # Count as loaded if BTF entry exists (module registered successfully).
    if [ -e "/sys/kernel/btf/${mod}" ]; then
        loaded=$((loaded + 1))
    fi
done
echo "kinsn modules: ${loaded}/${total} loaded"
