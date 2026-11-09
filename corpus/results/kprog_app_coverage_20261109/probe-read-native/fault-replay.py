from pathlib import Path
import subprocess,json,sys,os,tarfile,shutil,hashlib,resource,traceback
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/probe-read-native';G=Path('/var/tmp/kprog-tmp/C/probe-read-fault');C=Path('/workspaces/.agent-state/kprog-lanes/C');V=C/'design-only/remaining-apps/probe-read-fault';G.mkdir(exist_ok=True)
def state(**d):(G/'status.json').write_text(json.dumps(d,indent=2)+'\n')
def run(cmd,name):
 (G/(name+'.command.json')).write_text(json.dumps([str(x)for x in cmd],indent=2)+'\n')
 with(G/(name+'.log')).open('w')as f:p=subprocess.run([str(x)for x in cmd],cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (G/(name+'.exit')).write_text(str(p.returncode)+'\n');return p
try:
 if len(sys.argv)>2 and sys.argv[2]=='mount':
  V.mkdir(parents=True,exist_ok=True);subprocess.run(['mount','--bind',str(G),str(V)],check=True)
  subprocess.run(['mount','--bind',str(G/'link-alias'),str(R/'kprog/x86/native_lab/native_link')],check=True)
  os.execvp(sys.argv[3],sys.argv[3:])
 h=sys.argv[1];E=G/('committed-'+h[:12]);E.mkdir();files=['vendor/bpf/native_compat.h','kprog/test/native_load_fault/probe.cpp','kprog/libnativeloader/include/native_loader.hpp']+[str(O.relative_to(R)/n)for n in ['fault-subject.c','fault-guest.py','fault-replay.py']]
 p=subprocess.Popen(['git','archive',h,'--',*files],cwd=R,stdout=subprocess.PIPE)
 with tarfile.open(fileobj=p.stdout,mode='r|')as t:t.extractall(E,filter='data')
 p.stdout.close();p.wait()
 for p in E.rglob('*'):
  if p.is_file():p.chmod(0o444)
 for p in sorted([p for p in E.rglob('*')if p.is_dir()],key=lambda p:len(p.parts),reverse=True):p.chmod(0o555)
 E.chmod(0o555);shutil.copytree('/var/tmp/kprog-tmp/C/coherent-six-app-runtime/runtime',G/'runtime',dirs_exist_ok=True)
 alias=G/'link-alias/target/release';alias.mkdir(parents=True,exist_ok=True);shutil.copy2(G/'runtime/native-link',alias/'native-link')
 with tarfile.open(R/'corpus/results/kprog_app_coverage_20261109/smap-recovery/live-null/raw.tar.gz')as t:(G/'native_load_fault_module.ko').write_bytes(t.extractfile('native_load_fault_module.ko').read())
 state(state='building_four_original_module_replay_variants',source_commit=h)
 with(G/'vmlinux.h').open('w')as f:subprocess.run([str(R/'vendor/build/x86/bpftool/bin/bpftool'),'btf','dump','file','/var/tmp/kprog-tmp/C/master-x86-runtime/kernel-build/vmlinux','format','c'],stdout=f,check=True)
 for width in [1,2,4,8]:
  cmd=['clang-18','-O3','-g','-fPIC','-c','-DMICRO_NATIVE','-DMICRO_NATIVE_HELPER_MACROS','-D__TARGET_ARCH_x86','-DPROBE_WIDTH='+str(width),'-include',E/'vendor/bpf/native_compat.h','-I',G,'-march=native','-mgeneral-regs-only','-mno-red-zone','-mretpoline-external-thunk','-mfunction-return=thunk-extern','-fcf-protection=branch','-fno-stack-protector','-fno-asynchronous-unwind-tables','-fno-unwind-tables','-fno-jump-tables','-fno-optimize-sibling-calls',E/O.relative_to(R)/'fault-subject.c','-o',G/('width'+str(width)+'.native.o')];run(cmd,'compile'+str(width)).check_returncode()
 run(['g++','-std=c++20','-O2','-I'+str(R/'runner/build-llvmbpf/vendor/libbpf/prefix/include'),E/'kprog/test/native_load_fault/probe.cpp','/var/tmp/kprog-tmp/C/single-load-attempt/build/libnative_loader.a',R/'runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a','-lelf','-lz','-ldl','-pthread','-o',G/'probe'],'probe-build').check_returncode()
 state(state='unbound_producer_semantics_guest',source_commit=h)
 guest='mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; python3 '+str(V/E.name/O.relative_to(R)/'fault-guest.py')+' '+str(V)
 cmd=['unshare','--mount','--propagation','private','python3',O/'fault-replay.py',h,'mount','taskset','-c','20-23','vng','--run','/var/tmp/kprog-tmp/C/master-x86-runtime/kernel-build/arch/x86/boot/bzImage','--cwd',R,'--rwdir',R,'--rwdir',V,'--overlay-rwdir','/tmp','--overlay-rwdir','/run','--disable-monitor','--cpus','4','--memory','2G','--append','loglevel=4 panic=30 oops=panic','--exec',guest]
 p=run(cmd,'guest');rows=json.loads((G/'outcomes.json').read_text())if(G/'outcomes.json').exists()else[]
 result=dict(source_commit=h,guest_exit=p.returncode,widths=rows,mode='unbound native producer semantics with original guest module; separate from generation-bound acceptance',matched_runtime={n:hashlib.sha256((G/'runtime'/n).read_bytes()).hexdigest()for n in ['native-link','bpf_x86_native_lab.ko']});D=O/'fault-replay';D.mkdir(exist_ok=True);(D/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
 with tarfile.open(D/'raw.tar.gz','w:gz')as t:
  for q in G.iterdir():
   if q.name!='status.json':t.add(q,arcname=q.name)
 (D/'README.md').write_text('# Protected native probe-read actual guest semantics\n\nOriginal published live/NULL module, probe driver and control expectations retain their bytes. Four native P variants use the current producer wrapper at1/2/4/8byte widths. Live input checks an odd file-position value, legitimate zero data and original-helper NULL-address error; NULL input routes through a high unmapped source ending at address wraparound. Return codes and cleared output words are folded into the original module control/null results. The unbound load arm measures actual producer semantics with stock exception-table recovery; generation-bound acceptance remains separate. Every width and guest result stays in summary.json/raw.\n')
 sys.path.insert(0,str(O.parent));from publish_owned import publish
 commit=publish([str(q.relative_to(R))for q in D.iterdir()if q.is_file()],'Replay protected native probe reads with the original live and NULL module',G/'publication.json');state(state='finished',commit=commit,result=result)
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/V/A '+datetime.now(timezone.utc).isoformat()+': PUSHED '+commit+' protected probe-read producer semantic guest actual '+repr(result)+'. Original live/NULL module/probe expectations retained; four widths cover valid odd/zero, original helperNULL arm and protected high-address wraparound fault. Unbound semantics receipt stays separate from bound acceptance.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
