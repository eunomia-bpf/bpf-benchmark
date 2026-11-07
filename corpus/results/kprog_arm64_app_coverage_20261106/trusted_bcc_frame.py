"""Reproduce tcplife compiler frame with source-ELF map facts, without loading BPF."""
import ctypes as c
import hashlib
from io import BytesIO
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile
import tempfile
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/arm64'))
import trusted_specializer as worker


def source_maps(path):
    lib = c.CDLL('libbpf.so.1', use_errno=True)
    functions = [('bpf_object__open_file', [c.c_char_p, c.c_void_p], c.c_void_p),
        ('libbpf_get_error', [c.c_void_p], c.c_long),
        ('bpf_object__next_map', [c.c_void_p, c.c_void_p], c.c_void_p),
        ('bpf_map__name', [c.c_void_p], c.c_char_p),
        ('bpf_map__is_internal', [c.c_void_p], c.c_bool),
        ('bpf_object__close', [c.c_void_p], None)]
    fields = dict(map_type='type', key_size='key_size', value_size='value_size',
                  max_entries='max_entries', map_flags='map_flags')
    functions += [('bpf_map__' + n, [c.c_void_p], c.c_uint32) for n in fields.values()]
    for name, args, result in functions:
        fn = getattr(lib, name); fn.argtypes = args; fn.restype = result
    obj = lib.bpf_object__open_file(str(path).encode(), None)
    if not obj or lib.libbpf_get_error(obj):
        raise RuntimeError('libbpf could not open source ELF')
    rows = []
    try:
        pointer = None
        while True:
            pointer = lib.bpf_object__next_map(obj, pointer)
            if not pointer:
                break
            rows.append(dict(name=lib.bpf_map__name(pointer).decode(),
                internal=bool(lib.bpf_map__is_internal(pointer)),
                **{k:getattr(lib, 'bpf_map__'+v)(pointer) for k,v in fields.items()}))
    finally:
        lib.bpf_object__close(obj)
    return rows


def main():
    out = HERE / 'trusted-bcc-frame-result'
    out.mkdir(exist_ok=True)
    source = ROOT / 'vendor/build/.bcc-libbpf/none/arm64/output/tcplife.bpf.o'
    native = ROOT / 'kprog/arm64/build/app-verified-stage/bcc/tcplife.native.o'
    link = ROOT / 'kprog/arm64/build/app-native-link/release/native-link'
    inputs = [source, native, link, Path(worker.__file__),
        ROOT / 'kprog/trusted_generation.py', Path(worker.gen.__file__),
        ROOT / 'kprog/arm64/arm64_sim_local_bpf.h', ROOT / 'kprog/arm64/arm64_sim.h', Path(__file__)]
    hashes = {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
    maps = source_maps(source)
    ordinary = {m['name']:m for m in maps if not m['internal']}
    readonly = [m for m in maps if m['internal'] and m['name'].endswith('.rodata')]
    assert len(readonly) == 1
    src = ELFFile(BytesIO(source.read_bytes()))
    nat = ELFFile(BytesIO(native.read_bytes()))
    native_symbols = {s.name:s for s in nat.get_section_by_name('.symtab').iter_symbols()}
    bindings = []
    identities = []
    for symbol in src.get_section_by_name('.symtab').iter_symbols():
        if symbol['st_info']['type'] != 'STT_OBJECT' or type(symbol['st_shndx']) is not int:
            continue
        section = src.get_section(symbol['st_shndx'])
        if section.name not in {'.maps', '.rodata'}:
            continue
        other = native_symbols[symbol.name]
        assert other['st_size'] == symbol['st_size'] and other['st_value'] == symbol['st_value']
        ns = nat.get_section(other['st_shndx'])
        assert ns.name == section.name
        offset, size = symbol['st_value'], symbol['st_size']
        assert section.data()[offset:offset+size] == ns.data()[offset:offset+size]
        info = ordinary[symbol.name] if section.name == '.maps' else readonly[0]
        binding = {k:v for k,v in info.items() if k not in {'name','internal'}}
        binding.update(name=symbol.name, value_offset=None if section.name == '.maps' else offset)
        bindings.append(binding)
        identities.append(dict(symbol=symbol.name, section=section.name, offset=offset, size=size))
    metadata = dict(version=1, prog_type=5, section='tracepoint/sock/inet_sock_set_state', maps=bindings)
    summary = dict(scope='host compiler only; source libbpf pre-load facts, not kernel-pinned runtime facts',
        source_map_facts=maps, source_native_symbol_identities=identities, metadata=metadata, input_sha256=hashes)
    build = ROOT / 'kprog/arm64/build/trusted-transport'
    with tempfile.TemporaryDirectory(prefix='bcc-frame-', dir=build) as temporary:
        base = Path(temporary)
        result = worker.specialize(native.read_bytes(), 'inet_sock_set_state', metadata, base / 'worker', link)
        dump = subprocess.check_output(['llvm-objdump','-d',result['simulator_object']], text=True)
        (base / 'disassembly.txt').write_text(dump)
        offsets = [int(n,0) for n in re.findall(r'r10 - (0x[0-9a-f]+|[0-9]+)', dump)]
        if not offsets:
            raise RuntimeError('no BPF frame references found')
        summary.update(compile_returncode=0, maximum_fp_minus_offset=max(offsets),
            object_sha256=hashlib.sha256(Path(result['simulator_object']).read_bytes()).hexdigest())
        with tarfile.open(out / 'compiler-inputs.tar.gz', 'w:gz') as archive:
            archive.add(source, arcname='inputs/tcplife.source.bpf.o')
            archive.add(native, arcname='inputs/tcplife.native.o')
            for p in base.rglob('*'):
                if p.is_file():
                    archive.add(p, arcname='generated/'+str(p.relative_to(base)))
    summary['inputs_unchanged'] = all(hashlib.sha256(p.read_bytes()).hexdigest() == hashes[str(p.relative_to(ROOT))] for p in inputs)
    assert summary['inputs_unchanged']
    (out / 'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
