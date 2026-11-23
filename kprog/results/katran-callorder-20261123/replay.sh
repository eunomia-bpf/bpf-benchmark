#!/bin/bash
# Katran per call: native 145.9 ns at 8430daa81 (x86_kvm_corpus_20261122_002150_663253), 179.8 ns at
# dcf4a1aef (x86_kvm_corpus_20261123_125701_042461); eBPF 180 ns in both. This links the 8430daa81 Katran
# object with the 8430daa81 linker, offline, and prints the lookup site the linker gives each native
# bpf_map_lookup_elem call. Source of both is exported from git into /tmp; nothing in the tree changes.
# Plan: the Katran link plan saved 2026-11-16 (its lookup_sites come from the frozen eBPF object).
set -e
D=/tmp/katran-callorder-8430; R=/workspaces/repository
P=$R/kprog/results/shared-hash-regression-20261116/katran-shared.link-plan.json
rm -rf $D; mkdir -p $D/src
cd $R
for f in Cargo.toml Cargo.lock; do git show 8430daa81:kprog/x86/native_lab/native_link/$f > $D/$f; done
for f in $(git ls-tree --name-only 8430daa81 kprog/x86/native_lab/native_link/src/); do git show 8430daa81:$f > $D/src/$(basename $f); done
# one diagnostic line per lookup: the native map name the linker sees and the site it takes
python3 - $D/src/x86.rs <<'PY'
import sys
p = sys.argv[1]; s = open(p).read()
old = '''                        lookup_call_specs.insert(site_key, spec.clone());
                        match spec.kind {'''
new = '''                        lookup_call_specs.insert(site_key, spec.clone());
                        eprintln!("DIAG lookup call={} sym={} off={:#x} native_map={:?} site={} kind={:?} site_map={:?}", native_call_index, sym.name, local_ip, native_map_name, site_label, spec.kind, spec.map_name);
                        match spec.kind {'''
assert s.count(old) == 1
open(p, 'w').write(s.replace(old, new))
PY
(cd $D && CARGO_TARGET_DIR=$D/target nice -n 5 taskset -c 8-23 cargo build --release --offline > $D/build.log 2>&1)
# the 8430daa81 Katran compile (vendor/bpf/Makefile at 8430daa81: KATRAN_NATIVE_CFLAGS, Katran's own
# bpf_helpers.h with id-valued helper pointers; the same flags as today without -include katran-helpers.h)
cd $R/vendor/bpf
FLAGS=$(make -n ARCH=x86 OUT=$D/out $D/out/native/katran/balancer.native.o | grep '"clang' | sed 's/^"clang-18" *//; s/-include "[^"]*katran-helpers.h"//; s/\\$//')
INC='-I/workspaces/repository/vendor/bpf/katran -I/workspaces/repository/vendor/bpf/katran/katran/lib/linux_includes -I/usr/include -I/usr/include/x86_64-linux-gnu'
nice -n 5 clang-18 $FLAGS $INC -o $D/old.o katran/katran/lib/bpf/balancer.c
L=$D/target/release/native-link
$L --input $D/old.o --symbol balancer_ingress --mode proof --output $D/old.proof.o > $D/proof.log 2>&1
$L --input $D/old.proof.o --symbol balancer_ingress --mode kernel --output $D/old.blob --output-relocs $D/old.relocs \
  --output-map-patches $D/old.maps --output-abi $D/old.abi --link-plan $P > $D/kernel.log 2>&1
objdump -dr --no-show-raw-insn $D/old.proof.o > $D/old.proof.dis
python3 - $D/kernel.log <<'PY'
import re, sys
rows = [l for l in open(sys.argv[1]) if l.startswith('DIAG')]
same = 0
for l in rows:
    nm, site, kind, sm = re.search(r'native_map=(\S+) site=(\S+) kind=(\S+) site_map=(\S+)', l).groups()
    if nm.startswith('Some') and nm == sm:
        same += 1
        continue
    print(l.strip()[5:])
print('lookups', len(rows), 'matched by map name', same)
PY
echo "blob $(stat -c %s $D/old.blob) bytes"
