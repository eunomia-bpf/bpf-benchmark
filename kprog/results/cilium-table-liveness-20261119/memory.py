"""Inventory stack observations after the actual rejected table definitions.

The provisional CFG supplies dispatch edges only. ABI facts come from the
original instructions, never from the rejected provisional replacement.
"""
import json
from pathlib import Path
import sys
from collections import deque

root = Path('/workspaces/repository')
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter
from x86_abi import PointerAlternatives
from helper_abi import helper_prototypes
from x86_relative_tables import private_results_dead

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
retained = root/'kprog/results/cilium-table-liveness-20261119/result.json'
previous = json.loads(retained.read_text())
rows = []
for request in previous['requests']:
    directory = Path(previous['raw'])/str(request['request'])
    insns, functions, exit_addr, rodata = adapter.gen.parse_native_linked_program('trusted_x86', directory)
    all_insns = [*insns, *(i for body in functions.values() for i in body)]
    starts = {insns[0].addr, *(body[0].addr for body in functions.values() if body)}
    captured = {}

    def observe(frame, event, value):
        if event != 'return':
            return
        if frame.f_code.co_name == 'lower_relative_tables':
            captured['provisional'] = frame.f_locals['provisional_insns']
            captured['table_targets'] = frame.f_locals['table_targets']
        elif frame.f_code.co_name == 'check_definedness':
            captured['states'] = frame.f_locals['states']
            captured['registers'] = frame.f_locals['index']

    sys.setprofile(observe)
    try:
        try:
            adapter.gen.lower_relative_tables(all_insns, rodata, adapter.gen, exit_addr, starts)
        except ValueError as error:
            if str(error) != request['error']:
                raise
        else:
            raise AssertionError('original table rejection no longer reproduces')
        provisional = captured['provisional']
        targets = adapter.gen.indirect_targets(provisional, exit_addr, starts)
        extent = adapter.gen.check_definedness(all_insns, targets, exit_addr, adapter.gen)
    finally:
        sys.setprofile(None)

    registers = captured['registers']
    rsp = registers['X86_RSP']
    original = {i.addr: i for i in all_insns}
    failure = request['failures'][0]
    store = original[failure['native_pc']]
    _, _, _, displacement = adapter.gen.parse_mem_terms(store.operands[0])
    cells = {state.aliases[rsp] + displacement
             for (_, pc), state in captured['states'].items()
             if pc == store.addr and type(state.aliases[rsp]) is int}
    width = adapter.gen.operand_width(store.operands[0])//8
    accesses, calls, unknown = [], [], []

    def alias_record(value):
        if type(value) is int:
            return dict(stack_offset=value)
        if isinstance(value, PointerAlternatives):
            return dict(stack_offsets=sorted(value.offsets), external=value.external)
        return dict(alias='external_or_scalar' if value is False else 'unknown')

    for (context, pc), state in sorted(captured['states'].items()):
        instruction = original[pc]
        for operand in instruction.operands:
            if not adapter.gen.is_mem(operand):
                continue
            base, index, scale, offset = adapter.gen.parse_mem_terms(operand)
            if base not in registers:
                continue
            pointer = state.aliases[registers[base]]
            if type(pointer) is not int:
                if pointer is not False:
                    unknown.append(dict(pc=pc, instruction=instruction.raw,
                                        operand=operand, **alias_record(pointer)))
                continue
            if index in registers:
                constant = state.constants[registers[index]]
                if constant is None:
                    unknown.append(dict(pc=pc, instruction=instruction.raw, operand=operand,
                                        alias='unknown_stack_index'))
                    continue
                offset += constant << scale
            location = pointer + offset
            size = adapter.gen.operand_width(operand)//8
            if instruction.mnemonic == 'lea':
                size = 0
            if any(location < cell+width and cell < location+size for cell in cells):
                accesses.append(dict(pc=pc, instruction=instruction.raw, operand=operand,
                                     stack_offset=location, bytes=size, context=list(context)))
        if instruction.mnemonic == 'call':
            name = instruction.reloc_symbol
            prototype = helper_prototypes().get(name)
            if prototype is None:
                calls.append(dict(pc=pc, symbol=name, scope='unresolved call memory effects'))
                continue
            args = [] if prototype.arguments == 'void' else prototype.arguments.split(',')
            pointers = []
            for parameter, reg in zip(args, ('X86_RDI','X86_RSI','X86_RDX','X86_RCX','X86_R8')):
                if '*' in parameter:
                    pointers.append(dict(parameter=parameter, register=reg,
                                         **alias_record(state.aliases[registers[reg]])))
            if any('stack_offset' in p or 'stack_offsets' in p or p.get('alias') == 'unknown'
                   for p in pointers):
                calls.append(dict(pc=pc, symbol=name, pointers=pointers,
                                  scope='Pointer roots only; pointee read extents are not proved.'))
    # Follow every dispatch/branch path from this definition until a direct
    # cell access. Helper memory effects remain explicit, unproved boundaries
    # in the report. For a readback, ask the existing register-mask analysis
    # whether its retained upper bits have any later register/flag observation.
    following = {a.addr: b.addr for a, b in zip(all_insns, all_insns[1:])}
    by_pc = {}
    for access in accesses:
        by_pc.setdefault(access['pc'], []).append(access)
    pending = deque([following[store.addr]])
    visited, frontiers, prefix_calls = set(), [], []
    while pending:
        pc = pending.popleft()
        if pc in visited or pc == exit_addr:
            continue
        visited.add(pc)
        instruction = original[pc]
        if pc in by_pc:
            frontier = dict(pc=pc, instruction=instruction.raw, accesses=by_pc[pc])
            destination = adapter.gen.reg_info(instruction.operands[0])
            if instruction.mnemonic == 'mov' and destination is not None:
                # The original MOV AL,5 overwrites bits0..7; only8..31
                # of its DWORD spill still carry the removed code address.
                masks = set()
                for access in by_pc[pc]:
                    for cell in cells:
                        mask = 0
                        for byte in range(access['bytes']):
                            if cell+1 <= access['stack_offset']+byte < cell+4:
                                mask |= 255 << (8*byte+destination[2])
                        masks.add(mask)
                frontier['upper_bits_dead_after_readback'] = all(private_results_dead(
                    all_insns, [following[pc]], (destination[0],), 0,
                    adapter.gen, exit_addr, targets, captured['table_targets'],
                    initial=(mask, 0)) for mask in masks)
                frontier['readback_masks'] = sorted(masks)
            frontiers.append(frontier)
            continue
        if instruction.mnemonic == 'call':
            prefix_calls.append(dict(pc=pc, symbol=instruction.reloc_symbol))
        if instruction.mnemonic == 'ret':
            continue
        if pc in captured['table_targets']:
            children = captured['table_targets'][pc]
        elif instruction.mnemonic == 'jmp':
            if not adapter.gen.has_direct_branch_target(instruction.operands[0]):
                frontiers.append(dict(pc=pc, instruction=instruction.raw,
                                      scope='unresolved indirect successor'))
                continue
            children = (instruction.reloc_target if instruction.reloc_target is not None
                        else adapter.gen.branch_target(instruction.operands[0]),)
        elif instruction.mnemonic in adapter.gen.CC_AUX and instruction.mnemonic.startswith('j'):
            children = (following[pc], instruction.reloc_target if instruction.reloc_target is not None
                        else adapter.gen.branch_target(instruction.operands[0]))
        else:
            children = (following.get(pc, exit_addr),)
        pending.extend(children)
    row = dict(request=request['request'], rejected_store=dict(pc=store.addr, instruction=store.raw),
               stack_cells=sorted(cells), bytes=width, stack_extent=extent,
               overlapping_accesses=accesses, calls_with_possible_stack_arguments=calls,
               unresolved_memory_aliases=unknown, first_direct_cell_accesses=frontiers,
               calls_before_first_direct_access=prefix_calls,
               unresolved_prefix_aliases=[access for access in unknown if access['pc'] in visited],
               prefix_stack_arguments=[call for call in calls if call['pc'] in visited])
    rows.append(row)
    (out/'result.json').write_text(json.dumps(dict(requests=rows,
        source_capture=previous['raw'],
        scope='Diagnostic ABI inventory of original instructions with provisional dispatch edges only; no dead-memory proof, lowering, B emission, stock acceptance, or runtime result.'), indent=2)+'\n')
    print(json.dumps(dict(request=row['request'], cells=row['stack_cells'],
                         overlaps=len(accesses), calls=len(calls), unknown_aliases=len(unknown))), flush=True)
