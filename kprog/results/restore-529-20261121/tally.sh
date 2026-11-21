#!/bin/bash
# Lines added and removed on the performance path against 2026-05-29 (82ec89cb4), outside verify.
# Operator 2026-11-21: "应该在 5/29 基础上, 除了 verify 的部分以外整个路径 1000 行以内的 fix 和优化"
# Generated vmlinux headers (dumped from the one kernel's BTF) are listed apart.
cd /workspaces/repository
C=82ec89cb4
pairs() {
  for f in Cargo.toml Cargo.lock src/main.rs src/x86.rs; do
    echo "native-sim/x86/native_lab/native_link/$f kprog/x86/native_lab/native_link/$f"; done
  for f in $(cd kprog/libnativeloader && git ls-files -co --exclude-standard . | grep -vE '^build/|native_loader_lto.hpp|native_loader_subprocess.hpp|native-lpm.h'); do
    echo "native-sim/libnativeloader/$f kprog/libnativeloader/$f"; done
  echo "module/x86/bpf_x86_native_lab.c kprog/perf/direct-native/bpf_x86_native_lab.c"
  for f in $(git ls-tree -r --name-only $C bpfopt/shim | grep -vE '/selftest$|/selftest_full$'; git ls-files -co --exclude-standard bpfopt/shim | grep -vE 'build|\.so$|/selftest$|/selftest_full$'); do echo "$f $f"; done | sort -u
  for f in $( (git diff --name-only $C -- vendor/bpf; git ls-files -o --exclude-standard vendor/bpf) | sort -u | grep -vE 'vmlinux|/targets/|^vendor/bpf/\{|native-lpm.h'); do echo "$f $f"; done
}
total_add=0; total_del=0
while read old new; do
  a=/dev/null; b=/dev/null
  git cat-file -e $C:$old 2>/dev/null && { git show $C:$old > /tmp/tally.old; a=/tmp/tally.old; }
  [ -f "$new" ] && b=$new
  [ "$a" = /dev/null ] && [ "$b" = /dev/null ] && continue
  read ad de _ < <(git diff --no-index --numstat $a $b | head -1)
  [ -z "$ad" ] && continue
  printf '%6s %6s %s\n' "$ad" "$de" "$new"
  total_add=$((total_add+ad)); total_del=$((total_del+de))
done < <(pairs)
echo "TOTAL added=$total_add removed=$total_del"
echo "-- generated from the one kernel's BTF (not hand-written):"
for f in vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h vendor/bpf/tetragon/bpf/include/vmlinux_generated_x86.h; do
  git diff --numstat $C -- $f | awk '{printf "%6s %6s %s\n",$1,$2,$3}'; done
