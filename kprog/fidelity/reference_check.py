#!/usr/bin/env python3
"""Feed hardware/simulator states to lane V's executable reference; no ISA execution here."""
import argparse
import csv
import json
from pathlib import Path
import platform
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]
STATE=struct.Struct('<35Q64s')
RECORD_BYTES=16+3*STATE.size+3*256


def state(data):
    words=STATE.unpack(data)
    return dict(registers=list(words[:32]),flags=words[32],vector=list(words[33:35]),stack=words[35].hex())


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--binary',type=Path,required=True)
    parser.add_argument('--arch',choices=['x86','arm64'],required=True)
    parser.add_argument('--cases',type=int,required=True)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--reuse-trace',action='store_true')
    args=parser.parse_args()
    args.out.mkdir(parents=True,exist_ok=True)
    forms=json.loads((args.binary.parent/'coverage.json').read_text())
    trace=args.out/'cpu-states.bin'
    if args.reuse_trace:
        with (args.out/'forms.tsv').open() as source:
            cpu_failed=any(int(row['mismatches']) for row in csv.DictReader(source,delimiter='\t'))
    else:
        command=(['qemu-aarch64-static'] if args.arch=='arm64' and platform.machine()!='aarch64' else [])
        cpu_failed=subprocess.run(command+[str(args.binary.resolve()),str(args.cases),str(args.out),str(trace)]).returncode != 0
    native_code=json.loads((args.out/'native-code.json').read_text())
    reference=ROOT/'kprog/formal/.lake/build/bin/reference'
    supported = {
        'x86': {'X86_OP_CMOV','X86_OP_CMOV_MEM','X86_OP_BT','X86_OP_BT_IMM','X86_OP_BT_MEM_IMM','X86_OP_BZHI','X86_OP_BZHI_MEM','X86_OP_POP','X86_OP_PUSH','X86_OP_ANDN','X86_OP_ANDN_MEM'},
        'arm64': {'ARM64_OP_MUL','ARM64_OP_MADD','ARM64_OP_MSUB','ARM64_OP_UDIV','ARM64_OP_UMULH','ARM64_OP_UMULL','ARM64_OP_UMADDL','ARM64_OP_SMADDL'},
    }
    rows=[];bad=0;checked=0
    with trace.open('rb') as source,(args.out/'reference-mismatches.jsonl').open('w') as failures:
        magic=source.read(8)
        size,memory,count,cases=struct.unpack('<4I',source.read(16))
        if magic!=b'KPFID002' or size!=STATE.size or memory!=256 or count!=len(forms) or cases!=args.cases:
            raise RuntimeError('trace layout/header mismatch')
        if trace.stat().st_size!=24+count*cases*RECORD_BYTES:
            raise RuntimeError('incomplete CPU state trace')
        for index,form in enumerate(forms):
            if form['opcode'] not in supported[args.arch]:
                source.seek(cases*RECORD_BYTES,1)
                rows.append(dict(form=index,assembly=form['assembly'],cases=cases,reference_cases=0,cpu_mismatches=0,simulator_mismatches=0,status='awaiting_reference_instruction'))
                continue
            requests=[];records=[]
            assembly=form['assembly']
            for case in range(cases):
                ident=struct.unpack('<2I',source.read(8))
                if ident!=(index,case):raise RuntimeError('trace record order mismatch')
                stack_base=struct.unpack('<Q',source.read(8))[0]
                initial,native,simulator=[state(source.read(STATE.size)) for _ in range(3)]
                before,native_mem,sim_mem=[source.read(256) for _ in range(3)]
                address=initial['registers'][7 if args.arch=='x86' else 4]-32
                cells=[dict(address=address+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(before)]
                if args.arch=='x86':
                    cells += [dict(address=stack_base-64+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(bytes.fromhex(initial['stack']))]
                    registers=initial['registers'][:16].copy()
                    registers[4]=(registers[4]+stack_base)&((1<<64)-1)
                    architectural_state=dict(registers=registers,flags=initial['flags'],pc=native_code['forms'][index]['pc'],xmm0=initial['vector'][0]+(initial['vector'][1]<<64),fs_base=native_code['fs_base'],gs_base=native_code['gs_base'],memory=cells)
                else:
                    architectural_state=dict(registers=initial['registers'],flags=initial['flags'],pc=native_code['forms'][index]['pc'],vector0=initial['vector'][0]+(initial['vector'][1]<<64),memory=cells)
                request=dict(isa='x86_64' if args.arch=='x86' else 'aarch64',state=architectural_state,native_bytes=native_code['forms'][index]['native_bytes'])
                requests.append(json.dumps(request,separators=(',',':')))
                records.append((initial,native,simulator,before,native_mem,sim_mem,cells,stack_base))
            completed=subprocess.run([str(reference)],input='\n'.join(requests)+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True)
            responses=[json.loads(line) for line in completed.stdout.splitlines()]
            if len(responses)!=cases:raise RuntimeError('incomplete reference responses')
            cpu_bad=0;sim_bad=0
            for case,(record,response) in enumerate(zip(records,responses)):
                initial,native,simulator,before,native_mem,sim_mem,cells,stack_base=record
                registers=response['registers'].copy()
                if args.arch=='x86': registers[4]=(registers[4]-stack_base)&((1<<64)-1)
                vector_word=response['xmm0' if args.arch=='x86' else 'vector0']
                vector=[vector_word&((1<<64)-1),vector_word>>64]
                expected_bytes={cell['address']:cell['value'] for cell in response['memory']}
                address=initial['registers'][7 if args.arch=='x86' else 4]-32
                expected_memory=bytes(expected_bytes[address+i] for i in range(256))
                expected_stack=bytes(expected_bytes[stack_base-64+i] for i in range(64)).hex() if args.arch=='x86' else initial['stack']
                reg_count=16 if args.arch=='x86' else 32
                flag_mask=0x8c1 if args.arch=='x86' else 0xf0000000
                def differs(actual,actual_mem):
                    return (response['fault'] is not None or response['pc']!=native_code['forms'][index]['next_pc'] or actual['registers'][:reg_count]!=registers or ((actual['flags']^response['flags'])&response['defined_flags']&flag_mask)!=0 or actual['vector']!=vector or actual['stack']!=expected_stack or actual_mem!=expected_memory)
                c=differs(native,native_mem);s=differs(simulator,sim_mem)
                cpu_bad+=c;sim_bad+=s
                if c or s:
                    failures.write(json.dumps(dict(form=index,assembly=assembly,case=case,input=initial,native=native,simulator=simulator,memory_input=before.hex(),memory_native=native_mem.hex(),memory_simulator=sim_mem.hex(),reference=response,native_stack_base=stack_base))+'\n')
            checked+=cases;bad+=cpu_bad+sim_bad
            rows.append(dict(form=index,assembly=assembly,cases=cases,reference_cases=cases,cpu_mismatches=cpu_bad,simulator_mismatches=sim_bad,status='checked'))
    with (args.out/'reference-forms.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n');writer.writeheader();writer.writerows(rows)
    awaiting=sum(row['reference_cases']==0 for row in rows)
    print(f'reference checked_cases={checked} mismatches={bad} forms_awaiting_reference={awaiting}')
    return int(cpu_failed or bad!=0 or awaiting!=0)


if __name__=='__main__':
    raise SystemExit(main())
