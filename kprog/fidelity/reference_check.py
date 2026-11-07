#!/usr/bin/env python3
"""Feed hardware/simulator states to lane V's executable reference; no ISA execution here."""
import argparse
import csv
import json
from pathlib import Path
import platform
import re
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]


def control_extents(binary, metadata, forms, linear_paths=False):
    """Read extents only; canonical decode checks every byte and successor."""
    text=subprocess.check_output(['objdump','-d','-Mintel','--insn-width=16',str(binary)],text=True)
    extents={}
    for line in text.splitlines():
        match=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2} )+)',line)
        if match:
            extents[int(match[1],16)]=len(match[2].split())
    result={}
    for index,form in enumerate(forms):
        if form['opcode'] not in {'X86_OP_JCC','X86_OP_JMP','X86_OP_CALL'} and not (linear_paths and form['opcode']=='X86_STACK_COMPOSITE'):
            continue
        code=metadata['forms'][index]
        pc=code['pc'];entries=[]
        while pc<code['next_pc']:
            length=extents[pc]
            if pc+length>code['next_pc']:
                raise RuntimeError('control instruction crosses observed byte span')
            entries.append(dict(offset=pc-code['pc'],length=length))
            pc+=length
        expected=form['native_instructions'] if form['opcode']=='X86_STACK_COMPOSITE' else 4 if form['opcode']=='X86_OP_CALL' else 5 if form['assembly'].endswith('backward') else 4 if form['opcode']=='X86_OP_JCC' else 3
        if len(entries)!=expected:
            raise RuntimeError('unexpected generated control observer shape')
        result[index]=entries
    return result


