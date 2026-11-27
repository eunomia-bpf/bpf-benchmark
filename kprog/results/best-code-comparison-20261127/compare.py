#!/usr/bin/env python3
"""Read retained frozen-run receipts; no guest/build/benchmark changes."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
CASES=[('cilium_best','20261121_133941_317114','cilium__agent','cil_from_contai'),('cilium_current','20261124_054725_460151','cilium__agent','cil_from_contai'),('katran_best','20261116_145408_662903','katran','balancer_ingres'),('katran_current','20261123_233751_015523','katran','balancer_ingres')]
def source(p):
 data=p.read_bytes()
 return dict(path=str(p.relative_to(ROOT)) if p.is_relative_to(ROOT) else str(p),bytes=len(data),sha256=hashlib.sha256(data).hexdigest())
result=dict(scope='Historical loaded-program identities and counters only. All functional best runs retained; no count gate or timing rerun.',cases={})
for label,run,app,target in CASES:
 base=ROOT/'corpus/results'/('x86_kvm_corpus_'+run)
 canonical=base/'details/apps'/(app+'.json')
 appfile=canonical
 if not canonical.exists() and label=='katran_best':appfile=OUT/'katran-best-recovered/katran.json'
 log=base/'details/shim-logs'/(app+'.post_rejit.log')
 lines=log.read_text().splitlines()
 # Include immediately adjacent original-load / fallback receipts, with original line numbers.
 hits=set()
 for i,line in enumerate(lines):
  if target in line and any(x in line for x in ['native-loader failed','jit-info','native-loader replaced']):
   hits.update(range(max(0,i-1),min(len(lines),i+2)))
 d=dict(run=str(base.relative_to(ROOT)),target=target,shim=source(log),receipts=[dict(line=i+1,text=lines[i]) for i in sorted(hits)],app_json_present=appfile.exists(),canonical_app_json_present=canonical.exists())
 if appfile.exists():
  appdata=json.loads(appfile.read_text());d.update(app_json=source(appfile),status=appdata['status'],arms={})
  for arm in ['baseline','post_rejit']:
   programs=list(appdata[arm]['bpf'].values())
   count=sum(p['run_cnt_delta'] for p in programs)
   ns=sum(p['run_time_ns_delta'] for p in programs)
   d['arms'][arm]=dict(all_programs=programs,program_count=len(programs),positive_count_programs=sum(p['run_cnt_delta']>0 for p in programs),calls=count,ns=ns,ns_per_call=ns/count)
  d['baseline_over_post_per_call']=d['arms']['baseline']['ns_per_call']/d['arms']['post_rejit']['ns_per_call']
 else:
  d['limitation']='Structured app JSON and metadata are absent from the retained run. No counters reconstructed or best result excluded.'
 if label=='katran_best' and appfile.exists():
  meta=OUT/'katran-best-recovered/metadata.json';metadata=json.loads(meta.read_text())
  d['recovered_metadata']=dict(source=source(meta),value=metadata)
  d['recovery_receipt']=source(OUT/'katran-best-recovered/recovery.json')
  assert metadata['samples']==3 and metadata['workload_seconds']==180.0 and metadata['bpf_stats']
  assert metadata['started_at'].startswith('2026-11-16T14:54:08.662903')
  assert d['arms']['baseline']['all_programs'][0]['id']==9 and d['arms']['post_rejit']['all_programs'][0]['id']==16
  assert d['arms']['post_rejit']['all_programs'][0]['bytes_jited']==12990
 result['cases'][label]=d
old=result['cases']['katran_best'];new=result['cases']['katran_current']
if 'arms' in old:
 result['katran_counter_comparison']=dict(baseline_ns_per_call_change_percent=100*(new['arms']['baseline']['ns_per_call']/old['arms']['baseline']['ns_per_call']-1),native_ns_per_call_change_percent=100*(new['arms']['post_rejit']['ns_per_call']/old['arms']['post_rejit']['ns_per_call']-1),ratio_change_percent=100*(new['baseline_over_post_per_call']/old['baseline_over_post_per_call']-1),interpretation='Arithmetic across two retained functional runs, not a controlled causal comparison. Both absolute ns/call values fell; the BPF control fell more, reducing the ratio. The ratio change does not by itself establish a native runtime regression or a compiler/linker cause.')
host=OUT/'katran-best-host.log'
result['katran_best_original_host_log']=source(host)
result['katran_best_original_host_log']['original_path']='/workspaces/kprog-raw/one-image-runs/20261116T145226Z-katran-stats1.log'
assert '20261116_145408_662903' in host.read_text()
assert 'SAMPLES=3 WORKLOAD_DURATION=180' in host.read_text()
assert '"event": "app_done", "status": "ok"' in host.read_text()
result['conclusions']=[
 'Cilium best active cil_from_contai failed both native replacements at instruction 32, source imm 0 versus loaded imm -559038242; original BPF retained. Current active target successfully replaced: 1093/1720 JIT/xlated bytes versus 1686/16. This is BPF fallback versus native, not two native bodies.',
 'Keep Cilium 1.348x as an existing functional/hybrid result. Fallback receipt does not establish a functional defect. No historical active native body exists to restore from these failed installations.',
 'Katran best target was genuinely replaced with native 12990/16; current target native 9757/16, 24.888 percent smaller. Original BPF tag 90e1a12c30a4bce5, native tag 59f4a931744dcdc6 and source hash 0325eddd38cf33c9 match across logs; tags/source hash do not establish identical native bytes.',
 'Historical Katran structured app JSON/metadata recovered exactly from S19 cleanup preservation and its best ratio recomputed from the original counters. Installed bytes and exact proof input are still not located. The same-day shared/copy-hash diagnostic used separate 210136/210724 runs with 10546/12995 bytes, not this best run. May/Nov22 call-order wrong-map evidence likewise is not proof about the Nov16 best run.',
 'No causal flag/linker explanation follows from code length or aggregate ns/call. Timing remains frozen; no app/program selector introduced.'
]
(OUT/'comparison.json').write_text(json.dumps(result,indent=2)+chr(10))
print(json.dumps({k:dict(ratio=v.get('baseline_over_post_per_call'),receipts=len(v['receipts']),app_json_present=v['app_json_present']) for k,v in result['cases'].items()},indent=2))
