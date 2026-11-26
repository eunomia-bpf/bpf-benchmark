"""Inventory existing ARM select codegen; do not change production policy."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
commands = []

def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stderr=result.stderr))
    result.check_returncode()
    return result.stdout

fixture = ROOT / 'kprog/results/lto-codegen-parity-20261126/select.c'
controls = []
for name, extra in [('default', []), ('without-early-ifcvt',
                                     ['-mllvm', '-aarch64-enable-early-ifcvt=false'])]:
    assembly = run(['clang-18', '--target=aarch64-linux-gnu', '-O3',
        '-mtune=neoverse-n1', '-mgeneral-regs-only', '-mno-outline-atomics',
        '-ffixed-x26', '-fno-stack-protector', '-S', fixture, '-o', '-', *extra])
    (HERE / ('select-' + name + '.s')).write_text(assembly)
    controls.append(dict(name=name, select_family_instructions=len(re.findall(
        r'\bcs(?:el|inc|inv|neg|et|etm)\b', assembly))))
objects = []
for obj in sorted((ROOT / 'vendor/build/native-bpf/arm64/stage').glob('*/*.native.o')):
    with obj.open('rb') as stream:
        bitcode = ELFFile(stream).get_section_by_name('.llvmbc').data()
    result = subprocess.run(['llvm-dis-18', '-o', '-', '-'], input=bitcode,
                            capture_output=True, check=True)
    function = None
    selects = []
    attributes = []
    for line in result.stdout.decode().splitlines():
        if line.startswith('define '):
            function = line.split('@', 1)[1].split('(', 1)[0]
        if re.search(r'= select\b', line):
            selects.append(dict(function=function, ir=line.strip()))
        if line.startswith('attributes #'):
            attributes.append(line)
    assembly = run(['llvm-objdump-18', '-d', obj])
    family = Counter()
    sites = []
    instruction_count = 0
    for line in assembly.splitlines():
        symbol = re.match(r'[0-9a-f]+ <(.+)>:', line)
        if symbol:
            function = symbol[1]
        insn = re.match(r'\s*[0-9a-f]+:\s+[0-9a-f]{8}\s+(\S+)', line)
        if insn:
            instruction_count += 1
            if re.fullmatch(r'cs(?:el|inc|inv|neg|et|etm)', insn[1]):
                family[insn[1]] += 1
                sites.append(dict(function=function, assembly=line.strip()))
    objects.append(dict(object=str(obj.relative_to(ROOT)), object_bytes=obj.stat().st_size,
                        ir_selects=selects, attributes=attributes,
                        native_instruction_count=instruction_count,
                        native_select_counts=family, native_select_sites=sites))
by_app = {}
for row in objects:
    app = Path(row['object']).parent.name
    summary = by_app.setdefault(app, dict(objects=0, ir_selects=0,
        native_instructions=0, native_selects=0))
    summary['objects'] += 1
    summary['ir_selects'] += len(row['ir_selects'])
    summary['native_instructions'] += row['native_instruction_count']
    summary['native_selects'] += len(row['native_select_sites'])
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
    revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
    controls=controls, by_app=by_app, objects=objects, commands=commands,
    sources=[dict(url='https://github.com/llvm/llvm-project/blob/llvmorg-18.1.3/llvm/lib/Target/AArch64/AArch64.td',
                  lines='1237-1245', finding='N1 tune already enables select optimization and predictable-select-expensive.'),
             dict(url='https://github.com/llvm/llvm-project/blob/llvmorg-18.1.3/llvm/lib/Target/AArch64/AArch64TargetMachine.cpp',
                  lines='612-613,759-760', finding='O3 adds SelectOptimize; early if-conversion is a later distinct pass.')],
    scope='Static current-stage census and fixed compiler mechanism control only; no runtime weight, speedup, semantic execution, application or stock acceptance claim. No production flags, image, P or framework change.')
(HERE / 'select-audit.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(dict(controls=controls, by_app=by_app), indent=2))
