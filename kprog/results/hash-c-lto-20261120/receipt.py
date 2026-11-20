"""Retain actual component/stock/native API receipts, with no speed inference."""
import json
from pathlib import Path
import tarfile
from elftools.elf.elffile import ELFFile

here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/hash-c-lto-20261120')
host=base/'host-20261120T041202Z'
production=base/'production-20261120T041613Z'
build=Path('/var/tmp/kprog-tmp/perf/hash-c-lto')
report=dict(source='59763bf01',body='00bf7ede0',fixture_correction='49c7eb9a6',
    host=json.loads((host/'report.json').read_text()),
    stock=json.loads((production/'stock-result.json').read_text()),
    production=json.loads((production/'production-result.json').read_text()),
    lpm=json.loads((production/'lpm/report.json').read_text()),
    array_cases=1008,array_generic_controls=2,probe_cases=99,probe_proof_and_kernel_links=8,
    compiler='Existing installed compile-sim-ir353368B,Nov19 22:14, unchanged; existing lookup ABI',
    scope='C helper semantics, actual stock B acceptance and native compiler API/host execution. All LTO enabled. Application installation/per-call/throughput and formal helper refinement remain open.')
native=report['production']['native']
for name,key in [('native_object','native_entry_bytes'),('native_proof_object','proof_entry_bytes')]:
    with Path(native[name]).open('rb') as stream:
        elf=ELFFile(stream)
        symbol=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==native['symbol'])
        report[key]=symbol['st_size']
(here/'report.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'evidence.tar.gz','w:gz') as archive:
    for directory in sorted(base.iterdir()):
        if directory.is_dir(): archive.add(directory,arcname=directory.name)
    archive.add(build,arcname='current-native-program-products')
    for directory in ['array','probe']:
        archive.add(Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')/directory,arcname='compatibility-'+directory)
    archive.add('/workspaces/repository/kprog/x86/micro-prog/native_hash.h',arcname='native_hash.h')
print(report['host']['execution'],report['production']['execution'],report['native_entry_bytes'],report['proof_entry_bytes'])
