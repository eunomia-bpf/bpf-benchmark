#!/usr/bin/env python3
"""Collect stock-path guest receipts and independently reread the raw archive."""
from pathlib import Path
import json,hashlib,tarfile,gzip,collections,subprocess,re,argparse
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--previous',type=Path,default=Path('/var/tmp/kprog-tmp/S17'))
parser.add_argument('--current',type=Path,default=Path('/var/tmp/kprog-tmp/S18'))
parser.add_argument('--out',type=Path)
args=parser.parse_args()
R=Path('/workspaces/repository');O=args.previous;N=args.current
D=args.out or N/'collected';D.mkdir(parents=True,exist_ok=True)
K=Path('/var/tmp/kprog-tmp/CK/linux')

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
reference=json.loads((R/'kprog/results/kprog_recovery_safety_20261109/outcomes.json').read_text())
reference['arm64']=json.loads((R/'corpus/results/kprog_arm64_app_coverage_20261109/implicit-sp-release/outcomes.json').read_text())
summaries={};tables={}
for isa,label in [('x86','x86-current'),('arm64','arm64-final')]:
 rows=json.loads((O/'run'/label/'outcomes.json').read_text());assert len(rows)==48
 ref={r['name']:r for r in reference[isa]};table=['case\tnegative\tstock_stage\tkinsn_stage\tstock_returncode\tnative_test_run\tresult_note']
 diffs=[]
 for r in rows:
  peer=ref.get(r['name']);other=peer['stage'] if peer else 'additional_positive_control'
  executed=not r['negative'] and r['stage']=='valid_executed'
  note='stock_allow_uninit_stack_CAP_PERFMON' if r['name']=='uninitialized_stack' and r['stage']=='accepted_finding' else ''
  table.append(f"{r['name']}\t{int(r['negative'])}\t{r['stage']}\t{other}\t{r['returncode']}\t{int(executed)}\t{note}")
  if peer and other!=r['stage']:diffs.append(dict(case=r['name'],stock=r['stage'],kinsn=other))
  assert not r.get('unsafe_native_executed')
  assert (len(r['command'])==3)==r['negative']
 tables[isa]=rows
 (D/(isa+'-cases.tsv')).write_text('\n'.join(table)+'\n')
 (D/(isa+'-outcomes.json.gz')).write_bytes(gzip.compress(json.dumps(rows,indent=2).encode(),mtime=0))
 summaries[isa]=dict(cases=len(rows),stages=dict(collections.Counter(r['stage'] for r in rows)),negative_native_test_run=0,stage_differences=diffs,suite_exit=int((O/'run'/label/'suite.exit').read_text()),reference=('corpus/results/kprog_arm64_app_coverage_20261109/implicit-sp-release/outcomes.json' if isa=='arm64' else 'kprog/results/kprog_recovery_safety_20261109/outcomes.json'))
def error_receipt(root):
 records=[json.loads(line) for line in (root/'requests/requests.jsonl').read_text().splitlines()]
 assert len(records)==1, str(root)+': expected one completed request'
 record=records[0]
 field='failure_archive' if record['status'] else 'artifact_archive'
 archive=root/'requests'/Path(record[field]).name
 with tarfile.open(archive) as t:log=t.extractfile('request/load.stderr').read().decode()
 return record,log,archive

errors={}
for isa in ['x86','arm64']:
 for profile in ['multi-once','jit-error']:
  label=isa+'-'+profile+('-kernel' if isa=='arm64' and profile=='jit-error' else '')
  root=(N if isa=='x86' and profile=='jit-error' else O)/'run'/label
  rc=int((root/'client.exit').read_text());assert rc!=0
  record,log,archive=error_receipt(root)
  assert record['status']<0, str(root)+': expected service load error'
  assert log.count('stock-armed-load-attempt=1')==1
  assert 'diagnostic BPF_PROG_LOAD:' not in log
  if profile=='jit-error':assert 'processed ' in log and 'Unknown error 524' in log
  errors[isa+'-'+profile]=dict(client_exit=rc,service_status=record['status'],archive=archive.name,raw_load_attempts=1,worker_error=log.splitlines()[:4],native_test_run=0,verifier_completed='processed ' in log)
 for label in ['small','null-btf']:
  if isa=='arm64':root=O/'run'/('arm64-'+label+'-once');path=root/('client.exit' if label=='small' else 'probe.exit');assert int(path.read_text())==0
