"""Check the captured simple x86 JIT envelope and live kernel return-symbol binding.

Structural identity only. Architectural effects use TrustedSimpleJIT.lean;
this parser neither interprets native instructions nor certifies current B30.
"""
import argparse
import copy
import io
import hashlib
import json
from pathlib import Path
import struct
import tarfile

from capture_trusted_service import digest, gnu_build_ids
from check_trusted_capture import validate, materialization_controls

ROOT = Path(__file__).resolve().parents[2]
PROFILE = ROOT / 'kprog/results/kprog_tv_20261107/trusted-simple-kernel-xdp-layout.json'


def envelope(files, kernel):
    jit = files['jit.bin']
    prefix = bytes.fromhex('0f1f4400000f1f00554889e54157')
    if len(jit) != 82 or jit[:14] != prefix or jit[14:74] != files['native.bin'] or \
            jit[74:78] != bytes.fromhex('415fc9e9'):
        raise ValueError('JIT entry/save/native/restore envelope differs')
    if len(files['jit-addresses.bin']) != 8 or files['jit-lengths.bin'] != struct.pack('<I',82):
        raise ValueError('one exact captured JIT function required')
    base, = struct.unpack('<Q', files['jit-addresses.bin'])
    profile = json.loads(PROFILE.read_text())
    expected_images = {p:profile['source_sha256'][p] for p in
        ('kprog/tv/build-kernel-x86/vmlinux','kprog/tv/build-kernel-x86/arch/x86/boot/bzImage')}
    if kernel['running_build_ids'] != [profile['kernel_build_id']] or \
            kernel['vmlinux_build_ids'] != kernel['running_build_ids'] or \
            kernel['layout_profile_sha256'] != digest(PROFILE) or kernel['kernel_sha256'] != expected_images:
        raise ValueError('running kernel/build/layout identity differs')
    symbols = kernel['symbols']
    names = {'_text','its_return_thunk','__x86_return_thunk'}
    if not names <= symbols['running'].keys() or not names <= symbols['vmlinux'].keys():
        raise ValueError('live and compiled kernel symbols required')
    if not all(symbols['running'][name] and symbols['vmlinux'][name] for name in names):
        raise ValueError('kernel symbols hidden or null')
    slides = {name:(symbols['running'][name]-symbols['vmlinux'][name]) % 2**64 for name in names}
    if not symbols['all_three_share_slide'] or len(set(slides.values())) != 1 or slides != symbols['relocation_by_symbol']:
        raise ValueError('kernel symbols disagree on actual relocation')
    # Bind the captured relocation field to the live symbol. Execution of this
    # byte-decoded jump belongs to the single canonical ISA certificate.
    target = (base+82+struct.unpack_from('<i',jit,78)[0]) % 2**64
    if target != symbols['running']['its_return_thunk']:
        raise ValueError('captured return edge differs from live its_return_thunk')
    before, after = kernel.get('return_text_before'), kernel.get('return_text_after')
    text_verified = False
    if before and before.get('status') == 'captured':
        expected = bytes.fromhex('c3cc')
        if before != after or not kernel['return_text_stable'] or before['address'] != target or \
                before['bytes'] != 2 or before['hex'] != expected.hex() or \
                before['sha256'] != hashlib.sha256(expected).hexdigest():
            raise ValueError('observed return-thunk text differs or is unstable')
        text_verified = True
    return dict(jit_base=base, native_entry=base+14, native_end=base+74,
                native_bytes=60, caller_SP_to_body_SP=-16, saved_BP_offset=-8,
                saved_R15_offset=-16, return_target=target,
                kernel_symbol='its_return_thunk', kernel_relocation=slides['_text'],
                runtime_return_text_verified=text_verified,
                runtime_thunk_text='captured stable C3/CC before and after execution' if text_verified else
                    'not captured; alternatives/thunk execution remain trusted')



