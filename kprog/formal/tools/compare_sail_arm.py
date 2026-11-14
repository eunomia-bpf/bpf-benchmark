#!/usr/bin/env python3
"""Compare fresh LNSym execution with the retained, pinned Arm ASL outputs."""
import argparse
import base64
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
COHORTS = (
    'atomic-logical-broad-asl/cases.jsonl',
    'atomic-add-current-asl/cases.jsonl',
    'atomic-logical-asl/cases.jsonl',
    'atomic-logical-monitor-asl/cases.jsonl',
)


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_cases(archive):
    found = {}
    with gzip.open(archive, 'rt') as stream:
        for line in stream:
            if not line.startswith('{'):
                continue  # Version markers between the retained archive epochs.
            entry = json.loads(line)
            name = entry.get('path')
            if name not in COHORTS:
                continue
            if name in found:
                raise ValueError(f'duplicate ASL cohort: {name}')
            data = base64.b64decode(entry['base64'], validate=True)
            if len(data) != entry['bytes'] or hashlib.sha256(data).hexdigest() != entry['sha256']:
                raise ValueError(f'ASL archive payload checksum mismatch: {name}')
            rows = [json.loads(row) for row in data.splitlines() if row]
            if not rows:
                raise ValueError(f'empty ASL cohort: {name}')
            found[name] = (entry['sha256'], rows)
    if set(found) != set(COHORTS):
        raise ValueError(f'missing ASL cohorts: {set(COHORTS)-set(found)}')
    return found


def oracle_observation(row):
    if row['model_exit']:
        raise ValueError('retained ASL execution did not complete')
    scalars = {key: int(value, 16) for key, value in re.findall(
        r'^(PC|SP|FLAGS|R[0-9]+|V0) ([0-9a-fA-F]+)$', row['model_stdout'], re.M)}
    required = ['PC', 'SP', 'FLAGS', 'V0'] + [f'R{i}' for i in range(31)]
    if not all(key in scalars for key in required):
        raise ValueError('incomplete retained ASL register observation')
    memory = {int(address, 16): int(value, 16) for address, value in re.findall(
        r'^M ([0-9a-fA-F]+) ([0-9a-fA-F]+)$', row['model_stdout'], re.M)}
    addresses = [cell['address'] for cell in row['request']['state']['memory']]
    if not all(address in memory for address in addresses):
        raise ValueError('incomplete retained ASL memory observation')
    return dict(registers=[scalars[f'R{i}'] for i in range(31)] + [scalars['SP']],
                pc=scalars['PC'], flags=scalars['FLAGS'], vector0=scalars['V0'],
                memory={address: memory[address] for address in addresses})


def lean_observation(output):
    if output['fault'] is not None:
        return None
    return {**{key: output[key] for key in ('registers', 'pc', 'flags', 'vector0')},
            'memory': {cell['address']: cell['value'] for cell in output['memory']}}


def recorded_profile_difference(row, observation):
    # Keep the original failed-monitor cohort and its exact old outcome. Do not
    # silently change its input to the separate matching-monitor cohort.
    state = row['request']['state']
    inputs = state.get('exclusive_inputs', {})
    return (row.get('operation') == 'ARM64_OP_STLXR' and
            row['status'] == 'difference' and state.get('exclusive_monitor') is None and
            inputs.get('virtual_pass') is False and inputs.get('global_pass') is False and
            inputs.get('commit_pass') is False and row['lean_exit'] == 0 and
            observation == lean_observation(json.loads(row['lean_stdout'])))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', type=Path,
                        default=ROOT.parent/'results/kprog_verification_20261107/reference-arm-asl.log.gz')
    parser.add_argument('--receipt', type=Path,
                        default=ROOT.parent/'results/kprog_verification_20261107/reference-arm-asl.json')
    parser.add_argument('--reference', type=Path, default=ROOT/'.lake/build/bin/reference')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cohorts = read_cases(args.archive)
    receipt = json.loads(args.receipt.read_text())
    args.output.mkdir(parents=True, exist_ok=False)
    counts = Counter()
    per_cohort = {}
    with (args.output/'cases.jsonl').open('w') as stream:
        for name in COHORTS:
            checksum, rows = cohorts[name]
            status_counts = Counter()
            for index, row in enumerate(rows):
                oracle = oracle_observation(row)
                run = subprocess.run([str(args.reference.resolve())],
                    input=json.dumps(row['request'])+'\n', text=True, capture_output=True)
                result = dict(cohort=name, case=index, oracle_payload_sha256=checksum,
                    request=row['request'], oracle_input=row['model_input'],
                    oracle_stdout=row['model_stdout'], oracle_stderr=row['model_stderr'],
                    reference_exit=run.returncode, reference_stdout=run.stdout,
                    reference_stderr=run.stderr)
                if run.returncode:
                    status = 'reference-error'
                else:
                    output = json.loads(run.stdout)
                    if output.get('reference_base') != 'LNSym':
                        raise ValueError('reference executable is not the LNSym ARM binding')
                    observed = lean_observation(output)
                    if observed == oracle:
                        status = 'agree'
                    elif recorded_profile_difference(row, observed):
                        status = 'recorded-profile-difference'
                    else:
                        status = 'difference'
                    result.update(oracle=oracle, reference=output)
                result['status'] = status
                stream.write(json.dumps(result, sort_keys=True)+'\n')
                stream.flush()
                counts[status] += 1
                status_counts[status] += 1
            per_cohort[name] = dict(cases=len(rows), sha256=checksum, statuses=dict(status_counts))
            print(name, dict(status_counts), flush=True)
    summary = dict(mode='fresh LNSym versus archived ASL observations; no live Sail rerun',
        cases=sum(counts.values()), statuses=dict(counts), cohorts=per_cohort,
        archive_sha256=digest(args.archive), receipt_sha256=digest(args.receipt),
        reference_sha256=digest(args.reference),
        recorded_model_sha256=receipt['pins']['model_sha256'],
        recorded_sail_commit=receipt['upstream']['commit'],
        scope='X0-X30,SP,PC,NZCV,V0,supplied memory; typed events/permissions/monitor ordering separate',
        source_sha256={str(path.relative_to(ROOT)): digest(path) for path in (
            ROOT/'ReferenceMain.lean', ROOT/'KProgFormal/Reference/AArch64.lean',
            ROOT/'KProgFormal/Reference/Memory.lean')})
    (args.output/'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
    print('ASL ARCHIVE COMPARISON', dict(counts), flush=True)
    return 0 if set(counts) <= {'agree', 'recorded-profile-difference'} else 1


if __name__ == '__main__':
    raise SystemExit(main())
