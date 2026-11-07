"""Whole-application finite-dispatch coverage from closed common-service archives."""
from pathlib import Path
from collections import Counter
from datetime import datetime,timezone
import hashlib,io,json,re,tarfile
R=Path(__file__).resolve().parents[4];D=Path(__file__).resolve().parent
def sha(data):return hashlib.sha256(data).hexdigest()
def read(ar,name):
 try:m=ar.getmember(name)
 except KeyError:return None
 return ar.extractfile(m).read() if m.isfile() else None
def metrics(source):
 blocks=re.findall(r'/\* 0x[0-9a-f]+: ([^\n]*?) \*/\n(.*?)(?=\narm64_l_[0-9a-f]+:|\Z)',source,re.S)
 counts=Counter();hist=Counter();helpers=Counter();local_targets=Counter()
 for native,body in blocks:
  opcode=native.split()[0]
  if opcode not in {'br','blr'}:continue
  counts[opcode]+=1
  code=re.findall(r'case (0x[0-9a-f]+)ULL: (?:ARM64_SIM_A64_CALL|goto)',body)
  calls=re.findall(r'case ([0-9]+)ULL: [^\n]*?ARM64_SIM_BPF_CALL_(bpf_[a-z0-9_]+)\(\);',body)
  counts['code_target_arms']+=len(code);counts['helper_target_arms']+=len(calls)
  hist[len(code)+len(calls)]+=1
  helpers.update(name for _,name in calls);local_targets.update(code)
  counts['tag_partitioned_sites']+=int('== ARM64_SIM_TAG_CODE' in body)
  counts['register_read_sites']+=int('__a64_target = ARM64_SIM_L_READ_REG(' in body)
  switches=body.count('switch (__a64_target)')
  defaults=body.count('default: ARM64_SIM_L_REJECT_PC(); break;')
  counts['switches']+=switches;counts['reject_defaults']+=defaults
  counts['two_switch_two_default_sites']+=int(switches==2 and defaults==2)
  all_cases=re.findall(r'\bcase\b',body)
  counts['classified_literal_case_sites']+=int(len(all_cases)==len(code)+len(calls))
 returns=re.findall(r'^\s*ARM64_SIM_A64_RET_TO\([^,]+, (ARM64_SIM_RET_CASES_[0-9a-f]+)\);',source,re.M)
 definitions=dict(re.findall(r'^#define (ARM64_SIM_RET_CASES_[0-9a-f]+) ([^\n]*)',source,re.M))
 # Empty return case lists retain their macro name with a trailing space.
 definitions.update({x:'' for x in re.findall(r'^#define (ARM64_SIM_RET_CASES_[0-9a-f]+)[ \t]*$',source,re.M)})
 rh=Counter()
 for name in returns:
  if name in definitions:rh[len(re.findall(r'\bcase 0x[0-9a-f]+ULL:',definitions[name]))]+=1
 counts['return_sites']=len(returns);counts['return_sites_with_finite_case_macro']=sum(rh.values())
 counts['raw_target_register_reads']=source.count('__u64 __a64_target = ARM64_SIM_L_READ_REG(')
 return {'counts':dict(counts),'target_count_histogram':dict(sorted(hist.items())),'return_target_count_histogram':dict(sorted(rh.items())),'helper_target_histogram':dict(sorted(helpers.items())),'distinct_local_target_offsets':len(local_targets)}
folders={'bcc':R/'corpus/results/kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result'}
for app in ['otelcol-ebpf-profiler','cilium','tetragon','katran','tracee']:
 folders[app]=D.parent/('trusted-arm64-'+app+'-result')
output={'utc':datetime.now(timezone.utc).isoformat(),'scope':'Whole-application first-pass finite-dispatch source coverage from original common-service runtime artifacts. Universal O1/O2/O4 theorem work continues.','collector_source_sha256':sha(Path(__file__).read_bytes()),'applications':[]}
for app,folder in folders.items():
 summary_path=folder/'summary.json'
 if not summary_path.exists():
  output['applications'].append({'app':app,'state':'running_or_queued'});continue
 summary=json.loads(summary_path.read_text());archive=folder/summary['archive'];blob=archive.read_bytes();assert sha(blob)==summary['archive_sha256']
 counters=Counter();bound_counts=Counter();bound_hist=Counter();bound_rh=Counter();hist=Counter();rh=Counter();helpers=Counter();stages=Counter();source_count=bound_sources=bound_indirect_sources=0;source_bytes=0;digest_rows=[]
 with tarfile.open(fileobj=io.BytesIO(blob)) as ar:
  raw=read(ar,'run/requests/requests.jsonl');receipts=[json.loads(x) for x in raw.decode().splitlines()] if raw else []
  for receipt in receipts:
   request_name=Path(receipt.get('artifact_archive') or receipt['failure_archive']).name
   compressed=read(ar,'run/requests/'+request_name);assert compressed is not None
   with tarfile.open(fileobj=io.BytesIO(compressed)) as request:
    src=read(request,'request/generated/trusted_arm64.bpf.c')
    stages['bound' if receipt['status']==0 else 'refused']+=1
    if src is None:continue
    result=metrics(src.decode());source_count+=1;source_bytes+=len(src)
    if receipt['status']==0:
     bound_sources+=1;bound_counts.update(result['counts']);bound_hist.update({int(k):v for k,v in result['target_count_histogram'].items()});bound_rh.update({int(k):v for k,v in result['return_target_count_histogram'].items()})
     bound_indirect_sources+=int(result['counts'].get('br',0)+result['counts'].get('blr',0)>0)
    counters.update(result['counts']);hist.update({int(k):v for k,v in result['target_count_histogram'].items()});rh.update({int(k):v for k,v in result['return_target_count_histogram'].items()});helpers.update(result['helper_target_histogram'])
    digest_rows.append({'request_archive':request_name,'request_archive_sha256':sha(compressed),'generated_source_sha256':sha(src)})
 row={'app':app,'state':'closed','host_reported_ok':summary['ok'],'guest_exit':summary.get('guest_exit'),'raw_archive':str(archive.relative_to(R)),'raw_archive_sha256':sha(blob),'source_summary_sha256':sha(summary_path.read_bytes()),'terminal_requests':len(receipts),'request_status_counts':dict(stages),'generated_source_artifacts':source_count,'generated_source_bytes':source_bytes,'bound_source_artifacts':bound_sources,'bound_sources_with_indirect_dispatch':bound_indirect_sources,'counts':dict(counters),'bound_counts':dict(bound_counts),'bound_target_count_histogram':dict(sorted(bound_hist.items())),'bound_return_target_count_histogram':dict(sorted(bound_rh.items())),'target_count_histogram':dict(sorted(hist.items())),'return_target_count_histogram':dict(sorted(rh.items())),'helper_target_histogram':dict(sorted(helpers.items())),'source_artifact_digests':digest_rows}
 output['applications'].append(row)
(D/'summary.json').write_text(json.dumps(output,indent=2)+chr(10))
print(json.dumps([{k:r[k] for k in ['app','state','terminal_requests','generated_source_artifacts','bound_sources_with_indirect_dispatch','counts'] if k in r} for r in output['applications']],indent=2))
