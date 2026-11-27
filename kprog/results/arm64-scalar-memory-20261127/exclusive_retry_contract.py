"""Inspect operand stability and native entries before defining a common retry form."""
import collections
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
prior=HERE/'exclusive-census-20261127T181210Z/census.json'
rel=str(prior.relative_to(ROOT))
assert subprocess.check_output(['git','ls-tree','HEAD','--',rel],text=True).split()[2]==subprocess.check_output(['git','hash-object',str(prior)],text=True).strip()
census=json.loads(prior.read_text());selected={r['index']:r for r in census['requests'] if r['exclusive_retry_loops']}
run=json.loads((LANE/'scalar-run.json').read_text());parent=Path(run['result']);raw=Path(run['raw'])
sources={}
if raw.exists():
 sources={i:(raw/str(i)/'after.bpf.c').read_bytes() for i in selected}
else:
 parts=sorted(parent.glob('evidence.tar.zst.part-*'));assert parts
 for p in parts:
  assert subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2]==subprocess.check_output(['git','hash-object',str(p)],text=True).strip()
 a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE)
 b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
 with tarfile.open(fileobj=b.stdout,mode='r|') as archive:
  for m in archive:
   p=Path(m.name)
   if m.isfile() and len(p.parts)==3 and p.parts[0]==raw.name and p.parts[1].isdigit() and int(p.parts[1]) in selected and p.name=='after.bpf.c':
    sources[int(p.parts[1])]=archive.extractfile(m).read()
 b.stdout.close();assert a.wait()==b.wait()==0
assert set(sources)==set(selected)
def reg(s):
 s=s.strip()
 return int(s[1:]) if re.fullmatch('[wx][0-9]+',s) else s
pattern=re.compile(r'/\*\s*0x([0-9a-f]+):\s*([a-z0-9.]+)\s*(.*?)\s*\*/')
rows=[];indirect={}
for index,r in selected.items():
 data=sources[index];assert hashlib.sha256(data).hexdigest()==r['source_sha256']
 instructions=[dict(pc=int(m[1],16),op=m[2],operands=m[3]) for m in pattern.finditer(data.decode())]
 edges=[];unknown=[]
 for i in instructions:
  op=i['op'];operands=i['operands']
  if op in {'br','blr','ret'}:unknown.append(i);continue
  if op not in {'b','bl','cbz','cbnz','tbz','tbnz'} and not op.startswith('b.'):continue
  target=operands.split(',')[-1].strip();m=re.match(r'([0-9a-f]+)(?:\s|$)',target)
  if m:edges.append(dict(pc=i['pc'],op=op,target=int(m[1],16)))
 indirect[str(index)]=unknown
 for loop in r['exclusive_retry_loops']:
  load,ar,store,branch=loop['instructions']
  lr,base=re.fullmatch(r'([^,]+),\s*\[([^\]]+)\]',load['operands']).groups()
  args=[v.strip() for v in ar['operands'].split(',')]
  status,value,storebase=re.fullmatch(r'([^,]+),\s*([^,]+),\s*\[([^\]]+)\]',store['operands']).groups()
  operand=args[2];changed={reg(lr),reg(status)}
  incoming=[e for e in edges if loop['load_pc']<e['target']<=loop['retry_pc'] and not loop['load_pc']<=e['pc']<=loop['retry_pc']]
  aliases=dict(base_overwritten=reg(base) in changed,status_aliases_value=reg(status)==reg(value),status_aliases_base=reg(status)==reg(base),operand_overwritten=not operand.startswith('#') and reg(operand) in changed)
  rows.append(dict(index=index,app=r['app'],request=r['request'],symbol=r['symbol'],source_sha256=r['source_sha256'],load_pc=loop['load_pc'],store_pc=loop['store_pc'],retry_pc=loop['retry_pc'],width=64 if lr.strip().startswith('x') else 32,load_op=load['op'],store_op=store['op'],arithmetic=ar['op'],operand=operand,operand_kind='immediate' if operand.startswith('#') else 'register',load_value_register=lr,status_register=status,base_register=base,aliases=aliases,external_direct_entries_into_body=incoming,instructions=loop['instructions']))
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();out=HERE/('exclusive-contract-'+now.replace('-','').replace(':',''));out.mkdir()
count=lambda key:dict(collections.Counter(str(key(r)) for r in rows))
summary=dict(requests=len(selected),sites=len(rows),widths=count(lambda r:r['width']),operation_orders=count(lambda r:(r['load_op'],r['arithmetic'],r['store_op'])),operands=count(lambda r:r['operand_kind']),alias_counts={k:sum(r['aliases'][k] for r in rows) for k in rows[0]['aliases']},sites_with_external_direct_entries=sum(bool(r['external_direct_entries_into_body']) for r in rows),requests_with_indirect_control=sum(bool(v) for v in indirect.values()))
obligations=[
'Preserve explicit EXCLUSIVE_FAILURE per dynamic store visit, with both0/1 outcomes. Failed store must skip source/memory observation and write zero-extended Wstatus1; success performs the ordinary memory-write semantics and Wstatus0.',
'Every failed visit still executes its exclusive load and arithmetic; keep load faults, SP alignment, pointer tags, width and external read effects. No fairness, fixed retry count or constant-success substitution is licensed.',
'A native atomic fetch intrinsic is not a drop-in proof: reconcile memory-order labels, external interference/reservation model, per-visit choices, fault paths, local value/status live-outs and traces. The existing local simulator does not itself establish an atomic linearization relation.',
'Any stock-B loop/callback form needs its safety-preservation relation to arbitrary native failure prefixes and successful continuation. A finite bpf_loop/iterator bound alone does not cover an unbounded native retry.',
'Native direct-branch closure is checked here; indirect entry targets and specialization dispatch closure remain unproved. Structural operand stability is not sufficient for selecting a production rewrite.']
record=dict(utc=now,controller_status=0,scope='Read-only semantic-shape evidence for FORMAL/PERF common ARM retry lowering; no production rewrite, compiler, guest, proof or acceptance claim.',source_census=rel,summary=summary,sites=rows,indirect_control_by_request=indirect,obligations=obligations)
(out/'contract.json').write_text(json.dumps(record,indent=2)+'\n')
with (out/'sites.tsv').open('w') as f:
 f.write('index\tapp\trequest\tload_pc\twidth\tarithmetic\toperand\taliases\texternal_direct_entries\n')
 for r in rows:f.write('\t'.join(map(str,[r['index'],r['app'],r['request'],hex(r['load_pc']),r['width'],r['arithmetic'],r['operand'],r['aliases'],r['external_direct_entries_into_body']]))+'\n')
(out/'README.md').write_text('# ARM exclusive retry lowering boundary\n\n'+json.dumps(summary,indent=2)+'\n\n'+ '\n\n'.join(obligations)+'\n\nThe70 archived C sources match their captured hashes. The original145-stock acceptance and active Tetragon guest are unchanged. contract.json retains all216 sites and every native indirect control instruction for follow-up; direct entry checks cover parsed immediate branch targets only. No proposed lowering is established by these counts.\n')
(LANE/'exclusive-contract.json').write_text(json.dumps(dict(result=str(out)),indent=2)+'\n')
print(json.dumps(dict(result=str(out),summary=summary)),flush=True)
