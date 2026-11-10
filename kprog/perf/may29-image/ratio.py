"""Ratios for kprog/perf/may29-image runs, with the 2026-05-29 evaluation's own parsing.

Usage: python3 kprog/perf/may29-image/ratio.py off=<stats-off run dir> on=<stats-on run dir> ...
off= prints workload throughput native/eBPF (median over samples, the 2026-05-29 table's
definition); on= prints aggregate BPF ns per invocation over programs with at least 100 runs.
"""
import sys, importlib.util, statistics, types
# The archive script plots with matplotlib; the ratios need only its parsing functions.
_m = types.ModuleType('matplotlib'); _m.use = lambda *a, **k: None
_p = types.ModuleType('matplotlib.pyplot'); _m.pyplot = _p
sys.modules['matplotlib'] = _m; sys.modules['matplotlib.pyplot'] = _p
spec = importlib.util.spec_from_file_location('ne', '/workspaces/repository/kprog/docs/archive/native_eval_20260529.py')
ne = importlib.util.module_from_spec(spec)
sys.modules['ne'] = ne
spec.loader.exec_module(ne)
import pathlib
ne.ROOT = pathlib.Path('/workspaces/repository')  # the script moved from docs/tmp to kprog/docs/archive

def thr(run):
    app, _ = ne.load_app(run)
    e = [s[0] for s in ne.phase_samples(app, 'baseline')]
    n = [s[0] for s in ne.phase_samples(app, 'post_rejit')]
    errs = [s[2] for s in ne.phase_samples(app, 'baseline')] + [s[2] for s in ne.phase_samples(app, 'post_rejit')]
    r = [n[i] / e[i] for i in range(min(len(e), len(n)))]
    return statistics.median(n) / statistics.median(e), e, n, r, errs

def ns(run):
    app, _ = ne.load_app(run)
    a = ne.bpf_aggregate(app, 'baseline')
    b = ne.bpf_aggregate(app, 'post_rejit')
    return a, b

for kind, run in [a.split('=', 1) for a in sys.argv[1:]]:
    if kind == 'off':
        x, e, n, r, errs = thr(run)
        print(f'{run} throughput native/eBPF {x:.3f}x  eBPF {[round(v) for v in e]} native {[round(v) for v in n]} per-sample {[round(v,3) for v in r]} errors {sum(errs)}')
    else:
        a, b = ns(run)
        print(f'{run} ns/inv eBPF {a[0]:.1f} ({a[1]}/{a[2]} progs) native {b[0]:.1f} ({b[1]}/{b[2]}) speedup {a[0]/b[0]:.3f}x')
