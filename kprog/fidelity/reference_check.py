#!/usr/bin/env python3
"""Feed hardware/simulator states to lane V's executable reference; no ISA execution here."""
import argparse
import csv
import json
from pathlib import Path
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]
STATE=struct.Struct('<35Q64s')
RECORD_BYTES=8+3*STATE.size+3*256


def state(data):
    words=STATE.unpack(data)
    return dict(registers=list(words[:32]),flags=words[32],vector=list(words[33:35]),stack=words[35].hex())


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--binary',type=Path,required=True)
    parser.add_argument('--arch',choices=['x86','arm64'],required=True)
    parser.add_argument('--cases',type=int,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args()
    if args.arch!='x86':raise RuntimeError("lane V's AArch64 executable interface is required before this adapter can run it")
    args.out.mkdir(parents=True,exist_ok=True)
    forms=json.loads((args.binary.parent/'coverage.json').read_text())
    trace=args.out/'cpu-states.bin'
    cpu=subprocess.run([str(args.binary.resolve()),str(args.cases),str(args.out),str(trace)])
    native_code=json.loads((args.out/'native-code.json').read_text())
    reference=ROOT/'kprog/formal/.lake/build/bin/reference'
    rows=[];bad=0;checked=0
    with trace.open('rb') as source,(args.out/'reference-mismatches.jsonl').open('w') as failures:
        magic=source.read(8)
        size,memory,count,cases=struct.unpack('<4I',source.read(16))
        if magic!=b'KPFID001' or size!=STATE.size or memory!=256 or count!=len(forms) or cases!=args.cases:
            raise RuntimeError('trace layout/header mismatch')
        if trace.stat().st_size!=24+count*cases*RECORD_BYTES:
            raise RuntimeError('incomplete CPU state trace')
        for index,form in enumerate(forms):
            if form['opcode'] not in ['X86_OP_CMOV','X86_OP_CMOV_MEM','X86_OP_BT','X86_OP_BT_IMM','X86_OP_BT_MEM_IMM','X86_OP_BZHI','X86_OP_BZHI_MEM']:
                source.seek(cases*RECORD_BYTES,1)
                rows.append(dict(form=index,assembly=form['assembly'],cases=cases,reference_cases=0,cpu_mismatches=0,simulator_mismatches=0,status='awaiting_reference_instruction'))
                continue
            requests=[];records=[]
            assembly=form['assembly']
            for case in range(cases):
                ident=struct.unpack('<2I',source.read(8))
                if ident!=(index,case):raise RuntimeError('trace record order mismatch')
                initial,native,simulator=[state(source.read(STATE.size)) for _ in range(3)]
                before,native_mem,sim_mem=[source.read(256) for _ in range(3)]
                cells=[]
                if form['opcode'] in ['X86_OP_CMOV_MEM','X86_OP_BT_MEM_IMM','X86_OP_BZHI_MEM']:
                    address=initial['registers'][7]-32
                    cells=[dict(address=address+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(before)]
                request=dict(state=dict(registers=initial['registers'][:16],flags=initial['flags'],pc=native_code['forms'][index]['pc'],xmm0=initial['vector'][0]+(initial['vector'][1]<<64),fs_base=native_code['fs_base'],gs_base=native_code['gs_base'],memory=cells),native_bytes=native_code['forms'][index]['native_bytes'])
                requests.append(json.dumps(request,separators=(',',':')))
                records.append((initial,native,simulator,before,native_mem,sim_mem,cells))
            completed=subprocess.run([str(reference)],input='\n'.join(requests)+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True)
            responses=[json.loads(line) for line in completed.stdout.splitlines()]
            if len(responses)!=cases:raise RuntimeError('incomplete reference responses')
            cpu_bad=0;sim_bad=0
            for case,(record,response) in enumerate(zip(records,responses)):
                initial,native,simulator,before,native_mem,sim_mem,cells=record
                vector=[response['xmm0']&((1<<64)-1),response['xmm0']>>64]
                def differs(actual,actual_mem):
                    return (response['fault'] is not None or response['pc']!=native_code['forms'][index]['next_pc'] or actual['registers'][:16]!=response['registers'] or ((actual['flags']^response['flags'])&response['defined_flags']&0x8c1)!=0 or actual['vector']!=vector or actual['stack']!=initial['stack'] or actual_mem!=before or response['memory']!=cells)
                c=differs(native,native_mem);s=differs(simulator,sim_mem)
                cpu_bad+=c;sim_bad+=s
                if c or s:
                    failures.write(json.dumps(dict(form=index,assembly=assembly,case=case,input=initial,native=native,simulator=simulator,memory_input=before.hex(),memory_native=native_mem.hex(),memory_simulator=sim_mem.hex(),reference=response))+'\n')
            checked+=cases;bad+=cpu_bad+sim_bad
            rows.append(dict(form=index,assembly=assembly,cases=cases,reference_cases=cases,cpu_mismatches=cpu_bad,simulator_mismatches=sim_bad,status='checked'))
    with (args.out/'reference-forms.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n');writer.writeheader();writer.writerows(rows)
    awaiting=sum(row['reference_cases']==0 for row in rows)
    print(f'reference checked_cases={checked} mismatches={bad} forms_awaiting_reference={awaiting}')
    return int(cpu.returncode!=0 or bad!=0 or awaiting!=0)


if __name__=='__main__':
    raise SystemExit(main())
