"""Execute the captured actual linked entry through its early helper boundaries."""
import ctypes as C,json,mmap,struct,subprocess,sys
from pathlib import Path
ROOT=Path('/workspaces/repository');cache=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127/20261127T195100Z/linkcache/native_kernel_link_cache');raw=Path(sys.argv[1]);raw.mkdir(parents=True,exist_ok=True)
if len(sys.argv)>2:cache=Path(sys.argv[2])
key=next(p.name.split('.')[0] for p in cache.glob('*.frozen.proof.o') if any(l.split()[-1:]==['native_tracer_entry'] for l in subprocess.check_output(['llvm-nm-18','--defined-only',str(p)],text=True).splitlines()))
subprocess.run(['clang-18','-O2','-mstackrealign','-shared','-fPIC',str(ROOT/'kprog/results/x86-otel-perf-20261127/entry_trace_stub.c'),'-ldl','-o',str(raw/'stubs.so')],check=True)
stubs=C.CDLL(str(raw/'stubs.so'),mode=C.RTLD_GLOBAL);libc=C.CDLL(None);plan=json.loads(next(cache.glob(key+'*.link-plan.json')).read_text());by_address={}
for h in plan['helpers']:by_address.setdefault(h['addr'],[]).append(h['name'])
symbol_root=cache if (cache/'kallsyms.txt').exists() else cache.parent.parent
symbols=max(symbol_root.glob('kallsyms-bpf-*.txt'),key=lambda p:float(p.stem[len('kallsyms-bpf-'):]))
for line in ((symbol_root/'kallsyms.txt').read_text()+symbols.read_text()).splitlines():
 parts=line.split()
 if len(parts)>=3 and parts[1] in 'tTwW':by_address.setdefault(int(parts[0],16),[]).append(parts[2])
code=bytearray((cache/(key+'.blob.bin')).read_bytes());patches=[line.split() for line in (cache/(key+'.map-patches.tsv')).read_text().splitlines()];maps={name:C.create_string_buffer(4096) for name,_ in patches}
for name,off in patches:struct.pack_into('<Q',code,int(off),C.addressof(maps[name]))
# Preserve host callee-saved registers around the native ABI (the kernel
# bridge normally owns RBX/R13/R14/R15); leave SysV call alignment intact.
state=(C.c_uint64*16)();sp=C.addressof(state);stack=C.create_string_buffer(65536);bp=(C.addressof(stack)+32768)&~15
prefix=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex('49892349895b0849896b104d8963184d896b204d8973284d897b30')
prefix+=bytes.fromhex('48bc')+struct.pack('<Q',bp)+bytes.fromhex('48bd')+struct.pack('<Q',bp)
# Exact BPF tail-count/pointer and callee register frame before native P.
prefix+=bytes.fromhex('31c0504889e05053415541564157')
restore=bytes.fromhex('498b5b08498b6b104d8b63184d8b6b204d8b73284d8b7b30498b23c3')
suffix=bytes.fromhex('49bb')+struct.pack('<Q',sp)+restore
success=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex('4989434049897b484989635049896b5849c7436001000000b809030000')+restore
size=65536
region=mmap.mmap(-1,size,prot=mmap.PROT_READ|mmap.PROT_WRITE|mmap.PROT_EXEC);anchor=C.c_char.from_buffer(region);base=C.addressof(anchor);del anchor
payload=bytearray(prefix+code+suffix+success);targets=[]
diagnose=len(sys.argv)>3 and sys.argv[3]=='diagnose-tail'
if diagnose:
 signature=bytes.fromhex('89d23996')+struct.pack('<I',next(h['addr'] for h in plan['helpers'] if h['name']=='__native_x86_bpf_map_max_entries_offset'))
 starts=[i for i in range(len(code)) if code[i:i+len(signature)]==signature]
 for number,start in enumerate(starts):
  for reason,pattern in [(1,bytes.fromhex('0f86')),(2,bytes.fromhex('488338210f83')),(3,bytes.fromhex('4885c90f84'))]:
   at=code.index(pattern,start,start+140)+len(pattern)-2;marker=(number+1)*10+reason
   target=len(payload);callback=bytes.fromhex('49bb')+struct.pack('<Q',sp)+bytes.fromhex('4989434049897b484989635049896b58498973704989537849c74368')+struct.pack('<I',marker)+bytes.fromhex('b8')+struct.pack('<I',900+marker)+restore
   payload+=callback;at+=len(prefix);struct.pack_into('<i',payload,at+2,target-at-6)

