#!/usr/bin/env python3
"""Every recorded corpus run: per-call ns of both arms from the kernel's bpf stats.

    python3 kprog/results/timing-history-20261127/scan.py > kprog/results/timing-history-20261127/all-runs.tsv

One row per (run directory, application) whose run completed with bpf stats on and both
phases ran programs: eBPF ns/call = sum(run_time_ns_delta) / sum(run_cnt_delta) over the
baseline phase, native ns/call the same over the post_rejit phase, ratio = eBPF / native.
"""
import glob, json, os, sys

ROOT = 'corpus/results'
APPS = {'otelcol-ebpf-profiler__profiling': 'OTel', 'bcc__set': 'BCC', 'cilium__agent': 'Cilium',
        'tetragon__observer': 'Tetragon', 'tracee__monitor': 'Tracee', 'katran': 'Katran'}


def phase(app, key):
    bpf = ((app.get(key) or {}).get('bpf')) or {}
    t = c = active = 0
    for v in bpf.values():
        cnt = int(v.get('run_cnt_delta') or 0)
        if cnt > 0:
            active += 1
            c += cnt
            t += int(v.get('run_time_ns_delta') or 0)
    return t, c, active, len(bpf)


def main():
    print('\t'.join(['run', 'kind', 'started', 'samples', 'seconds', 'app', 'ebpf_ns', 'native_ns',
                     'ratio', 'ebpf_active', 'native_active', 'programs', 'ebpf_calls', 'native_calls']))
    for meta_path in sorted(glob.glob(os.path.join(ROOT, '*corpus_*', 'metadata.json'))):
        run_dir = os.path.dirname(meta_path)
        run = os.path.basename(run_dir)
        kind = run.split('_corpus')[0]
        try:
            meta = json.load(open(meta_path))
        except Exception:
            continue
        if meta.get('status') != 'completed' or not meta.get('bpf_stats'):
            continue
        for path in glob.glob(os.path.join(run_dir, 'details', 'apps', '*.json')):
            name = APPS.get(os.path.basename(path)[:-5])
            if not name:
                continue
            try:
                app = json.load(open(path))
            except Exception:
                continue
            if app.get('status') != 'ok':
                continue
            bt, bc, ba, n = phase(app, 'baseline')
            nt, nc, na, _ = phase(app, 'post_rejit')
            if bc == 0 or nc == 0 or bt == 0 or nt == 0:
                continue
            e, x = bt / bc, nt / nc
            print('\t'.join(str(v) for v in [run, kind, (meta.get('started_at') or '')[:19], meta.get('samples'),
                                              meta.get('workload_seconds'), name, '%.1f' % e, '%.1f' % x,
                                              '%.3f' % (e / x), ba, na, n, bc, nc]))


if __name__ == '__main__':
    main()
