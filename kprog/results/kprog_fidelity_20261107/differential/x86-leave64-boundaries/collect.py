from pathlib import Path
from datetime import datetime,timezone
import collections,csv,gzip,hashlib,json,subprocess,tarfile
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent;B=R/'kprog/fidelity/build-x86-leave64-boundaries';F=Path('/workspaces/.agent-state/kprog-lanes/F')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def emit(p,d):p.write_text(json.dumps(d,indent=2)+'\n')
def symbols(p):
 return {v[2]:int(v[0],16) for line in subprocess.check_output(['nm',p],text=True).splitlines() if len(v:=line.split())==3}
def table(p,rows):
 with p.open('w') as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n');w.writeheader();w.writerows(rows)
for name in ['leave64-boundaries.exit','leave64-address-control.exit','leave64-boundaries-kvm.exit','leave64-default-check.exit']:assert (F/name).read_text().strip()=='0',name
sym=symbols(B/'leave64');ctrl=symbols(B/'address-control');assert sym['leave_next']==sym['leave_pc']+1
native_asm=subprocess.check_output(['objdump','-d','-Mintel','--disassemble=observe_leave',B/'leave64'],text=True)
assert any(line.split(':',1)[0].strip()==format(sym['leave_pc'],'x') and line.split(':',1)[1].strip().split()[:2]==['c9','leave'] for line in native_asm.splitlines() if ':' in line)
all_classes=[];all_controls=[];profiles={}
for name,root,classes in [('host_lass',O,33),('kvm_without_lass',O/'kvm-clearcpuid-lass',33),('default_mode',O/'baseline',8)]:
 counts=collections.defaultdict(collections.Counter);seen=collections.defaultdict(set)
 for line in (root/'cases.jsonl').open():
  row=json.loads(line);initial=row['input'];observed=row['observed'];group=row['input_class'];assert row['case'] not in seen[group];seen[group].add(row['case']);c=counts[group];c['cases']+=1
  assert not row['memory_changed'] and not row['success_mismatch']
  if row['signal']:
   assert observed['registers']==initial['registers'];assert observed['flags']&~(1<<16)==initial['flags'];assert row['fault_pc']==sym['leave_pc'];c['faults']+=1;c['trap'+str(row['trap'])]+=1
  else:
   expected=initial['registers'].copy();assert len(row['readable_bytes'])==8;expected[4]=(expected[5]+8)&((1<<64)-1);expected[5]=int.from_bytes(bytes(row['readable_bytes']),'little');assert observed['registers']==expected and observed['flags']==initial['flags'];c['successes']+=1
  assert row['next_pc']==sym['leave_next']
 assert len(counts)==classes and all(v==set(range(1024)) for v in seen.values())
 for group,c in counts.items():all_classes.append(dict(profile=name,input_class=group,cases=c['cases'],successes=c['successes'],faults=c['faults'],trap12=c['trap12'],trap13=c['trap13'],trap14=c['trap14'],other_traps=sum(v for k,v in c.items() if k.startswith('trap') and k not in ['trap12','trap13','trap14']),state_mismatches=0,memory_writes=0))
 profiles[name]=dict(classes=classes,cases=classes*1024,successes=sum(c['successes'] for c in counts.values()),faults=sum(c['faults'] for c in counts.values()),state_mismatches=0,memory_writes=0,raw_cases_sha256=sha(root/'cases.jsonl'))
 if name=='default_mode':continue
 control_counts=collections.defaultdict(collections.Counter)
 rows=list(csv.DictReader((root/'control-cases.tsv').open(),delimiter='\t'));assert len(rows)==2048
 for row in rows:
  instruction=row['instruction'];pc=ctrl['control_ds_pc' if instruction=='mov_ds' else 'control_ss_pc'];assert int(row['fault_pc'])==(pc if int(row['signal']) else 0)
  control_counts[(row['input_class'],instruction)][int(row['trap'])]+=1
 assert len(control_counts)==64 and all(sum(c.values())==32 for c in control_counts.values())
 for (group,instruction),c in control_counts.items():all_controls.append(dict(profile=name,input_class=group,instruction=instruction,cases=sum(c.values()),successes=c[0],trap12=c[12],trap13=c[13],trap14=c[14],other_traps=sum(v for k,v in c.items() if k not in [0,12,13,14])))
 profiles[name]['control_cases']=2048
 profiles[name]['address_profile']=json.loads((root/'address-profile.json').read_text());profiles[name]['control_profile']=json.loads((root/'control-profile.json').read_text())
table(O/'traps.tsv',all_classes);table(O/'control-traps.tsv',all_controls)
flags=next(l.split(':',1)[1].split() for l in Path('/proc/cpuinfo').read_text().splitlines() if l.startswith('flags'));emit(O/'linux-profile.json',dict(lass_linux_flag='lass' in flags,la57_linux_flag='la57' in flags,privilege='ordinary userspace/CPL3; CR4 not directly observed'))
assert 'lass' in flags and not json.loads((O/'kvm-clearcpuid-lass/linux-profile.json').read_text())['lass_linux_flag']
for profile in ['host_lass','kvm_without_lass']:
 assert profiles[profile]['address_profile']['cpuid_linear_address_bits']==48 and profiles[profile]['address_profile']['cpuid_la57_supported']==0
