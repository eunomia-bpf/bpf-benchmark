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


def attribute_jit(a, code, rows, patches):
    """Join only retained source instructions after matching the installed bytes."""
    capture = json.loads(a.jit_capture.read_text())
    program, = [p for p in capture['programs'] if p['id'] == a.jit_program]
    installed = (a.jit_capture.parent/program['binary']).read_bytes()
    if hashlib.sha256(installed).hexdigest() != program['sha256']:
        raise ValueError('Live JIT capture differs from metadata')
    mask = bytearray(b'\1'*len(code))
    for row in rows:
        if row['kind'] != 1:
            raise ValueError('JIT byte matching needs an explicit mask for this relocation kind')
        mask[row['offset']+1:row['offset']+5] = b'\0'*4
    for line in patches.splitlines():
        _, offset = line.split('\t')
        offset = int(offset)
        mask[offset:offset+8] = b'\0'*8
    candidates = [base for base in range(len(installed)-len(code)+1)
                  if all(not keep or installed[base+i] == value
                         for i, (keep, value) in enumerate(zip(mask, code)))]
    if len(candidates) != 1:
        differences = [(base, [i for i, (keep, value) in enumerate(zip(mask, code))
                              if keep and installed[base+i] != value])
                       for base in range(len(installed)-len(code)+1)]
        best, changed = min(differences, key=lambda row: len(row[1]))
        (a.output/'jit-match-failure.json').write_text(json.dumps(dict(
            payload_sha256=hashlib.sha256(code).hexdigest(), best_start=best,
            differences=[dict(offset=i, template=code[i], installed=installed[best+i])
                         for i in changed]), indent=2)+'\n')
        raise ValueError('No unique installed payload match: '+str(candidates))
    base, = candidates
    def source_rows(label):
        return [json.loads(line.split(' ', 1)[1])
                for line in (a.output/(label+'.stderr.txt')).read_text().splitlines()
                if line.startswith('native-link-source-map ')]
    proof = {row['output_offset']: row for row in source_rows('linker')}
    intervals = []
    for row in source_rows('kernel'):
        source = proof.get(row['input_offset'])
        if source is not None:
            intervals.append(dict(start=base+row['output_offset'],
                end=base+row['output_offset']+row['length'],
                symbol=source['symbol'], section=source['section'],
                input_offset=source['input_offset'], symbol_offset=source['symbol_offset']))
    intervals.sort(key=lambda row: row['start'])
    if any(a['end'] > b['start'] for a, b in zip(intervals, intervals[1:])):
        raise ValueError('Joined source instructions overlap')
    observation = dict(capture=str(a.jit_capture), program=program['id'],
        installed_bytes=len(installed), installed_sha256=program['sha256'],
        payload_start=base, payload_bytes=len(code),
        unmasked_bytes=sum(mask), relocation_masked_bytes=len(mask)-sum(mask),
        matched_unmasked_bytes=True, retained_source_intervals=intervals,
        scope='Only exactly joined retained instructions; expanded/synthetic instructions remain unmapped. '
              'Relocated immediates are masked; this does not prove their runtime values.')
    (a.output/'jit-source-map.json').write_text(json.dumps(observation, indent=2)+'\n')


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
            effective_plan = a.link_plan
            boot_fact = None
            plan = json.loads(plan_bytes)
            if a.jit_capture:
                symbols = a.jit_capture.with_name(a.jit_capture.name.replace('.jit-lines.json', '.kallsyms'))
                symbol_rows = [line.split() for line in symbols.read_text().splitlines()]
                observed, = [int(row[0], 16) for row in symbol_rows
                              if len(row) >= 3 and row[2] == 'this_cpu_off']
                cpu_number, = [int(row[0], 16) for row in symbol_rows
                               if len(row) >= 3 and row[2] == 'cpu_number']
                old, = [h['addr'] for h in plan['helpers'] if h['name'] == '__native_x86_this_cpu_off']
                for group in ('lookup_sites', 'lookup_maps', 'update_sites'):
                    for fact in plan[group]:
                        if fact['percpu_base_addr']:
                            if fact['percpu_base_addr'] != old:
                                raise ValueError('Unexpected per-CPU base fact')
                            fact['percpu_base_addr'] = observed
                for helper in plan['helpers']:
                    if helper['name'] == '__native_x86_this_cpu_off':
                        helper['addr'] = observed
                    if helper['name'] == '__native_x86_cpu_number':
                        helper['addr'] = cpu_number
                effective_plan = anonymous('native-profile-plan')
                effective_plan.write_text(json.dumps(plan))
                boot_fact = dict(symbol='this_cpu_off', supplied=old, observed=observed,
                    cpu_number_observed=cpu_number,
                    kallsyms=str(symbols), scope='Only directly encoded per-CPU boot addresses are updated; '
                    'calls/map immediates are relocation-masked, not value-certified')
            blob, relocs, patches, abi = [anonymous('native-helper-'+n)
                                        for n in ('blob', 'relocs', 'patches', 'abi')]
            runtime_sites = run([a.linker, '--input', proof, '--symbol', a.symbol,
                '--mode', 'kernel', '--link-plan', effective_plan, '--show',
                '--output', blob, '--output-relocs', relocs,
                '--output-map-patches', patches, '--output-abi', abi], 'kernel')
            code, raw_relocs = blob.read_bytes(), relocs.read_bytes()
            # iter_unpack rejects truncated records instead of silently dropping bytes.
            rows = [dict(offset=offset, kind=kind, target=target)
                    for offset, kind, target in struct.iter_unpack('<IIQ', raw_relocs)]
            names = {}
            for fact in plan['helpers']:
                names.setdefault(fact['addr'], []).append(fact['name'])
            for row in rows:
                row['helper_names'] = sorted(names.get(row['target'], []))
            record['runtime'] = dict(link_plan=str(a.link_plan),
                link_plan_sha256=hashlib.sha256(plan_bytes).hexdigest(),
                profile_boot_fact=boot_fact,
                blob_bytes=len(code), blob_sha256=hashlib.sha256(code).hexdigest(),
                relocs_bytes=len(raw_relocs), relocs_sha256=hashlib.sha256(raw_relocs).hexdigest(),
                relocations=rows, map_patches=patches.read_text(), abi=abi.read_text(),
                helper_sites=runtime_sites,
                helper_counts=dict(Counter(site['helper'] for site in runtime_sites)),
                lookup_maps=plan['lookup_maps'],
                scope='Normal proof-to-kernel replay of supplied facts; compare hashes with captured run to establish identity; no kernel execution')
            if a.jit_capture:
                attribute_jit(a, code, rows, patches.read_text())
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
    parser.add_argument('--jit-capture', type=Path)
    parser.add_argument('--jit-program', type=int)
    args = parser.parse_args()
    if args.jit_capture and (not args.link_plan or args.jit_program is None):
        parser.error('--jit-capture requires --link-plan and --jit-program')
    main(args)
