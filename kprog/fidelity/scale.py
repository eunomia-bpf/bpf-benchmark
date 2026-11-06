#!/usr/bin/env python3
"""Native instruction-count sweep through the production specializer and verifier."""
import argparse
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import types

from tcb import includes

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as encoder


def run(args, log):
    try:
        result=subprocess.run([str(a) for a in args],capture_output=True,text=True,timeout=900)
    except subprocess.TimeoutExpired as error:
        parts=[x.decode(errors='replace') if isinstance(x,bytes) else x or '' for x in [error.stdout,error.stderr]]
        log.write_text('\n'.join(parts)+'\ncommand exceeded 900 seconds\n')
        return 124
    log.write_text(result.stdout+result.stderr)
    return result.returncode


def assembly(size, pointer, indirect):
    lines=['.intel_syntax noprefix','.text','.global entry','.type entry,%function','entry:',
        'mov rsi,QWORD PTR [rdi]','mov rdx,QWORD PTR [rdi+8]','lea rax,[rsi+16]',
        'cmp rax,rdx','ja bad','movzx r9d,BYTE PTR [rsi+8]','mov r8d,7']
    value=7
    blocks=min(8,max(1,size//1000))
    for block in range(blocks):
        for index in range(max(1,size//(2*blocks))):
            if pointer:
                lines += [f'movzx r10d,BYTE PTR [rsi+{8+index%8}]','add r8,r10']
                value=(value+1)&((1<<64)-1)
            else:
                lines += ['imul r8,r8,3','add r8,1']
                value=(value*3+1)&((1<<64)-1)
        if indirect:
            lines += ['test r9b,1',f'jnz choose_{block}',f'lea r10,[rip+target_a_{block}]',
                f'jmp dispatch_{block}',f'choose_{block}:',f'lea r10,[rip+target_b_{block}]',
                f'dispatch_{block}:','jmp r10',f'target_a_{block}:','add r8,1',
                f'jmp join_{block}',f'target_b_{block}:','add r8,2',f'join_{block}:']
            value=(value+2)&((1<<64)-1)
        else:
            lines += ['test r9b,1',f'jz join_{block}','xor r8,1',f'join_{block}:']
            value ^= 1
    lines += ['mov QWORD PTR [rsi],r8','mov eax,2','ret','bad:','xor eax,eax','ret',
              '.size entry,.-entry','.section .note.GNU-stack,"",%progbits']
    return '\n'.join(lines)+'\n',value


def build(directory,sizes):
    directory.mkdir(parents=True,exist_ok=True)
    snapshot=directory/'snapshot'
    saved_encoder=directory/'encoder.py.snapshot'
    global encoder
    if saved_encoder.exists():
        # Resume with the encoder source already paired to this header snapshot.
        frozen=types.ModuleType('fidelity_scale_frozen_encoder')
        frozen.__file__=encoder.__file__
        sys.modules[frozen.__name__]=frozen
        exec(compile(saved_encoder.read_text(),frozen.__file__,'exec'),frozen.__dict__)
        encoder=frozen
    else:
        for path in includes(ROOT/'kprog/x86/x86_sim_local_bpf.h'):
            target=snapshot/path.relative_to(ROOT)
            target.parent.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(path,target)
        shutil.copyfile(ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py',saved_encoder)
    failed=False
    for size in sizes:
        for pointer in [False,True]:
            for indirect in [False,True]:
                name=f'n{size}_{"ptr" if pointer else "scalar"}_{"indirect" if indirect else "direct"}'
                record=directory/f'{name}.json'
                if record.exists():
                    row=json.loads(record.read_text())
                    if row['name']!=name or row['target_native_instructions']!=size:
                        raise RuntimeError('checkpoint does not match requested case: '+str(record))
                    print(f"{name}: recorded {row['stage']} rc={row['returncode']}",flush=True)
                    failed |= row['returncode']!=0
                    continue
                source,expected=assembly(size,pointer,indirect)
                (directory/f'{name}.S').write_text(source)
                row=dict(name=name,target_native_instructions=size,expected_result=expected,stage='native_compile')
                rc=run(['cc','-c',directory/f'{name}.S','-o',directory/f'{name}.native.o'],directory/f'{name}.native.log')
                if not rc:
                    dump=subprocess.run(['objdump','-dr','-Mintel','--insn-width=16',str(directory/f'{name}.native.o')],capture_output=True,text=True,check=True)
                    (directory/f'{name}.asm').write_text(dump.stdout)
                    instructions=encoder.parse_asm_text(dump.stdout)
                    row['native_instructions']=len(instructions)
                    row['stage']='specialization'
                    try:
                        proof=encoder.render_program(name,instructions)
                    except ValueError as error:
                        row['error']=str(error); rc=1
                    else:
                        path=directory/f'{name}.bpf.c'
                        path.write_text(proof.replace('#include "../x86_sim_local_bpf.h"',f'#include "{snapshot}/kprog/x86/x86_sim_local_bpf.h"'))
                        row['stage']='proof_compile'
                        rc=run(['clang','-g','-O2','-target','bpf','-mllvm','-bpf-stack-size=4096',
                            '-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),
                            '-I/usr/include/x86_64-linux-gnu','-c',path,'-o',directory/f'{name}.bpf.o'],directory/f'{name}.compile.log')
                        if not rc:row['stage']='compiled'
                row['returncode']=rc
                record.write_text(json.dumps(row,indent=2)+'\n')
                print(f"{name}: {row['stage']} rc={rc}",flush=True)
                failed |= rc!=0
    return int(failed)


def memory_trace(text):
    active=False
    slab={};vmap={}
    slab_bytes=vmap_bytes=slab_peak=vmap_peak=0
    intervals=[]
    for line in text.splitlines():
        if 'kprog_f_check:' in line:
            active=True
            slab={};vmap={}
            slab_bytes=vmap_bytes=slab_peak=vmap_peak=0
            continue
        if 'kprog_f_check_ret:' in line:
            if not active:raise RuntimeError('verifier return without entry')
            intervals.append(dict(slab_peak_bytes=slab_peak,vmap_reserved_peak_bytes=vmap_peak))
            active=False
        if not active:continue
        if re.search(r'\b(?:kmalloc|kmem_cache_alloc):',line):
            ptr=re.search(r'\bptr=(0x[0-9a-fA-F]+|\(nil\))',line)
            size=re.search(r'\bbytes_alloc=(\d+)',line)
            if not ptr or not size:raise RuntimeError('cannot parse slab allocation: '+line)
            key=0 if ptr[1]=='(nil)' else int(ptr[1],16)
            if key:
                amount=int(size[1])
                # kvmalloc emits both its nested kmalloc and wrapper event.
                if key in slab:
                    if slab[key]!=amount:raise RuntimeError('conflicting live slab allocation: '+line)
                    continue
                slab[key]=amount;slab_bytes+=amount
                slab_peak=max(slab_peak,slab_bytes)
        elif re.search(r'\b(?:kfree|kmem_cache_free):',line):
            ptr=re.search(r'\bptr=(0x[0-9a-fA-F]+|\(nil\))',line)
            if not ptr:raise RuntimeError('cannot parse slab free: '+line)
            slab_bytes-=slab.pop(0 if ptr[1]=='(nil)' else int(ptr[1],16),0)
        elif 'alloc_vmap_area:' in line:
            fields=dict(re.findall(r'\b(addr|size|failed)=(0x[0-9a-fA-F]+|\d+)',line))
            if fields.keys()!={'addr','size','failed'}:raise RuntimeError('cannot parse vmap allocation: '+line)
            if int(fields['failed'],0)==0:
                key=int(fields['addr'],0);amount=int(fields['size'],0)
                if key in vmap:raise RuntimeError('duplicate live vmap area: '+line)
                vmap[key]=amount;vmap_bytes+=amount
                vmap_peak=max(vmap_peak,vmap_bytes)
        elif 'free_vmap_area_noflush:' in line:
            ptr=re.search(r'\bva_start=(0x[0-9a-fA-F]+|\d+)',line)
            if not ptr:raise RuntimeError('cannot parse vmap free: '+line)
            vmap_bytes-=vmap.pop(int(ptr[1],0),0)
    if active or not intervals:raise RuntimeError('incomplete verifier entry/return trace')
    return dict(verifier_allocation_intervals=intervals,
                verifier_slab_peak_bytes=intervals[-1]['slab_peak_bytes'],
                verifier_vmap_reserved_peak_bytes=intervals[-1]['vmap_reserved_peak_bytes'],
                trace_lost_events=sum(int(n) for n in re.findall(r'\bLOST (\d+) EVENTS\b',text)))


def check(directory,out):
    out.mkdir(parents=True,exist_ok=True)
    (out/'guest.txt').write_text(' '.join(os.uname())+'\n'+Path('/proc/cmdline').read_text())
    failed=False
    records=sorted(directory.glob('n*.json'))
    if not records:raise RuntimeError('no scale build records in '+str(directory))
    for path in records:
        row=json.loads(path.read_text());name=row['name']
        if row['stage']=='compiled':
            command=['trace-cmd','record','-F','-b','32768','-o',out/f'{name}.trace.dat']
            for event in ['kmem:kmalloc','kmem:kfree','kmem:kmem_cache_alloc','kmem:kmem_cache_free',
                          'vmalloc:alloc_vmap_area','vmalloc:free_vmap_area_noflush',
                          'kprobes:kprog_f_check','kprobes:kprog_f_check_ret']:
                command+=['-e',event]
            row['returncode']=run(command+[ROOT/'kprog/fidelity/build-x86/scale-probe',directory/f'{name}.bpf.o',
                out/f'{name}.verifier.log',row['expected_result']],out/f'{name}.load.log')
            row['stage']='passed' if row['returncode']==0 else 'load_or_execution_failed'
            counters=[json.loads(line) for line in (out/f'{name}.load.log').read_text().splitlines() if line.startswith('{')]
            if counters:row['probe_counters']=counters
            # Preserve completed load/execution outcomes even if trace analysis fails.
            (out/f'{name}.json').write_text(json.dumps(row,indent=2)+'\n')
            try:
                report=subprocess.run(['trace-cmd','report','-R','-i',str(out/f'{name}.trace.dat')],text=True,capture_output=True,check=True)
                (out/f'{name}.trace.txt').write_text(report.stdout+report.stderr)
                row.update(memory_trace(report.stdout))
            except (subprocess.CalledProcessError,RuntimeError) as error:
                row['trace_error']=str(error)
                failed=True
            text=(out/f'{name}.verifier.log').read_text() if (out/f'{name}.verifier.log').exists() else ''
            for field,pattern in [('verification_time_us',r'verification time (\d+) usec'),('peak_states',r'peak_states (\d+)')]:
                match=re.search(pattern,text)
                if match:row[field]=int(match[1])
        (out/f'{name}.json').write_text(json.dumps(row,indent=2)+'\n')
        print(f"{name}: {row['stage']}",flush=True)
        failed |= row['stage']!='passed'
    return int(failed)


def main():
    p=argparse.ArgumentParser()
    p.add_argument('mode',choices=['build','check'])
    p.add_argument('--build',type=Path,required=True)
    p.add_argument('--out',type=Path)
    p.add_argument('--sizes',type=int,nargs='+',default=[100,1000,10000,100000])
    a=p.parse_args()
    if a.mode=='build':return build(a.build.resolve(),a.sizes)
    if a.out is None:p.error('check requires --out')
    return check(a.build.resolve(),a.out.resolve())


if __name__=='__main__':raise SystemExit(main())
