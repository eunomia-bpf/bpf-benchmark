"""Copy the matched context-v2 runtime into lane-owned Docker contexts."""
from pathlib import Path
import shutil
import sys

ROOT=Path(__file__).resolve().parents[3]
source=Path('/workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64')
library=Path('/workspaces/.agent-state/kprog-lanes/T/context-v2-datasec/arm64')
base=Path(sys.argv[1]).resolve()
kernel=base/'kernel'
boot=kernel/'arch/arm64/boot';boot.mkdir(parents=True,exist_ok=True)
for name in ['Image','vmlinuz.efi']: shutil.copy2(source/name,boot/name)
shutil.copy2(source/'kernel.config',kernel/'.config')
shutil.copy2(source/'Module.symvers',kernel/'Module.symvers')
modules=source/'stock/lib/modules'
releases=[p.name for p in modules.iterdir() if p.is_dir()]
if len(releases)!=1: raise RuntimeError(f'kernel module release is not unique: {releases}')
(kernel/'include/config').mkdir(parents=True,exist_ok=True)
(kernel/'include/config/kernel.release').write_text(releases[0]+'\n')
shutil.copytree(source/'stock',kernel/'modules-install',dirs_exist_ok=True,symlinks=True)
kinsn=base/'kinsn';kinsn.mkdir(exist_ok=True)
custom=list(source.glob('*.ko'))
if len(custom)!=11: raise RuntimeError(f'expected the matched11 ARM kinsn modules, found{len(custom)}')
for path in custom: shutil.copy2(path,kinsn/path.name)
runner=base/'runner';runner.mkdir(exist_ok=True)
for path in (ROOT/'runner').iterdir():
    if path.name=='build-arm64-llvmbpf': continue
    target=runner/path.name
    if not target.exists(): target.symlink_to(path,target_is_directory=path.is_dir())
shutil.copytree(ROOT/'runner/build-arm64-llvmbpf',runner/'build-arm64-llvmbpf',dirs_exist_ok=True,symlinks=True)
shutil.copy2(library/'libnative_loader.so',runner/'build-arm64-llvmbpf/native_loader/libnative_loader.so')
shutil.copy2(library/'libnative_loader.a',runner/'build-arm64-llvmbpf/native_loader/libnative_loader.a')
print(f'matched kernel/EFI/{releases[0]} stock modules/all11 kinsn/library copied into {base}')
