"""Check local-call liveness using real assembled/linked instruction effects."""
import json
from pathlib import Path
import subprocess
import sys
import types

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker
from x86_relative_tables import private_results_dead

revision = sys.argv[1] if len(sys.argv) > 1 else None
if revision:
    before = types.ModuleType('before_relative_tables')
    sys.modules[before.__name__] = before
    source = subprocess.check_output(['git', 'show', revision + ':kprog/x86/micro-prog/x86_relative_tables.py'], text=True)
    exec(compile(source, revision, 'exec'), before.__dict__)
    private_results_dead = before.private_results_dead

linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
expected = dict(unused_local=True, callee_reads_register=False, caller_reads_register=False,
                callee_reads_flags=False, caller_reads_flags=False, unresolved_external=False,
                known_helper=True, caller_discards_return=True, caller_uses_return=False)
results = []
for name, answer in expected.items():
    out = HERE / 'calls' / name
    out.mkdir(parents=True, exist_ok=True)
    subprocess.run([linker, '--input', HERE / 'calls.o', '--symbol', name, '--mode', 'proof',
        '--preserve-entry-abi', '--output', out / 'test.proof.o'], check=True, capture_output=True)
    insns, functions, end, rodata = worker.gen.parse_native_linked_program('test', out)
    all_insns = [*insns, *(i for body in functions.values() for i in body)]
    scratch = ('X86_RAX', 'X86_RDX') if name.startswith('caller_') and name.endswith('return') else ('X86_R8', 'X86_RDX')
    actual = private_results_dead(all_insns, [insns[0].addr], scratch, 63,
                                  worker.gen, end, {}, {})
    results.append(dict(case=name, private_results_dead=actual, expected=answer))
suffix = '-before' if revision else ''
(HERE / ('call-checks' + suffix + '.json')).write_text(json.dumps(results, indent=2) + '\n')
failures = [row for row in results if row['private_results_dead'] != row['expected']]
if failures:
    raise AssertionError(failures)
print('9 assembled local/helper-call liveness cases passed')
