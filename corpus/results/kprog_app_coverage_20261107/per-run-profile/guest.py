"""Real corpus startup; fixed-input windows controlled by host guest-only perf."""
import json,os,re,subprocess,sys,time,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');sys.path.insert(0,str(ROOT))
from runner.libs.app_runners.katran import KatranServerSession,configure_katran_maps,F_LRU_BYPASS,ensure_kernel_module_loaded,ip_command,resolve_katran_server_binary,_resolve_katran_bpf_artifact,ROUTER_LB_MAC,DEFAULT_HC_V4_TUN_IFACE,DEFAULT_HC_V6_TUN_IFACE
from runner.libs.app_runners.tetragon import TetragonRunner,inspect_tetragon_setup
HERE=Path(__file__).resolve().parent;OUT=Path(sys.argv[1]);OUT.mkdir(parents=True,exist_ok=True)
HELPER=HERE/'fixed-run';INPUT=ROOT/'corpus/inputs/katran_vip_packet_64.bin'
COUNT=int(os.environ.get('KPROG_PROFILE_COUNT','200000'));WINDOW=0

def command(argv,path=None):
 p=subprocess.run(list(map(str,argv)),capture_output=True,text=True)
 if path is not None:Path(path).write_text(json.dumps(dict(command=list(map(str,argv)),returncode=p.returncode,stdout=p.stdout,stderr=p.stderr),indent=2)+'\n')
 if p.returncode:raise RuntimeError(f'{argv}: {p.stderr} {p.stdout}')
 return p.stdout

BTF_NAMES={}
def info(ident):
 result=json.loads(command([HELPER,'info',ident,0,INPUT]));btf=result['btf_id'];typeid=result['func_type_id']
 if btf and typeid:
  if btf not in BTF_NAMES:
   text=command(['bpftool','btf','dump','id',btf,'format','raw'])
   BTF_NAMES[btf]={int(i):name for i,name in re.findall(r"^\[(\d+)\] FUNC '([^']+)'",text,re.M)}
  result['source_btf_symbol']=BTF_NAMES[btf].get(typeid)
 return result
def proglist():return json.loads(command(['bpftool','-j','prog','show']))
def publish(path,value):
 tmp=path.with_suffix('.tmp');tmp.write_text(json.dumps(value,indent=2)+'\n');tmp.replace(path)

def wait(path):
 while not path.exists():
  if (OUT/'abort').exists():raise RuntimeError('host measurement aborted')
  time.sleep(.01)

def window(app,arm,scenario,ids,kind):
 global WINDOW
 seq=WINDOW;WINDOW+=1;prefix=OUT/f'{seq:03d}-{app}-{arm}-{scenario}-{kind}';prefix.mkdir()
 argv=[HELPER,'test' if app=='katran' else 'open',ids[0] if ids else 0,COUNT,INPUT]
 before=[info(i) for i in ids]
 for i in ids:
  command([HELPER,'dump',i,0,prefix/(str(i)+'.jit.bin')],prefix/(str(i)+'.jit-dump.json'))
 (prefix/'kallsyms.txt').write_text(Path('/proc/kallsyms').read_text())
 publish(OUT/f'ready-{seq:03d}.json',dict(index=seq,prefix=str(prefix),app=app,arm=arm,scenario=scenario,kind=kind,programs=before,count=COUNT,command=list(map(str,argv))))
 wait(OUT/f'go-{seq:03d}')
 try:
  result=command(argv,prefix/'work.json')
  publish(OUT/f'done-{seq:03d}.json',dict(ok=True,result=json.loads(result)))
 except BaseException as e:
  publish(OUT/f'done-{seq:03d}.json',dict(ok=False,error=str(e)));raise
 wait(OUT/f'ack-{seq:03d}')
 after=[info(i) for i in ids]
 publish(prefix/'program-deltas.json',[dict(before=a,after=b,run_count=b['run_cnt']-a['run_cnt'],run_time_ns=b['run_time_ns']-a['run_time_ns']) for a,b in zip(before,after)])

