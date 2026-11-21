#!/bin/bash
# Lines added and removed on the performance path against 2026-05-29 (82ec89cb4), outside verify.
# Operator 2026-11-21: "应该在 5/29 基础上, 除了 verify 的部分以外整个路径 1000 行以内的 fix 和优化"
# Verify-side files (the checked configuration, dd6559b54 and later) are counted apart, and so are
# the vmlinux headers generated from the one kernel's BTF. Mixed files: the checked-path lines in
# bpfopt/shim/shim_native_loader.h (REQUIRE_BOUND_PROOF), vendor/bpf/Makefile (kprog-perf-context-lto
# rule) and native_loader.cpp (the hand-off and moved declarations) are listed by the last block.
cd /workspaces/repository
C=82ec89cb4
VERIFY='native_loader_trusted|native_loader_internal\.hpp|native_loader_(context_lto|data_layout|entry_data|function_bodies|helper_query|kfunc|source_maps|timings|lto|subprocess)\.hpp|native-lpm\.h'
pairs() {
  for f in Cargo.toml Cargo.lock src/main.rs src/x86.rs; do
    echo "native-sim/x86/native_lab/native_link/$f kprog/x86/native_lab/native_link/$f"; done
  for f in $(cd kprog/libnativeloader && git ls-files -co --exclude-standard . | grep -vE '^build/'); do
    echo "native-sim/libnativeloader/$f kprog/libnativeloader/$f"; done
  echo "module/x86/bpf_x86_native_lab.c kprog/perf/direct-native/bpf_x86_native_lab.c"
  for f in $( (git ls-tree -r --name-only $C bpfopt/shim; git ls-files -co --exclude-standard bpfopt/shim) | grep -vE 'build|\.so$|/selftest$|/selftest_full$' | sort -u); do echo "$f $f"; done
  for f in $( (git diff --name-only $C -- vendor/bpf; git ls-files -o --exclude-standard vendor/bpf) | sort -u | grep -vE 'vmlinux|/targets/|^vendor/bpf/\{'); do echo "$f $f"; done
}
pa=0; pd=0; va=0; vd=0
while read old new; do
  a=/dev/null; b=/dev/null
  git cat-file -e $C:$old 2>/dev/null && { git show $C:$old > /tmp/tally.old; a=/tmp/tally.old; }
  [ -f "$new" ] && b=$new
  [ "$a" = /dev/null ] && [ "$b" = /dev/null ] && continue
  read ad de _ < <(git diff --no-index --numstat $a $b | head -1)
  [ -z "$ad" ] && continue
  if [[ $new =~ $VERIFY ]]; then va=$((va+ad)); vd=$((vd+de)); tag=verify; else pa=$((pa+ad)); pd=$((pd+de)); tag=path; fi
  printf '%6s %6s %-6s %s\n' "$ad" "$de" "$tag" "$new"
done < <(pairs)
echo "PATH TOTAL added=$pa removed=$pd   (verify-side files: added=$va removed=$vd)"
echo "-- checked-path lines inside path files (verify side, subtract from PATH):"
echo "   shim_native_loader.h REQUIRE_BOUND_PROOF: $(git diff --no-index --numstat <(git show $C:bpfopt/shim/shim_native_loader.h) bpfopt/shim/shim_native_loader.h | cut -f1)"
echo "   vendor/bpf/Makefile kprog-perf-context-lto rule: $(grep -cE 'PERF_CONTEXT_LTO|perf_context_lto|llvm-config-18|libbpf.a -lelf' vendor/bpf/Makefile)"
echo "   native_loader.cpp hand-off and moved declarations (dd6559b54): $(git show dd6559b54 --numstat -- kprog/libnativeloader/src/native_loader.cpp | tail -1 | cut -f1,2 | tr '\t' '/')"
echo "-- generated from the one kernel's BTF (not hand-written):"
for f in vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h vendor/bpf/tetragon/bpf/include/vmlinux_generated_x86.h; do
  git diff --numstat $C -- $f | awk '{printf "%6s %6s %s\n",$1,$2,$3}'; done
