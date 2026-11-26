"""Image-bound facts for lowering compiler-generated code tables."""
from dataclasses import dataclass
from dataclasses import replace
from collections import deque
import json
import re
from helper_abi import helper_prototypes


@dataclass(frozen=True)
class NativeEffects:
    reads: tuple[tuple[str, int], ...]
    writes: tuple[tuple[str, int], ...]
    flags_read: int
    flags_written: int


class ReadonlyBytes(bytes):
    def __new__(cls, data, code_relocations=(), map_relocations=(), absolute_code_relocations=()):
        value = super().__new__(cls, data)
        value.code_relocations = tuple(code_relocations)
        value.map_relocations = tuple(map_relocations)
        value.absolute_code_relocations = tuple(absolute_code_relocations)
        return value


def instruction_effects(elf):
    section = elf.get_section_by_name('.native_link_x86_effects')
    if section is None:
        return {}
    record = json.loads(section.data())
    if record['version'] != 1:
        raise ValueError('unsupported native instruction effect version')
    text = elf.get_section_by_name('.text').data()
    result = {}
    for row in record['instructions']:
        start, data = row['offset'], bytes(row['bytes'])
        if not data or text[start:start+len(data)] != data or start in result:
            raise ValueError('native instruction effect is not bound to proof bytes')
        masks = []
        for name in ('reads', 'writes'):
            values = row[name]
            if any(not key.startswith('X86_R') or type(mask) is not int or not 0 <= mask < 1 << 64
                   for key, mask in values.items()):
                raise ValueError('invalid native register effect')
            masks.append(tuple(sorted(values.items())))
        result[start] = (len(data), NativeEffects(*masks, row['flags_read'], row['flags_written']))
    return result


def readonly_relocations(elf, section_index, symbol):
    symbols = elf.get_section_by_name('.symtab')
    text_index = elf.get_section_index('.text')
    start, size = symbol['st_value'], symbol['st_size']
    result, maps, absolute = [], [], []
    for section in elf.iter_sections():
        if section['sh_type'] not in {'SHT_REL', 'SHT_RELA'} or section['sh_info'] != section_index:
            continue
        for relocation in section.iter_relocations():
            offset = relocation['r_offset']
            if not start <= offset < start + size:
                continue
            target = symbols.get_symbol(relocation['r_info_sym'])
            if (section['sh_type'] == 'SHT_RELA' and relocation['r_info_type'] == 1 and
                    target['st_shndx'] == text_index and offset + 8 <= start + size):
                absolute.append((offset-start, target['st_value'] + relocation['r_addend']))
                continue
            if (section['sh_type'] == 'SHT_RELA' and relocation['r_info_type'] == 1 and
                    target['st_shndx'] == 'SHN_UNDEF' and target.name and
                    target['st_info']['type'] != 'STT_FUNC' and
                    relocation['r_addend'] == 0 and offset + 8 <= start + size):
                maps.append((offset-start, target.name))
                continue
            if (section['sh_type'] != 'SHT_RELA' or relocation['r_info_type'] != 2 or
                    target['st_shndx'] != text_index or offset + 4 > start + size):
                raise ValueError('unsupported nested native readonly relocation')
            result.append((offset-start, target['st_value'] + relocation['r_addend'] - (offset-start)))
    return tuple(sorted(result)), tuple(sorted(maps)), tuple(sorted(absolute))


