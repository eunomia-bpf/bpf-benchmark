"""Offline paired re-emission of captured P, with and without its frozen scalar facts."""
import fcntl,hashlib,json,os,resource,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
token=now().replace('-','').replace(':','');out=HERE/('frozen-ir-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127')/('frozen-ir-'+token);raw.mkdir()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,raw=str(raw),scope='Offline same-P same-compiler no-facts/frozen-facts experiment. No installed-native or performance claim; no production, image, kernel or benchmark changes.')
def save():(out/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(label,cmd):
 r.setdefault('commands',[]).append(dict(label=label,argv=list(map(str,cmd))));save()
 with (raw/(label+'.log')).open('wb') as f:rc=subprocess.run(list(map(str,cmd)),stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT).returncode
 r['commands'][-1]['returncode']=rc;save();assert rc==0,(label,rc)
try:
 save();(LANE/'otel-frozen-ir.json').write_text(json.dumps(dict(result=str(out),raw=str(raw),pid=os.getpid()),indent=2)+'\n')
 locks=[]
 for name in ['timing','image']:
  p=Path('/workspaces/.agent-state/kprog-lanes/locks')/name
  f=p.open('a');fcntl.flock(f,fcntl.LOCK_SH|fcntl.LOCK_NB);locks.append(f)
 resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16})
 profile=Path(json.loads((LANE/'otel-performance-profile.json').read_text())['result']);pc=json.loads((profile/'controller.json').read_text());cap=Path(pc['raw'])/'linkcache/native_kernel_link_cache'
 proof=next(p for p in cap.glob('*.proof.o') if any(x.split()[-1:]==['perf_unwind_native'] for x in subprocess.check_output(['llvm-nm-18','--defined-only',str(p)],text=True).splitlines()))
 plan=next(cap.glob(proof.stem.split('.')[0]+'*.link-plan.json'));facts={v['name']:v['hex'] for v in json.loads(plan.read_text())['const_values']};(raw/'immutable.json').write_text(json.dumps(facts,indent=2)+'\n')
 source=ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o';p=raw/'input.native.o';p.write_bytes(source.read_bytes());linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link';compiler=ROOT/'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto';kernel=Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
 r.update(profile=str(profile),captured_proof=str(proof),captured_proof_sha256=sha(proof),input_sha256=sha(p),compiler_sha256=sha(compiler),linker_sha256=sha(linker),kernel_btf_sha256=sha(kernel),facts=facts);save()
 extracted=raw/'source.proof.o';run('identity',[linker,'--input',p,'--symbol','perf_unwind_native','--mode','proof','--output',extracted]);r['source_proof_sha256']=sha(extracted);r['same_captured_P']=sha(extracted)==sha(proof);save();assert r['same_captured_P'],'staged P does not reproduce captured selected-entry proof'
 for label in ['no-facts','frozen-facts']:
  target=raw/(label+'.o');cmd=[compiler,'--x86-cmov-converter-force-all',p,'--symbol','perf_unwind_native','--kernel-btf',kernel,'--prog-type','0','-o',target]
  if label=='frozen-facts':cmd+=['--immutable-globals',raw/'immutable.json']
  run(label,cmd);assembly=subprocess.check_output(['llvm-objdump-18','-d','--no-show-raw-insn',str(target)],text=True);(out/(label+'.dis')).write_text(assembly)
  undefined=subprocess.check_output(['llvm-nm-18','--undefined-only',str(target)],text=True);r.setdefault('outputs',{})[label]=dict(bytes=target.stat().st_size,sha256=sha(target),debug_symbol_remaining='bpf_trace_printk' in undefined,frozen_flag_remaining='with_debug_output' in undefined,undefined_symbols=undefined.splitlines());save()
 r['controller_status']=0
except Exception:r.update(controller_status=1,exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
