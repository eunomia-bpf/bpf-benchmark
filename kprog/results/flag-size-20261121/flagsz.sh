#!/bin/bash
# Coordinator 2026-11-21: executable bytes per app for one flag set at a time (operator 2026-11-17: "代码量少一半",
# "编译参数所有 app 统一."). Natives build into a scratch BUILD tree, so the image inputs stay as they are.
set -u
D=/workspaces/kprog-raw/coordinator/flagsz-20261121
mkdir -p $D
cd /workspaces/repository/vendor/bpf
COMMON="-g -fPIC -c -fomit-frame-pointer -march=native -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -Xclang -fembed-bitcode=all -Wno-unknown-attributes -Wno-compare-distinct-pointer-types"
for lvl in O3 Os Oz; do
  S=/tmp/flagsz/$lvl
  echo "$(date -u +%FT%TZ) $lvl start" >> $D/progress.log
  nice -n 19 taskset -c 16-23 make -j8 ARCH=x86 BUILD=$S NATIVE_CFLAGS="-$lvl $COMMON" \
    native-katran native-bcc native-otel native-cilium native-tracee native-tetragon > $D/build-$lvl.log 2>&1
  echo "$(date -u +%FT%TZ) $lvl rc=$?" >> $D/progress.log
  python3 /workspaces/repository/kprog/results/flag-tuning-20261117/textsize.py $S/x86/stage > $D/textsize-$lvl.txt 2>&1
done
echo "$(date -u +%FT%TZ) done" >> $D/progress.log