def control_witness(form, extents, native):
    """The CPU's final 0/1 selects the generated observer's taken path.
    No flags/condition are interpreted here. Canonical execution must validate
    the entire selected witness and end at the actual observed final PC.
    """
    if form['opcode']=='X86_OP_CALL':
        # Generated observer order: CALL, callee load, RET, caller JMP.
        return [extents[index] for index in [0,2,3,1]]
    if native['registers'][0] not in {0,1}:
        raise RuntimeError('control observer did not produce a 0/1 outcome')
    if form['opcode']=='X86_OP_JMP':
        indices=[0,2]
    elif form['assembly'].endswith('backward'):
        indices=[0,3,4]+([1,2] if native['registers'][0] else [])
    else:
        indices=[0]+([3] if native['registers'][0] else [1,2])
    return [extents[index] for index in indices]


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
    parser.add_argument('--trace',type=Path)
    parser.add_argument('--reference',type=Path,default=ROOT/'kprog/formal/.lake/build/bin/reference')
    parser.add_argument('--control-paths',action='store_true',help='use the canonical finite-path interface for generated Jcc/JMP/CALL observers')
    parser.add_argument('--linear-paths',action='store_true',help='use canonical finite paths for complete acyclic straight-line stack observers')
    parser.add_argument('--opcode',action='append',help='replay only this production opcode from the saved trace; repeat for multiple families')
    args=parser.parse_args()
    if args.trace and not args.reuse_trace:
        parser.error('--trace requires --reuse-trace')
    args.out.mkdir(parents=True,exist_ok=True)
    forms=json.loads((args.binary.parent/'coverage.json').read_text())
    if args.opcode and (not args.reuse_trace or set(args.opcode)-{form['opcode'] for form in forms}):
        parser.error('--opcode requires --reuse-trace and opcodes present in the saved form matrix')
    trace=args.trace if args.trace else args.out/'cpu-states.bin'
    if args.reuse_trace:
        with (args.out/'forms.tsv').open() as source:
            cpu_failed=any(int(row['mismatches']) for row in csv.DictReader(source,delimiter='\t') if not args.opcode or row['opcode'] in args.opcode)
    else:
        command=(['qemu-aarch64-static'] if args.arch=='arm64' and platform.machine()!='aarch64' else [])
        cpu_failed=subprocess.run(command+[str(args.binary.resolve()),str(args.cases),str(args.out),str(trace)]).returncode != 0
    native_code=json.loads((args.out/'native-code.json').read_text())
    paths=control_extents(args.binary,native_code,forms,args.linear_paths) if (args.control_paths or args.linear_paths) and args.arch=='x86' else {}
    reference=args.reference
    # Only a serialization optimization: every non-composite encoding is
    # probed against the reference, including opcodes absent from this set.
    arm_without_memory = {
        'ARM64_OP_BITFIELD','ARM64_OP_FMOV',
        'ARM64_OP_SHIFT_IMM','ARM64_OP_SHIFT_REG',
        'ARM64_OP_ADDS_IMM','ARM64_OP_ADDS_REG','ARM64_OP_ALU_IMM','ARM64_OP_ALU_REG',
        'ARM64_OP_ANDS_REG','ARM64_OP_BICS_REG','ARM64_OP_CCMP_IMM','ARM64_OP_CCMP_REG',
        'ARM64_OP_CMN_REG','ARM64_OP_CMP_REG','ARM64_OP_CNT','ARM64_OP_MOVK',
        'ARM64_OP_MOV_IMM','ARM64_OP_MOV_REG','ARM64_OP_MVN','ARM64_OP_NEG','ARM64_OP_NOP',
        'ARM64_OP_ORN_REG','ARM64_OP_SUBS_IMM','ARM64_OP_SUBS_REG','ARM64_OP_TST_REG','ARM64_OP_UADDLV',
        'ARM64_OP_MUL','ARM64_OP_MADD','ARM64_OP_MSUB','ARM64_OP_UDIV','ARM64_OP_UMULH','ARM64_OP_UMULL','ARM64_OP_UMADDL','ARM64_OP_SMADDL',
        'ARM64_OP_CSEL','ARM64_OP_CSINC','ARM64_OP_CSINV','ARM64_OP_CSNEG','ARM64_OP_CINC','ARM64_OP_CINV','ARM64_OP_CNEG','ARM64_OP_CSET','ARM64_OP_CSETM',
        'ARM64_OP_EXTR','ARM64_OP_REV','ARM64_OP_REV16','ARM64_OP_SXTB','ARM64_OP_SXTH','ARM64_OP_SXTW',
    }
    x86_without_memory = {
        'X86_OP_ALU_IMM','X86_OP_ALU_REG','X86_OP_ANDN','X86_OP_BSWAP',
        'X86_OP_BT','X86_OP_BT_IMM','X86_OP_BZHI','X86_OP_CMOV','X86_OP_CMP_IMM',
        'X86_OP_CMP_REG','X86_OP_DIV','X86_OP_IMUL_IMM','X86_OP_MOVSX_REG',
        'X86_OP_MOVZX_REG','X86_OP_MOV_IMM','X86_OP_MOV_REG','X86_OP_MULX',
        'X86_OP_NOP','X86_OP_POPCNT','X86_OP_ROR','X86_OP_RORX','X86_OP_SETCC','X86_OP_SHIFTX',
        'X86_OP_SHLD_IMM','X86_OP_SHRD_IMM','X86_OP_TEST_IMM','X86_OP_TEST_REG','X86_OP_XCHG',
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
            if args.opcode and form['opcode'] not in args.opcode:
                source.seek(cases*record_bytes,1)
                continue
            if args.arch=='x86' and form['opcode'] in {'X86_OP_JCC','X86_OP_JMP','X86_OP_CALL'} and index not in paths:
                source.seek(cases*record_bytes,1)
                reason='control composite requires a reference block-step interface'
                rows.append(dict(form=index,assembly=form['assembly'],cases=cases,reference_cases=0,cpu_mismatches=0,simulator_mismatches=0,status='awaiting_reference_block',reference_error=reason))
                unavailable.write(json.dumps(dict(form=index,assembly=form['assembly'],error=reason))+'\n')
                continue
            requests=[];records=[];rejection=None
            omit_memory=(args.arch=='arm64' and form['opcode'] in arm_without_memory) or (
                args.arch=='x86' and ((form['opcode'] in x86_without_memory and '[' not in form['assembly']) or form['opcode']=='X86_OP_LEA')) or (index in paths and form['opcode'] not in {'X86_STACK_COMPOSITE','X86_OP_CALL'})
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
                    architectural_state=dict(registers=registers,flags=initial['flags'],pc=native_code['forms'][index]['pc'],vector0=initial['vector'][0]+(initial['vector'][1]<<64),memory=cells)
                    if size==840:
                        architectural_state['vectors']=[initial['vector'][2*i]+(initial['vector'][2*i+1]<<64) for i in range(32)]
                if omit_memory:
                    architectural_state['memory']=[]
                request=dict(isa='x86_64' if args.arch=='x86' else 'aarch64',state=architectural_state,native_bytes=native_code['forms'][index]['native_bytes'])
                if index in paths:
                    request.update(native_base=native_code['forms'][index]['pc'],
                        native_path=paths[index] if form['opcode']=='X86_STACK_COMPOSITE' else control_witness(form,paths[index],native))
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
                expected_stack=bytes(expected_bytes[stack_base-64+i] for i in range(64)).hex() if not omit_memory and (args.arch=='x86' or stack_base) else initial['stack']
                reg_count=16 if args.arch=='x86' else 32
                # Compare all six arithmetic flags, including PF/AF. Older
                # simulator traces contain only four; a newly defined missing
                # output bit is a model difference, never an undefined waiver.
                flag_mask=0x8d5 if args.arch=='x86' else 0xf0000000
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
