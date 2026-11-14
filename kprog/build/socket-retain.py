#!/usr/bin/env python3
"""Retain socket compiler outputs and logs without copying application source."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tarfile


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def git(*args):
    return subprocess.check_output(['git', *args], text=True).strip()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--raw', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--features', required=True)
    parser.add_argument('--log', type=Path, required=True)
    args = parser.parse_args()
    snapshot = args.raw/'build-evidence'
    shutil.copytree(args.build, snapshot)  # Existing evidence is never replaced.
    rows = json.loads((snapshot/'proofs/report.json').read_text())
    repo = Path(__file__).resolve().parents[2]
    source = repo/'vendor/repos/cilium/bpf/bpf_sock.c'
    release = (Path('/workspaces/.agent-state/kprog-ck/build-x86')/
               'include/config/kernel.release').read_text().strip()
    btf_header = repo/'vendor/bpf/targets/x86'/release/'vmlinux.h'
    archive = args.output.with_suffix('.tar.gz')
    with tarfile.open(archive, 'x:gz') as target:
        target.add(args.raw, arcname=args.raw.name)
    # Packaging verification compares original bytes, not experiment validity.
    files = 0
    with tarfile.open(archive) as target:
        for item in target.getmembers():
            if item.isfile():
                original = args.raw.parent/item.name
                with target.extractfile(item) as stream:
                    if hashlib.sha256(stream.read()).hexdigest() != digest(original):
                        raise ValueError('archive bytes differ: '+item.name)
                files += 1
    receipt = dict(
        recorded_at=datetime.now(timezone.utc).isoformat(),
        tree_head=git('rev-parse', 'HEAD'), raw=str(args.raw),
        compiler_commit=git('log', '-1', '--format=%H', '--', str(repo/'kprog/build/socket-context-lower.cpp')),
        upstream_revision=git('-C', str(source.parents[1]), 'rev-parse', 'HEAD'),
        upstream_source=str(source.relative_to(repo)), source_sha256=digest(source),
        kernel_revision=git('-C', str(repo/'vendor/linux-framework'), 'rev-parse', 'HEAD'),
        target_btf_header=str(btf_header.relative_to(repo)), target_btf_sha256=digest(btf_header),
        features=args.features, frontend_target='bpf', native_target='x86_64',
        lowered_access_counts_from_log=[int(line.rsplit(':', 1)[1])
                                       for line in args.log.read_text().splitlines()
                                       if line.startswith('socket context accesses lowered:')],
        build_log=str(args.log),
        expected_error_cases=['dynamic offset', 'unmapped field', 'field-address escape'],
        offline_link_results=rows, verifier_submissions=0, native_installs=0,
        application_execution=False, default_path_changed=False,
        limits=['Compiler/host subset only; actual frozen runtime config remains to match.',
                'No application-decision or throughput equivalence certified.',
                'Known unsupported context kinds and general CO-RE still need implementation.',
                'Original-program helper deployment remains with lane verified.'],
        archive=dict(path=str(archive.relative_to(repo)), bytes=archive.stat().st_size,
                     sha256=digest(archive), files_byte_compared=files))
    with args.output.open('x') as target:
        json.dump(receipt, target, indent=2)
        target.write('\n')


if __name__ == '__main__':
    main()
