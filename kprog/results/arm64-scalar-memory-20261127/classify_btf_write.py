"""Classify the remaining refusal from its failing access and kernel write policy."""
import collections
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());parent=Path(run['result']);raw=Path(run['raw'])
path=parent/'outcomes.json';data=json.loads(path.read_text());assert 'btf_write_refinement' not in data
rows=[r for r in data['requests'] if r['after']['family']=='unclassified'];assert len(rows)==1
row=rows[0];index=row['index']
wanted={str(index)+'/'+n for n in ['stock-after.verifier.log','kernel.metadata.json']}
receipt=json.loads((parent/'controller.json').read_text());found={}
parts=sorted(parent.glob('evidence.tar.zst.part-*'))
for p in parts:
 assert subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2]==subprocess.check_output(['git','hash-object',str(p)],text=True).strip()
a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
with tarfile.open(fileobj=b.stdout,mode='r|') as archive:
 for m in archive:
  p=Path(m.name)
  if not m.isfile() or p.parts[0]!=raw.name:continue
  rel=str(Path(*p.parts[1:]))
  if rel in wanted:found[rel]=archive.extractfile(m).read()
b.stdout.close();assert a.wait()==b.wait()==0 and set(found)==wanted
for name,body in found.items():
 assert receipt['archive_files'][name]==dict(bytes=len(body),sha256=hashlib.sha256(body).hexdigest())
log=found[str(index)+'/stock-after.verifier.log'].decode();metadata=json.loads(found[str(index)+'/kernel.metadata.json'])
assert metadata['load_context']['prog_type']==3 and row['after']['errno']==13
assert hashlib.sha256(log.encode()).hexdigest()==row['after']['verifier_sha256']
assert log.splitlines()[-8:]==row['after']['verifier_tail']
assert re.search(r'R2=trusted_ptr_sk_buff\(off=134\)',log)
assert log.splitlines()[-2]=='1392: (6b) *(u16 *)(r2 +0) = r1'
assert 'only read is supported' not in log
kernel=ROOT/'vendor/linux-framework';sources={}
def capture(path,start,end):
 body=(kernel/path).read_text();lines=body.splitlines();a=next(i for i,l in enumerate(lines) if start in l);z=next(i for i in range(a+1,len(lines)) if end in lines[i]);text='\n'.join(lines[a:z])
 sources[path+':'+str(a+1)]=dict(file_sha256=hashlib.sha256(body.encode()).hexdigest(),first_line=a+1,text=text)
capture('kernel/bpf/verifier.c','static int check_ptr_to_btf_access(', 'if (ret != PTR_TO_BTF_ID)')
capture('net/core/filter.c','static int tc_cls_act_btf_struct_access(', 'static bool __is_valid_xdp_access')
capture('net/core/filter.c','const struct bpf_verifier_ops tc_cls_act_verifier_ops =', 'const struct bpf_prog_ops tc_cls_act_prog_ops')
capture('net/netfilter/nf_conntrack_bpf.c','static int _nf_conntrack_btf_struct_access(', 'switch (off)')
assert not subprocess.check_output(['git','-C',str(kernel),'diff','--name-only','--','kernel/bpf/verifier.c','net/core/filter.c','net/netfilter/nf_conntrack_bpf.c'],text=True).strip()
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();out=HERE/('btf-write-'+now.replace('-','').replace(':',''));out.mkdir()
basis='Observed terminal B1392 u16 store through trusted_ptr_sk_buff(off134), SCHED_CLS type3 and EACCES. Source check_ptr_to_btf_access delegates nonallocated BTF writes to tc_cls_act_btf_struct_access; that callback returns silent EACCES when nfct provider is absent, and the current nfct provider rejects non-nf_conn types if present. Callback value/branch was not dynamically recorded.'
record=dict(utc=now,index=index,app=row['app'],request=row['request'],symbol=row['symbol'],previous_family='unclassified',family='BTF typed object write',basis=basis,limits='Names the rejected access class, not a claimed dynamic callback-pointer observation. No fabricated only-read diagnostic; exact build-to-runtime callback registration is not independently traced. Source policy plus captured type/instruction/errno supports this classification. No repair or acceptance change.',kernel_revision=subprocess.check_output(['git','-C',str(kernel),'rev-parse','HEAD'],text=True).strip(),sources=sources,evidence={n:dict(bytes=len(v),sha256=hashlib.sha256(v).hexdigest()) for n,v in found.items()},load_context=metadata['load_context'],verifier_tail=log.splitlines()[-8:])
(out/'classification.json').write_text(json.dumps(record,indent=2)+'\n')
(out/'verifier.log').write_text(log)
row['after'].update(family='BTF typed object write',classification_basis=basis,classification_evidence=str((out/'classification.json').relative_to(ROOT)))
def stats(rs):
 return dict(requests=len(rs),before=dict(collections.Counter(r['before']['status'] for r in rs)),after=dict(collections.Counter(r['after']['status'] for r in rs)),transitions=dict(collections.Counter(r['before']['status']+' -> '+r['after']['status'] for r in rs)),after_families=dict(collections.Counter(r['after']['family'] for r in rs if r['after']['status']=='refused')),fixture_before_disagreements=sum(r['before_matches_original'] is False for r in rs))