assert profiles['host_lass']['control_profile']['cpuid_lass_supported']==1 and profiles['kvm_without_lass']['control_profile']['cpuid_lass_supported']==0
before=json.loads((O/'kvm-clearcpuid-lass/input-pins-before.json').read_text());after={p:sha(R/p) for p in before};assert before==after;emit(O/'kvm-clearcpuid-lass/input-pins-after.json',after)
lookup={(r['profile'],r['input_class']):r for r in all_classes}
for profile in ['host_lass','kvm_without_lass']:
 assert lookup[profile,'low48_last_word']['trap14']==1024
 for i in range(1,8):assert lookup[profile,'low48_cross_'+str(i)]['trap12']==1024
for group in ['high48_canonical_first','wrap_last_word']+['wrap_cross_'+str(i) for i in range(1,8)]:
 assert lookup['host_lass',group]['trap12']==1024 and lookup['kvm_without_lass',group]['trap14']==1024
summary=dict(recorded=datetime.now(timezone.utc).isoformat(),instruction_form='C9 LEAVE64, one instruction form',profiles=profiles,leave_cases=75776,control_cases=4096,cpu_binary_sha256=sha(B/'leave64'),control_binary_sha256=sha(B/'address-control'),canonical_comparison='not yet run for boundary dataset; V rule fix pending',wrap_conclusion='all eight KVM wrap groups trap14; a nonwrap-to-SS guard contradicts observed faults',limitations=['48-bit hardware only; numeric 57-bit addresses do not establish LA57 execution','Host LASS and KVM-no-LASS are separate CPL3 platform profiles','No successful wrapped load, CPL0 wrapper, complete JIT ABI or per-operation simulator proof claimed'])
emit(O/'summary.json',summary)
for root in [O,O/'baseline',O/'kvm-clearcpuid-lass']:
 for name in ['cases.jsonl','run.log','host.txt','control.log']:
  p=root/name
  if p.exists():(root/(name+'.gz')).write_bytes(gzip.compress(p.read_bytes(),mtime=0))
(O/'native.asm.gz').write_bytes(gzip.compress(native_asm.encode(),mtime=0))
control_asm=subprocess.check_output(['objdump','-d','-Mintel',B/'address-control'],text=True);(O/'control.asm.gz').write_bytes(gzip.compress(control_asm.encode(),mtime=0))
for source,name in [(B/'leave64','leave64-x86.gz'),(B/'address-control','address-control-x86.gz')]:(O/name).write_bytes(gzip.compress(source.read_bytes(),mtime=0))
assert sha(R/'kprog/fidelity/build-x86-leave64/leave64')=='308f484b26db4e7c2537b1228ba837e026a22a2b7de875449e44c7f17a7da3d5'
paths=['kprog/fidelity/leave64.c','kprog/fidelity/leave64.S']+[str((O/p).relative_to(R)) for p in ['Makefile','address_control.c','control-inputs.tsv','guest.sh','collect.py']]
manifest={p:dict(size=(R/p).stat().st_size,sha256=sha(R/p)) for p in paths};emit(O/'compiled-inputs.json',manifest)
with tarfile.open(O/'compiled-inputs.tar.gz','w:gz') as t:
 for p in paths:t.add(R/p,arcname=p,recursive=False)
with tarfile.open(O/'compiled-inputs.tar.gz') as t:
 for p,d in manifest.items():assert hashlib.sha256(t.extractfile(p).read()).hexdigest()==d['sha256']
root_names=['README.md','Makefile','address_control.c','control-inputs.tsv','guest.sh','collect.py','compiled-inputs.json','compiled-inputs.tar.gz','summary.json','traps.tsv','control-traps.tsv','linux-profile.json','address-profile.json','control-profile.json','forms.tsv','cases.jsonl.gz','run.log.gz','host.txt.gz','native.asm.gz','control.asm.gz','leave64-x86.gz','address-control-x86.gz','control-cases.tsv','control.log.gz','initial-build.log.gz','initial-compiled-inputs.json','initial-compiled-inputs.tar.gz']
selected=[R/'kprog/fidelity/leave64.c']+[O/p for p in root_names]+[O/'baseline'/p for p in ['forms.tsv','cases.jsonl.gz','run.log.gz']]+[O/'kvm-clearcpuid-lass'/p for p in ['forms.tsv','cases.jsonl.gz','control-cases.tsv','run.log.gz','host.txt.gz','linux-profile.json','address-profile.json','control-profile.json','input-pins-before.json','input-pins-after.json','launch-dry-run.txt']]
assert all(p.is_file() for p in selected);emit(F/'leave64-boundaries.paths.json',[str(p.relative_to(R)) for p in selected]);print('verified75776LEAVE+4096DS/SS/0statewrites;source+static+allraw retained',len(selected),'publication paths')
