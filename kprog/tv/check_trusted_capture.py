"""Check exact binding of the accepted single-region, relocation-free artifact.

Uses existing checked/emitted parsers. No ISA interpretation or TV claim.
Expected entry/ABI/architecture and saved hashes are external certificate inputs.
"""
import hashlib
import io
import json
import re
from pathlib import Path
import struct
import tarfile
from extract_checked import decode
from emitted_sites import validate_emitted
from elftools.elf.elffile import ELFFile
from elftools.common.exceptions import ELFError



def generated_components(request):
    result = {}
    for suffix in ('.blob.bin', '.abi.tsv', '.data-layout.json', '.map-patches.tsv', '.relocs.bin'):
        names = [name for name in request if name.endswith(suffix)]
        if len(names) != 1:
            raise ValueError('one generated materialization component required: '+suffix)
        result[suffix] = names[0]
    return result


def elf_entry_view(source, entry):
    # A deliberately narrow structural certificate for the two captured,
    # single-function ET_REL inputs. This is not ELF/ISA execution semantics.
    try:
        elf = ELFFile(io.BytesIO(source))
        if elf.elfclass != 64 or not elf.little_endian or elf['e_type'] != 'ET_REL' or \
                elf['e_machine'] != 'EM_X86_64' or elf['e_entry'] != 0 or elf['e_flags'] != 0 or \
                elf['e_ident']['EI_OSABI'] != 'ELFOSABI_SYSV' or elf['e_ident']['EI_ABIVERSION'] != 0:
            raise ValueError('unsupported immutable native ELF/ABI')
        symbols = [(section, i, symbol) for section in elf.iter_sections()
            if section['sh_type'] == 'SHT_SYMTAB'
            for i, symbol in enumerate(section.iter_symbols()) if symbol.name == entry]
        if len(symbols) != 1:
            raise ValueError('one exact immutable native entry symbol required')
        table, index, symbol = symbols[0]
        section_index = symbol['st_shndx']
        if symbol['st_info']['type'] != 'STT_FUNC' or symbol['st_info']['bind'] != 'STB_GLOBAL' or \
                not isinstance(section_index, int) or section_index == 0:
            raise ValueError('immutable entry must be a defined global function')
        section = elf.get_section(section_index)
        code = section.data()
        if section['sh_type'] != 'SHT_PROGBITS' or section['sh_flags'] != 6 or \
                symbol['st_value'] != 0 or symbol['st_size'] != len(code) or not code:
            raise ValueError('entry must exactly span the single readonly executable section')
        for i, other in enumerate(elf.iter_sections()):
            if i != section_index and other['sh_flags'] & 4 and other['sh_size']:
                raise ValueError('additional executable section outside this certificate')
            if other['sh_type'] in ('SHT_REL','SHT_RELA') and other['sh_info'] == section_index and other.num_relocations():
                raise ValueError('entry relocations outside this certificate')
        return code, section['sh_offset'], table['sh_offset']+index*table['sh_entsize']
    except ELFError as error:
        raise ValueError('invalid immutable native ELF') from error


def materialization_relation(files, request, expected):
    original = request['kernel.native.o']
    if original != request['request.native.o']:
        raise ValueError('specializer native copy differs from immutable kernel input')
    code, _, _ = elf_entry_view(original, expected['entry'])
    if code != files['native.bin']+b'\xc3':
        raise ValueError('immutable entry differs from exact payload plus terminal RET')
    components = generated_components(request)
    if request[components['.blob.bin']] != files['native.bin']:
        raise ValueError('generated blob differs from bound/emitted payload')
    if request[components['.relocs.bin']] or files['native.relocs']:
        raise ValueError('materialization certificate requires no native relocation')
    abi = [line.split('\t') for line in request[components['.abi.tsv']].decode().splitlines()]
    if abi != [['version','native-link-abi-v2'],['callee_saved_mask',str(expected['abi'])]]:
        raise ValueError('generated supported ABI/version/mask differs')
    if json.loads(request[components['.data-layout.json']]) != {'version':1,'objects':[]} or \
            request[components['.map-patches.tsv']]:
        raise ValueError('materialization certificate requires no data/map transformation')
    return dict(immutable_ELF_sha256=hashlib.sha256(original).hexdigest(),
        entry=expected['entry'],entry_offset=0,entry_bytes=len(code),payload_bytes=len(files['native.bin']),
        exact_entry_relation='immutable entry bytes = emitted payload bytes ++ c3',
        terminal_bytes_removed='c3',generated_copy_byte_identical=True,
        native_link_abi='native-link-abi-v2',callee_saved_mask=expected['abi'],
        relocations=0,data_objects=0,map_patches=0,structural_only=True,
        remaining='RET/entry-ABI/platform semantic transport and universal relational TV')


