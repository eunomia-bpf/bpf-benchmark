"""Finite existing checked-native regression, with evidence and resume callback."""
import fcntl
import json
import os
from pathlib import Path
import subprocess
import traceback

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
LANE = Path('/workspaces/.agent-state/kprog-lanes/perf')

def now():
    return subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip()

token = subprocess.check_output(['date', '-u', '+%Y%m%dT%H%M%SZ'], text=True).strip()
OUT = HERE / ('guest-' + token)
RAW = Path('/workspaces/kprog-raw/perf/lto-codegen-parity-20261126') / token
OUT.mkdir(); RAW.mkdir(parents=True)
record = dict(started_utc=now(), pid=os.getpid(), raw=str(RAW),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              scope='Existing control+12 probe inputs through stock verification and checked-sim-c installation/TEST_RUN. No application or timing result.', commands=[])

def save():
    (OUT / 'controller.json').write_text(json.dumps(record, indent=2) + '\n')

status = 1
try:
    save()
    for target in ['programs', 'run']:
        command = ['make', '-f', 'kprog/results/kernel-probe-live-20261120/Makefile', target, 'OUT=' + str(RAW)]
        with (RAW / (target + '.log')).open('w') as log:
            result = subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
        record['commands'].append(dict(command=command, returncode=result.returncode))
        save()
        result.check_returncode()
    status = 0
except Exception:
    record['exception'] = traceback.format_exc()
finally:
    try:
        if (RAW / 'cases.json').exists():
            record['cases'] = json.loads((RAW / 'cases.json').read_text())
        with (OUT / 'archive.log').open('w') as log:
            commands = [['tar', '-C', str(RAW.parent), '-cf', '-', RAW.name], ['zstd', '-T1', '-3', '-c'],
                        ['split', '-b', '48000000', '-', str(OUT / 'guest-evidence.tar.zst.part-')]]
            first = subprocess.Popen(commands[0], stdout=subprocess.PIPE, stderr=log)
            second = subprocess.Popen(commands[1], stdin=first.stdout, stdout=subprocess.PIPE, stderr=log)
            first.stdout.close()
            third = subprocess.Popen(commands[2], stdin=second.stdout, stderr=log)
            second.stdout.close()
            codes = [third.wait(), second.wait(), first.wait()][::-1]
        record.update(archive_commands=commands, archive_returncodes=codes)
        if any(codes):
            raise RuntimeError('guest evidence archive failed')
        record['archive_parts'] = [dict(name=p.name, bytes=p.stat().st_size) for p in sorted(OUT.glob('guest-evidence.tar.zst.part-*'))]
        record.update(ended_utc=now(), controller_status=status)
        save()
        with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('a') as lock, (OUT / 'publication.log').open('a') as log:
            fcntl.flock(lock, fcntl.LOCK_EX)
            paths = [str(OUT.relative_to(ROOT))]
            for command in [['git', 'add', '-f', '--', *paths],
                            ['git', 'commit', '--only', '-m', 'Record checked-native codegen policy guest regression', '--', *paths],
                            ['git', 'push']]:
                subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
    except Exception:
        status = 1
        record.update(publication_or_archive_error=traceback.format_exc(), controller_status=status, ended_utc=now())
        save()
    finally:
        with (LANE / 'resume-msg.md').open('a') as message:
            message.write(f'\nNative codegen policy guest check ended status {status}. Read {OUT}/controller.json, publication.log and archived/raw per-case service receipts. Record actual stock/checked installation/TEST_RUN outcomes, verify the common native backend option in emitted commands, fix real failures within design, and retain full timing freeze.\n')
        stop = LANE / 'STOP'
        if stop.exists() and stop.read_text().startswith('PERF native codegen guest:'):
            stop.unlink()
raise SystemExit(status)
