"""Check native ABI definedness before specializing concrete initializer values.

This is a read/write-effect analysis, not another ISA value interpreter. Native
instruction values/flags remain implemented by the C simulator and its contracts.
"""
from collections import deque
from dataclasses import dataclass

from helper_abi import helper_idents, helper_prototypes

FULL = (1 << 64) - 1
CF, ZF, SF, OF = 1, 2, 4, 8
ALL_FLAGS = CF | ZF | SF | OF
CC_FLAGS = {'A': CF | ZF, 'AE': CF, 'B': CF, 'BE': CF | ZF,
            'E': ZF, 'NE': ZF, 'G': ZF | SF | OF, 'GE': SF | OF,
            'L': SF | OF, 'LE': ZF | SF | OF, 'S': SF, 'NS': SF}
CALLER_SAVED = ('rax', 'rcx', 'rdx', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11')


@dataclass
class State:
    defined: tuple[int, ...]
    aliases: tuple[int | bool | None, ...]
    flags: int
    # Only bytes depending on unspecified ABI values need entries. Other raw
    # stack initialization remains the actual BPF verifier's responsibility.
    opaque: dict[int, int]
    pointers: dict[int, int | bool | None]
    constants: tuple[int | None, ...]


def check_definedness(insns, targets, exit_addr, decode):
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
    initial = State(tuple(defined), tuple(aliases), 0, {}, {}, (None,)*len(regs))
    states = {((), insns[0].addr): initial}
    queue = deque(states)
    # Call-string contexts retain opaque callee saves from distinct callers.
    # Repeated call sites join to a finite context, never a runtime depth limit.
    returns = {}
    entry_sp = {(): {0}}

    def same(a, b):
        return type(a) is type(b) and a == b

    def joined(a, b):
        opaque = {p: a.opaque.get(p, 255) & b.opaque.get(p, 255)
                  for p in a.opaque.keys() | b.opaque.keys()}
        opaque = {p: v for p, v in opaque.items() if v != 255}
        pointers = {p: a.pointers[p] if p in a.pointers and p in b.pointers and
                    same(a.pointers[p], b.pointers[p]) else None
                    for p in a.pointers.keys() | b.pointers.keys()}
        return State(tuple(x & y for x, y in zip(a.defined, b.defined)),
                     tuple(x if same(x, y) else None for x, y in zip(a.aliases, b.aliases)),
                     a.flags & b.flags, opaque, pointers,
                     tuple(x if x == y else None for x,y in zip(a.constants,b.constants)))

    def push(context, addr, state):
        if addr == exit_addr:
            if context or type(state.aliases[rsp]) is not int or state.aliases[rsp] != 0:
                raise ValueError('native entry return has an unbalanced stack pointer')
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

        def write(operand, value=None, pointer=False, constant=None):
            parsed = ri(operand)
            if parsed is None:
                return
            reg, width, shift = parsed
            if value is None: value = (1 << width)-1
            lane = ((1 << width) - 1) << shift
            bits[reg] = (bits[reg] & ~lane) | ((value << shift) & lane)
            if width == 32:
                bits[reg] |= FULL ^ 0xffffffff
            alias[reg] = pointer if width == 64 else False
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
                if base != 'X86_REG_NONE' and type(alias[index[base]]) is int:
                    return alias[index[base]] + (iv << scale) + disp if iv is not None else None
                return False if base == 'X86_REG_NONE' or alias[index[base]] is False else None
            if base == 'X86_REG_NONE':
                return False
            origin = alias[index[base]]
            return origin + disp if type(origin) is int else origin

        def read_memory(operand, width):
            location = address(operand)
            if type(location) is int:
                value = sum(opaque.get(location + j, 255) << (8*j) for j in range(width//8))
                return value, pointers.get(location, False) if width == 64 else False
            if location is None:
                return 0, None
            return (1 << width) - 1, False

        def store(operand, width, value=FULL, pointer=False):
            location = address(operand)
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
                pointer = alias[ri(args[0])[0]] if same(alias[ri(args[0])[0]],alias[ri(args[1])[0]]) else None
                write(args[0],FULL,pointer)
            else:
                value, pointer = read_memory(args[1],decode.operand_width(args[1],ri(args[0])[1]))
                write(args[0],value,pointer)
        elif op.startswith('set') and op in decode.CC_AUX:
            if ri(args[0]): write(args[0])
            else: store(args[0],8)
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
                bit=width-count if op=='shl' else count-1
                if count < width and value & (1 << bit): flags |= CF
                if count==1 and (op=='sar' or value & (1 << (width-1))):
                    if op!='shl' or flags & CF: flags |= OF
            else: result=value
            if ri(args[0]): write(args[0],result)
            else: store(args[0],width,result)
        elif op not in {'call','ret','jmp','nop','data16','cs'} and not op.startswith('j'):
            zero = op in {'xor','sub','cmp','pxor','xorps'} and len(args)==2 and args[0]==args[1] and ri(args[0])
            pure = op in {'andn','bzhi','mulx','popcnt','movbe','shlx','shrx','sarx','rorx'} or (op=='imul' and len(args)==3)
            for n,arg in enumerate(args):
                if ri(arg) and not zero and not ((n==0 and pure) or (op=='mulx' and n==1)):
                    need(incoming,arg,where)
                if decode.is_mem(arg):
                    value,_ = read_memory(arg,decode.operand_width(arg))
                    if value != (1 << decode.operand_width(arg))-1:
                        raise ValueError(f'undefined native ABI stack value at {where}')
            if op=='rep':
                for reg in ('rcx','rsi','rdi'): need(incoming,reg,where)
            if op in {'mul','imul','div','idiv'} and len(args)==1:
                need(incoming,'rax',where)
                if op in {'div','idiv'}: need(incoming,'rdx',where)
                write('rax');write('rdx')
            elif op in {'cdqe','cdq','cqo','cwd'}:
                need(incoming,'eax' if op in {'cdqe','cdq'} else 'rax',where)
                write('rax' if op=='cdqe' else 'edx' if op=='cdq' else 'dx' if op=='cwd' else 'rdx')
            elif op=='mulx':
                need(incoming,'rdx',where)
                write(args[0]);write(args[1])
            elif op in {'xchg','xadd'}:
                for arg in args:
                    if ri(arg): write(arg)
            elif args and ri(args[0]) and op not in {'cmp','test','bt'}:
                old = alias[ri(args[0])[0]]
                write(args[0],constant=0 if zero else None)
                if op in {'add','sub'} and len(args)==2 and decode.is_int(args[1]) and type(old) is int:
                    delta = decode.parse_int(args[1])
                    if delta >= 1 << 63: delta -= 1 << 64
                    alias[ri(args[0])[0]] = old + (delta if op=='add' else -delta)
            if op in {'add','sub','adc','sbb','cmp','test','xor','and','or','neg','xadd','bzhi','popcnt','andn'}:
                flags = ALL_FLAGS
            elif op in {'inc','dec'}: flags = (flags & CF) | ZF | SF | OF
            elif op in {'mul','imul'}: flags = CF | OF
            elif op in {'div','idiv'}: flags = 0
            elif op=='bt': flags = (flags & ZF) | CF
            elif op in {'shl','shr','sar','shld','shrd','rol','ror'}:
                count = decode.parse_int(args[-1]) & (63 if ri(args[0]) and ri(args[0])[1]==64 else 31) if decode.is_int(args[-1]) else None
                if count != 0:
                    new = CF | (OF if count==1 else 0)
                    if op not in {'rol','ror'}: new |= ZF | SF
                    else: new |= flags & (ZF|SF)
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
                edge = context,next_pc
                if edge not in returns.setdefault(child,set()):
                    returns[child].add(edge)
                    queue.extend(k for k in states if k[0]==child and by_addr[k[1]].mnemonic=='ret')
                at=alias[rsp]
                alias[rsp]=at-8 if type(at) is int else None
                if type(alias[rsp]) is int:
                    for j in range(8): opaque.pop(alias[rsp]+j,None)
                    pointers[alias[rsp]]=False
                if type(alias[rsp]) is not int:
                    raise ValueError(f'native call stack relation unresolved at {where}')
                entry_sp.setdefault(child,set()).add(alias[rsp])
                push(child,target,State(tuple(bits),tuple(alias),flags,opaque,pointers,tuple(constants)))
        elif op=='ret':
            if type(alias[rsp]) is not int or alias[rsp] not in entry_sp[context]:
                raise ValueError(f'native ABI return has an unbalanced stack pointer at {where}')
            if context:
                offset=alias[rsp]
                alias[rsp]=offset+8 if type(offset) is int else None
                for parent,continuation in returns.get(context,set()):
                    push(parent,continuation,State(tuple(bits),tuple(alias),flags,opaque,pointers,tuple(constants)))
            else: need(state,'eax',where)
        elif op=='jmp':
            for target in ([v for kind,v in targets.get(addr,()) if kind=='code'] if decode.is_indirect_branch(insn) else [direct]):
                push(context,target,state)
        else:
            if op in decode.CC_AUX and op.startswith('j'): push(context,direct,state)
            if next_pc is not None: push(context,next_pc,state)
