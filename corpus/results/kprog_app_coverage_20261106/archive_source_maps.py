"""Keep the tested producer inputs and logs, excluding rebuildable caches."""
from pathlib import Path
import tarfile
HERE=Path(__file__).resolve().parent
SOURCE=Path('/workspaces/.agent-state/kprog-lanes/C/source-map-check-source')
def keep(info):
 if any(part in {'.lake','target','build','__pycache__'} for part in Path(info.name).parts):return None
 if info.type in (tarfile.FIFOTYPE,tarfile.CHRTYPE,tarfile.BLKTYPE):return None
 return info
names=['source-map-elf','source-map-lift','source-map-alias','source-map-alias-first',
 'source-map-micro','source-map-micro-negative','bcc-real-13']
names += ['startup-lift/'+name for name in ['bcc_map_value','bcc_map_value_v2','bcc_map_value_v3',
 'bcc_map_alias','bcc_map_alias-first','bcc_trace_read','bcc_trace_zero','bcc_fentry_zero']]
names += [p.name for p in HERE.glob('source-map*.log')]
names += ['source-map-check-revision.txt','bcc-real-13-build.log','bcc-transient-proofs.log',
 'bcc-runtime-13-image.log','bcc-runtime-13-corpus.log','strict-runtime-guard-rebuild.log',
 'strict-runtime-guard-kvm.log','strict-guard-return']
with tarfile.open(HERE/'source-map-artifacts.tar.gz','w:gz') as archive:
 for name in names:archive.add(HERE/name,arcname=name,filter=keep)
 archive.add(HERE.parent/'x86_kvm_corpus_20261106_175435_598627',arcname='x86_kvm_corpus_20261106_175435_598627',filter=keep)
 archive.add(SOURCE/'kprog/x86/micro-prog/build/native-link',arcname='micro-native-proofs',filter=keep)
 for relative in ['kprog/formal','kprog/x86/x86_sim.h','kprog/x86/x86_sim_local_bpf.h',
                  'kprog/x86/micro-prog','kprog/x86/native_lab/native_link/src',
                  'kprog/x86/native_lab/native_link/Cargo.toml','kprog/x86/native_lab/native_link/Cargo.lock']:
  archive.add(SOURCE/relative,arcname='checked-source/'+relative,filter=keep)