def private_results_dead(insns, starts, scratch, flags, decode, exit_addr, call_targets, table_targets, *, initial=None,
                         return_destinations=None):
    """Check the bit masks of private definitions across the actual native CFG."""
    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    full, all_flags = (1 << 64) - 1, (1 << 32) - 1
    caller_saved = ('X86_RAX', 'X86_RCX', 'X86_RDX', 'X86_RSI', 'X86_RDI',
                    'X86_R8', 'X86_R9', 'X86_R10', 'X86_R11')
    arguments = ('X86_RDI', 'X86_RSI', 'X86_RDX', 'X86_RCX', 'X86_R8', 'X86_R9')
    if initial is None:
        initial = (full,) * len(scratch) + (flags,)
    pending = deque((target, initial, True) for target in starts)
    visited = {}
    while pending:
        addr, live, observes_return = pending.popleft()
        key = (addr, observes_return)
        old = visited.get(key)
        merged = live if old is None else tuple(a | b for a, b in zip(old, live))
        if old == merged:
            continue
        visited[key] = merged
        live = merged
        if addr == exit_addr:
            if any(reg == 'X86_RAX' and mask for reg, mask in zip(scratch, live[:-1])):
                return False
            continue
        insn = by_addr[addr]
        if insn.effects is None:
            raise ValueError('table liveness lacks image-bound instruction effects')
        reads, writes = dict(insn.effects.reads), dict(insn.effects.writes)
        flags_read, flags_written = insn.effects.flags_read, insn.effects.flags_written
        local_target = None
        if insn.mnemonic == 'call':
            target = insn.reloc_target
            if target is None and insn.reloc_symbol is None and decode.has_direct_branch_target(insn.operands[0]):
                target = decode.branch_target(insn.operands[0])
            if target in by_addr:
                local_target = target
        if insn.mnemonic == 'call' and local_target is None:
            prototype = helper_prototypes().get(insn.reloc_symbol)
            prototypes = [prototype] if prototype is not None else []
            if not prototypes:
                for kind, target in call_targets.get(insn.addr, ()):
                    if kind != 'scalar' or target not in decode.helper_idents():
                        prototypes = []
                        break
                    prototypes.append(helper_prototypes()[decode.helper_idents()[target]])
            if prototypes:
                argc = max(0 if p.arguments == 'void' else len(p.arguments.split(',')) for p in prototypes)
                flags_read = 0  # The helper ABI has no arithmetic-flag input.
            else:
                argc, flags_read = 6, all_flags
            for reg in arguments[:argc]:
                reads[reg] = full
            for reg in caller_saved:
                writes[reg] = full
            flags_written = all_flags
        if (any(reads.get(reg, 0) & mask for reg, mask in zip(scratch, live[:-1])) or
                flags_read & live[-1]):
            return False
        live = tuple(mask & ~writes.get(reg, 0) for reg, mask in zip(scratch, live[:-1])) + (
            live[-1] & ~flags_written,)
        if insn.mnemonic == 'ret':
            if return_destinations is None:
                if observes_return and any(reg == 'X86_RAX' and mask for reg, mask in zip(scratch, live[:-1])):
                    return False
                continue
            destinations = return_destinations.get(addr)
            if destinations is None:
                if any(live):
                    return False
                continue
            if None in destinations and any(reg == 'X86_RAX' and mask for reg, mask in zip(scratch, live[:-1])):
                return False
        if not any(live):
            continue
        if insn.mnemonic == 'ret':
            children = tuple(target for target in destinations if target is not None)
        elif local_target is not None and return_destinations is not None:
            children = (local_target,)
        elif insn.addr in table_targets:
            children = table_targets[insn.addr]
        elif insn.mnemonic == 'jmp':
            if not decode.has_direct_branch_target(insn.operands[0]):
                return False
            children = (insn.reloc_target if insn.reloc_target is not None
                        else decode.branch_target(insn.operands[0]),)
        elif insn.mnemonic in decode.CC_AUX and insn.mnemonic.startswith('j'):
            children = (following[addr], insn.reloc_target if insn.reloc_target is not None
                        else decode.branch_target(insn.operands[0]))
        else:
            children = (following.get(addr, exit_addr),)
        for child in children:
            if child != exit_addr and child not in by_addr:
                raise ValueError('table liveness has an unknown CFG successor')
            pending.append((child, live, observes_return))
        if local_target is not None and return_destinations is None:
            # Check the actual callee and keep old masks in the continuation,
            # crediting no callee kills. Only the caller observes its return.
            pending.append((local_target, live, False))
    return True


