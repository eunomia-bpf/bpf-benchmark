import sys,json,glob,statistics,types,importlib.util,pathlib,collections
_m=types.ModuleType('matplotlib'); _m.use=lambda *a,**k:None; _p=types.ModuleType('matplotlib.pyplot'); _m.pyplot=_p
sys.modules['matplotlib']=_m; sys.modules['matplotlib.pyplot']=_p
spec=importlib.util.spec_from_file_location('ne','/workspaces/repository/kprog/docs/archive/native_eval_20260529.py')
ne=importlib.util.module_from_spec(spec); sys.modules['ne']=ne; spec.loader.exec_module(ne)
ne.ROOT=pathlib.Path('/workspaces/repository')
runs=sorted(glob.glob('/workspaces/repository/corpus/results/x86_kvm_corpus_2026111[6-9]_*')+glob.glob('/workspaces/repository/corpus/results/x86_kvm_corpus_2026112[01]_*'))
rows=[]
for r in runs:
    try:
        md=json.load(open(r+'/metadata.json'))
        if md.get('samples')!=3 or int(float(md.get('workload_seconds') or 0))!=180: continue
        rel=r.replace('/workspaces/repository/','')
        app,_=ne.load_app(rel)
        if app.get('status')!='ok': continue
        name=app.get('app')
        stats=bool(md.get('bpf_stats'))
        e=[s[0] for s in ne.phase_samples(app,'baseline')]; n=[s[0] for s in ne.phase_samples(app,'post_rejit')]
        if not e or not n: continue
        thr=statistics.median(n)/statistics.median(e)
        pc=None; progs=None
        if stats:
            a=ne.bpf_aggregate(app,'baseline'); b=ne.bpf_aggregate(app,'post_rejit')
            if a[0] and b[0]: pc=a[0]/b[0]; progs=f'{a[1]}/{a[2]} {b[1]}/{b[2]}'
        rows.append((name,stats,thr,pc,progs,rel.split('_corpus_')[1]))
    except Exception as ex:
        continue
best=collections.defaultdict(dict)
for name,stats,thr,pc,progs,rid in rows:
    k='on' if stats else 'off'
    if thr is not None and (('thr_'+k) not in best[name] or thr>best[name]['thr_'+k][0]): best[name]['thr_'+k]=(thr,rid)
    if pc is not None and ('pc' not in best[name] or pc>best[name]['pc'][0]): best[name]['pc']=(pc,rid,progs)
print('runs considered', len(rows))
for name in sorted(best):
    b=best[name]
    f=lambda x: f'{x[0]:.3f}x ({x[1]})' if x else '-'
    print(f'{name:32s} per-call {f(b.get("pc"))} progs {b.get("pc",(0,0,""))[2]} | thr stats-off {f(b.get("thr_off"))} | thr stats-on {f(b.get("thr_on"))}')
# also count per app runs
c=collections.Counter((r[0],r[1]) for r in rows)
print(dict(c))
