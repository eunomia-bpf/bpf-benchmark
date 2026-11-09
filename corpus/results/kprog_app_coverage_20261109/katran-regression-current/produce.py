from pathlib import Path
import subprocess,json,sys,hashlib,tarfile,traceback,shlex,resource
from elftools.elf.elffile import ELFFile
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');G=Path('/var/tmp/kprog-tmp/C/katran-regression-current/producer');O=R/'corpus/results/kprog_app_coverage_20261109/katran-regression-current';plugin=G/'native_division.so';commands=[]
def run(cmd,name):
 cmd=[str(x)for x in cmd];commands.append(dict(command=cmd,log=name));(G/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 with(G/(name+'.log')).open('w')as f:p=subprocess.run(cmd,cwd=R,stdout=f,stderr=subprocess.STDOUT)
 (G/(name+'.exit')).write_text(str(p.returncode)+'\n');p.check_returncode()
try:
 (G/'status.json').write_text(json.dumps(dict(state='building_full_katran_producer'))+'\n')
 objs=[G/'native/katran'/(n+'.native.o')for n in ['balancer','healthchecking','healthchecking_ipip','xdp_root']]
 run(['make','-C',R/'vendor/bpf',*objs,'ARCH=x86','KERNEL_RELEASE=7.0.0-rc2+','NATIVE_OUT='+str(G/'native'),'NATIVE_DIVISION_PLUGIN='+str(plugin),'CLANG=clang-18','LLVM_CONFIG=llvm-config-18','LLVM_NM=llvm-nm-18'],'native')
 old=Path('/var/tmp/kprog-tmp/C/native-constant-division')
 run(['clang-18','-O3','-fPIC','-fpass-plugin='+str(plugin),'-c',old/'division-subject.c','-o',G/'division-subject.o'],'scalar-compile')
 run(['gcc','-O2',old/'division-oracle.c',G/'division-subject.o','-o',G/'division-oracle'],'scalar-link');run([G/'division-oracle'],'scalar-oracle')
 run(['python3',R/'vendor/bpf/write_native_manifest.py','--app','katran','--llvm-nm','llvm-nm-18','--output',G/'native/katran/manifest.json',*[v for obj in objs for v in ['--object',obj]]],'manifest')
 rows=[]
 for obj in objs:
  with obj.open('rb')as f:
   elf=ELFFile(f);sections=[dict(name=s.name,bytes=s['sh_size'],sha256=hashlib.sha256(s.data()).hexdigest())for s in elf.iter_sections()if s['sh_flags']&4 and s['sh_size']]
  rows.append(dict(object=obj.name,sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),sections=sections))
 result=dict(objects=rows,plugin_source_sha256=hashlib.sha256((R/'vendor/bpf/native_division.cpp').read_bytes()).hexdigest(),plugin_sha256=hashlib.sha256(plugin.read_bytes()).hexdigest(),scalar_oracle=(G/'scalar-oracle.log').read_text().strip(),known_accepted_P='ba252e0372d100f34b60a0deb3f0a7ccc16b632c3c1a5eb40e9b13d31e558c20',unselected_control_P='36f3daf9b98a3907d9a87307ab21133acf1225da88421035c4bb65f3dc95f751')
 (G/'summary.json').write_text(json.dumps(result,indent=2)+'\n');(O/'producer.json').write_text(json.dumps(result,indent=2)+'\n')
 with tarfile.open(O/'producer.tar.gz','w:gz')as t:
  for n in ['native','native_division.so','commands.json','summary.json','native.log','native.exit','manifest.log','manifest.exit','scalar-compile.log','scalar-link.log','scalar-oracle.log','division-subject.o','division-oracle']:t.add(G/n,arcname=n)
 (G/'status.json').write_text(json.dumps(dict(state='finished',objects=len(rows),scalar_oracle=result['scalar_oracle']),indent=2)+'\n')
except BaseException as e:(G/'status.json').write_text(json.dumps(dict(state='requires_continuation',error=str(e),traceback=traceback.format_exc()),indent=2)+'\n');raise
