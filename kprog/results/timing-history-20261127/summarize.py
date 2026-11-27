#!/usr/bin/env python3
"""Per app, run class and day: medians of all-runs.tsv (x86 KVM corpus runs).

    python3 kprog/results/timing-history-20261127/summarize.py > kprog/results/timing-history-20261127/by-day.tsv

Run class: full = 3 samples x 180 s (the frozen entry's defaults); 10s = 1 sample x 10 s (make check).
"""
import collections, csv, os, statistics as st

HERE = os.path.dirname(os.path.abspath(__file__))
rows = [r for r in csv.DictReader(open(os.path.join(HERE, 'all-runs.tsv')), delimiter='\t') if r['kind'] == 'x86_kvm']
groups = collections.defaultdict(list)
for r in rows:
    seconds = float(r['seconds'])
    cls = 'full' if r['samples'] == '3' and seconds >= 170 else ('10s' if seconds <= 15 else 'other')
    groups[(r['app'], cls, r['started'][:10])].append(r)
print('\t'.join(['app', 'class', 'day', 'runs', 'ebpf_ns_median', 'native_ns_median', 'ratio_median', 'ratio_min', 'ratio_max']))
for (app, cls, day), v in sorted(groups.items()):
    ratios = [float(r['ratio']) for r in v]
    print('\t'.join([app, cls, day, str(len(v)), '%.1f' % st.median(float(r['ebpf_ns']) for r in v),
                     '%.1f' % st.median(float(r['native_ns']) for r in v), '%.3f' % st.median(ratios),
                     '%.3f' % min(ratios), '%.3f' % max(ratios)]))
