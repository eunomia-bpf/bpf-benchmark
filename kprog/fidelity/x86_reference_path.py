#!/usr/bin/env python3
"""Apply the single canonical x86 step to actual finite-observer instructions.

objdump supplies byte extents only. All successors, faults, events, register
values and memory changes come from V's canonical reference executable.
"""
import argparse
import csv
import json
from pathlib import Path
import re
import struct
import subprocess
from reference_check import state


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,required=True)
    p.add_argument('--reference',type=Path,required=True)
    p.add_argument('--out',type=Path,required=True)
    p.add_argument('--cases',type=int,default=1024)
    a=p.parse_args()
    forms=json.loads((a.binary.parent/'coverage.json').read_text())
    metadata=json.loads((a.out/'native-code.json').read_text())
    dump=subprocess.check_output(['objdump','-d','-Mintel','--insn-width=16',a.binary],text=True)
    extents={}
    for line in dump.splitlines():
        m=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2} )+)',line)
        if m:extents[int(m[1],16)]=len(m[2].split())
    rows=[]
    with (a.out/'cpu-states.bin').open('rb') as source,(a.out/'reference-mismatches.jsonl').open('w') as failures:
        assert source.read(8)==b'KPFID002'
        size,memory,count,cases=struct.unpack('<4I',source.read(16))
        if (size,memory,count,cases)!=(344,256,len(forms),a.cases):raise ValueError('control trace layout mismatch')
        if (a.out/'cpu-states.bin').stat().st_size!=24+count*cases*(16+3*size+3*memory):raise ValueError('incomplete trace')
        for index,form in enumerate(forms):
            code=metadata['forms'][index];base=code['pc'];end=code['next_pc'];native_bytes=code['native_bytes']
            if len(native_bytes)!=end-base:raise ValueError('control byte extent mismatch')
            records=[];current=[];paths=[[] for _ in range(cases)];events=[[] for _ in range(cases)]
            for case in range(cases):
                if struct.unpack('<2I',source.read(8))!=(index,case):raise ValueError('trace record order')
                stack_base=struct.unpack('<Q',source.read(8))[0]
                initial,native,sim=[state(source.read(size)) for _ in range(3)]
                before,native_mem,sim_mem=[source.read(memory) for _ in range(3)]
                registers=initial['registers'][:16].copy();registers[4]=(registers[4]+stack_base)%(1<<64)
                cells=[dict(address=stack_base-64+i,value=value,readable=True,writable=True,initialized=True) for i,value in enumerate(bytes.fromhex(initial['stack']))]
                current.append(dict(registers=registers,flags=initial['flags'],pc=base,xmm0=initial['vector'][0]+(initial['vector'][1]<<64),fs_base=metadata['fs_base'],gs_base=metadata['gs_base'],memory=cells))
                records.append((initial,native,sim,before,native_mem,sim_mem,stack_base))
            active=list(range(cases));results=[None]*cases
            while active:
                requests=[]
                for case in active:
                    pc=current[case]['pc'];offset=pc-base
                    if pc not in extents or offset<0 or offset+extents[pc]>len(native_bytes):raise ValueError('canonical PC outside actual observer')
                    if pc in paths[case]:raise ValueError('finite observer revisited an instruction')
                    paths[case].append(pc)
                    requests.append(json.dumps(dict(isa='x86_64',state=current[case],native_bytes=native_bytes[offset:offset+extents[pc]]),separators=(',',':')))
                done=subprocess.run([str(a.reference.resolve())],input='\n'.join(requests)+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
                if done.returncode:
                    (a.out/'reference-error.json').write_text(json.dumps(dict(form=index,assembly=form['assembly'],stderr=done.stderr,first_request=json.loads(requests[0])),indent=2)+'\n')
                    raise RuntimeError('canonical step failed: '+done.stderr)
                answers=[json.loads(line) for line in done.stdout.splitlines()]
                if len(answers)!=len(active):raise ValueError('incomplete canonical responses')
                remaining=[]
                for case,answer in zip(active,answers):
                    events[case]+=answer['events'];results[case]=answer
                    current[case]={key:answer[key] for key in ['registers','flags','pc','xmm0','memory']}
                    current[case].update(fs_base=metadata['fs_base'],gs_base=metadata['gs_base'])
                    if answer['fault'] is None and answer['pc']!=end:remaining.append(case)
                active=remaining
            cpu_bad=sim_bad=0
            for case,(record,answer) in enumerate(zip(records,results)):
                initial,native,sim,before,native_mem,sim_mem,stack_base=record
                expected=answer['registers'].copy();expected[4]=(expected[4]-stack_base)%(1<<64)
                vector=[answer['xmm0']&((1<<64)-1),answer['xmm0']>>64]
                cells={cell['address']:cell for cell in answer['memory']}
                if set(cells)!=set(range(stack_base-64,stack_base)):raise ValueError('memory identity changed')
                if any(not(cell['readable'] and cell['writable'] and cell['initialized']) for cell in cells.values()):raise ValueError('stack permissions changed')
                stack=bytes(cells[stack_base-64+i]['value'] for i in range(64)).hex()
                def differs(actual,actual_memory):
                    return answer['fault'] is not None or answer['pc']!=end or actual['registers'][:16]!=expected or (actual['flags']^answer['flags'])&0x8d5!=0 or actual['vector']!=vector or actual['stack']!=stack or actual_memory!=before
                cb=differs(native,native_mem);sb=differs(sim,sim_mem);cpu_bad+=cb;sim_bad+=sb
                if cb or sb:failures.write(json.dumps(dict(form=index,assembly=form['assembly'],case=case,input=initial,native=native,simulator=sim,native_stack_base=stack_base,memory_input=before.hex(),memory_native=native_mem.hex(),memory_simulator=sim_mem.hex(),reference=answer,reference_events=events[case],reference_path=paths[case]))+'\n')
            rows.append(dict(form=index,assembly=form['assembly'],cases=cases,reference_cases=cases,cpu_mismatches=cpu_bad,simulator_mismatches=sim_bad,min_steps=min(map(len,paths)),max_steps=max(map(len,paths))))
            with (a.out/'reference-forms.tsv').open('w') as output:
                writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n');writer.writeheader();writer.writerows(rows)
            print(f'{index}: cases={cases} CPU={cpu_bad} C={sim_bad}',flush=True)
        if source.read(1):raise ValueError('trailing trace records')
    return int(any(row['cpu_mismatches'] or row['simulator_mismatches'] for row in rows))


if __name__=='__main__':raise SystemExit(main())
