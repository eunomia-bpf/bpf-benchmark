"""Derived work evidence for one immutable closed-case collection; preserve timing/semantic gaps."""
from pathlib import Path
import collections,hashlib,json,re,struct,sys
HERE=Path(__file__).resolve().parent;collection=Path(sys.argv[1]);c=json.loads(collection.read_text());r=dict(collection=str(collection),collection_sha256=hashlib.sha256(collection.read_bytes()).hexdigest(),cases=[],scope='Closedcases of1481233, actualrequests/workload/programs/sparsework evidence only; no automatic event/path equivalence or performance acceptance.')
for item in c['new_cases']:
 p=Path(item['review']['path']);d=json.loads(p.read_text());assert hashlib.sha256(p.read_bytes()).hexdigest()==item['review']['sha256'];n=d['native_requests'];redirects=[];helpers=[];remaining=[]
 for x in n['unclassified_native_loader_lines']:
  if 'native-loader redirected OBJ_GET_INFO_BY_FD ' in x['text']:redirects.append(x)
  elif 'native-loader skipped runtime helper program ' in x['text']:helpers.append(x)
  else:remaining.append(x)
 row=dict(app=item['app'],review=item['review'],guest_exit=item['case']['guest-exit.txt'],app_status=d['app_status'],image=d['image'],native_counts=n['counts'],success_id_associations_complete=n['success_id_associations_complete'],original_terminal_counts_complete=n['terminal_counts_complete'],metadata_redirect_count=len(redirects),metadata_redirect_results=dict(collections.Counter('ret='+a[1]+' errno='+a[2] for x in redirects if (a:=re.search(r'ret=(-?\d+) errno=(\d+)',x['text'])))),runtime_helpers_skipped=len(helpers),install_classification_complete_after_metadata_filter=not remaining,remaining_unclassified=remaining,phases={})
 for ph,x in d['phases'].items():
  captured={j['id'] for s in x['observations'] for j in s['jit_files']};active=[v for v in x['programs'].values() if v.get('run_cnt_delta',0)>0];observations=[]
  for s in x['observations']:
   m=json.loads(Path(s['map_snapshot']['path']).read_text()) if s['map_snapshot'] else None;policy=[]
   if m:
    for mp in m['maps']:
     if mp['name']=='policy_stats' and mp['value_size']==80:
      for q in mp['queries']:
       if q['returncode']==0:policy.append(dict(map_id=mp['id'],post_count=int.from_bytes(bytes.fromhex(q['value'])[8:16],'little')))
   observations.append(dict(path=s['path'],start=s['started_monotonic'],end=s['ended_monotonic'],entire_snapshot_inside_window=s['entire_snapshot_inside_window'],map_uptime=float(m['uptime']) if m else None,map_inside_window=bool(m and x['window']['start']<=float(m['uptime'])<=x['window']['end']),command_returncodes=[z['returncode'] for z in s['commands']],jit_count=len(s['jit_files']),jit_size_mismatches=sum(z['size_matches'] is False for z in s['jit_files']),function_length_mismatches=sum(z['function_sizes_match'] is False for z in s['jit_files']),policy_post_counts=policy,policy_post_sum=sum(z['post_count'] for z in policy) if policy else None))
  packets=[]
  for w in x['workers']:
   found=re.findall(r'pkts-sofar:\s*(\d+)\s+errors:\s*(\d+)',w.get('stdout',''))
   if found:packets.append(dict(packets=int(found[-1][0]),errors=int(found[-1][1]),returncode=w.get('returncode')))
  hot=sorted([v for v in active if v['name']=='cil_from_contai'],key=lambda v:v['run_cnt_delta']);packets=sorted(packets,key=lambda v:v['packets']);packetmatch=[]
  if len(hot)==len(packets)==2:packetmatch=[dict(program_id=a['id'],calls=a['run_cnt_delta'],packets=b['packets'],extra_calls=a['run_cnt_delta']-b['packets'],send_errors=b['errors']) for a,b in zip(hot,packets)]
  row['phases'][ph]=dict(window=x['window'],worker_returncodes=[w.get('returncode') for w in x['workers']],worker_durations=[w.get('duration_s') for w in x['workers']],active_programs=len(active),active_programs_with_jit=sum(v['id'] in captured for v in active),active_programs_without_jit=[v for v in active if v['id'] not in captured],active_program_counters=active,observations=observations,cilium_packet_to_entry=packetmatch)
 if 'useful_unwind' in d:
  row['unwind']={ph:dict(metric_growth=x['metric_growth'],max_stack_len=x['max_stack_len'],max_tail_calls=x['max_tail_calls'],prog_array_targets=[a for s in x['rows'] for a in s['program_arrays']]) for ph,x in d['useful_unwind']['phases'].items()}
 if 'useful_unwind_error' in d:row['unwind_error']=d['useful_unwind_error']
 r['cases'].append(row)
r['totals']={k:sum(x['native_counts'][k] for x in r['cases']) for k in ['checked','direct_installed','failed','feature_probes_skipped']};r['limits']=['Tetragon redirected infoqueries and skipped runtimehelper are metadata/probe messages, not extra installrequests; original parserunknownlines are preserved in reviews.','Snapshotcode/cache copy can cross a phase; per-mapuptime and missingactiveJIT IDs make gaps explicit. Do not equate files or controller0 with samework.','Tetragon native measure_start->finish includes a long pre-work interval; early1s/8s snapshots may not cover its10s stresswork. Captured policyPOST counters alone do not establish work-phase POST action growth here.','Positive OTel attempt/framegrowth and stacks/tails demonstrate actual unwinding engagement in botharms, not exactdynamic equivalence or everyinterpreter/eventdelivery.','Cilium bothhot entrycounts match workerpackets up to11-12extra calls; startupone-call controlprogram counts differ. This is engagement evidence, not full packetpath semantics.','All short ratios under the proven varyinghost scheduling environment are diagnostics only; checkedB/stock-verifier coverage remains zero for this unboundcheck.']
with collection.with_name('summary.json').open('x') as f:f.write(json.dumps(r,indent=2)+'\n')
md=['# Collected closed cases on current image','',r['scope'],'','|app|checked|direct installs|failed|active eBPF/native|guest/app|','|---|---:|---:|---:|---:|---|']
for x in r['cases']:
 n=x['native_counts'];md.append(f"|{x['app']}|{n['checked']}|{n['direct_installed']}|{n['failed']}|{x['phases']['baseline']['active_programs']}/{x['phases']['post_rejit']['active_programs']}|{x['guest_exit']}/{x['app_status']}|")
md+=['','Tetragon has864 redirected OBJ_GET_INFO_BY_FD metadata messages and1 skipped runtimehelper; these are not extra native installrequests. Original unknown messages remain in immutable review; derived classifications and returncodes are in summary.json.','',*r['limits'],'','The chain may still be active. Only the immutable new_cases listed in this collection are covered; do not call all-six complete or start duplicate checks. Full raw/corpus archival follows committed result publication; originals/prior-staging remain.']
collection.with_name('work-evidence.md').write_text('\n'.join(md)+'\n');print(json.dumps(dict(totals=r['totals'],apps=[x['app'] for x in r['cases']]),indent=2))
