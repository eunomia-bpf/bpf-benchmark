"""Compare the existing producer and checked-native ARM ABI flags."""
import gzip
import importlib.util
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
BUILD.mkdir(parents=True, exist_ok=True)
spec = importlib.util.spec_from_file_location('arm_abi_worker', ROOT / 'kprog/arm64/trusted_specializer.py')
worker = importlib.util.module_from_spec(spec)
spec.loader.exec_module(worker)
rows = []
for name, flags in [('checked-before', worker.AARCH64_HELPER_FLAGS),
                    ('producer-policy', [*worker.AARCH64_HELPER_FLAGS,
                     '-mtune=neoverse-n1', '-mno-outline-atomics', '-ffixed-x26'])]:
    output = BUILD / 'fixture.o'
    command = ['clang-18', *flags, '-c', HERE / 'abi_fixture.c', '-o', output]
    result = subprocess.run(list(map(str, command)), text=True, capture_output=True, check=True)
    assembly = subprocess.check_output(['aarch64-linux-gnu-objdump', '-dr', str(output)], text=True)
    undefined = subprocess.check_output(['llvm-nm-18', '-u', '-j', str(output)], text=True).splitlines()
    (HERE / ('abi-' + name + '.dis')).write_text(assembly)
    (HERE / ('abi-' + name + '.o.gz')).write_bytes(gzip.compress(output.read_bytes(), mtime=0))
    proof = BUILD / 'fixture.proof.o'
    link_command = [ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
                    '--input', output, '--symbol', 'atomic_entry', '--mode', 'proof',
                    '--preserve-entry-abi', '--output', proof]
    link = subprocess.run(list(map(str, link_command)), text=True, capture_output=True)
    rows.append(dict(name=name, command=list(map(str, command)), returncode=result.returncode,
                     stdout=result.stdout, stderr=result.stderr, undefined=undefined,
                     proof_command=list(map(str, link_command)), proof_returncode=link.returncode,
                     proof_stdout=link.stdout, proof_stderr=link.stderr))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              rows=rows, scope='Compiler/ABI compatibility diagnostic only. Canonical diagnostic object replaced in place after archiving; production flags/builds/image unchanged. No app or performance claim.')
(HERE / 'abi-probe.json').write_text(json.dumps(record, indent=2) + '\n')
for row in rows:
    print(row['name'], 'undefined', row['undefined'], 'proof', row['proof_returncode'], row['proof_stderr'])
