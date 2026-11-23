#!/bin/bash
# Cilium on the 8430daa81 linker: compile bpf_lxc.c with the 8430daa81 headers (exported from git into
# /tmp), link every bpf_lxc program that has a saved 2026-11-16 link plan with the 8430daa81 linker built
# by ../katran-callorder-20261123/replay.sh (its diagnostic line per lookup), and list the lookups that
# take a site of another map by call order. Nothing in the tree changes.
set -e
R=/workspaces/repository; X=/tmp/cilium-callorder-8430; V=$X/v/vendor/bpf
L=/tmp/katran-callorder-8430/target/release/native-link
PLANS=/workspaces/kprog-raw/perf/20261116-native-corpus-replay/identity-cilium
[ -x $L ] || bash $R/kprog/results/katran-callorder-20261123/replay.sh > /dev/null
rm -rf $X; mkdir -p $X/v $X/link
cd $R
H=$(git ls-tree --name-only 8430daa81 vendor/bpf/ | grep '\.h$')
git archive 8430daa81 vendor/bpf/cilium/bpf $H | tar -x -C $X/v
# today's compile command for bpf_lxc (vendor/bpf/Makefile, unchanged since 8430daa81 for Cilium), with
# every vendor/bpf path pointing at the 8430daa81 export
python3 - "$R/vendor/bpf" "$V" "$X" > $X/flags.txt <<'PY'
import shlex, subprocess, sys
src, dst, x = sys.argv[1:4]
out = subprocess.run(['make', '-n', 'ARCH=x86', 'OUT=%s/out' % x, '%s/out/native/cilium/bpf_lxc.native.o' % x],
                     cwd=src, capture_output=True, text=True, check=True).stdout.replace('\\\n', ' ')
line = [l for l in out.splitlines() if 'clang-18' in l][0]
args = shlex.split(line)[1:]
args = args[:args.index('-o')]
print(' '.join(shlex.quote(a.replace(src, dst)) for a in args))
PY
(cd $V && eval nice -n 5 clang-18 $(cat $X/flags.txt) -o $X/bpf_lxc.native.o cilium/bpf/bpf_lxc.c)
nm $X/bpf_lxc.native.o | awk '$2=="T"{print $3}' | sort > $X/lxc-symbols.txt
set +e
for d in $PLANS/*/; do d=${d%/}; sym=$(nm $d/entry.proof.o | awk '$2=="T"{print $3; exit}')
  grep -qx "$sym" $X/lxc-symbols.txt || continue
  [ -f $X/link/$sym.proof.o ] || $L --input $X/bpf_lxc.native.o --symbol $sym --mode proof --output $X/link/$sym.proof.o > $X/link/$sym.proof.log 2>&1 || { echo "$sym proof rc=$?" >> $X/rc.txt; continue; }
  for p in $d/*.link-plan.json; do n=$(basename $d).$(basename $p .link-plan.json)
    $L --input $X/link/$sym.proof.o --symbol $sym --mode kernel --output $X/link/$n.blob --output-relocs $X/link/$n.relocs \
      --output-map-patches $X/link/$n.maps --output-abi $X/link/$n.abi --link-plan $p > $X/link/$sym.$n.log 2>&1
    echo "$sym $n kernel rc=$?" >> $X/rc.txt
  done
done
sort $X/rc.txt | awk '{print $NF}' | sort | uniq -c
python3 - $X/link <<'PY'
import collections, glob, re, sys
tot = same = 0; other = collections.Counter(); ex = {}
for f in sorted(glob.glob(sys.argv[1] + '/*.log')):
    if f.endswith('.proof.log'):
        continue
    sym = f.split('/')[-1].split('.')[0]
    for l in open(f):
        if not l.startswith('DIAG'):
            continue
        tot += 1
        nm, site, kind, sm = re.search(r'native_map=(\S+) site=(\S+) kind=(\S+) site_map=(\S+)', l).groups()
        n = nm[6:-2] if nm.startswith('Some') else None
        s = sm[6:-2] if sm.startswith('Some') else None
        if n and s and (n == s or n.startswith(s)):
            same += 1
            continue
        key = (sym, n, kind, s)
        other[key] += 1
print('lookups', tot, 'matched by map name', same)
for (sym, n, kind, s), v in sorted(other.items()):
    print('%-28s native_map=%-24s -> %-12s %s  x%d' % (sym, n, kind, s, v))
PY
