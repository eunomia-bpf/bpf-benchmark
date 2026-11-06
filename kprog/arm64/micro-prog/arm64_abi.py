"""Native ABI dependency analysis, not an instruction-value interpreter.

Concrete zero initializers cannot stand for unspecified incoming/call-clobbered
state. Track which bits are independent of that state, allowing blind private
callee saves while rejecting observations of unspecified values.
"""
from collections import deque
from dataclasses import dataclass
import re

from helper_abi import helper_idents, helper_prototypes

FULL = (1 << 64) - 1
N, Z, C, V = 1, 2, 4, 8
ALL_FLAGS = N | Z | C | V
CC_FLAGS = {'eq': Z, 'ne': Z, 'cs': C, 'hs': C, 'cc': C, 'lo': C,
            'mi': N, 'pl': N, 'vs': V, 'vc': V, 'hi': C | Z, 'ls': C | Z,
            'ge': N | V, 'lt': N | V, 'gt': N | V | Z, 'le': N | V | Z,
            'al': 0, 'nv': 0}


@dataclass
class State:
    defined: tuple[int, ...]
    aliases: tuple[int | bool | None, ...]
    flags: int
    opaque: dict[int, int]
    pointers: dict[int, int | bool | None]


def check_definedness(insns, targets, linked_exit, decode):
    def ri(operand):
        operand = operand.lower()
        if operand in {'sp', 'wsp'}:
            return 31, 32 if operand == 'wsp' else 64
        if operand in {'xzr', 'wzr'}:
            return None, 32 if operand == 'wzr' else 64
        if operand in {'q0', 'v0.16b'}: return 32, 128
        if operand in {'d0', 'v0.8b'}: return 32, 64
        if operand == 's0': return 32, 32
        if operand == 'h0': return 32, 16
        match = re.fullmatch(r'([xw])([0-9]|[12][0-9]|30)', operand)
        return (int(match[2]), 32 if match[1] == 'w' else 64) if match else None

    def raw(constant):
        if constant == 'ARM64_REG_NONE': return None
        if constant == 'ARM64_SP': return 'sp'
        return constant.removeprefix('ARM64_').lower()

    def same(a, b):
        return type(a) is type(b) and a == b

    def joined(a, b):
        opaque = {p: a.opaque.get(p, 255) & b.opaque.get(p, 255)
                  for p in a.opaque.keys() | b.opaque.keys()}
        return State(tuple(x & y for x, y in zip(a.defined, b.defined)),
                     tuple(x if same(x, y) else None for x, y in zip(a.aliases, b.aliases)),
                     a.flags & b.flags, {p: v for p, v in opaque.items() if v != 255},
                     {p: a.pointers[p] if p in a.pointers and p in b.pointers and
                      same(a.pointers[p], b.pointers[p]) else None
                      for p in a.pointers.keys() | b.pointers.keys()})

    def mask(state, operand):
        parsed = ri(operand)
        if parsed is None or parsed[0] is None:
            return (1 << (parsed[1] if parsed else 64)) - 1
        return state.defined[parsed[0]] & ((1 << parsed[1]) - 1)

    def need(state, operand, where):
        parsed = ri(operand)
        if parsed and mask(state, operand) != (1 << parsed[1]) - 1:
            raise ValueError(f'undefined native ABI register {operand} at {where}')

    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    bits, aliases = [0] * 33, [None] * 33
    for register in [0, 30, 31]: bits[register] = FULL
    aliases[0], aliases[30], aliases[31] = False, False, 0
    initial = State(tuple(bits), tuple(aliases), 0, {}, {})
    states = {((), insns[0].addr): initial}
    queue = deque(states)
    returns = {}
    entry_sp = {(): {0}}

    def push(context, addr, state):
        if addr is None:
            if context or type(state.aliases[31]) is not int or state.aliases[31] != 0:
                raise ValueError('native entry return has an unbalanced stack pointer')
            need(state, 'w7' if linked_exit else 'w0', 'native entry return')
            return
        if addr not in by_addr:
            raise ValueError(f'ABI CFG target 0x{addr:x} is not an instruction')
        key = context, addr
        old = states.get(key)
        merged = state if old is None else joined(old, state)
        if old != merged:
            states[key] = merged
            queue.append(key)

    while queue:
        context, addr = queue.popleft()
        incoming = states[context, addr]
        insn = by_addr[addr]
        op, args = insn.mnemonic, insn.operands
        where = f'0x{addr:x}: {insn.raw}'
        bits, aliases = list(incoming.defined), list(incoming.aliases)
        opaque, pointers = dict(incoming.opaque), dict(incoming.pointers)
        flags = incoming.flags

        def write(operand, value=None, pointer=False):
            parsed = ri(operand)
            if parsed is None or parsed[0] is None: return
            register, width = parsed
            if value is None: value = (1 << width) - 1
            bits[register] = value & ((1 << width) - 1)
            if register == 32:
                bits[register] |= ((1 << 128)-1) ^ ((1 << width)-1)
            elif width == 32:
                bits[register] |= FULL ^ 0xffffffff
            aliases[register] = pointer if width == 64 else False

        def address(mem):
            base, index = raw(mem.base), raw(mem.index)
            need(incoming, base, where)
            if index is not None: need(incoming, index, where)
            origin = incoming.aliases[ri(base)[0]]
            if index is not None:
                return False if origin is False else None
            offset = 0 if mem.flags & 2 else mem.offset
            return origin + offset if type(origin) is int else origin

        def load(location, width):
            if type(location) is int:
                return (sum(opaque.get(location+j, 255) << (8*j) for j in range(width//8)),
                        pointers.get(location, False) if width == 64 else False)
            return (0 if location is None and opaque else (1 << width)-1), None if location is None else False

        def store(location, width, value, pointer=False):
            if type(location) is not int:
                if value & ((1 << width)-1) != (1 << width)-1:
                    raise ValueError(f'undefined native ABI value escapes private stack at {where}')
                return
            for position in list(pointers):
                if position < location + width//8 and position + 8 > location:
                    del pointers[position]
            for index in range(width//8):
                byte = (value >> (8*index)) & 255
                if byte == 255: opaque.pop(location+index, None)
                else: opaque[location+index] = byte
            if width == 64: pointers[location] = pointer

        def condition(cc):
            required = CC_FLAGS[cc]
            if incoming.flags & required != required:
                raise ValueError(f'undefined native ABI flags at {where}')

        if op.startswith('b.'):
            condition(op.split('.')[1])
        elif op in {'csel', 'cinc', 'cinv', 'csinc', 'csinv', 'csneg', 'cneg', 'cset', 'csetm', 'ccmp'}:
            condition(args[-1])
        elif op in {'cbz', 'cbnz'}:
            need(incoming, args[0], where)
        elif op in {'tbz', 'tbnz'}:
            bit = 1 << decode.parse_imm(args[1])
            if mask(incoming, args[0]) & bit != bit:
                raise ValueError(f'undefined native ABI register {args[0]} at {where}')

        memory_index = next((i for i, arg in enumerate(args) if arg.startswith('[')), None)
        if memory_index is not None:
            mem = decode.parse_mem(args, memory_index)
            location = address(mem)
            loads = op.startswith('ld')
            pair = op in {'ldp', 'stp'}
            data = args[0] if op not in {'stxr', 'stlxr'} else args[1]
            width = ri(data)[1]
            if op.endswith('b'): width = 8
            elif op.endswith('h'): width = 16
            elif op == 'ldrsw': width = 32
            for index in range(2 if pair else 1):
                operand = args[index] if pair else data
                at = location + index*(width//8) if type(location) is int else location
                if loads:
                    value, pointer = load(at, width)
                    if op in {'ldrsb', 'ldrsh', 'ldrsw'}:
                        if value & (1 << (width-1)): value |= FULL ^ ((1 << width)-1)
                    else: value |= FULL ^ ((1 << width)-1) if width < 64 else 0
                    write(operand, value, pointer)
                else:
                    parsed = ri(operand)
                    pointer = incoming.aliases[parsed[0]] if parsed and parsed[0] is not None else False
                    store(at, width, mask(incoming, operand), pointer)
            if op in {'stxr', 'stlxr'}: write(args[0])
            if mem.flags:
                base = raw(mem.base)
                origin = incoming.aliases[ri(base)[0]]
                write(base, FULL, origin + mem.offset if type(origin) is int else origin)
        elif op == 'mov' or op == 'fmov':
            source = ri(args[1])
            pointer = incoming.aliases[source[0]] if source and source[0] is not None else False
            value = mask(incoming, args[1])
            if source and source[1] < ri(args[0])[1]: value |= FULL ^ ((1 << source[1])-1)
            write(args[0], value, pointer)
        elif op in {'adr', 'adrp', 'cset', 'csetm'}:
            write(args[0])
        elif op == 'movk':
            shift = decode.parse_imm(args[2].split()[-1]) if len(args)>2 else 0
            write(args[0], mask(incoming, args[0]) | (0xffff << shift))
        elif op in {'lsl', 'lsr', 'asr', 'ror'} and args[2].startswith('#'):
            width = ri(args[0])[1]
            count = decode.parse_imm(args[2]) & (width-1)
            value, full = mask(incoming, args[1]), (1 << width)-1
            if count:
                if op == 'lsl': value = (value << count) | ((1 << count)-1)
                elif op == 'ror': value = (value >> count) | (value << (width-count))
                else:
                    fill = full ^ ((1 << (width-count))-1)
                    value = value >> count | (fill if op == 'lsr' or value & (1 << (width-1)) else 0)
            write(args[0], value)
        elif op in {'ubfx', 'sbfx', 'ubfiz', 'bfi', 'bfxil'}:
            lsb, width = decode.parse_imm(args[2]), decode.parse_imm(args[3])
            selected = (1 << width)-1
            source = mask(incoming, args[1])
            if op in {'ubfx', 'sbfx', 'bfxil'}: source >>= lsb
            if op in {'bfi', 'ubfiz'}: source = (source & selected) << lsb; selected <<= lsb
            if op in {'bfi', 'bfxil'}: value = (mask(incoming, args[0]) & ~selected) | (source & selected)
            else:
                value = source & selected
                if op != 'sbfx' or value & (1 << (width-1)): value |= FULL ^ selected
            write(args[0], value)
        elif op in {'and', 'ands', 'orr', 'eor', 'bic', 'bics'} and args[2].startswith('#'):
            width = ri(args[0])[1]
            immediate = decode.parse_imm(args[2]) & ((1 << width)-1)
            value = mask(incoming, args[1])
            if op in {'and','ands'}: value |= ~immediate
            elif op in {'bic','bics','orr'}: value |= immediate
            write(args[0], value)
            if op in {'ands','bics'}:
                # C and V are defined zero; Z needs every result bit, N only MSB.
                flags = C | V
                if bits[ri(args[0])[0]] & (1 << (width-1)): flags |= N
                if bits[ri(args[0])[0]] & ((1 << width)-1) == (1 << width)-1: flags |= Z
        elif op in {'csel', 'csinc', 'csinv', 'csneg'}:
            need(incoming, args[1], where); need(incoming, args[2], where)
            left, right = ri(args[1]), ri(args[2])
            a = incoming.aliases[left[0]] if left and left[0] is not None else False
            b = incoming.aliases[right[0]] if right and right[0] is not None else False
            write(args[0], pointer=a if op == 'csel' and same(a,b) else False)
        elif op not in {'bl', 'blr', 'br', 'ret', 'b', 'nop'} and not op.startswith('b.') and op not in {'cbz','cbnz','tbz','tbnz'}:
            reads = args if op in {'cmp','cmn','tst','ccmp'} else args[1:]
            zero = op in {'eor','sub','subs','cmp'} and len(args)>1 and args[-1] == args[-2] and ri(args[-1])
            for operand in reads:
                if ri(operand) and not zero: need(incoming, operand, where)
            if op in {'cmp','cmn','adds','subs','ands','bics','tst','ccmp'}: flags = ALL_FLAGS
            if args and ri(args[0]) and op not in {'cmp','cmn','tst','ccmp'}:
                write(args[0])
                if op in {'add','sub'} and len(args)>2 and args[2].startswith('#'):
                    source = ri(args[1])
                    origin = incoming.aliases[source[0]] if source and source[0] is not None else False
                    delta = decode.parse_shifted_imm(args,2)
                    aliases[ri(args[0])[0]] = origin + (delta if op=='add' else -delta) if type(origin) is int else origin

        state = State(tuple(bits), tuple(aliases), flags, opaque, pointers)
        next_pc = following.get(addr)
        if op in {'bl','blr'} or (op == 'br' and any(k == 'scalar' for k,v in targets.get(addr,()))):
            choices = targets.get(addr, ())
            names = [helper_idents()[value] for kind,value in choices if kind == 'scalar']
            if decode.is_helper_symbol(insn.reloc_symbol): names.append(insn.reloc_symbol)
            if insn.reloc_symbol and not names:
                raise ValueError(f'unresolved native ABI external call {insn.reloc_symbol} at {where}')
            for name in names:
                parameters = helper_prototypes()[name].arguments
                for index, parameter in enumerate([] if parameters=='void' else parameters.split(',')):
                    if parameter.strip() == '...': break
                    narrow = '*' not in parameter and any(t in parameter.split() for t in ('__u32','__s32','int'))
                    need(incoming, ('w' if narrow else 'x')+str(index), where)
            if names:
                for register in range(19): bits[register], aliases[register] = 0, None
                bits[32], aliases[32] = 0, None
                bits[0], aliases[0] = FULL, False
                if op != 'br':
                    bits[30], aliases[30] = FULL, False
                    push(context, next_pc, State(tuple(bits),tuple(aliases),0,opaque,pointers))
                else:
                    if type(state.aliases[31]) is not int or state.aliases[31] not in entry_sp[context]:
                        raise ValueError(f'native ABI tail return has an unbalanced stack pointer at {where}')
                    need(state,'x30',where)
                    result = State(tuple(bits),tuple(aliases),0,opaque,pointers)
                    if context:
                        for parent, continuation in returns.get(context,set()): push(parent,continuation,result)
                    else: need(result,'w0',where)
            code = [value for kind,value in choices if kind == 'code']
            if op == 'bl' and not names: code = [decode.branch_target(args[0])]
            for target in code:
                bits, aliases = list(state.defined), list(state.aliases)
                bits[30], aliases[30] = FULL, False
                child = context+(addr,) if addr not in context else context[:context.index(addr)+1]
                if type(state.aliases[31]) is not int:
                    raise ValueError(f'native call stack relation unresolved at {where}')
                entry_sp.setdefault(child,set()).add(state.aliases[31])
                edge = context, next_pc
                if edge not in returns.setdefault(child,set()):
                    returns[child].add(edge)
                    queue.extend(key for key in states if key[0]==child and by_addr[key[1]].mnemonic=='ret')
                push(child,target,State(tuple(bits),tuple(aliases),flags,opaque,pointers))
        elif op == 'ret':
            if type(state.aliases[31]) is not int or state.aliases[31] not in entry_sp[context]:
                raise ValueError(f'native ABI return has an unbalanced stack pointer at {where}')
            need(state, args[0] if args else 'x30', where)
            if context:
                for parent, continuation in returns.get(context,set()): push(parent, continuation, state)
            else: need(state,'w0',where)
        elif op == 'br':
            need(state,args[0],where)
            for kind,target in targets.get(addr,()):
                if kind == 'code': push(context,target,state)
        elif op == 'b': push(context,decode.branch_target(args[0]),state)
        else:
            if op.startswith('b.') or op in {'cbz','cbnz','tbz','tbnz'}:
                push(context,decode.branch_target(args[-1]),state)
            push(context,next_pc,state)
