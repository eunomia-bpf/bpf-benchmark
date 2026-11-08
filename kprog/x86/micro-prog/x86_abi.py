"""Check native ABI definedness before specializing concrete initializer values.

This is a read/write-effect analysis, not another ISA value interpreter. Native
instruction values/flags remain implemented by the C simulator and its contracts.
"""
from collections import deque
from dataclasses import dataclass

from helper_abi import HELPER_COPY_SOURCES, HELPER_FULL_WRITES, helper_idents, helper_prototypes

FULL = (1 << 64) - 1
CF, ZF, SF, OF, PF, AF = 1, 2, 4, 8, 16, 32
ALL_FLAGS = CF | ZF | SF | OF | PF | AF
CC_FLAGS = {'A': CF | ZF, 'AE': CF, 'B': CF, 'BE': CF | ZF,
            'E': ZF, 'NE': ZF, 'G': ZF | SF | OF, 'GE': SF | OF,
            'L': SF | OF, 'LE': ZF | SF | OF, 'S': SF, 'NS': SF,
            'O': OF, 'NO': OF, 'P': PF, 'NP': PF}
CALLER_SAVED = ('rax', 'rcx', 'rdx', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11')


@dataclass(frozen=True)
class ReturnAddress:
    context: tuple[int, ...]
    target: int | None


@dataclass(frozen=True)
class PointerAlternatives:
    # Keep external pointers distinct from stack offset0 (False == 0 in Python).
    offsets: frozenset[int]
    external: bool


@dataclass
class State:
    defined: tuple[int, ...]
    aliases: tuple[int | bool | frozenset[ReturnAddress] | PointerAlternatives | None, ...]
    flags: int
    # Only bytes depending on unspecified ABI values need entries. Other raw
    # stack initialization remains the actual BPF verifier's responsibility.
    opaque: dict[int, int]
    pointers: dict[int, int | bool | frozenset[ReturnAddress] | PointerAlternatives | None]
    constants: tuple[int | None, ...]


def check_definedness(insns, targets, exit_addr, decode, return_sites=None):
    regs = (*dict.fromkeys(r[0] for r in decode.REGS.values()), 'X86_XMM0')
    index = {reg: i for i, reg in enumerate(regs)}
    def ri(operand):
        if operand.lower() == 'xmm0':
            return index['X86_XMM0'], 128, 0
        parsed = decode.reg_info(operand)
        return (index[parsed[0]], parsed[1], parsed[2]) if parsed else None
    rsp, rax = ri('rsp')[0], ri('rax')[0]
    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    defined = [0] * len(regs)
    aliases = [None] * len(regs)
    defined[ri('rdi')[0]] = defined[rsp] = FULL
    aliases[ri('rdi')[0]], aliases[rsp] = False, 0
    outer_return = frozenset({ReturnAddress((),None)})
    initial = State(tuple(defined), tuple(aliases), 0, {}, {0:outer_return}, (None,)*len(regs))
    states = {((), insns[0].addr): initial}
    queue = deque(states)
    lowest_stack = 0
    # Call-string contexts retain opaque callee saves from distinct callers.
    # Repeated call sites join to a finite context, never a runtime depth limit.

    def same(a, b):
        return type(a) is type(b) and a == b

    def joined_pointer(a,b):
        if isinstance(a,frozenset) and isinstance(b,frozenset):
            return a | b
        if same(a,b): return a
        if a is None or b is None: return None
        def alternatives(value):
            if isinstance(value,PointerAlternatives): return value
            if type(value) is int: return PointerAlternatives(frozenset({value}),False)
            if value is False: return PointerAlternatives(frozenset(),True)
            return None
        left,right=alternatives(a),alternatives(b)
        if left is not None and right is not None:
            return PointerAlternatives(left.offsets | right.offsets,left.external or right.external)
        return None

    def offset_pointer(value, displacement):
        if type(value) is int:
            return value + displacement
        if isinstance(value, PointerAlternatives):
            return PointerAlternatives(
                frozenset(offset + displacement for offset in value.offsets),
                value.external)
        return value

    def joined(a, b):
        opaque = {p: a.opaque.get(p, 255) & b.opaque.get(p, 255)
                  for p in a.opaque.keys() | b.opaque.keys()}
        opaque = {p: v for p, v in opaque.items() if v != 255}
        pointers = {p: joined_pointer(a.pointers.get(p, False), b.pointers.get(p, False))
                    for p in a.pointers.keys() | b.pointers.keys()}
        return State(tuple(x & y for x, y in zip(a.defined, b.defined)),
                     tuple(joined_pointer(x,y) for x,y in zip(a.aliases,b.aliases)),
                     a.flags & b.flags, opaque, pointers,
                     tuple(x if x == y else None for x,y in zip(a.constants,b.constants)))

    def push(context, addr, state):
        nonlocal lowest_stack
        if type(state.aliases[rsp]) is int:
            lowest_stack = min(lowest_stack,state.aliases[rsp])
        if addr == exit_addr:
            if context or type(state.aliases[rsp]) is not int or state.aliases[rsp] != 0:
                raise ValueError('native entry return has an unbalanced stack pointer')
            if state.pointers.get(0) != outer_return:
                raise ValueError('native entry return address was overwritten')
            need(state, 'eax', 'native entry return')
            return
        if addr not in by_addr:
            raise ValueError(f'ABI CFG target 0x{addr:x} is not an instruction')
        key = context, addr
        old = states.get(key)
        merged = state if old is None else joined(old, state)
        if old != merged:
            states[key] = merged
            queue.append(key)

    def mask(state, operand):
        parsed = ri(operand)
        if parsed is None:
            return FULL
        reg, width, shift = parsed
        return (state.defined[reg] >> shift) & ((1 << width) - 1)

    def need(state, operand, reason):
        parsed = ri(operand)
        if parsed and mask(state, operand) != (1 << parsed[1]) - 1:
            raise ValueError(f'undefined native ABI register {operand} at {reason}')

    def flags_needed(state, op, where):
        condition = decode.CC_AUX[op].removeprefix('X86_CC_')
        required = CC_FLAGS[condition]
        if state.flags & required != required:
            raise ValueError(f'undefined native ABI flags at {where}')

    while queue:
        context, addr = queue.popleft()
        incoming = states[context, addr]
        insn = by_addr[addr]
        op, args = insn.mnemonic, insn.operands
        where = f'0x{addr:x}: {insn.raw}'
        bits, alias = list(incoming.defined), list(incoming.aliases)
        opaque, pointers = dict(incoming.opaque), dict(incoming.pointers)
        flags = incoming.flags
        constants = list(incoming.constants)

        def shift_count(operand, width):
            if decode.is_int(operand):
                value = decode.parse_int(operand)
            else:
                reg = ri(operand)
                value = incoming.constants[reg[0]] if reg else None
                if value is not None:
                    value >>= reg[2]
            return None if value is None else value & (63 if width == 64 else 31)

        no_pointer=object()
        def write(operand, value=None, pointer=no_pointer, constant=None):
            parsed = ri(operand)
            if parsed is None:
                return
            reg, width, shift = parsed
            if value is None: value = (1 << width)-1
            lane = ((1 << width) - 1) << shift
            bits[reg] = (bits[reg] & ~lane) | ((value << shift) & lane)
            if width == 32:
                bits[reg] |= FULL ^ 0xffffffff
            if pointer is no_pointer:
                pointer=None if isinstance(incoming.aliases[reg],PointerAlternatives) and constant is None else False
            alias[reg] = pointer if width == 64 else None if isinstance(incoming.aliases[reg],PointerAlternatives) else False
            if constant is not None:
                constant = (constant << shift) & lane
                constants[reg] = (constant if width in {32,64,128} else
                                  ((constants[reg] & ~lane) | constant) if constants[reg] is not None else None)
            else: constants[reg] = None

        def address(operand):
            base, ix, scale, disp = decode.parse_mem_terms(operand)
            if disp >= 1 << 63: disp -= 1 << 64
            for reg in (base, ix):
                if reg != 'X86_REG_NONE':
                    need(incoming, regs[index[reg]].removeprefix('X86_').lower(), where)
            if ix != 'X86_REG_NONE':
                iv = incoming.constants[index[ix]]
                if base != 'X86_REG_NONE' and (type(alias[index[base]]) is int or
                                               isinstance(alias[index[base]], PointerAlternatives)):
                    return offset_pointer(alias[index[base]], (iv << scale) + disp) if iv is not None else None
                return False if base == 'X86_REG_NONE' or alias[index[base]] is False else None
            if base == 'X86_REG_NONE':
                return False
            origin = alias[index[base]]
            return offset_pointer(origin, disp)

        def read_alias(location, width):
            if type(location) is int:
                value = sum(opaque.get(location + j, 255) << (8*j) for j in range(width//8))
                return value, pointers.get(location, False) if width == 64 else False
            if isinstance(location,PointerAlternatives):
                choices=[read_alias(offset,width) for offset in location.offsets]
                if location.external: choices.append(((1 << width)-1,False))
                if not choices: return 0,None
                value,pointer=choices[0]
                for bits,next_pointer in choices[1:]:
                    value &= bits;pointer=joined_pointer(pointer,next_pointer)
                return value,pointer
            if location is None:
                return 0, None
            return (1 << width) - 1, False

        def read_memory(operand, width):
            return read_alias(address(operand),width)

        def store(operand, width, value=FULL, pointer=False):
            location = address(operand)
            if isinstance(location,PointerAlternatives):
                full=(1 << width)-1
                if location.external and value & full != full:
                    raise ValueError(f'undefined native ABI value escapes private stack at {where}')
                # A write through a joined alias may leave every other candidate
                # unchanged. Never clear old taint or promise one stored pointer.
                for target in location.offsets:
                    for p in list(pointers):
                        if p < target + width//8 and p + 8 > target:
                            pointers[p]=None
                    for j in range(width//8):
                        byte=opaque.get(target+j,255) & ((value >> (8*j)) & 255)
                        if byte!=255: opaque[target+j]=byte
                return
            if type(location) is not int:
                if value & ((1 << width)-1) != (1 << width)-1:
                    raise ValueError(f'undefined native ABI value escapes private stack at {where}')
                return
            for p in list(pointers):
                if p < location + width//8 and p + 8 > location:
                    del pointers[p]
            for j in range(width//8):
                byte = (value >> (8*j)) & 255
                if byte == 255:
                    opaque.pop(location+j, None)
                else:
                    opaque[location+j] = byte
            if width == 64:
                pointers[location] = pointer

        if op in decode.CC_AUX:
            flags_needed(incoming, op, where)
        if op in {'adc', 'sbb', 'rcl', 'rcr'} and not (flags & CF):
            raise ValueError(f'undefined native ABI carry at {where}')

        # Memory addresses always execute, including false CMOV sources.
        for arg in args:
            if decode.is_mem(arg) and op not in {'lea','nop','data16','cs'}:
                address(arg)

        if op in {'mov', 'movabs', 'movzx', 'movsx', 'movsxd', 'movaps', 'movups', 'movbe'}:
            dst = ri(args[0])
            src = ri(args[1])
            if dst:
                width = dst[1]
                if src:
                    value, pointer = mask(incoming, args[1]), incoming.aliases[src[0]]
                    if op in {'movsx', 'movsxd'} and not (value & (1 << (src[1]-1))):
                        value &= (1 << src[1])-1
                    else:
                        value |= FULL ^ ((1 << (src[1] if src else width))-1)
                elif decode.is_mem(args[1]) and insn.reloc_symbol is None:
                    mw = decode.operand_width(args[1], 32 if op == 'movsxd' else width)
                    value, pointer = read_memory(args[1], mw)
                    if op not in {'movsx', 'movsxd'} or value & (1 << (mw-1)):
                        value |= FULL ^ ((1 << mw)-1)
                else:
                    value, pointer = FULL, False
                if op == 'movbe':
                    value = int.from_bytes((value & ((1 << width)-1)).to_bytes((width+7)//8, 'little'), 'big')
                constant = None
                if src and incoming.constants[src[0]] is not None:
                    constant = (incoming.constants[src[0]] >> src[2]) & ((1 << src[1])-1)
                elif decode.is_int(args[1]) and insn.reloc_symbol is None:
                    constant = decode.parse_int(args[1])
                write(args[0], value, pointer, constant)
            elif decode.is_mem(args[0]):
                width = decode.operand_width(args[0],src[1] if src else 64)
                value = mask(incoming,args[1])
                if op == 'movbe':
                    value = int.from_bytes((value & ((1 << width)-1)).to_bytes(width//8,'little'),'big')
                store(args[0],width,value,incoming.aliases[src[0]] if src and op!='movbe' else False)
        elif op == 'lea':
            location = address(args[1])
            write(args[0], FULL, location)
        elif op == 'push':
            need(incoming,'rsp',where)
            width = insn.stack_width or (ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0]))
            size = 2 if width == 16 else 8
            value, pointer = (read_memory(args[0],width) if decode.is_mem(args[0]) else
                              (mask(incoming,args[0]), incoming.aliases[ri(args[0])[0]] if ri(args[0]) else False))
            offset = alias[rsp]
            alias[rsp] = offset-size if type(offset) is int else None
            # Store at the decremented native SP without observing the saved bits.
            if type(alias[rsp]) is not int:
                raise ValueError(f'native stack address relation unresolved at {where}')
            at = alias[rsp]
            for j in range(size):
                byte = (value >> (8*j)) & 255
                if byte != 255: opaque[at+j] = byte
                else: opaque.pop(at+j,None)
            pointers[at] = pointer
        elif op == 'pop':
            need(incoming,'rsp',where)
            width = insn.stack_width or (ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0]))
            size = 2 if width == 16 else 8
            offset = alias[rsp]
            value = sum(opaque.get(offset+j,255) << (8*j) for j in range(size)) if type(offset) is int else 0
            pointer = pointers.get(offset,False) if type(offset) is int and size == 8 else False
            alias[rsp] = offset+size if type(offset) is int else None
            if ri(args[0]): write(args[0],value,pointer)
            else: store(args[0],width,value,pointer)
        elif op.startswith('cmov'):
            need(incoming,args[0],where)
            if ri(args[1]):
                need(incoming,args[1],where)
                pointer = joined_pointer(alias[ri(args[0])[0]],alias[ri(args[1])[0]])
                write(args[0],FULL,pointer)
            else:
                value, pointer = read_memory(args[1],decode.operand_width(args[1],ri(args[0])[1]))
                write(args[0],value,pointer)
        elif op.startswith('set') and op in decode.CC_AUX:
            if ri(args[0]): write(args[0])
            else: store(args[0],8)
        elif op=='xchg':
            width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
            values = [read_memory(arg,width) if decode.is_mem(arg) else
                      (mask(incoming,arg),incoming.aliases[ri(arg)[0]]) for arg in args]
            for arg,(value,pointer) in zip(args,reversed(values)):
                if ri(arg): write(arg,value,pointer)
                else: store(arg,width,value,pointer)
        elif op in {'shl','shr','sar'} and (len(args)==1 or decode.is_int(args[1])):
            width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
            value = mask(incoming,args[0]) if ri(args[0]) else read_memory(args[0],width)[0]
            count = (decode.parse_int(args[1]) if len(args)>1 else 1) & (63 if width==64 else 31)
            full = (1 << width)-1
            if count:
                if op=='shl': result=((value << count) | ((1 << count)-1)) & full
                else:
                    fill=full ^ ((1 << max(0,width-count))-1)
                    result=value >> count
                    if op=='shr' or value & (1 << (width-1)): result |= fill
                flags=(SF if result & (1 << (width-1)) else 0) | (ZF if result==full else 0)
                if result & 255 == 255: flags |= PF
                bit=width-count if op=='shl' else min(count-1,width-1)
                if (count < width or op=='sar') and value & (1 << bit): flags |= CF
                if count==1 and (op=='sar' or value & (1 << (width-1))):
                    if op!='shl' or flags & CF: flags |= OF
            else: result=value
            if ri(args[0]): write(args[0],result)
            else: store(args[0],width,result)
        elif op in {'shld','shrd'} and ri(args[0]) and ri(args[0])[1] == 16 and (
                shift_count(args[-1],16) is None or shift_count(args[-1],16) > 16):
            # A masked count17..31 makes the result and all six status flags
            # undefined. Do not admit the simulator's particular chosen value
            # as an ISA guarantee; allow a later overwrite before observation.
            if not decode.is_int(args[-1]): need(incoming,args[-1],where)
            write(args[0],0)
            flags = 0
        elif op in {'and','or','xor','test'}:
            width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
            full = (1 << width)-1
            operands = []
            for arg in args:
                if decode.is_mem(arg):
                    operands.append((read_memory(arg,width)[0],None))
                elif ri(arg):
                    reg, rw, shift = ri(arg)
                    constant = incoming.constants[reg]
                    operands.append((mask(incoming,arg),None if constant is None else (constant >> shift) & ((1 << rw)-1)))
                else:
                    constant = decode.parse_int(arg) & ((1 << min(width,32))-1)
                    if width == 64 and constant & (1 << 31): constant |= FULL ^ 0xffffffff
                    operands.append((full,constant))
            known = operands[0][0] & operands[1][0] & full
            zero = op == 'xor' and args[0] == args[1] and ri(args[0])
            if zero: known = full
            for _,constant in operands:
                if constant is not None:
                    if op in {'and','test'}: known |= ~constant & full
                    elif op == 'or': known |= constant & full
            flags = CF | OF | (SF if known & (1 << (width-1)) else 0)
            if known == full: flags |= ZF
            if known & 255 == 255: flags |= PF
            if op != 'test':
                constant = 0 if zero else None
                left,right = operands[0][1],operands[1][1]
                if left is not None and right is not None:
                    constant = left & right if op == 'and' else left | right if op == 'or' else left ^ right
                elif op == 'and' and (left == 0 or right == 0): constant = 0
                elif op == 'or' and (left == full or right == full): constant = full
                if ri(args[0]): write(args[0],known,constant=constant)
                else: store(args[0],width,known)
        elif op in {'inc','dec','neg','not'}:
            width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
            full = (1 << width)-1
            known = mask(incoming,args[0]) if ri(args[0]) else read_memory(args[0],width)[0]
            result = known
            if op != 'not':
                unknown = full ^ known
                result = full if not unknown else (unknown & -unknown)-1
                flags = (ZF | SF | OF) if result == full else 0
                if result & 255 == 255: flags |= PF
                if result & 15 == 15: flags |= AF
                flags |= incoming.flags & CF if op in {'inc','dec'} else CF if result == full else 0
            if ri(args[0]):
                reg,width,shift = ri(args[0])
                old = incoming.constants[reg]
                constant = None if old is None else (old >> shift) & full
                if constant is not None:
                    constant = (constant+1 if op == 'inc' else constant-1 if op == 'dec' else
                                -constant if op == 'neg' else ~constant) & full
                write(args[0],result,constant=constant)
                if width == 64 and type(incoming.aliases[reg]) is int and op in {'inc','dec'}:
                    alias[reg] = incoming.aliases[reg] + (1 if op == 'inc' else -1)
            else: store(args[0],width,result)
        elif op in {'add','sub','adc','sbb','cmp'}:
            width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
            full = (1 << width)-1
            values = [read_memory(arg,width)[0] if decode.is_mem(arg) else mask(incoming,arg)
                      for arg in args]
            zero = op in {'sub','cmp'} and args[0]==args[1] and ri(args[0])
            known = full if zero else values[0] & values[1] & full
            # An unknown input bit may carry/borrow into every higher bit.
            # Lower known bits survive and may be the only lanes observed.
            unknown = full ^ known
            result = full if not unknown else (unknown & -unknown)-1
            flags = (CF | ZF | SF | OF) if result==full else 0
            if result & 255 == 255: flags |= PF
            if result & 15 == 15: flags |= AF
            if op!='cmp':
                old = alias[ri(args[0])[0]] if ri(args[0]) else False
                if ri(args[0]): write(args[0],result,constant=0 if zero else None)
                else: store(args[0],width,result)
                if width==64 and (type(old) is int or isinstance(old,PointerAlternatives)) and decode.is_int(args[1]):
                    delta = decode.parse_int(args[1])
                    if delta >= 1 << 63: delta -= 1 << 64
                    if op in {'add','sub'}:
                        alias[ri(args[0])[0]] = offset_pointer(old, delta if op=='add' else -delta)
                elif width==64 and isinstance(old,PointerAlternatives) and op in {'add','sub'}:
                    alias[ri(args[0])[0]] = None
        elif op not in {'call','ret','jmp','nop','data16','cs'} and not op.startswith('j'):
            zero = op in {'pxor','xorps'} and len(args)==2 and args[0]==args[1] and ri(args[0])
            pure = op in {'andn','bzhi','mulx','popcnt','movbe','shlx','shrx','sarx','rorx'} or (op=='imul' and len(args)==3)
            for n,arg in enumerate(args):
                if ri(arg) and not zero and not ((n==0 and pure) or (op=='mulx' and n==1)):
                    if n == 2 and op in {'bzhi','shlx','shrx','sarx'}:
                        # BZHI observes the count byte; BMI2 shifts observe
                        # the low5/6 bits even with a wider register operand.
                        required = 255 if op == 'bzhi' else 63 if ri(args[0])[1] == 64 else 31
                        if mask(incoming,arg) & required != required:
                            raise ValueError(f'undefined native ABI register {arg} at {where}')
                    else:
                        need(incoming,arg,where)
                if decode.is_mem(arg):
                    value,_ = read_memory(arg,decode.operand_width(arg))
                    if value != (1 << decode.operand_width(arg))-1:
                        raise ValueError(f'undefined native ABI stack value at {where}')
            if op=='rep':
                for reg in ('rcx','rsi','rdi'): need(incoming,reg,where)
            if op=='div' and len(args)==1:
                width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
                low, high = {8: ('ax', None), 16: ('ax', 'dx'), 32: ('eax', 'edx'), 64: ('rax', 'rdx')}[width]
                need(incoming,low,where)
                if high is not None: need(incoming,high,where)
                write('ax' if width==8 else low)
                if high is not None: write(high)
            elif op in {'mul','imul','idiv'} and len(args)==1:
                need(incoming,'rax',where)
                if op in {'div','idiv'}: need(incoming,'rdx',where)
                write('rax');write('rdx')
            elif op in {'cbw','cwde','cdqe'}:
                source, target = {'cbw': ('al','ax'), 'cwde': ('ax','eax'), 'cdqe': ('eax','rax')}[op]
                source_bits, target_bits = ri(source)[1], ri(target)[1]
                known = mask(incoming,source)
                if known & (1 << (source_bits-1)):
                    known |= ((1 << target_bits)-1) ^ ((1 << source_bits)-1)
                constant = incoming.constants[ri(source)[0]]
                if constant is not None:
                    constant &= (1 << source_bits)-1
                    if constant & (1 << (source_bits-1)): constant -= 1 << source_bits
                    constant &= (1 << target_bits)-1
                write(target,known,constant=constant)
            elif op in {'cdq','cqo','cwd'}:
                source, target = {'cwd': ('ax','dx'), 'cdq': ('eax','edx'), 'cqo': ('rax','rdx')}[op]
                known = (1 << ri(target)[1])-1 if mask(incoming,source) & (1 << (ri(source)[1]-1)) else 0
                write(target,known)
            elif op=='mulx':
                need(incoming,'rdx',where)
                write(args[0]);write(args[1])
            elif op=='xadd':
                for arg in args:
                    if ri(arg): write(arg)
            elif args and ri(args[0]) and op!='bt':
                write(args[0],constant=0 if zero else None)
            if args and decode.is_mem(args[0]) and op!='bt':
                store(args[0],decode.operand_width(args[0]))
            if op in {'xadd','popcnt'}:
                flags = ALL_FLAGS
            elif op in {'bzhi','andn'}: flags = CF | ZF | SF | OF
            elif op in {'mul','imul'}: flags = CF | OF
            elif op in {'div','idiv'}: flags = 0
            elif op=='bt': flags = (flags & ZF) | CF
            elif op in {'shl','shr','sar','shld','shrd','rol','ror'}:
                width = ri(args[0])[1] if ri(args[0]) else decode.operand_width(args[0])
                count = shift_count(args[-1],width)
                if count != 0:
                    new = CF | (OF if count==1 else 0)
                    if op not in {'rol','ror'}: new |= ZF | SF | PF
                    else: new |= flags & (ZF|SF|PF|AF)
                    flags = flags & new if count is None else new

        state = State(tuple(bits),tuple(alias),flags,opaque,pointers,tuple(constants))
        next_pc = following.get(addr)
        direct = insn.reloc_target if insn.reloc_target is not None else decode.branch_target(args[0]) if args else None
        if op=='call':
            choices = targets.get(addr,())
            names = [helper_idents()[v] for kind,v in choices if kind=='scalar']
            if decode.is_helper_symbol(insn.reloc_symbol): names.append(insn.reloc_symbol)
            if insn.reloc_symbol in {'memcpy','memset'}:
                for reg in ('rdi','rsi','rdx'): need(incoming,reg,where)
                names.append(insn.reloc_symbol)
            for name in names:
                if name not in {'memcpy','memset'}:
                    params = helper_prototypes()[name].arguments
                    for n,param in enumerate([] if params=='void' else params.split(',')):
                        if param.strip()=='...': break
                        reg = ('rdi','rsi','rdx','rcx','r8')[n]
                        # C integer parameters read their declared argument width.
                        if '*' not in param and any(t in param.split() for t in ('__u32','__s32','int')):
                            reg = {'rdi':'edi','rsi':'esi','rdx':'edx','rcx':'ecx','r8':'r8d'}[reg]
                        need(incoming,reg,where)
            if names:
                # Only remove opaque bytes overwritten by every possible
                # callee. A helper writing four bytes must not initialize an
                # adjacent saved ABI register or a string helper's suffix.
                effects = []
                arg_regs = ('rdi','rsi','rdx','rcx','r8')
                for name in names:
                    written, saved = dict(state.opaque), dict(state.pointers)
                    effect = HELPER_FULL_WRITES.get(name)
                    if effect is not None:
                        dst, size = (ri(arg_regs[n])[0] for n in effect)
                        start, length = incoming.aliases[dst], incoming.constants[size]
                        if type(start) is int and length is not None:
                            length &= 0xffffffff
                            end = start + length
                            written = {p:v for p,v in written.items() if not start <= p < end}
                            saved = {p:v for p,v in saved.items() if not (p < end and p+8 > start)}
                            if name in HELPER_COPY_SOURCES:
                                source = incoming.aliases[ri(arg_regs[HELPER_COPY_SOURCES[name]])[0]]
                                if source is None:
                                    raise ValueError(f'native helper source stack relation unresolved at {where}')
                                origins=source.offsets if isinstance(source,PointerAlternatives) else {source} if type(source) is int else set()
                                for origin in origins:
                                    for p,v in state.opaque.items():
                                        if origin <= p < origin+length:
                                            target=start+p-origin
                                            written[target]=written.get(target,255) & v
                                if len(origins)==1 and not (isinstance(source,PointerAlternatives) and source.external):
                                    origin=next(iter(origins))
                                    saved.update({start+p-origin:v for p,v in state.pointers.items()
                                                  if origin <= p and p+8 <= origin+length})
                                elif origins:
                                    # Multiple origins do not establish control/
                                    # pointer provenance even when all bytes are defined.
                                    for n in range(max(0,length-7)): saved[start+n]=None
                    effects.append(State(state.defined,state.aliases,state.flags,written,saved,state.constants))
                effect = effects[0]
                for branch in effects[1:]: effect = joined(effect,branch)
                opaque, pointers = effect.opaque, effect.pointers
                for reg in CALLER_SAVED:
                    bits[ri(reg)[0]]=0;alias[ri(reg)[0]]=None;constants[ri(reg)[0]]=None
                bits[index['X86_XMM0']]=0;alias[index['X86_XMM0']]=None;constants[index['X86_XMM0']]=None
                bits[rax]=FULL;alias[rax]=False;constants[rax]=None
                push(context,next_pc,State(tuple(bits),tuple(alias),0,opaque,pointers,tuple(constants)))
            code = [v for kind,v in choices if kind=='code']
            if not choices and not names: code=[direct]
            for target in code:
                bits, alias = list(state.defined), list(state.aliases)
                constants = list(state.constants)
                child = context + (addr,)
                if addr in context: child=context[:context.index(addr)+1]
                at=alias[rsp]
                alias[rsp]=at-8 if type(at) is int else None
                if type(alias[rsp]) is int:
                    for j in range(8): opaque.pop(alias[rsp]+j,None)
                    pointers[alias[rsp]]=frozenset({ReturnAddress(context,next_pc)})
                if type(alias[rsp]) is not int:
                    raise ValueError(f'native call stack relation unresolved at {where}')
                push(child,target,State(tuple(bits),tuple(alias),flags,opaque,pointers,tuple(constants)))
        elif op=='ret':
            if type(alias[rsp]) is not int:
                raise ValueError(f'native ABI return has an unbalanced stack pointer at {where}')
            destinations=pointers.get(alias[rsp])
            if not isinstance(destinations,frozenset) or not destinations:
                raise ValueError(f'native return address lacks call/entry provenance at {where}')
            for destination in destinations:
                if destination.target is None:
                    if alias[rsp] != 0:
                        raise ValueError(f'native entry return has an unbalanced stack pointer at {where}')
                    need(state,'eax',where)
                else:
                    if return_sites is not None:
                        return_sites.add(destination.target)
                    returned_alias=list(alias)
                    returned_alias[rsp]+=8
                    push(destination.context,destination.target,State(tuple(bits),tuple(returned_alias),flags,opaque,pointers,tuple(constants)))
        elif op=='jmp':
            for target in ([v for kind,v in targets.get(addr,()) if kind=='code'] if decode.is_indirect_branch(insn) else [direct]):
                push(context,target,state)
        else:
            if op in decode.CC_AUX and op.startswith('j'): push(context,direct,state)
            if next_pc is not None: push(context,next_pc,state)
    return -lowest_stack
