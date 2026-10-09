#!/usr/bin/env python3
"""Check retained size signatures and, when supplied, actual JIT dump bytes.

This is an offline result check, not a benchmark validity/publication gate.
Equal lengths do not prove byte identity. --commit labels the candidate's
claimed source; it is not evidence that the candidate was built from it.
"""
import argparse
import collections
import json
import pathlib
import subprocess
import sys

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--reference', required=True, type=pathlib.Path)
p.add_argument('--candidate', required=True, type=pathlib.Path)
p.add_argument('--reference-runtime', default='kernel')
p.add_argument('--candidate-runtime', default='kernel')
p.add_argument('--commit', required=True)
p.add_argument('--source-repo', type=pathlib.Path, help='Optional source checkout: verify HEAD matches --commit')
p.add_argument('--reference-dumps', type=pathlib.Path)
p.add_argument('--candidate-dumps', type=pathlib.Path)
a = p.parse_args()
if bool(a.reference_dumps) != bool(a.candidate_dumps):
    p.error('both dump directories are required for byte comparison')
if a.source_repo:
    sha = subprocess.check_output(['git', '-C', str(a.source_repo), 'rev-parse', 'HEAD'], text=True).strip()
    expected = subprocess.check_output(['git', '-C', str(a.source_repo), 'rev-parse', a.commit + '^{commit}'], text=True).strip()
    if sha != expected:
        sys.exit('candidate source checkout HEAD does not match --commit')


def signature(root, runtime):
    result = json.loads((root / 'details/result.json').read_text())
    out = {}
    if 'benchmarks' in result:
        for b in result['benchmarks']:
            for r in b['runs']:
                if r['runtime'] != runtime:
                    continue
                key = b['name']
                if key in out:
                    raise ValueError('duplicate benchmark/runtime: ' + key)
                values = {(s.get('jited_prog_len'), s.get('xlated_prog_len'),
                           s.get('code_size', {}).get('native_code_bytes'),
                           s.get('code_size', {}).get('bpf_bytecode_bytes')) for s in r['samples']}
                if not values:
                    raise ValueError('no code size samples: ' + key)
                out[key] = sorted(values, key=repr)
        if not out:
            raise ValueError('no samples for runtime ' + runtime)
    else:
        if runtime not in ('baseline', 'post_rejit'):
            raise ValueError('corpus runtime must be baseline or post_rejit')
        for f in sorted((root / 'details/apps').glob('*.json')):
            app = json.loads(f.read_text())
            entries = app[runtime]['bpf'].values()
            # IDs change on restart; duplicate program names are retained as a
            # multiset. This verifies inventory, not an endpoint association.
            out[f.stem] = sorted(collections.Counter(
                (v['name'], v['type'], v['bytes_jited'], v['bytes_xlated']) for v in entries
            ).items(), key=repr)
        if not out:
            raise ValueError('no corpus program inventory')
    return out


old, new = signature(a.reference, a.reference_runtime), signature(a.candidate, a.candidate_runtime)
mismatches = [dict(program=k, reference=old.get(k), candidate=new.get(k))
              for k in sorted(old.keys() | new.keys()) if old.get(k) != new.get(k)]
result = dict(candidate_commit_asserted=a.commit, size_signatures_equal=not mismatches,
              mismatches=mismatches, byte_identity='not established: historical JIT bytes required')
byte_difference = False
if a.reference_dumps:
    def binaries(root):
        out = {str(f.relative_to(root)): f.read_bytes() for f in root.rglob('*.bin')}
        if not out:
            raise ValueError('no .bin dumps in ' + str(root))
        return out
    x, y = binaries(a.reference_dumps), binaries(a.candidate_dumps)
    differences = [k for k in sorted(x.keys() | y.keys()) if x.get(k) != y.get(k)]
    byte_difference = bool(differences)
    result.update(byte_identity='different' if differences else 'identical supplied dump bytes',
                  dump_mismatches=differences)
print(json.dumps(result, indent=2))
sys.exit(1 if mismatches or byte_difference else 0)
