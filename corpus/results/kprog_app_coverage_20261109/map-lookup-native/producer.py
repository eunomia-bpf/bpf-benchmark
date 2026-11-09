from pathlib import Path
import subprocess,json,hashlib,tarfile,sys,shutil,resource
from elftools.elf.elffile import ELFFile
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/map-lookup-native/cleanup-default';G=Path('/var/tmp/kprog-tmp/C/map-lookup-native/cleanup-default');G.mkdir(parents=True,exist_ok=True)
h=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip()
base=json.loads(Path('/var/tmp/kprog-tmp/C/katran-caller-registers/regalloc9/commands.json').read_text())[0]
position=base.index('-stress-regalloc=9');del base[position-1:position+1]
profiles={}
for label,plugin in [('control',Path('/var/tmp/kprog-tmp/C/map-lookup-native/native_division.so')),('candidate',G/'native_division.so')]:
 d=G/label;native=d/'native/katran';native.mkdir(parents=True,exist_ok=True);shutil.copy2(plugin,d/'native_division.so');commands=[];objects=[]
 for name in ['balancer','healthchecking','healthchecking_ipip','xdp_root']:
  source=R/('vendor/bpf/katran/katran/lib/bpf/'+name+'.c');obj=native/(name+'.native.o')
  cmd=[('-fpass-plugin='+str(plugin))if x.startswith('-fpass-plugin=')else x for x in base];cmd[cmd.index('-o')+1]=str(obj);cmd[-1]=str(source);commands.append(cmd)
  with(d/(name+'.log')).open('w')as f:done=subprocess.run(cmd,cwd=R,stdout=f,stderr=subprocess.STDOUT)
  done.check_returncode()
  with obj.open('rb')as f:executable_bytes=sum(int(s['sh_size'])for s in ELFFile(f).iter_sections()if int(s['sh_flags'])&4)
  objects.append(dict(object=obj.name,sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),executable_bytes=executable_bytes,lowered_sites=(d/(name+'.log')).read_text().count('native-map-lowering: array ')))
 cmd=['python3',str(R/'vendor/bpf/write_native_manifest.py'),'--app','katran','--llvm-nm','llvm-nm-18','--output',str(native/'manifest.json')]
 for row in objects:cmd+=['--object',str(native/row['object'])]
 commands.append(cmd);subprocess.run(cmd,cwd=R,check=True);(d/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 profiles[label]=dict(objects=objects,plugin_sha256=hashlib.sha256(plugin.read_bytes()).hexdigest(),lowered_sites=sum(row['lowered_sites']for row in objects))
result=dict(source_commit=h,change='standard LLVM SROA, InstCombine and SimplifyCFG after pre-submission array lookup lowering; matched original source and default register allocation',profiles=profiles)
O.mkdir(exist_ok=True);(G/'summary.json').write_text(json.dumps(result,indent=2)+'\n');(O/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
with tarfile.open(O/'payload.tar.gz','w:gz')as t:
 for name in ['control','candidate','plugin-command.json','plugin-build.log','component.json','summary.json']:t.add(G/name,arcname=name)
 t.add(Path('/var/tmp/kprog-tmp/C/map-lookup-native/btf-layout.json'),arcname='btf-layout.json')
p=O/'README.md';p.write_text(p.read_text()+'\nComplete paired4object control/candidate payloads are in payload.tar.gz, with manifests, plugins, exact commands and source/object hashes. Both use the same original source and default register allocation, and both lower'+str(profiles['candidate']['lowered_sites'])+'array sites. The candidate differs only by the standard cleanup pipeline. R times the unbound pair against the frozen JIT arm; native acceptance remains a separate actual run.\n')
sys.path.insert(0,str(O.parent.parent));from publish_owned import publish
commit=publish([str(O/name)for name in ['README.md','summary.json','payload.tar.gz']],'Publish matched Katran array lowering and cleanup payloads',G/'publication.json');(G/'launch-commit').write_text(commit+'\n')
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a')as f:f.write('\n### Timing request: complete matched Katran array cleanup P '+commit+'\n\nR: paired4object manifests/P/plugins at corpus/results/kprog_app_coverage_20261109/map-lookup-native/cleanup-default/payload.tar.gz; live /var/tmp/kprog-tmp/C/map-lookup-native/cleanup-default/{control,candidate}/native/katran. Both use original matched source, default register allocation, normal/cold inline1000 and21array-lowered sites. Candidate adds only standard SROA/InstCombine/SimplifyCFG after lowering. Overlay each complete native/katran directory into the existing native artifact path; frozen workload/framework and final kernel copy path retain bytes. Compare unbound control/candidate/JIT with the existing common Makefile, both stats modes and3x180s; retain replacements/fallbacks, sent/received/drops/reasons/XDP actions, invocations/time, latency and CPU. Full payload receipt is independent of the still-open bound stack frontier.\n')
