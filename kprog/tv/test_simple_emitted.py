"""Reject coherent changed native/JIT bytes and a changed accepted B in Lean."""
import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path
from extract_checked import decode
from emitted_sites import validate_emitted

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('exports', type=Path)
args = parser.parse_args()
original = sorted(args.exports.glob('*/emitted.bin'))[0].parent
_, metadata = decode((original/'checked.snapshot.bin').read_bytes())
site = validate_emitted((original/'emitted.bin').read_bytes(), metadata,
    *[(original/name).read_bytes() for name in
      ['native.bin', 'native.relocs', 'jit.bin', 'jit-addresses.bin', 'jit-lengths.bin']])[0]
for name, expected in [('coherent-native-store', 'native_is_certified'), ('checked-store', 'proof_is_checked')]:
    root = Path('build/simple-emitted-mutations')/name
    source = root/'exports'/original.name
    source.mkdir(parents=True, exist_ok=True)
    for file in original.iterdir():
        if file.is_file():
            shutil.copyfile(file, source/file.name)
    if name == 'coherent-native-store':
        native = bytearray((source/'native.bin').read_bytes()); native[52] ^= 1
        jit = bytearray((source/'jit.bin').read_bytes()); jit[site['jit_offset']+52] ^= 1
        (source/'native.bin').write_bytes(native); (source/'jit.bin').write_bytes(jit)
    else:
        checked = bytearray((source/'checked.snapshot.bin').read_bytes())
        checked[120+17*8] = 0xb7
        (source/'checked.snapshot.bin').write_bytes(checked)
    subprocess.run([sys.executable, 'extract_simple_emitted.py', str(root/'exports'),
        str(root/'certificate')], check=True)
    lean = root/'certificate'/('SimpleEmitted_'+original.name.replace('-', '_')+'.lean')
    line = next(index for index, text in enumerate(lean.read_text().splitlines(), 1)
                if text.startswith('theorem '+expected+' '))
    result = subprocess.run(['make', '--no-print-directory', 'simple-emitted-certificate',
        'SIMPLE_EMITTED_DIR='+str(root/'certificate')], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (root/'certificate.log').write_bytes(result.stdout)
    goal = b'native = SimpleCompiled.native' if name == 'coherent-native-store' else b'program = SimpleChecked.program'
    if not result.returncode or not re.search(rb':'+str(line).encode()+rb':\d+: error:', result.stdout) or \
            b'error: type mismatch' not in result.stdout or goal not in result.stdout:
        raise AssertionError('missing exact byte-identity theorem rejection: '+name)
    print(name+': metadata consistent, REJECTED by '+expected, flush=True)
print('actual emitted/native and accepted-B byte-identity negative certificates: PASS')
