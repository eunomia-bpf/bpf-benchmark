"""Capture accepted kernel/JIT artifacts through the common native-only service.

One control request, no alternate broker or specialization implementation.
Raw per-load bytes are compressed, hashed and deleted at completion.
"""
from pathlib import Path
import hashlib
import json
import os
import signal
import subprocess
import tarfile
import tempfile

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'kprog/results/kprog_tv_20261107/trusted-capture'

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    OUT.mkdir(parents=True, exist_ok=True)
    summary = dict(ok=False, architecture='x86', route='registered native-only common service')
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
            lines.append(service.stdout.readline())
            if not json.loads(lines[-1]).get('ready'):
                raise RuntimeError('common service did not register')
            result = subprocess.run([str(ROOT / 'kprog/libnativeloader/build/trusted-service-client'),
                str(ROOT / 'kprog/libnativeloader/build/trusted-native.o')],
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
