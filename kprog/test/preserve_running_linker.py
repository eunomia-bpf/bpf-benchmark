"""Keep an already-running loader paired with its retained linker artifact.

This changes a deployment path, not the normal linker source or its options.
The caller holds the shared image lock; future production builds take EX.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('canonical', 'retained', 'loader', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    before = hashlib.sha256(args.canonical.read_bytes()).hexdigest()
    retained = args.retained.resolve(strict=True)
    binary = retained.parent / 'native-link.real'
    record = dict(recorded=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
                  canonical=str(args.canonical), previous_sha256=before,
                  retained=str(retained), retained_sha256=hashlib.sha256(retained.read_bytes()).hexdigest(),
                  retained_binary_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
                  loader=str(args.loader), loader_sha256=hashlib.sha256(args.loader.read_bytes()).hexdigest(),
                  scope='Artifact pairing for the pre-existing census; normal source remains unchanged. '
                        'Paired normal loader/linker publication requires image EX after existing users finish.')
    args.output.mkdir(parents=True, exist_ok=True)
    temporary = args.canonical.with_name(args.canonical.name + '.pairing')
    temporary.symlink_to(retained)
    os.replace(temporary, args.canonical)
    (args.output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')


if __name__ == '__main__':
    main()
