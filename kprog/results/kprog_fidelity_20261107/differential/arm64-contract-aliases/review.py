#!/usr/bin/env python3
"""Collect the exact synchronized contract snapshot and compressed observations."""
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

ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
BUILD=ROOT/'kprog/fidelity/build-arm64-contract-aliases'
CANDIDATE=ROOT/'corpus/results/kprog_arm64_app_coverage_20261107/numeric-contract-sync'

def sha(data):
    return hashlib.sha256(data).hexdigest()

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    loaded=importlib.util.module_from_spec(spec)
    sys.modules[name]=loaded
    spec.loader.exec_module(loaded)
    return loaded

def main():
    status=json.loads((OUT/'status.json').read_text())
    assert status['exit']==0 and status['source_drift']=={}
    launch=json.loads((OUT/'launch.json').read_text())
    manifest=json.loads((OUT/'actual-compiled-inputs.json').read_text())
    changes=json.loads((BUILD/'candidate-changes.json').read_text())
    assert changes['production_adoption']=='owner_sync_pending'
    assert changes['retained_direct_tokens']==69 and changes['generated_body_text_equal']
    with tarfile.open(OUT/'actual-compiled-inputs.tar.gz') as archive:
        members={m.name:m for m in archive.getmembers() if m.isfile()}
        assert set(members)==set(manifest)
        for name,digest in manifest.items():
            assert sha(archive.extractfile(members[name]).read())==digest,name
    production={}
    candidate={}
    prefix='kprog/fidelity/build-arm64-contract-aliases/snapshot/'
    with tarfile.open(CANDIDATE/'inputs.tar.gz') as archive:
        for name,digest in manifest.items():
            if name.startswith(prefix):
                original=name[len(prefix):]
                if original in changes['changes']:
                    data=archive.extractfile('after/'+original).read()
                    assert sha(data)==digest==changes['changes'][original]['after_sha256']
                    candidate[original]=digest
                else:
                    data=subprocess.check_output(['git','show',launch['source_head']+':'+original],cwd=ROOT)
                    assert sha(data)==digest,original
                    production[original]=digest
    assert len(candidate)==3
    sys.path.insert(0,str(ROOT/'kprog/fidelity'))
    encoder_path=ROOT/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py'
    assert sha(encoder_path.read_bytes())==launch['source_sha256'][str(encoder_path.relative_to(ROOT))]
    sys.path.insert(0,str(encoder_path.parent))
    encoder=module('fidelity_arm_encoder',encoder_path)
    generator=module('fidelity_generator',ROOT/'kprog/fidelity/generate.py')
    assert sha((ROOT/'kprog/fidelity/generate.py').read_bytes())==launch['source_sha256']['kprog/fidelity/generate.py']
    matrix=generator.arm64_forms()
    instructions=encoder.parse_flat_instructions((BUILD/'instructions.asm').read_text())
    assert len(matrix)==len(instructions)
    by_assembly=dict(zip(matrix,instructions))
    bindings=json.loads((BUILD/'numeric-bindings.json').read_text())
    forms=json.loads((OUT/'coverage.json').read_text())
    native=json.loads((OUT/'native-code.json').read_text())['forms']
    assert len(bindings)==len(forms)==len(native)==60
    tokens={'ARM64_OP_ADD_IMM','ARM64_OP_SUB_IMM','ARM64_OP_ALU_IMM'}
    for i in range(0,60,6):
        assembly=bindings[i]['assembly']
        encoded=asdict(encoder.encode(by_assembly[assembly],{},{}))
        for j in range(i,i+6):
            binding=bindings[j]
            assert binding['original']==encoded
            assert binding['bound']['op'] in tokens
            assert {key:value for key,value in binding['bound'].items() if key!='op'}=={key:value for key,value in encoded.items() if key!='op'}
            assert native[j]['native_bytes']==native[i]['native_bytes']
        assert {b['bound']['op'] for b in bindings[i:i+6]}==tokens
        assert [b['route'] for b in bindings[i:i+6]]==['raw','direct']*3
    with (OUT/'forms.tsv').open() as source:
        observed=list(csv.DictReader(source,delimiter='\t'))
    with (OUT/'reference-forms.tsv').open() as source:
        reference=list(csv.DictReader(source,delimiter='\t'))
    assert len(observed)==len(reference)==60
    storage=json.loads((OUT/'trace-storage.json').read_text())
    packed=OUT/storage['path']
    assert sha(packed.read_bytes())==storage['compressed_sha256']
    process=subprocess.Popen(['zstd','-dcq',str(packed)],stdout=subprocess.PIPE)
    digest=hashlib.sha256()
    bytes_read=0
    def read(size):
        nonlocal bytes_read
        data=process.stdout.read(size)
        assert len(data)==size
        digest.update(data)
        bytes_read+=len(data)
        return data
    rows=[]
    try:
        assert read(8)==b'KPFID002'
        size,memory,count,cases=struct.unpack('<4I',read(16))
        assert (size,memory,count,cases)==(344,256,60,1024)
        for i,(binding,cpu,replay) in enumerate(zip(bindings,observed,reference)):
            assert int(cpu['cases'])==int(replay['reference_cases'])==cases
            assert int(cpu['mismatches'])==int(replay['cpu_mismatches'])==int(replay['simulator_mismatches'])==0
            assert replay['status']=='checked'
            unchanged=0
            for j in range(cases):
                assert struct.unpack('<2I',read(8))==(i,j)
                read(8)
                initial,host,sim=[read(size) for k in range(3)]
                assert host[:256]==sim[:256] and host[264:]==sim[264:]
                assert ((struct.unpack_from('<Q',host,256)[0]^struct.unpack_from('<Q',sim,256)[0])&0xf0000000)==0
                before,host_memory,sim_memory=[read(memory) for k in range(3)]
                unchanged+=before==host_memory==sim_memory
            assert unchanged==cases
            rows.append(dict(form=i,assembly=binding['assembly'],route=binding['route'],
                             token=binding['bound']['op'],aux=binding['bound']['aux'],
                             width=binding['bound']['width'],cases=cases,
                             cpu_simulator_mismatches=0,cpu_reference_mismatches=0,
                             simulator_reference_mismatches=0,unchanged_memory_cases=unchanged))
        assert process.stdout.read(1)==b''
        assert process.wait()==0
    finally:
        if process.poll() is None:
            process.terminate()
            process.wait()
    assert bytes_read==storage['raw_bytes'] and digest.hexdigest()==storage['raw_sha256']
    with (OUT/'observations.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n')
        writer.writeheader();writer.writerows(rows)
    summary=dict(forms=60,native_forms=10,cases=sum(row['cases'] for row in rows),
                 operations=sorted({row['assembly'].split()[0] for row in rows}),
                 tokens=sorted(tokens),widths=[32,64],differences=dict(cpu_simulator=0,cpu_reference=0,simulator_reference=0),
                 forms_awaiting_reference=0,unchanged_memory_cases=sum(row['unchanged_memory_cases'] for row in rows),
                 compiled_input_files=len(manifest),production_snapshot_files=len(production),
                 candidate_snapshot_files=len(candidate),production_snapshot_git_equal=True,
                 candidate_headers_equal_published_bundle=True,candidate_commit=changes['candidate_commit'],
                 candidate_inputs_sha256=changes['candidate_inputs_sha256'],encoded_fields_preserved=True,
                 native_byte_groups=10,raw_direct_native_byte_pairs=30,source_head=launch['source_head'],
                 reference_sha256=launch['reference_sha256'],binary_sha256=sha((BUILD/'cpu-differential').read_bytes()),
                 trace=storage,finished=status['finished'],source_drift=status['source_drift'],
                 production_adoption=changes['production_adoption'])
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps(summary,indent=2))

if __name__=='__main__':
    main()
