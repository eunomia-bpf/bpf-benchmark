"""Per-program BPF time for a stats-on kprog/perf/may29-image run, eBPF phase against native phase.

Usage: python3 kprog/perf/may29-image/perprog.py <stats-on run dir> [rows]
Programs are matched by name (the native phase loads new program ids); each name sums its
run_cnt_delta and run_time_ns_delta over all instances. Rows are sorted by eBPF-phase time,
so the top rows are where native code has the most time to win.
"""
import sys, json, collections, pathlib

def phase(app, name):
    runs, ns = collections.Counter(), collections.Counter()
    for rec in ((app.get(name) or {}).get('bpf') or {}).values():
        runs[rec.get('name', '?')] += rec.get('run_cnt_delta', 0)
        ns[rec.get('name', '?')] += rec.get('run_time_ns_delta', 0)
    return runs, ns

run = pathlib.Path(sys.argv[1])
rows = int(sys.argv[2]) if len(sys.argv) > 2 else 20
files = sorted((run / 'details' / 'apps').glob('*.json'))
if len(files) != 1:
    sys.exit(f'expected one app json under {run}, found {files}')
app = json.loads(files[0].read_text())
er, en = phase(app, 'baseline')
nr, nn = phase(app, 'post_rejit')
total = sum(en.values()) or 1
print(f'{"program":40} {"eBPF runs":>11} {"eBPF ns/inv":>11} {"native ns/inv":>13} {"speedup":>8} {"eBPF time":>9}')
for name, t in en.most_common(rows):
    if er[name] < 100 or nr[name] < 100:
        continue
    a, b = t / er[name], nn[name] / nr[name]
    print(f'{name[:40]:40} {er[name]:>11} {a:>11.1f} {b:>13.1f} {a / b:>7.3f}x {100 * t / total:>8.1f}%')
