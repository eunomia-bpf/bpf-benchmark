"""Capture accepted kernel/JIT artifacts through the common native-only service.

One control request, no alternate broker or specialization implementation.
Raw per-load bytes are compressed, hashed and deleted at completion.
"""
from pathlib import Path
import argparse
import hashlib
import json
import os
import signal
import struct
import subprocess
import tarfile
import tempfile

ROOT = Path(__file__).resolve().parents[2]

def digest(path):
    value = hashlib.sha256()
    with path.open('rb') as source:
        for block in iter(lambda: source.read(1024 * 1024), b''):
            value.update(block)
    return value.hexdigest()


def gnu_build_ids(notes):
    """GNU build IDs from little-endian, four-byte aligned ELF note records."""
    result = []
    offset = 0
    while offset < len(notes):
        if len(notes) - offset < 12:
            raise ValueError('truncated ELF note header')
        namesz, descsz, kind = struct.unpack_from('<III', notes, offset)
        offset += 12
        name_end = offset + namesz
        desc_start = (name_end + 3) & ~3
        desc_end = desc_start + descsz
        if desc_end > len(notes):
            raise ValueError('truncated ELF note payload')
        if notes[offset:name_end] == b'GNU\0' and kind == 3:
            result.append(notes[desc_start:desc_end].hex())
        offset = (desc_end + 3) & ~3
    return result


def elf_build_ids(path, receipt):
    output = subprocess.check_output(['readelf', '-n', str(path)], text=True)
    receipt.write_text(output)
    return [line.split('Build ID: ', 1)[1].strip()
            for line in output.splitlines() if 'Build ID: ' in line]


