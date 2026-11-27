#!/bin/bash
# Compile every OOM-list row with no address-space cap, one at a time.
prlimit --as=unlimited --pid $$ >/dev/null 2>&1
cd /workspaces/kprog-raw/omp/arm64-coverage-20261125 || exit 1
out=/tmp/uncapped_results.tsv; : > "$out"
while IFS=$'\t' read -r d src b; do
  [ -n "$d" ] || continue
  s=$(date +%s)
  ( flock -s 9
    /usr/lib/llvm-18/bin/clang -include /workspaces/repository/kprog/stock-path/include/stock_native_input.h \
      -w -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 \
      -I /workspaces/repository/vendor/libbpf/include/uapi \
      -I /workspaces/repository/vendor/libbpf/src -I /usr/include/x86_64-linux-gnu \
      -c "$src" -o "/tmp/unc_$(echo "$d" | tr / _).o" ) 9>/tmp/omp-timing.lock > "/tmp/unc_$(echo "$d" | tr / _).log" 2>&1
  printf '%s\t%s\t%s\t%s\n' "$d" "$b" "$?" "$(( $(date +%s) - s ))" >> "$out"
done < /tmp/oomlist.txt
echo DONE
