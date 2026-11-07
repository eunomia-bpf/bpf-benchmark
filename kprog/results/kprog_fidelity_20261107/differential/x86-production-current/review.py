"""Collect source identities and complete architectural observations for a production epoch."""
import csv,gzip,hashlib,json,re,struct,subprocess,tarfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5];OUT=Path(__file__).resolve().parent
BUILD=ROOT/'kprog/fidelity/build-x86-production-current'
PREFIX='kprog/fidelity/build-x86-production-current/snapshot/'
def sha(data):return hashlib.sha256(data).hexdigest()
def main():
    launch=json.loads((OUT/'launch.json').read_text());status=json.loads((OUT/'status.json').read_text())
    manifest=json.loads((OUT/'actual-compiled-inputs.json').read_text())
    with tarfile.open(OUT/'actual-compiled-inputs.tar.gz') as archive:
        members={m.name:m for m in archive.getmembers() if m.isfile()}
        assert set(members)==set(manifest)
        generated_bytes=archive.extractfile(str((BUILD/'generated.c').relative_to(ROOT))).read()
        for name,digest in manifest.items():
            assert sha(archive.extractfile(members[name]).read())==digest,name
    production={}
    for name,digest in manifest.items():
        if name.startswith(PREFIX) and '/__pycache__/' not in name:
            original=name[len(PREFIX):]
            published=subprocess.check_output(['git','show',launch['source_head']+':'+original],cwd=ROOT)
            assert sha(published)==digest,original
            production[original]=digest
    assert production['kprog/formal/generated/x86_reg_write.h']=='cf27e323c885cdf8258974a8800907af2f6ee56093d7721822b9e75360e72994'
    assert production['kprog/x86/x86_sim_local_bpf.h']=='6b3f31731d9d127a36183e3e35cd6b39335d8b5865649a8282fc503a7be0dc11'
    assert sha(generated_bytes)==manifest[str((BUILD/'generated.c').relative_to(ROOT))]
    pattern=re.compile(r'^\{(?P<assembly>"(?:[^"\\]|\\.)*"), (?P<opcode>"[^"]+"), native_(?P<index>\d+), sim_(?P=index), (?P<mask>\d+)U, (?P<width>\d+), (?P<count>-?\d+), (?P<mode>\d+), &native_pc_(?P=index), &native_next_(?P=index)\},?$',re.M)
    entries=[match.groupdict() for match in pattern.finditer(generated_bytes.decode())]
    forms=json.loads((OUT/'coverage.json').read_text())
    with (OUT/'forms.tsv').open() as source:cpu=list(csv.DictReader(source,delimiter='\t'))
    with (OUT/'reference-forms.tsv').open() as source:reference=list(csv.DictReader(source,delimiter='\t'))
    assert len(entries)==len(forms)==len(cpu)==len(reference)==launch['expected_forms']
    storage=json.loads((OUT/'trace-storage.json').read_text())
    packed=OUT/storage['path'];assert sha(packed.read_bytes())==storage['compressed_sha256']
    process=subprocess.Popen(['zstd','-dcq',str(packed)],stdout=subprocess.PIPE)
    digest=hashlib.sha256();length=0
    def read(size):
        nonlocal length
        data=process.stdout.read(size);assert len(data)==size
        digest.update(data);length+=len(data);return data
    rows=[]
    try:
        assert read(8)==b'KPFID002'
        size,memory,count,cases=struct.unpack('<4I',read(16))
        assert (size,memory,count,cases)==(344,256,launch['expected_forms'],launch['cases_per_form'])
        for i,(entry,form,observed,replay) in enumerate(zip(entries,forms,cpu,reference)):
            assert int(entry['index'])==i
            assert json.loads(entry['assembly'])==form['assembly']==observed['assembly']==replay['assembly']
            assert json.loads(entry['opcode'])==form['opcode']==observed['opcode']
            assert int(observed['cases'])==int(replay['cases'])==cases
            differences=0;memory_write_cases=0
            for j in range(cases):
                assert struct.unpack('<2I',read(8))==(i,j)
                read(8)
                initial,host,sim=[read(size) for k in range(3)]
                before,host_memory,sim_memory=[read(memory) for k in range(3)]
                mask=int(entry['mask']);mode=int(entry['mode']);width=int(entry['width'])
                if mode in [2,3]:
                    effective=struct.unpack_from('<Q',initial,8)[0] if int(entry['count'])==256 else int(entry['count'])
                    effective&=63 if width==64 else 31
                    if mode==2 and effective:mask&=~0x10
                    if effective>1:mask&=~0x800
                    if mode==2 and effective>=width:mask&=~1
                different=(host[:256]!=sim[:256] or host[264:]!=sim[264:] or
                    ((struct.unpack_from('<Q',host,256)[0]^struct.unpack_from('<Q',sim,256)[0])&mask)!=0 or host_memory!=sim_memory)
                differences+=different;memory_write_cases+=host_memory!=before
            assert differences==int(observed['mismatches'])
            rows.append(dict(form=i,assembly=form['assembly'],opcode=form['opcode'],cases=cases,
                cpu_simulator_mismatches=differences,reference_cases=int(replay['reference_cases']),
                cpu_reference_mismatches=int(replay['cpu_mismatches']),
                simulator_reference_mismatches=int(replay['simulator_mismatches']),
                reference_status=replay['status'],native_memory_write_cases=memory_write_cases))
        assert process.stdout.read(1)==b'' and process.wait()==0
    finally:
        if process.poll() is None:process.terminate();process.wait()
    assert length==storage['raw_bytes'] and digest.hexdigest()==storage['raw_sha256']
    executable=json.loads((OUT/'executable-pins.json').read_text())
    assert sha(gzip.decompress((OUT/'cpu-differential-x86.gz').read_bytes()))==executable['binary_sha256']
    with (OUT/'observations.tsv').open('w') as source:
        writer=csv.DictWriter(source,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n')
        writer.writeheader();writer.writerows(rows)
    summary=dict(forms=len(rows),cases_per_form=cases,cases=sum(row['cases'] for row in rows),
        differences=dict(cpu_simulator=sum(row['cpu_simulator_mismatches'] for row in rows),
                         cpu_reference=sum(row['cpu_reference_mismatches'] for row in rows),
                         simulator_reference=sum(row['simulator_reference_mismatches'] for row in rows)),
        forms_awaiting_reference=sum(row['reference_cases']==0 for row in rows),
        reference_cases=sum(row['reference_cases'] for row in rows),
        initial_command_exit=status['exit'],
        canonical_completion_exit=json.loads((OUT/'replay-interface.json').read_text())['control_completion']['exit'],
        canonical_finished=json.loads((OUT/'replay-interface.json').read_text())['control_completion']['finished'],
        native_memory_write_cases=sum(row['native_memory_write_cases'] for row in rows),
        compiled_input_files=len(manifest),production_snapshot_files=len(production),
        production_snapshot_git_equal=True,derived_source_cache_files=sum('/__pycache__/' in name for name in manifest),
        source_head=launch['source_head'],adopted_write_commit=launch['adopted_write_commit'],
        simulator_header_sha256=production['kprog/x86/x86_sim_local_bpf.h'],
        register_write_sha256=production['kprog/formal/generated/x86_reg_write.h'],
        reference_sha256=launch['reference_sha256'],binary_sha256=executable['binary_sha256'],
        trace_bytes=length,trace_sha256=digest.hexdigest(),exit=status['exit'],finished=status['finished'],
        source_drift=status['source_drift'])
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps(summary,indent=2))
if __name__=='__main__':main()
