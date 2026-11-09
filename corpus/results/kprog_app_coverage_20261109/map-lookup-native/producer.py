from pathlib import Path
import subprocess,json,hashlib,tarfile,sys,shutil,resource
from elftools.elf.elffile import ELFFile
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
profile=sys.argv[1]if len(sys.argv)>1 else 'cleanup-default'
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/map-lookup-native'/profile;G=Path('/var/tmp/kprog-tmp/C/map-lookup-native')/profile;G.mkdir(parents=True,exist_ok=True)
if profile=='percpu-array':
 command=json.loads(Path('/var/tmp/kprog-tmp/C/map-lookup-native/cleanup-default/plugin-command.json').read_text());command[-1]=str(G/'native_division.so');(G/'plugin-command.json').write_text(json.dumps(command,indent=2)+chr(10))
 with(G/'plugin-build.log').open('w')as f:subprocess.run(command,cwd=R,stdout=f,stderr=subprocess.STDOUT,check=True)
 (G/'component.json').write_text(json.dumps(dict(plugin_source_sha256=hashlib.sha256((R/'vendor/bpf/native_division.cpp').read_bytes()).hexdigest(),layout='matched7rc2 array.pptrs/value share offset304',percpu_conversion_helper=154),indent=2)+chr(10))
h=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip()
base=json.loads(Path('/var/tmp/kprog-tmp/C/katran-caller-registers/regalloc9/commands.json').read_text())[0]
position=base.index('-stress-regalloc=9');del base[position-1:position+1]
profiles={}
for label,plugin in [('control',Path('/var/tmp/kprog-tmp/C/map-lookup-native/cleanup-default/candidate/native_division.so')if profile=='percpu-array'else Path('/var/tmp/kprog-tmp/C/map-lookup-native/native_division.so')),('candidate',G/'native_division.so')]:
 d=G/label;native=d/'native/katran';native.mkdir(parents=True,exist_ok=True);shutil.copy2(plugin,d/'native_division.so');commands=[];objects=[]
 for name in ['balancer','healthchecking','healthchecking_ipip','xdp_root']:
  source=R/('vendor/bpf/katran/katran/lib/bpf/'+name+'.c');obj=native/(name+'.native.o')
  cmd=[('-fpass-plugin='+str(plugin))if x.startswith('-fpass-plugin=')else x for x in base];cmd[cmd.index('-o')+1]=str(obj);cmd[-1]=str(source);commands.append(cmd)
  with(d/(name+'.log')).open('w')as f:done=subprocess.run(cmd,cwd=R,stdout=f,stderr=subprocess.STDOUT)
  done.check_returncode()
  with obj.open('rb')as f:executable_bytes=sum(int(s['sh_size'])for s in ELFFile(f).iter_sections()if int(s['sh_flags'])&4)
  objects.append(dict(object=obj.name,sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),executable_bytes=executable_bytes,lowered_sites=(d/(name+'.log')).read_text().count('native-map-lowering:'),percpu_sites=(d/(name+'.log')).read_text().count('native-map-lowering: percpu-array ')))
 cmd=['python3',str(R/'vendor/bpf/write_native_manifest.py'),'--app','katran','--llvm-nm','llvm-nm-18','--output',str(native/'manifest.json')]
 for row in objects:cmd+=['--object',str(native/row['object'])]
 commands.append(cmd);subprocess.run(cmd,cwd=R,check=True);(d/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 profiles[label]=dict(objects=objects,plugin_sha256=hashlib.sha256(plugin.read_bytes()).hexdigest(),lowered_sites=sum(row['lowered_sites']for row in objects))
result=dict(source_commit=h,change=('pre-submission per-CPU array index/bounds/mask/pptr lookup with existing this_cpu_ptr helper154; matched original source and default register allocation'if profile=='percpu-array'else 'standard LLVM SROA, InstCombine and SimplifyCFG after pre-submission array lookup lowering; matched original source and default register allocation'),profiles=profiles)
O.mkdir(exist_ok=True);(G/'summary.json').write_text(json.dumps(result,indent=2)+'\n');(O/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
with tarfile.open(O/'payload.tar.gz','w:gz')as t:
 for name in ['control','candidate','plugin-command.json','plugin-build.log','component.json','summary.json']:t.add(G/name,arcname=name)
 t.add(Path('/var/tmp/kprog-tmp/C/map-lookup-native/btf-layout.json'),arcname='btf-layout.json')
p=O/'README.md';description=('The candidate additionally lowers per-CPU array pointer-slot lookup and calls the existing this_cpu_ptr helper154; the control retains the published plain-array cleanup plugin.'if profile=='percpu-array'else 'The candidate adds the standard SROA/InstCombine/SimplifyCFG cleanup pipeline.');p.write_text((p.read_text()if p.exists()else '# Pre-submission native map lookup profile'+chr(10))+chr(10)+'Complete paired4object payloads retain original C, default register allocation, manifests, exact commands, plugin/source hashes and build diagnostics. '+description+' Actual per-object lookup counts and executable sizes are in summary.json. R times the unbound pair against the frozen JIT arm; verified generation, stock verifier and runtime acceptance are separate observations.'+chr(10))
sys.path.insert(0,str(O.parent.parent));from publish_owned import publish
commit=publish([str(O/name)for name in ['README.md','summary.json','payload.tar.gz']],('Publish complete Katran per-CPU array native payloads'if profile=='percpu-array'else 'Publish matched Katran array lowering and cleanup payloads'),G/'publication.json');(G/'launch-commit').write_text(commit+'\n')
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a')as f:f.write(chr(10)+'### Timing request: matched Katran native map profile '+profile+' '+commit+chr(10)+chr(10)+'R: complete paired4object control/candidate manifests and plugins at '+str(O/'payload.tar.gz')+'; live '+str(G)+'/{control,candidate}/native/katran. Original C, native ABI and compiler flags match; summary.json records actual lowered lookup classes, code sizes, object/source/plugin hashes. Use the existing unbound native/JIT arms, frozen workload and common Makefile on0-7, stats modes and3x180s, retaining all replacements/fallbacks/work/drop reasons/XDP actions/latency/CPU. Kernel emitted-copy path retains its definition. Verified acceptance follows separately.'+chr(10))
