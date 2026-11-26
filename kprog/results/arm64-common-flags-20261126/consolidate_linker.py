"""Consolidate the obsolete ARM tool target into the sole cross-ISA target."""
import json
from pathlib import Path
import shutil
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
old=ROOT/'kprog/arm64/build/app-native-link'
current=ROOT/'kprog/x86/native_lab/native_link/target'
archive_path=HERE/'obsolete-linker-build-records.tar.gz'
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
            old_target=str(old),canonical_target=str(current),archived=[],rebuildable_files=0,
            rebuildable_bytes=0,commands=[])
# Capture build recipes/logs/metadata and both old executables; Rust object,
# library and noncanonical executable outputs are rebuildable cache products.
with tarfile.open(archive_path,'w:gz') as archive:
    for path in sorted(old.rglob('*')):
        if not path.is_file():continue
        relative=path.relative_to(old)
        with path.open('rb') as stream:magic=stream.read(4)
        rebuildable=(path.suffix in {'.rlib','.rmeta','.o','.so','.a','.bc'} or magic==b'\x7fELF') and path.name!='native-link'
        if rebuildable:
            record['rebuildable_files']+=1
            record['rebuildable_bytes']+=path.stat().st_size
            continue
        stat=path.stat()
        item=dict(member=str(relative),bytes=stat.st_size,mtime_ns=stat.st_mtime_ns)
        if path.name=='native-link':
            with path.open('rb') as stream:item['machine']=ELFFile(stream)['e_machine']
        record['archived'].append(item)
        archive.add(path,arcname=str(relative),recursive=False)
with tarfile.open(archive_path) as archive:
    for item in record['archived']:
        if archive.extractfile(item['member']).read()!=(old/item['member']).read_bytes():
            raise AssertionError('build record archive differs: '+item['member'])
record['archive_bytes']=archive_path.stat().st_size
record['archive_members_compared']=len(record['archived'])
shutil.rmtree(old)
old.symlink_to(current,target_is_directory=True)
record['alias_target']=str(old.resolve())
for prefix,executable in [([],old/'release/native-link'),
                          (['qemu-aarch64-static','-cpu','cortex-a57'],old/'aarch64-unknown-linux-gnu/release/native-link')]:
    with executable.open('rb') as stream:machine=ELFFile(stream)['e_machine']
    command=[*prefix,str(executable),'--help']
    result=subprocess.run(command,text=True,capture_output=True)
    record['commands'].append(dict(command=command,machine=machine,returncode=result.returncode,
                                   stdout=result.stdout,stderr=result.stderr))
    result.check_returncode()
record['scope']='Obsolete duplicate build cache removed after complete recipe/log/metadata and both old binary archive comparison. Host/ARM executable help only; no image/base/kernel, stock/app or timing change.'
(HERE/'linker-consolidation.json').write_text(json.dumps(record,indent=2)+'\n')
print('archived records',len(record['archived']),'rebuildable bytes removed',record['rebuildable_bytes'])
print('alias',old,'->',current)
