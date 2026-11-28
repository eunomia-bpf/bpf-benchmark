"""Build canonical common components and execute provenance-sensitive context cases."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;os.sched_setaffinity(0,{19})
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,stages=[])
def save():(OUT/'core-controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(name,args,env=None):
 p=OUT/(name+'.log');start=now()
 with p.open('xb') as f:c=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=limits,env=env)
 r['stages'].append(dict(name=name,args=args,started_utc=start,ended_utc=now(),returncode=c.returncode,cpu=16,address_space_bytes=48*1024**3,log=dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=sha(p))));save();return c.returncode
try:
 prep=json.loads((OUT/'fix-preparation.json').read_text());r['source_sha256']=prep['source_sha256']
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 header=ROOT/'vendor/bpf/cilium/bpf/include/bpf/ctx/xdp.h';assert sha(header)=='93bffd9691f1564c03d7b778ce57b20b80d4cecf3183e2c57ba23e97e9769911';save()
 tool={}
 for arch in ['x86','arm64']:tool[arch]=run(arch+'-context-build',['make','-C','vendor/bpf','ARCH='+arch,str(ROOT/f'vendor/build/native-bpf/{arch}/stage/kprog-perf-context-lto'),'-j1'])
 target=['make','-C','kprog/results/arm64-common-flags-20261126'];host=run('host-linker-build',target+['native-link-build'])
 if host==0:run('existing-linker-tests',target+['native-link-tests'],dict(os.environ,RUST_TEST_THREADS='1'))
 run('arm-linker-build',target+['native-link-arm-build'])
 for arch,d in [('x86','runner/build-llvmbpf'),('arm64','runner/build-arm64-llvmbpf')]:run(arch+'-loader-build',['make','-C',d,'native_loader','native_loader_shared','trusted-native-loader','-j1'])
 if all(x==0 for x in tool.values()):run('actual-context-after',['make','-C',str(OUT.relative_to(ROOT)),'after'])
 after=OUT/'after/controller.json'
 if after.exists():
  a=json.loads(after.read_text());r['context_cases']=a['cases'];r['context_regression_passed']=a.get('regression_passed',False)
 r['products']={}
 paths=['vendor/build/native-bpf/x86/stage/kprog-perf-context-lto','vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto','kprog/x86/native_lab/native_link/target/release/native-link','kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link']
 for d in ['runner/build-llvmbpf/native_loader','runner/build-arm64-llvmbpf/native_loader']:paths += [str(p.relative_to(ROOT)) for p in (ROOT/d).glob('*') if p.is_file() and (p.name=='trusted-native-loader' or p.name.startswith('libnative_loader'))]
 for n in paths:p=ROOT/n;r['products'][n]=dict(bytes=p.stat().st_size,sha256=sha(p))
 for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
 assert sha(header)=='93bffd9691f1564c03d7b778ce57b20b80d4cecf3183e2c57ba23e97e9769911'
 r['controller_status']=0 if all(x['returncode']==0 for x in r['stages']) and r.get('context_regression_passed',False) else 1
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
