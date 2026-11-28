"""Resolve only the anonymous-BTF comparison gap; reuse the completed census."""
from pathlib import Path
import collections,hashlib,json,os,resource,subprocess,traceback
from audit import btf_fields,compare,sha,now,ROOT,OUT
os.sched_setaffinity(0,{19})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,commands=[],corrected_objects={})
def save():(OUT/'btf-resolution-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 prep=json.loads((OUT/'btf-resolution-preparation.json').read_text());raw=json.loads((OUT/'controller.json').read_text());rows=json.loads((OUT/'per-program.json').read_text())
 for n,x in prep['raw_outputs'].items():assert sha(OUT/n)==x['sha256'],n
 for n,h in raw['source_sha256'].items():assert sha(ROOT/n)==h,n
 btf={}
 def limit():resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
 for arch,k in raw['kernel_layouts'].items():
  path=Path(k['path']);assert sha(path)==k['sha256'];args=[str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'-j','btf','dump','file',str(path),'format','raw'];p=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,preexec_fn=limit);(OUT/(arch+'-btf-resolution.stderr')).write_bytes(p.stderr);r['commands'].append(dict(args=args,exit=p.returncode,cpu=19,address_space_bytes=48*1024**3));assert p.returncode==0
  types=json.loads(p.stdout)['types'];btf[arch]={n:btf_fields(types,n) for n in json.loads((OUT/k['fields_file']).read_text())};(OUT/(arch+'-btf-resolved.json')).write_text(json.dumps(btf[arch],indent=2)+'\n')
 totals=collections.Counter();reachable_totals=collections.Counter();decldiff=[];reachable={}
 for row in rows:
  reachable.setdefault(row['object'],set()).update(i for c in row['candidates'] for i in c['typed_field_gep_indices'])
 for x in raw['objects']:
  a=json.loads((OUT/x['analysis_file']).read_text());assert sha(ROOT/x['object'])==x['sha256'];updated=[]
  for i,g in enumerate(a['typed_field_geps']):
   typ=g['llvm_type'].split('.',1)[1].split('.')[0];cs=[]
   for c in g['layout_candidates']:
    possible=[lay for lay in a['declared_layouts'] if lay['name']==typ and lay['size']==c['layout_size'] and len(lay['fields'])==g['llvm_element_count']]
    for lay in possible:
     f=lay['fields'][g['field_index']];v=compare(lay,f,btf[a['architecture']]);totals[v['status']]+=1
     if i in reachable[x['object']]:reachable_totals[v['status']]+=1
     cs.append(dict(field_name=f['name'],field_offset=f['offset'],comparison=v))
   updated.append(dict(gep_index=i,function=g['function'],reachable_from_manifest_candidate=i in reachable[x['object']],comparisons=cs))
  for lay in a['declared_layouts']:
   for f in lay['fields']:
    v=compare(lay,f,btf[a['architecture']])
    if v['status']=='declared-offset-differs':decldiff.append(dict(object=x['object'],context_type=lay['name'],field=f['name'],comparison=v))
  r['corrected_objects'][x['object']]=updated
 r.update(comparison_counts=dict(totals),candidate_reachable_comparison_counts=dict(reachable_totals),declared_offset_differences=decldiff,original_job_launcher=1398321,original_controller=1398323,scope='BTF expansion repair only. Raw DWARF/IR/callgraph/perprogram outputs unchanged; addendum indices refer to original GEPs. No pointer origin/branch/width/installed/full-parity proof.',controller_status=0)
 for n,x in prep['raw_outputs'].items():assert sha(OUT/n)==x['sha256'],n
 for n,h in raw['source_sha256'].items():assert sha(ROOT/n)==h,n
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
