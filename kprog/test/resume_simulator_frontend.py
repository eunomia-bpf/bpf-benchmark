"""Continue the normal B pipeline from a measured, matching LLVM frontend."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / 'kprog/x86'), str(ROOT / 'kprog/fidelity')]
import trusted_specializer as worker
import scale


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    record = dict(completed=False, profile=str(a.profile), source=str(a.source),
                  object=str(a.object), scope='Normal bounds/MIR/all-pairs/llc continuation; no kernel submission')
    commands = []

    def run(command):
        log = a.output / f'command-{len(commands):03d}.log'
        code = scale.run(command, log)
        commands.append(json.loads(log.with_suffix(log.suffix + '.resources.json').read_text()))
        (a.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        if code:
            raise subprocess.CalledProcessError(code, list(map(str, command)))

    try:
        profile = json.loads(a.profile.read_text())
        record['profile_sha256'] = digest(a.profile)
        if not profile['completed'] or not profile['frontend_completed']:
            raise ValueError('Frontend did not complete; there is no completed LLVM input to resume')
        frontend = a.source.with_suffix('.bounds-input.bc')
        if digest(frontend) != profile['frontend_sha256']:
            raise ValueError('Canonical LLVM input differs from the completed frontend record')
        if digest(a.source) != profile['source_sha256']:
            raise ValueError('Canonical simulator source differs from the completed frontend record')
        record.update(frontend_sha256=digest(frontend), source_sha256=digest(a.source),
                      bounds_sha256=digest(a.bounds), source_head=subprocess.check_output(
                          ['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip())
        worker.compile_simulator_from_frontend(str(ROOT / 'kprog/stock-path/bin/clang'),
            a.source, a.object, run, frontend=frontend, bounds_compiler=a.bounds)
        record.update(completed=True, object_sha256=digest(a.object), object_bytes=a.object.stat().st_size)
    except (OSError, ValueError, KeyError, RuntimeError, subprocess.CalledProcessError) as error:
        record['error'] = str(error)
        raise
    finally:
        record['wall_seconds'] = time.monotonic() - started
        (a.output / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
        print(json.dumps(record), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('profile', 'source', 'object', 'bounds', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    main(parser.parse_args())
