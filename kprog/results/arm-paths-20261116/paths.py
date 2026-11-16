"""Per-program run counts in both arms of a stats-on run: do the two arms run the same programs as often?"""
import json, glob, sys, os, statistics

def counts(a, ph):
    out = {}
    def walk(o):
        if isinstance(o, dict):
            nm = o.get('name')
            if nm is not None and 'run_cnt_delta' in o:
                out[nm] = out.get(nm, 0) + int(o.get('run_cnt_delta') or 0)
                return
            for v in o.values(): walk(v)
        elif isinstance(o, list):
            for v in o: walk(v)
    walk((a.get(ph) or {}).get('bpf'))
    return out

for r in sys.argv[1:]:
    f = glob.glob(r + '/details/apps/*.json')
    if not f: continue
    a = json.load(open(f[0]))
    b, n = counts(a, 'baseline'), counts(a, 'post_rejit')
    names = sorted(set(b) | set(n), key=lambda k: -(b.get(k, 0) + n.get(k, 0)))
    active = [k for k in names if max(b.get(k, 0), n.get(k, 0)) >= 1000]
    ratios = [n[k] / b[k] for k in active if b.get(k, 0) >= 1000 and n.get(k, 0) >= 1000]
    med = statistics.median(ratios) if ratios else float('nan')
    print(f'== {os.path.basename(r)} ({os.path.basename(f[0])}): {len(active)} active programs, median native/eBPF run ratio {med:.3f}')
    odd = 0
    for k in active:
        bb, nn = b.get(k, 0), n.get(k, 0)
        rr = (nn / bb) if bb else float('inf')
        flag = bb < 1000 or nn < 1000 or not (0.7 * med <= rr <= 1.3 * med)
        if flag:
            odd += 1
            print(f'   DIFFERENT {k}: eBPF {bb:,}  native {nn:,}  ratio {rr:.3f}')
    print(f'   programs whose counts track the median: {len(active) - odd} of {len(active)}')
