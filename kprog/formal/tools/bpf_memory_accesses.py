"""Trace guest accesses through the real ELF calls of the compiled BPF oracles.

Guest offsets and scalar constants are exact. Other scalar values remain
abstract; a guest address or control decision must resolve before execution
continues. Stack slots carry spilled addresses across calls. Function ranges,
call targets and addends come from ELF symbols and relocations.
"""
from dataclasses import dataclass
from pathlib import Path
import struct


@dataclass(frozen=True)
class Pointer:
    space: str
    offset: int = 0
    frame: int = 0


@dataclass(frozen=True)
class Function:
    name: str
    section: int
    start: int
    size: int
    binding: int


def signed(value, bits=64):
    value &= (1 << bits) - 1
    return value - (1 << bits) if value >> (bits - 1) else value


class BpfObject:
    def __init__(self, data):
        self.data = bytes(data)
        header = self.unpack('<16sHHIQQQIHHHHHH', 0)
        if header[0][:6] != b'\x7fELF\x02\x01' or header[2] != 247:
            raise ValueError('memory trace: expected little-endian ELF64 BPF')
        if header[11] != 64:
            raise ValueError('memory trace: unexpected ELF section-header size')
        self.sections = [self.unpack('<IIQQQQIIQQ', header[6] + 64 * i)
                         for i in range(header[12])]
        self.symbols = {}
        self.functions = {}
        self.targets = {}
        for index, section in enumerate(self.sections):
            if section[1] != 2:  # SHT_SYMTAB
                continue
            if section[9] != 24:
                raise ValueError('memory trace: unexpected symbol size')
            strings = self.section_data(section[6])
            symbols = []
            for pos in range(section[4], section[4] + section[5], 24):
                name, info, _, owner, value, size = self.unpack('<IBBHQQ', pos)
                end = strings.index(b'\0', name)
                text = strings[name:end].decode()
                symbols.append((text, info, owner, value, size))
                if info & 15 == 2 and owner:  # defined STT_FUNC
                    if size % 8 or value % 8 or not self.sections[owner][2] & 4:
                        raise ValueError(f'memory trace: invalid function extent: {text}')
                    function = Function(text, owner, value, size, info >> 4)
                    if text in self.functions:
                        raise ValueError(f'memory trace: duplicate function: {text}')
                    self.functions[text] = function
                    self.targets[(owner, value)] = function
            self.symbols[index] = symbols
        self.relocations = {}
        for section in self.sections:
            if section[1] != 9 or not self.sections[section[7]][2] & 4:
                continue
            if section[9] != 16:
                raise ValueError('memory trace: unexpected relocation size')
            symbols = self.symbols[section[6]]
            for pos in range(section[4], section[4] + section[5], 16):
                offset, info = self.unpack('<QQ', pos)
                self.relocations[(section[7], offset)] = (info & 0xffffffff,
                    symbols[info >> 32], pos)

    @classmethod
    def read(cls, path):
        return cls(Path(path).read_bytes())

    def unpack(self, fmt, offset):
        size = struct.calcsize(fmt)
        if offset < 0 or offset + size > len(self.data):
            raise ValueError('memory trace: truncated ELF record')
        return struct.unpack_from(fmt, self.data, offset)

    def section_data(self, index):
        section = self.sections[index]
        return self.data[section[4]:section[4] + section[5]]

    @property
    def entries(self):
        return {name for name, function in self.functions.items() if function.binding in (1, 2)}

    def file_offset(self, section, offset):
        return self.sections[section][4] + offset

    def call_target(self, function, offset, immediate):
        key = (function.section, offset)
        if key in self.relocations:
            kind, symbol, _ = self.relocations[key]
            if kind != 10:  # R_BPF_64_32
                raise ValueError('memory trace: expected BPF call relocation')
            name, _, section, value, _ = symbol
            if not section:
                raise ValueError(f'memory trace: undefined call target: {name}')
            address = value + (immediate + 1) * 8
        else:
            section, address = function.section, offset + (immediate + 1) * 8
        key = (section, address)
        if key not in self.targets:
            raise ValueError(f'memory trace: call target is outside a function: {key}')
        return self.targets[key]

    def accesses(self, entry, second_argument=None, fixed_displacement=None):
        events, stack, executed = [], {}, []
        next_frame = 0

        def stack_store(pointer, width, value):
            for key in list(stack):
                frame, offset, size = key
                if frame == pointer.frame and offset < pointer.offset + width and pointer.offset < offset + size:
                    del stack[key]
            stack[(pointer.frame, pointer.offset, width)] = value

        def execute(function, incoming, active):
            nonlocal next_frame
            if function.name in active:
                raise ValueError('memory trace: recursive BPF call')
            registers = list(incoming)
            registers[10] = Pointer('stack', frame=next_frame)
            next_frame += 1
            pc, visited = 0, set()
            while 0 <= pc < function.size // 8:
                state = (pc, tuple(registers))
                if state in visited:
                    raise ValueError('memory trace: repeated BPF execution state')
                visited.add(state)
                offset = function.start + pc * 8
                position = self.file_offset(function.section, offset)
                code, packed, displacement, immediate = self.unpack('<BBhi', position)
                dst, src = packed & 15, packed >> 4
                if dst > 10 or src > 10:
                    raise ValueError('memory trace: invalid BPF register')
                executed.append((function.section, offset, code, packed, immediate))
                pc += 1
                if code == 0x18:
                    if src or pc >= function.size // 8:
                        raise ValueError('memory trace: expected complete scalar64 literal')
                    high = self.unpack('<BBhi', position + 8)
                    if high[:3] != (0, 0, 0):
                        raise ValueError('memory trace: malformed scalar64 literal')
                    registers[dst] = (immediate & 0xffffffff) | ((high[3] & 0xffffffff) << 32)
                    pc += 1
                elif code & 7 in (4, 7):
                    bits = 32 if code & 7 == 4 else 64
                    mask, operation = (1 << bits) - 1, code & 0xf0
                    left = registers[dst]
                    right = registers[src] if code & 8 else immediate & mask
                    if operation == 0xb0:
                        registers[dst] = (right & mask if isinstance(right, int) else
                                          right if bits == 64 else None)
                    elif bits == 64 and operation in (0, 0x10) and isinstance(left, Pointer) and isinstance(right, int):
                        amount = signed(right, bits) * (1 if operation == 0 else -1)
                        registers[dst] = Pointer(left.space, left.offset + amount, left.frame)
                    elif bits == 64 and operation == 0 and isinstance(left, int) and isinstance(right, Pointer):
                        registers[dst] = Pointer(right.space, right.offset + signed(left, bits), right.frame)
                    elif isinstance(left, int) and isinstance(right, int):
                        if operation == 0:
                            value = left + right
                        elif operation == 0x10:
                            value = left - right
                        elif operation == 0x20:
                            value = left * right
                        elif operation == 0x30:
                            value = left // right if right else 0
                        elif operation == 0x40:
                            value = left | right
                        elif operation == 0x50:
                            value = left & right
                        elif operation == 0x60:
                            value = left << (right & (bits - 1))
                        elif operation == 0x70:
                            value = (left & mask) >> (right & (bits - 1))
                        elif operation == 0x80:
                            value = -left
                        elif operation == 0x90:
                            value = left % right if right else left
                        elif operation == 0xa0:
                            value = left ^ right
                        elif operation == 0xc0:
                            value = signed(left, bits) >> (right & (bits - 1))
                        else:
                            raise ValueError(f'memory trace: scalar operation {code:#x}')
                        registers[dst] = value & mask
                    else:
                        registers[dst] = None
                elif code & 7 in (1, 2, 3) and code & 0xe0 == 0x60:
                    read = code & 7 == 1
                    pointer = registers[src if read else dst]
                    if not isinstance(pointer, Pointer):
                        raise ValueError('memory trace: access lost its address')
                    address = Pointer(pointer.space, pointer.offset + displacement, pointer.frame)
                    width = {0: 4, 8: 2, 16: 1, 24: 8}[code & 24]
                    if address.space == 'guest':
                        events.append(('read' if read else 'write', address.offset, width))
                        if read:
                            registers[dst] = None
                    elif read:
                        registers[dst] = stack.get((address.frame, address.offset, width))
                    else:
                        stack_store(address, width, registers[src] if code & 7 == 3 else immediate)
                elif code == 0x85:
                    if src == 1:
                        target = self.call_target(function, offset, immediate)
                        if fixed_displacement is not None:
                            if registers[2] != Pointer('guest') or not isinstance(registers[3], int) or signed(registers[3]) != fixed_displacement:
                                raise ValueError('memory trace: fixed call changed its base/displacement arguments')
                        value = execute(target, registers, active + (function.name,))
                    elif src == 0 and immediate == 113:
                        destination, width, source = registers[1:4]
                        if not isinstance(destination, Pointer) or not isinstance(source, Pointer) or not isinstance(width, int):
                            raise ValueError('memory trace: unresolved probe-read arguments')
                        if source.space == 'guest':
                            events.append(('read', source.offset, width))
                        if destination.space == 'guest':
                            events.append(('write', destination.offset, width))
                        else:
                            stack_store(destination, width, None)
                        value = None
                    else:
                        raise ValueError(f'memory trace: unsupported call {src}:{immediate}')
                    registers[0] = value
                    registers[1:6] = [None] * 5
                elif code == 0x95:
                    return registers[0]
                elif code & 7 in (5, 6):
                    operation, bits = code & 0xf0, 32 if code & 7 == 6 else 64
                    if operation == 0:
                        pc += displacement
                        continue
                    left = registers[dst]
                    right = registers[src] if code & 8 else immediate
                    if not isinstance(left, int) or not isinstance(right, int):
                        raise ValueError('memory trace: unresolved branch condition')
                    left, right = left & ((1 << bits) - 1), right & ((1 << bits) - 1)
                    conditions = {0x10: left == right, 0x20: left > right, 0x30: left >= right,
                        0x40: bool(left & right), 0x50: left != right, 0x60: signed(left, bits) > signed(right, bits),
                        0x70: signed(left, bits) >= signed(right, bits), 0xa0: left < right,
                        0xb0: left <= right, 0xc0: signed(left, bits) < signed(right, bits),
                        0xd0: signed(left, bits) <= signed(right, bits)}
                    if operation not in conditions:
                        raise ValueError(f'memory trace: branch operation {code:#x}')
                    if conditions[operation]:
                        pc += displacement
                else:
                    raise ValueError(f'memory trace: instruction {code:#x}')
            raise ValueError('memory trace: function fell through its extent')

        registers = [None] * 11
        registers[1] = Pointer('guest')
        registers[2] = second_argument & ((1 << 64) - 1) if second_argument is not None else None
        execute(self.functions[entry], registers, ())
        self.executed = executed
        return events
