"""Finite normal B compilation and detached stock loads of the two new text groups."""
import fcntl
import json
from pathlib import Path
import subprocess
import sys
import tarfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OUT = HERE / 'return-pipeline'
LOCKS = Path('/workspaces/.agent-state/kprog-lanes/locks')
ARCHIVES = Path('/workspaces/kprog-raw/verified/omp-five-20261120/tetragon/state/session-6f0mwwi2/requests')

def now():
    return datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')

def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')

def run(command, log):
    with log.open('a') as stream:
        result = subprocess.run(list(map(str, command)), cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
    return result.returncode

def publish(paths, message):
    with (LOCKS / 'git').open('a') as lock, (OUT / 'publication.log').open('a') as log:
        fcntl.flock(lock, fcntl.LOCK_EX)
        relative = [str(p.relative_to(ROOT)) for p in paths]
        for args in [('status', '--short', '--branch', '--untracked-files=no'),
                     ('add', '--', *relative), ('commit', '--only', '-m', message, '--', *relative), ('push',)]:
            subprocess.run(['git', *args], cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)

def compile_case(ident, cpu):
    destination = OUT / str(ident)
    destination.mkdir()
    command = ['taskset', '-c', str(cpu), 'prlimit', '--as=17179869184', '--',
        'make', '-C', HERE, 'compile-group', 'REQUEST=' + str(ident), 'RECORDS=' + str(destination)]
    row = dict(request=ident, started_utc=now(), command=list(map(str, command)))
    row['compile_returncode'] = run(command, destination / 'compile.log')
    row['ended_utc'] = now()
    case = HERE / ('request-' + str(ident))
    members = [p.name for p in case.glob('trusted_x86.bpf.*') if p.suffix in {'.i', '.bc', '.mir', '.json', '.o'}]
    row['archive_members'] = sorted(members)
    if members:
        subprocess.run(['tar', '-I', 'zstd -T1 -3', '-cf', str(destination / 'compiler-evidence.tar.zst'),
            '-C', str(case), *sorted(members)], check=True)
    return row

OUT.mkdir()  # Preserve an earlier run if this finite recipe is invoked twice.
status = 1
record = dict(started_utc=now(), source=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              kernel_source=subprocess.check_output(['git', '-C', 'vendor/linux-framework', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              scope='B compilation and sole-kernel detached stock verification only; no native execution or timing.', cases=[])
try:
    with (LOCKS / 'timing').open('a') as timing:
        fcntl.flock(timing, fcntl.LOCK_SH)
        with ThreadPoolExecutor(max_workers=2) as pool:
            for future in as_completed([pool.submit(compile_case, 12, 16), pool.submit(compile_case, 38, 17)]):
                row = future.result()
                record['cases'].append(row)
                write(OUT / 'controller.json', record)
                publish([OUT / str(row['request']), OUT / 'controller.json'],
                    'Record Tetragon return-group ' + str(row['request']) + ' B compilation')

        successful = [row['request'] for row in record['cases'] if row['compile_returncode'] == 0]
        if successful:
            stock = OUT / 'stock'
            stock.mkdir()
            for ident in successful:
                case = HERE / ('request-' + str(ident))
                destination = stock / str(ident)
                destination.mkdir()
                with tarfile.open(ARCHIVES / (str(ident) + '.success.tar.gz')) as archive:
                    (destination / 'kernel.facts.json').write_bytes(archive.extractfile('request/kernel.facts.json').read())
                (destination / 'generation.metadata.json').symlink_to(case / 'generation.metadata.json')
                replay = OUT / 'replay' / str(ident)
                replay.mkdir(parents=True)
                (replay / 'replay.bpf.o').symlink_to(case / 'trusted_x86.bpf.o')
            write(OUT / 'stock-index.json', dict(source_archive=str(ARCHIVES), requests=[dict(request=i) for i in successful]))
            command = ['make', '-f', 'kprog/results/cilium-headlen-20261119/Makefile', 'archive-stock',
                'OUT=' + str(stock), 'INPUTS=' + str(OUT / 'stock-index.json'), 'REPLAY=' + str(OUT / 'replay')]
            record['stock_command'] = command
            record['stock_started_utc'] = now()
            with (LOCKS / 'image').open('a') as image:
                fcntl.flock(image, fcntl.LOCK_SH)
                record['stock_returncode'] = run(command, stock / 'guest.log')
            record['stock_ended_utc'] = now()
        status = 0 if len(successful) == 2 and record.get('stock_returncode') == 0 else 1
finally:
    record.update(ended_utc=now(), controller_status=status)
    if sys.exc_info()[1] is not None:
        record['exception'] = repr(sys.exc_info()[1])
    try:
        if OUT.exists():
            write(OUT / 'controller.json', record)
            publish([OUT], 'Record Tetragon return-group stock verification')
    finally:
        lane = Path('/workspaces/.agent-state/kprog-lanes/perf')
        with (lane / 'resume-msg.md').open('a') as message:
            message.write(f'\nTetragon return-group pipeline ended status {status}. Read {OUT}/controller.json, '
                'per-case compile logs/status/commands and stock/result.json/verifier logs. Record actual outcomes, '
                'inspect own preprocessing cleanup and continue phase1 within design; full timing stays frozen.\n')
        stop = lane / 'STOP'
        if stop.exists() and stop.read_text().startswith('PERF return-group pipeline:'):
            stop.unlink()
sys.exit(status)
