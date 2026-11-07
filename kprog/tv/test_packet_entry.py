"""Coherent entry mutations must fail the semantic certificate, with fresh dependents."""
import os
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent
FORMAL = ROOT.parent/'formal'
compiled = (ROOT/'build/simple-packet-arm64/PacketCompiled.lean').read_text()
modules = ['PacketCompiled', 'PacketGuardCertificate', 'PacketEntryCertificate',
           'PacketCheckedPlatform', 'PacketCheckedBlocks']
cases = [
    ('native-ldp-destination', ['native'], 0, 0x08, 0x09,
     'PacketEntryCertificate', 'decode0'),
    ('proof-spill-address', ['proof', 'program'], 10, 0xf8, 0xf0,
     'PacketEntryCertificate', 'prefix_instruction'),
    ('proof-context-offset', ['proof', 'program'], 18, 4, 8,
     'PacketCheckedPlatform', 'second_virtual'),
]
for name, arrays, offset, old, new, expected_module, expected_theorem in cases:
    directory = ROOT/'build/packet-entry-mutations'/name
    directory.mkdir(parents=True, exist_ok=True)
    source = compiled
    for array in arrays:
        pattern = r'(def '+array+r' : Array KProgTV.Byte := #\[)([^\]]*)(\])'
        matched = re.search(pattern, source)
        if not matched:
            raise ValueError('missing exact generated array '+array)
        values = [int(x, 0) for x in matched[2].split(',')]
        if values[offset] != old:
            raise ValueError('mutation input changed: '+name)
        values[offset] = new
        source = source[:matched.start()]+matched[1]+','.join(hex(x) for x in values)+matched[3]+source[matched.end():]
    for module in modules:
        text = source if module == 'PacketCompiled' else (ROOT/(module+'.lean')).read_text()
        (directory/(module+'.lean')).write_text(text)
        # Only these known derived outputs are removed. Never import a cached
        # dependent built against a different PacketCompiled definition.
        (directory/(module+'.olean')).unlink(missing_ok=True)
    environment = dict(os.environ)
    environment['LEAN_PATH'] = ':'.join(str(x) for x in [directory, ROOT/'build',
        ROOT/'build/simple-checked', ROOT/'build/simple-arm64', ROOT/'build/simple-packet-arm64'])
    lines = (directory/(expected_module+'.lean')).read_text().splitlines()
    start = next(i for i, line in enumerate(lines, 1) if line.startswith('theorem '+expected_theorem+' '))
    end = next((i for i, line in enumerate(lines, 1) if i > start and line.startswith(('theorem ', 'def '))), len(lines)+1)
    logs, rejected = [], False
    for module in modules:
        result = subprocess.run(['lake', 'env', 'lean', '-R', str(directory), '-o',
            str(directory/(module+'.olean')), str(directory/(module+'.lean'))],
            cwd=FORMAL, env=environment, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        logs.append(result.stdout)
        if result.returncode:
            failures = re.findall(rb'\.lean:(\d+):\d+: error:', result.stdout)
            if module != expected_module or not any(start <= int(line) < end for line in failures):
                (directory/'certificate.log').write_bytes(b''.join(logs))
                raise AssertionError('failed outside expected semantic theorem: '+name)
            rejected = True
            break
    (directory/'certificate.log').write_bytes(b''.join(logs))
    if not rejected:
        raise AssertionError('accepted coherent mutation: '+name)
    print(f'{name}: REJECTED by {expected_module}.{expected_theorem}; all preceding dependents rebuilt', flush=True)
print('actual entry/context/private-spill semantic mutation certificates: PASS')
