#!/usr/bin/env python3
"""Per-program ratio geomean per run, per rejit/docs/evaluation.md §5.

    ./measure.py [app]      # app = otel | cilium | bcc | tracee | tetragon | katran
Prints one line per run and the distribution over runs.
"""
import glob,json,math,os,statistics,sys
APPS={'otel':'otelcol-ebpf-profiler__profiling','cilium':'cilium__agent','bcc':'bcc__set',
      'tracee':'tracee__monitor','tetragon':'tetragon__observer','katran':'katran'}
def geomean(values):
    return math.exp(sum(math.log(v) for v in values)/len(values)) if values else None
def program_ratios(app):
    """§5.1/5.2: join phases by (name,type), require min run_cnt >= 100."""
    baseline=(app.get('baseline') or {}).get('bpf') or {}
    post=(app.get('post_rejit') or {}).get('bpf') or {}
    by_key=lambda d:{(v.get('name'),v.get('type')):v for v in d.values()}
    b,p=by_key(baseline),by_key(post)
    ratios=[]
    for key,base in b.items():
        if key not in p: continue
        if min(base['run_cnt_delta'],p[key]['run_cnt_delta'])<100: continue
        ratios.append((p[key]['run_time_ns_delta']/p[key]['run_cnt_delta'])/
                      (base['run_time_ns_delta']/base['run_cnt_delta']))
    return ratios
def main():
    key=APPS[sys.argv[1] if len(sys.argv)>1 else 'otel']
    per_sample={}
    for meta in sorted(glob.glob('corpus/results/x86_kvm_corpus_*/metadata.json')):
        detail=meta.replace('metadata.json','details/apps/%s.json'%key)
        if not os.path.exists(detail): continue
        run=json.load(open(meta)); app=json.load(open(detail))
        g=geomean(program_ratios(app))
        if g is None: continue
        per_sample.setdefault(run.get('samples'),[]).append((meta.split('/')[-2],g))
    for samples,rows in sorted(per_sample.items(),key=lambda kv:(kv[0] is None,kv[0])):
        vals=[g for _,g in rows]
        print('samples=%s n=%d geomean %.3f sd %.3f faster %d/%d'%(
            samples,len(rows),geomean(vals),
            statistics.stdev(vals) if len(vals)>1 else 0.0,
            sum(1 for v in vals if v<1.0),len(vals)))
    for run,g in sorted(per_sample.get(3,[]))[-5:]:
        print('  %s %.3f'%(run,g))
if __name__=='__main__': main()
