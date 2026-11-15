"""Inventory actual helper sites and optionally replay a saved runtime link plan.

Outputs stay in anonymous descriptors; only observations persist. Replaying a
plan is artifact analysis, not kernel execution or a timed-workload result.
"""
import argparse
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    original = a.native.read_bytes()
    linker_hash = hashlib.sha256(a.linker.read_bytes()).hexdigest()
    plan_bytes = a.link_plan.read_bytes() if a.link_plan else None
    descriptors = []
    commands = []

    def anonymous(name):
        fd = os.memfd_create(name, os.MFD_CLOEXEC)
        descriptors.append(fd)
        return Path('/proc/self/fd')/str(fd)

    def run(command, label):
        command = list(map(str, command))
        result = subprocess.run(command, capture_output=True, text=True,
                                pass_fds=tuple(descriptors))
        (a.output/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command, returncode=result.returncode))
        (a.output/'command.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return [json.loads(line.removeprefix('native-link-helper-site '))
                for line in result.stderr.splitlines()
                if line.startswith('native-link-helper-site ')]

    try:
        proof = anonymous('native-helper-proof')
        sites = run([a.linker, '--input', a.native, '--symbol', a.symbol,
                     '--mode', 'proof', '--show', '--output', proof], 'linker')
        proof_bytes = proof.read_bytes()
        record = dict(native=str(a.native), symbol=a.symbol,
            native_sha256=hashlib.sha256(original).hexdigest(),
            linker_sha256=linker_hash,
            proof_bytes=len(proof_bytes), proof_sha256=hashlib.sha256(proof_bytes).hexdigest(),
            helper_sites=sites, helper_counts=dict(Counter(site['helper'] for site in sites)),
            scope='Current object/proof CFG; no timed-image/map-LTO/kernel execution certification')
        if a.link_plan:
            blob, relocs, patches, abi = [anonymous('native-helper-'+n)
                                        for n in ('blob', 'relocs', 'patches', 'abi')]
            runtime_sites = run([a.linker, '--input', proof, '--symbol', a.symbol,
                '--mode', 'kernel', '--link-plan', a.link_plan, '--show',
                '--output', blob, '--output-relocs', relocs,
                '--output-map-patches', patches, '--output-abi', abi], 'kernel')
            code, raw_relocs = blob.read_bytes(), relocs.read_bytes()
            # iter_unpack rejects truncated records instead of silently dropping bytes.
            rows = [dict(offset=offset, kind=kind, target=target)
                    for offset, kind, target in struct.iter_unpack('<IIQ', raw_relocs)]
            plan = json.loads(plan_bytes)
            names = {}
            for fact in plan['helpers']:
                names.setdefault(fact['addr'], []).append(fact['name'])
            for row in rows:
                row['helper_names'] = sorted(names.get(row['target'], []))
            record['runtime'] = dict(link_plan=str(a.link_plan),
                link_plan_sha256=hashlib.sha256(plan_bytes).hexdigest(),
                blob_bytes=len(code), blob_sha256=hashlib.sha256(code).hexdigest(),
                relocs_bytes=len(raw_relocs), relocs_sha256=hashlib.sha256(raw_relocs).hexdigest(),
                relocations=rows, map_patches=patches.read_text(), abi=abi.read_text(),
                helper_sites=runtime_sites,
                helper_counts=dict(Counter(site['helper'] for site in runtime_sites)),
                lookup_maps=plan['lookup_maps'],
                scope='Normal proof-to-kernel replay of supplied facts; compare hashes with captured run to establish identity; no kernel execution')
        if a.native.read_bytes() != original:
            raise ValueError('Native object changed during its helper audit')
        if hashlib.sha256(a.linker.read_bytes()).hexdigest() != linker_hash:
            raise ValueError('Linker changed during its helper audit')
        if a.link_plan and a.link_plan.read_bytes() != plan_bytes:
            raise ValueError('Link plan changed during its helper audit')
        (a.output/'result.json').write_text(json.dumps(record, indent=2)+'\n')
        print(json.dumps(record), flush=True)
    finally:
        for fd in descriptors:
            os.close(fd)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('native', 'linker', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--symbol', required=True)
    parser.add_argument('--link-plan', type=Path)
    main(parser.parse_args())
