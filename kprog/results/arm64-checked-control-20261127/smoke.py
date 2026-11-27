"""Record current ARM tools, module and kernel-derived context layouts."""
import json
from pathlib import Path
import shutil
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BASE=Path('/workspaces/.agent-state/kprog-ck')
loader=ROOT/'runner/build-arm64-llvmbpf/native_loader/trusted-native-loader'
client=loader.with_name('trusted-service-client')
linker=ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'
module=BASE/'verified-module/arm64/bpf_arm64_native_lab.ko'
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),files=[],commands=[])
for path in [loader,client,linker,module]:
 with path.open('rb') as stream:machine=ELFFile(stream)['e_machine']
 record['files'].append(dict(path=str(path),bytes=path.stat().st_size,machine=machine))
for executable,args in [(loader,['abi']),(linker,['--help'])]:
 command=['qemu-aarch64-static','-L',str(ROOT/'.cache/qemu-arm64-root'),'-cpu','cortex-a57',str(executable),*args]
 r=subprocess.run(command,text=True,capture_output=True)
 record['commands'].append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (HERE/'build-smoke.json').write_text(json.dumps(record,indent=2)+'\n')
 r.check_returncode()
for name in ['public-layout.json','physical-layout.json']:
 path=BASE/'verified-compiler/arm64'/name
 (HERE/('arm64-'+name)).write_bytes(path.read_bytes())
record['scope']='ARM executable startup/wire ABI and actual ARM-kernel-header context layout builds; no guest stock/native installation or timing result.'
(HERE/'build-smoke.json').write_text(json.dumps(record,indent=2)+'\n')
# One old duplicate target; its entire contents were captured before removal.
old=ROOT/'kprog/libnativeloader/build-arm64'
with tarfile.open(HERE/'loader-before.tar.gz') as archive:
 for p in old.rglob('*'):
  if p.is_file() and archive.extractfile('0/'+str(p.relative_to(old))).read()!=p.read_bytes():raise AssertionError(p)
shutil.rmtree(old)
(HERE/'loader-consolidation.json').write_text(json.dumps(dict(recorded_utc=record['recorded_utc'],
 removed=str(old),archive='loader-before.tar.gz',canonical=str(loader.parent),
 note='All old duplicate files byte-compared to complete archive before removal; current runner ARM target remains sole loader build. Image copy untouched.'),indent=2)+'\n')
with tarfile.open(HERE/'build-products.tar.gz','w:gz') as archive:
 for p in [loader,client,module,Path('/var/tmp/kprog-tmp/perf/arm64-checked-control/control.o')]:archive.add(p,arcname=p.name)
print('ARM loader ABI startup0, native-link help0; sole stock ARM module and layouts built; duplicate target removed')
