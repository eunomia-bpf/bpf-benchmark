"""Normalize existing decoded period sums by actual recorded operations, without re-decoding perf."""
from pathlib import Path
import hashlib,json
HERE=Path(__file__).resolve().parent;PAIR=HERE/'paired-profile';OUT=PAIR/'analysis';c=json.loads((OUT/'controller.json').read_text());assert c['pid']==1456924 and c['controller_status']==0;review=json.loads((PAIR/'case-review.json').read_text());manifest=[]
for row in c['cases']:
 stats=row['stats'];p=OUT/('stats'+str(stats)+'-pmu.json');data=p.read_bytes();r=json.loads(data);case=next(x for x in review['cases'] if x['stats']==stats)
 for phase,x in r['phases'].items():
  samples=case['workload_cpu'][phase];assert len(samples)==1;ops=sum(z['bogo_ops'] for z in samples[0]['cpu_rows'].values());assert ops>0;x['observed_total_bogo_ops']=ops;x['nominal_rate_times_window_denominator']=x['window']['duration']*x['workload']['total_ops_per_second']
  for v in x['symbols'].values():v['nominal_rate_window_normalized_periods']=v.pop('periods_per_total_bogo_op');v['periods_per_observed_total_bogo_op']=v['period_sum']/ops
 r['normalization_input']=dict(path=str(p),sha256=hashlib.sha256(data).hexdigest());r['normalization_note']='Use actual summed recorded bogo counts, NOT sum(ops/s)*whole shim measurement duration. Worker duration and cleanup window differ (stats0native parent13s vsmoststressors10s). PMU includes observers/cleanup and mixed component work; this is not exact kernel time/per-program cost.';dest=OUT/('stats'+str(stats)+'-pmu-normalized.json');assert not dest.exists();dest.write_text(json.dumps(r,indent=2)+'\n');manifest.append(dict(stats=stats,path=str(dest),sha256=hashlib.sha256(dest.read_bytes()).hexdigest()))
(OUT/'normalized-results.json').write_text(json.dumps(manifest,indent=2)+'\n');print(json.dumps(manifest))
