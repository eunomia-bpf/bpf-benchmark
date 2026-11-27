"""Compare captured Cilium generator inputs without compiling or changing them."""
import datetime
import hashlib
import io
import json
import os
from pathlib import Path
import re
import statistics
import subprocess
import tarfile

ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();token=now.replace('-','').replace(':','')
OUT=HERE/('cilium-source-'+token);OUT.mkdir();RAW=Path('/workspaces/kprog-raw/perf/arm64-loadtime-20261127')/('cilium-source-'+token);RAW.mkdir()
profile=(HERE/'header-source-20261127T151253Z/runtime-overrides.txt').read_bytes()
inputs={'x86':Path('/workspaces/kprog-raw/verified/checked-corpus-20261126-qm/service.tar.gz'),'arm64':Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T120527Z/cilium-agent/service.tar.gz')}
record=dict(started_utc=now,pid=os.getpid(),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),scope='Read-only captured Cilium x86 qm64 vs ARM17 sources. Join exact symbol/prog_type/map binding+shape groups where possible; otherwise report common entry groups with map/native-input differences. Whole service request time is not frontend time. No new compiler/native/workload/timing experiment.',inputs={},requests={},pairs=[])
def sha(data):return hashlib.sha256(data).hexdigest()
def save():(OUT/'comparison.json').write_text(json.dumps(record,indent=2)+'\n')
for arch,archive in inputs.items():
 rows=[];audits={};dest=RAW/arch;dest.mkdir();record['inputs'][arch]=dict(archive=str(archive),bytes=archive.stat().st_size,sha256=sha(archive.read_bytes()))
 with tarfile.open(archive,mode='r|gz') as outer:
  for capsule in outer:
   if not capsule.isfile():continue
   if capsule.name.endswith('/service.log'):
    for line in outer.extractfile(capsule).read().decode().splitlines():
     try:audit=json.loads(line)
     except json.JSONDecodeError:continue
     if 'request_id' in audit:audits[audit['request_id']]={k:audit.get(k) for k in ['request_id','started','finished','status','execution_path','b_generated','b_stock_passed','native_sha256']}
    continue
   if '/requests/' not in capsule.name or not capsule.name.endswith('.tar.gz'):continue
   request=int(Path(capsule.name).name.split('.')[0]);files={}
   wanted={'kernel.entry','kernel.facts.json','generation.metadata.json','source-identities.json','commands.jsonl','trusted_'+arch+'.bpf.c','trusted_arm64.bpf.frontend.compiler.json.broker.json'}
   with tarfile.open(fileobj=outer.extractfile(capsule),mode='r|gz') as inner:
    for m in inner:
     leaf=Path(m.name).name
     if m.isfile() and leaf in wanted:files[leaf]=inner.extractfile(m).read()
   case=dest/str(request);case.mkdir()
   for name,data in files.items():(case/name).write_bytes(data)
   source=files.get('trusted_'+arch+'.bpf.c',b'');count=source.count(profile);assert count in [0,1]
   normalized=source.replace(b'\n'+profile,b'',1) if count else source
   if count:(case/'source-without-obsolete-overrides.c').write_bytes(normalized)
   text=normalized.decode();meta=json.loads(files['generation.metadata.json']);facts=json.loads(files['kernel.facts.json']);commands=[json.loads(l) for l in files.get('commands.jsonl',b'').decode().splitlines() if l]
   frontend=[c for c in commands if '-emit-llvm' in c.get('command',[])];flagrows=[]
   for c in frontend:
    args=c['command'];flagrows.append(dict(command=args,optimization=[x for x in args if re.fullmatch(r'-O[0-3sz]',x)],input_form='preprocessed-i' if any(x.endswith('.bpf.i') for x in args) else 'C-source',returncode=c.get('returncode')))
   broker=json.loads(files['trusted_arm64.bpf.frontend.compiler.json.broker.json']) if 'trusted_arm64.bpf.frontend.compiler.json.broker.json' in files else None
   row=dict(request=request,capsule=capsule.name,symbol=files['kernel.entry'].decode().strip(),prog_type=facts['prog_type'],maps=meta['maps'],source_bytes=len(source),source_sha256=sha(source),normalized_source_bytes=len(normalized),normalized_source_sha256=sha(normalized),removed_obsolete_profile=count,native_instruction_labels=len(re.findall(r'^'+('x86' if arch=='x86' else 'arm64')+r'_l_[0-9a-f]+:',text,re.M)),simulator_steps=len(re.findall(r'\b(?:ARM64_SIM_RUN_KNOWN_OP3|X86_SIM_RUN_OP)\(',text)),frontend=flagrows,frontend_wall_seconds=broker.get('wall_seconds') if broker else None,frontend_max_rss_kib=broker.get('max_rss_kib') if broker else None,request_audit=None)
   row['binding_key']=json.dumps([row['symbol'],row['prog_type'],sorted([[m.get(k) for k in ['name','value_offset','map_type','key_size','value_size','max_entries','map_flags']] for m in meta['maps']],key=lambda x:json.dumps(x))],sort_keys=True)
   rows.append(row)
 for row in rows:
  row['request_audit']=audits.get(row['request'])
  audit=row['request_audit']
  row['whole_request_seconds']=(datetime.datetime.fromisoformat(audit['finished'])-datetime.datetime.fromisoformat(audit['started'])).total_seconds() if audit and audit.get('finished') and audit.get('started') else None
 rows.sort(key=lambda x:x['request']);record['requests'][arch]=rows;save()
