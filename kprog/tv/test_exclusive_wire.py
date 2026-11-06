"""Check the actual clang marker preserves the complete unsigned source PC."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import struct
import subprocess

subprocess.run(['build/test-exclusive-host'],check=True)
bad = subprocess.run(['build/test-exclusive-host','invalid'],capture_output=True,text=True)
if bad.returncode != 1 or 'must be 0 or 1' not in bad.stderr:
    raise ValueError('invalid host failure choice did not fail explicitly')

with Path('build/exclusive-input.bpf.o').open('rb') as stream:
    elf = ELFFile(stream)
    for name, pc in [('exclusive_site_16',16),('exclusive_site_high',0xfffffffc)]:
        symbols = elf.get_section_by_name('.symtab').get_symbol_by_name(name)
        if not symbols or len(symbols) != 1:
            raise ValueError('missing/ambiguous actual marker entry')
        symbol = symbols[0]
        section = elf.get_section(symbol['st_shndx'])
        data = section.data()[symbol['st_value']:symbol['st_value']+symbol['st_size']]
        if data != struct.pack('<BBhI',0xb7,0x90,5,pc) + bytes([0x95,0,0,0,0,0,0,0]):
            raise ValueError('clang changed the exact marker/return encoding')
print('actual clang kind5 marker: complete source PCs16/0xfffffffc, no helper/default value: PASS')
