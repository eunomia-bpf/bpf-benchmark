"""Image-bound facts for lowering compiler-generated relative code tables."""
from dataclasses import dataclass
import json


@dataclass(frozen=True)
class NativeEffects:
    reads: tuple[tuple[str, int], ...]
    writes: tuple[tuple[str, int], ...]
    flags_read: int
    flags_written: int


class ReadonlyBytes(bytes):
    def __new__(cls, data, code_relocations=()):
        value = super().__new__(cls, data)
        value.code_relocations = tuple(code_relocations)
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


def readonly_code_relocations(elf, section_index, symbol):
    symbols = elf.get_section_by_name('.symtab')
    text_index = elf.get_section_index('.text')
    start, size = symbol['st_value'], symbol['st_size']
    result = []
    for section in elf.iter_sections():
        if section['sh_type'] not in {'SHT_REL', 'SHT_RELA'} or section['sh_info'] != section_index:
            continue
        for relocation in section.iter_relocations():
            offset = relocation['r_offset']
            if not start <= offset < start + size:
                continue
            target = symbols.get_symbol(relocation['r_info_sym'])
            if (section['sh_type'] != 'SHT_RELA' or relocation['r_info_type'] != 2 or
                    target['st_shndx'] != text_index or offset + 4 > start + size):
                raise ValueError('unsupported nested native readonly relocation')
            result.append((offset-start, target['st_value'] + relocation['r_addend'] - (offset-start)))
    return tuple(sorted(result))
