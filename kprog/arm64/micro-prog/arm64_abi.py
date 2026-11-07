"""Native ABI dependency analysis, not an instruction-value interpreter.

Concrete zero initializers cannot stand for unspecified incoming/call-clobbered
state. Track which bits are independent of that state, allowing blind private
callee saves while rejecting observations of unspecified values.
"""
from collections import deque
from dataclasses import dataclass
import re

from helper_abi import HELPER_COPY_SOURCES, HELPER_FULL_WRITES, helper_idents, helper_prototypes

FULL = (1 << 64) - 1
N, Z, C, V = 1, 2, 4, 8
ALL_FLAGS = N | Z | C | V
CC_FLAGS = {'eq': Z, 'ne': Z, 'cs': C, 'hs': C, 'cc': C, 'lo': C,
            'mi': N, 'pl': N, 'vs': V, 'vc': V, 'hi': C | Z, 'ls': C | Z,
            'ge': N | V, 'lt': N | V, 'gt': N | V | Z, 'le': N | V | Z,
            'al': 0, 'nv': 0}


@dataclass(frozen=True)
class PointerAlternatives:
    # False (external memory) and stack offset0 must remain distinct.
    offsets: frozenset[int]
    external: bool


@dataclass
class State:
    defined: tuple[int, ...]
    aliases: tuple[int | bool | PointerAlternatives | None, ...]
    flags: int
    opaque: dict[int, int]
    pointers: dict[int, int | bool | PointerAlternatives | None]
    constants: tuple[int | None, ...]
    ghost: tuple[bool, ...]
    ghost_memory: frozenset[int]
    maxima: tuple[int | None, ...]


