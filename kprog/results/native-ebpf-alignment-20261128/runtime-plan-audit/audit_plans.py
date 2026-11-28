"""Join archived native plans with captured proof entries, globals and map metadata."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import collections,hashlib,io,json,os,re,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BASE=OUT.parent
plans={};proofs={};patches={};abis={};snapshots=[];phases={};members=[];sources=[];duplicate_plan_variants=[]
def sha(data):return hashlib.sha256(data).hexdigest()
def file_sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def take(arch,group,rel,data,expected):
 row=expected[rel];assert len(data)==row['bytes'] and sha(data)==row['sha256'],rel
 app=rel.split('/')[0].split('__')[0] if group=='five' else 'otelcol-ebpf-profiler';key=Path(rel).name.split('.')[0];identity=(arch,app,key);origin=dict(architecture=arch,app=app,member=rel,bytes=len(data),sha256=sha(data));members.append(origin)
 if rel.endswith('.link-plan.json'):
  value=json.loads(data)
  if identity in plans and {k:v for k,v in plans[identity].items() if k!='origin'}!=value:duplicate_plan_variants.append(dict(identity=list(identity),first=plans[identity]['origin'],second=origin,second_plan=value))
  else:plans[identity]=dict(value,origin=origin)
 elif re.fullmatch(r'[0-9a-f]{16}\.proof\.o',Path(rel).name):
  elf=ELFFile(io.BytesIO(data));symbols=elf.get_section_by_name('.symtab');entries=[]
  for s in symbols.iter_symbols():
   if isinstance(s['st_shndx'],int) and s['st_info']['type']=='STT_FUNC' and s['st_info']['bind'] in ['STB_GLOBAL','STB_WEAK'] and s['st_value']==0 and s['st_size']>0:entries.append(s.name)
  proofs[identity]=dict(entries=sorted(set(entries)),origin=origin,elf_machine=elf['e_machine'])
 elif rel.endswith('.abi.tsv'):abis[identity]=dict(origin=origin,lines=data.decode().splitlines())
 elif rel.endswith('.map-patches.tsv'):patches[identity]=dict(origin=origin,names=sorted({x.split('\t')[0] for x in data.decode().splitlines() if x}))
 elif rel.endswith('/snapshot.json'):
  j=json.loads(data);snapshots.append(dict(architecture=arch,app=app,origin=origin,uptime=j['uptime'],programs=j['programs'],maps=j['maps']))
 elif '/details/apps/' in rel and rel.endswith('.json'):
  j=json.loads(data);phases[(arch,app)]={ph:{int(k) for k in j.get(ph,{}).get('bpf',{})} for ph in ['baseline','post_rejit']}
def selected(n):return n.endswith(('.link-plan.json','.abi.tsv','.map-patches.tsv','/snapshot.json')) or bool(re.fullmatch(r'[0-9a-f]{16}\.proof\.o',Path(n).name)) or ('/details/apps/' in n and n.endswith('.json'))
def read_archive(arch,group,parts,expected,inner_expected):
 records=[]
 for part in parts:
  p=ROOT/part['path'];h=file_sha(p);assert h==part['sha256'] and p.stat().st_size==part['bytes'];records.append(dict(part,git_blob=subprocess.check_output(['git','rev-parse','HEAD:'+part['path']],cwd=ROOT,text=True).strip()))
 sources.append(dict(architecture=arch,group=group,parts=records))
 a=subprocess.Popen(['cat',*[str(ROOT/p['path']) for p in parts]],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   if not m.isfile():continue
   rel=str(Path(*Path(m.name).parts[1:]))
   if selected(rel):take(arch,group,rel,t.extractfile(m).read(),expected)
   elif rel=='corpus-source.tar.gz':
    data=t.extractfile(m).read();assert sha(data)==expected[rel]['sha256']
    with tarfile.open(fileobj=io.BytesIO(data),mode='r:gz') as inner:
     for n in inner:
      if n.isfile() and '/details/apps/' in n.name and n.name.endswith('.json'):
       d=inner.extractfile(n).read();j=json.loads(d);app=j['app'].split('/')[0];phases[(arch,app)]={ph:{int(k) for k in j.get(ph,{}).get('bpf',{})} for ph in ['baseline','post_rejit']};assert sha(d)==inner_expected[n.name]['sha256']
 b.stdout.close();assert a.wait()==b.wait()==0
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='archive-analysis')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 os.sched_setaffinity(0,{19});save()
 five=BASE/'check-20261128T034810Z';otel=ROOT/'kprog/results/x86-otel-perf-20261127/profile-20261128T033629Z';arm=BASE/'arm64-frozen-ir/otel-work-check'
 for d,group in [(five,'five'),(otel,'otel')]:
  c=json.loads((d/'collection-controller.json').read_text());assert c['controller_status']==0;read_archive('x86',group,c['parts'],c['files'],json.loads((d/'corpus-source-files.json').read_text()))
 p=arm/'evidence.tar.zst.part-aa';read_archive('arm64','otel',[dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256='2df4f8998a08d14b2f7ce9918ad234c82d2a6bb92c189cbbebefc74ec301515e')],json.loads((arm/'raw-file-manifest.json').read_text()),{})
 data_maps=collections.defaultdict(dict);programs=collections.defaultdict(dict);readonly=[]
 for snap in snapshots:
  arch,app=snap['architecture'],snap['app'];ids={p['id'] for p in snap['programs']};present={k:bool(ids&v) for k,v in phases.get((arch,app),{}).items()}
  for p in snap['programs']:programs[(arch,app,p['name'])][p['id']]=dict(p)
  for m in snap['maps']:
   shape={k:m[k] for k in ['id','name','type','key_size','value_size','max_entries','flags']};data_maps[(arch,app,m['name'])][json.dumps(shape,sort_keys=True)]=shape
   if m['type']==2 and m['key_size']==4 and m['max_entries']==1 and m['flags']&128:
    for q in m['queries']:
     if q.get('key')==0 and q['returncode']==0 and 'value' in q:readonly.append(dict(architecture=arch,app=app,uptime=snap['uptime'],source=snap['origin'],map=shape,phase_program_ids_present=present,value_hex=q['value']))
 inventory=json.loads((BASE/'arm64-frozen-ir/alignment-inventory/programs.json').read_text());manifest=collections.defaultdict(list)
 for row in inventory:
  for name in row['symbol_candidates']:manifest[(row['architecture'],row['app'],name)].append(dict(object=row['object'],symbol_resolution=row['symbol_resolution'],manifest_symbol=row['manifest_symbol']))
 rows=[];groups=collections.defaultdict(list)
 for identity,plan in sorted(plans.items()):
  arch,app,key=identity;proof=proofs.get(identity);entries=proof['entries'] if proof else [];entry=entries[0] if len(entries)==1 else None;lookups=[]
  for item in plan.get('lookup_maps',[]):
   name=item['name'];candidates=list(data_maps[(arch,app,name[:15])].values()) if '#inner' not in name else []
   lookups.append(dict(name=name,form=item['kind'],plan_shape={k:v for k,v in item.items() if k not in ['name','map_name']},observed_kernel_name_candidates=candidates,identity_scope='Name/shape candidates across captured lifetime; original program-to-map ID binding remains separate.'))
  signature=sha(json.dumps({k:v for k,v in plan.items() if k not in ['origin','const_values']},sort_keys=True).encode());const=plan.get('const_values',[]);const_sig=sha(json.dumps(const,sort_keys=True).encode());groups[(arch,app,signature)].append(dict(cache_key=key,entry=entry,const_sha256=const_sig,const_values=const))
  abi=abis.get(identity);loads=[x for x in abi['lines'] if x.startswith('load_site\t')] if abi else []
  rows.append(dict(architecture=arch,app=app,cache_key=key,entry=entry,entry_candidates=entries,proof_origin=proof['origin'] if proof else None,plan_origin=plan['origin'],manifest_candidates=manifest[(arch,app,entry)] if entry else [],observed_kernel_name_program_candidates=list(programs[(arch,app,entry[:15])].values()) if entry else [],constants=const,constants_sha256=const_sig,helper_bindings=plan.get('helpers',[]),lookup_sites=plan.get('lookup_sites',[]),lookup_maps=lookups,update_sites=plan.get('update_sites',[]),map_patch_names=patches.get(identity,{}).get('names',[]),abi_origin=abi['origin'] if abi else None,abi_load_site_count=len(loads),remaining='Original source-object/program-ID/map-ID binding, installed context/helper/tail paths and baseline/native useful work remain distinct checks.'))
 varied=[dict(architecture=a,app=b,other_plan_fields_sha256=s,variants=v) for (a,b,s),v in groups.items() if len({x['const_sha256'] for x in v})>1]
 summary=[]
 for arch,app in sorted({(x['architecture'],x['app']) for x in rows}):
  items=[x for x in rows if (x['architecture'],x['app'])==(arch,app)];entrynames={x['entry'] for x in items if x['entry']};variables=collections.defaultdict(set)
  for x in items:
   for v in x['constants']:variables[v['name']].add(v['hex'])
  summary.append(dict(architecture=arch,app=app,cache_plans=len(items),unique_named_entries=len(entrynames),plans_with_constants=sum(bool(x['constants']) for x in items),plans_with_entry_proof=sum(bool(x['proof_origin']) for x in items),plans_with_abi=sum(bool(x['abi_origin']) for x in items),manifest_candidate_counts=dict(collections.Counter(len(x['manifest_candidates']) for x in items)),lookup_forms=dict(collections.Counter(y['form'] for x in items for y in x['lookup_maps'])),constant_value_variants={n:sorted(v) for n,v in sorted(variables.items())},readonly_snapshot_values=sum((x['architecture'],x['app'])==(arch,app) for x in readonly)))
 output=dict(scope='Captured native cache plans from x86 six-app checks and legacy ARM OTel. Plan coverage differs from install counts. Full symbol proof entry is joined by exact cache key; kernel names and map shapes remain candidates across snapshots.',per_app=summary,plans=rows,readonly_snapshot_values=readonly,constant_only_plan_variation_groups=varied,duplicate_cache_key_plan_variants=duplicate_plan_variants)
 (OUT/'runtime-plans.json').write_text(json.dumps(output,indent=2)+'\n');(OUT/'sources.json').write_text(json.dumps(dict(archives=sources,members=members),indent=2)+'\n')
 header=['architecture','app','cache_key','entry','constants','lookup_sites','abi_load_sites','manifest_candidates','observed_program_name_candidates'];lines=['\t'.join(header)]
 for x in rows:lines.append('\t'.join(map(str,[x['architecture'],x['app'],x['cache_key'],x['entry'] or '',len(x['constants']),len(x['lookup_sites']),x['abi_load_site_count'],len(x['manifest_candidates']),len(x['observed_kernel_name_program_candidates'])])))
 (OUT/'programs.tsv').write_text('\n'.join(lines)+'\n')
 r.update(controller_status=0,phase='finished-manual-result-review-pending',plans=len(rows),selected_verified_members=len(members),snapshots=len(snapshots),readonly_snapshot_values=len(readonly),constant_only_variation_groups=len(varied),duplicate_cache_key_plan_variants=len(duplicate_plan_variants),per_app=[{k:v for k,v in x.items() if k!='constant_value_variants'} for x in summary],outputs={n:dict(bytes=(OUT/n).stat().st_size,sha256=file_sha(OUT/n)) for n in ['runtime-plans.json','sources.json','programs.tsv']})
except Exception:r.update(controller_status=1,phase='failed-receipts-retained',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k not in ['per_app','outputs']}),flush=True)
raise SystemExit(r['controller_status'])
