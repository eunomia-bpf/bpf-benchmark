"""Compare current atomic codegen with LSE and the existing ARM decoder."""
from collections import Counter
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
model_dir = ROOT / 'kprog/arm64/micro-prog'
sys.path.insert(0, str(model_dir))
spec = importlib.util.spec_from_file_location('arm_atomic_model', model_dir / 'generate_micro_sim_proofs.py')
model = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = model
spec.loader.exec_module(model)
source = '''unsigned long fetch_add(unsigned long *p, unsigned long v) { return __sync_fetch_and_add(p,v); }
unsigned long fetch_or(unsigned long *p, unsigned long v) { return __sync_fetch_and_or(p,v); }
unsigned long fetch_and(unsigned long *p, unsigned long v) { return __sync_fetch_and_and(p,v); }
unsigned long fetch_xor(unsigned long *p, unsigned long v) { return __sync_fetch_and_xor(p,v); }
unsigned long exchange(unsigned long *p, unsigned long v) { return __atomic_exchange_n(p,v,__ATOMIC_SEQ_CST); }
unsigned long compare_exchange(unsigned long *p, unsigned long v) { return __sync_val_compare_and_swap(p,0,v); }
'''
atomic = re.compile(r'^(?:ldaxr|ldxr|stlxr|stxr|ldadd|ldset|ldclr|ldeor|swp|cas|stadd|stset|stclr|steor)(?:al|a|l)?(?:b|h)?$')
records = []
for extra in ([], ['-march=armv8-a+lse']):
    command = ['clang-18', '--target=aarch64-linux-gnu', '-O3', '-fPIC',
               '-fomit-frame-pointer', '-mtune=neoverse-n1', '-mgeneral-regs-only',
               '-mno-outline-atomics', '-ffixed-x26', '-fno-stack-protector',
               *extra, '-x', 'c', '-S', '-', '-o', '-']
    result = subprocess.run(command, input=source, text=True, capture_output=True, check=True)
    decoded = []
    for line in result.stdout.splitlines():
        match = re.match(r'^\s+([a-z0-9]+)\s+(.+?)(?:\s*//.*)?$', line)
        if not match or not atomic.match(match[1]):
            continue
        insn = model.NativeInsn(0, match[1], model.split_operands(match[2]), line.strip())
        try:
            encoded = model.encode(insn, {}, {})
            decoded.append(dict(instruction=line.strip(), encoded=repr(encoded)))
        except ValueError as error:
            decoded.append(dict(instruction=line.strip(), error=str(error)))
    records.append(dict(command=command, returncode=result.returncode,
                        stdout=result.stdout, stderr=result.stderr, atomic_decode=decoded))
staged = []
for obj in sorted((ROOT / 'vendor/build/native-bpf/arm64/stage').glob('*/*.native.o')):
    command = ['aarch64-linux-gnu-objdump', '-d', str(obj)]
    result = subprocess.run(command, text=True, capture_output=True, check=True)
    rows = []
    for line in result.stdout.splitlines():
        match = re.match(r'^\s*[0-9a-f]+:\s+[0-9a-f]{8}\s+([a-z0-9.]+)\s', line)
        if match and atomic.match(match[1]):
            rows.append(dict(mnemonic=match[1], line=line))
    staged.append(dict(object=str(obj.relative_to(ROOT)), bytes=obj.stat().st_size,
                       command=command, counts=dict(Counter(r['mnemonic'] for r in rows)), atomic_instructions=rows))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              source=source, probes=records, staged=staged,
              scope='Codegen and existing decoder capability only. No production flags, P build, image, runtime or timing changed; no speedup or hot-path attribution claimed.')
(HERE / 'atomic-probe.json').write_text(json.dumps(record, indent=2) + '\n')
for probe in records:
    print('flags', probe['command'][10:16], 'atomic instructions', len(probe['atomic_decode']))
    for row in probe['atomic_decode']:
        print(row['instruction'], row.get('error', 'decoder accepted'))
print('staged object count', len(staged))
for app in sorted({Path(r['object']).parent.name for r in staged}):
    counts = Counter()
    for row in staged:
        if Path(row['object']).parent.name == app:
            counts.update(row['counts'])
    print(app, dict(counts))
