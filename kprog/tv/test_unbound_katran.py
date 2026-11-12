"""Actual upstream Katran startup regression; no direct loading of app .bpf.o."""
import hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[2]
def check_unbound_stub(raw):
    if len(raw)%8:raise RuntimeError('truncated native stub')
    instructions=list(struct.iter_unpack('<BBhi',raw))
    if len(instructions)%2!=1 or len(instructions)<5:
        raise RuntimeError('expected multiple sidecar/call pairs plus EXIT')
    count=(len(instructions)-1)//2
    if instructions[-1]!=(0x95,0,0,0):raise RuntimeError('missing final EXIT')
    kfunc=instructions[1][3]
    if kfunc<=0:raise RuntimeError('missing module kfunc BTF identity')
    for i in range(count):
        # src=SIDECAR3, ABI mask15, sequential slot, generation zero.
        if instructions[2*i]!=(0xb7,0x30,15|(i<<4),0):
            raise RuntimeError('not a sequential generation-zero mask15 sidecar')
        if instructions[2*i+1]!=(0x85,0x40,1,kfunc):
            raise RuntimeError('not the matching module kinsn call')
    return count

if sys.argv[1]=='--check-stub':
    print('unbound Katran stub: PASS',check_unbound_stub(Path(sys.argv[2]).read_bytes()),'chunks')
    raise SystemExit(0)

if sys.argv[1]=='--prepare':
    inputs=Path(sys.argv[2]);inputs.mkdir(parents=True,exist_ok=True)
    libs=inputs/'lib';libs.mkdir(exist_ok=True)
    image='bpf-benchmark/kprog:current'
    name='kprog-tv-unbound-inputs-'+str(os.getpid())
    subprocess.run(['docker','create','--name',name,image,'true'],check=True,stdout=subprocess.DEVNULL)
    try:
        subprocess.run(['docker','cp',name+':/artifacts/user/repo-artifacts/x86_64/katran/bin/katran_server_grpc',str(inputs/'katran_server_grpc')],check=True)
        while True:
            env=dict(os.environ,LD_LIBRARY_PATH=str(libs))
            result=subprocess.run(['ldd',str(inputs/'katran_server_grpc')],env=env,text=True,capture_output=True,check=True)
            missing=re.findall(r'^\s*(\S+) => not found',result.stdout,re.M)
            if not missing:break
            for lib in missing:
                target=libs/lib
                if target.exists():raise RuntimeError('unresolved copied library '+lib)
                subprocess.run(['docker','cp','-L',name+':/usr/lib/x86_64-linux-gnu/'+lib,str(target)],check=True)
        (inputs/'ldd.txt').write_text(result.stdout)
        (inputs/'image.json').write_text(subprocess.check_output(['docker','inspect',image],text=True))
    finally:subprocess.run(['docker','rm',name],check=True,stdout=subprocess.DEVNULL)
    raise SystemExit(0)

sys.path.insert(0,str(ROOT))
from runner.libs.app_runners.katran import KatranServerSession
OUT=ROOT/'kprog/tv/build'/('unbound-katran-run-'+datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ'))
OUT.mkdir()
inputs=Path(sys.argv[1]);shimlog=OUT/'katran-shim.log'
if shimlog.exists():raise RuntimeError('refusing to overwrite prior Katran regression log')
os.environ.update(LD_LIBRARY_PATH=str(inputs/'lib'),
 BPFREJIT_SHIM_NATIVE_LOADER='1',
 BPFREJIT_SHIM_NATIVE_MANIFEST=str(ROOT/'vendor/build/native-bpf/x86/stage/katran/manifest.json'),
 BPFREJIT_NATIVE_LOADER_SO=str(ROOT/'kprog/libnativeloader/build/libnative_loader.so'),
 BPFREJIT_NATIVE_LINK_BINARY=str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'),
 LD_PRELOAD=str(ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so'),
 BPFREJIT_SHIM_LOG=str(shimlog),BPFTOOL_BIN=str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'))
for key in ('BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF','BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF'):
 os.environ.pop(key,None)
# A load/attach test needs only the upstream server's interface, not workload topology.
subprocess.run(['ip','link','add','tvkatran0','type','veth','peer','name','tvkatran1'],check=True)
subprocess.run(['ip','link','set','tvkatran0','up'],check=True)
subprocess.run(['ip','link','set','tvkatran1','up'],check=True)
result=dict(ok=False,scope='Actual upstream Katran server startup/unbound loader load+attach; no timing or workload claim.')
session=KatranServerSession(server_binary=inputs/'katran_server_grpc',
 balancer_prog_path=ROOT/'vendor/build/x86/katran/bpf/balancer.bpf.o',
 healthchecking_prog_path=ROOT/'vendor/build/x86/katran/bpf/healthchecking_ipip.bpf.o',
 iface='tvkatran0',default_router_mac='02:00:00:00:00:01')
try:
 with session:
  result['metadata']=session.metadata()
  result['server_output']=session.collector_snapshot()
  text=shimlog.read_text()
  native=[line for line in text.splitlines() if 'native-loader replaced' in line and 'prog=balancer_ingres' in line]
  if len(native)!=1:raise RuntimeError('expected exactly one native balancer replacement: '+text[-4000:])
  line=native[0]
  timings=[line for line in text.splitlines() if 'native-loader timings prog=balancer_ingres ' in line]
  if len(timings)!=1 or 'bound_required=0' not in timings[0]:
   raise RuntimeError('expected unbound Katran timing receipt')
  native_id=int(re.search(r'native_id=(\d+)',line)[1])
  raw=OUT/'katran-stub.bin'
  subprocess.run([os.environ['BPFTOOL_BIN'],'prog','dump','xlated','id',str(native_id),'file',str(raw)],check=True)
  chunks=check_unbound_stub(raw.read_bytes())
  result.update(ok=True,balancer_receipt=line,timings_receipt=timings[0],proof_bound=False,
   chunks=chunks,abi_mask=15,generation=0,xlated_size=raw.stat().st_size,
   xlated_sha256=hashlib.sha256(raw.read_bytes()).hexdigest())

finally:
 result['source_sha256']={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in
  [ROOT/'vendor/build/x86/katran/bpf/balancer.bpf.o',ROOT/'vendor/build/native-bpf/x86/stage/katran/balancer.native.o',
   ROOT/'kprog/tv/build-x86/bpf_x86_native_lab.ko',ROOT/'kprog/tv/build-kernel-x86/arch/x86/boot/bzImage']}
 (OUT/'katran.json').write_text(json.dumps(result,indent=2)+'\n')
 subprocess.run(['ip','link','del','tvkatran0'],check=True)
print(json.dumps(dict(ok=result['ok'],chunks=result['chunks'],generation=result['generation'],abi_mask=result['abi_mask'],output=str(OUT))),flush=True)
