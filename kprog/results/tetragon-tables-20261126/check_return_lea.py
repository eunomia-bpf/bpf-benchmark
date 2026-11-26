"""A displaced saved return PC must not retain its original exact target."""
import json
from pathlib import Path
import subprocess
import sys
import types

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker
import x86_abi

revision = sys.argv[1] if len(sys.argv) > 1 else None
if revision:
    module = types.ModuleType('previous_abi')
    sys.modules[module.__name__] = module
    source = subprocess.check_output(['git', 'show', revision + ':kprog/x86/micro-prog/x86_abi.py'], text=True)
    exec(compile(source, revision, 'exec'), module.__dict__)
    x86_abi = module

linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
results = []
for name, known in [('return_lea_copy', True), ('return_lea_forward', False),
                    ('return_lea_backward', False)]:
    out = HERE / 'calls' / name
    out.mkdir(parents=True, exist_ok=True)
    linked = subprocess.run([linker, '--input', HERE / 'calls.o', '--symbol', name,
                    '--mode', 'proof', '--preserve-entry-abi',
                    '--output', out / 'test.proof.o'], text=True, capture_output=True)
    (out / 'link.json').write_text(json.dumps(dict(returncode=linked.returncode,
        stdout=linked.stdout, stderr=linked.stderr), indent=2) + '\n')
    linked.check_returncode()
    insns, functions, end, _ = worker.gen.parse_native_linked_program('test', out)
    all_insns = [*insns, *(i for body in functions.values() for i in body)]
    sites, states = {}, {}
    x86_abi.check_definedness(all_insns, {}, end, worker.gen,
                             return_sites_by_pc=sites, incoming_states=states)
    # Inspect the local callee's RET rather than the outer exit continuation.
    local_returns = {pc for context, pc in states if context and pc in sites}
    sites = {pc: targets for pc, targets in sites.items() if pc in local_returns}
    if len(sites) != 1:
        raise AssertionError((name, sites))
    actual = all(targets is not None and len(targets) == 1 for targets in sites.values())
    results.append(dict(case=name, known_return=actual, expected=known,
                        return_sites={str(pc): sorted(targets) if targets is not None else None
                                      for pc, targets in sites.items()}))
suffix = '-before' if revision else ''
(HERE / ('return-lea-checks' + suffix + '.json')).write_text(json.dumps(results, indent=2) + '\n')
failures = [row for row in results if row['known_return'] != row['expected']]
if failures:
    raise AssertionError(failures)
print('3 assembled return-address LEA cases passed')