unarmed={isa:dict(exit=int((O/'run'/(isa+'-multifunction')/'unarmed.exit').read_text()),log=(O/'run'/(isa+'-multifunction')/'unarmed.log').read_text()) for isa in ['x86','arm64']}
assert all(x['exit']==0 for x in unarmed.values())
tail=O/'run/x86-tail-current';assert int((tail/'client.exit').read_text())==0
tail_rows=[json.loads(s) for s in (tail/'client.out').read_text().splitlines()];assert tail_rows[0]==dict(jit_stack_depth=0,jit_stack_pop=0)
assert all(r['retval']==2 and r['invocations']==34 and r['tail_transfers']==33 for r in tail_rows[1:])
frame=N/'run/x86-tail-frame'
assert int((frame/'client.exit').read_text())==0
frame_log=(frame/'dmesg').read_text()
frame_match=re.search(r'stock_tail_frame: retval=(\d+) r12_preserved=(\d+) rsp_preserved=(\d+) rbp_preserved=(\d+)',frame_log)
assert frame_match and tuple(map(int,frame_match.groups()))==(2,1,1,1)
frame_state=dict(zip(['retval','r12_preserved','rsp_preserved','rbp_preserved'],map(int,frame_match.groups())))
(D/'tail-frame-disassembly.txt').write_bytes(subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64',str(frame/'native.bin')]))
kernel_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=K,text=True).strip();blob=subprocess.check_output(['git','hash-object','kernel/bpf/verifier.c'],cwd=K,text=True).strip();base_blob=subprocess.check_output(['git','rev-parse','c23719abc330:kernel/bpf/verifier.c'],cwd=K,text=True).strip();assert blob==base_blob
diffstat=subprocess.check_output(['git','diff','c23719abc330','--stat'],cwd=K,text=True);(D/'kernel-diffstat.txt').write_text(diffstat)
patch=subprocess.check_output(['git','diff','c23719abc330','--binary'],cwd=K);(D/'kernel.patch').write_bytes(patch)
for isa in ['x86','arm64']:
 config=O/(isa+'-build/.config');assert 'CONFIG_BPF_JIT_ALWAYS_ON=y' in config.read_text();(D/(isa+'-kernel.config.gz')).write_bytes(gzip.compress(config.read_bytes(),mtime=0))
artifacts={}
for name in ['x86-build/arch/x86/boot/bzImage','arm64-build/arch/arm64/boot/Image','mod/kprog_stock.ko','arm64-mod/kprog_stock.ko','loader-once/build/trusted-native-loader','arm64-loader-once/build/trusted-native-loader','native-link','cargo/aarch64-unknown-linux-gnu/release/native-link','bp/bound-probe','arm64-input/bound-probe-current']:
 p=O/name;artifacts[name]=dict(sha256=sha(p),bytes=p.stat().st_size)
summary=dict(lane='S18',artifact_identities=artifacts,kernel_commit=kernel_commit,kernel_base='c23719abc330',verifier_blob=blob,verifier_base_blob=base_blob,kernel_diffstat=diffstat,stock_loader_patch='d140d92ab',source_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip(),suites=summaries,load_error_tests=errors,unarmed_subprogram_controls=unarmed,tail=tail_rows,physical_tail_frame=frame_state,credentials=json.loads((R/'kprog/stock-path/results/20261109/credentials-summary.json').read_text()),arm64_small=json.loads((O/'run/arm64-small-once/client.out').read_text()),arm64_null_btf=json.loads((O/'run/arm64-null-btf-once/probe.out').read_text()),arm64_null_fixture_diagnostic='The inherited direct-invocation fixture emits its migration-context debug trace and completes control/null checks; raw console retains the trace.',runtime_scope='Finite runtime receipts for the ordinary-B path. Shared universal compiler/physical-call/successful-tail composition stays with V and its existing ledger.',formal_check_slot='V retains the sole full check; S18 changes stock-path fixtures and receipt collection.',guest=dict(memory_mib=2048,max_own_guests=1,host_cpu_affinity='S18:x86-8-23;inherited-S17:ARM8-23,x86-8-15'))
# Retain the original accepted injection as a separate measured receipt.
old_record,old_log,old_archive=error_receipt(O/'run/x86-jit-error')
summary['original_x86_jit_injection']=dict(client_exit=int((O/'run/x86-jit-error/client.exit').read_text()),service_status=old_record['status'],archive=old_archive.name,observation='Offset0 kind1 target1 follows x86 rel32 arithmetic and produces an installed image; client records a TEST_RUN return mismatch')
summary['physical_frame_fixture']=json.loads((R/'kprog/stock-path/results/20261109/s18-tail-frame-summary.json').read_text())
summary['jit_error_fixture']=json.loads((R/'kprog/stock-path/results/20261109/s18-jit-error-summary.json').read_text())
for name in ['frameprobe/build/tail_frame_probe.ko','jit-error-x86/trusted-native-loader']:
 p=N/name;artifacts['S18/'+name]=dict(sha256=sha(p),bytes=p.stat().st_size)
