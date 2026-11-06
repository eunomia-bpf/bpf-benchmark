"""Recompile the actual QEMU Cilium configuration with the ARM backend flags."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from runner.libs import cilium_native_build as build

phase=Path(sys.argv[1]).resolve();phase.mkdir()
guest=ROOT/'kprog/arm64/build/app-runtime-v2/root'
run=guest/'workspaces/repository/corpus/results/arm64_qemu_corpus_19700101_000006_530516'
captures=list((run/'details/cilium-native-config/parity').rglob('parity.json'))
if len(captures)!=1:raise RuntimeError('expected the exact captured failing Cilium configuration')
capture=captures[0];parity=json.loads(capture.read_text())
shutil.copy2(capture,phase/'original-parity.json')
native_root=phase/'native-abi-overlay'
shutil.copytree(capture.parent/'native-abi-overlay',native_root,symlinks=True)
config=phase/'config'
for row in parity['headers']:
    destination=config/row['source'].lstrip('/')
    destination.parent.mkdir(parents=True,exist_ok=True)
    shutil.copy2(capture.parent/row['archive'],destination)
original=ROOT/'vendor/repos/cilium/bpf'
args=[]
for arg in parity['bpf_command'][1:]:
    if arg.startswith('-I'):
        directory=arg[2:]
        if directory.startswith('/var/lib/cilium/bpf'):
            directory=str(original)+directory.removeprefix('/var/lib/cilium/bpf')
        else:directory=str(config/directory.lstrip('/'))
        arg='-I'+directory
    elif arg.startswith('/var/lib/cilium/bpf/'):
        arg=str(original/Path(arg).name)
    args.append(arg)
compat=phase/'native_compat.h'
shutil.copy2(guest/'usr/local/lib/bpfrejit/native/native_compat.h',compat)
native=phase/'bpf_xdp.native.o'
# The real capture ran in an AArch64 guest. Cross-compile that same target on
# this x86 build host; the ELF machine check below detects target drift.
build.platform.machine=lambda:'aarch64'
command=['clang',*build.native_compile_args(args,native,compat,native_root,native_root/'bpf_xdp.c')]
result=subprocess.run(command,text=True,capture_output=True)
(phase/'compile.json').write_text(json.dumps(dict(command=command,returncode=result.returncode,
    stdout=result.stdout,stderr=result.stderr),indent=2)+'\n')
if result.returncode:raise RuntimeError(result.stderr)
with native.open('rb') as source:
    elf=ELFFile(source)
    if elf['e_machine']!='EM_AARCH64':raise RuntimeError('native target changed architecture')
    symbols=sorted({s.name for s in elf.get_section_by_name('.symtab').iter_symbols()
        if s['st_info']['type']=='STT_FUNC' and isinstance(s['st_shndx'],int) and s['st_size']})
if 'tail_drop_notify' not in symbols:raise RuntimeError('lost the original failing Cilium function')
rows=[]
for symbol in symbols:
    command=[str(ROOT/'kprog/arm64/build/app-native-link/release/native-link'),'--input',str(native),
        '--symbol',symbol,'--mode','proof','--preserve-entry-abi','--output',str(phase/(symbol+'.proof.o'))]
    result=subprocess.run(command,text=True,capture_output=True)
    rows.append(dict(symbol=symbol,command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
(phase/'link-results.json').write_text(json.dumps(rows,indent=2)+'\n')
if any(row['returncode'] for row in rows):raise RuntimeError('Cilium native linking failed; all exact outcomes retained')
print(f'actual captured Cilium XDP configuration: AArch64 compilation and all{len(rows)} native functions link successfully, including tail_drop_notify')
