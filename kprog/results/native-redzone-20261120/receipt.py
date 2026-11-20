"""Record native compile-option enforcement and unchanged cached input."""
import json
from pathlib import Path
import tarfile
from elftools.elf.elffile import ELFFile

here=Path(__file__).resolve().parent
raw=Path('/workspaces/kprog-raw/perf/native-redzone-20261120/candidate-20261120T042712Z')
before=json.loads((raw/'before.json').read_text())
after=json.loads((raw/'after.json').read_text())
record=dict(correction='91a703ada',raw=str(raw),before=before,after=after,
    same_cached_frontend=before['source_frontend']==after['source_frontend'],
    make_exit=int((raw/'exit-code').read_text()),
    lpm=json.loads((raw/'lpm/report.json').read_text()),
    hash=json.loads((raw/'hash/production-result.json').read_text()),
    array_cases=1008,array_generic_controls=2,probe_cases=99,probe_proof_and_kernel_links=8,
    emitted_code='LPM entry changes rsp-24/rsp-16 unallocated stores to sub rsp,24 with stores at rsp/rsp+8 and matching epilogues',
    policy='Existing Clang O3 -mllvm -force-attribute=noredzone, uniform for all checked native program/helper functions, including cached BPF frontend IR',
    scope='Native program compile option and emitted ABI, host semantics/compatibility. No compiler/tool source/binary change, extra optimizer stage, B rewrite, application speed or asynchronous interrupt experiment.')
native=record['lpm']['native']
with Path(native['native_proof_object']).open('rb') as stream:
    elf=ELFFile(stream)
    selected=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==native['symbol'])
    record['proof_entry_bytes']=selected['st_size']
(here/'report.json').write_text(json.dumps(record,indent=2)+'\n')
with tarfile.open(here/'evidence.tar.gz','w:gz') as archive:
    archive.add(raw,arcname=raw.name)
print(record['same_cached_frontend'],before['native_entry_bytes'],after['native_entry_bytes'],record['proof_entry_bytes'])
