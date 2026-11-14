#!/usr/bin/env python3
"""Opt-in read-only corpus observation; use eqcodex-bin in PATH and EQCODEX_OUT.

Without EQCODEX_OUT the vng wrapper forwards its arguments unchanged. With it,
the standard make corpus guest command still owns all application execution.
Only the observer's own PID is stopped after that command finishes.
"""
import datetime
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys
import time


def save(command, path):
    started = {'wall_time': datetime.datetime.now(datetime.timezone.utc).isoformat(),
               'monotonic_ns': time.clock_gettime_ns(time.CLOCK_MONOTONIC)}
    try:
        result = subprocess.run(command, capture_output=True, timeout=45)
    finally:
        finished = {'wall_time': datetime.datetime.now(datetime.timezone.utc).isoformat(),
                    'monotonic_ns': time.clock_gettime_ns(time.CLOCK_MONOTONIC)}
        path.with_suffix(path.suffix + '.timing.json').write_text(
            json.dumps({'start': started, 'end': finished}, indent=2) + '\n')
    path.write_bytes(result.stdout)
    path.with_suffix(path.suffix + '.stderr').write_bytes(result.stderr)
    path.with_suffix(path.suffix + '.rc').write_text(str(result.returncode) + '\n')
    return result


def profile_loader(perf, prefix, dest):
    agent = save(prefix + ['pgrep', '-x', 'tetragon'], dest / 'loader-perf-pid.txt')
    if agent.returncode:
        raise RuntimeError(f'Tetragon PID query failed ({agent.returncode}); see {dest}/loader-perf-pid.txt.stderr')
    pid = str(int(agent.stdout.decode().strip()))
    save(['cat', f'/proc/{pid}/maps'], dest / 'loader-perf-maps.txt')
    symbols = dest / 'loader-perf-symbols'
    library = Path('usr/local/lib/bpfrejit/libnative_loader.so')
    (symbols / library).parent.mkdir(parents=True)
    shutil.copy2(Path(f'/proc/{pid}/root') / library, symbols / library)
    save(['cat', '/proc/kallsyms'], dest / 'loader-perf-kallsyms.txt')
    # perf data mmap needs a local filesystem, rather than the shared 9p mount.
    data = Path('/dev/shm') / f'eqcodex-loader-{pid}.data'
    recording = save([perf, 'record', '--namespaces', '--no-inherit', '-e', 'cpu-clock', '-F', '99',
                      '--call-graph', 'dwarf,8192', '-p', pid, '-o', str(data),
                      '--', 'sleep', '10'], dest / 'loader-perf-record.txt')
    if recording.returncode:
        raise RuntimeError(f'loader perf record failed ({recording.returncode}); see {dest}/loader-perf-record.txt.stderr')
    shutil.copy2(data, dest / 'loader-perf.data')
    arguments = ['-i', str(data), '--symfs', str(symbols),
                 '--kallsyms', str(dest / 'loader-perf-kallsyms.txt')]
    report = save([perf, 'report', *arguments, '--stdio', '--no-children', '--percent-limit', '0'],
                  dest / 'loader-perf-report.txt')
    if report.returncode:
        raise RuntimeError(f'loader perf report failed ({report.returncode}); see {dest}/loader-perf-report.txt.stderr')
    script = save([perf, 'script', *arguments], dest / 'loader-perf-script.txt')
    if script.returncode:
        raise RuntimeError(f'loader perf script failed ({script.returncode}); see {dest}/loader-perf-script.txt.stderr')


def capture_cilium_configuration(prefix, dest):
    agent = save(prefix + ['pgrep', '-x', 'cilium-agent'], dest / 'cilium-pid.txt')
    agent.check_returncode()
    pid = str(int(agent.stdout.decode().strip()))
    command = save(prefix + ['cat', f'/proc/{pid}/cmdline'], dest / 'cilium-command.bin')
    command.check_returncode()
    argv = command.stdout.decode().rstrip('\0').split('\0')
    state = None
    socket_path = None
    for index, argument in enumerate(argv):
        if argument.startswith('--state-dir='):
            state = argument.split('=', 1)[1]
        elif argument == '--state-dir':
            state = argv[index + 1]
        if argument.startswith('--socket-path='):
            socket_path = argument.split('=', 1)[1]
        elif argument == '--socket-path':
            socket_path = argv[index + 1]
    if not state:
        raise RuntimeError('running Cilium command has no state directory')
    source = Path(__file__).with_name('cilium-config.py').read_text()
    archive = save(prefix + ['python3', '-c', source, state, '/var/lib/cilium/bpf/include/bpf'], dest / 'cilium-config.tar.gz')
    archive.check_returncode()
    if not socket_path:
        raise RuntimeError('running Cilium command has no API socket path')
    save(prefix + ['curl', '-sS', '--max-time', '3', '--unix-socket', socket_path,
                   'http://localhost/v1/endpoint'], dest / 'cilium-endpoints.json')


