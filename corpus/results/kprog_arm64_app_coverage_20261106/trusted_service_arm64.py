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


def katran(live):
    """Run the unchanged corpus Katran topology, application and packet recipe."""
    from dataclasses import asdict
    import shutil
    sys.path.insert(0, str(ROOT))
    os.environ.update(RUN_TARGET_ARCH="arm64", BPFREJIT_REMOTE_PYTHON_BIN="python3",
        BPFREJIT_REPO_ARTIFACT_ROOT="/artifacts/user/repo-artifacts/arm64",
        BPFREJIT_KERNEL_MODULES_ROOT=str(ROOT / "vendor/build/arm64/linux/modules-install"),
        BPFREJIT_SHIM_NATIVE_LOADER="1", BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF="1",
        BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF="1",
        BPFREJIT_NATIVE_LOADER_SO=str(LOADER / "libnative_loader.so"),
        BPFREJIT_SHIM_NATIVE_MANIFEST=str(ROOT / "kprog/arm64/build/app-verified-stage/katran/manifest.json"),
        BPFREJIT_SHIM_LOG=str(live / "shim.log"),
        BPFREJIT_SHIM_DIR=str(live / "shim-dumps"))
    bpftool = shutil.which("bpftool")
    if not bpftool:
        raise RuntimeError("retained runtime has no bpftool")
    os.environ["BPFTOOL"] = bpftool
    Path("/proc/sys/kernel/bpf_stats_enabled").write_text("1\n")
    from runner.libs.app_runners.katran import KatranRunner
    from runner.libs.app_outcomes import katran_outcome_snapshot
    runner = KatranRunner(workload_spec={"kind": "xdp_pktgen"})
    work = {}
    def programs():
        return json.loads(subprocess.check_output([bpftool, "-j", "prog", "show"], text=True))
    try:
        runner.start()
        work.update(application_artifacts=runner.artifacts, programs_before=programs(),
                    outcomes_before=katran_outcome_snapshot())
        (live / "work.json").write_text(json.dumps(work, indent=2) + chr(10))
        work["workload"] = asdict(runner.run_workload(2))
        work.update(programs_after=programs(), outcomes_after=katran_outcome_snapshot())
        requests = live / "requests/requests.jsonl"
        receipts = [json.loads(line) for line in requests.read_text().splitlines()] if requests.exists() else []
        if not receipts or any(r["status"] for r in receipts):
            raise RuntimeError("Katran has no complete successful trusted-service receipts")
        before = {r["id"]:r for r in work["programs_before"]}
        after = {r["id"]:r for r in work["programs_after"]}
        deltas = [{"prog_id":r["prog_id"], "run_cnt_delta":int(after.get(r["prog_id"],{}).get("run_cnt",0))-int(before.get(r["prog_id"],{}).get("run_cnt",0))} for r in receipts]
        work["native_run_counts"] = deltas
        if not any(r["run_cnt_delta"] > 0 for r in deltas):
            raise RuntimeError("no bound native application program executed during workload")
        return dict(app="katran/xdp_pktgen", completed_requests=receipts, native_run_counts=deltas)
    finally:
        try:
            runner.stop()
        finally:
            work["application_output"] = runner.process_output
            (live / "work.json").write_text(json.dumps(work, indent=2) + chr(10))


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
        if case == "katran":
            summary.update(katran(live), ok=True)
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
        summary['finished'] = datetime.now(timezone.utc).isoformat()
        (live / 'guest.json').write_text(json.dumps(summary, indent=2) + chr(10))


def host(case="control"):
    """Mount the retained runtime read-only; use the new canonical Image/module."""
    build = ROOT / 'kprog/arm64/build/trusted-transport'
    build.mkdir(exist_ok=True)
    out = HERE / ('trusted-arm64-katran-result' if case == 'katran' else 'trusted-arm64-service-result')
    out.mkdir(exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    archive = out / ('run-' + stamp + '.tar.gz')
    summary = dict(ok=False, case=case, started=datetime.now(timezone.utc).isoformat(), archive=archive.name)
    with tempfile.TemporaryDirectory(prefix='service-', dir=build) as temporary:
        live = Path(temporary)
        image = ROOT / 'vendor/build/arm64/linux/arch/arm64/boot/Image'
        module = ROOT / 'kinsn/module/arm64/build/bpf_arm64_native_lab.ko'
        root = ROOT / 'kprog/arm64/build/app-runtime-v35/root'
        argv = ['taskset', '-c', '20-23', 'qemu-system-aarch64', '-M', 'virt',
            '-cpu', 'max', '-smp', '8' if case == 'katran' else '2', '-m', '4096' if case == 'katran' else '2048', '-nographic', '-no-reboot',
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
        if case == 'katran':
            inputs.extend([ROOT / 'bpfopt/shim/build-arm64/libbpfrejit_shim.so', LOADER / 'libnative_loader.so',
                ROOT / 'kprog/arm64/build/app-verified-stage/katran/manifest.json',
                ROOT / 'kprog/arm64/build/app-verified-stage/katran/balancer.native.o',
                root / 'artifacts/user/repo-artifacts/arm64/katran/bin/katran_server_grpc',
                ROOT / 'runner/libs/app_runners/katran.py',
                ROOT / 'vendor/build/arm64/linux/Module.symvers',
                ROOT / 'vendor/build/arm64/linux/modules-install/lib/modules' / (ROOT / 'vendor/build/arm64/linux/include/config/kernel.release').read_text().strip() / 'modules.dep'])
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
                        if case == 'katran':
                            commands.append('mount --bind ' + str(ROOT / 'bpfopt/shim/build-arm64/libbpfrejit_shim.so') + ' /usr/local/lib/bpfrejit/libbpfrejit_shim.so')
                        commands.extend([
                            'PATH=/usr/lib/llvm-18/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin PYTHONDONTWRITEBYTECODE=1 python3 ' + str(Path(__file__)) + ' guest ' + str(live) + ' ' + case])
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
    if len(sys.argv) in (2, 3) and sys.argv[1] == 'host':
        case = sys.argv[2] if len(sys.argv) == 3 else 'control'
        if case not in {'control', 'katran'}:
            raise SystemExit('unknown case')
        host(case)
    elif len(sys.argv) in (3, 4) and sys.argv[1] == 'guest':
        guest(sys.argv[2], sys.argv[3] if len(sys.argv) == 4 else 'control')
    else:
        raise SystemExit('usage: trusted_service_arm64.py host [katran] | guest LIVE [katran]')
