#!/usr/bin/env python3
"""Publish small archive parts while preserving the full original under raw."""
import argparse
import hashlib
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--receipt', type=Path, required=True)
    parser.add_argument('--raw-archive', type=Path, required=True)
    args = parser.parse_args()
    record = json.loads(args.receipt.read_text())
    archive = Path(record['archive']['path'])
    if args.raw_archive.exists():
        raise FileExistsError(args.raw_archive)
    parts = []
    combined = hashlib.sha256()
    with archive.open('rb') as source:
        while data := source.read(40 * 1024 * 1024):
            part = archive.with_name(archive.name + '.part%03d' % len(parts))
            with part.open('xb') as output:
                output.write(data)
            actual = part.read_bytes()
            if actual != data:
                raise ValueError('archive part bytes differ: ' + str(part))
            combined.update(actual)
            parts.append(dict(path=str(part), bytes=len(actual), sha256=hashlib.sha256(actual).hexdigest()))
    if combined.hexdigest() != record['archive']['sha256']:
        raise ValueError('concatenated parts differ from original archive SHA256')
    if sum(part['bytes'] for part in parts) != record['archive']['bytes']:
        raise ValueError('concatenated parts differ from original archive length')
    archive.rename(args.raw_archive)
    record['archive'].update(path=str(args.raw_archive), parts=parts,
                             reconstruction='Concatenate parts in listed order to recover the full tar.gz; verify original SHA256.')
    args.receipt.write_text(json.dumps(record, indent=2) + '\n')


if __name__ == '__main__':
    main()
