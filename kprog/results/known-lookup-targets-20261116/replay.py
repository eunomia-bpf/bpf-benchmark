"""Compare lookup facts with one current linker, without running old code.

Retained proof and load plans are host replay inputs. OTel's added LPM target
uses its source declaration and a symbol delta from the captured same kernel;
this is not a new capture of loader-generated facts or installed code.
"""
import copy
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path('/workspaces/repository')
raw = Path(sys.argv[1])
retained = Path('/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication')
inventory = json.loads((retained / 'report.json').read_text())
linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
kallsyms = {}
for line in Path('/workspaces/kprog-raw/perf/20261116-otel-regression/pmu/profile/baseline.start.kallsyms').read_text().splitlines():
    fields = line.split()
    if len(fields) >= 3:
        kallsyms[fields[2]] = int(fields[0], 16)
rows = []
for index in [114, 130, 140]:
    entry = inventory['entries'][index]
    before = json.loads((retained / str(index) / '0.link-plan.json').read_text())
    generic = next(h['addr'] for h in before['helpers'] if h['name'] == 'bpf_map_lookup_elem')
    after = copy.deepcopy(before)
    if entry['app'] == 'otelcol-ebpf-profiler':
        target = generic + kallsyms['trie_lookup_elem'] - kallsyms['bpf_map_lookup_elem']
        for fact in after['lookup_maps']:
            if fact['name'] in ['pid_page_to_map', 'pid_page_to_mapping_info']:
                fact['target_addr'] = target
    old = copy.deepcopy(before)
    # Reproduce the former selection's loss of every named `call` target.
    for fact in old['lookup_maps']:
        if fact['kind'] == 'call':
            fact['target_addr'] = generic
    variants = {}
    for label, facts in [('generic-call-facts', old), ('bound-call-facts', after)]:
        output = raw / (str(index) + '-' + label)
        output.mkdir()
        plan = output / 'plan.json'
        plan.write_text(json.dumps(facts, indent=2) + '\n')
        args = [str(linker), '--input', str(retained / str(index) / 'entry.proof.o'),
                '--symbol', entry['symbol'], '--mode', 'kernel', '--link-plan', str(plan),
                '--output', str(output / 'image.blob'), '--output-relocs', str(output / 'image.relocs'),
                '--output-map-patches', str(output / 'image.maps'), '--output-abi', str(output / 'image.abi')]
        child = subprocess.run(args, capture_output=True, text=True)
        (output / 'command.json').write_text(json.dumps(args, indent=2) + '\n')
        (output / 'link.log').write_text(child.stdout + child.stderr)
        child.check_returncode()
        relocs = list(struct.iter_unpack('<IIQ', (output / 'image.relocs').read_bytes()))
        variants[label] = dict(payload_bytes=(output / 'image.blob').stat().st_size,
            generic_calls=sum(kind == 1 and target == generic for _, kind, target in relocs),
            call_targets=[dict(offset=at, target=target) for at, kind, target in relocs if kind == 1])
    rows.append(dict(app=entry['app'], symbol=entry['symbol'], variants=variants))
result = dict(scope=__doc__, programs=rows, installed_bytes='pending publication',
              per_call_body_helper_map='pending affected-app measurement')
(raw / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