for off,kind,target in struct.iter_unpack('<IIQ',(cache/(key+'.relocs.bin')).read_bytes()):
 assert kind==1
 names=by_address[target];function=None
 for name in names:
  mapped='bpf_map_lookup_elem' if name=='trie_lookup_elem' or name.startswith('kprog_htab_elem_') else name
  try:function=getattr(stubs,mapped);break
  except AttributeError:
   try:function=getattr(libc,mapped);break
   except AttributeError:pass
 assert function is not None,names
 address=C.cast(function,C.c_void_p).value;thunk=len(payload);payload+=b'\x48\xb8'+struct.pack('<Q',address)+b'\xff\xe0'
 at=len(prefix)+off;assert payload[at]==0xe8;struct.pack_into('<i',payload,at+1,thunk-at-5);targets.append(dict(offset=off,names=names,stub=mapped))
# Model this kernel's inline per-CPU array ABI on the isolated host thread.
# The first execution deliberately exposed the unmodelled GS access; retain
# that failure separately rather than treating it as a guest-code failure.
stubs.record_address.restype=C.c_void_p;stubs.metric_address.restype=C.c_void_p
for spec in plan['lookup_maps']:
 if spec['name'] not in maps or spec['kind']!='percpu_array':continue
 pointer=stubs.record_address() if spec['name']=='per_cpu_records' else stubs.metric_address()
 for index in range(spec['max_entries']):
  C.c_uint64.from_address(C.addressof(maps[spec['name']])+304+index*8).value=pointer
cpu_offset=next(h['addr'] for h in plan['helpers'] if h['name']=='__native_x86_this_cpu_off');signed=C.c_int64(cpu_offset).value
fake_cpu=C.c_uint64(0);old_gs=C.c_uint64();assert libc.syscall(158,0x1004,C.byref(old_gs))==0
assert libc.syscall(158,0x1001,C.c_uint64(C.addressof(fake_cpu)-signed))==0
region.write(payload);entry=C.CFUNCTYPE(C.c_int,C.c_void_p)(base)
regs=(C.c_uint64*32)();regs[16]=0x123456789;regs[17]=0x33;regs[19]=0x7fff12345678;regs[20]=0x2b
class Context(C.Structure):_fields_=[('regs',C.c_void_p),('data',C.c_void_p)]
context=Context(C.addressof(regs),0);stubs.configure_maps.argtypes=[C.c_void_p]*4+[C.c_int];returns=[]
prog=C.create_string_buffer(4096);func_offset=next(h['addr'] for h in plan['helpers'] if h['name']=='__native_x86_bpf_prog_bpf_func_offset');entry_offset=next(h['addr'] for h in plan['helpers'] if h['name']=='__native_x86_tail_call_offset')
C.c_uint64.from_address(C.addressof(prog)+func_offset).value=base+len(prefix)+len(code)+len(suffix)-entry_offset
C.c_uint32.from_address(C.addressof(maps['perf_progs'])+68).value=32
C.c_uint64.from_address(C.addressof(maps['perf_progs'])+304+8).value=C.addressof(prog)
transfers=[]
for present in [0,1,2]:
 for i in range(8,16):state[i]=0
 print('CASE',present,flush=True);stubs.configure_maps(*[C.addressof(maps[n]) for n in ['per_cpu_records','metrics','pid_page_to_mapping_info','reported_pids']],present);result=entry(C.byref(context));returns.append(result);print('RETURN',result,flush=True)
 transfers.append(dict(case=present,transferred=bool(state[12]),count=state[8],context=state[9],stack=state[10],frame=state[11],expected_context=C.addressof(context),expected_stack=bp))
 if present==2:print('TAIL_BRANCH',list(state)[8:16],'expected_counter',C.c_uint64.from_address(bp-8).value,'map',C.addressof(maps['perf_progs']),flush=True)
 if present==2:assert result==777 and state[12]==1 and state[8]==1 and state[9]==C.addressof(context) and state[10]==bp and state[11]==bp,transfers[-1]
assert libc.syscall(158,0x1001,C.c_uint64(old_gs.value))==0
(raw/'result.json').write_text(json.dumps(dict(returns=returns,transfers=transfers,targets=targets,scope='Captured actual linked code with deterministic early-path helper stubs and native ABI wrapper; no guest/full-work equivalence claim.'),indent=2)+'\n')
