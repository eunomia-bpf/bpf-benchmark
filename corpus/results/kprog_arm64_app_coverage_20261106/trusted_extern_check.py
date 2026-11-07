"""Compile ARM trusted externs while preserving ELF identities and relative bases."""
import copy
import gzip
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'kprog'))
from trusted_service import adapter
from trusted_generation import c_symbol_aliases, declarations
worker = adapter(2)
link = ROOT / 'kprog/arm64/build/app-native-link/release/native-link'
OUT = HERE / 'trusted-extern-result'
OUT.mkdir(exist_ok=True)
summary = dict(scope='generation/compiler ABI checks, not kernel/verifier/application acceptance', cases=[])
inputs = [Path(worker.__file__), ROOT / 'kprog/trusted_generation.py',
    ROOT / 'kprog/arm64/micro-prog/generate_micro_sim_proofs.py', link]
summary['input_sha256'] = {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}


def inspect(result, expected):
    source = Path(result['simulator_object']).with_suffix('.c').read_text()
    with Path(result['simulator_object']).open('rb') as stream:
        elf = ELFFile(stream)
        assert elf.get_section_by_name('.maps') is None
        assert elf.get_section_by_name('.native_lab.source_maps') is None
        assert elf.get_section_by_name('.native_lab.rodata') is None
        symbols = elf.get_section_by_name('.symtab')
        undefined = {s.name for s in symbols.iter_symbols() if s['st_shndx'] == 'SHN_UNDEF' and s.name}
        assert undefined == expected, (undefined, expected)
        entry = next(s for s in symbols.iter_symbols() if s.name == result['simulator_program'])
        section = elf.get_section(entry['st_shndx'])
        records = []
        for relsec in elf.iter_sections():
            if relsec['sh_type'] not in ('SHT_REL', 'SHT_RELA') or relsec['sh_info'] != entry['st_shndx']:
                continue
            names = elf.get_section(relsec['sh_link'])
            for rel in relsec.iter_relocations():
                symbol = names.get_symbol(rel['r_info_sym']).name
                if symbol not in expected:
                    continue
                site = rel['r_offset']
                assert section.data()[site] == 0x18
                low = int.from_bytes(section.data()[site+4:site+8], 'little', signed=True)
                high = int.from_bytes(section.data()[site+12:site+16], 'little', signed=True)
                records.append(dict(symbol=symbol, offset=site, low=low, high=high,
                                    addend=rel['r_addend'] if relsec['sh_type'] == 'SHT_RELA' else None))
        assert {r['symbol'] for r in records} == expected
        return source, section.data(), records


