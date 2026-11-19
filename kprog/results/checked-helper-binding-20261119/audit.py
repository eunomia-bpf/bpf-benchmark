"""Read actual checked-native helper relocations; no guest or new profile."""
import argparse
from collections import Counter
import io
import json
from pathlib import Path
import struct
import tarfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('archive', type=Path)
parser.add_argument('system_map', type=Path)
parser.add_argument('output', type=Path)
args = parser.parse_args()
symbols = {}
addresses = {}
for line in args.system_map.read_text().splitlines():
    address, kind, name = line.split()[:3]
    symbols[name] = int(address, 16)
    addresses.setdefault(int(address, 16), []).append(name)
rows = []
with tarfile.open(args.archive) as service:
    completions = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl').read().decode().splitlines()]
    for completion in completions:
        name = Path(completion['artifact_archive'] if completion['status'] == 0 else completion['failure_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+name).read())) as capsule:
            members = capsule.getnames()
            entry = capsule.extractfile('request/kernel.entry').read().decode().strip()
            facts = json.load(capsule.extractfile('request/kernel.facts.json'))
            row = dict(request=completion['request_id'], entry=entry, prog_type=facts['prog_type'], status=completion['status'])
            plans = [m for m in members if m.endswith('link-plan.json')]
            if not plans:
                row['plan_present'] = False
                rows.append(row)
                continue
            # The archived request has one installed kernel-link plan. Retain
            # every candidate if a future capsule contains more than one.
            row['plans'] = []
            for member in plans:
                plan = json.load(capsule.extractfile(member))
                helpers = {item['name']: item['addr'] for item in plan['helpers']}
                anchor = helpers.get('__native_x86_ktime_get_mono_fast_ns')
                slide = anchor-symbols['ktime_get_mono_fast_ns'] if anchor is not None else None
                stem = member[:member.rfind('.tmp.')]
                relocations = capsule.extractfile(stem+'.relocs.bin').read()
                calls = []
                for offset, kind, target in struct.iter_unpack('<IIQ', relocations):
                    if kind != 1:
                        continue
                    calls.append(dict(offset=offset, target=target,
                        helper_names=sorted(name for name, address in helpers.items() if address == target),
                        kernel_symbols=addresses.get(target-slide, []) if slide is not None else []))
                contextual = []
                for call in calls:
                    for helper in ['bpf_perf_event_output', 'bpf_get_stack']:
                        if helper not in call['helper_names']:
                            continue
                        expected = helper+('_tp' if facts['prog_type'] == 5 else '_raw_tp') if facts['prog_type'] in [5, 17] else None
                        contextual.append(dict(offset=call['offset'], helper=helper,
                            actual=call['kernel_symbols'], expected=expected,
                            expected_bound=expected in call['kernel_symbols'] if expected else None))
                row['plans'].append(dict(path=member, kernel_slide=slide,
                    map_ops=plan['map_ops'], calls=calls, contextual=contextual))
            rows.append(row)
contexts = [call for row in rows for plan in row.get('plans', []) for call in plan['contextual'] if call['expected']]
writes = Counter(helper for row in rows for plan in row.get('plans', []) for call in plan['calls']
                 for helper in call['helper_names'] if helper in ['bpf_map_update_elem', 'bpf_map_delete_elem'])
result = dict(archive=str(args.archive), system_map=str(args.system_map), requests=len(rows),
    context_calls=len(contexts), expected_context_bound=sum(c['expected_bound'] for c in contexts),
    generic_write_calls=dict(writes),
    plans_with_map_ops=sum(bool(plan['map_ops']) for row in rows for plan in row.get('plans', [])),
    rows=rows, scope='Retained installed call relocations, not invocation weights or current helper time shares.')
args.output.write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps({key: value for key, value in result.items() if key != 'rows'}))
