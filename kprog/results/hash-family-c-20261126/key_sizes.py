"""Read hash map key sizes from the staged native objects' DWARF map types."""
import json
from pathlib import Path
from elftools.elf.elffile import ELFFile

def base(die):
    while die.tag in {'DW_TAG_typedef', 'DW_TAG_const_type', 'DW_TAG_volatile_type', 'DW_TAG_restrict_type'}:
        die = die.get_DIE_from_attribute('DW_AT_type')
    return die

def count(die):
    ranges = [d for d in base(die).iter_children() if d.tag == 'DW_TAG_subrange_type']
    assert len(ranges) == 1, die
    r = ranges[0].attributes
    return r['DW_AT_count'].value if 'DW_AT_count' in r else r['DW_AT_upper_bound'].value + 1

def size(die):
    die = base(die)
    if 'DW_AT_byte_size' in die.attributes:
        return die.attributes['DW_AT_byte_size'].value
    if die.tag == 'DW_TAG_array_type':
        return count(die) * size(die.get_DIE_from_attribute('DW_AT_type'))
    raise ValueError('key has no DWARF size: ' + die.tag)

rows = []
for obj in sorted(Path('vendor/build/native-bpf/x86/stage').glob('*/*.native.o')):
    with obj.open('rb') as source:
        elf = ELFFile(source)
        names = {s.name for s in elf.get_section_by_name('.symtab').iter_symbols()
                 if isinstance(s['st_shndx'], int) and elf.get_section(s['st_shndx']).name == '.maps'}
        remaining = set(names)
        for cu in elf.get_dwarf_info().iter_CUs():
            for die in cu.get_top_DIE().iter_children():
                attr = die.attributes.get('DW_AT_name')
                if die.tag != 'DW_TAG_variable' or not attr or attr.value.decode() not in remaining:
                    continue
                name = attr.value.decode()
                members = {m.attributes['DW_AT_name'].value.decode(): m
                           for m in base(die.get_DIE_from_attribute('DW_AT_type')).iter_children()
                           if m.tag == 'DW_TAG_member' and 'DW_AT_name' in m.attributes}
                def pointee(member):
                    return base(members[member].get_DIE_from_attribute('DW_AT_type')).get_DIE_from_attribute('DW_AT_type')
                kind = count(pointee('type'))
                if kind in {1, 5, 9, 13}:
                    key = size(pointee('key')) if 'key' in members else count(pointee('key_size'))
                    rows.append(dict(object=str(obj), name=name, type=kind, key_size=key))
                remaining.remove(name)
        assert not remaining, (obj, sorted(remaining))
print(json.dumps(dict(key_sizes=sorted({r['key_size'] for r in rows}), maps=rows), indent=2))
