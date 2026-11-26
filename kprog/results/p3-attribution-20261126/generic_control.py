"""Sequential module-symbol control of existing loader selection; always rebuild normal module."""
from datetime import datetime, timezone
import fcntl
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import traceback

ROOT = Path('/workspaces/repository')
HERE = ROOT / 'kprog/results/p3-attribution-20261126'
OUT = Path(sys.argv[1]).resolve()
LOCKS = Path('/workspaces/.agent-state/kprog-lanes/locks')
LANE = LOCKS.parent / 'perf'
MODULE = ROOT / 'kinsn/module/x86/build/bpf_x86_native_lab.ko'
SIZES = [2, 4, 8, 12, 14, 16, 20, 24, 32, 36, 38, 40, 41, 48, 64, 88, 224, 256, 260]

def build_command(target):
    return ['prlimit', '--as=8589934592', '--', 'taskset', '-c', '18-19',
            'make', '-C', str(HERE), target, '-j2']

def check_command(app, case):
    return ['prlimit', '--as=85899345920', '--', 'make', '-C', str(ROOT / 'kprog/perf/one-image'),
            'check', 'ORDER=' + app, 'LOGS=' + str(case / 'guest')]

if '--dry-run' in sys.argv[2:]:
    print(json.dumps(dict(locks=['timing EX', 'image EX (SH during checks)'],
        control=build_command('module-control'), normal_finally=build_command('module-normal'),
        checks=[check_command(app, OUT / f'{short}-{i}')
                for app, short in [('tetragon/observer', 'tetragon'), ('otelcol-ebpf-profiler/profiling', 'otel')]
                for i in range(1, 4)],
        treatment='Rename 19 module symbols; existing loader falls back to __htab_map_lookup_elem. '
                  'Same module source/text, sole build output, image, P and workload.'), indent=2))
    raise SystemExit(0)

OUT.mkdir(parents=True, exist_ok=True)

