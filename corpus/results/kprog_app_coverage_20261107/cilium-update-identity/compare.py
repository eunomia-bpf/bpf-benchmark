"""Replay captured source/plan bytes through the old and corrected linker only."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,json,subprocess
O=Path(__file__).resolve().parent;S=Path('/workspaces/.agent-state/kprog-lanes/C/cilium-update-identity')
assert not (O/'offline').exists(),'preserve previous comparison'
D=O/'offline';D.mkdir();names=json.loads((O/'baseline.json').read_text())['map_error_counts'];rows=[]
for plan in sorted(O.glob('cache-*/native_kernel_link_cache/*.link-plan.json')):
 data=json.loads(plan.read_text());maps={r['name']:r['addr'] for r in data['maps']}
 matches={name:sum(name in r.get('map_names',[]) for r in data['update_sites']) for name in names if name in maps}
 if not any(n>1 for n in matches.values()):continue
 key=plan.name.split('.')[0];proof=plan.parent/(key+'.proof.o');assert proof.is_file(),proof
 with proof.open('rb') as f:
  e=ELFFile(f);entry=[r.name for r in e.get_section_by_name('.symtab').iter_symbols() if r['st_info']['type']=='STT_FUNC' and isinstance(r['st_shndx'],int) and r['st_value']==0]
 assert len(entry)==1,(proof,entry)
 row=dict(key=key,entry=entry[0],proof_sha256=hashlib.sha256(proof.read_bytes()).hexdigest(),plan_sha256=hashlib.sha256(plan.read_bytes()).hexdigest(),full_map_identity_matches=matches)
 for kind,binary in [('baseline',S/'baseline-native-link'),('corrected',S/'package/native-link')]:
  prefix=D/(key+'.'+kind)
  command=[str(binary),'--input',str(proof),'--symbol',entry[0],'--mode','kernel','--output',str(prefix)+'.bin','--output-relocs',str(prefix)+'.relocs','--output-map-patches',str(prefix)+'.maps','--output-abi',str(prefix)+'.abi','--output-data-layout',str(prefix)+'.data.json','--link-plan',str(plan)]
  done=subprocess.run(command,capture_output=True,text=True);Path(str(prefix)+'.stdout').write_text(done.stdout);Path(str(prefix)+'.stderr').write_text(done.stderr)
  row[kind]=dict(returncode=done.returncode,truncation_ambiguity='truncation-matches multiple update_sites' in done.stderr)
  if kind=='corrected' and done.returncode==0:
   row['matches_actual_cached_blob']=Path(str(prefix)+'.bin').read_bytes()==(plan.parent/(key+'.blob.bin')).read_bytes()
 rows.append(row);(O/'same-input-comparison.json').write_text(json.dumps(rows,indent=2)+'\n')
print(json.dumps(dict(compared=len(rows),baseline_ambiguity=sum(r['baseline']['truncation_ambiguity'] for r in rows),corrected_failed=sum(r['corrected']['returncode']!=0 for r in rows),actual_blob_equal=sum(r.get('matches_actual_cached_blob',False) for r in rows))),flush=True)
if not rows or any(r['corrected']['returncode'] for r in rows):raise RuntimeError('inspect captured same-input comparison')
