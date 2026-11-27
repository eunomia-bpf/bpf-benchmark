"""Inventory native exclusive retry loops in every captured generated B source."""
import collections
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());parent=Path(run['result']);raw=Path(run['raw']);prepared=json.loads((parent/'prepare-controller.json').read_text());assert len(prepared['inputs'])==145
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();token=now.replace('-','').replace(':','');OUT=HERE/('exclusive-census-'+token);OUT.mkdir()
try:sources={x['index']:(raw/str(x['index'])/'after.bpf.c').read_bytes() for x in prepared['inputs']};origin='live immutable recovered sources'
except FileNotFoundError:
 sources={};parts=sorted(parent.glob('evidence.tar.zst.part-*'));assert parts
 for p in parts:
  oid=subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2];assert oid==subprocess.check_output(['git','hash-object',str(p)],text=True).strip()
 a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   path=Path(m.name)
   if m.isfile() and len(path.parts)==3 and path.parts[0]==raw.name and path.parts[1].isdigit() and path.name=='after.bpf.c':sources[int(path.parts[1])]=t.extractfile(m).read()
 b.stdout.close();assert a.wait()==b.wait()==0;origin='verified committed full-sweep archive parts'
assert len(sources)==145
original=json.loads((ROOT/'kprog/results/arm64-checked-corpus-20261127/refusals.json').read_text());families={(r['app'],r['request']):r['family'] for r in original['stock_refusals']}
load_ops={'ldxr','ldaxr','ldxrb','ldaxrb','ldxrh','ldaxrh'};store_ops={'stxr','stlxr','stxrb','stlxrb','stxrh','stlxrh'}
pattern=re.compile(r'/\*\s*0x([0-9a-f]+):\s*([a-z0-9.]+)\s*(.*?)\s*\*/');rows=[]
for item in prepared['inputs']:
 data=sources[item['index']];assert hashlib.sha256(data).hexdigest()==item['normalized_source_sha256'];text=data.decode();instructions=[dict(address=int(m[1],16),op=m[2],operands=m[3]) for m in pattern.finditer(text)];by_pc={x['address']:x for x in instructions};assert len(by_pc)==len(instructions)
 loops=[]
 for branch in instructions:
  if branch['op']!='cbnz':continue
  parts=branch['operands'].split(',',1)
  if len(parts)!=2:continue
  status=parts[0].strip();target=re.match(r'\s*([0-9a-f]+)\b',parts[1])
  if not target:continue
  target=int(target[1],16);load=by_pc.get(target);store=by_pc.get(branch['address']-4)
  if target>=branch['address'] or not load or load['op'] not in load_ops or not store or store['op'] not in store_ops:continue
  st=re.fullmatch(r'([^,]+),\s*([^,]+),\s*(\[[^\]]+\])',store['operands']);ld=re.fullmatch(r'([^,]+),\s*(\[[^\]]+\])',load['operands'])
  if not st or not ld or st[1].strip()!=status or st[3].replace(' ','')!=ld[2].replace(' ',''):continue
  body=[by_pc[pc] for pc in range(target,branch['address']+4,4) if pc in by_pc];simple=False
  if branch['address']==target+12 and len(body)==4 and body[1]['op'] in {'add','sub','and','orr','eor'}:
   ar=[x.strip() for x in body[1]['operands'].split(',')];simple=len(ar)>=3 and ar[0]==st[2].strip() and ar[1]==ld[1].strip()
  loops.append(dict(load_pc=target,store_pc=store['address'],retry_pc=branch['address'],status_register=status,same_memory_operand=ld[2],simple_four_instruction_form=simple,instructions=body))
 rows.append(dict(index=item['index'],app=item['app'],request=item['request'],symbol=item['symbol'],original_stock_passed=item['original_stock_passed'],original_family=families.get((item['app'],item['request'])),source_sha256=item['normalized_source_sha256'],native_instruction_comments=len(instructions),exclusive_retry_loops=loops))
assert next(x for x in rows if x['index']==49)['exclusive_retry_loops'][0]['simple_four_instruction_form']
def counts(group):
 loops=[l for x in group for l in x['exclusive_retry_loops']]
 return dict(requests=len(group),requests_with_retry=sum(bool(x['exclusive_retry_loops']) for x in group),retry_sites=len(loops),simple_four_instruction_sites=sum(l['simple_four_instruction_form'] for l in loops),distinct_sources_with_retry=len({x['source_sha256'] for x in group if x['exclusive_retry_loops']}))
summary=dict(all=counts(rows),apps={app:counts([x for x in rows if x['app']==app]) for app in sorted({x['app'] for x in rows})},original_families={family:counts([x for x in rows if x['original_family']==family]) for family in sorted({x['original_family'] for x in rows if x['original_family']})})
record=dict(utc=now,origin=origin,scope='Static native-instruction-comment census across all145 captured generatedB sources; each source SHA checked against immutable prepared input. Structural candidate inventory, not a transformation/proof or new verifier acceptance. Repeated requests/sources remain explicit.',summary=summary,requests=rows,limits='Recognizes CBNZ-to-exclusive-load retries with immediately preceding matching exclusive store and same textual memory operand. Four-instruction subset also matches the arithmetic source/destination registers. Does not establish atomic linearization, alias freedom, ordering, progress/fairness or safety of replacing failed visits; no forced-success/bound/per-app selection is introduced.',controller_status=0)
(OUT/'census.json').write_text(json.dumps(record,indent=2)+'\n')
with (OUT/'census.tsv').open('w') as f:
 f.write('index\tapp\trequest\tsymbol\toriginal_family\tsource_sha256\tretry_sites\tsimple_sites\n')
 for x in rows:f.write('\t'.join(str(v) for v in [x['index'],x['app'],x['request'],x['symbol'],x['original_family'],x['source_sha256'],len(x['exclusive_retry_loops']),sum(l['simple_four_instruction_form'] for l in x['exclusive_retry_loops'])])+'\n')
(OUT/'README.md').write_text('# Captured ARM exclusive retry inventory\n\n'+json.dumps(summary,indent=2)+'\n\nAll145 generatedB sources were checked by SHA against the original recovered-input receipt; no compiler, guest, source, flag or framework changed. Counts refer to requests and sites, with distinct C source hashes reported separately. The inventory recognizes native instruction structure; it does not establish a safe atomic-block replacement or infer the final verifier family. The actual Tetragon1 retry diagnosis remains f5d34434a. Full paired stock outcomes and queued Tetragon stage2 are collected separately.\n')
(LANE/'exclusive-census.json').write_text(json.dumps(dict(result=str(OUT)),indent=2)+'\n');print(json.dumps(summary),flush=True)
