from pathlib import Path
import json,shutil,sys
b=Path(sys.argv[1]);out=b/'full-run';out.mkdir(exist_ok=True);(out/'fixtures').mkdir(exist_ok=True)
for n in ['bound-probe','init','bpf_arm64_native_lab.ko','native-link','companion.bpf.o']:shutil.copyfile(b/n,out/n)
rows=json.loads((b/'full-suite/build.json').read_text())['cases'];names=[]
for row in rows:
 if row['stage']!='generated':continue
 n=row['name'];names.append(n)
 for ext in ['.native.o','.bpf.o']:shutil.copyfile(b/'full-suite'/(n+ext),out/'fixtures'/(n+ext))
 plan={'objects':[{'program':'neg_source','native_object':n+'.native.o','symbol':'entry','simulator_object':n+'.bpf.o','simulator_program':n+'_arm64_sim_xdp'}]}
 (out/'fixtures'/(n+'.manifest.json')).write_text(json.dumps(plan,indent=2)+'\n')
(out/'cases').write_text(''.join(n+'\n' for n in names))
