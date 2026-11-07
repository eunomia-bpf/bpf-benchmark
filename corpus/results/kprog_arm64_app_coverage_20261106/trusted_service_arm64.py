"""AArch64 full-system replay of the common native-only trusted service."""
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import queue
import signal
import shlex
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


CORPUS_APPS = {
    "bcc": "bcc/set", "otelcol-ebpf-profiler": "otelcol-ebpf-profiler/profiling",
    "cilium": "cilium/agent", "tetragon": "tetragon/observer",
    "katran": "katran", "tracee": "tracee/monitor",
}


def corpus_application(live, case):
    """Run the retained two-start recipe with the requested corpus app selector."""
    import shutil
    artifact_root = "/artifacts" if case in {"tracee", "tetragon"} else "/artifacts/user/repo-artifacts/arm64"
    os.environ.update(BPFREJIT_REPO_ARTIFACT_ROOT=artifact_root, BPFREJIT_REMOTE_PYTHON_BIN="python3",
        BPFREJIT_KERNEL_MODULES_ROOT=str(ROOT / "vendor/build/arm64/linux/modules-install"),
        BPFREJIT_NATIVE_LOADER_SO=str(LOADER / "libnative_loader.so"),
        BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF="1",
        BPFREJIT_SHIM_NATIVE_MANIFEST=str(live / "native-only-manifest.json"),
        BPFREJIT_KEEP_ALL_WORKDIRS="1", BPFREJIT_CORPUS_REJIT_TIMEOUT="0")
    os.environ.pop("BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF", None)
    launcher = Path("/qemu-run.sh").read_text()
    entry = "exec python3 -m corpus.driver"
    if launcher.count(entry) != 1:
        raise RuntimeError("retained corpus launcher has no unique driver entry")
    # APP is an existing corpus knob; retain every other saved launcher setting.
    launcher = launcher.replace(entry, "export BPFREJIT_CORPUS_APPS=" +
        shlex.quote(CORPUS_APPS[case]) + "\n" + entry)
    launch_path = live / "corpus-launch.sh"
    launch_path.write_text(launcher)
    command = ["sh", str(launch_path)]
    work = dict(command=command)
    try:
        with (live / "corpus.log").open("w") as output:
            done = subprocess.run(command, stdout=output, stderr=subprocess.STDOUT)
        work["returncode"] = done.returncode
        done.check_returncode()
    finally:
        boot = Path("/proc/sys/kernel/random/boot_id").read_text().strip()
        work["corpus_metadata"] = []
        for path in sorted((ROOT / "corpus/results").glob("arm64_qemu_corpus_*/metadata.json")):
            metadata = json.loads(path.read_text())
            if metadata.get("launcher_boot_id") == boot:
                work["corpus_metadata"].append(dict(path=str(path), status=metadata["status"],
                    error_message=metadata.get("error_message")))
                shutil.copytree(path.parent, live / "corpus-results" / path.parent.name)
        requests = live / "requests/requests.jsonl"
        work["completed_requests"] = [json.loads(line) for line in requests.read_text().splitlines()] if requests.exists() else []
        (live / "work.json").write_text(json.dumps(work, indent=2) + chr(10))
    if not work["corpus_metadata"]:
        raise RuntimeError(case + " corpus produced no application metadata")
    errors = [row for row in work["corpus_metadata"] if row["status"] == "error"]
    if errors:
        raise RuntimeError(case + " corpus recorded application errors: " + json.dumps(errors))
    return dict(app=CORPUS_APPS[case], **work)


def guest(live, case="control"):
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
    summary = dict(ok=False, arch='arm64', case=case, started=datetime.now(timezone.utc).isoformat())
    def event():
        line = events.get()
        if line is None:
            raise RuntimeError('common service exited before receipt')
        return json.loads(line)
    try:
        ready = event()
        if not ready.get('ready') or ready['arch'] != 2:
            raise RuntimeError('ARM common service did not register')
        if case in CORPUS_APPS:
            summary.update(corpus_application(live, case), ok=True)
        else:
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
        with (live / 'kernel.log').open('w') as output:
            subprocess.run(['dmesg'], stdout=output, stderr=subprocess.STDOUT, check=True)
        (live / 'meminfo.txt').write_text(Path('/proc/meminfo').read_text())
        summary['finished'] = datetime.now(timezone.utc).isoformat()
        (live / 'guest.json').write_text(json.dumps(summary, indent=2) + chr(10))


