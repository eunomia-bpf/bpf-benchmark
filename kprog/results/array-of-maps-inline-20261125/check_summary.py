"""Per-app ratios of the 1 x 10 s functional check runs (diagnostic numbers), read with the 05-29 evaluator."""
import sys, json, glob, statistics, types, importlib.util, pathlib
_m = types.ModuleType('matplotlib'); _m.use = lambda *a, **k: None
_p = types.ModuleType('matplotlib.pyplot'); _m.pyplot = _p
sys.modules['matplotlib'] = _m; sys.modules['matplotlib.pyplot'] = _p
spec = importlib.util.spec_from_file_location('ne', '/workspaces/repository/kprog/docs/archive/native_eval_20260529.py')
ne = importlib.util.module_from_spec(spec); sys.modules['ne'] = ne; spec.loader.exec_module(ne)
ne.ROOT = pathlib.Path('/workspaces/repository')
after = sys.argv[1] if len(sys.argv) > 1 else '20261125_1109'
for r in sorted(glob.glob('/workspaces/repository/corpus/results/x86_kvm_corpus_2026*')):
    rid = r.split('_corpus_')[1]
    if rid < after:
        continue
    md = json.load(open(r + '/metadata.json'))
    rel = r.replace('/workspaces/repository/', '')
    try:
        app, _ = ne.load_app(rel)
    except Exception as ex:
        print(rid, 'unreadable', ex); continue
    e = [s[0] for s in ne.phase_samples(app, 'baseline')]; n = [s[0] for s in ne.phase_samples(app, 'post_rejit')]
    thr = statistics.median(n) / statistics.median(e) if e and n else None
    pc = None
    if md.get('bpf_stats'):
        a = ne.bpf_aggregate(app, 'baseline'); b = ne.bpf_aggregate(app, 'post_rejit')
        if a[0] and b[0]:
            pc = (a[0] / b[0], a[0], b[0])
    print(f"{rid} {app.get('app'):32s} status={app.get('status')} samples={md.get('samples')} s={md.get('workload_seconds')} "
          f"per-call={'%.3fx (%.1f / %.1f ns)' % pc if pc else '-'} thr={'%.3fx' % thr if thr else '-'}")
