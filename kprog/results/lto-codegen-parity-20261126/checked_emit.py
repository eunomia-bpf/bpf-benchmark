"""Exercise checked-native emission only, without claiming stock acceptance."""
import gzip
import importlib.util
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
spec = importlib.util.spec_from_file_location('parity_worker', ROOT / 'kprog/x86/trusted_specializer.py')
worker = importlib.util.module_from_spec(spec)
spec.loader.exec_module(worker)
subprocess.run(['clang-18', '-E', str(HERE / 'select.c'), '-o', str(BUILD / 'fixture.i')], check=True)
artifacts = dict(simulator_preprocessed=str(BUILD / 'fixture.i'), maps=[], context_kind='raw',
                 kernel_btf='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux', simulator_program='entry')
log = BUILD / 'native-commands.jsonl'
previous_lines = len(log.read_text().splitlines(keepends=True)) if log.exists() else 0
result = worker.compile_checked_simulator(artifacts,
    ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
    Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
obj = Path(result['native_object'])
assembly = subprocess.check_output(['llvm-objdump-18', '-d', obj], text=True)
(HERE / ('checked-' + phase + '.dis')).write_text(assembly)
(HERE / ('checked-' + phase + '.o.gz')).write_bytes(gzip.compress(obj.read_bytes(), mtime=0))
subprocess.run(['gcc', '-O2', '-fsanitize=undefined', '-fno-sanitize-recover=all',
                str(HERE / 'driver.c'), str(obj), '-o', str(BUILD / 'execute')], check=True)
execution = subprocess.check_output([str(BUILD / 'execute')], text=True)
cmovs = len(re.findall(r'\bcmov[a-z]+\b', assembly))
if phase == 'after' and cmovs:
    raise AssertionError('checked-native emission lost common cmov policy')
(HERE / ('checked-' + phase + '-commands.jsonl')).write_text(''.join(log.read_text().splitlines(keepends=True)[previous_lines:]))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              phase=phase, cmov_instructions=cmovs, execution=execution,
              scope='Actual checked-native compiler function only, on a standalone codegen fixture. No service admission, stock verification, bound installation, app or timing result.')
if phase == 'after':
    with tarfile.open(HERE / 'checked-before-evidence.tar.gz') as before:
        record['frontend_ir_unchanged'] = before.extractfile('checked-simulator.bc').read() == (BUILD / 'checked-simulator.bc').read_bytes()
    if not record['frontend_ir_unchanged']:
        raise AssertionError('native policy change altered fixture frontend IR')
with tarfile.open(HERE / ('checked-' + phase + '-evidence.tar.gz'), 'w:gz') as archive:
    for path in sorted(BUILD.glob('checked-simulator.*')):
        archive.add(path, arcname=path.name)
    archive.add(log, arcname=log.name)
(HERE / ('checked-' + phase + '-result.json')).write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
