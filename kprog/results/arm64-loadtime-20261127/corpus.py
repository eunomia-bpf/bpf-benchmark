"""Replay the same readonly-decoder lowering for every captured Cilium request."""
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys
import traceback

ROOT = Path('/workspaces/repository')
HERE = Path(__file__).resolve().parent
LANE = Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():
    return subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip()
token = subprocess.check_output(['date', '-u', '+%Y%m%dT%H%M%SZ'], text=True).strip()
OUT = HERE/('corpus-'+token)
OUT.mkdir()
record = dict(started_utc=now(), pid=os.getpid(),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              scope='All ten captured Cilium requests, identical const-controls lowering and existing architecture flags. Diagnostic cold compiler cost; actual stock/native/full frozen startup validation remains open.',
              cases=[])
def save():
    (OUT/'controller.json').write_text(json.dumps(record, indent=2)+'\n')
try:
    save()
    attribution = json.loads((ROOT/'kprog/results/arm64-checked-corpus-20261127/loadtime-attribution.json').read_text())
    for specimen in sorted(attribution['per_request'], key=lambda row: row['request']):
        number = specimen['request']
        before = set(HERE.glob('const-controls-request'+str(number)+'-*/controller.json'))
        command = [sys.executable, str(HERE/'profile.py'), 'const-controls', str(number)]
        with (OUT/('request'+str(number)+'.log')).open('w') as log:
            result = subprocess.run(command, cwd=ROOT, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
        created = set(HERE.glob('const-controls-request'+str(number)+'-*/controller.json')) - before
        profiles = []
        for path in sorted(created):
            profile = json.loads(path.read_text())
            profiles.append(dict(controller=str(path.relative_to(ROOT)), **{key: profile.get(key) for key in
                ['raw', 'controller_status', 'exception', 'publication_error', 'commands',
                 'frontend_byte_equal_original', 'B_executable_sections_equal_original', 'B_entire_object_equal_original']}))
        record['cases'].append(dict(request=number, symbol=specimen['symbol'], command=command,
                                    returncode=result.returncode, original_frontend_seconds=specimen['host_frontend_wall_seconds'],
                                    original_frontend_max_rss_kib=specimen['host_frontend_max_rss_kib'], profiles=profiles))
        save()
    commands = [command for case in record['cases'] for profile in case['profiles'] for command in (profile.get('commands') or [])]
    frontend = [command for command in commands if '-emit-llvm' in command['command']]
    record.update(original_frontend_seconds=sum(case['original_frontend_seconds'] for case in record['cases']),
                  replay_frontend_seconds=sum(command['wall_seconds'] for command in frontend),
                  replay_all_compiler_seconds=sum(command['wall_seconds'] for command in commands),
                  replay_frontend_max_rss_kib=max((command['max_rss_kib'] for command in frontend), default=0),
                  frontend_jobs=len(frontend),
                  controller_status=int(any(case['returncode'] or len(case['profiles']) != 1 for case in record['cases'])))
except Exception:
    record.update(controller_status=1, exception=traceback.format_exc())
finally:
    record['ended_utc'] = now()
    save()
    try:
        with (LANE.parent/'locks/git').open('a') as lock, (OUT/'publication.log').open('a') as log:
            fcntl.flock(lock, fcntl.LOCK_EX)
            path = str(OUT.relative_to(ROOT))
            for command in [['git', 'add', '-f', '--', path], ['git', 'commit', '--only', '-m', 'Record common ARM decoder loading replay across captured Cilium requests', '--', path], ['git', 'push']]:
                subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
    except Exception:
        record.update(publication_error=traceback.format_exc(), controller_status=1)
        save()
    with (LANE/'resume-msg.md').open('a') as output:
        output.write(f'\nARM all-captured Cilium const-controls loading replay finished status {record["controller_status"]}. Read {OUT}/controller.json and all child raw/profile/canonical-stage receipts, then advance common producer lowering and real stock/native/full frozen startup validation; Tetragon retains original source.\n')
raise SystemExit(record['controller_status'])
