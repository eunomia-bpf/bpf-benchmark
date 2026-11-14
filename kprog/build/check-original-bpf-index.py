#!/usr/bin/env python3
"""Catch byte/insn offset confusion and dropped map/call ELF relocations."""
import importlib.util
from pathlib import Path
import sys

spec = importlib.util.spec_from_file_location('index', Path(__file__).with_name('original-bpf-index.py'))
index = importlib.util.module_from_spec(spec)
spec.loader.exec_module(index)
native, original = map(Path, sys.argv[1:])
record = index.pair(native, original)
entry = next(f for f in record['functions'] if f['original']['name'] == 'native_frame')
assert entry['original']['section'] == 'frame-test' and entry['original']['offset'] == 0
assert len(entry['native']) == 1 and entry['native'][0]['section'] == 'frame-test'
maps = [r for r in record['relocations'] if r['target_symbol'] == 'frame_map']
calls = [r for r in record['relocations'] if r['target_symbol'] == 'bpf_tail_call']
assert maps and calls
for row in maps:
    assert row['relocation_type'] == 1 and row['target_section'] == '.maps'
    assert bytes.fromhex(row['site_bytes_hex'])[0] == 0x18
for row in calls:
    assert row['relocation_type'] == 10 and bytes.fromhex(row['site_bytes_hex'])[0] == 0x85
from elftools.elf.elffile import ELFFile
with original.open('rb') as stream:
    elf = ELFFile(stream)
    for row in maps + calls:
        data = elf.get_section_by_name(row['section']).data()
        assert data[row['instruction_slot'] * 8:][:16].hex() == row['site_bytes_hex']
try:
    index.pair(native, native)
except ValueError as error:
    assert 'expected original BPF ELF' in str(error)
else:
    raise AssertionError('native object was treated as original BPF instruction sites')
print('Original BPF map/call sites, function correspondence and ELF-kind regression PASS')