assert len(record['requests']['x86'])==64 and len(record['requests']['arm64'])==17
xrows=record['requests']['x86']
for arm in record['requests']['arm64']:
 exact=[x for x in xrows if x['binding_key']==arm['binding_key']];candidates=exact or [x for x in xrows if (x['symbol'],x['prog_type'])==(arm['symbol'],arm['prog_type'])]
 if not candidates:continue
 lengths=[x['normalized_source_bytes'] for x in candidates if x['normalized_source_bytes']];labels=[x['native_instruction_labels'] for x in candidates if x['native_instruction_labels']]
 pair=dict(arm_request=arm['request'],symbol=arm['symbol'],match='exact-symbol-type-map-shapes' if exact else 'symbol-and-type-only/native-inputs-differ',x86_requests=[x['request'] for x in candidates],arm_C_bytes=arm['normalized_source_bytes'],x86_C_bytes_median=statistics.median(lengths) if lengths else None,arm_native_labels=arm['native_instruction_labels'],x86_native_labels_median=statistics.median(labels) if labels else None,arm_frontend_seconds=arm['frontend_wall_seconds'],x86_frontend_seconds=None,arm_whole_request_seconds=arm['whole_request_seconds'],x86_whole_request_seconds_median=statistics.median([x['whole_request_seconds'] for x in candidates if x['whole_request_seconds'] is not None]),arm_only_map_names=sorted(set(m['name'] for m in arm['maps'])-set(m['name'] for m in candidates[0]['maps'])),x86_only_map_names=sorted(set(m['name'] for m in candidates[0]['maps'])-set(m['name'] for m in arm['maps'])))
 if lengths:pair['C_bytes_ratio']=arm['normalized_source_bytes']/statistics.median(lengths)
 if labels:pair['native_labels_ratio']=arm['native_instruction_labels']/statistics.median(labels)
 record['pairs'].append(pair)
record['summary']=dict(x86_requests=len(xrows),arm_requests=17,matched_arm_requests=len(record['pairs']),exact_map_binding_matches=sum(p['match']=='exact-symbol-type-map-shapes' for p in record['pairs']),entry_only_matches=sum(p['match']!='exact-symbol-type-map-shapes' for p in record['pairs']),x86_frontend_wall_receipts=0,arm_frontend_wall_receipts=sum(r['frontend_wall_seconds'] is not None for r in record['requests']['arm64']),median_normalized_C_ratio=statistics.median([p['C_bytes_ratio'] for p in record['pairs'] if 'C_bytes_ratio' in p]),median_native_label_ratio=statistics.median([p['native_labels_ratio'] for p in record['pairs'] if 'native_labels_ratio' in p]),limitations='x86 original archive has no per-frontend wall/RSS receipt; all x86 frontend times are null. Whole-request seconds include native linking, preprocessing, bounds pass, verifier and native compilation. Different native instructions/map bindings/configuration relocations are reported; source byte ratios do not establish generator causal cost. Captured x86 uses O1 and preprocessed-i; ARM O2 and direct C. Identical-host controlled frontend measurement remains next after current two compiler workers release.')
record.update(controller_status=0,ended_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),raw=str(RAW));save()
with (OUT/'pairs.tsv').open('w') as f:
 cols=['arm_request','symbol','match','x86_requests','arm_C_bytes','x86_C_bytes_median','C_bytes_ratio','arm_native_labels','x86_native_labels_median','native_labels_ratio','arm_frontend_seconds','x86_frontend_seconds','arm_whole_request_seconds','x86_whole_request_seconds_median'];f.write('\t'.join(cols)+'\n')
 for row in record['pairs']:f.write('\t'.join(json.dumps(row.get(k)) if isinstance(row.get(k),list) else str(row.get(k,'')) for k in cols)+'\n')
(LANE/'cilium-source-comparison.json').write_text(json.dumps(dict(result=str(OUT),raw=str(RAW)),indent=2)+'\n');print(json.dumps(record['summary']),flush=True)
