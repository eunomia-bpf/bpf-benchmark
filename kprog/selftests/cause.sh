#!/bin/sh
# Read the cause of one refused program from the service's own archive.
# Usage: cause.sh <object-stem>   (in the guest that boots the lab kernel)
set -u
ROOT=/workspaces/repository
p=$1
d=$(mktemp -d)
python3 "$ROOT/kprog/trusted_service.py" --arch 1 \
    --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
    --state "$d" \
    --native-link "$ROOT/kprog/x86/native_lab/native_link/target/release/native-link" \
    --loader "$ROOT/kprog/libnativeloader/build/trusted-native-loader" \
    > "$d.log" 2>&1 &
sleep 4
"$ROOT/runner/build-llvmbpf/micro_exec" run-native-kernel \
    --program "$ROOT/kprog/selftests/build/$p.bpf.o" \
    --native-program "$ROOT/kprog/selftests/build/$p.native.o" \
    --inner-repeat 1 --native-kernel-prog-type sched_cls >/dev/null 2>&1
sleep 2
echo "== $p"
for a in "$d"/*.tar.gz; do
    tar xzf "$a" -C "$d" 2>/dev/null && break
done
grep -h -o 'Error: [^"]*' "$d"/request/load.stdout 2>/dev/null | head -2
grep -h -o 'invalid [a-z ]*stack[^"]*' "$d"/request/load.stderr 2>/dev/null |
    head -2
python3 -c "import json,sys;print(json.load(open('$d/request/error.json'))['error'][:160])" 2>/dev/null