"""Compile the untouched real-header IR through canonical common context LTO."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BASE=OUT.parent
phase=sys.argv[1];assert phase in ['before','before-controls','after'];DEST=OUT/phase;DEST.mkdir(exist_ok=False);os.sched_setaffinity(0,{19})
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,commands=[],cases=[])
def run(name,args,expected=None):
 with (DEST/(name+'.log')).open('xb') as f:p=subprocess.run([str(x) for x in args],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=limits)
 r['commands'].append(dict(name=name,args=[str(x) for x in args],returncode=p.returncode));assert expected is None or p.returncode==expected,(name,p.returncode);return p.returncode
try:
 old=json.loads((BASE/'before-isolated/controller.json').read_text());compiler=ROOT/'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto';r['compiler']=dict(path=str(compiler),bytes=compiler.stat().st_size,sha256=sha(compiler));r['header_sha256']=sha(ROOT/'vendor/bpf/cilium/bpf/include/bpf/ctx/xdp.h');assert r['header_sha256']=='93bffd9691f1564c03d7b778ce57b20b80d4cecf3183e2c57ba23e97e9769911'
 for row in old['cases']:
  arch=row['architecture'];ir=DEST/(arch+'-input.o');args=row['compile_command'].copy();args[-1]=str(ir);args[-3]=str(OUT/'accessors.c');args[1:1]=['-Xclang','-fembed-bitcode=all'];run(arch+'-embed',args,0)
  btf=Path(f'/workspaces/.agent-state/kprog-ck/build-{arch}/vmlinux');r.setdefault('btf',{})[arch]=dict(path=str(btf),sha256=sha(btf))
  tools=[('host',[str(compiler)])]
  if phase=='after' and arch=='arm64':tools.append(('arm-native',['qemu-aarch64-static','-L',str(ROOT/'.cache/qemu-arm64-root'),str(ROOT/'vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto')]))
  for tool,prefix in tools:
   for entry,expected_value in [('native_ifindex',34),('native_ingress',34),('native_physical_upper',17),('native_local_copy',51)]:
    label=arch+'-'+tool+'-'+entry;obj=DEST/(label+'.o');command=prefix+[str(ir),'--symbol',entry,'--kernel-btf',str(btf),'--prog-type','6','-o',str(obj)]
    if arch=='x86':command.insert(len(prefix),'--x86-cmov-converter-force-all')
    run(label+'-lto',command,0)
    output=DEST/(label+'.elf');driver=row['driver_compile_command'].copy();i=driver.index(str(BASE/'ifindex_driver.c'));driver[i]=str(OUT/'driver.c');driver[i+1]=str(obj);driver[-1]=str(output);driver.insert(1,'-DENTRY='+entry);driver.insert(1,'-DEXPECTED_VALUE='+str(expected_value));run(label+'-driver',driver,0)
    command=[str(output)] if arch=='x86' else ['qemu-aarch64-static',str(output)];p=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE);(DEST/(label+'-stdout.txt')).write_bytes(p.stdout);(DEST/(label+'-stderr.txt')).write_bytes(p.stderr);case=dict(architecture=arch,tool=tool,entry=entry,execute_returncode=p.returncode);r['cases'].append(case);case['values']=json.loads(p.stdout);case['regression_passed']=p.returncode==0 and case['values']['value']==expected_value
    run(label+'-disassembly',[('objdump' if arch=='x86' else 'aarch64-linux-gnu-objdump'),'-d',str(obj)],0)
 r.update(controller_status=0,regression_passed=all(x['regression_passed'] for x in r['cases']),scope='Untouched actual-header embedded IR, canonical common compiler, actual canonical kernel BTF, actual host/ARM-user execution. No kernel/image/loader activation or frozen workload claim.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:
 r['ended_utc']=now();r['files']={p.name:dict(bytes=p.stat().st_size,sha256=sha(p)) for p in DEST.iterdir() if p.is_file() and p.name!='controller.json'};(DEST/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
raise SystemExit(r['controller_status'])
