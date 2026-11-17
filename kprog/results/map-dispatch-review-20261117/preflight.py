#!/usr/bin/env python3
"""Execute retained map-dispatch fragments against host-only fake maps and a local callback."""
import ctypes as C
import json
import mmap
from pathlib import Path
import struct
import sys

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
index=json.loads(Path('kprog/results/map-dispatch-review-20261117/dispatch.json').read_text())
row=next(r for r in index['requests'] if r['app']=='katran')
capture=json.loads(Path('kprog/results/current-link-capture-20261117/katran.json').read_text())['captures'][0]
plan=json.loads(Path(capture['plan']).read_text())
a,l=plan['kernel_layout']['array'],plan['kernel_layout']['lpm']
data=(Path(row['output'])/'image.blob').read_bytes()
array=data[row['array']['start']:row['array']['end']]
lpm=data[row['lpm']['start']:row['lpm']['end']]
assert array[-14:-10]==bytes.fromhex('4883ec08') and array[-10]==0xe8 and array[-5:]==bytes.fromhex('4883c408c3')
assert lpm[-14:]==bytes.fromhex('4883ec08e8000000004883c408c3')
old=bytearray(array+lpm);struct.pack_into('<i',old,len(array)-9,5)
fused=array[:-14]+lpm
(out/'old-chain.bin').write_bytes(old);(out/'fused-fragment.bin').write_bytes(fused)
(out/'inputs.json').write_text(json.dumps(dict(source=row,plan=capture['plan'],array=a,lpm=l,
    old_bytes=len(old),fused_bytes=len(fused),scope='Extracted test fragments, not a production transformation or timing result.'),indent=2)+'\n')
libc=C.CDLL(None,use_errno=True)
libc.mprotect.argtypes=[C.c_void_p,C.c_size_t,C.c_int];libc.mprotect.restype=C.c_int
page=mmap.PAGESIZE
keys=mmap.mmap(-1,page*2,prot=mmap.PROT_READ|mmap.PROT_WRITE)
anchor=C.c_char.from_buffer(keys);key_base=C.addressof(anchor);del anchor
assert libc.mprotect(key_base+page,page,0)==0
map_buffer=C.create_string_buffer(4096);node=C.create_string_buffer(256)
mp,np=C.addressof(map_buffer),C.addressof(node)
state=(C.c_uint64*5)();sp=C.addressof(state)
# callback records count/map/key/RSP and returns the two original arguments XORed.
callback=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex(
    '49ff0349897b08498973104889e0498943184889f84831f0c3')
# Record entry RSP before any test CALL/JMP frame, without changing arguments.
entry=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex('4889e049894320')
lookup_type=C.CFUNCTYPE(C.c_uint64,C.c_void_p,C.c_void_p)
mask64=(1<<64)-1

def u32(ptr,offset,value):C.c_uint32.from_address(ptr+offset).value=value

def u64(ptr,offset,value):C.c_uint64.from_address(ptr+offset).value=value

def set_key(prefix,contents,guard):
    ptr=key_base+page-16 if guard else key_base+2049
    C.memmove(ptr,bytes(16),16);u32(ptr,l['key_prefixlen'],prefix)
    C.memmove(ptr+l['key_data'],contents,12)
    return ptr

