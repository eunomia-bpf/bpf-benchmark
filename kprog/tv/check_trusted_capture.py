"""Check exact binding of the accepted single-region, relocation-free artifact.

Uses existing checked/emitted parsers. No ISA interpretation or TV claim.
Expected entry/ABI/architecture and saved hashes are external certificate inputs.
"""
import hashlib
import io
import json
from pathlib import Path
import struct
import tarfile
from extract_checked import decode
from emitted_sites import validate_emitted


def validate(files, request, expected, pins):
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
        source_prog_id=load['source_prog_id'], native_prog_id=load['native_prog_id'], emitted_sites=sites)


def check(directory, expected):
    saved = json.loads((directory/'summary.json').read_text())
    with tarfile.open(directory/'artifacts.tar.gz') as archive:
        members = [m for m in archive.getmembers() if m.isfile()]
        files = {Path(m.name).name:archive.extractfile(m).read() for m in members if '/capture/' in m.name}
        success = [m for m in members if m.name.endswith('.success.tar.gz')]
        if len(success) != 1: raise ValueError('one completed service request required')
        with tarfile.open(fileobj=io.BytesIO(archive.extractfile(success[0]).read())) as inner:
            request = {Path(m.name).name:inner.extractfile(m).read() for m in inner.getmembers()
                if m.isfile() and m.name.startswith('request/kernel.')}
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
        rejected_controls=controls, expected=expected,
        trusted=['kernel capture/binding code and archived accepted-byte provenance',
            'registered specialization/link service until per-program TV connects output to immutable P',
            'verifier soundness', 'reference ISA/platform semantics when refinement is supplied'])

if __name__=='__main__':
    root=Path(__file__).resolve().parents[1]/'results/kprog_tv_20261107'
    results={name:check(root/name,dict(arch=1,abi=0,entry=entry)) for name,entry in
        [('trusted-capture','trusted_entry'),('trusted-simple','simple_xdp')]}
    results['checker_sha256']={str(p.relative_to(root.parents[2])):hashlib.sha256(p.read_bytes()).hexdigest()
        for p in [Path(__file__),Path(__file__).with_name('emitted_sites.py'),Path(__file__).with_name('extract_checked.py')]}
    (root/'trusted-binding.json').write_text(json.dumps(results,indent=2)+'\n')
    print('actual native-only control/simple binding: PASS; 22 mismatch controls rejected; ISA refinement remains separate')
