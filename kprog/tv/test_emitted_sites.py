"""Reject stale sites, wrong RX ranges and changed bytes even with a decoy copy."""
import argparse
import struct
from pathlib import Path
from extract_checked import decode
from emitted_sites import validate_emitted

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('directory', type=Path)
parser.add_argument('--native-bytes', type=int, default=84)
parser.add_argument('--store-offset', type=int, default=52)
args = parser.parse_args()
if args.native_bytes <= 4 or args.native_bytes % 4 or not 0 <= args.store_offset < args.native_bytes:
    raise ValueError('valid native extent/store fixture offset required')
records = sorted(args.directory.glob('*/emitted.bin'))
if len(records) != 2:
    raise ValueError('two actual ARM simple bound-load captures required')
observed = []
for record in records:
    path = record.parent
    data = record.read_bytes()
    _, metadata = decode((path/'checked.snapshot.bin').read_bytes())
    values = [(path/name).read_bytes() for name in
        ['native.bin', 'native.relocs', 'jit.bin', 'jit-addresses.bin', 'jit-lengths.bin']]
    result = validate_emitted(data, metadata, *values)
    if len(result) != 1 or result[0]['native_size'] != args.native_bytes:
        raise ValueError('actual complete simple entry required')
    observed.append(result[0])
    print(f'{path.name}: actual callback RX entry {result[0]["entry_address"]:#x}, '
          f'JIT offset {result[0]["jit_offset"]}, exact{args.native_bytes}B/GEN{result[0]["generation"]}: PASS')

    def changed(offset, fmt, value):
        copy = bytearray(data)
        struct.pack_into(fmt, copy, offset, value)
        return copy

    cases = {
        'truncated header': (data[:15], values),
        'truncated site': (data[:-1], values),
        'extra site': (data+data[-24:], values),
        'wrong version': (changed(0, '<I', 2), values),
        'wrong site count': (changed(4, '<I', 2), values),
        'wrong source ID': (changed(8, '<I', 0), values),
        'nonzero reserved': (changed(12, '<I', 1), values),
        'wrong blob ID': (changed(16, '<I', 1), values),
        'stale generation': (changed(20, '<I', result[0]['generation']+1), values),
        'wrong native extent': (changed(24, '<I', args.native_bytes-4), values),
        'wrong ABI': (changed(28, '<I', 1), values),
        'absent RX entry': (changed(32, '<Q', 0), values),
        'RX outside function': (changed(32, '<Q', result[0]['entry_address']+len(values[2])), values),
        'shifted RX entry': (changed(32, '<Q', result[0]['entry_address']+4), values),
    }
    altered = list(values)
    jit = bytearray(values[2]); jit[result[0]['jit_offset']+args.store_offset] ^= 1
    altered[2] = bytes(jit)
    cases['changed emitted store'] = (data, altered)
    # A byte search would find this correct decoy; the reported actual entry
    # must still reject because its real store instruction was changed.
    decoy = list(altered); decoy[2] += values[0]
    decoy[4] = struct.pack('<I', len(decoy[2]))
    cases['changed entry with intact decoy'] = (data, decoy)
    wrong_layout = list(values); wrong_layout[4] = struct.pack('<I', len(values[2])-4)
    cases['truncated actual JIT layout'] = (data, wrong_layout)
    wrong_native = list(values); wrong_native[0] = values[0][:-4]
    cases['wrong native program'] = (data, wrong_native)
    for name, (candidate, inputs) in cases.items():
        try:
            validate_emitted(candidate, metadata, *inputs)
        except ValueError:
            print(f'{path.name}/{name}: REJECTED')
        else:
            raise AssertionError('accepted mismatch: '+name)
if observed[0]['generation'] == observed[1]['generation'] or \
        observed[0]['entry_address'] == observed[1]['entry_address']:
    raise ValueError('actual distinct generations/RX addresses required')
print('actual entry binding: 2 captures PASS; 36 corruptions REJECTED')
