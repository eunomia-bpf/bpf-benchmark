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
parser.add_argument('--program', choices=['simple', 'simple_packet'], default='simple')
args = parser.parse_args()
packet = args.program == 'simple_packet'
prefix = 'Packet' if packet else 'Simple'
store = 40 if packet else 52
proof_store = 14 if packet else 17
original = sorted(args.exports.glob('*/emitted.bin'))[0].parent
_, metadata = decode((original/'checked.snapshot.bin').read_bytes())
site = validate_emitted((original/'emitted.bin').read_bytes(), metadata,
    *[(original/name).read_bytes() for name in
      ['native.bin', 'native.relocs', 'jit.bin', 'jit-addresses.bin', 'jit-lengths.bin']])[0]
for name, expected in [('coherent-native-store', 'native_is_certified'), ('checked-store', 'proof_is_checked')]:
    root = Path('build/'+args.program.replace('_', '-')+'-emitted-mutations')/name
    source = root/'exports'/original.name
    source.mkdir(parents=True, exist_ok=True)
    for file in original.iterdir():
        if file.is_file():
            shutil.copyfile(file, source/file.name)
    if name == 'coherent-native-store':
        native = bytearray((source/'native.bin').read_bytes()); native[store] ^= 1
        jit = bytearray((source/'jit.bin').read_bytes()); jit[site['jit_offset']+store] ^= 1
        (source/'native.bin').write_bytes(native); (source/'jit.bin').write_bytes(jit)
    else:
        checked = bytearray((source/'checked.snapshot.bin').read_bytes())
        checked[120+proof_store*8] = 0xb7
        (source/'checked.snapshot.bin').write_bytes(checked)
    subprocess.run([sys.executable, 'extract_simple_emitted.py', str(root/'exports'),
        str(root/'certificate'), '--program', args.program], check=True)
    lean = root/'certificate'/(prefix+'Emitted_'+original.name.replace('-', '_')+'.lean')
    line = next(index for index, text in enumerate(lean.read_text().splitlines(), 1)
                if text.startswith('theorem '+expected+' '))
    result = subprocess.run(['make', '--no-print-directory', ('simple-packet-emitted-certificate' if packet else 'simple-emitted-certificate'),
        ('PACKET_EMITTED_DIR=' if packet else 'SIMPLE_EMITTED_DIR=')+str(root/'certificate')], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (root/'certificate.log').write_bytes(result.stdout)
    goal = ('native = '+prefix+'Compiled.native').encode() if name == 'coherent-native-store' else (b'program = PacketCompiled.program' if packet else b'program = SimpleChecked.program')
    if not result.returncode or not re.search(rb':'+str(line).encode()+rb':\d+: error:', result.stdout) or \
            b'error: type mismatch' not in result.stdout or goal not in result.stdout:
        raise AssertionError('missing exact byte-identity theorem rejection: '+name)
    print(name+': metadata consistent, REJECTED by '+expected, flush=True)
print('actual emitted/native and accepted-B byte-identity negative certificates: PASS')
