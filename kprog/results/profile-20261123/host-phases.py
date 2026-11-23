#!/usr/bin/env python3
"""Guest-kernel profile of one profile-host.sh run, eBPF phase against native phase.
Samples: the host PMU's guest-mode samples from the raw dump (perf script leaves guest samples out).
Symbols: the guest's boot kallsyms plus the BPF programs a phase's own snapshots list (the native
programs reuse addresses the eBPF phase had, so each phase resolves with the snapshots taken in it; a
symbol ends where the next one starts). Windows: given in guest uptime seconds, as
EBPF_START,EBPF_END NATIVE_START,NATIVE_END (the native programs load in the quiet gap between the
two workloads). Output: samples per second per symbol in each window.
Usage: host-phases.py OUTDIR EBPF_WINDOW NATIVE_WINDOW NATIVE_FIRST_SNAPSHOT_UPTIME [TOP]"""
import bisect, collections, glob, os, re, subprocess, sys
out, we, wn, cut = sys.argv[1], sys.argv[2], sys.argv[3], float(sys.argv[4])
top = int(sys.argv[5]) if len(sys.argv) > 5 else 45
PERF = '/workspaces/.agent-state/kprog-ck/perf-tool/perf'
snaps = sorted(glob.glob(os.path.join(out, 'kallsyms-bpf-*.txt')), key=lambda p: float(p.rsplit('-', 1)[1][:-4]))
boot = {}
for line in open(os.path.join(out, 'kallsyms.txt')):
    p = line.split()
    if len(p) >= 3 and p[1] in 'tTwW':
        boot[int(p[0], 16)] = p[2]
def table(paths):
    s = dict(boot)
    for path in paths:
        for line in open(path):
            a, t, name = line.split()[:3]
            s[int(a, 16)] = name
    return s, sorted(s)
up = lambda p: float(p.rsplit('-', 1)[1][:-4])
tables = {'eBPF': table([p for p in snaps if up(p) < cut]), 'native': table([p for p in snaps if up(p) >= cut])}
def sym(tab, ip):
    if ip < 0xffff800000000000:
        return '[user]'
    s, a = tab
    k = bisect.bisect_right(a, ip) - 1
    return s[a[k]] if k >= 0 else '?'
proc = subprocess.Popen([PERF, 'report', '-D', '-i', os.path.join(out, 'host-perf.data')],
                        stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
SAMPLE = re.compile(r'^\d+ (\d+) \S+ \[\S+\]: PERF_RECORD_SAMPLE\(IP, 0x([45])\): \S+ 0x([0-9a-f]+) ')
raw = []
for line in proc.stdout:
    m = SAMPLE.match(line)
    if m:
        raw.append((int(m.group(1)) / 1e9, int(m.group(3), 16)))
# windows are in guest uptime: sample time (host uptime) + host realtime-minus-uptime (HOST_RT_MINUS_UPTIME
# in the environment) - guest realtime + guest uptime, both from clock.txt
g_rt, g_up = map(float, open(os.path.join(out, 'clock.txt')).read().split())
host_off = float(os.environ['HOST_RT_MINUS_UPTIME'])
up_of = lambda t: t + host_off - g_rt + g_up
win = {}
for k, w in (('eBPF', we), ('native', wn)):
    a, b = map(float, w.split(','))
    win[k] = (a, b)
prof = {}
for k, (a, b) in win.items():
    c = collections.Counter(sym(tables[k], ip) for t, ip in raw if a <= up_of(t) < b)
    prof[k] = {s: v / (b - a) for s, v in c.items()}
progs = lambda d: sum(v for s, v in d.items() if s.startswith('bpf_prog_'))
print('windows (guest uptime): %s; samples/s: eBPF %.0f, native %.0f' % (
    win, sum(prof['eBPF'].values()), sum(prof['native'].values())))
print('samples/s in BPF programs: eBPF %.0f, native %.0f' % (progs(prof['eBPF']), progs(prof['native'])))
names = sorted(set(prof['eBPF']) | set(prof['native']), key=lambda n: -max(prof['eBPF'].get(n, 0), prof['native'].get(n, 0)))
print('%8s %8s  %s' % ('eBPF/s', 'native/s', 'symbol'))
for n in names[:top]:
    print('%8.0f %8.0f  %s' % (prof['eBPF'].get(n, 0), prof['native'].get(n, 0), n[:90]))
