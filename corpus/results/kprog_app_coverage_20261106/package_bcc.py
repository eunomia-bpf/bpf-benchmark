"""Package every paired BCC resident entry for the unchanged corpus runtime."""
import json
from pathlib import Path
import shutil
import sys
from elftools.elf.elffile import ELFFile
HERE=Path(__file__).resolve().parent
phase=HERE/sys.argv[1]
out=HERE/sys.argv[2]
out.mkdir()
app=out/'bcc';app.mkdir()
manifest=json.loads((phase/'manifest.json').read_text())
rows=[json.loads(line) for line in (phase/'programs.jsonl').read_text().splitlines()]
if len(manifest['objects'])!=len(rows) or any(not row['ok'] for row in rows):
    raise ValueError('every actual BCC entry must have a generated proof')
proofs={row['original_name']:Path(row['proof']) for row in rows}
for entry in manifest['objects']:
    native=Path(entry['native_object'])
    stem=native.name.removesuffix('.native.o')
    canonical=app/(stem+'.'+entry['symbol']+'.proof.o')
    source_proof=proofs[entry['symbol']]
    shutil.copy2(source_proof,canonical)
    # Check exact readonly identities in the actual paired simulator/native proof.
    with Path(entry['simulator_object']).open('rb') as stream:
        simulator=ELFFile(stream);section=simulator.get_section_by_name('.native_lab.rodata')
        objects=json.loads(section.data().rstrip(b'\0'))['objects'] if section else []
        values={r['native_symbol']:simulator.get_section_by_name(r['proof_section']).data() for r in objects}
    with canonical.open('rb') as stream:
        proof=ELFFile(stream);symbols=proof.get_section_by_name('.symtab')
        for item in objects:
            symbol,=symbols.get_symbol_by_name(item['native_symbol'])
            if symbol['st_size']!=item['size']:raise ValueError('native/proof readonly extent mismatch')
            section=proof.get_section(symbol['st_shndx'])
            data=section.data()[symbol['st_value']:symbol['st_value']+symbol['st_size']]
            if data!=values[item['native_symbol']]:raise ValueError('native/proof readonly bytes mismatch')
    for field in ('native_object','simulator_object'):
        source=Path(entry[field])
        if not source.is_file(): raise FileNotFoundError(source)
        shutil.copy2(source,app/source.name)
        entry[field]='/opt/bpf-benchmark/native-bpf/x86_64/bcc/'+source.name
probe_manifest=json.loads((HERE/'object-startup-published/manifest.json').read_text())
for probe in probe_manifest['objects']:
    if probe['program']=='runtime_source':continue
    native_source=Path(probe['native_object'])
    for field in ('native_object','simulator_object'):
        source=Path(probe[field]);target=app/('startup-'+source.parent.name+'-'+source.name)
        shutil.copy2(source,target);probe[field]='/opt/bpf-benchmark/native-bpf/x86_64/bcc/'+target.name
    native_name=Path(probe['native_object']).name.removesuffix('.native.o')
    source_proof=native_source.parent/(probe['symbol']+'.proof.o')
    shutil.copy2(source_proof,app/(native_name+'.'+probe['symbol']+'.proof.o'))
    manifest['objects'].append(probe)
(app/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
for source,name in [(HERE/'strict-runtime-input/libbpfrejit_shim.so','libbpfrejit_shim.so'),
                    (HERE.parents[2]/'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link','native-link'),
                    (HERE/'strict-runtime-input/libnative_loader.so','libnative_loader.so')]:
    shutil.copy2(source,out/name)
shutil.copy2(phase/'load-pairing.json',out/'load-pairing.json')
print(f'packaged all {len(rows)} BCC resident entries; probes/transient coverage remains in startup records')
