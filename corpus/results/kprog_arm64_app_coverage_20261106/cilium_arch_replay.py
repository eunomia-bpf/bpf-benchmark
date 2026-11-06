"""Recompile the actual QEMU Cilium configuration with the ARM backend flags."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from runner.libs import cilium_native_build as build

phase=Path(sys.argv[1]).resolve();phase.mkdir()
with tarfile.open(Path(__file__).with_name('cilium-native-arch')/'replay.tar.gz') as archive:
    members=[entry for entry in archive.getmembers() if entry.name.startswith(('config/','native-abi-overlay/'))
        or entry.name in {'original-parity.json','native_compat.h'}]
    archive.extractall(phase,members=members,filter='data')
parity=json.loads((phase/'original-parity.json').read_text())
native_root=phase/'native-abi-overlay'
config=phase/'config'
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
