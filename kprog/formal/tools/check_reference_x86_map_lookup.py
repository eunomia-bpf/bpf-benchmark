#!/usr/bin/env python3
"""Execute actual native-link array bytes with the single canonical x86 ISA.

Direct-call checks retain the typed call relocation; their platform/callee
semantics are supplied by TV, rather than an invented helper-ID1 equivalence.
"""
import copy
import ctypes
import json
import os
from pathlib import Path
import re
import struct
import subprocess

ROOT=Path(__file__).resolve().parent.parent
MASK=(1<<64)-1
STATUS=0x8D5


def command(argv):
    result=subprocess.run([str(x) for x in argv],text=True,capture_output=True)
    if result.returncode: raise RuntimeError(result.stderr or result.stdout)
    return result.stdout


def layout_fixture():
    """Synthetic ABI data, not a boot-BTF assertion.

    The checked paths below use the exact named ARRAY facts, which are the only
    kernel-layout facts the linker consumes.
    """
    return dict(
        array=dict(map_type=12,max_entries=24,elem_size=32,index_mask=36,value=64,array_type=2))


def main():
    out=ROOT/'build/map-reference'
    out.mkdir(parents=True,exist_ok=True)
    env=dict(os.environ,CARGO_TARGET_DIR=str(ROOT.parent/'x86/native_lab/native_link/target'))
    subprocess.run(['cargo','build','--release','--locked','--quiet','--jobs','1','--manifest-path',
        str(ROOT.parent/'x86/native_lab/native_link/Cargo.toml'),'--bin','native-link'],env=env,check=True)
    linker=ROOT.parent/'x86/native_lab/native_link/target/release/native-link'
    source=out/'lookup.c'
    source.write_text('extern void *bpf_map_lookup_elem(void*,const void*);\nextern char fixture_map[];\n'
        'void *map_lookup(void *m,const void *k){return bpf_map_lookup_elem(fixture_map,k); }\n'
        'void *map_lookup_dynamic(void *m,const void *k){return bpf_map_lookup_elem(m,k); }\n')
    command(['cc','-O2','-fPIC','-fno-optimize-sibling-calls','-c',source,'-o',out/'lookup.o'])

    command([linker,'--mode','proof','--input',out/'lookup.o','--symbol','map_lookup',
        '--output',out/'lookup.proof.o'])
    command([linker,'--mode','proof','--input',out/'lookup.o','--symbol','map_lookup_dynamic',
        '--output',out/'lookup.dynamic.proof.o'])
    flags_source=out/'flags.c'
    flags_source.write_text('''#include <stdint.h>
uint64_t cmp32(uint32_t a,uint32_t b){uint64_t f;__asm__ volatile("cmpl %k2,%k1;pushfq;popq %0":"=r"(f):"r"(a),"r"(b):"cc","memory");return f;}
uint64_t add64(uint64_t a,uint64_t b){uint64_t f;__asm__ volatile("addq %2,%1;pushfq;popq %0":"=r"(f),"+r"(a):"r"(b):"cc","memory");return f;}
uint64_t shl5(uint64_t a){uint64_t f;__asm__ volatile("shlq $5,%1;pushfq;popq %0":"=r"(f),"+r"(a)::"cc","memory");return f;}
uint64_t imul12(uint64_t a){uint64_t f;__asm__ volatile("imulq $12,%1,%1;pushfq;popq %0":"=r"(f),"+r"(a)::"cc","memory");return f;}
''')
    command(['cc','-O2','-shared','-fPIC',flags_source,'-o',out/'flags.so'])
    flags=ctypes.CDLL(str(out/'flags.so'))
    for name,args in [('cmp32',[ctypes.c_uint32,ctypes.c_uint32]),('add64',[ctypes.c_uint64,ctypes.c_uint64]),
                      ('shl5',[ctypes.c_uint64]),('imul12',[ctypes.c_uint64])]:
        fn=getattr(flags,name);fn.argtypes=args;fn.restype=ctypes.c_uint64
    cases=[]
    for kind,elem_size in [(k,8) for k in ('array','percpu_array','hash','lru_hash','percpu_hash','call')]+[('array',32),('percpu_array',32),('array',12),('percpu_array',12)]:
        name=kind if elem_size==8 else kind+'-stride'+str(elem_size)
        plan=dict(version=1,helpers=[dict(name='bpf_map_lookup_elem',addr=0x1000)],
            maps=[dict(name='fixture_map',addr=0x400000000000)],lookup_maps=[dict(
            kind=kind,target_addr=0x12345000,key_offset=48,max_entries=16,elem_size=elem_size,index_mask=15,
            value_offset=128,percpu_base_addr=0x20,name='fixture_map')],
            kernel_layout=layout_fixture())
        plan_path=out/(name+'.json');plan_path.write_text(json.dumps(plan)+'\n')
        blob_path=out/(name+'.bin');reloc_path=out/(name+'.relocs')
        command([linker,'--input',out/'lookup.proof.o','--symbol','map_lookup','--output',blob_path,
            '--link-plan',plan_path,'--output-relocs',reloc_path,'--output-map-patches',out/(name+'.maps'),
            '--output-abi',out/(name+'.abi.json')])
        patches=[line.split('\t') for line in (out/(name+'.maps')).read_text().splitlines()]
        assert patches and all(map_name=='fixture_map' for map_name,_ in patches),(name,patches)
        if kind in ('array','percpu_array') and elem_size==8:
            dynamic=out/(name+'.dynamic.bin');dynamic_reloc=out/(name+'.dynamic.relocs')
            command([linker,'--input',out/'lookup.dynamic.proof.o','--symbol','map_lookup_dynamic',
                '--output',dynamic,'--link-plan',plan_path,'--output-relocs',dynamic_reloc,
                '--output-abi',out/(name+'.dynamic.abi.json')])
            records=dynamic_reloc.read_bytes();assert len(records)==16,(name,records)
            offset,reloc_kind,target=struct.unpack('<IIQ',records)
            assert dynamic.read_bytes()[offset]==0xE8 and target==0x1000,(name,offset,reloc_kind,target)
        blob=bytearray(blob_path.read_bytes())
        offsets=[int(offset) for _,offset in patches]
        assert len(set(offsets))==len(offsets),(name,patches)
        # Apply the typed map-pointer binding as the loader does, retaining
        # each symbol/offset record. Native-link reserves a zero movabs field.
        for offset in offsets:
            assert 2<=offset<=len(blob)-8 and blob[offset-2]&0xf8==0x48 and 0xb8<=blob[offset-1]<=0xbf,(name,offset)
            assert struct.unpack_from('<Q',blob,offset)[0]==0,(name,offset)
            struct.pack_into('<Q',blob,offset,0x400000000000)
        blob_path.write_bytes(blob);blob=bytes(blob)
        assembly=command(['objdump','-D','-b','binary','-m','i386:x86-64','-Mintel','--insn-width=16',blob_path])
        (out/(name+'.asm')).write_text(assembly)
        insns={}
        for line in assembly.splitlines():
            hit=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(\S.*)$',line)
            if hit:insns[int(hit[1],16)]=(len(bytes.fromhex(hit[2])),re.sub(r'\s+',' ',hit[3]).strip())
        calls=[pc for pc,(_,text) in insns.items() if text.startswith('call ')]
        if kind not in ('array','percpu_array'):
            assert len(calls)==1 and len(reloc_path.read_bytes())==16,(kind,assembly)
            offset,reloc_kind,target=struct.unpack('<IIQ',reloc_path.read_bytes())
            assert offset==calls[0] and blob[offset]==0xE8 and target==0x12345000,(kind,offset,target,assembly)
            continue
        assert not reloc_path.read_bytes(),(kind,assembly)
        start=next(pc for pc,(_,text) in insns.items() if re.fullmatch(r'mov eax,DWORD PTR \[rsi\]',text))
        # Observe the selected load/bounds fragment up to its common exit.
        # The entry wrapper's stack effects remain outside this fragment.
        for call in calls:
            target=re.fullmatch(r'call (0x[0-9a-f]+)',insns[call][1])
            assert target is not None and int(target[1],16)==start,(kind,assembly)

        zero=next(pc for pc,(_,text) in insns.items() if text=='xor eax,eax')
        null_end=zero+insns[zero][0]
        value_exit=[text for pc,(_,text) in insns.items() if start<pc<zero and text.startswith('jmp ')]
        assert len(value_exit)==1,(name,assembly)
        join=re.fullmatch(r'jmp (0x[0-9a-f]+)',value_exit[0])
        assert join is not None,(name,assembly)
        value_end=int(join[1],16)
        assert value_end==null_end,(name,value_end,null_end,assembly)
        if elem_size>8:
            scale_text={32:'shl rax,0x5',12:'imul rax,rax,0xc'}[elem_size]
            scale_pc=next(pc for pc,(_,text) in insns.items() if start<pc<zero and text==scale_text)
            scale_end=scale_pc+insns[scale_pc][0]
        first_pp=next((pc for pc,(_,text) in insns.items() if text=='mov rax,QWORD PTR [rax]'),None)
        gs_read=next((pc for pc,(_,text) in insns.items() if text.startswith('add rax,QWORD PTR gs:')),None)
        for key in (0,1,15,16,17,0xFFFFFFFF):
            modes=('normal','key_fault')+ (('slot_fault','cpu_fault') if kind=='percpu_array' and key<16 else ())
            for mode in modes:
                state=dict(registers=[(0xA123000000000000+17*i)&MASK for i in range(16)],flags=0xAD7,
                    pc=start,xmm0=(1<<127)+9,fs_base=0xA000,gs_base=0x9000,memory=[])
                state['registers'][6]=0x2003;state['registers'][7]=0x400000000000
                cells=[]
                def memory(address,value,width,readable=True,initialized=False):
                    cells.extend(dict(address=(address+i)&MASK,value=(value>>(8*i))&255,
                        readable=readable,writable=False,initialized=initialized) for i in range(width))
                memory(0x2003,key,4,mode!='key_fault')
                slot=(state['registers'][7]+128+key*elem_size)&MASK
                pointer=0xFEDCBA9876543210;cpu_offset=0x123456789ABCDEF0
                if kind=='percpu_array' and key<16:
                    memory(slot,pointer,8,mode!='slot_fault',True)
                    memory(0x9020,cpu_offset,8,mode!='cpu_fault',True)
                state['memory']=cells
                expected=copy.deepcopy(state);expected.update(pc=value_end if key<16 else null_end,events=[],fault=None,defined_flags=MASK)
                events=expected['events']
                def read(address,value,width,initialized=False):
                    events.append(dict(kind='read',address=address,value=list(value.to_bytes(width,'little')),initialized=initialized))
                def fault(address,width,pc):
                    expected.update(pc=pc,fault=dict(kind='read',address=address,bytes=width))
                    events.append(dict(kind='fault',fault=expected['fault']))
                if mode=='key_fault':fault(0x2003,4,start)
                else:
                    read(0x2003,key,4)
                    expected['flags']=(state['flags']&~STATUS)|(flags.cmp32(key,16)&STATUS)
                    expected['registers'][0]=slot
                    if key>=16:
                        expected['registers'][0]=0
                        expected['flags']=(expected['flags']&~(STATUS^0x10))|0x44
                        expected['defined_flags']=MASK^0x10
                    elif elem_size>8:
                        # Both ADDs follow scaling; the final ADD defines status
                        # flags. The path mask retains earlier undefined bits.
                        scaled=(key*elem_size)&MASK
                        base=(state['registers'][7]+scaled)&MASK
                        expected['flags']=(expected['flags']&~STATUS)|(flags.add64(base,128)&STATUS)
                        expected['defined_flags']=MASK^(0x810 if elem_size&(elem_size-1)==0 else 0xD4)
                    if key<16 and kind=='percpu_array':
                        if mode=='slot_fault':fault(slot,8,first_pp)
                        else:
                            read(slot,pointer,8,True);expected['registers'][0]=pointer
                            if mode=='cpu_fault':fault(0x9020,8,gs_read)
                            else:
                                read(0x9020,cpu_offset,8,True)
                                expected['registers'][0]=(pointer+cpu_offset)&MASK
                                expected['flags']=(expected['flags']&~STATUS)|(flags.add64(pointer,cpu_offset)&STATUS)
                path=[];pc=start
                while pc!=expected['pc'] or (expected['fault'] is not None and not path):
                    length,text=insns[pc];path.append(dict(offset=pc,length=length))
                    if expected['fault'] is not None and pc==expected['pc']:break
                    if text.startswith('jae '):pc=zero if key>=16 else pc+length
                    elif text.startswith('jmp '):
                        target=re.fullmatch(r'jmp (0x[0-9a-f]+)',text)
                        assert target is not None,(name,pc,text)
                        pc=int(target[1],16)
                    else:pc+=length
                if expected['fault'] is not None and path[-1]['offset']!=expected['pc']:
                    path.append(dict(offset=expected['pc'],length=insns[expected['pc']][0]))
                cases.append((dict(isa='x86_64',native_bytes=list(blob),native_base=0,native_path=path,state=state),expected))
                if elem_size>8 and key<16 and mode=='normal':
                    # Retain the earlier scaling-flag observation before ADD
                    # overwrites it, in addition to the complete fragment.
                    scale_flags={32:flags.shl5,12:flags.imul12}[elem_size]
                    scaled_state=copy.deepcopy(state)
                    scaled_state.update(pc=scale_end,events=[copy.deepcopy(events[0])],fault=None,
                        defined_flags=MASK^(0x810 if elem_size&(elem_size-1)==0 else 0xD4))
                    scaled_state['registers'][0]=(key*elem_size)&MASK
                    scaled_state['flags']=(state['flags']&~STATUS)|(scale_flags(key)&STATUS)
                    cases.append((dict(isa='x86_64',native_bytes=list(blob),native_base=0,
                        native_path=[row for row in path if row['offset']<scale_end],state=state),scaled_state))
    run=subprocess.run([str(ROOT/'.lake/build/bin/reference')],input=''.join(json.dumps(r)+'\n' for r,_ in cases),
        text=True,capture_output=True)
    if run.returncode:
        raise RuntimeError(run.stderr or run.stdout)
    results=[json.loads(line) for line in run.stdout.splitlines()];assert len(results)==len(cases)
    for (request,expected),actual in zip(cases,results):
        mask=expected['defined_flags'];actual['flags']&=mask;expected['flags']&=mask
        assert actual==expected,(request,actual,expected)
    print(f'map lowering reference: {len(cases)} actual linked ARRAY/PERCPU_ARRAY load/bounds fragments, full state/ordered reads/faults and common exit; entry-wrapper stack effects are outside that observation; four named direct-call targets and two opaque-map generic helper targets retained')


if __name__=='__main__':
    main()
