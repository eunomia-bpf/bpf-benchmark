"""Compare actual phase-matched unwinder JIT/native images, not source-size proxies."""
import bisect,collections,hashlib,json,re,subprocess
from pathlib import Path
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
out=Path(json.loads((LANE/'otel-performance-profile.json').read_text())['result']);c=json.loads((out/'controller.json').read_text());assert c['controller_status']==0
raw=Path(c['raw']);run=Path(c['run_dir']);app=json.loads((run/'details/apps/otelcol-ebpf-profiler__profiling.json').read_text());record=dict(image=c['profile-image.txt'],source=c['profile-source.txt'],scope='Actual in-phase dumped JIT/native images of perf_unwind_nat. Static instructions/calls and stack operands; stack operands are not automatically compiler spills. Sizes include the complete dumped image, not only hot executed instructions.',phases={})
for ph in ['baseline','post_rejit']:
 log=(run/('details/shim-logs/otelcol-ebpf-profiler__profiling.'+ph+'.log')).read_text();start=float(re.search(r'^\[([\d.]+) .*cmd=measure_start',log,re.M)[1]);end=float(re.search(r'^\[([\d.]+) .*cmd=measure_finish',log,re.M)[1])
 selected=[(k,v) for k,v in app[ph]['bpf'].items() if v['name']=='perf_unwind_nat'];assert len(selected)==1;pid,info=selected[0]
 files=[p for p in (raw/'progdump').glob('*/prog-'+pid+'-perf_unwind_nat.jited.bin') if start<=float(p.parent.name)<end];assert files,(ph,pid)
 path=min(files,key=lambda p:abs(float(p.parent.name)-(start+end)/2));funcs=path.with_name(path.name.replace('.jited.bin','.funcs.txt')).read_text().split();assert len(funcs)==2,funcs
 address=int(funcs[0],16);length=int(funcs[1]);data=path.read_bytes();assert length==len(data)==info['bytes_jited']
 snapshots={p.parent.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in files};assert len(set(snapshots.values()))==1
 syms={}
 for p in [raw/'kallsyms.txt',min(raw.glob('kallsyms-bpf-*.txt'),key=lambda p:abs(float(p.name[len('kallsyms-bpf-'):-4])-float(path.parent.name)))]:
  for line in p.read_text().splitlines():
   a,t,n,*_=line.split()
   if t in 'tTwW':syms[int(a,16)]=n
 keys=sorted(syms)
 def resolve(target):
  if address<=target<address+length:return 'local+'+hex(target-address)
  i=bisect.bisect_right(keys,target)-1
  return syms[keys[i]]+('+'+hex(target-keys[i]) if target!=keys[i] else '') if i>=0 else hex(target)
 assembly=subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64','-Mintel','--no-show-raw-insn','--adjust-vma='+hex(address),str(path)],text=True)
 label='ebpf' if ph=='baseline' else 'native';(out/(label+'-unwinder.dis')).write_text(assembly)
 instructions=[]
 for line in assembly.splitlines():
  m=re.match(r'^\s*([0-9a-f]+):\s+([a-z][a-z0-9.]*)\s*(.*)$',line)
  if m:instructions.append(dict(address=int(m[1],16),opcode=m[2],operands=m[3]))
 by_addr={x['address']:i for i,x in enumerate(instructions)}
 calls=[]
 for i,x in enumerate(instructions):
  if x['opcode']!='call':continue
  m=re.match(r'(?:0x)?([0-9a-f]+)(?:\s|$)',x['operands']);target=int(m[1],16) if m else None;name=resolve(target) if target else '[indirect]';thunk=None
  if target in by_addr:
   block=instructions[by_addr[target]:by_addr[target]+5]
   # Resolve only a literal movabs+jmp thunk, not an arbitrary local call.
   if len(block)>=2:
    a,b=block[:2];imm=re.fullmatch(r'([^,]+),0x([0-9a-f]+)',a['operands'])
    if a['opcode']=='movabs' and imm and b['opcode']=='jmp' and b['operands']==imm[1]:
     thunk=target;target=int(imm[2],16);name=resolve(target)
  calls.append(dict(address=x['address'],offset=x['address']-address,target=target,target_symbol=name,via_literal_thunk=thunk,window=instructions[max(0,i-8):i+3]))
 histogram=dict(collections.Counter(x['opcode'] for x in instructions));stack=[x for x in instructions if re.search(r'\[(?:r(?:sp|bp))(?:[+\]-])',x['operands'])]
 row=dict(prog_id=pid,program_info=info,address=address,bytes=length,instructions=len(instructions),image_sha256=hashlib.sha256(data).hexdigest(),snapshots=snapshots,source_dump=str(path.relative_to(raw)),opcode_histogram=histogram,cmovs=sum(v for k,v in histogram.items() if k.startswith('cmov')),pushes=histogram.get('push',0),pops=histogram.get('pop',0),stack_operand_instructions=len(stack),calls_by_target=dict(collections.Counter(x['target_symbol'] for x in calls)),calls=calls,prologue=instructions[:30],stack_operand_examples=stack[:45])
 record['phases'][ph]=row
(out/'code-comparison.json').write_text(json.dumps(record,indent=2)+'\n')
with (out/'code-metrics.tsv').open('w') as f:
 f.write('phase\tbytes\tinstructions\tcmovs\tpushes\tpops\tstack_operand_instructions\n')
 for ph,r in record['phases'].items():f.write('\t'.join(map(str,[ph,*[r[k] for k in ['bytes','instructions','cmovs','pushes','pops','stack_operand_instructions']]]))+'\n')
print(json.dumps({ph:{k:r[k] for k in ['prog_id','bytes','instructions','cmovs','pushes','pops','stack_operand_instructions','calls_by_target']} for ph,r in record['phases'].items()}),flush=True)
