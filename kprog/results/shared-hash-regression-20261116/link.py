#!/usr/bin/env python3
"""Diagnostic adapter: image linker plus the retained pre-f45 hash body.

Proof emission stays with the image linker. Kernel emission changes only calls
to the raw typed hash target; generic LRU map ops and their ref writes stay.
"""
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile


def copied_hash(blob, relocs, maps, abi, plan, code, sites):
    targets = {m['target_addr'] for m in plan['lookup_maps']
               if m['kind'] in ('hash', 'lru_hash', 'percpu_hash', 'hash_of_maps')}
    rows = list(struct.iter_unpack('<IIQ', relocs))
    calls = [(at, target) for at, kind, target in rows if kind == 1 and target in targets]
    if not calls:
        return blob, relocs, maps, abi, dict(redirected_calls=0, shift=0)
    # One boot's typed hash variants all call the same raw htab lookup. Their
    # distinct value/percpu/ref-bit postprocessing is outside the copied body.
    assert len({target for _, target in calls}) == 1
    assert len(code) == 2444 and code[-10:] == bytes.fromhex('e8000000004883c408c3')
    shift = len(code) + 5
    output = bytearray(b'\xe9' + struct.pack('<i', len(code)) + code + blob)
    removed = {at for at, _ in calls}
    for at, _ in calls:
        assert blob[at:at + 5] == bytes.fromhex('e800000000')
        struct.pack_into('<i', output, at + shift + 1, 5 - (at + shift + 5))
    shifted = [(at + shift, kind, target + shift if kind == 12 else target)
               for at, kind, target in rows if at not in removed]
    shifted.append((5 + len(code) - 10, 1, calls[0][1]))
    shifted.sort()
    relocs = b''.join(struct.pack('<IIQ', *row) for row in shifted)
    maps = ''.join(f'{name}\t{int(at) + shift}\n'
                   for name, at in (line.split('\t') for line in maps.splitlines()))
    headers, loads = [], [[0, 5, 65535]] + [[at + 5, size, dst] for at, size, dst in sites]
    for line in abi.splitlines():
        key, value = line.split('\t')
        if key == 'load_site':
            at, size, dst = map(int, value.split(','))
            loads.append([at + shift, size, dst])
        else:
            headers.append(line)
    abi = '\n'.join(headers) + '\n' + ''.join(
        f'load_site\t{at},{size},{dst}\n' for at, size, dst in sorted(loads))
    return bytes(output), relocs, maps, abi, dict(
        redirected_calls=len(calls), original_calls=calls, shift=shift,
        copied_range=[5, shift], fallback_offset=5 + len(code) - 10)


def main(argv):
    result = subprocess.run(['/usr/local/bin/native-link', *argv])
    if result.returncode or '--mode' not in argv or argv[argv.index('--mode') + 1] != 'kernel':
        return result.returncode
    args = {argv[i]: argv[i + 1] for i in range(len(argv) - 1) if argv[i].startswith('--')}
    here = Path(__file__).absolute().parent
    capture = Path(tempfile.mkdtemp(prefix='link-', dir=here / 'captures'))
    files = {name: Path(args[key]) for name, key in [
        ('blob', '--output'), ('relocs', '--output-relocs'),
        ('maps', '--output-map-patches'), ('abi', '--output-abi')]}
    for name, source in files.items():
        shutil.copyfile(source, capture / ('shared.' + name))
    shutil.copyfile(args['--link-plan'], capture / 'link-plan.json')
    shutil.copyfile(args['--input'], capture / 'entry.proof.o')
    report = dict(mode=Path(sys.argv[0]).name, argv=argv, redirected_calls=0)
    if report['mode'] == 'copy-link':
        transformed = copied_hash(
            files['blob'].read_bytes(), files['relocs'].read_bytes(),
            files['maps'].read_text(), files['abi'].read_text(),
            json.loads(Path(args['--link-plan']).read_text()),
            (here / 'copied-hash.bin').read_bytes(),
            json.loads((here / 'copied-hash-sites.json').read_text()))
        for name, value in zip(files, transformed[:4]):
            if isinstance(value, bytes):
                files[name].write_bytes(value)
            else:
                files[name].write_text(value)
        report.update(transformed[4])
    for name, source in files.items():
        shutil.copyfile(source, capture / ('installed-input.' + name))
    (capture / 'adapter.json').write_text(json.dumps(report, indent=2) + '\n')
    print('hash diagnostic: ' + json.dumps(report), file=sys.stderr)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
