#!/usr/bin/env python3
"""Flat perf profile of the eBPF phase and the native phase of one profile.sh run, side by side.
Windows: the last 55 s of each phase's shim log (the workload runs at the end of a phase).
Usage: phases.py OUTDIR [TOP]"""
import glob, os, re, subprocess, sys
out = sys.argv[1]
top = int(sys.argv[2]) if len(sys.argv) > 2 else 30
PERF = '/workspaces/.agent-state/kprog-ck/perf-tool/perf'
run = open(os.path.join(out, 'run_dir')).read().strip()

def span(log):
    ts = [float(m.group(1)) for m in re.finditer(r'^\[(\d+\.\d+) ', open(log, errors='replace').read(), re.M)]
    return min(ts), max(ts)

def profile(t0, t1):
    r = subprocess.run([PERF, 'report', '-i', os.path.join(out, 'perf.data'), '--kallsyms',
                        os.path.join(out, 'kallsyms.txt'), '--stdio', '--no-children', '--sort', 'sym',
                        '--time', '%.3f,%.3f' % (t0, t1), '--percent-limit', '0.2'],
                       capture_output=True, text=True)
    rows = {}
    for line in r.stdout.splitlines():
        m = re.match(r'^\s+([\d.]+)%\s+\[([kH.])\]\s+(.+?)\s*$', line)
        if m:
            rows[m.group(3)] = float(m.group(1))
    return rows

phases = {}
for ph in ('baseline', 'post_rejit'):
    log = glob.glob(os.path.join(run, 'details/shim-logs/*.%s.log' % ph))[0]
    a, b = span(log)
    phases[ph] = profile(max(a, b - 55), b - 1)
    print('%s window %.1f-%.1f' % (ph, max(a, b - 55), b - 1))
names = sorted(set(phases['baseline']) | set(phases['post_rejit']),
               key=lambda n: -max(phases['baseline'].get(n, 0), phases['post_rejit'].get(n, 0)))
print('%7s %7s  %s' % ('eBPF%', 'native%', 'symbol'))
for n in names[:top]:
    print('%7.2f %7.2f  %s' % (phases['baseline'].get(n, 0), phases['post_rejit'].get(n, 0), n[:90]))
