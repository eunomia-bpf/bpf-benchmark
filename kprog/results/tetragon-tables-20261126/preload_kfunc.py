"""Attribute the unchanged try_preload_arg offline refusal to kernel ABI facts."""
import io
import json
import os
from pathlib import Path
import subprocess
import tarfile

from elftools.elf.elffile import ELFFile
import stage_acceptance as audit
from kernel_function_abi import KernelTypes

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BTF = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
with tarfile.open(HERE / 'stage-acceptance/case-188.tar.gz') as archive:
    case = json.load(archive.extractfile('case.json'))
    proof = archive.extractfile('generation/p.proof.o').read()
elf = ELFFile(io.BytesIO(proof))
symbol = next(s for s in elf.get_section_by_name('.symtab').iter_symbols()
              if s.name == 'bpf_copy_from_user_str')
types = KernelTypes(BTF)
try:
    function = types.function(symbol.name, symbol['st_info']['bind'] == 'STB_WEAK')
finally:
    types.close()
if function is None or not function['present']:
    raise ValueError('sole-kernel BTF lacks the referenced copy_from_user_str function')

# The same archived proof is read from anonymous memory. The existing parser
# opens this parent-process FD through /proc, including from its objdump child.
# No source tree, second build or uncompressed proof copy is created.
fd = os.memfd_create('preload-proof')
os.write(fd, proof)
class ProofDirectory:
    def __truediv__(self, name):
        return Path(f'/proc/{os.getpid()}/fd/{fd}')

try:
    options = dict(case['generation_metadata'], kernel_functions={symbol.name: function})
    before, before_source = audit.generate(audit.old_gen, 'p', ProofDirectory(), options)
    current, current_source = audit.generate(audit.worker.gen, 'p', ProofDirectory(), options)
finally:
    os.close(fd)
result = dict(recorded_utc=audit.now(), kernel_btf=str(BTF),
    kernel_source=subprocess.check_output(['git', '-C', str(ROOT / 'vendor/linux-framework'),
                                         'rev-parse', 'HEAD'], text=True).strip(),
    case=188, symbol=case['symbol'], supplied_kernel_function=function,
    original_before=case['before'], original_current=case['current'],
    typed_before=before, typed_current=current,
    typed_source_identical=before_source == current_source if before_source is not None else None,
    scope='Same archived .text helper proof with the existing target-kernel kfunc ABI metadata. Offline C generation only, no production change or stock/app acceptance.')
(HERE / 'preload-kfunc-result.json').write_text(json.dumps(result, indent=2) + '\n')
with tarfile.open(HERE / 'preload-kfunc-evidence.tar.gz', 'w:gz') as archive:
    audit.add_bytes(archive, 'p.proof.o', proof)
    audit.add_bytes(archive, 'result.json', (json.dumps(result, indent=2) + '\n').encode())
    for name, source in [('before', before_source), ('current', current_source)]:
        if source is not None:
            audit.add_bytes(archive, name + '/p.bpf.c', source)
print(json.dumps(result, indent=2))
if before['status'] != 'generated' or current['status'] != 'generated':
    raise SystemExit(1)
