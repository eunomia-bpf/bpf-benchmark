"""Read current staged native programs; static scope is explicit, no runtime verdict."""
from pathlib import Path
import collections,csv,hashlib,json,subprocess
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
rows=[];objects={};manifests={}
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def inspect(p):
 key=str(p.relative_to(ROOT))
 if key in objects:return objects[key]
 with p.open('rb') as stream:
  elf=ELFFile(stream);secs=list(elf.iter_sections());tab=elf.get_section_by_name('.symtab');symbols=list(tab.iter_symbols()) if tab else [];funcs=[x for x in symbols if x['st_info']['type']=='STT_FUNC' and isinstance(x['st_shndx'],int)];maps=[];readonly=[];undef=[]
  for x in symbols:
   if not x.name:continue
   index=x['st_shndx']
   if index=='SHN_UNDEF':undef.append(x.name)
   elif isinstance(index,int) and index<len(secs) and x['st_info']['type']=='STT_OBJECT':
    sec=secs[index]
    if sec.name=='.maps':maps.append(x.name)
    if sec['sh_flags']&2 and not sec['sh_flags']&1:readonly.append(dict(name=x.name,section=sec.name,size=x['st_size'],binding=x['st_info']['bind']))
  aliases=collections.defaultdict(set)
  for name in maps:aliases[name[:15]].add(name)
  relocs=collections.defaultdict(list)
  for sec in secs:
   if not isinstance(sec,RelocationSection):continue
   table=elf.get_section(sec['sh_link'])
   for rel in sec.iter_relocations():
    x=table.get_symbol(rel['r_info_sym']);relocs[sec['sh_info']].append(dict(offset=rel['r_offset'],target=x.name,type=rel['r_info_type'],target_undefined=x['st_shndx']=='SHN_UNDEF'))
  details=[]
  for x in funcs:
   direct=[r for r in relocs[x['st_shndx']] if x['st_size']>0 and x['st_value']<=r['offset']<x['st_value']+x['st_size']]
   details.append(dict(name=x.name,section=secs[x['st_shndx']].name,offset=x['st_value'],size=x['st_size'],direct_relocations=direct))
  ir=elf.get_section_by_name('.llvmbc');cmd=elf.get_section_by_name('.llvmcmd')
  r=dict(path=key,bytes=p.stat().st_size,sha256=sha(p),elf_machine=elf['e_machine'],frontend_ir_bytes=ir['sh_size'] if ir else 0,embedded_compile_command=cmd.data().decode(errors='replace').split('\0') if cmd else None,readonly_native_objects=readonly,map_symbols=sorted(maps),map_alias_collisions={k:sorted(v) for k,v in aliases.items() if len(v)>1},undefined_symbols=sorted(set(undef)),functions=details)
 objects[key]=r;return r
for arch in ['x86','arm64']:
 stage=ROOT/'vendor/build/native-bpf'/arch/'stage'
 for manifest in sorted(stage.rglob('manifest.json')):
  app=manifest.parent.name;doc=json.loads(manifest.read_text());manifests[str(manifest.relative_to(ROOT))]=dict(sha256=sha(manifest),program_rows=len(doc['objects']))
  for entry in doc['objects']:
   p=manifest.parent/entry['native_object'];obj=inspect(p);symbol=entry.get('symbol',entry['program']);exact=[f for f in obj['functions'] if f['name']==symbol];prefix=[] if exact and entry.get('symbol') else [f for f in obj['functions'] if f['name'][:15]==entry['program']]
   selected=exact if exact and entry.get('symbol') else prefix;direct=selected[0]['direct_relocations'] if len(selected)==1 else None
   rows.append(dict(architecture=arch,app=app,program=entry['program'],manifest_symbol=entry.get('symbol'),object=obj['path'],symbol_resolution='exact' if len(exact)==1 and len(selected)==1 else 'unique-kernel-prefix-candidate' if len(prefix)==1 else 'ambiguous-prefix' if len(prefix)>1 else 'absent',symbol_candidates=[f['name'] for f in selected],entry_text_bytes=selected[0]['size'] if len(selected)==1 else None,elf_machine=obj['elf_machine'],frontend_ir_present=obj['frontend_ir_bytes']>0,direct_entry_external_symbols=sorted({r['target'] for r in direct if r['target_undefined']}) if direct is not None else None,direct_entry_tail_call_reference=any(r['target']=='bpf_tail_call' for r in direct) if direct is not None else None,runtime_alignment='not-decided-by-static-inventory'))
counts=collections.Counter((r['architecture'],r['app']) for r in rows);summary=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),time_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),rows=len(rows),objects=len(objects),per_app=[dict(architecture=k[0],app=k[1],rows=v) for k,v in sorted(counts.items())],symbol_resolution=dict(collections.Counter(r['symbol_resolution'] for r in rows)),missing_ir=[p for p,r in objects.items() if not r['frontend_ir_bytes']],isa_mismatches=[r for r in rows if r['elf_machine']!=('EM_X86_64' if r['architecture']=='x86' else 'EM_AARCH64')],limitations='Manifest rows are staged definitions, not workload loads/install events. Entry relocations exclude resolved local calls, transitive functions, runtime optimizer output and code patched after load; absence is not absence of execution. Native read-only object sections are only candidate globals: actual BPF map read-only+frozen flags and app-written values require load-time plan evidence. Static prefix candidates do not assert the loader selected them. No runtime equality or per-program semantic pass inferred.')
(OUT/'programs.json').write_text(json.dumps(rows,indent=2)+'\n');(OUT/'objects.json').write_text(json.dumps(objects,indent=2)+'\n');(OUT/'manifests.json').write_text(json.dumps(manifests,indent=2)+'\n');(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
with (OUT/'programs.tsv').open('w',newline='') as f:
 w=csv.writer(f,delimiter='\t');w.writerow(['arch','app','program','symbol_resolution','candidates','native_text_bytes','frontend_ir','direct_external_symbols','object'])
 for r in rows:w.writerow([r['architecture'],r['app'],r['program'],r['symbol_resolution'],','.join(r['symbol_candidates']),r['entry_text_bytes'],r['frontend_ir_present'],','.join(r['direct_entry_external_symbols'] or []),r['object']])
print(json.dumps(summary,indent=2))
