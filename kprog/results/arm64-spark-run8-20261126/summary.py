"""arm64 run 8 on the two Sparks: per-app ratios read with the 05-29 evaluator (as check_summary.py does).
Per call: stats-on arm, eBPF aggregate ns/call over native aggregate ns/call.
Throughput: native median over eBPF median of the workload samples, and the per-sample ratios in sample order."""
import sys, json, glob, statistics, types, importlib.util, pathlib
_m = types.ModuleType('matplotlib'); _m.use = lambda *a, **k: None
_p = types.ModuleType('matplotlib.pyplot'); _m.pyplot = _p
sys.modules['matplotlib'] = _m; sys.modules['matplotlib.pyplot'] = _p
spec = importlib.util.spec_from_file_location('ne', '/workspaces/repository/kprog/docs/archive/native_eval_20260529.py')
ne = importlib.util.module_from_spec(spec); sys.modules['ne'] = ne; spec.loader.exec_module(ne)
RAW = pathlib.Path('/workspaces/kprog-raw/arm64-spark-run8')
rows = {}
for host in ('spark-9773', 'spark-d5fe'):
    root = RAW / host / 'root/workspaces/repository'
    ne.ROOT = root
    for r in sorted(glob.glob(str(root / 'corpus/results/arm64_qemu_corpus_*'))):
        rel = str(pathlib.Path(r).relative_to(root))
        md = json.load(open(r + '/metadata.json'))
        app, _ = ne.load_app(rel)
        name = app.get('app')
        e = [s[0] for s in ne.phase_samples(app, 'baseline')]
        n = [s[0] for s in ne.phase_samples(app, 'post_rejit')]
        rec = rows.setdefault(name, {'host': host})
        key = 'on' if md.get('bpf_stats') else 'off'
        rec['thr_' + key] = statistics.median(n) / statistics.median(e) if e and n else None
        rec['thr_' + key + '_each'] = [b / a for a, b in zip(e, n)]
        rec['status_' + key] = app.get('status')
        rec['run_' + key] = rel.split('/')[-1]
        if md.get('bpf_stats'):
            a = ne.bpf_aggregate(app, 'baseline'); b = ne.bpf_aggregate(app, 'post_rejit')
            if a[0] and b[0]:
                rec['pc'] = (a[0] / b[0], a[0], b[0])
for name, r in sorted(rows.items()):
    pc = r.get('pc')
    f = lambda v: '%.3fx' % v if v else '-'
    each = lambda k: ', '.join('%.3f' % x for x in r.get(k, []))
    print(f"{name:32s} {r['host']:10s} per-call {('%.3fx (eBPF %.1f ns, native %.1f ns)' % pc) if pc else '-'} | "
          f"thr off {f(r.get('thr_off'))} ({each('thr_off_each')}) | thr on {f(r.get('thr_on'))} ({each('thr_on_each')}) | "
          f"status {r.get('status_off')}/{r.get('status_on')} | runs {r.get('run_off')} {r.get('run_on')}")