def check(directory):
    saved = json.loads((directory/'summary.json').read_text())
    if not saved['ok'] or digest(directory/'artifacts.tar.gz') != saved['archive_sha256']:
        raise ValueError('capture failed or archive identity differs')
    with tarfile.open(directory/'artifacts.tar.gz') as archive:
        members = [m for m in archive.getmembers() if m.isfile()]
        captured = [m for m in members if '/capture/' in m.name]
        if len({Path(m.name).name for m in captured}) != len(captured):
            raise ValueError('duplicate captured artifact name')
        files = {Path(m.name).name:archive.extractfile(m).read() for m in captured}
        initial = json.loads(archive.extractfile('run/kernel-identity.json').read())
        completed = json.loads(archive.extractfile('run/summary.json').read())
        kernel = completed['kernel_identity']
        before = {k:v for k,v in kernel.items() if k not in ('return_text_after','return_text_stable')}
        if initial not in (kernel,before) or completed['ok'] != saved['ok'] or kernel != saved['kernel_identity'] or \
                gnu_build_ids(archive.extractfile('run/running-kernel.notes').read()) != kernel['running_build_ids']:
            raise ValueError('archived actual kernel notes/identity differ')
        raw_symbols = archive.extractfile('run/running-kernel-symbols.txt').read().decode().splitlines()
        raw_running = {line.split()[2]:int(line.split()[0],16) for line in raw_symbols}
        if raw_running != kernel['symbols']['running']:
            raise ValueError('live symbol receipt differs from raw kernel output')
        raw_compiled = archive.extractfile('run/vmlinux-symbols.txt').read().decode().splitlines()
        if {line.split()[-1]:int(line.split()[1],16) for line in raw_compiled} != kernel['symbols']['vmlinux']:
            raise ValueError('compiled symbol receipt differs from archived ELF output')
        if gnu_build_ids(archive.extractfile('run/loaded-module.notes').read()) != kernel['loaded_module_build_ids'] or \
                kernel['loaded_module_build_ids'] != kernel['module_file_build_ids']:
            raise ValueError('loaded module note identity differs')
        for label in ['before','after']:
            sample = kernel.get('return_text_'+label,{})
            if sample.get('status') == 'captured':
                code = archive.extractfile('run/return-text-'+label+'.bin').read()
                segment = archive.extractfile('run/return-text-'+label+'.segment.bin').read()
                kind,_,_,start,_,length,_,_ = struct.unpack('<IIQQQQQQ',segment)
                if code.hex() != sample['hex'] or hashlib.sha256(code).hexdigest() != sample['sha256'] or \
                        len(code) != 2 or kind != 1 or not start <= sample['address'] < start+length-1:
                    raise ValueError('raw live return-text/segment receipt differs')
        success = [m for m in members if m.name.endswith('.success.tar.gz')]
        if len(success) != 1:
            raise ValueError('one completed trusted request required')
        with tarfile.open(fileobj=io.BytesIO(archive.extractfile(success[0]).read())) as inner:
            request = {Path(m.name).name:inner.extractfile(m).read() for m in inner.getmembers()
                if m.isfile() and (m.name.startswith('request/kernel.') or
                    m.name == 'request/generated/request.native.o' or
                    ('/generated/kernel-link/' in m.name and m.name.endswith(
                        ('.blob.bin','.abi.tsv','.data-layout.json','.map-patches.tsv','.relocs.bin'))))}
    expected = dict(arch=1,abi=0,entry='simple_xdp',native_sha256=saved['completion']['native_sha256'])
    binding = validate(files,request,expected,saved['capture_sha256'])
    layout = envelope(files,kernel)
    if binding['emitted_sites'][0]['entry_address'] != layout['native_entry']:
        raise ValueError('actual emitted entry differs from envelope entry')
    rejected = []
    cases = ['entry padding','restore opcode','return displacement','JIT base',
                 'live return symbol','live text symbol','compiled return symbol',
                 'symbol relocation receipt','kernel build ID','layout profile']
    if layout['runtime_return_text_verified']:
        cases += ['return instruction','return text address','return text SHA','return text instability']
    for name in cases:
        altered, identity = dict(files), copy.deepcopy(kernel)
        if name in ('entry padding','restore opcode','return displacement'):
            wire=bytearray(altered['jit.bin'])
            wire[{'entry padding':0,'restore opcode':74,'return displacement':78}[name]] ^= 1
            altered['jit.bin']=bytes(wire)
        if name == 'JIT base':
            altered['jit-addresses.bin']=struct.pack('<Q',layout['jit_base']+1)
        if name == 'live return symbol': identity['symbols']['running']['its_return_thunk'] += 1
        if name == 'live text symbol': identity['symbols']['running']['_text'] += 1
        if name == 'compiled return symbol': identity['symbols']['vmlinux']['its_return_thunk'] += 1
        if name == 'symbol relocation receipt': identity['symbols']['relocation_by_symbol']['_text'] += 1
        if name == 'kernel build ID': identity['running_build_ids']=['00']
        if name == 'layout profile': identity['layout_profile_sha256']='00'
        if name == 'return instruction':
            for label in ['before','after']:
                identity['return_text_'+label]['hex']='90cc'
                identity['return_text_'+label]['sha256']=hashlib.sha256(bytes.fromhex('90cc')).hexdigest()
        if name == 'return text address':
            for label in ['before','after']: identity['return_text_'+label]['address'] += 1
        if name == 'return text SHA':
            for label in ['before','after']: identity['return_text_'+label]['sha256']='00'
        if name == 'return text instability': identity['return_text_after']['hex']='90cc'
        try:
            envelope(altered,identity)
        except ValueError:
            rejected.append(name)
        else:
            raise AssertionError('invocation mismatch accepted: '+name)
    return dict(binding=binding,invocation_layout=layout,rejected_controls=rejected,
        materialization_rejected_controls=materialization_controls(files,request,expected),
        archive_sha256=saved['archive_sha256'],translation_validation='current B30 not validated',
        remaining=['canonical LEAVE/whole epilogue transport','actual kernel caller/context/stack permissions',
                   'canonical return execution composition','full-state TV of the accepted B'],
        trusted=['kernel capture/provenance and live symbol reporting','structural ELF/archive parser',
                 'verifier soundness and canonical ISA semantics when composing the separate certificate'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capture', type=Path)
    args = parser.parse_args()
    print(json.dumps(check(args.capture),indent=2))
