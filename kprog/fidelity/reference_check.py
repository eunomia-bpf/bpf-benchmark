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


def state(data):
    words=struct.unpack(f'<{(len(data)-64)//8}Q64s',data)
    return dict(registers=list(words[:32]),flags=words[32],vector=list(words[33:-1]),stack=words[-1].hex())


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
    # Only a serialization optimization: every non-composite encoding is
    # probed against the reference, including opcodes absent from this set.
    arm_without_memory = {
        'ARM64_OP_MUL','ARM64_OP_MADD','ARM64_OP_MSUB','ARM64_OP_UDIV','ARM64_OP_UMULH','ARM64_OP_UMULL','ARM64_OP_UMADDL','ARM64_OP_SMADDL',
        'ARM64_OP_CSEL','ARM64_OP_CSINC','ARM64_OP_CSINV','ARM64_OP_CSNEG','ARM64_OP_CINC','ARM64_OP_CINV','ARM64_OP_CNEG','ARM64_OP_CSET','ARM64_OP_CSETM',
        'ARM64_OP_EXTR','ARM64_OP_REV','ARM64_OP_REV16','ARM64_OP_SXTB','ARM64_OP_SXTH','ARM64_OP_SXTW',
    }
    rows=[];bad=0;checked=0
    with trace.open('rb') as source,(args.out/'reference-mismatches.jsonl').open('w') as failures,(args.out/'reference-unavailable.jsonl').open('w') as unavailable:
        magic=source.read(8)
        size,memory,count,cases=struct.unpack('<4I',source.read(16))
        if magic!=b'KPFID002' or size not in {344,840} or (args.arch=='x86' and size!=344) or memory!=256 or count!=len(forms) or cases!=args.cases:
            raise RuntimeError('trace layout/header mismatch')
        record_bytes=16+3*size+3*256
        if trace.stat().st_size!=24+count*cases*record_bytes:
            raise RuntimeError('incomplete CPU state trace')
        for index,form in enumerate(forms):
            if args.arch=='x86' and form['opcode'] in {'X86_OP_JCC','X86_OP_JMP','X86_OP_CALL'}:
                source.seek(cases*record_bytes,1)
                reason='control composite requires a reference block-step interface'
                rows.append(dict(form=index,assembly=form['assembly'],cases=cases,reference_cases=0,cpu_mismatches=0,simulator_mismatches=0,status='awaiting_reference_block',reference_error=reason))
                unavailable.write(json.dumps(dict(form=index,assembly=form['assembly'],error=reason))+'\n')
                continue
            requests=[];records=[];rejection=None
            omit_memory=args.arch=='arm64' and form['opcode'] in arm_without_memory
            assembly=form['assembly']
            for case in range(cases):
                ident=struct.unpack('<2I',source.read(8))
                if ident!=(index,case):raise RuntimeError('trace record order mismatch')
                stack_base=struct.unpack('<Q',source.read(8))[0]
                initial,native,simulator=[state(source.read(size)) for _ in range(3)]
                before,native_mem,sim_mem=[source.read(256) for _ in range(3)]
                address=initial['registers'][7 if args.arch=='x86' else 4]-32
                cells=[dict(address=address+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(before)]
                if args.arch=='x86':
                    cells += [dict(address=stack_base-64+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(bytes.fromhex(initial['stack']))]
                    registers=initial['registers'][:16].copy()
                    registers[4]=(registers[4]+stack_base)&((1<<64)-1)
                    architectural_state=dict(registers=registers,flags=initial['flags'],pc=native_code['forms'][index]['pc'],xmm0=initial['vector'][0]+(initial['vector'][1]<<64),fs_base=native_code['fs_base'],gs_base=native_code['gs_base'],memory=cells)
                else:
                    registers=initial['registers'].copy()
                    registers[31]=(registers[31]+stack_base)&((1<<64)-1)
                    if stack_base:
                        cells += [dict(address=stack_base-64+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(bytes.fromhex(initial['stack']))]
                    # The admitted Arm multiply/select forms have no memory operands.
                    # Unexpected memory events/faults fail below; raw CPU memory is
                    # still compared in full, without serializing irrelevant cells.
                    if omit_memory: cells=[]
                    architectural_state=dict(registers=registers,flags=initial['flags'],pc=native_code['forms'][index]['pc'],vector0=initial['vector'][0]+(initial['vector'][1]<<64),memory=cells)
                    if size==840:
                        architectural_state['vectors']=[initial['vector'][2*i]+(initial['vector'][2*i+1]<<64) for i in range(32)]
                request=dict(isa='x86_64' if args.arch=='x86' else 'aarch64',state=architectural_state,native_bytes=native_code['forms'][index]['native_bytes'])
                encoded_request=json.dumps(request,separators=(',',':'))
                if case==0:
                    probe=subprocess.run([str(reference)],input=encoded_request+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
                    if probe.returncode:
                        rejection=probe.stderr.strip()
                        if not rejection:raise RuntimeError('reference failed without a diagnostic')
                        unavailable.write(json.dumps(dict(form=index,assembly=assembly,error=rejection,returncode=probe.returncode,request=request))+'\n')
                        source.seek((cases-1)*record_bytes,1)
                        break
                requests.append(encoded_request)
                records.append((initial,native,simulator,before,native_mem,sim_mem,cells,stack_base))
            if rejection is not None:
                rows.append(dict(form=index,assembly=assembly,cases=cases,reference_cases=0,cpu_mismatches=0,simulator_mismatches=0,status='reference_rejected_encoding',reference_error=rejection))
                continue
            completed=subprocess.run([str(reference)],input='\n'.join(requests)+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True)
            responses=[json.loads(line) for line in completed.stdout.splitlines()]
            if len(responses)!=cases:raise RuntimeError('incomplete reference responses')
            cpu_bad=0;sim_bad=0
            for case,(record,response) in enumerate(zip(records,responses)):
                initial,native,simulator,before,native_mem,sim_mem,cells,stack_base=record
                registers=response['registers'].copy()
                if args.arch=='x86': registers[4]=(registers[4]-stack_base)&((1<<64)-1)
                else: registers[31]=(registers[31]-stack_base)&((1<<64)-1)
                vector_word=response['xmm0' if args.arch=='x86' else 'vector0']
                vector=[vector_word&((1<<64)-1),vector_word>>64]
                if size==840:
                    vector=[half for word in response['vectors'] for half in [word&((1<<64)-1),word>>64]]
                expected_bytes={cell['address']:cell['value'] for cell in response['memory']}
                address=initial['registers'][7 if args.arch=='x86' else 4]-32
                expected_memory=bytes(expected_bytes[address+i] for i in range(256)) if not omit_memory else before
                expected_stack=bytes(expected_bytes[stack_base-64+i] for i in range(64)).hex() if args.arch=='x86' or (stack_base and not omit_memory) else initial['stack']
                reg_count=16 if args.arch=='x86' else 32
                flag_mask=0x8c1 if args.arch=='x86' else 0xf0000000
                def differs(actual,actual_mem):
                    return (response['fault'] is not None or (omit_memory and (response['events'] or response['memory'])) or response['pc']!=native_code['forms'][index]['next_pc'] or actual['registers'][:reg_count]!=registers or ((actual['flags']^response['flags'])&response['defined_flags']&flag_mask)!=0 or actual['vector']!=vector or actual['stack']!=expected_stack or actual_mem!=expected_memory)
                c=differs(native,native_mem);s=differs(simulator,sim_mem)
                cpu_bad+=c;sim_bad+=s
                if c or s:
                    failures.write(json.dumps(dict(form=index,assembly=assembly,case=case,input=initial,native=native,simulator=simulator,memory_input=before.hex(),memory_native=native_mem.hex(),memory_simulator=sim_mem.hex(),reference=response,native_stack_base=stack_base))+'\n')
            checked+=cases;bad+=cpu_bad+sim_bad
            rows.append(dict(form=index,assembly=assembly,cases=cases,reference_cases=cases,cpu_mismatches=cpu_bad,simulator_mismatches=sim_bad,status='checked',reference_error='none'))
    with (args.out/'reference-forms.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(rows[0]),delimiter='\t',lineterminator='\n');writer.writeheader();writer.writerows(rows)
    awaiting=sum(row['reference_cases']==0 for row in rows)
    print(f'reference checked_cases={checked} mismatches={bad} forms_awaiting_reference={awaiting}')
    return int(cpu_failed or bad!=0 or awaiting!=0)


if __name__=='__main__':
    raise SystemExit(main())
