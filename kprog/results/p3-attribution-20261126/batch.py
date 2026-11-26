"""Finite diagnostic/profile collection; publish each result and resume analysis."""
from datetime import datetime, timezone
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys
import traceback

ROOT = Path('/workspaces/repository')
HERE = ROOT / 'kprog/results/p3-attribution-20261126'
OUT = Path(sys.argv[1]).resolve()
PHASE = sys.argv[2] if len(sys.argv) > 2 else 'all'
LANE = Path('/workspaces/.agent-state/kprog-lanes/perf')
OUT.mkdir(parents=True, exist_ok=True)
os.chdir(ROOT)

def journal(event, **fields):
    with (OUT / 'journal.jsonl').open('a') as log:
        log.write(json.dumps(dict(time=datetime.now(timezone.utc).isoformat(), event=event, **fields)) + '\n')

def run(command, log):
    with log.open('w') as stream:
        job = subprocess.Popen(command, stdout=stream, stderr=subprocess.STDOUT)
        while True:
            try:
                return job.wait(timeout=30)
            except subprocess.TimeoutExpired:
                journal('heartbeat', pid=job.pid, log=str(log))

def raw_paths(run_dir):
    run_dir = Path(run_dir)
    files = [run_dir / 'metadata.json', run_dir / 'details/result.json', run_dir / 'details/progress.json',
             *(run_dir / 'details/apps').glob('*.json'), *(run_dir / 'details/shim-logs').glob('*.log')]
    return [p for p in files if p.exists()]

def publish(paths, message, log):
    paths = [str(p.relative_to(ROOT)) for p in paths]
    with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('w') as lock, log.open('w') as stream:
        fcntl.flock(lock, fcntl.LOCK_EX)
        commands = [['git', 'status', '--short', '--branch', '--untracked-files=no'],
                    ['git', 'add', '-f', '--', *paths],
                    ['git', 'diff', '--cached', '--stat', '--', *paths],
                    ['git', 'commit', '--only', '-m', message, '--', *paths],
                    ['git', 'push', 'origin', 'master']]
        for command in commands:
            subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT, check=True)

def archive_profile(case):
    # Raw profiles stay in place. Their compressed publication uses GitHub-sized parts.
    names = sorted(p.name for p in case.iterdir())
    with (case / 'archive.log').open('w') as log:
        tar = subprocess.Popen(['tar', '-C', str(case), '-cf', '-', '--', *names], stdout=subprocess.PIPE, stderr=log)
        compressed = subprocess.Popen(['zstd', '-T1', '-3', '-c'], stdin=tar.stdout, stdout=subprocess.PIPE, stderr=log)
        tar.stdout.close()
        split = subprocess.run(['split', '-b', '44M', '-', str(case / 'evidence.tar.zst.part-')],
                               stdin=compressed.stdout, stderr=log)
        compressed.stdout.close()
        statuses = [split.returncode, compressed.wait(), tar.wait()]
    if any(statuses):
        raise RuntimeError('profile archive failed: ' + str(statuses))
    (case / 'archive.txt').write_text('All original profile files stay beside these parts.\n'
                                    'Extract: cat evidence.tar.zst.part-* | zstd -d | tar -xf -\n')
    return [*case.glob('evidence.tar.zst.part-*'), case / 'archive.txt', case / 'archive.log']

def collect(kind, label, app):
    case = OUT / label
    case.mkdir()
    command = ['make', '-C', str(HERE), kind, 'APP=' + app, 'OUT=' + str(case)]
    if kind == 'profile':
        if app == 'otelcol-ebpf-profiler/profiling':
            command.append('PROG_NAME=perf_unwind_nat')
        command = ['prlimit', '--as=42949672960', '--', *command]
    (case / 'command.json').write_text(json.dumps(command, indent=2) + '\n')
    journal('start', kind=kind, app=app, case=str(case), command=command)
    status = run(command, case / 'make.log')
    (case / 'status.json').write_text(json.dumps(dict(returncode=status, app=app, kind=kind), indent=2) + '\n')
    raw = []
    if kind == 'diagnostic':
        result = subprocess.run(['make', '-C', 'kprog/results/hash-family-c-20261126', 'collect',
                                 'OUT=' + str(case)], capture_output=True, text=True)
        (case / 'collect.log').write_text(result.stdout + result.stderr)
        result.check_returncode()
        raw = [Path(line) for line in (case / 'raw-paths.txt').read_text().splitlines()]
        raw = [p if p.is_absolute() else ROOT / p for p in raw]
        files = [p for p in case.rglob('*') if p.is_file()]
    else:
        run_dir = (case / 'run_dir').read_text().strip() if (case / 'run_dir').exists() else ''
        if run_dir:
            raw = raw_paths(run_dir)
        files = [case / 'command.json', case / 'status.json', case / 'make.log', *archive_profile(case)]
    publish([*files, *raw], 'Record P3 attribution ' + label, case / 'publication.log')
    journal('end', kind=kind, app=app, case=str(case), returncode=status)
    return status

status = 0
def checks():
    for app, short in [('tetragon/observer', 'tetragon'), ('otelcol-ebpf-profiler/profiling', 'otel')]:
        for repetition in range(1, 4):
            if collect('diagnostic', f'{short}-{repetition}', app) != 0:
                return 1  # A failed launcher stops its dependent checks; raw errors remain.
    return 0

try:
    if PHASE not in {'all', 'diagnostic', 'otel-profile'}:
        raise ValueError('unknown collection phase: ' + PHASE)
    if PHASE == 'otel-profile':
        status |= int(collect('profile', 'otel-profile', 'otelcol-ebpf-profiler/profiling') != 0)
    else:
        status |= checks()
    if PHASE == 'all':
        for app, short in [('tetragon/observer', 'tetragon'), ('tracee/monitor', 'tracee')]:
            status |= int(collect('profile', short + '-profile', app) != 0)
except Exception:
    status = 1
    (OUT / 'exception.txt').write_text(traceback.format_exc())
    traceback.print_exc()
finally:
    (OUT / 'controller-exit.txt').write_text(str(status) + '\n')
    journal('finished', returncode=status)
    with (LANE / 'resume-msg.md').open('a') as message:
        message.write(f'\nP3 attribution collection ended (controller status {status}). Read {OUT}/journal.jsonl '
                      'and per-case guest-summary/profile records. Determine reproducibility and per-program mix, '
                      'resolve phase PMU samples in kprog_htab_elem_k*, kernel hash lookup, memset and other work; '
                      'fix the evidenced cause within the design and record Tetragon/Tracee memset weight. '
                      'Collection completion is not task completion. Full timing stays frozen.\n')
    stop = LANE / 'STOP'
    if stop.exists() and stop.read_text().startswith('PERF P3 attribution:'):
        stop.unlink()
raise SystemExit(status)
