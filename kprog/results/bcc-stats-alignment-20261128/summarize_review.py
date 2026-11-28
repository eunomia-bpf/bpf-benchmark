"""Summarize completed code/RO/CPU observations without pretending they prove causality."""
from pathlib import Path
import hashlib,json,re,statistics
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;PAIR=HERE/'paired-profile';x=json.loads((PAIR/'case-review.json').read_text());c=json.loads((PAIR/'controller.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();ro=[];reference=None
for case in x['cases']:
 rawcase=next(r for r in c['cases'] if r['stats']==case['stats']);run=Path(rawcase['run_dir'])
 for phase,q in case['phases'].items():
  values={}
  for m in q['readonly_maps']:
   assert len(m['queries'])==1;v=m['queries'][0];assert v['key']==0 and v['returncode']==0 and v['errno']==0;data=bytes.fromhex(v['value']);assert len(data)==m['value_size'];values[m['name']]=dict(bytes=len(data),hex=data.hex())
  assert len(values)==7;pid=int.from_bytes(bytes.fromhex(values['capable_.rodata']['hex'])[:4],'little');log=(run/'details/shim-logs'/('bcc__set.'+phase+'.log')).read_text();matches=re.findall(r'shim_init pid=(\d+) exe=\S*/capable\b',log);assert str(pid) in matches,(pid,matches)
  masked={n:dict(bytes=v['bytes'],hex=('00000000'+v['hex'][8:]) if n=='capable_.rodata' else v['hex']) for n,v in values.items()}
  if reference is None:reference=masked
  assert masked==reference;ro.append(dict(stats=case['stats'],phase=phase,map_count=7,capable_my_pid=pid,matched_actual_tool_pid=True,all_bytes_equal_after_only_own_pid_mask=True,original_snapshot=q['map_snapshot']))
account={}
for mode,r in x['long_run_cpu_accounting'].items():
 e=[s['cpu_rows']['sockfd'] for s in r['samples']['baseline']];n=[s['cpu_rows']['sockfd'] for s in r['samples']['post_rejit']];med=lambda rows,k:statistics.median(z[k] for z in rows);account[mode]=dict(ebpf_cpu_seconds_median=statistics.median(z['user_seconds']+z['system_seconds'] for z in e),native_cpu_seconds_median=statistics.median(z['user_seconds']+z['system_seconds'] for z in n),ebpf_wall_ops_median=med(e,'wall_ops_per_second'),native_wall_ops_median=med(n,'wall_ops_per_second'),ebpf_cpu_ops_median=med(e,'cpu_ops_per_second'),native_cpu_ops_median=med(n,'cpu_ops_per_second'),scope='Separate reported medians; exact per-sample raw rows remain in case-review.json. CPU-time availability/execution and CPU-normalized operation rate are descriptive, not a cause proof.')
summary=dict(profile_pid=1454977,code_comparison=x['code_shape_comparison'],all_six_instruction_shapes_equal=all(r['equal_shape'] for r in x['code_shape_comparison']),readonly_maps=ro,long_run_sockfd_cpu=account,source_anchors=[])
for name,lo,hi in [('vendor/bpf/bcc/libbpf-tools/capable.bpf.c',14,24),('vendor/bpf/bcc/libbpf-tools/capable.bpf.c',80,94),('vendor/repos/bcc/libbpf-tools/capable.c',322,333)]:
 p=ROOT/name;lines=p.read_text().splitlines();summary['source_anchors'].append(dict(path=name,sha256=sha(p),lines=[dict(line=i,text=lines[i-1]) for i in range(lo,hi+1)]))
summary['limits']=['Three observed hot programs only; unknown high-address literals are unresolved, so shape equality does not establish bound-map equality.','Seven observed RO-map values agree except my_pid, verified against each actual capable tool PID and the loader getpid producer. HASH contents and dynamic execution remain unproved.','The short profile pair is disturbed by read-only observers and showed CPU-time variation; original full-run loss must not be causally explained by the short ratio alone.','Perf143 remains explicit; SAME1456924 is validating decoding/phase/ownQEMU next. No new native bug or fix is established by these facts.']
(PAIR/'review-summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(dict(shapes_equal=summary['all_six_instruction_shapes_equal'],ro_phases=len(ro),cpu=account),indent=2))
