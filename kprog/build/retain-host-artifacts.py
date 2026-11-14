#!/usr/bin/env python3
"""Retain explicitly selected compiler/replay artifacts and their JSON reports."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil
import tarfile


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--raw', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--protocol', required=True)
    parser.add_argument('--scope', default='Host compiler/replay artifacts only; no kernel submission, native installation or application equal-work claim.')
    parser.add_argument('--build', type=Path)
    parser.add_argument('--input', action='append', type=Path, default=[])
    parser.add_argument('--report', action='append', type=Path, default=[])
    args = parser.parse_args()
    if args.build:
        shutil.copytree(args.build, args.raw / 'build-evidence')
    inputs = []
    if args.input:
        target = args.raw / 'input-evidence'
        target.mkdir()
        for path in args.input:
            with (target / path.name).open('xb') as stream:
                stream.write(path.read_bytes())
            inputs.append(dict(path=str(path), sha256=digest(path)))
    reports = [dict(path=str(path), sha256=digest(path), data=json.loads(path.read_text())) for path in args.report]
    archive = args.output.with_suffix('.tar.gz')
    with tarfile.open(archive, 'x:gz') as target:
        target.add(args.raw, arcname=args.raw.name)
    files = 0
    with tarfile.open(archive) as target:
        for member in target.getmembers():
            if member.isfile():
                with target.extractfile(member) as stream:
                    if hashlib.sha256(stream.read()).hexdigest() != digest(args.raw.parent / member.name):
                        raise ValueError('archive bytes differ: ' + member.name)
                files += 1
    result = dict(recorded_at=datetime.now(timezone.utc).isoformat(), protocol_commit=args.protocol,
                  raw=str(args.raw), inputs=inputs, reports=reports,
                  scope=args.scope,
                  archive=dict(path=str(archive), bytes=archive.stat().st_size, sha256=digest(archive), files_byte_compared=files))
    with args.output.open('x') as output:
        json.dump(result, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
