"""Retain installed-tool native C results and each stock boundary verdict."""
import json
from pathlib import Path
import tarfile
from elftools.elf.elffile import ELFFile

here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120')
native=base/'installed-abi-20261120T024230Z'
compat=base/'compatibility-20261120T025007Z'
record=json.loads((native/'report.json').read_text())
tmp=Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')
for kind in ['array','probe']:
    commands=json.loads((tmp/kind/'commands.json').read_text())
    assert all(command['returncode']==0 for command in commands)
record.update(helper_revision='0ca3869fa',driver_revision='215e6f7a5',
    native_raw=str(native),compatibility_raw=str(compat),
    array_cases=1008,array_generic_controls=2,probe_cases=99,probe_proof_and_kernel_links=8,
    compiler='Existing installed compile-sim-ir, unchanged at Nov19 22:14; current ABI --array-map / __kprog_array_lookup',
    invocation='Native C source and program builds only; new tool interface/build/publication deleted',
    scope='Stock helper-call B acceptance, installed-tool native compiler API, host native C semantics and compatibility. OTel app validation is running separately; application speed remains pending.')
for name,key in [('native_object','native_entry_bytes'),('native_proof_object','proof_entry_bytes')]:
    with Path(record['native'][name]).open('rb') as stream:
        elf=ELFFile(stream)
        selected=next(symbol for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                      if symbol.name==record['native']['symbol'])
        record[key]=selected['st_size']
(here/'native-helper-result.json').write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(here/'native-helper-evidence.tar.gz','w:gz') as archive:
    for directory in ['stock-20261120T015715Z','stock-20261120T015803Z',
                      'stock-20261120T020339Z','stock-20261120T022137Z',
                      'stock-generation-20261120T020308Z','after-b-build-20261120T022114Z',
                      'installed-abi-20261120T023804Z','installed-abi-20261120T024230Z',
                      'compatibility-20261120T025007Z']:
        archive.add(base/directory,arcname=directory)
    archive.add(tmp/'generation',arcname='accepted-B-and-native')
    for directory in ['array','probe']:
        archive.add(tmp/directory,arcname='compatibility-'+directory)
print(record['native_entry_bytes'],record['proof_entry_bytes'],record['production_execution'])
