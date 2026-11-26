"""Exercise persistent-base dominance, clobbers, observations and actual RET edges."""
import json
from pathlib import Path
import subprocess
import sys
import types

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker
from x86_relative_tables import lower_relative_tables

revision = sys.argv[1] if len(sys.argv) > 1 else None
if revision:
    before = types.ModuleType('before_hoisted_tables')
    sys.modules[before.__name__] = before
    source = subprocess.check_output(['git', 'show', revision + ':kprog/x86/micro-prog/x86_relative_tables.py'], text=True)
    exec(compile(source, revision, 'exec'), before.__dict__)
    lower_relative_tables = before.lower_relative_tables

linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
definitions = 'persistent code-table base has another reaching definition'
expected = dict(hoisted_loop=None, shared_base=None, changed_base=definitions,
                bypassed_base=definitions, redirected_base=definitions, callee_changes_base=definitions,
                observed_base='persistent code-table base has an observable use',
                live_flags='relative table computation has live register or flag results')
rows = []
for name, error in expected.items():
    out = HERE / 'hoisted' / name
    out.mkdir(parents=True, exist_ok=True)
    command = [linker, '--input', HERE / 'hoisted.o', '--symbol', name, '--mode', 'proof',
        '--preserve-entry-abi', '--output', out / 'test.proof.o']
    linked = subprocess.run(command, text=True, capture_output=True)
    (out / 'linker.json').write_text(json.dumps(dict(command=list(map(str, command)),
        returncode=linked.returncode, stdout=linked.stdout, stderr=linked.stderr), indent=2) + '\n')
    if linked.returncode:
        raise RuntimeError(linked.stderr)
    insns, functions, end, rodata = worker.gen.parse_native_linked_program('test', out)
    original = [*insns, *(i for body in functions.values() for i in body)]
    starts = {insns[0].addr, *(body[0].addr for body in functions.values() if body)}
    row = dict(case=name, expected_error=error)
    try:
        lowered = lower_relative_tables(original, rodata, worker.gen, end, starts)
        row['actual_error'] = None if any(i.code_table is not None for i in lowered) else 'table dispatch not lowered'
        if not revision and row['actual_error'] is None:
            for lea in original:
                if lea.mnemonic == 'lea' and lea.reloc_symbol in rodata:
                    assert any(i.addr == lea.addr and i.mnemonic == 'nop' for i in lowered)
    except ValueError as exception:
        row['actual_error'] = str(exception)
    row['passed'] = row['actual_error'] == error if not revision else (row['actual_error'] is None) == (error is None)
    rows.append(row)
(HERE / ('hoisted-checks-before.json' if revision else 'hoisted-checks.json')).write_text(json.dumps(rows, indent=2) + '\n')
if any(not row['passed'] for row in rows):
    raise AssertionError([row for row in rows if not row['passed']])
print(str(len(rows)) + ' actual persistent-table cases passed')
