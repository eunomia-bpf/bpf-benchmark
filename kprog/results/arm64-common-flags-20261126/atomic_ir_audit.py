"""Inventory actual embedded-IR atomic operations before an LSE flag change."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
records = []
for obj in sorted((ROOT / 'vendor/build/native-bpf/arm64/stage').glob('*/*.native.o')):
    with obj.open('rb') as stream:
        section = ELFFile(stream).get_section_by_name('.llvmbc')
        if section is None:
            raise ValueError(f'No embedded IR: {obj}')
        bitcode = section.data()
    command = ['llvm-dis-18', '-o', '-', '-']
    result = subprocess.run(command, input=bitcode, capture_output=True, check=True)
    function = None
    operations = []
    for line in result.stdout.decode().splitlines():
        if line.startswith('define '):
            function = line.split('@', 1)[1].split('(', 1)[0]
        match = re.search(r'\b(atomicrmw\s+(?:volatile\s+)?\w+|cmpxchg)\b', line)
        if match:
            operations.append(dict(function=function, operation=match[1], ir=line.strip()))
    records.append(dict(object=str(obj.relative_to(ROOT)), bitcode_bytes=len(bitcode),
                        command=command, operations=operations))
    print(str(obj.relative_to(ROOT)), len(operations), flush=True)
by_app = {}
for row in records:
    counts = by_app.setdefault(Path(row['object']).parent.name, Counter())
    counts.update(op['operation'] for op in row['operations'])
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              by_app=by_app, objects=records,
              scope='Static complete staged-object IR census, not hot-path attribution, candidate recompilation, stock acceptance or performance measurement. Production flags/builds/image unchanged.')
(HERE / 'atomic-ir-audit.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(by_app, indent=2))
