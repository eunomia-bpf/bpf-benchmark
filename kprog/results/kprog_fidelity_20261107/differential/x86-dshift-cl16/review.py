#!/usr/bin/env python3
"""Collect source identity and per-form observations for CL double shifts."""
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

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
BUILD = ROOT / 'kprog/fidelity/build-x86-dshift-cl16'

def sha(data):
    return hashlib.sha256(data).hexdigest()

def main():
    status = json.loads((OUT / 'status.json').read_text())
    assert status['exit'] == 0 and status['source_drift'] == {}, status
    launch = json.loads((OUT / 'launch.json').read_text())
    manifest = json.loads((OUT / 'actual-compiled-inputs.json').read_text())
    with tarfile.open(OUT / 'actual-compiled-inputs.tar.gz') as source:
        members = {m.name: m for m in source.getmembers() if m.isfile()}
        assert set(members) == set(manifest)
        for name, digest in manifest.items():
            assert sha(source.extractfile(members[name]).read()) == digest, name
    snapshots = {}
    prefix = 'kprog/fidelity/build-x86-dshift-cl16/snapshot/'
    for name, digest in manifest.items():
        if name.startswith(prefix):
            original = name[len(prefix):]
            published = subprocess.check_output(['git', 'show', launch['source_head'] + ':' + original], cwd=ROOT)
            assert sha(published) == digest, original
            snapshots[original] = digest
    bindings = json.loads((BUILD / 'numeric-bindings.json').read_text())
    forms = json.loads((OUT / 'coverage.json').read_text())
    native = json.loads((OUT / 'native-code.json').read_text())['forms']
    assert len(bindings) == len(forms) == len(native) == 32
    encoder_path = ROOT / 'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
    assert sha(encoder_path.read_bytes()) == launch['source_sha256'][str(encoder_path.relative_to(ROOT))]
    sys.path.insert(0, str(encoder_path.parent))
    spec = importlib.util.spec_from_file_location('fidelity_encoder', encoder_path)
    encoder = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = encoder
    spec.loader.exec_module(encoder)
    instructions = encoder.parse_asm_text((BUILD / 'instructions.asm').read_text())
    assert len(instructions) == 16
    for i, instruction in enumerate(instructions):
        actual = asdict(encoder.encode(instruction, {}))
        assert bindings[2*i]['encoded'] == bindings[2*i+1]['encoded'] == actual
        assert native[2*i]['native_bytes'] == native[2*i+1]['native_bytes']
        assert [forms[2*i]['route'], forms[2*i+1]['route']] == ['raw', 'direct']
    with (OUT / 'forms.tsv').open() as source:
        cpu = list(csv.DictReader(source, delimiter='\t'))
    with (OUT / 'reference-forms.tsv').open() as source:
        reference = list(csv.DictReader(source, delimiter='\t'))
    assert len(cpu) == len(reference) == 32
    rows = []
    trace = OUT / 'cpu-states.bin'
    with trace.open('rb') as source:
        assert source.read(8) == b'KPFID002'
        size, memory, count, cases = struct.unpack('<4I', source.read(16))
        assert (size, memory, count, cases) == (344, 256, 32, 1024)
        for i, (form, observed, replay) in enumerate(zip(forms, cpu, reference)):
            assert int(observed['cases']) == int(replay['reference_cases']) == cases
            assert int(observed['mismatches']) == int(replay['cpu_mismatches']) == int(replay['simulator_mismatches']) == 0
            assert replay['status'] == 'checked'
            counts = {}
            unchanged_memory = 0
            bits = 16
            for j in range(cases):
                assert struct.unpack('<2I', source.read(8)) == (i, j)
                source.read(8)
                states = [source.read(size) for k in range(3)]
                assert all(len(state) == size for state in states)
                cl = struct.unpack_from('<Q', states[0], 8)[0] & 0xff
                effective = cl & 31
                counts[effective] = counts.get(effective, 0) + 1
                before, host, sim = [source.read(memory) for k in range(3)]
                unchanged_memory += before == host == sim
            assert set(counts) == set(range(17)), (form, counts)
            assert unchanged_memory == cases
            rows.append(dict(form=i, assembly=form['assembly'], route=form['route'],
                             opcode=form['opcode'], width=bits, cases=cases,
                             cpu_simulator_mismatches=int(observed['mismatches']),
                             cpu_reference_mismatches=int(replay['cpu_mismatches']),
                             simulator_reference_mismatches=int(replay['simulator_mismatches']),
                             observed_effective_counts=len(counts), count_zero=counts[0],
                             count_one=counts[1], unchanged_memory_cases=unchanged_memory,
                             count_histogram=json.dumps(counts, sort_keys=True, separators=(',', ':'))))
        assert source.read(1) == b''
    with (OUT / 'observations.tsv').open('w') as output:
        writer = csv.DictWriter(output, fieldnames=list(rows[0]), delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    summary = dict(forms=len(rows), native_forms=len(instructions), cases=sum(row['cases'] for row in rows),
                   differences=dict(cpu_simulator=0, cpu_reference=0, simulator_reference=0),
                   forms_awaiting_reference=0, all_effective_counts_observed=True,
                   count_zero=sum(row['count_zero'] for row in rows),
                   count_one=sum(row['count_one'] for row in rows),
                   unchanged_memory_cases=sum(row['unchanged_memory_cases'] for row in rows),
                   compiled_input_files=len(manifest), production_snapshot_files=len(snapshots),
                   production_snapshot_git_equal=True, encoded_fields_preserved=True,
                   input_sampling=json.loads((BUILD / 'selection-review.json').read_text())['input_sampling'],
                   raw_direct_native_byte_pairs=16, source_head=launch['source_head'],
                   reference_sha256=launch['reference_sha256'],
                   binary_sha256=sha((BUILD / 'cpu-differential').read_bytes()),
                   trace_bytes=trace.stat().st_size, trace_sha256=sha(trace.read_bytes()),
                   finished=status['finished'], source_drift=status['source_drift'])
    (OUT / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary, indent=2))

if __name__ == '__main__':
    main()
