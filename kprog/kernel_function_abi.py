"""Derive callable kernel signatures from the running kernel's BTF via libbpf."""
import ctypes as c
from io import BytesIO
from elftools.elf.elffile import ELFFile
from helper_abi import is_helper_symbol


class Type(c.Structure):
    _fields_ = [('name', c.c_uint32), ('info', c.c_uint32), ('value', c.c_uint32)]


class KernelTypes:
    def __init__(self, path):
        self.lib = c.CDLL('libbpf.so.1', use_errno=True)
        self.lib.btf__parse.argtypes = [c.c_char_p, c.c_void_p]
        self.lib.btf__parse.restype = c.c_void_p
        self.lib.btf__free.argtypes = [c.c_void_p]
        self.lib.btf__type_by_id.argtypes = [c.c_void_p, c.c_uint32]
        self.lib.btf__type_by_id.restype = c.POINTER(Type)
        self.lib.btf__name_by_offset.argtypes = [c.c_void_p, c.c_uint32]
        self.lib.btf__name_by_offset.restype = c.c_char_p
        self.lib.btf__find_by_name_kind.argtypes = [c.c_void_p, c.c_char_p, c.c_uint32]
        self.lib.btf__find_by_name_kind.restype = c.c_int
        self.lib.btf__resolve_size.argtypes = [c.c_void_p, c.c_uint32]
        self.lib.btf__resolve_size.restype = c.c_int64
        self.btf = self.lib.btf__parse(str(path).encode(), None)
        if not self.btf:
            raise OSError(c.get_errno(), 'parse target kernel BTF')
        self.forwards = set()

    def close(self):
        self.lib.btf__free(self.btf)

    def type(self, identity):
        pointer = self.lib.btf__type_by_id(self.btf, identity)
        if not pointer:
            raise ValueError('kernel BTF type is absent: ' + str(identity))
        return pointer.contents

    def name(self, t):
        value = self.lib.btf__name_by_offset(self.btf, t.name)
        if value is None:
            raise ValueError('kernel BTF name is absent')
        return value.decode('ascii')

    def base(self, identity):
        while identity:
            t = self.type(identity)
            if t.info >> 24 & 31 not in {8, 9, 10, 11, 18}:
                return identity, t
            identity = t.value
        return 0, None

    def spelling(self, identity):
        if not identity:
            return 'void'
        t = self.type(identity); kind = t.info >> 24 & 31
        if kind in {8, 9, 11, 18}:
            return self.spelling(t.value)
        if kind == 10:
            return 'const ' + self.spelling(t.value)
        if kind == 2:
            return self.spelling(t.value) + ' *'
        if kind in {4, 5, 7}:
            tag = 'union' if kind == 5 or (kind == 7 and t.info >> 31) else 'struct'
            name = self.name(t)
            if not name:
                raise ValueError('anonymous aggregate kernel argument needs a complete declaration')
            self.forwards.add(tag + ' ' + name + ';')
            return tag + ' ' + name
        if kind in {1, 6, 19}:
            if kind == 1:
                encoding = c.c_uint32.from_address(c.addressof(t) + c.sizeof(Type)).value
                signed = bool(encoding >> 24 & 1)
            else:
                signed = bool(t.info >> 31)
            if t.value not in {1, 2, 4, 8}:
                raise ValueError('kernel scalar ABI width is not supported: ' + str(t.value))
            return '__' + ('s' if signed else 'u') + str(t.value * 8)
        raise ValueError('kernel ABI type needs an explicit bridge: ' + str(kind))

    def value(self, identity):
        _, base = self.base(identity)
        pointer = base is not None and base.info >> 24 & 31 == 2
        size = 0 if base is None else self.lib.btf__resolve_size(self.btf, identity)
        if size < 0:
            raise ValueError('kernel argument type has no ABI size')
        result = dict(type=self.spelling(identity), pointer=pointer, size=size)
        return result

    def function(self, name, weak):
        identity = self.lib.btf__find_by_name_kind(self.btf, name.encode(), 12)
        if identity == -2:
            return dict(name=name, present=False, weak=True) if weak else None
        if identity < 0:
            raise ValueError('query kernel function BTF failed: ' + str(identity))
        function = self.type(identity); prototype = self.type(function.value)
        if prototype.info >> 24 & 31 != 13:
            raise ValueError('kernel function lacks FUNC_PROTO')
        self.forwards.clear()
        result = self.value(prototype.value)
        params = (c.c_uint32 * ((prototype.info & 65535) * 2)).from_address(
            c.addressof(prototype) + c.sizeof(Type))
        arguments = [self.value(params[i * 2 + 1]) for i in range(prototype.info & 65535)]
        return dict(name=name, present=True, weak=weak, result=result,
                    arguments=arguments, forwards=sorted(self.forwards))


def describe(native, maps, path='/sys/kernel/btf/vmlinux'):
    elf = ELFFile(BytesIO(native))
    table = elf.get_section_by_name('.symtab')
    candidates = {s.name: s['st_info']['bind'] == 'STB_WEAK' for s in table.iter_symbols()
                  if s.name and s['st_shndx'] == 'SHN_UNDEF'
                  and s.name not in maps and s.name not in {'memcpy', 'memset', 'memmove'}
                  and not is_helper_symbol(s.name)}
    if not candidates:
        return {}
    types = KernelTypes(path)
    try:
        result = {}
        for name, weak in candidates.items():
            function = types.function(name, weak)
            if function is not None:
                result[name] = function
        return result
    finally:
        types.close()