def lower_relative_tables(insns, rodata, decode, exit_addr, function_starts):
    """Lower a table's control flow only after its temporary state is dead.

    The native image retains its instructions. Specialization may eliminate
    private table-base/result/flags definitions whose values cannot be observed
    after dispatch. Memory, other registers and the original case bodies stay.
    """
    if not any(getattr(data, 'code_relocations', ()) or getattr(data, 'absolute_code_relocations', ())
               for data in rodata.values()):
        return insns
    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    candidates = []
    bases = {}
    for position, (load, add) in enumerate(zip(insns, insns[1:])):
        if (load.mnemonic == 'lea' and load.reloc_symbol in rodata and
                getattr(rodata[load.reloc_symbol], 'code_relocations', ()) and
                load.reloc_type == 'R_X86_64_PC32' and '[rip' in load.raw.lower()):
            register = decode.reg_info(load.operands[0])
            if register is not None and register[1] == 64:
                bases[register[0]] = load
        if load.mnemonic != 'movsxd' or add.mnemonic != 'add' or not decode.is_mem(load.operands[1]):
            continue
        memory_base, index, scale, displacement = decode.parse_mem_terms(load.operands[1])
        lea = bases.get(memory_base)
        if lea is None:
            continue
        base = decode.reg_info(lea.operands[0])
        destination = decode.reg_info(load.operands[0])
        if base is None or destination is None or base[1] != 64 or destination[1] != 64:
            continue
        address_registers = [decode.reg_info(token) for token in re.findall(r'[a-z][a-z0-9]*', load.operands[1].lower())
                             if decode.reg_info(token) is not None]
        index_info = next((name for name, info in decode.REGS.items()
                           if info == (index, 64, 0)), None)
        if (any(info[1] != 64 for info in address_registers) or
                memory_base != base[0] or index_info is None or index == base[0] or scale != 2 or
                displacement != 0 or destination[0] == base[0] or
                base[0] == 'X86_RSP' or destination[0] == 'X86_RSP' or
                decode.reg_info(add.operands[0]) != destination or
                decode.reg_info(add.operands[1]) != base):
            continue
        scheduled = []
        jump = None
        for instruction in insns[position+2:]:
            if instruction.mnemonic == 'jmp':
                if decode.reg_info(instruction.operands[0]) == destination:
                    jump = instruction
                break
            if instruction.mnemonic in {'call', 'ret'} or instruction.mnemonic.startswith(('j', 'loop')):
                break
            scheduled.append(instruction)
        if jump is None:
            continue
        candidates.append(dict(window=(lea, load, add, jump), lea=lea, scheduled=tuple(scheduled), symbol=lea.reloc_symbol,
                               base=lea.symbol_offset, scratch=(base[0], destination[0]),
                               index=index_info, absolute=False, persistent=lea.end_addr != load.addr))
    persistent = {c['lea'].addr for c in candidates if c['persistent']}
    for candidate in candidates:
        if candidate['lea'].addr in persistent:
            candidate['persistent'] = True
            candidate['window'] = candidate['window'][1:]
            candidate['scratch'] = candidate['scratch'][1:]
    for lea, jump in zip(insns, insns[1:]):
        if (lea.mnemonic != 'lea' or lea.reloc_symbol not in rodata or
                not getattr(rodata[lea.reloc_symbol], 'absolute_code_relocations', ()) or
                lea.reloc_type != 'R_X86_64_PC32' or '[rip' not in lea.raw.lower() or
                jump.mnemonic != 'jmp' or len(jump.operands) != 1 or '[' not in jump.operands[0]):
            continue
        base = decode.reg_info(lea.operands[0])
        memory_base, index, scale, displacement = decode.parse_mem_terms(jump.operands[0])
        index_info = next((name for name, info in decode.REGS.items()
                           if info == (index, 64, 0)), None)
        address_registers = [decode.reg_info(token) for token in re.findall(r'[a-z][a-z0-9]*', jump.operands[0].lower())
                             if decode.reg_info(token) is not None]
        if (base is None or base[1] != 64 or base[0] == 'X86_RSP' or
                any(info[1] != 64 for info in address_registers) or
                memory_base != base[0] or index_info is None or index == base[0] or
                scale != 3 or displacement != 0):
            continue
        if lea.addr in persistent:
            raise ValueError('persistent code-table base has mixed table encodings')
        candidates.append(dict(window=(lea, jump), lea=lea, scheduled=(), symbol=lea.reloc_symbol,
                               base=lea.symbol_offset, scratch=(base[0],), index=index_info, absolute=True,
                               persistent=False))
    entries = set(function_starts)
    for insn in insns:
        target = decode.code_address(insn)
        if target in by_addr:
            entries.add(target)
        if insn.mnemonic == 'call' and insn.addr in following:
            entries.add(following[insn.addr])
        if insn.mnemonic == 'call' or insn.mnemonic == 'jmp' or insn.mnemonic in decode.CC_AUX:
            if insn.operands and decode.has_direct_branch_target(insn.operands[0]):
                entries.add(insn.reloc_target if insn.reloc_target is not None
                            else decode.branch_target(insn.operands[0]))
    table_targets = {}
    for candidate in candidates:
        base = candidate['base']
        end = min((c['base'] for c in candidates if c['symbol'] == candidate['symbol'] and c['base'] > base),
                  default=len(rodata[candidate['symbol']]))
        choices = []
        data = rodata[candidate['symbol']]
        relocations = data.absolute_code_relocations if candidate['absolute'] else data.code_relocations
        width = 8 if candidate['absolute'] else 4
        for offset, delta in relocations:
            if not base <= offset < end:
                continue
            if offset != base + width * len(choices):
                break
            target = delta if candidate['absolute'] else delta + base
            if target not in by_addr:
                raise ValueError('relative code-table target is not an instruction')
            choices.append(((offset-base)//width*4, target))
            entries.add(target)
        if not choices:
            raise ValueError('relative code table has no complete relocated entry')
        candidate['choices'] = tuple(choices)
        table_targets[candidate['window'][-1].addr] = tuple(target for _, target in choices)

    full = (1 << 64) - 1

    def captured(candidate):
        anchor = candidate['window'][0]
        lea = candidate['lea']
        calculation = candidate['window'][-2]
        index = candidate['index']
        destination = (lea.operands[0] if candidate['absolute'] else
                       candidate['window'][0 if candidate['persistent'] else 1].operands[0])
        return replace(anchor, mnemonic='mov', operands=(destination, index),
            reloc_symbol=None, reloc_type=None, reloc_target=None, symbol_offset=0,
            end_addr=calculation.end_addr, code_table=candidate['choices'],
            effects=NativeEffects(((decode.reg_info(index)[0], full),),
                ((decode.reg_info(destination)[0], full),), 0, 0))

    def dispatch(candidate):
        jump = candidate['window'][-1]
        if not candidate['absolute']:
            return jump
        base = candidate['window'][0].operands[0]
        return replace(jump, operands=(base,),
            effects=NativeEffects(((candidate['scratch'][0], full),), (), 0, 0))

    provisional = {c['window'][0].addr: captured(c) for c in candidates}
    provisional.update({c['window'][-1].addr: dispatch(c) for c in candidates})
    interiors = {i.addr for c in candidates for i in c['window'][1:-1]}
    provisional_insns = [provisional.get(i.addr, i) for i in insns if i.addr not in interiors]
    call_targets = decode.indirect_targets(provisional_insns, exit_addr, function_starts)
    # Use the existing stack/return-address analysis on the original image.
    # Unioning contexts overapproximates returns, without assuming that a RET
    # must resume at the instruction following a structural CALL.
    states, cfg_edges = {}, set()
    targets = dict(call_targets)
    targets.update({pc: frozenset(('code', target) for target in choices)
                    for pc, choices in table_targets.items()})
    decode.check_definedness(insns, targets, exit_addr, decode, incoming_states=states, cfg_edges=cfg_edges)
    rsp = list(dict.fromkeys(info[0] for info in decode.REGS.values())).index('X86_RSP')
    return_destinations = {}
    for (_, pc), state in states.items():
        if by_addr[pc].mnemonic != 'ret':
            continue
        stack = state.aliases[rsp]
        destinations = state.pointers.get(stack) if type(stack) is int else None
        if not isinstance(destinations, frozenset) or not destinations:
            return_destinations[pc] = None
        elif return_destinations.get(pc, set()) is not None:
            return_destinations.setdefault(pc, set()).update(d.target for d in destinations)

    def dead(candidate, private):
        add = candidate['window'][-2]
        if add.effects is None:
            raise ValueError('relative table lowering requires native instruction effects')
        return private_results_dead(insns, [target for _, target in candidate['choices']],
            candidate['scratch'], add.effects.flags_written, decode, exit_addr, call_targets, table_targets,
            initial=private, return_destinations=return_destinations)

    replacements, removed = {}, set()
    predecessors = {}
    for source, target in cfg_edges:
        predecessors.setdefault(target, set()).add(source)
    for candidate in candidates:
        anchor, jump = candidate['window'][0], candidate['window'][-1]
        lea = candidate['lea']
        if candidate['persistent']:
            # A syntax candidate is insufficient: every original path to the
            # load must reach this LEA before any other definition of its base.
            base = decode.reg_info(lea.operands[0])[0]
            if (any(value is None for value in return_destinations.values()) or
                    not any(pc == anchor.addr for _, pc in states)):
                raise ValueError('persistent code-table base lacks a complete native CFG')
            pending, visited = deque(predecessors.get(anchor.addr, ())), set()
            while pending:
                pc = pending.popleft()
                if pc == lea.addr or pc in visited:
                    continue
                visited.add(pc)
                if (pc == insns[0].addr or pc not in predecessors or by_addr[pc].effects is None or
                        dict(by_addr[pc].effects.writes).get(base, 0)):
                    raise ValueError('persistent code-table base has another reaching definition')
                pending.extend(predecessors[pc])
            if not private_results_dead(provisional_insns, [following[lea.addr]], (base,), 0,
                    decode, exit_addr, call_targets, table_targets, return_destinations=return_destinations):
                raise ValueError('persistent code-table base has an observable use')
            # Retain the address as a CFG entry/return destination even when
            # its now-private data definition disappears from B.
            replacements[lea.addr] = replace(lea, mnemonic='nop', operands=(),
                reloc_symbol=None, reloc_type=None, reloc_target=None, symbol_offset=0,
                effects=NativeEffects((), (), 0, 0))
        add = candidate['window'][-2]
        if entries.intersection((*(i.addr for i in candidate['window'][1:]), *(i.addr for i in candidate['scheduled']))):
            raise ValueError('relative table computation has an external CFG entry')
        if add.effects is None:
            raise ValueError('relative table lowering requires native instruction effects')
        private = (full,) * len(candidate['scratch']) + (add.effects.flags_written,)
        destination = candidate['scratch'][-1]
        for instruction in candidate['scheduled']:
            if instruction.effects is None:
                raise ValueError('relative table schedule lacks native instruction effects')
            effects = instruction.effects
            reads, writes = dict(effects.reads), dict(effects.writes)
            if (any(reads.get(reg, 0) & mask for reg, mask in zip(candidate['scratch'], private[:-1])) or
                    writes.get(destination, 0) or effects.flags_read & private[-1]):
                raise ValueError('relative table schedule observes or overwrites private results')
            # A scheduled definition kills the old private bits. Its own value
            # remains in the instruction stream and may be observed by cases.
            private = tuple(mask & ~writes.get(reg, 0)
                for reg, mask in zip(candidate['scratch'], private[:-1])) + (
                    private[-1] & ~effects.flags_written,)
        if not dead(candidate, private):
            raise ValueError('relative table computation has live register or flag results')
        replacements[anchor.addr] = captured(candidate)
        replacements[jump.addr] = dispatch(candidate)
        removed.update(i.addr for i in candidate['window'][1:-1])
    return [replacements.get(insn.addr, insn) for insn in insns if insn.addr not in removed]
