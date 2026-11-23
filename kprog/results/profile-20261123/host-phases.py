#!/usr/bin/env python3
"""Flat guest profile of one profile-host.sh run: eBPF phase and native phase side by side.
The guest symbol table is the boot kallsyms plus every BPF program the 30 s snapshots listed. A phase's
window is the time span of the samples that land in that phase's programs: the baseline programs are the
ones listed while the first snapshots ran, the native ones appear later. Usage: host-phases.py OUTDIR [TOP]"""
import glob, os, re, subprocess, sys
out = sys.argv[1]
top = int(sys.argv[2]) if len(sys.argv) > 2 else 40
PERF = '/workspaces/.agent-state/kprog-ck/perf-tool/perf'
snaps = sorted(glob.glob(os.path.join(out, 'kallsyms-bpf-*.txt')), key=lambda p: float(p.rsplit('-', 1)[1][:-4]))
seen = {}
for p in snaps:
    for line in open(p):
        a, t, name = line.split()[:3]
        seen.setdefault(name, (a, t, name))
ks = os.path.join(out, 'kallsyms-all.txt')
with open(ks, 'w') as f:
    f.write(open(os.path.join(out, 'kallsyms.txt')).read())
    for a, t, name in seen.values():
        f.write('%s %s %s\n' % (a, t, name))
base = [PERF, 'kvm', '--guest', '--guestkallsyms=' + ks, '--guestmodules=' + os.path.join(out, 'modules.txt')]
script = subprocess.run(base + ['script', '-i', os.path.join(out, 'host-perf.data'), '-F', 'time,sym'],
                        capture_output=True, text=True).stdout
def span(pred):
    ts = []
    for line in script.splitlines():
        m = re.match(r'^\s*([\d.]+):\s+(\S+)', line)
        if m and pred(m.group(2)):
            ts.append(float(m.group(1)))
    return (min(ts), max(ts), len(ts)) if ts else None
app = sys.argv[3] if len(sys.argv) > 3 else None
progs = [n for n in seen if n.startswith('bpf_prog_')]
# a program present in every snapshot from the first one is a baseline (eBPF) program; native ones come later
first = {l.split()[2] for l in open(snaps[0])} if snaps else set()
later = [n for n in progs if n not in first]
w_ebpf = span(lambda s: s in first and s.startswith('bpf_prog_'))
w_nat = span(lambda s: s in later)
print('eBPF window', w_ebpf, 'native window', w_nat)
def profile(w):
    r = subprocess.run(base + ['report', '-i', os.path.join(out, 'host-perf.data'), '--stdio', '--no-children',
                               '--sort', 'sym', '--time', '%.6f,%.6f' % (w[0], w[1]), '--percent-limit', '0.05'],
                       capture_output=True, text=True).stdout
    rows = {}
    for line in r.splitlines():
        m = re.match(r'^\s+([\d.]+)%\s+\[([kgu.H])\]\s+(.+?)\s*$', line)
        if m:
            rows[m.group(3)] = float(m.group(1))
    return rows
a, b = profile(w_ebpf), profile(w_nat)
names = sorted(set(a) | set(b), key=lambda n: -max(a.get(n, 0), b.get(n, 0)))
print('%7s %7s  %s' % ('eBPF%', 'native%', 'symbol'))
for n in names[:top]:
    print('%7.2f %7.2f  %s' % (a.get(n, 0), b.get(n, 0), n[:90]))
