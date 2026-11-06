from pathlib import Path
import json,shutil,subprocess,sys
b=Path(sys.argv[1]);root=Path(__file__).resolve().parents[5];out=b/'positive-run';out.mkdir(exist_ok=True);(out/'fixtures').mkdir(exist_ok=True)
for n in ['bound-probe','init','bpf_arm64_native_lab.ko','native-link','companion.bpf.o']:shutil.copyfile(b/n,out/n)
names=[]
for old in ['unaligned-effective-address','preindex-old-sp-aligned','postindex-old-sp-aligned']:
 n=old.replace('-','_');names.append(n)
 s=(b/'regressions'/(old+'.bpf.c')).read_text().replace('#include "../arm64_sim_local_bpf.h"','#include "'+str(b/'full-suite/snapshot/kprog/arm64/arm64_sim_local_bpf.h')+'"')
 source=out/'fixtures'/(n+'.bpf.c');source.write_text(s)
 subprocess.run(['clang','-g','-O2','-target','bpf','-I'+str(root/'vendor/libbpf/include/uapi'),'-I'+str(root/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(source),'-o',str(out/'fixtures'/(n+'.bpf.o'))],check=True)
 shutil.copyfile(b/'regressions'/(old+'.proof.o'),out/'fixtures'/(n+'.native.o'))
 plan={'objects':[{'program':'neg_source','native_object':n+'.native.o','symbol':'entry','simulator_object':n+'.bpf.o','simulator_program':n+'_arm64_sim_xdp'}]}
 (out/'fixtures'/(n+'.manifest.json')).write_text(json.dumps(plan,indent=2)+'\n')
(out/'cases').write_text(''.join(n+'\n' for n in names))