def observe(out):
    out = Path(out)
    log = out / 'guest.log'
    seen = set()
    sequence = 0
    trace_ready = False
    while True:
        text = log.read_text(errors='replace') if log.exists() else ''
        phases = re.findall(r'"event": "measurement_start", "phase": "([^"]+)"', text)
        if not phases:
            time.sleep(2)
            continue
        phase = phases[-1]
        sequence += 1
        dest = out / f'{phase}-{sequence:04d}'
        dest.mkdir()
        (dest / 'time.txt').write_text(datetime.datetime.now(datetime.timezone.utc).isoformat() + '\n')
        ids = subprocess.run(['docker', 'ps', '-q'], capture_output=True, check=True).stdout.decode().split()
        if len(ids) != 1:
            (dest / 'container-error.txt').write_text(repr(ids))
            time.sleep(2)
            continue
        cid = ids[0]
        prefix = ['docker', 'exec', cid]
        if phase not in seen or '--cilium-config' in sys.argv:
            save(prefix + ['sha256sum', '/usr/local/lib/bpfrejit/libnative_loader.so'],
                 dest / 'native-loader-sha256.txt')
        if '--cilium-config' in sys.argv:
            capture_cilium_configuration(prefix, dest)
        programs = save(prefix + ['bpftool', '-j', 'prog', 'show'], dest / 'programs.json')
        maps = save(prefix + ['bpftool', '-j', 'map', 'show'], dest / 'maps.json')
        if programs.returncode or maps.returncode:
            time.sleep(2)
            continue
        map_records = json.loads(maps.stdout)
        for item in map_records:
            name = item.get('name', '')
            if name in ('metrics', 'tg_stats_map') or ('--cilium-config' in sys.argv and name == 'cilium_metrics') or (phase not in seen and (
                    item['type'] == 'prog_array' or name in ('config_map', '.rodata.var', 'policy_conf'))):
                save(prefix + ['bpftool', '-j', 'map', 'dump', 'id', str(item['id'])],
                     dest / f'map-{item["id"]}-{name}.json')
        for port in (8888, 2112):
            save(prefix + ['curl', '-sS', '--max-time', '3', f'http://localhost:{port}/metrics'],
                 dest / f'collector-{port}.txt')
        if '--loader-perf' in sys.argv and phase == 'post_rejit' and phase not in seen:
            profile_loader(sys.argv[sys.argv.index('--loader-perf') + 1], prefix, dest)
        if '--tetra' in sys.argv or '--tetra-policy' in sys.argv:
            option = '--tetra' if '--tetra' in sys.argv else '--tetra-policy'
            client = sys.argv[sys.argv.index(option) + 1]
            agent = save(prefix + ['pgrep', '-x', 'tetragon'], dest / 'tetragon-pid.txt')
            if agent.returncode == 0:
                pid = agent.stdout.decode().strip()
                command = save(prefix + ['cat', f'/proc/{pid}/cmdline'], dest / 'tetragon-command.bin')
                if command.returncode == 0:
                    argv = command.stdout.decode().split('\0')
                    address = argv[argv.index('--server-address') + 1]
                    cli = [client, '--server-address', address, '--timeout', '2s']
                    save(prefix + cli + ['tracingpolicy', 'list', '-o', 'json'], dest / 'tracingpolicies.json')
                    if '--tetra' in sys.argv and sequence % 3 == 0:
                        save(prefix + ['timeout', '--signal=INT', '--kill-after=2', '1s', *cli,
                                       'getevents', '-o', 'json'], dest / 'events.jsonl')
        if phase not in seen:
            save(['docker', 'logs', cid], dest / 'container.log')
            save(prefix + ['sh', '-c', 'cat /opt/bpf-benchmark/native-bpf/x86_64/*/manifest.json'],
                 dest / 'manifests.txt')
            save(prefix + ['sh', '-c', 'sha256sum /opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/*.o /opt/bpf-benchmark/native-bpf/x86_64/tetragon/*.o'],
                 dest / 'native-object-sha256.txt')
            records = json.loads(programs.stdout)
            # Full disassembly identifies same-name entry/tail programs. It is
            # taken only once per phase, outside the framework's timed counters.
            selected = [item for item in records if item.get('name', '').startswith(
                ('native_tracer', 'perf_unwind_', 'kprobe_unwind_', 'unwind_',
                 'generic_kprobe', 'generic_tracepo'))]
            for item in selected[:18]:
                ident = str(item['id'])
                save(prefix + ['bpftool', 'prog', 'dump', 'xlated', 'id', ident, 'opcodes'], dest / f'prog-{ident}-xlated.txt')
                save(['/workspaces/repository/kprog/results/equal-work-20261113/eqcodex-jit',
                      ident, str(dest / f'prog-{ident}-jited.bin')],
                     dest / f'prog-{ident}-jit-dump.txt')
            # Short diagnostic trace samples in this job's guest.
            # This never attaches to the host or another lane's VM.
            trace_result = save(['sh', '-eu', '-c', '''
mountpoint -q /sys/kernel/tracing || mount -t tracefs tracefs /sys/kernel/tracing
cd /sys/kernel/tracing
printf '%s\n' 'p:eqcodex/ring_commit bpf_ringbuf_commit op=+0($arg1):u8' >> kprobe_events
printf '%s\n' 'r256:eqcodex/kernel_read copy_from_kernel_nofault ret=$retval:s64' >> kprobe_events
install -d instances/eqcodex
echo 8192 > instances/eqcodex/buffer_size_kb
'''], dest / 'trace-setup.txt') if not trace_ready and '--trace' in sys.argv else None
            if trace_result is not None:
                trace_ready = trace_result.returncode == 0
            seen.add(phase)
        if trace_ready:
            save(['sh', '-eu', '-c', '''
cd /sys/kernel/tracing/instances/eqcodex
echo > trace
echo 1 > events/eqcodex/enable
sleep 0.02
echo 0 > events/eqcodex/enable
cat trace
cat /sys/kernel/tracing/kprobe_profile
'''], dest / 'helper-sample.txt')
        (dest / 'end-time.txt').write_text(datetime.datetime.now(datetime.timezone.utc).isoformat() + '\n')
        time.sleep(8)


