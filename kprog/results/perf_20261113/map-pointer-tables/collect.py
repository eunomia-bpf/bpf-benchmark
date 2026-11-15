"""Record the actual anonymous RELRO relocation shape and bounded test receipt."""
import hashlib
import json
from pathlib import Path
import shutil
from elftools.elf.elffile import ELFFile

out = Path(__file__).resolve().parent
raw = Path('/workspaces/kprog-raw/perf/20261115-map-pointer-tables')
build = Path('/var/tmp/kprog-tmp/perf/map-pointer-tables')


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


records = []
for label, path in [('historical-otel-shape', Path('/workspaces/kprog-raw/perf/20261114-otel-combined-codegen/all-flags-build/tracer.native.o')),
                    ('clang-fixture', build/'fixture.native.o')]:
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        table = elf.get_section_by_name('.data.rel.ro')
        index = elf.get_section_index('.data.rel.ro')
        slots = []
        for section in elf.iter_sections():
            if section['sh_type'] != 'SHT_RELA' or section['sh_info'] != index:
                continue
            symbols = elf.get_section(section['sh_link'])
            for relocation in section.iter_relocations():
                symbol = symbols.get_symbol(relocation['r_info_sym'])
                owner = symbol['st_shndx']
                slots.append(dict(offset=relocation['r_offset'], kind=relocation['r_info_type'],
                    addend=relocation['r_addend'], symbol=symbol.name,
                    target_section=elf.get_section(owner).name if isinstance(owner, int) else owner))
        records.append(dict(label=label, path=str(path), sha256=digest(path), bytes=table['sh_size'], slots=slots))
(out/'inventory.json').write_text(json.dumps(records, indent=2)+'\n')
for name in ('result.json', 'compile-command.json'):
    shutil.copyfile(build/name, out/name)
(out/'build-inputs.json').write_text(json.dumps({name: dict(path=str(build/name), sha256=digest(build/name))
    for name in ('fixture.native.o', 'fixture.proof.o')}, indent=2)+'\n')
for stage in ('rust', 'rust-fixed', 'final'):
    destination = out/stage
    destination.mkdir(exist_ok=True)
    for name in ('make-command.txt', 'make.log', 'exit-code', 'finished'):
        shutil.copyfile(raw/stage/'job'/name, destination/name)