def materialization_controls(files, request, expected):
    components = generated_components(request)
    original = request['kernel.native.o']
    _, code_offset, symbol_offset = elf_entry_view(original, expected['entry'])
    controls = []
    names = ['immutable input SHA','generated copy','entry offset','entry code','terminal RET',
        'ELF machine','ELF type','ABI version','ABI mask','generated blob','data layout',
        'map patches','native relocations','duplicate blob']
    for name in names:
        f, r = dict(files), dict(request)
        source = bytearray(original)
        if name == 'immutable input SHA': source[-1] ^= 1
        if name == 'generated copy':
            copy = bytearray(r['request.native.o']);copy[-1] ^= 1;r['request.native.o'] = bytes(copy)
        if name == 'entry offset': struct.pack_into('<Q',source,symbol_offset+8,1)
        if name == 'entry code': source[code_offset] ^= 1
        if name == 'terminal RET': source[code_offset+len(f['native.bin'])] = 0x90
        if name == 'ELF machine': struct.pack_into('<H',source,18,183)
        if name == 'ELF type': struct.pack_into('<H',source,16,3)
        if name in ('immutable input SHA','entry offset','entry code','terminal RET','ELF machine','ELF type'):
            r['kernel.native.o'] = bytes(source);r['request.native.o'] = bytes(source)
        if name == 'ABI version': r[components['.abi.tsv']] = r[components['.abi.tsv']].replace(b'abi-v2',b'abi-v3')
        if name == 'ABI mask': r[components['.abi.tsv']] = r[components['.abi.tsv']].replace(b'mask\t0',b'mask\t1')
        if name == 'generated blob':
            blob = bytearray(r[components['.blob.bin']]);blob[-1] ^= 1;r[components['.blob.bin']] = bytes(blob)
        if name == 'data layout': r[components['.data-layout.json']] = b'{"version":1,"objects":[{}]}'
        if name == 'map patches': r[components['.map-patches.tsv']] = b'0\t1\n'
        if name == 'native relocations': r[components['.relocs.bin']] = bytes(16)
        if name == 'duplicate blob': r['duplicate.blob.bin'] = f['native.bin']
        try:
            # Only this control uses the original SHA anchor; all other
            # mutations directly exercise structural relations without hashes.
            if name == 'immutable input SHA': validate(f,r,expected,{})
            else: materialization_relation(f,r,expected)
        except ValueError: controls.append(name)
        else: raise AssertionError('materialization mismatch accepted: '+name)
    return controls

