"""Exercise actual loader invocation and cache invalidation, not a stub."""
import gzip
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/lto-codegen-parity')
phase = sys.argv[1]
commands = []

def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (HERE / ('loader-' + phase + '-commands.json')).write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
    return result.stdout

manual = BUILD / 'lto.o'
if phase == 'base':
    with tarfile.open(HERE / 'loader-cache-evidence.tar.gz', 'w:gz') as archive:
        for path in sorted((BUILD / 'cache').iterdir()):
            archive.add(path, arcname=path.name)
    for path in (BUILD / 'cache').glob('*.perf.native.o'):
        if path.read_bytes() != gzip.decompress((HERE / 'loader-after.o.gz').read_bytes()):
            raise ValueError('previous cache object archive differs')
        path.unlink()
if phase == 'before' and manual.exists():
    if gzip.decompress((HERE / 'lto-common-option.o.gz').read_bytes()) != manual.read_bytes():
        raise ValueError('manual diagnostic archive differs')
    manual.unlink()
run(['g++', '-std=c++20', HERE / 'loader_call.cpp', '-L' + str(ROOT / 'kprog/libnativeloader/build'),
     '-lnative_loader', '-Wl,-rpath=' + str(ROOT / 'kprog/libnativeloader/build'), '-o', BUILD / 'loader-call'])
call = [BUILD / 'loader-call', BUILD / 'p.o',
        ROOT / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto', BUILD / 'cache']
obj = Path(run(call).strip())
assembly = run(['llvm-objdump-18', '-d', obj])
(HERE / ('loader-' + phase + '.dis')).write_text(assembly)
payload = obj.read_bytes()
(HERE / ('loader-' + phase + '.o.gz')).write_bytes(gzip.compress(payload, mtime=0))
run(['gcc', '-O2', '-fsanitize=undefined', '-fno-sanitize-recover=all',
     HERE / 'driver.c', obj, '-o', BUILD / 'execute'])
execution = run([BUILD / 'execute'])
cmovs = len(re.findall(r'\bcmov[a-z]+\b', assembly))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              phase=phase, cmov_instructions=cmovs, execution=execution,
              scope='Actual shared-library context LTO and host oracle only; no app, stock verification, image or timing result.')
marker = BUILD / 'previous-cache-path.txt'
if phase == 'before':
    marker.write_text(str(obj))
    if gzip.decompress((HERE / 'loader-before.o.gz').read_bytes()) != payload:
        raise ValueError('old cache object archive differs')
    obj.write_bytes(b'')  # Deliberately stale cache sentinel, not a second build.
elif phase == 'after':
    previous = Path(marker.read_text())
    if obj == previous or cmovs:
        raise AssertionError('common option/cache identity regression')
    stamp = obj.stat().st_mtime_ns
    repeated = Path(run(call).strip())
    if repeated != obj or obj.stat().st_mtime_ns != stamp:
        raise AssertionError('current cache hit unexpectedly regenerated output')
    record.update(stale_cache_ignored=True, current_cache_reused=True)
    previous.unlink()
else:
    if cmovs:
        raise AssertionError('canonical base lost common codegen policy')
    record.update(canonical_library=str((ROOT / 'kprog/libnativeloader/build/libnative_loader.so').resolve()),
                  fresh_base_emission=True)
(HERE / ('loader-' + phase + '-result.json')).write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
