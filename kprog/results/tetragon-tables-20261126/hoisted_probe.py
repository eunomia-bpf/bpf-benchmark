"""Inspect the persistent-base obligation on the retained identical proof class.

This is a proposed dispatch substitution in memory, not production generation.
It checks private-state observations; reaching-base provenance remains separate.
"""
from dataclasses import replace
import json
from pathlib import Path
import sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[2] / 'kprog/x86'))
import trusted_specializer as worker
from x86_relative_tables import NativeEffects, private_results_dead

insns, functions, end, rodata = worker.gen.parse_native_linked_program('trusted_x86', HERE / 'request-9')
original = [*insns, *(i for body in functions.values() for i in body)]
starts = {insns[0].addr, *(body[0].addr for body in functions.values() if body)}
captured = {}

def observe(frame, event, value):
    if event == 'return' and frame.f_code.co_name == 'lower_relative_tables':
        captured.update(frame.f_locals)
    if event == 'return' and frame.f_code.co_name == 'private_results_dead' and value is False:
        state = frame.f_locals
        captured['observation'] = dict(pc=state['addr'], instruction=state['insn'].raw,
            private_masks=state['live'])

sys.setprofile(observe)
try:
    worker.gen.lower_relative_tables(original, rodata, worker.gen, end, starts)
except ValueError as error:
    if str(error) != 'unresolved finite indirect target at 0x3580: jmp    rax':
        raise
finally:
    sys.setprofile(None)
by_addr = {i.addr: i for i in original}
lea, load, add, jump = [by_addr[pc] for pc in (0x3560, 0x3579, 0x357d, 0x3580)]
data = rodata[lea.reloc_symbol]
choices = tuple((offset, target) for offset, target in data.code_relocations)
full = (1 << 64) - 1
substitution = replace(load, mnemonic='mov', operands=('rax', 'rcx'), end_addr=add.end_addr,
    code_table=choices, effects=NativeEffects((('X86_RCX', full),), (('X86_RAX', full),), 0, 0))
provisional = [substitution if i.addr == load.addr else i
               for i in captured['provisional_insns'] if i.addr != add.addr]
targets = worker.gen.indirect_targets(provisional, end, starts)
table_targets = dict(captured['table_targets'])
table_targets[jump.addr] = tuple(target for _, target in choices)
states = {}
worker.gen.check_definedness(original, targets, end, worker.gen, incoming_states=states)
rsp = list(dict.fromkeys(info[0] for info in worker.gen.REGS.values())).index('X86_RSP')
returns = {}
for (_, pc), state in states.items():
    if by_addr[pc].mnemonic != 'ret':
        continue
    stack = state.aliases[rsp]
    destinations = state.pointers.get(stack) if type(stack) is int else None
    if not isinstance(destinations, frozenset) or not destinations:
        returns[pc] = None
    elif returns.get(pc, set()) is not None:
        returns.setdefault(pc, set()).update(d.target for d in destinations)
sys.setprofile(observe)
try:
    dead = private_results_dead(provisional, [lea.end_addr], ('X86_R15',), 0,
        worker.gen, end, targets, table_targets, return_destinations=returns)
finally:
    sys.setprofile(None)
record = dict(request=9, scope=__doc__, table_bytes=len(data), choices=choices,
    private_base_dead_after_proposed_dispatch=dead, first_observation=captured.get('observation'),
    reaching_base_provenance='Not tested; required before production substitution.')
(HERE / 'hoisted-probe.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