def host(case="control", results=None):
    """Mount the retained runtime read-only; use the new canonical Image/module."""
    build = ROOT / 'kprog/arm64/build/trusted-transport'
    build.mkdir(exist_ok=True)
    out = (Path(results).resolve() if results else HERE) / ('trusted-arm64-' + case + '-result' if case in CORPUS_APPS else 'trusted-arm64-service-result')
    out.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    archive = out / ('run-' + stamp + '.tar.gz')
    summary = dict(ok=False, case=case, started=datetime.now(timezone.utc).isoformat(), archive=archive.name)
    with tempfile.TemporaryDirectory(prefix='service-', dir=build) as temporary:
        live = Path(temporary)
        image = ROOT / 'vendor/build/arm64/linux/arch/arm64/boot/Image'
        module = ROOT / 'kinsn/module/arm64/build/bpf_arm64_native_lab.ko'
        root = ROOT / 'kprog/arm64/build/app-runtime-v35/root'
        argv = ['taskset', '-c', '8-11', 'qemu-system-aarch64', '-M', 'virt',
            '-cpu', 'max', '-smp', '8' if case in CORPUS_APPS else '2', '-m', '8192' if case in CORPUS_APPS else '2048', '-nographic', '-no-reboot',
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
            ROOT / 'kprog/arm64/micro-prog/arm64_abi.py', ROOT / 'kprog/arm64/arm64_sim_direct.h',
            ROOT / 'kinsn/module/include/native_lab_trusted_wire.h', Path(__file__)]
        if case in CORPUS_APPS:
            manifest = ROOT / 'kprog/arm64/build/app-verified-stage' / case / 'manifest.json'
            data = json.loads(manifest.read_text())
            inputs.append(manifest)
            for row in data['objects'] + data.get('data_objects', []):
                for key in ['simulator_object', 'simulator_program']:
                    row.pop(key, None)
                native = (manifest.parent / row['native_object']).resolve()
                row['native_object'] = str(native)
                inputs.append(native)
            (live / 'native-only-manifest.json').write_text(json.dumps(data, indent=2) + chr(10))
            inputs.extend([root / 'qemu-run.sh', root / 'qemu-init',
                ROOT / 'bpfopt/shim/build-arm64/libbpfrejit_shim.so', LOADER / 'libnative_loader.so',
                ROOT / 'corpus/driver.py', ROOT / 'runner/libs/app_runners' / ({'bcc':'bcc_set', 'otelcol-ebpf-profiler':'otel_profiler'}.get(case, case) + '.py')])
            if case == 'bcc':
                inputs.append(ROOT / 'runner/libs/app_runners/bcc.py')
                inputs.extend(root / 'usr/local/bin' / name for name in
                    ['capable', 'biosnoop', 'vfsstat', 'opensnoop', 'syscount', 'tcpconnect', 'tcplife', 'runqlat'])
            if case == 'katran':
                inputs.append(root / 'artifacts/user/repo-artifacts/arm64/katran/bin/katran_server_grpc')
            elif case in {'tracee', 'tetragon'}:
                inputs.extend(p for p in (root / 'artifacts' / case).rglob('*') if p.is_file())
            elif case in {'cilium', 'otelcol-ebpf-profiler'}:
                inputs.append(root / 'usr/local/bin' / ('cilium-agent' if case == 'cilium' else case))
            inputs.extend([ROOT / 'runner/libs/app_runners/native_loader_env.py',
                ROOT / 'corpus/config/macro_apps.yaml', ROOT / 'corpus/config/benchmark_config.yaml'])
            inputs.extend(sorted((ROOT / 'kinsn/module/arm64/build').glob('*.ko')))
            inputs.extend([ROOT / 'vendor/build/arm64/linux/Module.symvers',
                ROOT / 'vendor/build/arm64/linux/modules-install/lib/modules' / (ROOT / 'vendor/build/arm64/linux/include/config/kernel.release').read_text().strip() / 'modules.dep'])
            inputs = list(dict.fromkeys(inputs))
        inputs.extend(sorted((ROOT / 'kprog/formal/generated').glob('*.h')))
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
                            'mount -t tmpfs tmpfs /tmp', 'mount -t tmpfs tmpfs /run',
                            'mount -t 9p -o trans=virtio,version=9p2000.L repo /workspaces/repository',
                            'mount -t debugfs debugfs /sys/kernel/debug',
                            'insmod ' + str(module),
                            'cd ' + str(ROOT),
                        ]
                        if case in CORPUS_APPS:
                            commands.append('mount --bind ' + str(ROOT / 'bpfopt/shim/build-arm64/libbpfrejit_shim.so') + ' /usr/local/lib/bpfrejit/libbpfrejit_shim.so')
                        if case in CORPUS_APPS:
                            commands.extend(['mount --bind ' + str(ROOT / 'kinsn/module/arm64/build') + ' /artifacts/kinsn',
                                'mount --bind ' + str(ROOT / 'vendor/build/arm64/linux/modules-install/lib/modules') + ' /artifacts/lib/modules',
                                'mount -t bpf bpffs /sys/fs/bpf',
                                'mount -t tmpfs -o mode=1777 tmpfs /var/tmp',
                                'install -d -m1777 /dev/shm', 'mount -t tmpfs -o mode=1777 tmpfs /dev/shm', 'ulimit -l unlimited'])
                        commands.extend([
                            'PATH=' + str(ROOT / 'runner/build-arm64-llvmbpf') + ':/usr/lib/llvm-18/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin PYTHONDONTWRITEBYTECODE=1 python3 ' + str(Path(__file__)) + ' guest ' + str(live) + ' ' + case])
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
    if len(sys.argv) in (2, 3, 4) and sys.argv[1] == 'host':
        case = sys.argv[2] if len(sys.argv) >= 3 else 'control'
        if case not in {'control', *CORPUS_APPS}:
            raise SystemExit('unknown case')
        host(case, sys.argv[3] if len(sys.argv) == 4 else None)
    elif len(sys.argv) in (3, 4) and sys.argv[1] == 'guest':
        guest(sys.argv[2], sys.argv[3] if len(sys.argv) == 4 else 'control')
    else:
        raise SystemExit('usage: trusted_service_arm64.py host [control|APP] [RESULTS] | guest LIVE [control|APP]')
