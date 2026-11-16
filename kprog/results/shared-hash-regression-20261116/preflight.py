"""Check the adapter's branch, relocation and ABI contract before a guest."""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys

HERE = Path(__file__).absolute().parent
spec = importlib.util.spec_from_file_location('hash_adapter', HERE / 'link.py')
adapter = importlib.util.module_from_spec(spec)
spec.loader.exec_module(adapter)
raw = Path(sys.argv[1])
code = (raw / 'katran.copied-hash.bin').read_bytes()
sites = json.loads((raw / 'katran.copied-hash-sites.json').read_text())
# A call, image pointer, tail-count and a literal map slot exercise the records
# whose fields have different meanings under a uniform image displacement.
blob = bytes.fromhex('e800000000') + bytes(27)
relocs = b''.join(struct.pack('<IIQ', *row) for row in [(0, 1, 1234), (8, 12, 29), (16, 10, 0)])
abi = 'version\tnative-link-abi-v2\ncallee_saved_mask\t3\nload_site\t0,5,65535\n'
plan = dict(lookup_maps=[dict(kind='hash', target_addr=1234)])
new, rel, maps, meta, report = adapter.copied_hash(blob, relocs, 'map\t24\n', abi, plan, code, sites)
shift = 2449
assert 5 + struct.unpack_from('<i', new, 1)[0] == shift
assert shift + 5 + struct.unpack_from('<i', new, shift + 1)[0] == 5
assert new[5:shift] == code and new[shift + 5:] == blob[5:]
assert list(struct.iter_unpack('<IIQ', rel)) == [(2439, 1, 1234), (2457, 12, 2478), (2465, 10, 0)]
assert maps == 'map\t2473\n' and 'callee_saved_mask\t3\n' in meta
assert meta.count('load_site\t') == len(sites) + 2
assert adapter.copied_hash(blob, b'', '', abi, plan, code, sites) == (blob, b'', '', abi, dict(redirected_calls=0, shift=0))
# The retained copy has no address-dependent relative references except its
# one fallback E8 slot. Disassemble it so the whole fixed-length body remains
# available for independent inspection alongside the exact 123 ABI sites.
with (raw / 'copied-hash.disassembly.txt').open('w') as output:
    subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', str(raw / 'katran.copied-hash.bin')], stdout=output, check=True)
print(json.dumps(dict(transformation='pass', retained_bytes=len(code), abi_sites=len(sites),
                     branch_targets=[shift, 5], relocation_fields='pass', no_hash_passthrough='pass'), indent=2))
