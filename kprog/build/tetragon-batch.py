#!/usr/bin/env python3
"""Compile every upstream object named by a retained Tetragon manifest."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shlex
import subprocess
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, required=True)
    parser.add_argument('--raw', type=Path, required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--socket-build', type=Path, required=True)
    parser.add_argument('--workers', type=int, default=4)
    parser.add_argument('--dry-run', action='store_true')
    args = parser.parse_args()
    upstream = ROOT / 'vendor/repos/tetragon/bpf'
    manifest = json.loads(args.manifest.read_text())
    rows = []
    for unit in sorted({row['native_object'].removesuffix('.native.o') for row in manifest['objects']}):
        stem, _, suffix = unit.rpartition('_')
        if not (suffix.startswith('v') and suffix[1:].isdigit()):
            stem = unit
        # These aliases are the explicit source prerequisites in upstream's
        # DEFINE_VARIANT and non-variant dependency rules.
        if stem in ('bpf_multi_enforcer', 'bpf_fmodret_enforcer'):
            stem = 'bpf_enforcer'
        elif stem.startswith('bpf_multi_'):
            stem = stem.replace('bpf_multi_', 'bpf_generic_', 1)
        sources = [upstream / directory / (stem + '.c') for directory in ('process', 'cgroup', 'test')]
        sources = [source for source in sources if source.is_file()]
        if len(sources) != 1:
            raise ValueError('ambiguous/missing upstream source for ' + unit)
        reference = ROOT / 'vendor/build/x86/tetragon' / (unit + '.o')
        with reference.open('rb') as stream:
            elf = ELFFile(stream)
            sections = [section.name for section in elf.iter_sections()
                        if section['sh_flags'] & 4 and section.name != '.text']
        command = ['make', '-f', str(HERE / 'Makefile'), 'upstream-tetragon-link',
                   'SOCKET_BUILD=' + str(args.socket_build), 'TETRAGON_UNIT=' + unit,
                   'TETRAGON_SOURCE=' + str(sources[0]), 'TETRAGON_SAME_BUILD=' + str(args.build / unit),
                   'TETRAGON_SECTION_ARGS=' + shlex.join([item for section in sections
                                                         for item in ('--section-prefix', section)])]
        rows.append(dict(unit=unit, source=str(sources[0]), source_sha256=digest(sources[0]),
                         reference=str(reference), reference_sha256=digest(reference),
                         entry_sections=sections, command=command))
    record = dict(manifest=str(args.manifest), manifest_sha256=digest(args.manifest), workers=args.workers,
                  kernel_btf_sha256=digest(Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')),
                  started_at=datetime.now(timezone.utc).isoformat(), rows=rows,
                  scope='Unchanged-source host compilation and offline proof generation; no native installation or equal-work claim.')
    if args.dry_run:
        print(json.dumps(record, indent=2))
        return
    args.raw.mkdir(parents=True, exist_ok=True)
    report = args.raw / 'report.json'
    report.write_text(json.dumps(record, indent=2) + '\n')

    def run(row):
        with (args.raw / (row['unit'] + '.log')).open('x') as log:
            result = subprocess.run(row['command'], cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
        return row, result.returncode

    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        for future in as_completed([pool.submit(run, row) for row in rows]):
            row, status = future.result()
            row.update(returncode=status, finished_at=datetime.now(timezone.utc).isoformat())
            report.write_text(json.dumps(record, indent=2) + '\n')
            print(json.dumps(dict(unit=row['unit'], returncode=status)), flush=True)
    record['finished_at'] = datetime.now(timezone.utc).isoformat()
    report.write_text(json.dumps(record, indent=2) + '\n')
    if any(row['returncode'] for row in rows):
        raise SystemExit(1)


if __name__ == '__main__':
    main()
