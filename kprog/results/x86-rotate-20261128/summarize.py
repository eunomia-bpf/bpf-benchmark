#!/usr/bin/env python3
"""Summary of the 2026-11-28 x86 frozen-entry rotate with the 05-29 parser (kprog/docs/archive/native_eval_20260529.py).

    python3 kprog/results/x86-rotate-20261128/summarize.py /workspaces/kprog-raw/coordinator/x86-rotate-20261128/progress.log

Per app and stats mode: throughput = median(native samples) / median(eBPF samples) and each sample pair;
per call (stats on) = eBPF aggregate ns per run / native aggregate ns per run, with active / total programs.
"""
import importlib.util, json, pathlib, re, statistics, sys, types

_m = types.ModuleType('matplotlib'); _m.use = lambda *a, **k: None
_p = types.ModuleType('matplotlib.pyplot'); _m.pyplot = _p
sys.modules['matplotlib'] = _m; sys.modules['matplotlib.pyplot'] = _p
ROOT = pathlib.Path('/workspaces/repository')
spec = importlib.util.spec_from_file_location('ne', ROOT / 'kprog/docs/archive/native_eval_20260529.py')
ne = importlib.util.module_from_spec(spec); sys.modules['ne'] = ne; spec.loader.exec_module(ne)
ne.ROOT = ROOT

rows = re.findall(r'end (\S+) stats=(\d) rc=(\d+) run=(\S*)', open(sys.argv[1]).read())
print('\t'.join(['app', 'stats', 'rc', 'status', 'throughput_median_ratio', 'throughput_sample_ratios',
                 'ebpf_samples', 'native_samples', 'per_call', 'ebpf_ns', 'native_ns', 'ebpf_active/total',
                 'native_active/total', 'run']))
for app, stats, rc, run in rows:
    rel = run.replace(str(ROOT) + '/', '')
    if rc != '0' or not run:
        print('\t'.join([app, stats, rc, '', '', '', '', '', '', '', '', '', '', rel]))
        continue
    j, _ = ne.load_app(rel)
    e = [s[0] for s in ne.phase_samples(j, 'baseline')]
    n = [s[0] for s in ne.phase_samples(j, 'post_rejit')]
    thr = statistics.median(n) / statistics.median(e) if e and n else None
    pairs = [b / a for a, b in zip(e, n) if a] if e and n else []
    pc = ens = nns = ea = na = ''
    if stats == '1':
        a = ne.bpf_aggregate(j, 'baseline'); b = ne.bpf_aggregate(j, 'post_rejit')
        if a[0] and b[0]:
            pc = '%.3f' % (a[0] / b[0]); ens = '%.1f' % a[0]; nns = '%.1f' % b[0]
            ea = '%s/%s' % (a[1], a[2]); na = '%s/%s' % (b[1], b[2])
    print('\t'.join([app, stats, rc, str(j.get('status')), '%.3f' % thr if thr else '',
                     ','.join('%.3f' % x for x in pairs), ','.join('%.0f' % x for x in e),
                     ','.join('%.0f' % x for x in n), pc, ens, nns, ea, na, rel]))