def kernel_identity(live):
    notes = live / 'running-kernel.notes'
    notes.write_bytes(Path('/sys/kernel/notes').read_bytes())
    kernel = ROOT / 'kprog/tv/build-kernel-x86'
    vmlinux = kernel / 'vmlinux'
    image = kernel / 'arch/x86/boot/bzImage'
    profile_path = ROOT / 'kprog/results/kprog_tv_20261107/trusted-simple-kernel-xdp-layout.json'
    profile = json.loads(profile_path.read_text())
    result = dict(uname=list(os.uname()), running_notes_sha256=digest(notes),
        running_build_ids=gnu_build_ids(notes.read_bytes()),
        vmlinux_build_ids=elf_build_ids(vmlinux, live / 'vmlinux.notes.txt'),
        kernel_sha256={str(p.relative_to(ROOT)): digest(p) for p in (vmlinux, image)},
        layout_profile_sha256=digest(profile_path),
        interpretation='structural XDP layout profile; not a post-conversion instruction capture')
    result['running_matches_vmlinux'] = (len(result['vmlinux_build_ids']) == 1 and
        result['running_build_ids'] == result['vmlinux_build_ids'])
    result['layout_profile_matches_kernel'] = (
        result['vmlinux_build_ids'] == [profile['kernel_build_id']] and all(
            profile['source_sha256'][p] == value for p, value in result['kernel_sha256'].items()))
    module = ROOT / 'kprog/tv/build-x86/bpf_x86_native_lab.ko'
    module_note = Path('/sys/module/bpf_x86_native_lab/notes/.note.gnu.build-id')
    if module_note.is_file():
        raw = live / 'loaded-module.notes'
        raw.write_bytes(module_note.read_bytes())
        result['loaded_module_build_ids'] = gnu_build_ids(raw.read_bytes())
        result['module_file_build_ids'] = elf_build_ids(module, live / 'module.notes.txt')
        result['loaded_module_matches_file'] = (len(result['module_file_build_ids']) == 1 and
            result['loaded_module_build_ids'] == result['module_file_build_ids'])
    (live / 'kernel-identity.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('case', nargs='?', choices=['simple'])
    parser.add_argument('--output-dir', type=Path,
                        help='fresh result directory (existing captures are preserved)')
    args = parser.parse_args()
    SIMPLE = args.case == 'simple'
    OUT = args.output_dir or ROOT / 'kprog/results/kprog_tv_20261107' / (
        'trusted-simple' if SIMPLE else 'trusted-capture')
    if any((OUT / name).exists() for name in ('summary.json', 'artifacts.tar.gz')):
        raise FileExistsError('capture already exists; select a fresh --output-dir')
    OUT.mkdir(parents=True, exist_ok=True)
    summary = dict(ok=False, program='simple' if SIMPLE else 'return2-control', architecture='x86', route='registered native-only common service')
    with tempfile.TemporaryDirectory(prefix='.live-', dir=OUT) as temporary:
        live = Path(temporary)
        state = live / 'requests'
        environment = dict(os.environ, BPFREJIT_NATIVE_LOADER_TV_DIR=str(live / 'capture'))
        service = subprocess.Popen([
            'python3', str(ROOT / 'kprog/trusted_service.py'), '--arch', '1',
            '--endpoint', '/sys/kernel/debug/bpf_x86_native_lab/specializer',
            '--state', str(state), '--native-link', str(ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'),
            '--loader', str(ROOT / 'kprog/libnativeloader/build/trusted-native-loader')],
            env=environment, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            text=True, start_new_session=True)
        lines = []
        try:
            summary['kernel_identity'] = kernel_identity(live)
            identity = summary['kernel_identity']
            if not identity['running_matches_vmlinux'] or not identity['layout_profile_matches_kernel'] or \
                    identity.get('loaded_module_matches_file') is False:
                raise RuntimeError('running kernel/module differs from captured build/profile')
            lines.append(service.stdout.readline())
            if not json.loads(lines[-1]).get('ready'):
                raise RuntimeError('common service did not register')
            client_argv = [ROOT / 'kprog/tv/build/trusted-simple-client',
                ROOT / 'micro/programs/build-host-docker-x86/simple.bpf.o',
                ROOT / 'kprog/tv/build/simple.native.o'] if SIMPLE else [
                ROOT / 'kprog/libnativeloader/build/trusted-service-client',
                ROOT / 'kprog/libnativeloader/build/trusted-native.o']
            result = subprocess.run([str(p) for p in client_argv],
                text=True, capture_output=True)
            (live / 'client.stdout').write_text(result.stdout)
            (live / 'client.stderr').write_text(result.stderr)
            result.check_returncode()
            client = json.loads(result.stdout)
            lines.append(service.stdout.readline())
            completion = json.loads(lines[-1])
            if not client['ok'] or client['retval'] != 2 or client['prebuilt_proof'] or \
                completion['status'] or completion['prog_id'] != client['native_prog_id']:
                raise RuntimeError('actual accepted native control/result identity differs')
            record = live / 'capture' / (str(client['original_prog_id']) + '-' + str(client['native_prog_id']))
            required = ['checked.snapshot.bin', 'emitted.bin', 'native.bin', 'native.relocs',
                'proof-input.bin', 'jit.bin', 'jit-addresses.bin', 'jit-lengths.bin', 'stub.bin', 'load.json']
            for name in required:
                if not (record / name).is_file():
                    raise RuntimeError('missing actual kernel/JIT artifact: ' + name)
            identity = json.loads((record / 'load.json').read_text())
            if identity['native_prog_id'] != client['native_prog_id'] or identity['source_prog_id'] != client['original_prog_id']:
                raise RuntimeError('captured load identity differs from returned native program')
            summary.update(ok=True, client=client, completion=completion,
                application_inputs={str(p.relative_to(ROOT)):digest(p) for p in client_argv},
                capture_sha256={name: digest(record / name) for name in required},
                sources={str(path.relative_to(ROOT)): digest(path) for path in [
                    ROOT / 'kprog/libnativeloader/src/native_tv_capture.hpp',
                    ROOT / 'kinsn/module/include/native_lab_checked.h',
                    ROOT / 'kinsn/module/x86/bpf_x86_native_lab.c',
                    ROOT / 'kprog/tv/build-x86/bpf_x86_native_lab.ko']},
                validated_by_loader='actual checked binding/generation/context; emission entry inside actual JIT layout; exact native bytes when no relocation',
                remaining='ISA/translation certificate and trust of kernel binding code are not discharged by capture')
        except Exception as error:
            summary.update(error=str(error))
            raise
        finally:
            if service.poll() is None:
                os.killpg(service.pid, signal.SIGTERM)
            service.wait()
            lines.extend(service.stdout.readlines())
            (live / 'service.log').write_text(''.join(lines))
            (live / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
            archive = OUT / 'artifacts.tar.gz'
            with tarfile.open(archive, 'w:gz') as output:
                output.add(live, arcname='run')
            summary['archive_sha256'] = digest(archive)
            (OUT / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    print('trusted native-only kernel/JIT artifact capture: PASS')

if __name__ == '__main__':
    main()