def validate(files, request, expected, pins):
    if hashlib.sha256(request['kernel.native.o']).hexdigest() != expected['native_sha256']:
        raise ValueError('immutable kernel ELF differs from original completion SHA')
    materialization = materialization_relation(files,request,expected)
    for name, digest in pins.items():
        if hashlib.sha256(files[name]).hexdigest() != digest:
            raise ValueError('accepted artifact bytes changed: '+name)
    program, metadata = decode(files['checked.snapshot.bin'])
    binding = metadata['binding']
    if binding[1] != expected['arch'] or binding[4] != expected['abi'] or \
            request['kernel.entry'].decode() != expected['entry']:
        raise ValueError('expected entry/architecture/ABI differs')
    envelope = json.loads(request['kernel.metadata.json'])
    facts = json.loads(request['kernel.facts.json'])
    fields = dict(prog_type=12, expected_attach_type=13, prog_flags=16,
        attach_btf_id=17, attach_btf_obj_id=18, attach_prog_id=19, prog_ifindex=20)
    if envelope['version'] != 1 or envelope['maps'] or facts['maps']:
        raise ValueError('this certificate requires the actual mapless context')
    for name, index in fields.items():
        if envelope['load_context'][name] != binding[index] or facts[name] != binding[index]:
            raise ValueError('capsule metadata differs from pinned context/binding: '+name)
    if facts['id'] != binding[21] or facts['gpl_compatible'] != binding[22]:
        raise ValueError('kernel source identity differs')
    load = json.loads(files['load.json'])
    if load['version'] != 1 or load['source_prog_id'] != binding[21] or \
            load['generation'] != metadata['generation'] or load['prog_type'] != binding[12]:
        raise ValueError('load receipt differs from binding')
    if len(metadata['regions']) != 1 or binding[8] != 1 or binding[4] != 0:
        raise ValueError('this proof correspondence requires one region and no ABI markers')
    start, count, _ = metadata['regions'][0]
    proof = files['proof-input.bin']
    if start != 0 or len(proof) != binding[11]*8 or count*8 != len(proof) or len(program) != len(proof)+8:
        raise ValueError('proof instantiation extent differs')
    instantiated = bytearray(proof)
    exits = 0
    for pc in range(len(proof)//8):
        if proof[pc*8] == 0x95:
            exits += 1
            struct.pack_into('<BBhi', instantiated, pc*8, 5, 0, len(proof)//8-pc-1, 0)
    if not exits or program != bytes(instantiated)+bytes.fromhex('9500000000000000'):
        raise ValueError('actual accepted B differs from instantiated proof input')
    sites = validate_emitted(files['emitted.bin'], metadata, files['native.bin'], files['native.relocs'],
        files['jit.bin'], files['jit-addresses.bin'], files['jit-lengths.bin'])
    return dict(native_bytes=len(files['native.bin']), verifier_insns=len(program)//8,
        source_prog_id=load['source_prog_id'], native_prog_id=load['native_prog_id'], emitted_sites=sites,
        materialization=materialization)


def check(directory, expected):
    saved = json.loads((directory/'summary.json').read_text())
    expected = dict(expected,native_sha256=saved['completion']['native_sha256'])
    if hashlib.sha256((directory/'artifacts.tar.gz').read_bytes()).hexdigest() != saved['archive_sha256']:
        raise ValueError('accepted archive differs from external capture SHA')
    with tarfile.open(directory/'artifacts.tar.gz') as archive:
        members = [m for m in archive.getmembers() if m.isfile()]
        files = {Path(m.name).name:archive.extractfile(m).read() for m in members if '/capture/' in m.name}
        success = [m for m in members if m.name.endswith('.success.tar.gz')]
        if len(success) != 1: raise ValueError('one completed service request required')
        with tarfile.open(fileobj=io.BytesIO(archive.extractfile(success[0]).read())) as inner:
            request = {Path(m.name).name:inner.extractfile(m).read() for m in inner.getmembers()
                if m.isfile() and (m.name.startswith('request/kernel.') or
                    m.name == 'request/generated/request.native.o' or
                    ('/generated/kernel-link/' in m.name and m.name.endswith(
                        ('.blob.bin','.abi.tsv','.data-layout.json','.map-patches.tsv','.relocs.bin'))))}
    if expected['entry'] == 'simple_xdp':
        lean = Path(__file__).with_name('TrustedSimpleX86.lean').read_text()
        captured, _ = decode(files['checked.snapshot.bin'])
        for name, actual in [('native', files['native.bin']), ('proof', captured)]:
            literal = re.search(r'def '+name+r' : Array Byte := #\[([^\]]+)\]', lean)
            if literal is None or bytes(int(x, 0) for x in literal[1].split(',')) != actual:
                raise ValueError('Lean literals differ from accepted artifact: '+name)
    pins = saved['capture_sha256']
    positive = validate(files, request, expected, pins)
    controls = []
    mutations = [('entry', 'request'), ('abi', 'expected'), ('architecture','expected'),
        ('metadata', 'request'), ('proof', 'files'), ('native', 'files'), ('RX entry', 'files'), ('accepted B','files')]
    for name, _ in mutations:
        f, r, e = dict(files), dict(request), dict(expected)
        if name=='entry': r['kernel.entry'] += b'_wrong'
        if name=='abi': e['abi']=1
        if name=='architecture': e['arch']=2
        if name=='metadata':
            v=json.loads(r['kernel.metadata.json']);v['load_context']['prog_flags']^=1
            r['kernel.metadata.json']=json.dumps(v).encode()
        target={'proof':'proof-input.bin','native':'native.bin','RX entry':'emitted.bin','accepted B':'checked.snapshot.bin'}.get(name)
        if target:
            v=bytearray(f[target]);v[-1]^=1;f[target]=bytes(v)
        try: validate(f,r,e,pins)
        except ValueError: controls.append(name)
        else: raise AssertionError('binding mismatch accepted: '+name)
    # Bypass the external byte pins to check structural relations themselves.
    for name, target in [('proof correspondence','proof-input.bin'),('RX bytes','native.bin'),('RX address','emitted.bin')]:
        f=dict(files);v=bytearray(f[target]);v[4 if target=='proof-input.bin' else -1]^=1;f[target]=bytes(v)
        try: validate(f,request,expected,{})
        except ValueError: controls.append(name)
        else: raise AssertionError('structural binding mismatch accepted: '+name)
    return dict(binding='passed', translation_validation='not_discharged', **positive,
        rejected_controls=controls, materialization_rejected_controls=materialization_controls(files,request,expected), expected=expected,
        trusted=['kernel capture/binding code and archived accepted-byte provenance',
            'registered specialization/link service until per-program TV connects output to immutable P',
            'verifier soundness', 'reference ISA/platform semantics when refinement is supplied',
            'structural ELF/archive parser and checker; terminal RET semantic transport remains open'])

if __name__=='__main__':
    root=Path(__file__).resolve().parents[1]/'results/kprog_tv_20261107'
    results={name:check(root/name,dict(arch=1,abi=0,entry=entry)) for name,entry in
        [('trusted-capture','trusted_entry'),('trusted-simple','simple_xdp')]}
    results['checker_sha256']={str(p.relative_to(root.parents[2])):hashlib.sha256(p.read_bytes()).hexdigest()
        for p in [Path(__file__),Path(__file__).with_name('emitted_sites.py'),Path(__file__).with_name('extract_checked.py')]}
    (root/'trusted-binding.json').write_text(json.dumps(results,indent=2)+'\n')
    rejected=sum(len(results[name]['materialization_rejected_controls']) for name in ('trusted-capture','trusted-simple'))
    print('actual native-only control/simple binding: PASS; 22 mismatch controls rejected; '+str(rejected)+' materialization controls rejected; RET semantic transport remains separate')