def main():
    if len(sys.argv) > 1 and sys.argv[1] == '--guest':
        out = Path(sys.argv[2])
        plan = json.loads((out / 'guest-plan.json').read_text())
        with (out / 'observer.log').open('wb') as observer_log, (out / 'guest.log').open('wb') as guest_log:
            observer = subprocess.Popen(plan['observer'], stdout=observer_log, stderr=subprocess.STDOUT)
            try:
                result = subprocess.run(['/bin/bash', '-c', plan['command']], stdout=guest_log, stderr=subprocess.STDOUT)
            finally:
                if observer.poll() is None:
                    observer.terminate()
                observer_status = observer.wait()
                (out / 'observer-exit-code').write_text(str(observer_status) + '\n')
        sys.stdout.buffer.write((out / 'guest.log').read_bytes())
        return result.returncode
    if len(sys.argv) > 1 and sys.argv[1] == '--observe':
        observe(sys.argv[2])
        return 0
    arguments = sys.argv[1:]
    output = os.environ.get('EQCODEX_OUT')
    if output:
        out = Path(output).resolve()
        out.mkdir(parents=True, exist_ok=True)
        index = arguments.index('--exec') + 1
        original = arguments[index]
        selected_linker = os.environ.get('EQCODEX_NATIVE_LINK_BINARY')
        if selected_linker:
            original = shlex.join(['env', f'BPFREJIT_NATIVE_LINK_BINARY={selected_linker}']) + ' ' + original
        observer = ['python3', str(Path(__file__).resolve()), '--observe', str(out)]
        if os.environ.get('EQCODEX_TRACE') == '1':
            observer.append('--trace')
        if client := os.environ.get('EQCODEX_TETRA'):
            observer += ['--tetra', client]
        if client := os.environ.get('EQCODEX_TETRA_POLICIES'):
            observer += ['--tetra-policy', client]
        if perf := os.environ.get('EQCODEX_LOADER_PERF'):
            observer += ['--loader-perf', perf]
        if os.environ.get('EQCODEX_CILIUM_CONFIG') == '1':
            observer.append('--cilium-config')
        (out / 'guest-plan.json').write_text(json.dumps({'command': original, 'observer': observer}, indent=2) + '\n')
        arguments[index] = shlex.join(['python3', str(Path(__file__).resolve()), '--guest', str(out)])
        (out / 'vng-command.json').write_text(json.dumps(arguments, indent=2) + '\n')
    os.execv('/opt/virtme-ng/bin/vng', ['vng', *arguments])


if __name__ == '__main__':
    sys.exit(main())
