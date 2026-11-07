"""Package current trusted-path inputs over the existing application image."""
from pathlib import Path
import hashlib,json,shutil,subprocess
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent
S=Path('/workspaces/.agent-state/kprog-lanes/C/native-only-runtime');D=S/'package'
D.mkdir(parents=True,exist_ok=True)
base=json.loads(subprocess.check_output(['docker','image','inspect','bpf-benchmark/runner-runtime:x86_64'],text=True))[0]
assert base['Config']['WorkingDir']==str(R)
pins={}
def copy(src,dst):
 src=Path(src);dst=Path(dst);dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dst);pins[str(src)]=hashlib.sha256(src.read_bytes()).hexdigest()
for src,name in [('kprog/libnativeloader/build/libnative_loader.so','libnative_loader.so'),('bpfopt/shim/build-x86/libbpfrejit_shim.so','libbpfrejit_shim.so'),('kprog/x86/native_lab/native_link/target/release/native-link','native-link')]:copy(R/src,D/name)
K=R/'kprog/tv/build-kernel-x86';release=(K/'include/config/kernel.release').read_text().strip()
module_root=S/'kernel-modules/lib/modules'
assert (module_root/release).is_dir(),'export current cached kbuild modules with modules_install'
if (D/'modules').exists():raise RuntimeError('preserve existing package; do not silently replace compiled inputs')
shutil.copytree(module_root,D/'modules',ignore=shutil.ignore_patterns('build','source'))
for src in sorted((R/'kprog/tv/build-x86/corpus-modules').glob('*.ko')):copy(src,D/'kinsn'/src.name)
assert len(list((D/'kinsn').glob('*.ko')))==15
copy(K/'arch/x86/boot/bzImage',D/'kernel/bzImage');copy(K/'.config',D/'kernel/config')
(D/'manifest.json').write_text(json.dumps(dict(kernel_release=release,target_arch='x86_64',kernel_image='bzImage'),indent=2)+'\n')
for app in sorted((R/'vendor/build/native-bpf/x86/stage').iterdir()):
 if app.is_dir():
  for src in sorted(app.iterdir()):
   if src.is_file() and (src.name.endswith('.native.o') or src.suffix=='.json'):copy(src,D/'native-bpf'/app.name/src.name)
for folder in ['runner/libs','runner/config','runner/suites','corpus/config','corpus/inputs']:
 for src in sorted((R/folder).rglob('*')):
  if src.is_file() and '__pycache__' not in src.parts:copy(src,D/'code'/src.relative_to(R))
for folder in ['runner','corpus']:
 for src in sorted((R/folder).glob('*.py')):copy(src,D/'code'/src.relative_to(R))
record=dict(base_id=base['Id'],base_layers=base['RootFS']['Layers'],source_head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip(),kernel_release=release,input_sha256=pins)
(O/'package-inputs.json').write_text(json.dumps(record,indent=2)+'\n')
print('packaged',len(pins),'current inputs; cached kernel modules and15 matching kinsn modules; base',base['Id'],flush=True)
