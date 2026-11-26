"""Check local-call liveness using real assembled/linked instruction effects."""
import json
import inspect
from pathlib import Path
import subprocess
import sys
import types

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker
from x86_relative_tables import private_results_dead, lower_relative_tables

revision = sys.argv[1] if len(sys.argv) > 1 else None
if revision:
    before = types.ModuleType('before_relative_tables')
    sys.modules[before.__name__] = before
    source = subprocess.check_output(['git', 'show', revision + ':kprog/x86/micro-prog/x86_relative_tables.py'], text=True)
    exec(compile(source, revision, 'exec'), before.__dict__)
    private_results_dead = before.private_results_dead
    lower_relative_tables = before.lower_relative_tables

linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
expected = dict(unused_local=True, callee_reads_register=False, caller_reads_register=False,
                callee_reads_flags=False, caller_reads_flags=False, unresolved_external=False,
                known_helper=True, caller_discards_return=True, caller_uses_return=False)
expected.update(callee_defines_return=True, callee_partial_return=False,
                callee_conditional_return=False, callee_nested_return=True,
                callee_defines_flags=True, redirected_return=True, unresolved_return=False)
results = []
for name, answer in expected.items():
    out = HERE / 'calls' / name
    out.mkdir(parents=True, exist_ok=True)
    subprocess.run([linker, '--input', HERE / 'calls.o', '--symbol', name, '--mode', 'proof',
        '--preserve-entry-abi', '--output', out / 'test.proof.o'], check=True, capture_output=True)
    insns, functions, end, rodata = worker.gen.parse_native_linked_program('test', out)
    all_insns = [*insns, *(i for body in functions.values() for i in body)]
    scratch = ('X86_RAX', 'X86_RDX') if name.endswith('return') and name != 'redirected_return' else ('X86_R8', 'X86_RDX')
    options = {}
    if 'return_destinations' in inspect.signature(private_results_dead).parameters and name != 'unresolved_external':
        states = {}
        worker.gen.check_definedness(all_insns, {}, end, worker.gen, incoming_states=states)
        rsp = list(dict.fromkeys(r[0] for r in worker.gen.REGS.values())).index('X86_RSP')
        destinations = {}
        by_addr = {i.addr: i for i in all_insns}
        for (_, pc), state in states.items():
            if by_addr[pc].mnemonic == 'ret':
                stack = state.aliases[rsp]
                values = state.pointers.get(stack) if type(stack) is int else None
                if not isinstance(values, frozenset) or not values:
                    destinations[pc] = None
                elif destinations.get(pc, set()) is not None:
                    destinations.setdefault(pc, set()).update(d.target for d in values)
        options['return_destinations'] = destinations
    actual = private_results_dead(all_insns, [insns[0].addr], scratch, 63,
                                  worker.gen, end, {}, {}, **options)
    results.append(dict(case=name, private_results_dead=actual, expected=answer))
for name, answer in [('table_private_stack', True), ('table_external_stack', False)]:
    out = HERE / 'calls' / name
    out.mkdir(parents=True, exist_ok=True)
    subprocess.run([linker, '--input', HERE / 'calls.o', '--symbol', name, '--mode', 'proof',
        '--preserve-entry-abi', '--output', out / 'test.proof.o'], check=True, capture_output=True)
    insns, functions, end, rodata = worker.gen.parse_native_linked_program('test', out)
    all_insns = [*insns, *(i for body in functions.values() for i in body)]
    starts = {insns[0].addr, *(body[0].addr for body in functions.values() if body)}
    try:
        lowered = lower_relative_tables(all_insns, rodata, worker.gen, end, starts)
        actual = any(i.code_table is not None for i in lowered)
    except ValueError as error:
        if str(error) != 'relative table computation has live register or flag results':
            raise
        actual = False
    results.append(dict(case=name, private_results_dead=actual, expected=answer))
suffix = '-before' if revision else ''
(HERE / ('call-checks' + suffix + '.json')).write_text(json.dumps(results, indent=2) + '\n')
failures = [row for row in results if row['private_results_dead'] != row['expected']]
if failures:
    raise AssertionError(failures)
print(str(len(results)) + ' assembled local/helper-call liveness cases passed')
