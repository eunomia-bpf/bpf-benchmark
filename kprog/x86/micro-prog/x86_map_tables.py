"""Specialize immutable map-pointer selections using existing capability ops."""
from dataclasses import replace
import re
from x86_relative_tables import NativeEffects, private_results_dead


def lower_map_tables(insns, rodata, decode, exit_addr, function_starts, source_pointers):
    if not any(getattr(data, 'map_relocations', ()) for data in rodata.values()):
        return insns
    full = (1 << 64) - 1
    by_addr = {insn.addr: insn for insn in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    entries = set(function_starts)
    targets = decode.indirect_targets(insns, exit_addr, function_starts)
    table_targets = {i.addr: tuple(target for kind, target in targets.get(i.addr, ()) if kind == 'code')
                     for i in insns if i.mnemonic == 'jmp' and decode.is_indirect_branch(i)}
    for insn in insns:
        address = decode.code_address(insn)
        if address in by_addr:
            entries.add(address)
        if insn.mnemonic == 'call' and insn.addr in following:
            entries.add(following[insn.addr])
        if insn.operands and (insn.mnemonic in {'call', 'jmp'} or insn.mnemonic in decode.CC_AUX):
            if decode.has_direct_branch_target(insn.operands[0]):
                entries.add(insn.reloc_target if insn.reloc_target is not None else decode.branch_target(insn.operands[0]))
        entries.update(target for kind, target in targets.get(insn.addr, ()) if kind == 'code')
    candidates = []
    for lea, load in zip(insns, insns[1:]):
        data = rodata.get(lea.reloc_symbol)
        if (lea.mnemonic != 'lea' or data is None or not getattr(data, 'map_relocations', ()) or
                lea.reloc_type != 'R_X86_64_PC32' or '[rip' not in lea.raw.lower() or
                load.mnemonic != 'mov' or len(load.operands) != 2 or not decode.is_mem(load.operands[1]) or
                ':' in load.operands[1]):
            continue
        base, dst = decode.reg_info(lea.operands[0]), decode.reg_info(load.operands[0])
        if base is None or dst is None or base[1:] != (64, 0) or dst[1:] != (64, 0):
            continue
        memory_base, index, scale, displacement = decode.parse_mem_terms(load.operands[1])
        address_regs = [decode.reg_info(token) for token in re.findall(r'[a-z][a-z0-9]*', load.operands[1].lower())
                        if decode.reg_info(token) is not None]
        if (memory_base != base[0] or index in {'X86_REG_NONE', base[0]} or scale != 3 or
                decode.operand_width(load.operands[1]) != 64 or any(info[1] != 64 for info in address_regs) or
                'X86_RSP' in {base[0], dst[0]}):
            continue
        if load.addr in entries:
            raise ValueError('map table computation has an external CFG entry')
        candidates.append(dict(lea=lea, load=load, base=base[0], dst=dst[0], index=index,
                               symbol=lea.reloc_symbol, offset=lea.symbol_offset+displacement))
    replacements, removed = {}, set()
    for candidate in candidates:
        lea, load = candidate['lea'], candidate['load']
        data, start = rodata[candidate['symbol']], candidate['offset']
        end = min((c['offset'] for c in candidates if c['symbol'] == candidate['symbol'] and c['offset'] > start),
                  default=len(data))
        if start < 0 or start >= end:
            raise ValueError('map table base exceeds its immutable object')
        relocations = dict(data.map_relocations)
        choices = []
        for offset in range(start, end-7, 8):
            if any(at < offset+8 and at+8 > offset and at != offset for at in relocations):
                raise ValueError('map table load observes only part of a relocated pointer')
            if offset in relocations:
                symbol = relocations[offset]
                if symbol not in source_pointers:
                    raise ValueError('map table lacks actual source capability: '+symbol)
                value = source_pointers[symbol]
            else:
                value = int.from_bytes(data[offset:offset+8], 'little')
            choices.append((offset-start, value))
        if not choices:
            raise ValueError('map table has no complete pointer entry')
        scratch = () if candidate['base'] == candidate['dst'] else (candidate['base'],)
        if not private_results_dead(insns, [following.get(load.addr, exit_addr)], scratch, 0,
                                    decode, exit_addr, targets, table_targets):
            raise ValueError('map table computation has a live private address result')
        dst = load.operands[0]
        index = next(name for name, info in decode.REGS.items() if info == (candidate['index'], 64, 0))
        replacements[lea.addr] = replace(lea, mnemonic='mov', operands=(dst, index),
            reloc_symbol=None, reloc_type=None, reloc_target=None, symbol_offset=0,
            end_addr=load.end_addr, map_table=tuple(choices),
            effects=NativeEffects(((candidate['index'], full),), ((candidate['dst'], full),), 0, 0))
        removed.add(load.addr)
    return [replacements.get(insn.addr, insn) for insn in insns if insn.addr not in removed]
