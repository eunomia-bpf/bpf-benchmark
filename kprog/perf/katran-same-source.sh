#!/bin/bash
# Build Katran's native objects from the untouched upstream sources.
#
# The eBPF arm's own frontend (vendor/Makefile:32) compiles the upstream source to host
# IR; a lowering step replaces each public XDP/TC context access with the physical one the
# verifier's converter produces; native codegen follows. Nothing in vendor/bpf/katran is
# edited: the source, the headers and the MICRO_NATIVE context prototypes stay as upstream.
#
# Usage: katran-same-source.sh <output dir>
#   Requires the lowering tool and its rule tables:
#     kprog/perf/native-context/build-x86/socket-context-lower (make -f
#       kprog/perf/native-context/Makefile socket-context-check builds it)
#   The xdp/skb rule tables are passed explicitly; see the README next to this script for
#   where their offsets come from and why lane perf's tool is the place for them.
set -euo pipefail

OUT=${1:?output directory}
ROOT=/workspaces/repository
UPSTREAM=$ROOT/vendor/repos/katran
SHIPPED=$ROOT/vendor/build/native-bpf/x86/7.0.0-rc2+/native/katran
LOWER=${LOWER:-/var/tmp/kprog-tmp/perf/socket-context/socket-context-lower}
# The rule tables: lane perf's packet tables (make -f kprog/perf/native-context/Makefile
# packet-context-check writes them under /var/tmp/kprog-tmp/perf/packet-context), or the
# copies kept beside the evidence. Both name their files differently, so accept either.
RULES=${RULES:-/var/tmp/kprog-tmp/perf/packet-context}
first_existing() { for f in "$@"; do [ -f "$f" ] && { printf '%s' "$f"; return 0; }; done; return 1; }
PUBLIC=$(first_existing "$RULES/public-layout.json" "$RULES/public.json") \
  || { echo "no public layout table under $RULES" >&2; exit 1; }
PHYSICAL=$(first_existing "$RULES/physical-layout.json" "$RULES/physical.json") \
  || { echo "no physical layout table under $RULES" >&2; exit 1; }
LINK=$ROOT/kprog/x86/native_lab/native_link/target/release/native-link
CLANG=clang-18

# The eBPF arm's frontend, verbatim from vendor/Makefile:32, plus -fPIC so the .maps
# globals stay non-dso_local and the map reference lowers to the GOTPCRELX load the loader
# patches (a `lea`/PC32 form would take the address of an embedded copy instead).
FRONTEND=(-I"$UPSTREAM" -I"$UPSTREAM/katran/lib/linux_includes" -DDEBUG -D__KERNEL__
  -Wno-unused-value -Wno-pointer-sign -Wno-compare-distinct-pointer-types
  -O2 -emit-llvm -c -g -fPIC)

# Native codegen. The IR keeps "target-features"="+sse,+sse2", which would let
# llvm.memset/memcpy expand to movdqa/pxor and break the SIMD-free rule for native code, so
# the attribute is stripped first. Without -march=native: the IR round trip fixes the CPU.
CODEGEN=(-target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls
  -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector
  -fno-jump-tables)

install -d "$OUT"

# program:source
for pair in balancer_ingress:balancer healthcheck_encap:healthchecking_ipip xdp_root:xdp_root; do
  symbol=${pair%%:*}; src=${pair##*:}
  "$CLANG" "${FRONTEND[@]}" "$UPSTREAM/katran/lib/bpf/$src.c" -o "$OUT/$src.bc"
  "$LOWER" "$OUT/$src.bc" --public-layout "$PUBLIC" \
    --physical-layout "$PHYSICAL" -o "$OUT/$src.lowered.bc"
  llvm-dis-18 "$OUT/$src.lowered.bc" -o "$OUT/$src.lowered.ll"
  sed -E 's/"target-features"="[^"]*"//; s/"target-cpu"="[^"]*"//' \
    "$OUT/$src.lowered.ll" > "$OUT/$src.notf.ll"
  "$CLANG" "${CODEGEN[@]}" -c "$OUT/$src.notf.ll" -o "$OUT/$src.native.o"
  "$LINK" --input "$OUT/$src.native.o" --symbol "$symbol" \
    --output "$OUT/$symbol.same-source.o" --mode proof
  "$LINK" --input "$SHIPPED/$src.native.o" --symbol "$symbol" \
    --output "$OUT/$symbol.shipped.o" --mode proof
  if cmp -s "$OUT/$symbol.same-source.o" "$OUT/$symbol.shipped.o"; then
    verdict=IDENTICAL
  else
    verdict="differs ($(stat -c%s "$OUT/$symbol.shipped.o") shipped, \
$(stat -c%s "$OUT/$symbol.same-source.o") same-source)"
  fi
  sse=$(objdump -d --no-show-raw-insn "$OUT/$src.native.o" | grep -c xmm || true)
  printf '%-20s %-40s sse=%s\n' "$symbol" "$verdict" "$sse"
done