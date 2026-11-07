#!/usr/bin/env python3
"""Collect architectural observations and source identities for partial-register storage."""
import csv
from dataclasses import asdict
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import tarfile
sys.dont_write_bytecode=True
ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
BUILD=ROOT/'kprog/fidelity/build-x86-partial-gpr-candidate'
PREFIX='kprog/fidelity/build-x86-partial-gpr-candidate/snapshot/'
def sha(data):
    return hashlib.sha256(data).hexdigest()
def main():
    launch=json.loads((OUT/'launch.json').read_text())
    status=json.loads((OUT/'status.json').read_text())
    manifest=json.loads((OUT/'actual-compiled-inputs.json').read_text())
    with tarfile.open(OUT/'actual-compiled-inputs.tar.gz') as archive:
        members={m.name:m for m in archive.getmembers() if m.isfile()}
        assert set(members)==set(manifest)
        for name,digest in manifest.items():
            assert sha(archive.extractfile(members[name]).read())==digest,name
            if name.startswith(PREFIX):
                assert sha((ROOT/name).read_bytes())==digest,name
    candidate='kprog/formal/generated/x86_reg_write.h'
    with tarfile.open(OUT/'candidate-inputs.tar.gz') as archive:
        prior=archive.extractfile('before.h').read()
        after=archive.extractfile('include/generated/x86_reg_write.h').read()
    publication='52e83e0216f760f70b62c973c5d32aeb3f0615b0'
    owner_path='corpus/results/kprog_app_coverage_20261107/partial-gpr-storage-candidate/raw.tar.gz'
    assert subprocess.check_output(['git','show',publication+':'+owner_path],cwd=ROOT)==(OUT/'candidate-inputs.tar.gz').read_bytes()
    assert sha(prior)==launch['source_sha256'][candidate]
    assert sha(after)==manifest[PREFIX+candidate]
    production={};git_differences={}
    for name,digest in manifest.items():
        if name.startswith(PREFIX) and '/__pycache__/' not in name:
            original=name[len(PREFIX):]
            if original==candidate:
                continue
            if original in launch['source_sha256']:
                assert digest==launch['source_sha256'][original],original
            production[original]=digest
            published=subprocess.check_output(['git','show',launch['source_head']+':'+original],cwd=ROOT)
            if sha(published)!=digest:
                git_differences[original]=dict(git_sha256=sha(published),launch_sha256=digest)
    sys.path.insert(0,str(BUILD/'snapshot/kprog/x86/micro-prog'))
    encoder_path=BUILD/'snapshot/kprog/x86/micro-prog/generate_micro_sim_proofs.py'
    spec=importlib.util.spec_from_file_location('partial_gpr_encoder',encoder_path)
    encoder=importlib.util.module_from_spec(spec);sys.modules[spec.name]=encoder
    spec.loader.exec_module(encoder)
    bindings=json.loads((BUILD/'numeric-bindings.json').read_text())
    forms=json.loads((OUT/'coverage.json').read_text())
    native=json.loads((OUT/'native-code.json').read_text())['forms']
    instructions=encoder.parse_asm_text((BUILD/'instructions.asm').read_text())
    assert len(instructions)==16 and len(bindings)==len(forms)==len(native)==32
    for i,instruction in enumerate(instructions):
        encoded=asdict(encoder.encode(instruction,{}))
        assert encoded==bindings[2*i]['encoded']==bindings[2*i+1]['encoded']
        assert native[2*i]['native_bytes']==native[2*i+1]['native_bytes']
        assert [forms[2*i]['route'],forms[2*i+1]['route']]==['raw','direct']
    with (OUT/'forms.tsv').open() as f:
        cpu=list(csv.DictReader(f,delimiter='\t'))
    with (OUT/'reference-forms.tsv').open() as f:
        reference=list(csv.DictReader(f,delimiter='\t'))
    assert len(cpu)==len(reference)==32
    storage=json.loads((OUT/'trace-storage.json').read_text())
    packed=OUT/storage['path']
    assert sha(packed.read_bytes())==storage['compressed_sha256']
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
        assert (size,memory,count,cases)==(344,256,32,1024)
        for i,(form,observed,replay) in enumerate(zip(forms,cpu,reference)):
            assert observed['assembly']==replay['assembly']==form['assembly']
            assert int(observed['cases'])==cases
            differences=0;unchanged_memory=0
            for j in range(cases):
                assert struct.unpack('<2I',read(8))==(i,j)
                read(8)
                initial,host,sim=[read(size) for k in range(3)]
                before,host_memory,sim_memory=[read(memory) for k in range(3)]
                unchanged_memory+=before==host_memory==sim_memory
                differences+=(host[:256]!=sim[:256] or host[264:]!=sim[264:] or
                    ((struct.unpack_from('<Q',host,256)[0]^struct.unpack_from('<Q',sim,256)[0])&0x8d5)!=0 or host_memory!=sim_memory)
            assert differences==int(observed['mismatches'])
            rows.append(dict(form=i,assembly=form['assembly'],route=form['route'],opcode=form['opcode'],
                cases=cases,cpu_simulator_mismatches=differences,reference_cases=int(replay['reference_cases']),
                cpu_reference_mismatches=int(replay['cpu_mismatches']),
                simulator_reference_mismatches=int(replay['simulator_mismatches']),
                reference_status=replay['status'],unchanged_memory_cases=unchanged_memory))
        assert process.stdout.read(1)==b''
        assert process.wait()==0
    finally:
        if process.poll() is None:
            process.terminate();process.wait()
    assert length==storage['raw_bytes'] and digest.hexdigest()==storage['raw_sha256']
    with (OUT/'observations.tsv').open('w') as f:
        writer=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n')
        writer.writeheader();writer.writerows(rows)
    summary=dict(native_forms=16,groups=len(rows),cases=sum(row['cases'] for row in rows),
        differences=dict(cpu_simulator=sum(row['cpu_simulator_mismatches'] for row in rows),
                         cpu_reference=sum(row['cpu_reference_mismatches'] for row in rows),
                         simulator_reference=sum(row['simulator_reference_mismatches'] for row in rows)),
        forms_awaiting_reference=sum(row['reference_cases']==0 for row in rows),
        unchanged_memory_cases=sum(row['unchanged_memory_cases'] for row in rows),
        compiled_input_files=len(manifest),production_snapshot_files=len(production),candidate_snapshot_files=1,
        launch_pinned_snapshot_files=sum(name in launch['source_sha256'] for name in production),
        snapshot_launch_identity_equal=True,snapshot_git_differences=git_differences,
        derived_source_cache_files=sum('/__pycache__/' in name for name in manifest),
        candidate_publication=publication,candidate_before_sha256=sha(prior),candidate_after_sha256=sha(after),
        encoded_fields_preserved=True,raw_direct_native_byte_pairs=16,
        source_head=launch['source_head'],reference_sha256=launch['reference_sha256'],
        binary_sha256=sha((BUILD/'cpu-differential').read_bytes()),
        trace_bytes=length,trace_sha256=digest.hexdigest(),finished=status['finished'],
        observer_exit=status['exit'],source_drift=status['source_drift'])
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps(summary,indent=2))
if __name__=='__main__':
    main()
