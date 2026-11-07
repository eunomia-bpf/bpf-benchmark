"""Reconcile generic compiled-BPF read observations with captured sources and ELF bytes."""
from pathlib import Path
from collections import Counter
import csv,gzip,hashlib,io,json,struct,subprocess,tarfile
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[5];OUT=Path(__file__).resolve().parent
def sha(data):return hashlib.sha256(data).hexdigest()
def main():
 launch=json.loads((OUT/'launch.json').read_text());status=json.loads((OUT/'status.json').read_text())
 with tarfile.open(OUT/'inputs.tar.gz') as archive:
  actual={m.name:archive.extractfile(m).read() for m in archive.getmembers() if m.isfile()}
 for name,data in actual.items():
  if name.startswith('lane-F/'):continue
  assert sha(data)==launch['source_sha256'][name],name
 owner='corpus/results/kprog_app_coverage_20261107/register-representation-candidates/raw.tar.gz'
 owner_data=subprocess.check_output(['git','show',launch['candidate_publication']+':'+owner],cwd=ROOT)
 assert owner_data==(OUT/'candidate-inputs.tar.gz').read_bytes()
 with tarfile.open(fileobj=io.BytesIO(owner_data)) as archive:
  before=archive.extractfile('narrow-read/before.h').read()
  candidate=archive.extractfile('narrow-read/include/generated/x86_reg_read.h').read()
 assert before==(OUT/'before/x86_reg_read.h').read_bytes()
 assert candidate==(OUT/'candidate/x86_reg_read.h').read_bytes()
 published_width=subprocess.check_output(['git','show',launch['source_head']+':kprog/formal/generated/x86_width.h'],cwd=ROOT)
 assert published_width==(OUT/'x86_width.h').read_bytes()
 object_pins=json.loads((OUT/'compiled-objects.json').read_text())
 with tarfile.open(OUT/'compiled-objects.tar.gz') as archive:
  assert {m.name:sha(archive.extractfile(m).read()) for m in archive.getmembers() if m.isfile()}==object_pins
 bytecode=json.loads((OUT/'bytecode.json').read_text())
 forms=json.loads((OUT/'forms.json').read_text());assert len(forms)==20 and len(bytecode)==40
 for variant in ['before','candidate']:
  with (OUT/variant/'reads.o').open('rb') as f:
   assert sha(f.read())==object_pins[str((OUT/variant/'reads.o').relative_to(ROOT))]
   f.seek(0);elf=ELFFile(f)
   functions={s.name:s for s in elf.get_section_by_name('.symtab').iter_symbols() if s['st_info']['type']=='STT_FUNC'}
   assert set(functions)=={row['name'] for row in forms}
   for row in bytecode:
    if row['variant']!=variant:continue
    symbol=functions[row['form']];section=elf.get_section(symbol['st_shndx'])
    data=section.data()[symbol['st_value']:symbol['st_value']+symbol['st_size']]
    assert sha(data)==row['sha256'] and len(data)==row['bytes']
    assert [list(struct.unpack('<BBhi',data[i:i+8])) for i in range(0,len(data),8)]==row['instructions']
    assert all((ins[0]&7) not in [2,3] and ins[0]!=0x85 for ins in row['instructions'])
 with (OUT/'forms.tsv').open() as f:rows=list(csv.DictReader(f,delimiter='\t'))
 assert len(rows)==40
 for variant in ['before','candidate']:
  selected=[r for r in rows if r['variant']==variant]
  assert len(selected)==20 and {r['form'] for r in selected}=={r['name'] for r in forms}
  assert all(int(row['cases'])==335872 for row in selected)
  assert all(int(row['guard_taken'])>=8192 for row in selected if row['guarded']=='1')
 summary=json.loads((OUT/'summary.json').read_text())
 for variant in ['before','candidate']:
  for key,value in summary['variants'][variant].items():
   if key=='forms':assert value==20
   else:assert value==sum(int(row[key]) for row in rows if row['variant']==variant)
 mismatch=gzip.decompress((OUT/'mismatches.jsonl.gz').read_bytes())
 executable=json.loads((OUT/'executable-pins.json').read_text())
 assert sha(gzip.decompress((OUT/'check-x86.gz').read_bytes()))==executable['binary_sha256']
 changed=[]
 for name in [r['name'] for r in forms]:
  a=next(r for r in bytecode if r['variant']=='before' and r['form']==name)
  b=next(r for r in bytecode if r['variant']=='candidate' and r['form']==name)
  if a['sha256']!=b['sha256']:changed.append(name)
 report=dict(source_archive_files=len(actual),source_archive_identity_equal=True,
  owner_publication=launch['candidate_publication'],before_header_sha256=sha(before),
  candidate_header_sha256=sha(candidate),width_header_git_equal=True,
  compiled_object_count=len(object_pins),extracted_functions=40,elf_bytecode_identity_equal=True,
  bytecode_changed_forms=changed,bytecode_store_instructions=0,bytecode_helper_calls=0,
  mismatch_records=len(mismatch.splitlines()),cases=summary['total_cases'],binary_sha256=executable['binary_sha256'],
  captured_vm_object_count=len(launch['cached_vm_objects']),recorded_exit=status['exit'],source_drift=status['source_drift'])
 (OUT/'review.json').write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps(report,indent=2))
if __name__=='__main__':main()
