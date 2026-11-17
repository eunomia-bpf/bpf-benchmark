#!/usr/bin/env python3
"""Execute retained tail stubs and short-encoding candidates on synthetic host frames."""
import ctypes as C
import json
import mmap
from pathlib import Path
import struct
import sys

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
rows=json.loads(Path('kprog/results/tail-encoding-review-20261117/inventory.json').read_text())['sites']
libc=C.CDLL(None,use_errno=True)
libc.mprotect.argtypes=[C.c_void_p,C.c_size_t,C.c_int];libc.mprotect.restype=C.c_int
page=mmap.PAGESIZE
state=(C.c_uint64*16)();sp=C.addressof(state)
stack=C.create_string_buffer(65536);rsp=(C.addressof(stack)+32768)&~15;rsp+=8
frame=C.create_string_buffer(8192);bp=C.addressof(frame)+4096
map_buffer=C.create_string_buffer(4096);mp=C.addressof(map_buffer)
prog=C.create_string_buffer(4096);pp=C.addressof(prog)
counters=(C.c_uint64*2)();cp=C.addressof(counters)
context=0x123456789abc
function=C.CFUNCTYPE(C.c_uint64,C.c_uint64,C.c_void_p,C.c_uint64)

def put64(address,value):C.c_uint64.from_address(address).value=value

def callback(path):
    # Record the tail's result/stack/arguments. Restore actual host callee-saved
    # registers and RSP before RET; all fake popped registers are test data.
    b=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex(
        '498943404989634849897b504989735849895360')
    b+=bytes.fromhex('b8')+struct.pack('<I',path)
    b+=bytes.fromhex('498b5b08498b6b104d8b63184d8b6b204d8b73284d8b7b30498b23c3')
    return b

# Capture the real host frame before switching to the synthetic BPF stack.
entry=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex(
    '49892349895b0849896b104d8963184d896b204d8973284d897b30')
entry+=bytes.fromhex('48bc')+struct.pack('<Q',rsp)
entry+=bytes.fromhex('48bd')+struct.pack('<Q',bp)+bytes.fromhex('b80c000000')


def candidate(row):
    old=bytes.fromhex(row['stub_hex']);end=len(old)
    branches=row['branches']
    edits=[(site,site+6,bytes([old[site+1]-0x10,0])) for site in branches]
    bound=struct.unpack_from('<i',old,4)[0]
    edits.append((2,8,bytes.fromhex('3956')+bytes([bound])))
    func=struct.unpack_from('<i',old,end-13)[0]
    edits.append((end-16,end-9,bytes.fromhex('488b49')+bytes([func])))
    add=struct.unpack_from('<i',old,end-6)[0]
    edits.append((end-9,end-2,bytes.fromhex('4883c1')+bytes([add])))
    edits.sort()
    def mapped(offset):return offset-sum(finish-start-len(replacement) for start,finish,replacement in edits if finish<=offset)
    new=bytearray();cursor=0
    for start,finish,replacement in edits:
        assert start>=cursor
        new+=old[cursor:start]+replacement;cursor=finish
    new+=old[cursor:]
    for site in branches:
        at=mapped(site);delta=len(new)-at-2
        assert -128<=delta<=127
        new[at+1]=delta&255
    field=row['counter_field']-row['start'];new_field=mapped(field)
    assert len(new)==len(old)-21
    assert old[field-3:field]==new[new_field-3:new_field]
    assert new[new_field:new_field+4]==old[field:field+4]
    return bytes(new),new_field,func,add

reports=[];total=0
for index,row in enumerate(rows):
    if not row.get('recognized_end'):continue
    old=bytes.fromhex(row['stub_hex']);field=row['counter_field']-row['start']
    short,short_field,func_offset,tail_entry=candidate(row)
    old_results={};executions=0
    print('start',index,row['app'],row['symbol'],len(old),len(short),flush=True)
    # All actual stubs have this four-byte source displacement. A saved-frame
    # variant loads BPF RBP from the synthetic stack; the live variant uses RBP.
    if old[field-3:field]==bytes.fromhex('488b80'):
        assert old[field-11:field-7]==bytes.fromhex('488b8424')
        saved=struct.unpack_from('<i',old,field-7)[0]
        put64(rsp+saved,bp)
    else:
        assert old[field-3:field]==bytes.fromhex('488b85')
    for variant,fragment,at in [('old',old,field),('short',short,short_field)]:
        for displacement,selected in [(-16,0),(-32,1)]:
            code=bytearray(entry+fragment+callback(0));success=len(code);code+=callback(1)
            struct.pack_into('<i',code,len(entry)+at,displacement)
            size=(len(code)+page-1)//page*page
            mapping=mmap.mmap(-1,size,prot=mmap.PROT_READ|mmap.PROT_WRITE)
            anchor=C.c_char.from_buffer(mapping);base=C.addressof(anchor);del anchor
            mapping.write(code);assert libc.mprotect(base,size,mmap.PROT_READ|mmap.PROT_EXEC)==0
            call=function(base)
            put64(pp+func_offset,base+success-tail_entry)
            # Counter limit and empty-slot misses must preserve counts; successful
            # transfers increment exactly the selected counter. Upper EDX bits die.
            for limit in [0,1,4]:
                C.c_uint32.from_address(mp+row['max_entries_displacement']).value=limit
                for count in [0,32,33,34]:
                    for populated in [False,True]:
                        for key in [0,1,4,0xffffffff,0xfeedface00000001]:
                            for slot in range(4):put64(mp+304+8*slot,pp if populated else 0)
                            counters[0]=count;counters[1]=count
                            put64(bp-16,cp);put64(bp-32,cp+8)
                            for n in range(8,16):state[n]=0
                            expected=int((key&0xffffffff)<limit and count<33 and populated)
                            result=call(context,mp,key)
                            values=(counters[0],counters[1])
                            expected_counts=[count,count];expected_counts[selected]+=expected
                            assert result==expected,(index,variant,displacement,limit,count,populated,key,'path',result)
                            assert values==tuple(expected_counts),(index,variant,'counter',values,expected_counts)
                            assert (state[10],state[11],state[12])==(context,mp,key&0xffffffff),'context/map/index changed'
                            if (key&0xffffffff)>=limit:assert state[8]==12,'bound miss lost original RAX state'
                            case=(displacement,limit,count,populated,key)
                            observation=(result,values,state[9],state[10],state[11],state[12])
                            if variant=='old':old_results[case]=observation
                            else:assert observation==old_results[case],('old/short frame/result difference',index,case)
                            executions+=1;total+=1
            mapping.close()
    reports.append(dict(app=row['app'],symbol=row['symbol'],counter_field=row['counter_field'],
        old_bytes=len(old),short_bytes=len(short),old_field=field,short_field=short_field,executions=executions))
    print('pass',index,'executions',executions,flush=True)
result=dict(scope='Host retained-fragment functional preflight with synthetic maps, counters, program target and stack. '
    'No real kernel address executes. No production transformation, stock verification, installed-size or timing claim.',
    stubs=len(reports),executions=total,old_bytes=sum(r['old_bytes'] for r in reports),
    short_bytes=sum(r['short_bytes'] for r in reports),reports=reports)
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n')
print('PASS stubs',len(reports),'executions',total,'bytes',result['old_bytes'],result['short_bytes'],flush=True)