def journal(event, **fields):
    with (OUT / 'journal.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(time=datetime.now(timezone.utc).isoformat(), event=event, **fields)) + '\n')

def run(command, logfile):
    journal('command', argv=command, log=str(logfile))
    with logfile.open('w') as stream:
        job = subprocess.Popen(command, stdout=stream, stderr=subprocess.STDOUT)
        while True:
            try:
                return job.wait(timeout=30)
            except subprocess.TimeoutExpired:
                journal('heartbeat', pid=job.pid, log=str(logfile))

def snapshot(label):
    # Evidence only: no second module binary or source copy is kept.
    table = subprocess.check_output(['nm', '-n', str(MODULE)], text=True)
    (OUT / (label + '-symbols.txt')).write_text(table)
    text = subprocess.check_output(['readelf', '-x', '.text', str(MODULE)])
    (OUT / (label + '-text.txt')).write_bytes(text)
    return dict(module_sha256=hashlib.sha256(MODULE.read_bytes()).hexdigest(),
                text_dump_sha256=hashlib.sha256(text).hexdigest(),
                specialized=[f'kprog_htab_elem_k{n}' for n in SIZES if f' kprog_htab_elem_k{n}\n' in table],
                controls=[f'kprog_htab_control_k{n}' for n in SIZES if f' kprog_htab_control_k{n}\n' in table])

def publish(paths, message, log):
    paths = [str(p.relative_to(ROOT)) for p in paths]
    with (LOCKS / 'git').open('a') as lock, log.open('w') as stream:
        fcntl.flock(lock, fcntl.LOCK_EX)
        for command in [['git', 'status', '--short', '--untracked-files=no'],
                        ['git', 'add', '-f', '--', *paths],
                        ['git', 'commit', '--only', '-m', message, '--', *paths],
                        ['git', 'push', 'origin', 'master']]:
            subprocess.run(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT, check=True)

status = 0
normal_restored = False
try:
    journal('acquiring_resources')
    with (LOCKS / 'timing').open('a') as timing, (LOCKS / 'image').open('a') as image:
        fcntl.flock(timing, fcntl.LOCK_EX)
        fcntl.flock(image, fcntl.LOCK_EX)
        evidence = dict(source=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
                        before=snapshot('before'))
        try:
            if run(build_command('module-control'), OUT / 'module-control.log'):
                raise RuntimeError('control module build failed')
            evidence['control'] = snapshot('control')
            if evidence['control']['specialized'] or len(evidence['control']['controls']) != len(SIZES):
                raise RuntimeError('control symbol substitution failed')
            if evidence['before']['text_dump_sha256'] != evidence['control']['text_dump_sha256']:
                raise RuntimeError('control changed .text; inspect before running apps')
            (OUT / 'module-evidence.json').write_text(json.dumps(evidence, indent=2) + '\n')
            fcntl.flock(image, fcntl.LOCK_SH)
            for app, short in [('tetragon/observer', 'tetragon'), ('otelcol-ebpf-profiler/profiling', 'otel')]:
                for i in range(1, 4):
                    case = OUT / f'{short}-{i}'
                    case.mkdir()
                    command = check_command(app, case)
                    (case / 'check-command.json').write_text(json.dumps(command, indent=2) + '\n')
                    rc = run(command, case / 'controller.log')
                    (case / 'controller-exit.txt').write_text(str(rc) + '\n')
                    if rc == 0:
                        (case / 'completed.txt').write_text('Default app check command completed.\n')
                    collected = run(['make', '-C', str(ROOT / 'kprog/results/hash-family-c-20261126'),
                                     'collect', 'OUT=' + str(case)], case / 'collect.log')
                    if collected:
                        raise RuntimeError('result collection failed')
                    raw = [Path(p) for p in (case / 'raw-paths.txt').read_text().splitlines()]
                    raw = [p if p.is_absolute() else ROOT / p for p in raw]
                    publish([*[p for p in case.rglob('*') if p.is_file()], *raw],
                            'Record generic hash control ' + case.name, case / 'publication.log')
                    journal('case_finished', app=app, repetition=i, returncode=rc)
                    if rc:
                        raise RuntimeError('functional check failed; remaining dependent checks stopped')
        finally:
            fcntl.flock(image, fcntl.LOCK_EX)
            normal_rc = run(build_command('module-normal'), OUT / 'module-normal.log')
            evidence['normal_build_status'] = normal_rc
            if normal_rc == 0:
                evidence['after'] = snapshot('after')
                normal_restored = len(evidence['after']['specialized']) == len(SIZES) and not evidence['after']['controls']
            (OUT / 'module-evidence.json').write_text(json.dumps(evidence, indent=2) + '\n')
            if not normal_restored:
                raise RuntimeError('normal module rebuild failed; inspect before using this base')
except Exception:
    status = 1
    (OUT / 'exception.txt').write_text(traceback.format_exc())
    traceback.print_exc()
finally:
    (OUT / 'controller-exit.txt').write_text(str(status) + '\n')
    journal('finished', returncode=status, normal_module_restored=normal_restored)
    try:
        names = ['launch.json', 'controller.log', 'controller-exit.txt', 'journal.jsonl',
                 'module-control.log', 'module-normal.log', 'module-evidence.json', 'exception.txt',
                 'before-symbols.txt', 'before-text.txt', 'control-symbols.txt', 'control-text.txt',
                 'after-symbols.txt', 'after-text.txt']
        publish([OUT / name for name in names if (OUT / name).is_file()],
                'Record generic hash control module lifecycle', OUT / 'publication.log')
    except Exception:
        status = 1
        (OUT / 'publication-error.txt').write_text(traceback.format_exc())
    with (LANE / 'resume-msg.md').open('a') as stream:
        stream.write(f'\nP3 generic-helper control ended status {status}, normal module restored {normal_restored}. '
                     f'Read {OUT}/module-evidence.json, journal.jsonl and per-case guest summaries. '
                     'Compare against P3 repeats; record causal conclusion and fix only an evidenced within-design cause. '
                     'Full timing stays frozen.\n')
    stop = LANE / 'STOP'
    if stop.exists() and stop.read_text().startswith('PERF P3 attribution:'):
        stop.unlink()
raise SystemExit(status)
