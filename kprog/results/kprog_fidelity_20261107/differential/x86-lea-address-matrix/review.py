#!/usr/bin/env python3
"""Collect LEA source identities and compressed architectural observations."""
import csv
from dataclasses import asdict
import gzip
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import struct
import subprocess
import sys
import tarfile
import tempfile

sys.dont_write_bytecode=True

ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
BUILD=ROOT/'kprog/fidelity/build-x86-lea-address-matrix'
PREFIX='kprog/fidelity/build-x86-lea-address-matrix/snapshot/'

def sha(data):
    return hashlib.sha256(data).hexdigest()

def main():
    launch=json.loads((OUT/'launch.json').read_text())
    status=json.loads((OUT/'status.json').read_text())
    changes=json.loads((BUILD/'candidate-changes.json').read_text())
    manifest=json.loads((OUT/'actual-compiled-inputs.json').read_text())
    with tarfile.open(OUT/'actual-compiled-inputs.tar.gz') as archive:
        members={m.name:m for m in archive.getmembers() if m.isfile()}
        assert set(members)==set(manifest)
        for name,digest in manifest.items():
            assert sha(archive.extractfile(members[name]).read())==digest,name
            if name.startswith(PREFIX):
                assert sha((ROOT/name).read_bytes())==digest,name
    with tarfile.open(OUT/'launch-inputs.tar.gz') as archive:
        patch_path='kprog/results/kprog_verification_20261107/lea-corrections.patch.gz'
        packed=archive.extractfile(patch_path).read()
    assert sha(packed)==changes['patch_sha256']
    correction=gzip.decompress(packed)
    with tempfile.TemporaryDirectory(prefix='lea-source-review-',dir='/workspaces/.agent-state/kprog-lanes/F') as temp:
        temp=Path(temp)
        for name,row in changes['changes'].items():
            before=subprocess.check_output(['git','show',launch['source_head']+':'+name],cwd=ROOT)
            assert sha(before)==row['before_sha256'],name
            target=temp/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(before)
        completed=subprocess.run(['patch','-p1','--batch','--forward'],input=correction,cwd=temp,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        assert completed.returncode==0,completed.stdout.decode()
        for name,row in changes['changes'].items():
            assert sha((temp/name).read_bytes())==row['after_sha256']
    production={}
    private={}
    for name,digest in manifest.items():
        if name.startswith(PREFIX) and '/__pycache__/' not in name:
            original=name[len(PREFIX):]
            if original in changes['used_snapshot_changes']:
                assert digest==changes['changes'][original]['after_sha256']
                private[original]=digest
            else:
                before=subprocess.check_output(['git','show',launch['source_head']+':'+original],cwd=ROOT)
                assert sha(before)==digest,original
                production[original]=digest
    assert len(production)==80 and len(private)==2
    snapshot=BUILD/'snapshot'
    sys.path.insert(0,str(snapshot/'kprog/x86/micro-prog'))
    encoder_path=snapshot/'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
    spec=importlib.util.spec_from_file_location('lea_encoder',encoder_path)
    encoder=importlib.util.module_from_spec(spec);sys.modules[spec.name]=encoder
    spec.loader.exec_module(encoder)
    bindings=json.loads((BUILD/'numeric-bindings.json').read_text())
    forms=json.loads((OUT/'coverage.json').read_text())
    native=json.loads((OUT/'native-code.json').read_text())['forms']
    instructions=encoder.parse_asm_text((BUILD/'instructions.asm').read_text())
    assert len(instructions)==384 and len(bindings)==len(forms)==len(native)==768
    for index,instruction in enumerate(instructions):
        encoded=asdict(encoder.encode(instruction,{}))
        assert bindings[2*index]['encoded']==bindings[2*index+1]['encoded']==encoded
        assert native[2*index]['native_bytes']==native[2*index+1]['native_bytes']
        assert [bindings[2*index]['route'],bindings[2*index+1]['route']]==['raw','direct']
    with (OUT/'forms.tsv').open() as source:
        cpu=list(csv.DictReader(source,delimiter='\t'))
    with (OUT/'reference-forms.tsv').open() as source:
        refs=list(csv.DictReader(source,delimiter='\t'))
    assert len(cpu)==len(refs)==768
    interface=json.loads((OUT/'production-interface.json').read_text())
    for name,digest in interface['headers_sha256'].items():
        data=subprocess.check_output(['git','show',interface['production_commit']+':'+name],cwd=ROOT)
        assert sha(data)==digest==sha((snapshot/name).read_bytes())
    emitted=[]
    for index,instruction in enumerate(instructions):
        encoded=encoder.encode(instruction,{})
        emitted.append(dict(form=index,encoded=asdict(encoded),direct_statement=encoder.direct_step_statement(encoded)))
    assert sha(json.dumps(emitted,sort_keys=True).encode())==interface['field_and_direct_statement_sha256']
    storage=json.loads((OUT/'trace-storage.json').read_text())
    packed=OUT/storage['path']
    assert sha(packed.read_bytes())==storage['compressed_sha256']
    process=subprocess.Popen(['zstd','-dcq',str(packed)],stdout=subprocess.PIPE)
    digest=hashlib.sha256();bytes_read=0
    def read(size):
        nonlocal bytes_read
        data=process.stdout.read(size);assert len(data)==size
        digest.update(data);bytes_read+=len(data)
        return data
    rows=[]
    try:
        assert read(8)==b'KPFID002'
        size,memory,count,cases=struct.unpack('<4I',read(16))
        assert (size,memory,count,cases)==(344,256,768,256)
        for i,(form,observed,reference) in enumerate(zip(forms,cpu,refs)):
            assert observed['assembly']==reference['assembly']==form['assembly']
            assert int(observed['cases'])==int(reference['cases'])==cases
            memory_retained=0;state_differences=0
            for j in range(cases):
                assert struct.unpack('<2I',read(8))==(i,j)
                read(8)
                initial,host,sim=[read(size) for k in range(3)]
                before,host_memory,sim_memory=[read(memory) for k in range(3)]
                memory_retained+=before==host_memory==sim_memory
                different=(host[:256]!=sim[:256] or host[264:]!=sim[264:] or
                           ((struct.unpack_from('<Q',host,256)[0]^struct.unpack_from('<Q',sim,256)[0])&0x8d5)!=0 or
                           host_memory!=sim_memory)
                state_differences+=different
            assert state_differences==int(observed['mismatches'])
            width={'ax':16,'eax':32,'rax':64}[form['assembly'].split()[1].removesuffix(',')]
            rows.append(dict(form=i,assembly=form['assembly'],route=form['route'],opcode=form['opcode'],
                             address_bits=64 if i//2<192 else 32,write_bits=width,
                             encoded_flags=bindings[i]['encoded']['flags'],cases=cases,
                             cpu_simulator_mismatches=state_differences,
                             reference_cases=int(reference['reference_cases']),
                             cpu_reference_mismatches=int(reference['cpu_mismatches']),
                             simulator_reference_mismatches=int(reference['simulator_mismatches']),
                             reference_status=reference['status'],unchanged_memory_cases=memory_retained))
        assert process.stdout.read(1)==b''
        assert process.wait()==0
    finally:
        if process.poll() is None:process.terminate();process.wait()
    assert bytes_read==storage['raw_bytes'] and digest.hexdigest()==storage['raw_sha256']
    with (OUT/'observations.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n')
        writer.writeheader();writer.writerows(rows)
    totals=dict(cpu_simulator=sum(r['cpu_simulator_mismatches'] for r in rows),
                cpu_reference=sum(r['cpu_reference_mismatches'] for r in rows),
                simulator_reference=sum(r['simulator_reference_mismatches'] for r in rows))
    summary=dict(native_forms=384,forms=768,cases=sum(r['cases'] for r in rows),
                 differences=totals,forms_awaiting_reference=sum(r['reference_cases']==0 for r in rows),
                 unchanged_memory_cases=sum(r['unchanged_memory_cases'] for r in rows),
                 compiled_input_files=len(manifest),production_snapshot_files=len(production),
                 candidate_snapshot_files=len(private),production_snapshot_git_equal=True,
                 candidate_patch_reproduced=True,candidate_source_sha256=private,
                 derived_source_cache_files=sum('/__pycache__/' in name for name in manifest),
                 raw_direct_native_byte_pairs=384,encoded_fields_preserved=True,
                 source_head=launch['source_head'],reference_sha256=launch['reference_sha256'],
                 binary_sha256=sha((BUILD/'cpu-differential').read_bytes()),
                 correction_commit=changes['correction_commit'],patch_sha256=changes['patch_sha256'],
                 production_source_correspondence=dict(
                     commit=interface['production_commit'],
                     identical_compiled_headers=interface['compiled_headers'],
                     encoded_forms_equal=interface['encoded_forms_equal'],
                     direct_statements_equal=interface['direct_statements_equal'],
                     report_sha256=sha((OUT/'production-interface.json').read_bytes())),
                 trace=storage,exit=status['exit'],finished=status['finished'],
                 live_source_drift=status['source_drift'],production_adoption=changes['production_adoption'])
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps(summary,indent=2))

if __name__=='__main__':
    main()
