"""Compare raw control counterexamples without hiding any recorded fields."""
import argparse
import hashlib
import json
from pathlib import Path


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def xor_hex(a, b):
    return bytes(x ^ y for x, y in zip(bytes.fromhex(a), bytes.fromhex(b), strict=True)).hex()


def observations(path):
    result = {}
    with path.open() as stream:
        for line in stream:
            row = json.loads(line)
            a, b = row['native'], row['simulator']
            key = (row['form'], row['case'])
            if key in result:
                raise ValueError(f'Duplicate counterexample identity {key} in {path}')
            result[key] = dict(assembly=row['assembly'],
                registers=[i for i, (x, y) in enumerate(zip(a['registers'], b['registers'], strict=True)) if x != y],
                vector=[i for i, (x, y) in enumerate(zip(a['vector'], b['vector'], strict=True)) if x != y],
                masked_flags_xor=(int(a['flags'], 16) ^ int(b['flags'], 16)) & int(row['flag_mask'], 16),
                stack_xor=xor_hex(a['stack'], b['stack']),
                memory_xor=xor_hex(row['memory_native'], row['memory_simulator']))
    return result


def main(a):
    before, after = observations(a.before), observations(a.after)
    shared = before.keys() & after.keys()
    changed = [list(key) for key in sorted(shared) if before[key] != after[key]]
    record = dict(before=str(a.before), before_sha256=digest(a.before),
        after=str(a.after), after_sha256=digest(a.after), shared_cases=len(shared),
        before_only=[list(k) for k in sorted(before.keys() - after.keys())],
        after_only=[list(k) for k in sorted(after.keys() - before.keys())], changed_cases=changed,
        after_register_differences=sum(bool(r['registers']) for r in after.values()),
        after_vector_differences=sum(bool(r['vector']) for r in after.values()),
        after_masked_flag_differences=sum(bool(r['masked_flags_xor']) for r in after.values()),
        after_memory_differences=sum(any(bytes.fromhex(r['memory_xor'])) for r in after.values()),
        scope='Exact counterexample identities and observed differences; all raw fields remain in input recordings. No hardware-input witness or proof.')
    a.output.mkdir(parents=True, exist_ok=True)
    (a.output / 'comparison.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ['before', 'after', 'output']:
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