summary['integration_tests']={
 'x86-physical-tail-frame':dict(fixture_exit=0,**frame_state),
 **{name:dict(fixture_exit=0,**row) for name,row in errors.items()}}
lines=['case\tfixture_exit\tclient_exit\tservice_status\traw_load_attempts\tverifier_completed\tnative_test_run']
# The tail-frame run used the ordinary loader, so its load-attempt cell stays unmeasured.
lines.append('x86-physical-tail-frame\t0\t0\t0\t-\t1\t1')
for name,row in errors.items():
 lines.append(f"{name}\t0\t{row['client_exit']}\t{row['service_status']}\t{row['raw_load_attempts']}\t{int(row['verifier_completed'])}\t0")
(D/'integration-cases.tsv').write_text('\n'.join(lines)+'\n')
# Preserve both source epochs, every terminal request and each original setup diagnostic.
# loader-once/kinsn links to the live shared tree, so only the headers the loader includes are archived.
include=['run','arm64-source','arm64-source2','x86-source','x86-mode-diagnostic-x86-source','loader-once/kprog/libnativeloader/src','loader-once/kprog/libnativeloader/include','loader-once/kprog/trusted_loader.cpp','loader-once/kprog/test','loader-once/kinsn/module/include','once-fixture-source','multifunction-source','x86-input','arm64-input','tail','frameprobe/module','frameprobe/client.cpp','frameprobe/client','frameprobe/build/tail_frame_probe.ko']
include += [p.name for p in O.iterdir() if p.is_file() and (p.suffix in ['.py','.sh','.log','.json','.exit'] or 'source-commit' in p.name)]
current=['run','source','setup-first','frameprobe/disassembly.txt','frameprobe/original-disassembly.txt','frameprobe/build/tail_frame_probe.ko','jit-fixture/kprog/libnativeloader/src/native_loader.cpp','jit-error-x86/trusted-native-loader']
current += [p.name for p in N.iterdir() if p.is_file() and p.suffix in ['.py','.sh','.log','.json','.exit']]
members={}
with tarfile.open(D/'current-raw.tar.gz','w:gz') as t:
 for source,names in [(O,include),(N,current)]:
  for name in names:
   p=source/name
   files=sorted(q for q in p.rglob('*') if q.is_file()) if p.is_dir() else [p]
   for q in files:
    if q.name.endswith('.core'):continue
    rel=source.name+'/'+str(q.relative_to(source))
    t.add(q,arcname=rel,recursive=False);members[rel]=sha(q)
with tarfile.open(D/'current-raw.tar.gz') as t:
 for m in t.getmembers():
  if m.isfile():assert hashlib.sha256(t.extractfile(m).read()).hexdigest()==members[m.name]
manifest=dict(sha256=sha(D/'current-raw.tar.gz'),bytes=(D/'current-raw.tar.gz').stat().st_size,members=members)
(D/'archive-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
summary['raw_collection']=dict(exit=0,archive='current-raw.tar.gz',sha256=manifest['sha256'],members=len(members),independently_reread=len(members))
(D/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps({k:summary[k] for k in ['lane','suites','load_error_tests','physical_tail_frame','raw_collection']},indent=2))