class FixedKatran:
 # Upstream Katran server and all its program loads; TEST_RUN needs no traffic topology/NAPI workers.
 def __init__(self):self.session=None;self.artifacts={}
 def start(self):
  for mod in ('veth','tunnel4','ip_tunnel','ipip','ip6_tunnel'):ensure_kernel_module_loaded(mod)
  ip_command(['link','add','kp-prof','type','veth','peer','name','kp-peer'])
  for name,kind in [(DEFAULT_HC_V4_TUN_IFACE,'ipip'),(DEFAULT_HC_V6_TUN_IFACE,'ip6tnl')]:
   ip_command(['link','add','name',name,'type',kind,'external']);ip_command(['link','set',name,'up'])
  ip_command(['link','set','kp-prof','up']);ip_command(['link','set','kp-peer','up'])
  self.session=KatranServerSession(server_binary=resolve_katran_server_binary(),balancer_prog_path=_resolve_katran_bpf_artifact('bpf/balancer.bpf.o','balancer.bpf.o'),healthchecking_prog_path=_resolve_katran_bpf_artifact('bpf/healthchecking_ipip.bpf.o','healthchecking_ipip.bpf.o','healthchecking_ipip.o'),iface='kp-prof',default_router_mac=ROUTER_LB_MAC)
  self.session.__enter__();self.artifacts={'live_program':self.session.metadata(),'map_configuration':configure_katran_maps(self.session)}
 def stop(self):
  if self.session:self.session.close()
  for name in ['kp-prof',DEFAULT_HC_V4_TUN_IFACE,DEFAULT_HC_V6_TUN_IFACE]:ip_command(['link','del',name],check=False)

(OUT/'guest-launch.snapshot.py').write_bytes(Path(__file__).read_bytes())
for p,v in [('/proc/sys/kernel/bpf_stats_enabled','1'),('/proc/sys/net/core/bpf_jit_kallsyms','1')]:Path(p).write_text(v+'\n')
try:
 for app in ('katran','tetragon'):
  for arm in ('jit','native'):
   os.environ.update(BPFREJIT_SHIM_NATIVE_LOADER='1' if arm=='native' else '0',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='0',BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1',BPFREJIT_NATIVE_LOADER_SO='/usr/local/lib/bpfrejit/libnative_loader.so',RUN_TARGET_ARCH='x86_64',BPFREJIT_NATIVE_DISABLE_MAP_LOWERING='0',BPFREJIT_SHIM_LOG=str(OUT/f'{app}-{arm}.shim.log'))
   os.environ.pop('BPFREJIT_SHIM_NATIVE_MANIFEST',None)
   previous={p['id'] for p in proglist()}
   runner=FixedKatran() if app=='katran' else TetragonRunner(setup_result=inspect_tetragon_setup())
   try:
    runner.start();new=[p for p in proglist() if p['id'] not in previous];publish(OUT/f'{app}-{arm}-programs.json',new)
    if app=='katran':
     attach=runner.session.attach_info;publish(OUT/f'{app}-{arm}-setup.json',runner.artifacts)
     entries=attach.get('xdp',[])
     ids=[int(attach.get('prog_id') or attach.get('id') or (entries[0].get('id') if isinstance(entries,list) and entries else 0) or 0)]
     if not ids[0]:raise RuntimeError(f'no attached XDP id: {attach}')
     if info(ids[0])['type']!=6:raise RuntimeError('selected program is not XDP')
     for scenario,flags in [('vip-hit-lru-bypass',F_LRU_BYPASS),('vip-hit-warm-lru',0)]:
      configure_katran_maps(runner.session,flags=flags)
      command([HELPER,'test',ids[0],100,INPUT],OUT/f'{app}-{arm}-{scenario}-warmup.json')
      for kind in ('stat','record'):window(app,arm,scenario,ids,kind)
    else:
     ids=[p['id'] for p in new if p.get('name','').startswith('generic_kprobe_') and p.get('type')=='kprobe']
     if arm=='jit':ids=[i for i in ids if info(i).get('source_btf_symbol')=='generic_kprobe_event']
     if arm=='native':
      text=Path(os.environ['BPFREJIT_SHIM_LOG']).read_text();active=set(map(int,re.findall(r'native-loader replaced .*?native_id=(\d+) .*?symbol=generic_kprobe_event(?: |$)',text,re.M)));ids=[i for i in ids if i in active]
     if not ids:raise RuntimeError('no real generic_kprobe program IDs')
     command([HELPER,'smoke',ids[0],1,INPUT],OUT/f'{app}-{arm}-test-run-capability.json')
     for kind in ('stat','record'):window(app,arm,'open-dev-null',ids,kind)
   finally:runner.stop()
 publish(OUT/'guest-complete.json',dict(ok=True,windows=WINDOW))
except BaseException as e:
 publish(OUT/'guest-complete.json',dict(ok=False,error=str(e),traceback=traceback.format_exc()));raise
