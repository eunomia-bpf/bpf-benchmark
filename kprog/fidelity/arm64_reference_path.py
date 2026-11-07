#!/usr/bin/env python3
"""Sequence V's four-byte canonical step on actual ARM control-observer bytes.

No instruction or condition is interpreted here: each successor PC comes
from the canonical response. These finite, acyclic observers stop at their
recorded outer boundary; the runner does not change simulated execution.
"""
import argparse
import csv
import json
from pathlib import Path
import struct
import subprocess
from reference_check import state


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, required=True)
    parser.add_argument('--reference', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--cases', type=int, default=1024)
    a = parser.parse_args()
    forms = json.loads((a.binary.parent/'coverage.json').read_text())
    metadata = json.loads((a.out/'native-code.json').read_text())['forms']
    trace = a.out/'cpu-states.bin'
    rows = []
    with trace.open('rb') as source, (a.out/'reference-mismatches.jsonl').open('w') as failures:
        magic = source.read(8)
        size, memory, count, cases = struct.unpack('<4I', source.read(16))
        if magic != b'KPFID002' or size != 344 or memory != 256 or count != len(forms) or cases != a.cases:
            raise ValueError('control trace layout mismatch')
        if trace.stat().st_size != 24+count*cases*(16+3*size+3*memory):
            raise ValueError('incomplete control trace')
        for index, form in enumerate(forms):
            code = metadata[index]; base = code['pc']; end = code['next_pc']; native_bytes = code['native_bytes']
            if len(native_bytes) != end-base or len(native_bytes) % 4:
                raise ValueError('control extent is not whole AArch64 words')
            records = []; current = []; paths = [[] for _ in range(cases)]
            for case in range(cases):
                if struct.unpack('<2I', source.read(8)) != (index, case):
                    raise ValueError('control trace order mismatch')
                stack_base = struct.unpack('<Q', source.read(8))[0]
                initial, native, sim = [state(source.read(size)) for _ in range(3)]
                before, native_mem, sim_mem = [source.read(memory) for _ in range(3)]
                regs = initial['registers'].copy(); regs[31] = (regs[31]+stack_base) % (1<<64)
                cells = [dict(address=stack_base-64+i, value=value, readable=True, writable=True, initialized=True)
                         for i, value in enumerate(bytes.fromhex(initial['stack']))]
                current.append(dict(registers=regs, flags=initial['flags'], pc=base,
                    vector0=initial['vector'][0]+(initial['vector'][1]<<64), memory=cells))
                records.append((initial, native, sim, before, native_mem, sim_mem, stack_base))
            active = list(range(cases)); results = [None]*cases; events = [[] for _ in range(cases)]
            while active:
                requests = []
                for case in active:
                    pc = current[case]['pc']; offset = pc-base
                    if offset < 0 or offset+4 > len(native_bytes) or offset % 4:
                        raise ValueError(f'{form["assembly"]}: canonical PC outside actual observer: {pc:#x}')
                    if pc in paths[case]:
                        raise ValueError('finite acyclic control observer revisited an instruction')
                    paths[case].append(pc)
                    requests.append(json.dumps(dict(isa='aarch64', state=current[case],
                        native_bytes=native_bytes[offset:offset+4]), separators=(',', ':')))
                done = subprocess.run([str(a.reference.resolve())], input='\n'.join(requests)+'\n',
                    text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                if done.returncode:
                    (a.out/'reference-error.json').write_text(json.dumps(dict(form=index,
                        assembly=form['assembly'], stderr=done.stderr, first_request=json.loads(requests[0])),indent=2)+'\n')
                    raise RuntimeError('canonical single-step failed: '+done.stderr)
                answers = [json.loads(line) for line in done.stdout.splitlines()]
                if len(answers) != len(active):
                    raise ValueError('incomplete canonical responses')
                remaining = []
                for case, answer in zip(active, answers):
                    events[case] += answer['events']
                    current[case] = {key:answer[key] for key in ['registers','flags','pc','vector0','memory']}
                    results[case] = answer
                    if answer['fault'] is None and answer['pc'] != end:
                        remaining.append(case)
                active = remaining
            cpu_bad = sim_bad = 0
            for case, (record, answer) in enumerate(zip(records, results)):
                initial, native, sim, before, native_mem, sim_mem, stack_base = record
                expected = answer['registers'].copy(); expected[31] = (expected[31]-stack_base) % (1<<64)
                vector = [answer['vector0'] & ((1<<64)-1), answer['vector0'] >> 64]
                cells = {cell['address']:cell for cell in answer['memory']}
                if set(cells) != set(range(stack_base-64, stack_base)):
                    raise ValueError('canonical memory-cell identities changed')
                if any(not (cell['readable'] and cell['writable'] and cell['initialized']) for cell in cells.values()):
                    raise ValueError('canonical stack permissions/initialization changed')
                stack = bytes(cells[stack_base-64+i]['value'] for i in range(64)).hex()
                def differs(actual, actual_memory):
                    return (answer['fault'] is not None or answer['pc'] != end or actual['registers'] != expected or
                        (actual['flags'] ^ answer['flags']) & 0xf0000000 != 0 or actual['vector'] != vector or
                        actual['stack'] != stack or actual_memory != before)
                cb = differs(native, native_mem); sb = differs(sim, sim_mem)
                cpu_bad += cb; sim_bad += sb
                if cb or sb:
                    failures.write(json.dumps(dict(form=index, assembly=form['assembly'], case=case,
                        input=initial, native=native, simulator=sim, native_stack_base=stack_base,
                        memory_input=before.hex(), memory_native=native_mem.hex(), memory_simulator=sim_mem.hex(),
                        reference=answer, reference_events=events[case], reference_path=paths[case]))+'\n')
            rows.append(dict(form=index, assembly=form['assembly'], cases=cases, reference_cases=cases,
                cpu_mismatches=cpu_bad, simulator_mismatches=sim_bad,
                min_steps=min(map(len,paths)), max_steps=max(map(len,paths))))
            with (a.out/'reference-forms.tsv').open('w') as output:
                writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n')
                writer.writeheader();writer.writerows(rows)
            print(f'{index}: {form["assembly"]}: cases={cases} CPU={cpu_bad} C={sim_bad}',flush=True)
        if source.read(1):
            raise ValueError('trailing trace records')
    print(f'ARM canonical control: forms={len(rows)} cases={len(rows)*cases} CPU={sum(r["cpu_mismatches"] for r in rows)} C={sum(r["simulator_mismatches"] for r in rows)}')
    return int(any(r['cpu_mismatches'] or r['simulator_mismatches'] for r in rows))


if __name__ == '__main__':
    raise SystemExit(main())
