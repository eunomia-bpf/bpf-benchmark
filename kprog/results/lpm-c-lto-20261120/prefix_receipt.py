"""Record the key-width C change against the retained previous component."""
import json
from pathlib import Path
import tarfile
from elftools.elf.elffile import ELFFile

here = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120/prefix-20261120T033731Z')
tmp = Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')
result = json.loads((raw/'report.json').read_text())
before = json.loads((here/'native-helper-result.json').read_text())
result.update(source_revision='6d18958c0', raw=str(raw),
    compiler='Existing installed compile-sim-ir, 353368 bytes, Nov19 22:14; no tool build or publication',
    old_native_entry_bytes=before['native_entry_bytes'], old_proof_entry_bytes=before['proof_entry_bytes'],
    scope='Host native helper semantics and actual compiler API after unchanged stock B acceptance. Application speed is pending; the previous OTel diagnostic regressed.')
for name, key in [('native_object', 'native_entry_bytes'), ('native_proof_object', 'proof_entry_bytes')]:
    with Path(result['native'][name]).open('rb') as stream:
        elf = ELFFile(stream)
        selected = next(symbol for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                        if symbol.name == result['native']['symbol'])
        result[key] = selected['st_size']
(here/'prefix-result.json').write_text(json.dumps(result, indent=2)+'\n')
with tarfile.open(here/'prefix-evidence.tar.gz', 'w:gz') as archive:
    archive.add(raw, arcname=raw.name)
    archive.add(tmp/'generation', arcname='accepted-B-and-native')
    for name in ['post-b-input.bc', 'post-b-helpers.c', 'post-b-helpers.bc', 'post-b-linked.bc',
                 'post-b-native.bc', 'post-b.o', 'post-b-execute', 'post-b-production-execute']:
        archive.add(tmp/name, arcname=name)
print(result['native_entry_bytes'], result['proof_entry_bytes'])
