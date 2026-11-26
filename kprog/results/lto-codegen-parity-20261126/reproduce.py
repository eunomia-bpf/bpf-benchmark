"""Check a P backend option through the real load-time native compiler."""
import gzip
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/lto-codegen-parity')
BUILD.mkdir(parents=True, exist_ok=True)
commands = []

def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (HERE / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
    return result.stdout

source = BUILD / 'p.o'
output = BUILD / 'lto.o'
exe = BUILD / 'execute'
tool = ROOT / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
run(['clang-18', '-O3', '-g', '-fPIC', '-c', '-march=native', '-mno-red-zone',
     '-mgeneral-regs-only', '-fomit-frame-pointer', '-fno-stack-protector',
     '-fno-jump-tables', '-fno-optimize-sibling-calls', '-mllvm',
     '-x86-cmov-converter-force-all', '-Xclang', '-fembed-bitcode=all',
     HERE / 'select.c', '-o', source])
rows = []
for name, extra in [('p', None), ('lto-default', []),
                    ('lto-common-option', ['--x86-cmov-converter-force-all'])]:
    obj = source
    if extra is not None:
        run([tool, source, '--symbol', 'entry', '--prog-type', '5',
             '--kernel-btf', '/workspaces/.agent-state/kprog-ck/build-x86/vmlinux',
             *extra, '-o', output])
        obj = output
    assembly = run(['llvm-objdump-18', '-d', obj])
    (HERE / (name + '.dis')).write_text(assembly)
    (HERE / (name + '.o.gz')).write_bytes(gzip.compress(obj.read_bytes(), mtime=0))
    run(['gcc', '-O2', '-fsanitize=undefined', '-fno-sanitize-recover=all',
         HERE / 'driver.c', obj, '-o', exe])
    execution = run([exe])
    rows.append(dict(name=name, cmov_instructions=len(re.findall(r'\bcmov[a-z]+\b', assembly)),
                     execution=execution, object_bytes=obj.stat().st_size))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              rows=rows, scope='Existing native compiler codegen/host semantic regression only. No app, image, runtime, benchmark or timing change; no speedup claim.')
(HERE / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
