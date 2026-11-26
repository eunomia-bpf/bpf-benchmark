"""Inspect original native return destinations using the existing ABI analysis."""
import json
from pathlib import Path
import sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[2] / 'kprog/x86'))
import trusted_specializer as worker

rows = []
for ident in map(int, sys.argv[1:] or ['12']):
    insns, functions, end, rodata = worker.gen.parse_native_linked_program(
        'trusted_x86', HERE / ('request-' + str(ident)))
    original = [*insns, *(i for body in functions.values() for i in body)]
    starts = {insns[0].addr, *(body[0].addr for body in functions.values() if body)}
    captured = {}

    def observe(frame, event, value):
        if event == 'return' and frame.f_code.co_name == 'lower_relative_tables':
            captured.update(frame.f_locals)

    sys.setprofile(observe)
    try:
        worker.gen.lower_relative_tables(original, rodata, worker.gen, end, starts)
    except ValueError as error:
        captured['error'] = str(error)
    finally:
        sys.setprofile(None)
    states = {}
    targets = captured['call_targets']
    for pc, destinations in captured['table_targets'].items():
        targets[pc] = [('code', target) for target in destinations]
    row = dict(request=ident, lowering_error=captured.get('error'))
    try:
        row['stack_bytes'] = worker.gen.check_definedness(original, targets, end,
            worker.gen, incoming_states=states)
        rsp = list(dict.fromkeys(r[0] for r in worker.gen.REGS.values())).index('X86_RSP')
        by_addr = {i.addr: i for i in original}
        row['returns'] = [dict(pc=pc, context=list(context), stack=state.aliases[rsp],
            destinations=[dict(context=list(d.context), target=d.target) for d in value]
                if isinstance(value, frozenset) else repr(value))
            for (context, pc), state in sorted(states.items())
            if by_addr[pc].mnemonic == 'ret'
            for value in [state.pointers.get(state.aliases[rsp])]]
    except ValueError as error:
        row['abi_error'] = str(error)
    rows.append(row)
(HERE / 'return-paths.json').write_text(json.dumps(rows, indent=2) + '\n')
print(json.dumps(rows, indent=2))
