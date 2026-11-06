"""Reject stale identity, truncated snapshots and mismatched environment records."""
import argparse
import struct
import subprocess
from pathlib import Path
from extract_checked import decode, emit

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('simple', type=Path)
parser.add_argument('environment_log', type=Path)
args = parser.parse_args()
simple = args.simple.read_bytes()
program, metadata = decode(simple)
assert len(program) == 29*8 and metadata['binding'][9] == 84
records = [bytes.fromhex(line.split()[1]) for line in args.environment_log.read_text().splitlines()
           if line.startswith('TV_CHECKED_ENV ')]
assert len(records) == 1, 'real map/helper snapshot required'
environment = records[0]
_, resolved = decode(environment)
assert len(resolved['maps']) == 1 and len(resolved['helpers']) == 1

def changed(data, offset, value):
    copy = bytearray(data)
    struct.pack_into('<I', copy, offset, value)
    return copy

map_start = 120 + len(decode(environment)[0]) + 16
helper_start = map_start + 40
cases = {
    'truncated header': simple[:119],
    'truncated body': simple[:-1],
    'extra bytes': simple + b'\0',
    'wrong version': changed(simple, 0, 2),
    'wrong program extent': changed(simple, 4, 28),
    'stale generation': changed(simple, 20, metadata['generation']+1),
    'wrong entry': changed(simple, 32, 4),
    'wrong ABI': changed(simple, 36, 2),
    'missing original identity': changed(simple, 108, 0),
    'missing environment map': changed(environment, 12, 0),
    'map site differs': changed(environment, map_start, 1),
    'map pointer differs': changed(environment, map_start+32, 0),
    'helper site differs': changed(environment, helper_start, 4),
    'helper identity differs': changed(environment, helper_start+4, 0),
}
for name, data in cases.items():
    try:
        decode(data)
    except ValueError:
        print(name + ': REJECTED')
    else:
        raise AssertionError('accepted negative: '+name)
print('actual simple and resolved map/helper snapshots: PASS;14 corruptions rejected')

for name, pc, opcode in [('context-width', 0, 0x79), ('erased-store', 17, 0xb7),
                         ('wrong-redirect', 27, 0x95), ('erased-stub-exit', 28, 0x05)]:
    mutant = bytearray(simple)
    mutant[120+pc*8] = opcode
    directory = Path('build/checked-mutations')/name
    emit(mutant, directory)
    result = subprocess.run(['make','--no-print-directory','checked-certificate',
        'SIMPLE_CHECKED_DIR='+str(directory)], capture_output=True)
    (directory/'certificate.log').write_bytes(result.stdout+result.stderr)
    if not result.returncode or b'SimpleChecked.lean:' not in result.stdout or b'error:' not in result.stdout:
        raise AssertionError('changed checked instruction not rejected semantically: '+name)
    print(name+': REJECTED by exact captured-byte Lean certificate')
