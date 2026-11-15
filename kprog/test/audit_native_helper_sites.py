"""Inventory actual native-object helper sites through the linker's CFG analysis.

Proof-mode inventory does not establish a timed image's runtime map lowering.
The proof output stays in an anonymous descriptor; only observations persist.
"""
import argparse
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import subprocess


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    original = a.native.read_bytes()
    fd = os.memfd_create('native-helper-audit', os.MFD_CLOEXEC)
    try:
        command = list(map(str, [a.linker, '--input', a.native, '--symbol', a.symbol,
            '--mode', 'proof', '--show', '--output', Path('/proc/self/fd')/str(fd)]))
        result = subprocess.run(command, capture_output=True, text=True, pass_fds=(fd,))
        (a.output/'linker.stderr.txt').write_text(result.stderr)
        (a.output/'command.json').write_text(json.dumps(dict(command=command,
            returncode=result.returncode), indent=2)+'\n')
        result.check_returncode()
        sites = [json.loads(line.removeprefix('native-link-helper-site '))
                 for line in result.stderr.splitlines() if line.startswith('native-link-helper-site ')]
        if a.native.read_bytes() != original:
            raise ValueError('Native object changed during its helper audit')
        proof = Path('/proc/self/fd', str(fd)).read_bytes()
        record = dict(native=str(a.native), symbol=a.symbol,
            native_sha256=hashlib.sha256(original).hexdigest(),
            linker_sha256=hashlib.sha256(a.linker.read_bytes()).hexdigest(),
            proof_bytes=len(proof), proof_sha256=hashlib.sha256(proof).hexdigest(),
            helper_sites=sites, helper_counts=dict(Counter(site['helper'] for site in sites)),
            scope='Actual current native object and normal proof CFG recognition; no timed-image/map-LTO/kernel execution certification')
        (a.output/'result.json').write_text(json.dumps(record, indent=2)+'\n')
        print(json.dumps(record), flush=True)
    finally:
        os.close(fd)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('native', 'linker', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--symbol', required=True)
    main(parser.parse_args())