def check_definedness(insns, targets, linked_exit, decode):
    def ri(operand):
        operand = operand.lower()
        if operand in {'sp', 'wsp'}:
            return 31, 32 if operand == 'wsp' else 64
        if operand in {'xzr', 'wzr'}:
            return None, 32 if operand == 'wzr' else 64
        vector = re.fullmatch(r'([qdshb])([0-9]|[12][0-9]|3[01])', operand)
        if vector: return 32 + int(vector[2]), {'q':128, 'd':64, 's':32, 'h':16, 'b':8}[vector[1]]
        vector = re.fullmatch(r'v([0-9]|[12][0-9]|3[01])\.(8b|16b)', operand)
        if vector: return 32 + int(vector[1]), 64 if vector[2] == '8b' else 128
        match = re.fullmatch(r'([xw])([0-9]|[12][0-9]|30)', operand)
        return (int(match[2]), 32 if match[1] == 'w' else 64) if match else None

    def raw(constant):
        if constant == 'ARM64_REG_NONE': return None
        if constant == 'ARM64_SP': return 'sp'
        return constant.removeprefix('ARM64_').lower()

    def same(a, b):
        return type(a) is type(b) and a == b

    def joined_pointer(a, b):
        if same(a, b): return a
        if a is None or b is None: return None
        def alternatives(value):
            if isinstance(value, PointerAlternatives): return value
            if type(value) is int: return PointerAlternatives(frozenset({value}), False)
            if value is False: return PointerAlternatives(frozenset(), True)
            return None
        left, right = alternatives(a), alternatives(b)
        if left is None or right is None: return None
        return PointerAlternatives(left.offsets | right.offsets, left.external or right.external)

    def memory_offset(value, offset):
        if isinstance(value, PointerAlternatives):
            return PointerAlternatives(frozenset(p+offset for p in value.offsets), value.external)
        return value+offset if type(value) is int else value

    def shifted_pointer(value, offset):
        if type(value) is int: return value + offset
        # Widen arithmetic on a joined pointer instead of growing loop offsets.
        return None if offset and isinstance(value, PointerAlternatives) else value

    def joined(a, b):
        opaque = {p: a.opaque.get(p, 255) & b.opaque.get(p, 255)
                  for p in a.opaque.keys() | b.opaque.keys()}
        return State(tuple(x & y for x, y in zip(a.defined, b.defined)),
                     tuple(joined_pointer(x, y) for x, y in zip(a.aliases, b.aliases)),
                     a.flags & b.flags, {p: v for p, v in opaque.items() if v != 255},
                     {p: joined_pointer(a.pointers.get(p), b.pointers.get(p))
                      for p in a.pointers.keys() | b.pointers.keys()},
                     tuple(x if x == y else None for x,y in zip(a.constants,b.constants)),
                     tuple(x or y for x,y in zip(a.ghost,b.ghost)), a.ghost_memory | b.ghost_memory,
                     tuple(max(x,y) if x is not None and y is not None else None for x,y in zip(a.maxima,b.maxima)))

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
    bits, aliases = [0] * 64, [None] * 64
    for register in [0, 30, 31]: bits[register] = FULL
    aliases[0], aliases[30], aliases[31] = False, False, 0
    initial = State(tuple(bits), tuple(aliases), 0, {}, {}, (None,)*64, tuple(i in {30,31} for i in range(64)), frozenset(), (None,)*64)
    states = {((), insns[0].addr): initial}
    queue = deque(states)
    returns = {}
    entry_sp = {(): {0}}
    stack_min = stack_max = 0
    payload_slots = set()
    layout_unknown = False

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
        constants = list(incoming.constants)
        maxima = list(incoming.maxima)
        ghost = list(incoming.ghost)
        ghost_memory = set(incoming.ghost_memory)

        no_pointer = object()
        def write(operand, value=None, pointer=no_pointer, constant=None, may_payload=None):
            parsed = ri(operand)
            if parsed is None or parsed[0] is None: return
            register, width = parsed
            if value is None: value = (1 << width) - 1
            bits[register] = value & ((1 << width) - 1)
            if register >= 32:
                bits[register] |= ((1 << 128)-1) ^ ((1 << width)-1)
            elif width == 32:
                bits[register] |= FULL ^ 0xffffffff
            if pointer is no_pointer:
                pointer = None if isinstance(incoming.aliases[register], PointerAlternatives) and constant is None else False
            aliases[register] = pointer if width == 64 else False
            constants[register] = constant & ((1 << width)-1) if constant is not None else None
            maxima[register] = constants[register]
            ghost[register] = (any(incoming.ghost[q[0]] for arg in args[1:] if (q := ri(arg)) and q[0] is not None) if may_payload is None else may_payload) if width == 64 else False

        def address(mem):
            base, index = raw(mem.base), raw(mem.index)
            need(incoming, base, where)
            if index is not None: need(incoming, index, where)
            origin = incoming.aliases[ri(base)[0]]
            if index is not None:
                return False if origin is False else None
            offset = 0 if mem.flags & 2 else mem.offset
            location = memory_offset(origin, offset)
            return location

        def load(location, width):
            if type(location) is int:
                return (sum(opaque.get(location+j, 255) << (8*j) for j in range(width//8)),
                        pointers.get(location, False) if width == 64 else False)
            if isinstance(location, PointerAlternatives):
                choices = [load(offset, width) for offset in location.offsets]
                if location.external: choices.append(((1 << width)-1, False))
                if not choices: return 0, None
                value, pointer = choices[0]
                for other, alias in choices[1:]:
                    value &= other
                    pointer = joined_pointer(pointer, alias)
                return value, pointer
            return (0 if location is None and opaque else (1 << width)-1), None if location is None else False

        def store(location, width, value, pointer=False, may_payload=True):
            nonlocal layout_unknown
            if width == 64 and may_payload:
                base_register = ri(raw(mem.base))[0]
                if location is False and incoming.ghost[base_register]:
                    location = None
                destinations = location.offsets if isinstance(location, PointerAlternatives) else {location} if type(location) is int else set()
                if location is None:
                    layout_unknown = True
                for destination in destinations:
                    if destination % 8 == 0:
                        payload_slots.add(destination)
                        ghost_memory.add(destination)
            if isinstance(location, PointerAlternatives):
                if location.external and value & ((1 << width)-1) != (1 << width)-1:
                    raise ValueError(f'undefined native ABI value escapes private stack at {where}')
                for target in location.offsets:
                    for position in list(pointers):
                        if position < target + width//8 and position + 8 > target:
                            pointers[position] = None
                    for index in range(width//8):
                        byte = opaque.get(target+index, 255) & ((value >> (8*index)) & 255)
                        if byte != 255: opaque[target+index] = byte
                return
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
            if op in {'stxr', 'stlxr'}:
                status, source = ri(args[0])[0], ri(args[1])[0]
                base = ri(raw(mem.base))[0]
                if status == source or (mem.base != 'ARM64_SP' and status == base):
                    raise ValueError(f'constrained-unpredictable native exclusive status register overlap at {where}')
            # LDPOVERLAP permits UNDEF/NOP as well as unknown data. A later
            # overwrite does not make the native instruction safe to admit.
            if op == 'ldp' and args[0] == args[1]:
                raise ValueError(f'constrained-unpredictable native LDP destination overlap at {where}')
            # GPR base/data overlap with writeback can also decode as UNDEF.
            # SP and ZR share an encoding number but are distinct registers.
            if mem.flags and mem.base != 'ARM64_SP':
                base = ri(raw(mem.base))[0]
                data = args[:2] if op in {'ldp', 'stp'} else args[:1]
                if any(ri(operand)[0] == base for operand in data):
                    raise ValueError(f'constrained-unpredictable native writeback/base register overlap at {where}')
            # Kernel entry SP is 16-byte aligned and SCTLR_EL1.SA is enabled.
            # CheckSPAlignment uses the old SP, before address/writeback.
            if mem.base == 'ARM64_SP':
                sp = incoming.aliases[31]
                if type(sp) is not int:
                    raise ValueError(f'native SP alignment unresolved at {where}')
                if sp % 16:
                    raise ValueError(f'native SP alignment fault at {where}')
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
                at = memory_offset(location, index*(width//8))
                if loads:
                    value, pointer = load(at, width)
                    if op in {'ldrsb', 'ldrsh', 'ldrsw'}:
                        if value & (1 << (width-1)): value |= FULL ^ ((1 << width)-1)
                    else: value |= FULL ^ ((1 << width)-1) if width < 64 else 0
                    base_register = ri(raw(mem.base))[0]
                    if at is False and incoming.ghost[base_register]:
                        at = None
                    if width != 64 or at is False:
                        may_payload = False
                    elif type(at) is int:
                        may_payload = at in incoming.ghost_memory
                    elif isinstance(at, PointerAlternatives):
                        may_payload = any(p in incoming.ghost_memory for p in at.offsets)
                    else:
                        may_payload = True
                    write(operand, value, pointer, may_payload=may_payload)
                else:
                    parsed = ri(operand)
                    pointer = incoming.aliases[parsed[0]] if parsed and parsed[0] is not None else False
                    store(at, width, mask(incoming, operand), pointer, incoming.ghost[parsed[0]] if parsed and parsed[0] is not None else False)
            if op in {'stxr', 'stlxr'}: write(args[0])
            if mem.flags:
                base = raw(mem.base)
                origin = incoming.aliases[ri(base)[0]]
                write(base, FULL, shifted_pointer(origin, mem.offset), may_payload=incoming.ghost[ri(base)[0]])
        elif op == 'mov' or op == 'fmov':
            source = ri(args[1])
            pointer = incoming.aliases[source[0]] if source and source[0] is not None else False
            value = mask(incoming, args[1])
            if source and source[1] < ri(args[0])[1]: value |= FULL ^ ((1 << source[1])-1)
            literal = (decode.parse_shifted_imm(args,1) if args[1].startswith('#') else
                       incoming.constants[source[0]] if source and source[0] is not None else
                       0 if args[1] in {'xzr','wzr'} else None)
            write(args[0], value, pointer, literal, incoming.ghost[source[0]] if source and source[0] is not None else False)
            if ri(args[0])[0] is not None and source and source[0] is not None and incoming.maxima[source[0]] is not None:
                maxima[ri(args[0])[0]] = min(incoming.maxima[source[0]], (1 << ri(args[0])[1])-1)
        elif op in {'adr', 'adrp', 'cset', 'csetm'}:
            write(args[0], pointer=False, may_payload=False)
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
            source = ri(args[1])
            origin = incoming.aliases[source[0]] if source and source[0] is not None else False
            pointer = None if isinstance(origin, PointerAlternatives) else False
            if op == 'orr' and width == 64 and immediate < 16:
                pointer = origin | immediate if type(origin) is int else None if isinstance(origin, PointerAlternatives) else origin
            write(args[0], value, pointer)
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
            write(args[0], pointer=joined_pointer(a, b) if op == 'csel' else None)
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
                    aliases[ri(args[0])[0]] = shifted_pointer(origin, delta if op=='add' else -delta) if ri(args[0])[1] == 64 else False

        if type(aliases[31]) is int:
            stack_min = min(stack_min, aliases[31])
            stack_max = max(stack_max, aliases[31])
        state = State(tuple(bits), tuple(aliases), flags, opaque, pointers, tuple(constants), tuple(ghost), frozenset(ghost_memory),tuple(maxima))
        next_pc = following.get(addr)
        if op in {'bl','blr'} or (op == 'br' and any(k == 'scalar' for k,v in targets.get(addr,()))):
            choices = targets.get(addr, ())
            names = [helper_idents()[value] for kind,value in choices if kind == 'scalar']
            if decode.is_helper_symbol(insn.reloc_symbol): names.append(insn.reloc_symbol)
            if insn.reloc_symbol in {'memcpy','memset'}: names.append(insn.reloc_symbol)
            if insn.reloc_symbol and not names:
                raise ValueError(f'unresolved native ABI external call {insn.reloc_symbol} at {where}')
            for name in names:
                if name in {'memcpy','memset'}:
                    for reg in ['x0','x2','x1' if name=='memcpy' else 'w1']: need(incoming,reg,where)
                    continue
                parameters = helper_prototypes()[name].arguments
                for index, parameter in enumerate([] if parameters=='void' else parameters.split(',')):
                    if parameter.strip() == '...': break
                    narrow = '*' not in parameter and any(t in parameter.split() for t in ('__u32','__s32','int'))
                    need(incoming, ('w' if narrow else 'x')+str(index), where)
            if names:
                effects=[]
                for name in names:
                    written,saved=dict(state.opaque),dict(state.pointers)
                    effect=(0,2) if name in {'memcpy','memset'} else HELPER_FULL_WRITES.get(name)
                    if effect is not None:
                        dst,size=effect
                        start,length=incoming.aliases[dst],incoming.constants[size]
                        if type(start) is int and length is not None:
                            if name not in {'memcpy','memset'}: length &= 0xffffffff
                            end=start+length
                            written={p:v for p,v in written.items() if not start<=p<end}
                            saved={p:v for p,v in saved.items() if not (p<end and p+8>start)}
                            source_arg=1 if name=='memcpy' else HELPER_COPY_SOURCES.get(name)
                            if source_arg is not None:
                                source=incoming.aliases[source_arg]
                                if source is None:
                                    raise ValueError(f'native helper source stack relation unresolved at {where}')
                                origins = source.offsets if isinstance(source, PointerAlternatives) else {source} if type(source) is int else set()
                                for origin in origins:
                                    for position, value in state.opaque.items():
                                        if origin <= position < origin+length:
                                            target = start+position-origin
                                            written[target] = written.get(target, 255) & value
                                if len(origins) == 1 and not (isinstance(source, PointerAlternatives) and source.external):
                                    origin = next(iter(origins))
                                    saved.update({start+p-origin:v for p,v in state.pointers.items() if origin<=p and p+8<=origin+length})
                                elif origins:
                                    for position in range(max(0, length-7)): saved[start+position] = None
                    # Helper copies may transport private pointer tags. Unknown
                    # destinations/lengths retain the complete ghost layout.
                    source_arg = 1 if name == 'memcpy' else HELPER_COPY_SOURCES.get(name)
                    if effect is not None and source_arg is not None:
                        dst,size = effect
                        start,length = incoming.aliases[dst],incoming.maxima[size]
                        source = incoming.aliases[source_arg]
                        origins = source.offsets if isinstance(source,PointerAlternatives) else {source} if type(source) is int else set()
                        if ((source is None or source is False) and incoming.ghost[source_arg]) or (origins and (type(start) is not int or length is None)):
                            layout_unknown = True
                        elif origins and length is not None:
                            for origin in origins:
                                for position in incoming.ghost_memory:
                                    if origin <= position and position+8 <= origin+length:
                                        destination = start+position-origin
                                        if destination % 8 == 0:
                                            payload_slots.add(destination)
                                            ghost_memory.add(destination)
                    effects.append(State(state.defined,state.aliases,state.flags,written,saved,state.constants,state.ghost,frozenset(ghost_memory),state.maxima))
                effect=effects[0]
                for branch in effects[1:]: effect=joined(effect,branch)
                opaque,pointers=effect.opaque,effect.pointers
                for register in range(19):
                    bits[register], aliases[register], constants[register] = 0, None, None
                    ghost[register] = False
                    maxima[register] = None
                for register in range(32,64):
                    bits[register], aliases[register], constants[register] = 0, None, None
                    ghost[register] = False
                    maxima[register] = None
                bits[0], aliases[0] = FULL, False
                ghost[0] = False
                maxima[0] = None
                if len(names)==1 and names[0] in {'memcpy','memset'}:
                    aliases[0]=incoming.aliases[0]
                    ghost[0]=incoming.ghost[0]
                if op != 'br':
                    bits[30], aliases[30] = FULL, False
                    ghost[30] = False
                    maxima[30] = None
                    constants[30]=None
                    push(context, next_pc, State(tuple(bits),tuple(aliases),0,opaque,pointers,tuple(constants),tuple(ghost),frozenset(ghost_memory),tuple(maxima)))
                else:
                    if type(state.aliases[31]) is not int or state.aliases[31] not in entry_sp[context]:
                        raise ValueError(f'native ABI tail return has an unbalanced stack pointer at {where}')
                    need(state,'x30',where)
                    result = State(tuple(bits),tuple(aliases),0,opaque,pointers,tuple(constants),tuple(ghost),frozenset(ghost_memory),tuple(maxima))
                    if context:
                        for parent, continuation in returns.get(context,set()): push(parent,continuation,result)
                    else: need(result,'w0',where)
            code = [value for kind,value in choices if kind == 'code']
            if op == 'bl' and not names: code = [decode.branch_target(args[0])]
            for target in code:
                bits, aliases = list(state.defined), list(state.aliases)
                ghost = list(state.ghost)
                bits[30], aliases[30] = FULL, False
                ghost[30] = False
                maxima[30] = None
                child = context+(addr,) if addr not in context else context[:context.index(addr)+1]
                if type(state.aliases[31]) is not int:
                    raise ValueError(f'native call stack relation unresolved at {where}')
                entry_sp.setdefault(child,set()).add(state.aliases[31])
                edge = context, next_pc
                if edge not in returns.setdefault(child,set()):
                    returns[child].add(edge)
                    queue.extend(key for key in states if key[0]==child and by_addr[key[1]].mnemonic=='ret')
                push(child,target,State(tuple(bits),tuple(aliases),flags,opaque,pointers,state.constants,tuple(ghost),frozenset(ghost_memory),tuple(maxima)))
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
    return stack_min, stack_max, None if layout_unknown else sorted(payload_slots)
