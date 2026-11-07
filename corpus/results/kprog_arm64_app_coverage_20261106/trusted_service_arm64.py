"""AArch64 full-system replay of the common native-only trusted service."""
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import queue
import signal
import subprocess
import sys
import tarfile
import tempfile
import threading
import traceback

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
LOADER = ROOT / 'kprog/libnativeloader/build-arm64-a-map-order-v3'
NATIVE_LINK = ROOT / 'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link'


def guest(live):
    """Use C's unchanged broker and T's unchanged portable application client."""
    live = Path(live)
    events = queue.Queue()
    state = live / 'requests'
    state.mkdir(mode=0o700)
    service = subprocess.Popen([sys.executable, ROOT / 'kprog/trusted_service.py',
        '--arch', '2', '--endpoint', '/sys/kernel/debug/bpf_arm64_native_lab/specializer',
        '--state', state, '--native-link', NATIVE_LINK,
        '--loader', LOADER / 'trusted-native-loader'],
        text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, start_new_session=True)
    def collect():
        with (live / 'service.log').open('w') as log:
            for line in service.stdout:
                log.write(line); log.flush(); events.put(line)
        events.put(None)
    reader = threading.Thread(target=collect)
    reader.start()
    summary = dict(ok=False, arch='arm64', started=datetime.now(timezone.utc).isoformat())
    def event():
        line = events.get()
        if line is None:
            raise RuntimeError('common service exited before receipt')
        return json.loads(line)
    try:
        ready = event()
        if not ready.get('ready') or ready['arch'] != 2:
            raise RuntimeError('ARM common service did not register')
        result = subprocess.run([LOADER / 'trusted-service-client', LOADER / 'trusted-native.o'],
            text=True, capture_output=True)
        (live / 'client.stdout').write_text(result.stdout)
        (live / 'client.stderr').write_text(result.stderr)
        summary['returncode'] = result.returncode
        result.check_returncode()
        client = json.loads(result.stdout)
        if not client['ok'] or client['retval'] != 2 or client['prebuilt_proof']:
            raise RuntimeError('bound ARM native result differs from expected 2')
        receipt = event()
        if receipt['status'] or receipt['prog_id'] != client['native_prog_id']:
            raise RuntimeError('service completion differs from application result')
        summary.update(client, receipt=receipt, ok=True)
    except Exception as error:
        summary.update(error=str(error), traceback=traceback.format_exc())
        raise
    finally:
        if service.poll() is None:
            try:
                os.killpg(service.pid, signal.SIGTERM)
            except ProcessLookupError:
                if service.poll() is None:
                    raise
        service.wait(); reader.join()
        summary['finished'] = datetime.now(timezone.utc).isoformat()
        (live / 'guest.json').write_text(json.dumps(summary, indent=2) + chr(10))


