"""Export committed sources plus this lane's exact map-pointer producer changes."""
from pathlib import Path
import io
import shutil
import subprocess
import tarfile
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=Path('/workspaces/.agent-state/kprog-lanes/C/source-map-check-source')
OUT.mkdir()
revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
paths=['kprog/formal','kprog/x86','kprog/arm64','kprog/test','kprog/helper_abi.py',
       'micro/programs','micro/config','kprog/helper-abi.json']
# Missing optional pathspecs must not make the archive silently incomplete.
paths=[p for p in paths if subprocess.check_output(['git','ls-tree',revision,p],cwd=ROOT)]
archive=subprocess.check_output(['git','archive',revision,*paths],cwd=ROOT)
with tarfile.open(fileobj=io.BytesIO(archive)) as stream:stream.extractall(OUT,filter='data')
for relative in ['vendor/libbpf/src','vendor/libbpf/include','vendor/linux-framework/include']:
 shutil.copytree(ROOT/relative,OUT/relative,dirs_exist_ok=True)
owned=['kprog/x86/native_lab/native_link/src/x86.rs',
       'kprog/formal/contracts/x86_ptr_write_spec.json',
       'kprog/formal/tools/generate_x86_ptr_write_spec.py',
       'kprog/formal/generated/x86_ptr_write.h',
       'kprog/formal/KProgFormal/Generated/GeneratedX86PtrWrite.lean',
       'kprog/formal/KProgFormal/X86PtrWriteHandler.lean',
       'kprog/formal/oracles/test_x86_mov_load_map_ptr_host.c']
for relative in owned:shutil.copy2(ROOT/relative,OUT/relative)
# Keep V's not-yet-published condition changes out of this isolated check.
relative='kprog/x86/micro-prog/generate_micro_sim_proofs.py'
text=(ROOT/relative).read_text().replace('from generated_x86_full_condition import CC_AUX',
                                     'from generated_x86_cc_decode import CC_AUX')
(OUT/relative).write_text(text)
relative='kprog/x86/x86_sim_local_bpf.h'
text=(OUT/relative).read_text().replace('KPROG_X86_PTR_WRITE_TAG(                  \\',
                                     'KPROG_X86_PTR_WRITE_SOURCE_TAG(           \\',1)
text=text.replace('(OP) == X86_OP_MOV_LOAD_HELPER_ID);\\',
                  '(OP) == X86_OP_MOV_LOAD_HELPER_ID, (AUX));\\',1)
(OUT/relative).write_text(text)
(HERE/'source-map-check-revision.txt').write_text(revision+'\n'+ '\n'.join(owned+[relative])+'\n')
print('immutable source map check',revision,OUT)
