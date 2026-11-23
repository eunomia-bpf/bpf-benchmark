#!/usr/bin/env python3
"""Instruction-level host-PMU profile of one program in one profile-host.sh run.
Sample times (host perf clock = host uptime) become guest uptime through clock.txt (guest realtime and
uptime) and the host's realtime-minus-uptime offset given on the command line. Samples in [START, START+LEN)
within the guest-uptime window [U0, U1) are counted per byte offset; the code is a native-link blob
(objdump of the raw bytes, call targets from the blob's relocation file) or, with --nocode, only the
per-10 s counts are printed. Usage:
  host-annotate.py OUTDIR HOST_RT_MINUS_UPTIME START LEN U0 U1 [BLOB RELOCS KALLSYMS] [--hist]"""
import bisect, collections, os, re, struct, subprocess, sys
out, off = sys.argv[1], float(sys.argv[2])
start, length, u0, u1 = int(sys.argv[3], 16), int(sys.argv[4]), float(sys.argv[5]), float(sys.argv[6])
rest = [a for a in sys.argv[7:] if not a.startswith('--')]
hist = '--hist' in sys.argv
PERF = '/workspaces/.agent-state/kprog-ck/perf-tool/perf'
g_rt, g_up = map(float, open(os.path.join(out, 'clock.txt')).read().split())
def guest_uptime(t):
    return (t + off) - g_rt + g_up
proc = subprocess.Popen([PERF, 'report', '-D', '-i', os.path.join(out, 'host-perf.data')],
                        stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
SAMPLE = re.compile(r'^\d+ (\d+) \S+ \[\S+\]: PERF_RECORD_SAMPLE\(IP, 0x4\): \S+ 0x([0-9a-f]+) ')
c = collections.Counter(); h = collections.Counter(); total = 0
for line in proc.stdout:
    m = SAMPLE.match(line)
    if not m:
        continue
    ip = int(m.group(2), 16)
    if start <= ip < start + length:
        u = guest_uptime(int(m.group(1)) / 1e9)
        h[int(u // 10) * 10] += 1
        if u0 <= u < u1:
            c[ip - start] += 1; total += 1
if hist:
    for k in sorted(h):
        print('uptime %4d  %d' % (k, h[k]))
print('samples in range and window:', total)
if not rest:
    for o, v in c.most_common(40):
        print('%6d  +%#x' % (v, o))
    sys.exit(0)
blob, relocs, kall = rest
ks = {}
for line in open(kall):
    p = line.split()
    if len(p) >= 3:
        ks[int(p[0], 16)] = p[2]
ka = sorted(ks)
def ksym(a):
    k = bisect.bisect_right(ka, a) - 1
    return '%s+%#x' % (ks[ka[k]], a - ka[k]) if k >= 0 else hex(a)
rel = {}
if relocs != '-':
    data = open(relocs, 'rb').read()
    for o, kind, target in struct.iter_unpack('<IIQ', data):
        rel[o] = (kind, target)
# a JITed eBPF image (RELOCS '-') is disassembled at its load address, so its direct calls name their target
vma = start if relocs == '-' else 0
dis = subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '--no-show-raw-insn',
                      '--adjust-vma=%#x' % vma, blob], capture_output=True, text=True).stdout
rows = []
for line in dis.splitlines():
    m = re.match(r'^\s*([0-9a-f]+):\s+(.*)$', line)
    if m:
        text = m.group(2)
        t = re.search(r'call\s+0x([0-9a-f]+)', text)
        if t and vma:
            text += '   ; -> ' + ksym(int(t.group(1), 16))
        rows.append((int(m.group(1), 16) - vma, text))
offs = [r[0] for r in rows]
per = collections.Counter()
for o, v in c.items():
    k = bisect.bisect_right(offs, o) - 1
    per[k] += v
def note(k):
    o, text = rows[k]
    ln = (rows[k + 1][0] if k + 1 < len(rows) else o + 5) - o
    for ro in range(o, o + ln):
        if ro in rel:
            kind, target = rel[ro]
            return '%s   ; reloc kind %d -> %s' % (text, kind, ksym(target))
    return text
print('hottest instructions (samples, offset, instruction), with 6 before each:')
shown = set()
for k, v in sorted(per.items(), key=lambda kv: -kv[1])[:25]:
    print('---- %d samples' % v)
    for j in range(max(0, k - 6), min(len(rows), k + 2)):
        print('%6d  %5x:  %s' % (per.get(j, 0), rows[j][0], note(j)))