def host():
    """Mount the retained runtime read-only; use the new canonical Image/module."""
    build = ROOT / 'kprog/arm64/build/trusted-transport'
    build.mkdir(exist_ok=True)
    out = HERE / 'trusted-arm64-service-result'
    out.mkdir(exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    archive = out / ('run-' + stamp + '.tar.gz')
    summary = dict(ok=False, started=datetime.now(timezone.utc).isoformat(), archive=archive.name)
    with tempfile.TemporaryDirectory(prefix='service-', dir=build) as temporary:
        live = Path(temporary)
        image = ROOT / 'vendor/build/arm64/linux/arch/arm64/boot/Image'
        module = ROOT / 'kinsn/module/arm64/build/bpf_arm64_native_lab.ko'
        root = ROOT / 'kprog/arm64/build/app-runtime-v35/root'
        argv = ['taskset', '-c', '20-23', 'qemu-system-aarch64', '-M', 'virt',
            '-cpu', 'max', '-smp', '2', '-m', '2048', '-nographic', '-no-reboot',
            '-kernel', str(image), '-fsdev',
            'local,id=rootfs,path=' + str(root) + ',security_model=none,readonly=on',
            '-device', 'virtio-9p-device,fsdev=rootfs,mount_tag=rootfs',
            '-fsdev', 'local,id=repo,path=' + str(ROOT) + ',security_model=none',
            '-device', 'virtio-9p-device,fsdev=repo,mount_tag=repo', '-append',
            'console=ttyAMA0 root=rootfs rootfstype=9p rootflags=trans=virtio,version=9p2000.L ro init=/bin/sh loglevel=4 panic=-1 oops=panic']
        inputs = [image, module, LOADER / 'trusted-native-loader', LOADER / 'trusted-service-client',
            LOADER / 'trusted-native.o', NATIVE_LINK, ROOT / 'kprog/trusted_service.py',
            ROOT / 'kprog/trusted_loader.cpp', ROOT / 'kprog/trusted_generation.py',
            ROOT / 'kprog/arm64/trusted_specializer.py',
            ROOT / 'kprog/arm64/arm64_sim_local_bpf.h', ROOT / 'kprog/arm64/arm64_sim.h',
            ROOT / 'kprog/arm64/micro-prog/generate_micro_sim_proofs.py',
            ROOT / 'kinsn/module/include/native_lab_trusted_wire.h', Path(__file__)]
        summary['command'] = argv
        summary['hashes_before'] = {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
        (live / 'inputs.json').write_text(json.dumps(summary, indent=2) + chr(10))
        qemu = subprocess.Popen(argv, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        booted = False
        try:
            tail = b''
            with (live / 'qemu.log').open('wb') as log:
                while True:
                    chunk = os.read(qemu.stdout.fileno(), 4096)
                    if not chunk:
                        break
                    log.write(chunk); log.flush()
                    tail = (tail + chunk)[-8192:]
                    if not booted and tail.endswith(b'# '):
                        commands = [
                            'mount -t proc proc /proc', 'mount -t sysfs sysfs /sys',
                            'mount -t tmpfs tmpfs /tmp',
                            'mount -t 9p -o trans=virtio,version=9p2000.L repo /workspaces/repository',
                            'mount -t debugfs debugfs /sys/kernel/debug',
                            'insmod ' + str(module),
                            'cd ' + str(ROOT),
                            'PATH=/usr/lib/llvm-18/bin:$PATH PYTHONDONTWRITEBYTECODE=1 python3 ' + str(Path(__file__)) + ' guest ' + str(live)]
                        qemu.stdin.write((' && '.join(commands) + '; rc=$?; echo $rc > ' + str(live / 'guest.exit') + '; echo o > /proc/sysrq-trigger' + chr(10)).encode())
                        qemu.stdin.flush(); booted = True
            summary['qemu_returncode'] = qemu.wait()
            summary['booted'] = booted
            summary['guest_exit'] = int((live / 'guest.exit').read_text()) if (live / 'guest.exit').exists() else None
            if (live / 'guest.json').exists():
                summary['guest'] = json.loads((live / 'guest.json').read_text())
            summary['hashes_unchanged'] = all(hashlib.sha256(p.read_bytes()).hexdigest() == summary['hashes_before'][str(p.relative_to(ROOT))] for p in inputs)
            summary['ok'] = summary['qemu_returncode'] == 0 and summary['guest_exit'] == 0 and summary.get('guest', {}).get('ok', False) and summary['hashes_unchanged']
        finally:
            if qemu.poll() is None:
                qemu.terminate(); qemu.wait()
            summary['finished'] = datetime.now(timezone.utc).isoformat()
            with tarfile.open(archive, 'x:gz') as output:
                output.add(live, arcname='run')
            summary['archive_sha256'] = hashlib.sha256(archive.read_bytes()).hexdigest()
            (out / 'summary.json').write_text(json.dumps(summary, indent=2) + chr(10))
        if not summary['ok']:
            raise RuntimeError('ARM trusted service replay failed; see ' + str(out / 'summary.json'))


if __name__ == '__main__':
    if sys.argv[1:] == ['host']:
        host()
    elif len(sys.argv) == 3 and sys.argv[1] == 'guest':
        guest(sys.argv[2])
    else:
        raise SystemExit('usage: trusted_service_arm64.py host | guest LIVE')
