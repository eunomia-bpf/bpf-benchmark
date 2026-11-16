"""Reconstruct a host-only native-unwinder plan from its captured map metadata.

Map names, IDs and shapes come from request 3, including declared inner shapes.
Kernel helpers/layout come from request 13 in the same guest. No kernel object
addresses were captured for request 3: map pointer patches remain zero and the
result must not be loaded. Compare absent versus retained named layout facts.
"""
import copy
import io
import json
from pathlib import Path
import struct
import subprocess
import sys
import tarfile

ROOT = Path('/workspaces/repository')
raw = Path(sys.argv[1])
retained = Path('/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication')
archive = Path('/workspaces/kprog-raw/perf/20261116-checked-six-apps/otelcol-ebpf-profiler/service.tar.gz')
request = 'service/requests/3.success.tar.gz'
with tarfile.open(archive) as outer:
    with tarfile.open(fileobj=io.BytesIO(outer.extractfile(request).read()), mode='r:gz') as inner:
        metadata = json.load(inner.extractfile('request/kernel.metadata.json'))
        generation = json.load(inner.extractfile('request/generation.metadata.json'))
        kernel_facts = json.load(inner.extractfile('request/kernel.facts.json'))
for name, data in [('kernel.metadata', metadata), ('generation.metadata', generation), ('kernel.facts', kernel_facts)]:
    (raw / (name + '.json')).write_text(json.dumps(data, indent=2) + '\n')
plan = json.loads((retained / '130/0.link-plan.json').read_text())
reference = {fact['name']: fact for fact in plan['lookup_maps']}
generic = next(h['addr'] for h in plan['helpers'] if h['name'] == 'bpf_map_lookup_elem')
this_cpu = next(h['addr'] for h in plan['helpers'] if h['name'] == '__native_x86_this_cpu_off')
symbols = {}
for line in Path('/workspaces/kprog-raw/perf/20261116-otel-regression/pmu/profile/baseline.start.kallsyms').read_text().splitlines():
    fields = line.split()
    if len(fields) >= 3:
        symbols[fields[2]] = int(fields[0], 16)
lpm = generic + symbols['trie_lookup_elem'] - symbols['bpf_map_lookup_elem']
raw_hash = reference['interpreter_offsets']['target_addr']
plan['maps'] = [dict(name=m['name'], addr=0) for m in metadata['maps']]
plan['lookup_maps'] = []
for m in metadata['maps']:
    fact = dict(name=m['name'], map_name=m['name'], kind='call', target_addr=generic,
                key_offset=0, max_entries=0, elem_size=0, index_mask=0, value_offset=0, percpu_base_addr=0)
    kind = m['map_type']
    if kind in [1, 13]:
        fact.update(kind='hash' if kind == 1 else 'hash_of_maps', target_addr=raw_hash,
                    key_offset=plan['kernel_layout']['hash']['key'] + ((m['key_size'] + 7) & ~7))
    elif kind in [2, 6]:
        fact.update(kind='array' if kind == 2 else 'percpu_array', max_entries=m['max_entries'],
                    elem_size=((m['value_size'] + 7) & ~7) if kind == 2 else 8,
                    index_mask=(1 << (m['max_entries'] - 1).bit_length()) - 1,
                    value_offset=plan['kernel_layout']['array']['value'],
                    percpu_base_addr=this_cpu if kind == 6 else 0)
    elif kind == 11:
        fact['target_addr'] = lpm
    plan['lookup_maps'].append(fact)
variants = {}
for label, facts in [('no-named-facts', []), ('captured-named-facts', plan['lookup_maps'])]:
    output = raw / label
    output.mkdir()
    candidate = copy.deepcopy(plan)
    candidate['lookup_maps'] = facts
    path = output / 'plan.json'
    path.write_text(json.dumps(candidate, indent=2) + '\n')
    args = [str(ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'),
            '--input', str(retained / '134/entry.proof.o'), '--symbol', 'perf_unwind_native',
            '--mode', 'kernel', '--link-plan', str(path), '--output', str(output / 'image.blob'),
            '--output-relocs', str(output / 'image.relocs'), '--output-map-patches', str(output / 'image.maps'),
            '--output-abi', str(output / 'image.abi'), '--show']
    child = subprocess.run(args, capture_output=True, text=True)
    (output / 'command.json').write_text(json.dumps(args, indent=2) + '\n')
    (output / 'link.log').write_text(child.stdout + child.stderr)
    child.check_returncode()
    relocs = list(struct.iter_unpack('<IIQ', (output / 'image.relocs').read_bytes()))
    sites, ranges = [], []
    for line in child.stderr.splitlines():
        if line.startswith('native-link-helper-site '):
            sites.append(json.loads(line.split(' ', 1)[1]))
        if line.startswith('native-link-lto-range '):
            ranges.append(json.loads(line.split(' ', 1)[1]))
    variants[label] = dict(payload_bytes=(output / 'image.blob').stat().st_size,
        generic_helper_relocations=sum(kind == 1 and target == generic for _, kind, target in relocs),
        helper_sites=sites, appended_ranges=ranges)
report = dict(scope=__doc__, archive=str(archive), request=request,
              map_shapes=generation['maps'], variants=variants,
              installed_bytes='unmeasured', runtime_gain='unmeasured')
(raw / 'unwinder-report.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report, indent=2))
