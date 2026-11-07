"""Build requested compiler-option experiments from a frozen source tree."""
from pathlib import Path
import json
import subprocess
import sys
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
SOURCE=HERE/'native-options-source/vendor/bpf';OUT=HERE/(sys.argv[1] if len(sys.argv)>1 else 'native-options');OUT.mkdir()
records=[];failures=0
profiles={'tables':['-fPIC'],'absolute-tables':['-fno-pic','-fno-pie','-mcmodel=large']}
common=['clang-18','-O3','-g','-c','-DMICRO_NATIVE','-D__TARGET_ARCH_x86',
        '-fomit-frame-pointer','-march=native','-mno-red-zone','-mgeneral-regs-only',
        '-fno-stack-protector','-fno-asynchronous-unwind-tables','-fno-unwind-tables',
        '-Wno-unknown-attributes','-I/usr/include','-I/usr/include/x86_64-linux-gnu',
        '-ffile-prefix-map='+str(SOURCE)+'='+str(ROOT/'vendor/bpf')]
def run(args,profile,app,stage):
 global failures
 result=subprocess.run(list(map(str,args)),text=True,capture_output=True)
 records.append(dict(profile=profile,application=app,stage=stage,command=list(map(str,args)),returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
 (OUT/'commands.json').write_text(json.dumps(records,indent=2)+'\n')
 if result.returncode:failures+=1
 return result
for profile,flags in profiles.items():
 for app,symbol,filename in [('katran','balancer_ingress','balancer'),('tetragon','generic_kprobe_event','bpf_generic_kprobe_v61')]:
  directory=OUT/profile/app;directory.mkdir(parents=True)
  native=directory/(filename+'.native.o');command=common+flags
  if app=='katran':
   command+=['-Wno-compare-distinct-pointer-types','-I'+str(SOURCE/'katran'),'-I'+str(SOURCE/'katran/katran/lib/linux_includes'),str(SOURCE/'katran/katran/lib/bpf/balancer.c')]
  else:
   command+=['-fms-extensions','-DMICRO_NATIVE_HELPER_MACROS','-DMICRO_NATIVE_TETRAGON','-D__LARGE_BPF_PROG','-D__V511_BPF_PROG','-D__V61_BPF_PROG','-include',str(SOURCE/'native_compat.h')]
   command+=['-I'+str(SOURCE/'tetragon/bpf'/name) for name in ['', 'include','lib','libbpf','process','errmetrics']]
   command+=[str(SOURCE/'tetragon/bpf/process/bpf_generic_kprobe.c')]
  if run(command+['-o',str(native)],profile,app,'compile').returncode:continue
  run(['objdump','-dr','-Mintel',str(native)],profile,app,'native-disassembly')
  result=run([HERE/'baseline/native-link','--input',native,'--symbol',symbol,'--mode','proof','--preserve-entry-abi','--output',directory/(filename+'.'+symbol+'.proof.o')],profile,app,'entry-proof')
  print(profile,app,'entry-proof',result.returncode,flush=True)
print('recorded failures',failures,flush=True)
raise SystemExit(int(failures!=0))