rs=data['requests'];summary=dict(all=stats(rs),original_refused=stats([r for r in rs if not r['original_stock_passed']]),accepted_controls=stats([r for r in rs if r['original_stock_passed']]),apps={app:stats([r for r in rs if r['app']==app]) for app in sorted({r['app'] for r in rs})})
assert summary['all']['transitions']==data['summary']['all']['transitions']
data['summary']=summary;data['btf_write_refinement']=dict(utc=now,evidence=str((out/'classification.json').relative_to(ROOT)),previous_family='unclassified',changed_indices=[index],remaining_unclassified=[r['index'] for r in rs if r['after']['family']=='unclassified'])
path.write_text(json.dumps(data,indent=2)+'\n')
cols=['index','app','request','symbol','original_stock_passed','original_family','before_status','before_family','after_status','after_family','before_matches_original']
with (parent/'outcomes.tsv').open('w') as f:
 f.write('\t'.join(cols)+'\n')
 for r in rs:
  flat=dict(r,before_status=r['before']['status'],before_family=r['before']['family'],after_status=r['after']['status'],after_family=r['after']['family']);f.write('\t'.join(str(flat.get(k,'')) for k in cols)+'\n')
(parent/'stock-outcome.md').write_text('# ARM scalar-memory paired verifier outcomes\n\n'+json.dumps(summary,indent=2)+'\n\n145pairedloads:28beforeacceptances preserved,17newacceptances,100refusals,no preparation errors or fixture-before disagreements. All100 refusal access/diagnostic classes now named. The last Cilium BTF typed object write is classified from its terminal trusted sk_buff u16 store/type3/EACCES and kernel write policy, with no invented only-read log line or runtime callback-pointer observation. See '+str((out/'classification.json').relative_to(ROOT))+'. Prior initial_summary/initial_family/classification_refinement and original controller/archive retain their exact earlier snapshots. Fresh maps do not establish native install/stage2/workload/performance acceptance.\n')
(out/'README.md').write_text('# Silent Cilium BTF write refusal\n\n'+basis+'\n\n'+record['limits']+'\n\nAll100 final refusals now have names: '+json.dumps(summary['all']['after_families'])+'. Acceptance remains45/145 with all28 controls preserved. Full archived log and load metadata hashes checked against committed3052-file receipt. The archive parts are retained; no RAW copy or guest/compiler/header/kernel/framework change.\n')
(LANE/'btf-write-classification.json').write_text(json.dumps(dict(result=str(out)),indent=2)+'\n')
print(json.dumps(dict(result=str(out),families=summary['all']['after_families'])),flush=True)
