from pathlib import Path
import subprocess,sys,os,json,hashlib,tarfile,shutil,gzip,traceback,resource
from datetime import datetime,timezone
from elftools.elf.elffile import ELFFile
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/probe-read-native';G=Path('/var/tmp/kprog-tmp/C/probe-read-native');G.mkdir(exist_ok=True)
header=R/'vendor/bpf/native_compat.h';plugin=G/'native_division.so'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def state(**x):(G/'status.json').write_text(json.dumps(x,indent=2)+'\n')
def build(profile):
 D=G/profile;D.mkdir(exist_ok=True);native=D/'native';names=['tracee.native.o','lsm_support/lsm_check.native.o','lsm_support/kprobe_check.native.o']
 cmd=['make','-C',str(R/'vendor/bpf'),*[str(native/'tracee'/n)for n in names],'ARCH=x86','KERNEL_RELEASE=7.0.0-rc2+','NATIVE_OUT='+str(native),'NATIVE_DIVISION_PLUGIN='+str(plugin),'CLANG=clang-18','LLVM_CONFIG=llvm-config-18','LLVM_NM=llvm-nm-18'];(D/'command.json').write_text(json.dumps(cmd,indent=2)+'\n');(D/'header.sha256').write_text(sha(header)+'\n')
 with(D/'build.log').open('w')as f:p=subprocess.run(cmd,cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (D/'build.exit').write_text(str(p.returncode)+'\n');p.check_returncode();payload=D/'payload';payload.mkdir(exist_ok=True)
 for n in names:shutil.copy2(native/'tracee'/n,payload/Path(n).name)
 cmd=['python3',str(R/'vendor/bpf/write_native_manifest.py'),'--app','tracee','--llvm-nm','llvm-nm-18','--dedupe-program','last','--output',str(payload/'manifest.json')]
 for n in ['tracee.native.o','kprobe_check.native.o','lsm_check.native.o']:cmd+=['--object',str(payload/n)]
 with(D/'manifest.log').open('w')as f:subprocess.run(cmd,cwd=R,check=True,stdout=f,stderr=subprocess.STDOUT)
 rows=[]
 for p in sorted(payload.glob('*.native.o')):
  with p.open('rb')as f:code_bytes=sum(int(s['sh_size'])for s in ELFFile(f).iter_sections()if int(s['sh_flags'])&4)
  text=subprocess.check_output(['llvm-objdump-18','-d',str(p)],text=True)
  with gzip.open(D/(p.name+'.disassembly.gz'),'wt')as f:f.write(text)
  rows.append(dict(object=p.name,sha256=sha(p),executable_bytes=code_bytes,rep_movs_sites=sum('rep' in l and 'movs' in l for l in text.splitlines())))
 result=dict(header_sha256=sha(header),objects=rows,manifest_entries=len(json.loads((payload/'manifest.json').read_text())['objects']));(D/'summary.json').write_text(json.dumps(result,indent=2)+'\n');return result
try:
 if len(sys.argv)>1 and sys.argv[1]=='control':
  subprocess.run(['mount','--bind',str(G/'parent/vendor/bpf/native_compat.h'),str(header)],check=True);build('control');raise SystemExit(0)
 parent=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip();(G/'parent').mkdir(exist_ok=True)
 p=subprocess.Popen(['git','archive',parent,'--','vendor/bpf/native_compat.h'],cwd=R,stdout=subprocess.PIPE)
 with tarfile.open(fileobj=p.stdout,mode='r|')as t:t.extractall(G/'parent',filter='data')
 p.stdout.close();p.wait()
 for p in (G/'parent').rglob('*'):
  if p.is_file():p.chmod(0o444)
 for p in sorted([p for p in(G/'parent').rglob('*')if p.is_dir()],key=lambda p:len(p.parts),reverse=True):p.chmod(0o555)
 (G/'parent').chmod(0o555);shutil.copy2('/var/tmp/kprog-tmp/C/katran-regression-current/producer/native_division.so',plugin)
 inputs=dict(parent=parent,native_header_sha256=sha(header),control_header_sha256=sha(G/'parent/vendor/bpf/native_compat.h'),plugin_sha256=sha(plugin),source_sha256={str(p.relative_to(R)):sha(p)for p in[R/'vendor/bpf/tracee/pkg/ebpf/c/tracee.bpf.c',*sorted((R/'vendor/bpf/tracee/pkg/ebpf/c/lsmsupport').glob('*.bpf.c'))]});(G/'inputs.json').write_text(json.dumps(inputs,indent=2)+'\n')
 state(state='matched_control_compile',inputs=inputs)
 with(G/'control-controller.log').open('w')as f:subprocess.run(['unshare','--mount','--propagation','private','python3',str(O/'producer.py'),'control'],cwd=R,stdout=f,stderr=subprocess.STDOUT,check=True)
 state(state='complete_candidate_compile',inputs=inputs);candidate=build('candidate');control=json.loads((G/'control/summary.json').read_text());result=dict(inputs=inputs,control=control,candidate=candidate);(O/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
 patch=subprocess.check_output(['git','diff','HEAD','--','vendor/bpf/native_compat.h'],cwd=R);(O/'candidate.patch').write_bytes(patch)
 with tarfile.open(O/'payload.tar.gz','w:gz')as t:
  for n in ['inputs.json','control','candidate','native_division.so','control-controller.log']:t.add(G/n,arcname=n)
 (O/'README.md').write_text('# Native P protected probe-read candidate\n\nThe native-only helper wrapper lowers constant1/2/4/8byte kernel reads to one REP MOVS element at the same access width. Existing exception recovery skips a faulting element and clears its destination. Success uses source advancement together with zero remaining count; this distinguishes legitimate zero data and wrapped source addresses from faults. Failure clears the complete destination and returns-EFAULT. Existing x86 maccess address eligibility routes user/vsyscall addresses through the original helper; other sizes retain their original call. Kernel after-verification code and submitted P bytes retain their definitions.\n\nBoth complete3object Tracee payloads use the same current source, flags and division plugin. The control reads its header from a read-only committed export in a private mount namespace; the candidate uses the master edit. The original Tracee C/JIT source retains its paired09f40 definition. summary.json records every object/hash/REP site and full manifest count; payload.tar.gz carries both complete manifests, all objects, command/build/disassembly logs and plugin. Actual fault and application work replays remain separate from compiler observations.\n')
 sys.path.insert(0,str(O.parent));from publish_owned import publish
 commit=publish(['vendor/bpf/native_compat.h']+[str(p.relative_to(R))for p in O.iterdir()if p.is_file()],'Compile complete Tracee P with protected fixed-width probe reads',G/'publication.json');state(state='payload_published',commit=commit,result=result)
 with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a')as f:f.write('\n### Timing request: complete Tracee protected probe-read P '+commit+'\n\nR: full matched-control/candidate3object manifests, native_division.so and raw compile/disassembly in corpus/results/kprog_app_coverage_20261109/probe-read-native/payload.tar.gz. Live /var/tmp/kprog-tmp/C/probe-read-native/{control,candidate}/payload. Native-only constant1/2/4/8byte probe reads become a protected single REP element before submission; helper-domain/zeroing/error semantics retained, other reads retain helper. Same original09f40 paired C/JIT/source and compiler flags/plugin in both arms; frozen workload/framework retain bytes. Time unbound candidate/control/JIT on0-7 with existing common Makefile, both stats modes and3x180s. Record replacements/fallbacks, events/samples, lost/drop reasons, invocations/time, latency and CPU. Guest fault/wholeapp replay follows independently; compiler observations remain distinct from runtime equivalence.\n')
except SystemExit:raise
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
