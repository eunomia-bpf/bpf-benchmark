from pathlib import Path
import subprocess,json,re,tarfile,sys,resource
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/katran-regression-current';G=Path('/var/tmp/kprog-tmp/C/katran-regression-current');E=Path('/var/tmp/kprog-tmp/C/katran-regression-runtime/committed-044d32e09e21')
# Consume the generated C without modifying it; committed include files replace live headers in this private namespace.
for p in E.rglob('*'):
 if p.is_file() and (R/p.relative_to(E)).is_file():subprocess.run(['mount','--bind',str(p),str(R/p.relative_to(E))],check=True)
D=G/'compiler-o2';D.mkdir(exist_ok=True);source=G/'native-context/generated/trusted_x86.bpf.c';obj=D/'trusted_x86.bpf.o';cmd=['/usr/lib/llvm-18/bin/clang','-g','-O2','-mcpu=v4','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I',str(R/'vendor/libbpf/include/uapi'),'-I',str(R/'vendor/libbpf/src'),'-I','/usr/include/x86_64-linux-gnu','-c',str(source),'-o',str(obj)]
with(D/'compile.log').open('w')as f:p=subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT)
r=dict(source_commit='044d32e09e21e8fd885517fffaa5c12125fe8a30',command=cmd,compiler_exit=p.returncode)
if obj.exists():
 text=subprocess.check_output(['llvm-objdump-18','-d',str(obj)],text=True);(D/'disassembly.txt').write_text(text);offsets=[int(x,16)for x in re.findall(r'r10 - 0x([0-9a-f]+)',text)];r.update(stack_max_byte_offset=max(offsets,default=0),object_bytes=obj.stat().st_size)
(D/'observation.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r),flush=True)