with tempfile.TemporaryDirectory(prefix='arm64-extern-', dir=ROOT / 'kprog/arm64/build/trusted-transport') as temporary:
    base = Path(temporary)
    fixture = base / 'fixture.c'
    fixture.write_text('volatile unsigned int a[16] __asm__("sys_exit.zero");\n'
        'volatile unsigned int b[16] __asm__("__arm64_trusted_map_0");\n'
        'int trusted_entry(void *ctx) { (void)ctx; return a[2] ^ b[0]; }\n')
    native = base / 'fixture.o'
    subprocess.run(['aarch64-linux-gnu-gcc', '-O2', '-fPIC', '-ffreestanding',
        '-fno-asynchronous-unwind-tables', '-c', fixture, '-o', native], check=True)
    metadata = dict(version=1, prog_type=6, section='xdp', maps=[dict(name=n,
        map_type=2, key_size=4, value_size=128, max_entries=1, map_flags=0, value_offset=0)
        for n in ['sys_exit.zero', '__arm64_trusted_map_0']])
    aliases = c_symbol_aliases([m['name'] for m in metadata['maps']], '__arm64_trusted_map_')
    assert aliases['sys_exit.zero'] != aliases['__arm64_trusted_map_0']
    pairs = []
    for offset in [0, 8]:
        metadata['maps'][0]['value_offset'] = offset
        result = worker.specialize(native.read_bytes(), 'trusted_entry', metadata, base / ('direct'+str(offset)), link)
        source, code, relocs = inspect(result, set(aliases))
        assert '__asm__("sys_exit.zero")' in source and 'ARM64_SIM_TAG_MAP_VALUE' in source
        assert '(' + aliases['sys_exit.zero'] + ' + ' not in source
        pairs.append((source, code, relocs))
        summary['cases'].append(dict(case='dotted_alias_collision_direct'+str(offset), compile_returncode=0,
            native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(), aliases=aliases, map_relocations=relocs))
    assert pairs[0] == pairs[1], 'capsule direct-value base leaked into generated body'
    summary['direct0_direct8_source_and_instruction_bytes_identical'] = True
    rejected = []
    for bad in [True, -1, 0x100000000]:
        broken = copy.deepcopy(metadata); broken['maps'][0]['value_offset'] = bad
        try:
            worker.specialize(native.read_bytes(), 'trusted_entry', broken, base / 'must-not-create', link)
        except ValueError:
            rejected.append(repr(bad))
        else:
            raise AssertionError('invalid direct base accepted')
    assert not (base / 'must-not-create').exists()
    summary['invalid_direct_offsets_rejected_before_output'] = rejected
    metadata = json.loads((HERE / 'trusted-worker-result/metadata.json').read_text())
    required = set(json.loads((HERE / 'trusted-arm64-katran-result/map-membership-static-audit.json').read_text())['native_link_relocation_map_names'])
    metadata['maps'] = [m for m in metadata['maps'] if m['name'] in required]
    native = ROOT / 'kprog/arm64/build/app-verified-stage/katran/balancer.native.o'
    result = worker.specialize(native.read_bytes(), 'balancer_ingress', metadata, base / 'katran', link)
    _, _, relocs = inspect(result, required)
    summary['cases'].append(dict(case='actual_katran14_handles', compile_returncode=0,
        native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(), undefined_map_symbols=sorted(required),
        map_relocations=relocs, metadata_origin='stored typed host preparation; not runtime kernel facts'))
    # The old producer-side/original declaration API must remain byte-identical.
    import types
    reference = types.ModuleType('arm64_legacy_render_reference')
    reference.__file__ = worker.gen.__file__
    sys.modules[reference.__name__] = reference
    reference_blob = '5f9e0ee22e3a255ef4fbefacc98288e3b9277364'
    previous = subprocess.check_output(['git', 'show', reference_blob], text=True)
    exec(compile(previous, reference.__file__, 'exec'), reference.__dict__)
    functions, rodata = worker.gen.parse_native_linked_program(
        worker.gen.Bench('trusted_arm64', 'balancer_ingress', 'xdp'), base / 'katran')
    header = base / 'legacy-decls.h'
    declaration_text, symbols = declarations(metadata)
    header.write_text(declaration_text)
    arguments = dict(rodata16=rodata, linked_exit=True, original_source=header, original_symbols=symbols)
    old_text = reference.render_program('legacy', 'balancer_ingress', functions, 'xdp', **arguments)
    new_text = worker.gen.render_program('legacy', 'balancer_ingress', functions, 'xdp', **arguments)
    assert old_text == new_text
    (base / 'legacy-reference.c').write_text(old_text)
    summary['legacy_actual_katran_original_declaration_render_identical'] = dict(
        reference_generator_blob=reference_blob, generated_c_sha256=hashlib.sha256(old_text.encode()).hexdigest())
    with tarfile.open(OUT / 'compiler-inputs.tar.gz', 'w:gz') as archive:
        for p in base.rglob('*'):
            if p.is_file() and p.suffix in {'.c','.h','.o','.json','.jsonl'}:
                archive.add(p,arcname=p.relative_to(base))
summary['inputs_unchanged'] = all(hashlib.sha256(p.read_bytes()).hexdigest() == summary['input_sha256'][str(p.relative_to(ROOT))] for p in inputs)
assert summary['inputs_unchanged']
summary['ok'] = True
(OUT / 'summary.json').write_text(json.dumps(summary,indent=2)+chr(10))
print(json.dumps(summary))
