"""Catch public packet-pointer truncation and the eight-byte qdisc CB shift."""
import ctypes as c
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'kprog'))
from trusted_service import adapter
from kernel_function_abi import KernelTypes, Type
compiler,linker,context,public,physical,native,output=map(Path,sys.argv[1:])
output.mkdir(parents=True)
rules=json.loads(physical.read_text())
def offset(kind,field):
    rule=next(r for r in rules if r['kind']==kind and r['field']==field)
    assert not rule['pointers']
    return rule['offset']
# Independently read the sole kernel BTF, rather than assuming a raw cb offset
# from a different configuration. The simulator constant means qdisc data.
class Member(c.Structure):
    _fields_=[('name',c.c_uint32),('type',c.c_uint32),('offset',c.c_uint32)]
target=KernelTypes('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
try:
    def member(structure,field):
        identity=target.lib.btf__find_by_name_kind(target.btf,structure.encode(),4)
        assert identity>0,(structure,identity)
        t=target.type(identity)
        members=(Member*(t.info&65535)).from_address(c.addressof(t)+c.sizeof(Type))
        for item in members:
            if target.lib.btf__name_by_offset(target.btf,item.name).decode()==field:
                return (item.offset&0xffffff)//8
        raise AssertionError((structure,field))
    actual=dict(skb_cb=member('sk_buff','cb'),qdisc_data=member('qdisc_skb_cb','data'))
    actual['bpf_cb']=actual['skb_cb']+actual['qdisc_data']
    assert offset('skb','cb')==actual['bpf_cb']
    (output/'target-btf.json').write_text(json.dumps(actual,indent=2)+'\n')
finally:target.close()
worker=adapter(1)
rows=[]
for kind,entry,prog_type,section in [('xdp','packet_xdp',6,'xdp'),('tc','packet_tc',3,'tc'),('cgroup_skb','packet_tc',8,'cgroup_skb/egress')]:
    directory=output/kind;directory.mkdir()
    artifact=worker.specialize(native.read_bytes(),entry,dict(version=1,prog_type=prog_type,section=section,maps=[]),directory/'generated',linker)
    result=worker.compile_checked_simulator(artifact,linker,compiler,context_compiler=context,public_layout=public,physical_layout=physical)
    harness=directory/'harness.c'
    harness.write_text('unsigned long long kprog_unspecified_input[1];\nvoid *bpf_cast_to_kern_ctx(void *ctx) { return ctx; }\n')
    shared=directory/'simulator.so'
    command=['clang-18','-shared','-fPIC',str(native),result['native_object'],str(harness),'-o',str(shared)]
    completed=subprocess.run(command,capture_output=True,text=True)
    (directory/'link.json').write_text(json.dumps(dict(command=command,returncode=completed.returncode,stdout=completed.stdout,stderr=completed.stderr),indent=2)+'\n')
    completed.check_returncode()
    library=c.CDLL(str(shared))
    reference=getattr(library,entry);compiled=getattr(library,result['symbol'])
    for fn in [reference,compiled]:fn.argtypes=[c.c_void_p];fn.restype=c.c_int
    cases=[(length,byte) for length in [63,64,65] for byte in [0,0x5a,0xff]] if kind=='xdp' else [(a,b) for a in [0,1,0x80000000,0xffffffff] for b in [0,0xfedcba98]]
    for a,b in cases:
        before=bytearray(4096)
        if kind=='xdp':
            packet=c.create_string_buffer(bytes([b])*80)
            before[offset('xdp','data'):offset('xdp','data')+8]=c.addressof(packet).to_bytes(8,'little')
            before[offset('xdp','data_end'):offset('xdp','data_end')+8]=(c.addressof(packet)+a).to_bytes(8,'little')
        else:
            cb=offset('skb','cb')
            before[cb-8:cb+20]=bytes(range(28))
            for field,value in [('mark',a),('priority',b)]:before[offset('skb',field):offset('skb',field)+4]=value.to_bytes(4,'little')
        original=c.create_string_buffer(bytes(before),len(before))
        candidate=c.create_string_buffer(bytes(before),len(before))
        expected=reference(original);observed=compiled(candidate)
        assert expected==observed,(kind,a,b,expected,observed)
        assert original.raw==candidate.raw,(kind,a,b,'context bytes differ')
        if kind!='xdp':assert candidate.raw[cb-8:cb]==bytes(before[cb-8:cb]),'qdisc prefix overwritten'
        rows.append(dict(kind=kind,a=a,b=b,retval=observed,context_bytes_equal=True))
(output/'execution.json').write_text(json.dumps(rows,indent=2)+'\n')
print(json.dumps(dict(vectors=len(rows),kinds=['xdp','tc','cgroup_skb'],physical_cb_offset=offset('skb','cb'),scope='actual native input vs checked-C native compiler host execution, no kernel acceptance')))
