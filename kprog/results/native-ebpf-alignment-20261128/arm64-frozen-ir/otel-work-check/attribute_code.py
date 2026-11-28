"""Attribute the actual frozen ARM proofs to three installed code readbacks."""
from pathlib import Path
import hashlib,json
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
OUT=Path(__file__).resolve().parent;c=json.loads((OUT/'controller.json').read_text());RAW=Path(c['raw']);cache=RAW/'observations/data/linkcache'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def inspect(p):
 with p.open('rb') as f:
  elf=ELFFile(f);tab=elf.get_section_by_name('.symtab');entry=[s.name for s in tab.iter_symbols() if s['st_info']['type']=='STT_FUNC' and s['st_info']['bind']=='STB_GLOBAL' and s.name!='__native_link_arm64_ret_trampoline'];calls=0
  for sec in elf.iter_sections():
   if not isinstance(sec,RelocationSection) or not elf.get_section(sec['sh_info'])['sh_flags']&4:continue
   symbols=elf.get_section(sec['sh_link']);calls+=sum(symbols.get_symbol(r['r_info_sym']).name=='bpf_trace_printk' and r['r_info_type']==283 for r in sec.iter_relocations())
  return dict(file=str(p.relative_to(RAW)),sha256=sha(p),entry=entry,trace_printk_call_relocations=calls)
rows=[]
for p in sorted(cache.glob('*.proof.o')):
 if '.tmp.' in p.name:continue
 row=inspect(p);assert len(row['entry'])==1;key=p.name.split('.')[0];optimized=list(cache.glob(key+'.*.frozen.proof.o'));plans=list(cache.glob(key+'.*.link-plan.json'));assert len(optimized)==len(plans)==1;row['optimized']=inspect(optimized[0]);plan=json.loads(plans[0].read_text());row['const_values']=plan['const_values'];row['plan']=str(plans[0].relative_to(RAW));blob=cache/(key+'.blob.bin');data=blob.read_bytes();row['blob']=dict(file=str(blob.relative_to(RAW)),bytes=len(data),sha256=sha(blob));row['installed_readbacks']=[]
 for q in (RAW/'observations/data/progdump').rglob('*.jited.bin'):
  if q.name.split('-')[-1]!=''.join(row['entry'])[:15]+'.jited.bin':continue
  installed=q.read_bytes();patches=[]
  for line in (cache/(key+'.map-patches.tsv')).read_text().splitlines():
   name,off=line.split('\t');off=int(off);assert off+8<=len(data);patches.append((name,off))
  first=min([off for name,off in patches],default=len(data));prefix=data[:first];offset=installed.find(prefix)
  if offset<0 or offset+len(data)>len(installed):continue
  changed=[i for i,(a,b) in enumerate(zip(data,installed[offset:offset+len(data)])) if a!=b];allowed={i for name,off in patches for i in range(off,off+8)}
  outside=[i for i in changed if i not in allowed]
  if outside:continue
  row['installed_readbacks'].append(dict(file=str(q.relative_to(RAW)),bytes=len(installed),sha256=sha(q),blob_offset=offset,all_bytes_equal_except_documented_map_slots=True,changed_bytes=len(changed),map_slot_readbacks=[dict(name=name,offset=off,link_blob_u64=int.from_bytes(data[off:off+8],'little'),installed_u64=int.from_bytes(installed[offset+off:offset+off+8],'little')) for name,off in patches]))
 rows.append(row)
r=dict(programs=rows,program_count=len(rows),all_optimized_debug_calls_zero=all(v['optimized']['trace_printk_call_relocations']==0 for v in rows),total_original_debug_call_relocations=sum(v['trace_printk_call_relocations'] for v in rows),actual_readback_entries=[v['entry'][0] for v in rows if v['installed_readbacks']],limits='Captured entry/unwind-native/stop match actual kernel bytes except exact documented 8-byte map slots (recorded separately); all other instruction/data bytes match. Map slot identity still needs live plan/map evidence. Only these three have kernel readback; other successful install logs plus compiled proof/blob retained separately. Relocation counts are ARM direct call sites, not executed calls. No dynamic unwind-work or complete app-configuration claim follows from eliminating debug calls.')
assert len(rows)==13 and r['all_optimized_debug_calls_zero'];assert set(r['actual_readback_entries'])=={'native_tracer_entry','perf_unwind_native','perf_unwind_stop'}
(OUT/'code-attribution.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(dict(programs=len(rows),all_debug_calls_removed=r['all_optimized_debug_calls_zero'],original_calls=r['total_original_debug_call_relocations'],actual_readbacks=r['actual_readback_entries'],perprogram=[dict(entry=v['entry'][0],before=v['trace_printk_call_relocations'],after=v['optimized']['trace_printk_call_relocations'],readbacks=len(v['installed_readbacks'])) for v in rows]),indent=2))
