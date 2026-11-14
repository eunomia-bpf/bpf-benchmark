#!/usr/bin/env python3
"""Catch old-base/index truncation, premature writeback and lost SIMD lanes."""
import copy
import json
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parent.parent
MASK=(1<<64)-1
BASE=0x4000
modes={'scaled':0x39000000,'unscaled':0x38000000,'pre':0x38000c00,'post':0x38000400,'register':0x38200800}
cases=[];rejects=[]

def fixture(width,load,mode,*,signed=0,vector=False,reg=0,base=4,index=5,option=3,shift=True,raw=2,imm=8):
    size=width.bit_length()-1
    opc=(2+load if width==16 else int(load)) if vector else (signed if load and signed else int(load))
    encoded_size=0 if width==16 else size
    word=modes[mode]|(encoded_size<<30)|(opc<<22)|(int(vector)<<26)|(base<<5)|reg
    state=dict(registers=[0x8877665544332200+i for i in range(31)]+[0x8000],
        flags=0xf0000000,pc=0x1000,vectors=[((i+1)<<120)+0x1122334455667788 for i in range(32)],memory=[])
    state['vector0']=state['vectors'][0]
    state['registers'][4]=BASE
    state['registers'][5]=raw&MASK
    if mode=='register':
        word|=(index<<16)|(option<<13)|(int(shift)<<12)
        value=state['registers'][index] if index!=31 else 0
        if option in [2,6]:value&=0xffffffff
        if option==6 and value&(1<<31):value-=1<<32
        offset=(value<<(size if shift else 0))&MASK
    elif mode=='scaled':
        assert imm%width==0
        word|=(imm//width)<<10
        offset=imm
    else:
        word|=(imm&511)<<12
        offset=imm
    oldbase=state['registers'][base]
    address=(oldbase+(0 if mode=='post' else offset))&MASK
    data=[(0xa5+7*i)&255 for i in range(width)]
    state['memory']=[dict(address=(address+i)&MASK,value=value,readable=True,writable=True,initialized=i%2==0) for i,value in enumerate(data)]
    q=dict(isa='aarch64',state=state,native_bytes=list(word.to_bytes(4,'little')))
    e=copy.deepcopy(state);e.update(pc=0x1004,defined_flags=MASK,fault=None)
    if load:
        value=int.from_bytes(bytes(data),'little')
        if vector:
            e['vectors'][reg]=value;e['vector0']=e['vectors'][0]
        elif reg!=31:
            if signed and value&(1<<(8*width-1)):value-=1<<(8*width)
            e['registers'][reg]=value&((1<<(32 if signed==3 else 64))-1)
        event=dict(kind='read',address=address,value=data,initialized=width==1)
    else:
        value=state['vectors'][reg] if vector else state['registers'][reg] if reg!=31 else 0
        data=list((value&((1<<(width*8))-1)).to_bytes(width,'little'))
        for cell,value in zip(e['memory'],data):cell.update(value=value,initialized=True)
        event=dict(kind='write',address=address,value=data,initialized=True)
    if mode in ['pre','post']:e['registers'][base]=(oldbase+offset)&MASK
    e['events']=[event]
    return q,e

for width in [1,2,4,8]:
    for load in [False,True]:
        signs=[0]+([2,3] if width<4 else [2] if width==4 else []) if load else [0]
        for signed in signs:
            for mode in modes:
                for imm in ([8,-8] if mode in ['unscaled','pre','post'] else [8]):
                    for base in [4,31]:
                        cases.append(fixture(width,load,mode,signed=signed,base=base,imm=imm))
            for option in [2,3,6,7]:
                for shift in [False,True]:
                    for raw in [0,2,0xfffffffffffffffe]:
                        cases.append(fixture(width,load,'register',signed=signed,option=option,shift=shift,raw=raw))
            for mode in ['scaled','pre','post','register']:
                cases.append(fixture(width,load,mode,signed=signed,reg=31))
            cases.append(fixture(width,load,'register',signed=signed,index=31))
            cases.append(fixture(width,load,'scaled',signed=signed,reg=4))
for width in [1,2,4,8,16]:
    for load in [False,True]:
        for mode in modes:
            for reg in [0,1,15,31]:
                cases.append(fixture(width,load,mode,vector=True,reg=reg,imm=16))
        for option in [2,3,6,7]:
            for shift in [False,True]:
                cases.append(fixture(width,load,'register',vector=True,option=option,shift=shift,raw=0xfffffffffffffffe))
# A data fault must leave all data registers, memory and the old base unchanged.
for vector in [False,True]:
    for load in [False,True]:
        for mode in ['pre','post']:
            q,e=fixture(16 if vector else 8,load,mode,vector=vector)
            q['state']['memory'][-1]['readable' if load else 'writable']=False
            e=copy.deepcopy(q['state']);e.update(defined_flags=MASK)
            fault=dict(kind='read' if load else 'write',address=e['memory'][0]['address'],bytes=16 if vector else 8)
            e.update(fault=fault,events=[dict(kind='fault',fault=fault)])
            cases.append((q,e))
# The incoming SP faults even if its pre-indexed effective address would align.
q,e=fixture(8,True,'pre',base=31,imm=-1)
q['state']['registers'][31]+=1
fault=dict(kind='sp_alignment',address=0x8001)
e=copy.deepcopy(q['state']);e.update(defined_flags=MASK,fault=fault,events=[dict(kind='fault',fault=fault)])
cases.append((q,e))
for load in [False,True]:
    for mode in ['pre','post']:
        q,_=fixture(8,load,mode,reg=4)
        rejects.append((q,'constrained-unpredictable load/store writeback overlap'))
for option in [0,1,4,5]:
    q,_=fixture(8,True,'register')
    word=int.from_bytes(bytes(q['native_bytes']),'little');word=(word&~(7<<13))|(option<<13)
    q['native_bytes']=list(word.to_bytes(4,'little'))
    rejects.append((q,'reserved load/store index extension'))
q,_=fixture(16,True,'scaled',vector=True,imm=16)
word=int.from_bytes(bytes(q['native_bytes']),'little')|(1<<30)
q['native_bytes']=list(word.to_bytes(4,'little'))
rejects.append((q,'reserved SIMD load/store size'))

# Pair writeback commits after both ordered accesses, including partial-store faults.
for width,sizebit in [(4,0),(8,1<<31)]:
    for load in [False,True]:
        for mode,baseop in [('offset',0x29000000),('pre',0x29800000),('post',0x28800000)]:
            for imm in [-16,16]:
                word=baseop|sizebit|(int(load)<<22)|(((imm//width)&127)<<15)|(1<<10)|(4<<5)
                q=copy.deepcopy(cases[0][0]);q['native_bytes']=list(word.to_bytes(4,'little'))
                st=q['state'];st['registers'][0]=0x8877665544332211;st['registers'][1]=0x1122334455667788
                address=BASE+(0 if mode=='post' else imm)
                st['memory']=[dict(address=address+i,value=(0xa5+i)&255,readable=True,writable=True,initialized=i%2==0) for i in range(2*width)]
                e=copy.deepcopy(st);e.update(pc=0x1004,defined_flags=MASK,fault=None,events=[])
                for lane in [0,1]:
                    data=[c['value'] for c in st['memory'][lane*width:(lane+1)*width]]
                    if load:e['registers'][lane]=int.from_bytes(bytes(data),'little')
                    else:
                        data=list((st['registers'][lane]&((1<<(width*8))-1)).to_bytes(width,'little'))
                        for cell,value in zip(e['memory'][lane*width:(lane+1)*width],data):cell.update(value=value,initialized=True)
                    e['events'].append(dict(kind='read' if load else 'write',address=address+lane*width,value=data,initialized=not load))
                if mode!='offset':e['registers'][4]=BASE+imm
                cases.append((q,e))
                for lane in [0,1]:
                    bad=copy.deepcopy(q);bad['state']['memory'][(lane+1)*width-1]['readable' if load else 'writable']=False
                    failed=copy.deepcopy(bad['state']);fault=dict(kind='read' if load else 'write',address=address+lane*width,bytes=width)
                    failed.update(defined_flags=MASK,fault=fault,events=e['events'][:lane]+[dict(kind='fault',fault=fault)])
                    if not load and lane==1:failed['memory'][:width]=copy.deepcopy(e['memory'][:width])
                    cases.append((bad,failed))
        for mode,baseop in [('pre',0x29800000),('post',0x28800000)]:
            q=copy.deepcopy(cases[0][0]);word=baseop|sizebit|(int(load)<<22)|(1<<10)|(4<<5)|4
            q['native_bytes']=list(word.to_bytes(4,'little'))
            rejects.append((q,'constrained-unpredictable pair writeback overlap'))
q,_=fixture(8,True,'scaled',vector=True,reg=1)
q['state'].pop('vectors');rejects.append((q,'nonzero SIMD register requires explicit vectors V0..V31'))

# The explicit LSE2 profile must affect a real unaligned RMW, not merely echo
# an input flag. Crossing the16-byte atomicity quantity still faults.
for address,feature,success in [(0x4001,False,False),(0x4001,True,True),(0x4009,True,False)]:
    q=copy.deepcopy(cases[0][0]);q['native_bytes']=list((0xf8220020).to_bytes(4,'little'))
    st=q['state'];st['registers'][1]=address;st['registers'][2]=7
    st['lse2_unaligned_within_16']=feature
    st['memory']=[dict(address=address+i,value=i+1,readable=True,writable=True,initialized=False) for i in range(8)]
    e=copy.deepcopy(st);e.update(defined_flags=MASK,events=[],fault=None)
    if success:
        e['pc']=0x1004;e['registers'][0]=0x0807060504030201
        written=[8,2,3,4,5,6,7,8]
        for cell,value in zip(e['memory'],written):cell.update(value=value,initialized=True)
        e['events']=[dict(kind='atomic',address=address,value=list(range(1,9)),initialized=False),
                     dict(kind='write',address=address,value=written,initialized=True)]
    else:
        fault=dict(kind='alignment',address=address,bytes=8)
        e.update(fault=fault,events=[dict(kind='fault',fault=fault)])
    cases.append((q,e))

binary=ROOT/'.lake/build/bin/reference'
result=subprocess.run([str(binary)],input=''.join(json.dumps(q)+'\n' for q,e in cases),text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True)
outputs=[json.loads(line) for line in result.stdout.splitlines()]
assert len(outputs)==len(cases)
for n,((q,e),out) in enumerate(zip(cases,outputs)):
    assert out.pop('reference_base') == 'LNSym'
    assert e==out,(n,q,e,out)
for q,message in rejects:
    result=subprocess.run([str(binary)],input=json.dumps(q)+'\n',text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    if message == 'nonzero SIMD register requires explicit vectors V0..V31':
        diagnostic = 'reference: ' + message
    else:
        kind = 'Unimplemented' if message == 'reserved SIMD load/store size' else 'Illegal'
        diagnostic = 'reference: external AArch64 model refusal: StateError.' + kind
    assert result.returncode and not result.stdout and result.stderr.startswith(diagnostic),(q,message,result)
print(f'Arm addressed/vector memory: {len(cases)} full-state cases, {len(rejects)} encoding/input rejections PASS')