cases=[]
for form,fragment in [('old',bytes(old)),('fused',fused)]:
    for transfer in ('call','jmp'):
        prefix=bytearray(entry)
        site=len(prefix)+(4 if transfer=='call' else 0)
        prefix.extend(bytes.fromhex('4883ec08e8000000004883c408c3') if transfer=='call' else bytes.fromhex('e900000000'))
        prefix.extend(b'\x90'*16);body=len(prefix)
        struct.pack_into('<i',prefix,site+1,body-site-5)
        code=prefix+fragment
        generic=body+len(fragment)-10
        target=len(code);code+=callback
        struct.pack_into('<i',code,generic+1,target-generic-5)
        (out/f'{form}-{transfer}.bin').write_bytes(code)
        size=(len(code)+page-1)//page*page
        mapping=mmap.mmap(-1,size,prot=mmap.PROT_READ|mmap.PROT_WRITE)
        anchor=C.c_char.from_buffer(mapping);base=C.addressof(anchor);del anchor
        mapping.write(code);assert libc.mprotect(base,size,mmap.PROT_READ|mmap.PROT_EXEC)==0
        lookup=lookup_type(base)
        count=0;generic_count=0
        print('start',form,transfer,'bytes',len(fragment),flush=True)
        def check(key,expected,generic_call=False):
            global count,generic_count
            for i in range(5):state[i]=0
            actual=lookup(mp,key)
            assert actual==expected,(form,transfer,count,'result',hex(actual),hex(expected))
            assert state[0]==int(generic_call),(form,transfer,count,'callback count',state[0])
            if generic_call:
                assert (state[1],state[2])==(mp,key),'generic arguments changed'
                assert state[3]&15==8,'generic helper stack is not SysV aligned'
                depth=(16 if transfer=='call' else 0)+(32 if form=='old' else 16)
                assert state[4]-state[3]==depth,('unexpected callback stack depth',state[4]-state[3],depth)
                generic_count+=1
            count+=1
        # ARRAY tests use the captured live field offsets, masked u32 keys and wide products.
        for maximum in (0,1,5,4096):
            for bits in (3,7,4095):
                for stride in (8,24,0xffffffff):
                    u32(mp,a['map_type'],a['array_type']);u32(mp,a['max_entries'],maximum)
                    u32(mp,a['index_mask'],bits);u32(mp,a['elem_size'],stride)
                    for number in (0,1,max(0,maximum-1),maximum,maximum+1,0xffffffff):
                        kp=key_base+page-4;u32(kp,0,number)
                        expected=0 if number>=maximum else (mp+a['value']+(number&bits)*stride)&mask64
                        check(kp,expected)
        # The exact specialized LPM shape is data_size12/max_prefixlen96.
        u32(mp,l['map_type'],l['lpm_type']);u64(mp,l['data_size'],12);u64(mp,l['max_prefixlen'],96)
        u64(mp,l['root'],np)
        C.memset(np,0,256)
        for differing in (0,1,7,8,31,32,63,64,95,96):
            contents=bytearray(12)
            if differing<96:contents[differing//8]=1<<(7-differing%8)
            common=0
            for bit in range(96):
                if (contents[bit//8]>>(7-bit%8))&1:break
                common+=1
            for prefix in (0,1,31,32,63,64,95,96):
                u32(np,l['node_prefixlen'],prefix)
                for query in (0,1,31,32,63,64,95,96,97):
                    for flags in (0,1):
                        u32(np,l['node_flags'],flags)
                        kp=set_key(query,bytes(contents),(query+flags)&1)
                        found=query<=96 and query>=prefix and common>=prefix and (not flags or prefix==96)
                        check(kp,np+l['node_data']+12 if found else 0)
        kp=set_key(96,bytes(12),True);u64(mp,l['root'],0);check(kp,0)
        # Invalid prefix returns before touching an inaccessible root.
        u64(mp,l['root'],key_base+page);kp=set_key(97,bytes(12),True);check(kp,0)
        # Both dispatch guards delegate before reading an inaccessible key.
        for kind in range(32):
            if kind in (a['array_type'],l['lpm_type']):continue
            u32(mp,a['map_type'],kind);check(1,mp^1,True)
        u32(mp,l['map_type'],l['lpm_type'])
        for width in range(21):
            if width==12:continue
            u64(mp,l['data_size'],width);check(1,mp^1,True)
        cases.append(dict(form=form,transfer=transfer,cases=count,generic_callbacks=generic_count,
                          fragment_bytes=len(fragment),stack_alignment=8))
        print('pass',form,transfer,count,'cases',generic_count,'generic callbacks',flush=True)
        del lookup;mapping.close()
assert libc.mprotect(key_base+page,page,mmap.PROT_READ|mmap.PROT_WRITE)==0
keys.close()
result=dict(scope='Host functional ABI preflight on extracted retained fragments and a host test callback. '
    'No real kernel helper executes. No production transformation, installed-size or timing result.',
    old_bytes=len(old),fused_bytes=len(fused),cases=cases,total_cases=sum(r['cases'] for r in cases))
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n')
print('completed',result['total_cases'],'host functional cases',flush=True)
