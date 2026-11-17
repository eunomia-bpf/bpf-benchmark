#!/usr/bin/env python3
"""Match retained unnamed load metadata to upstream Go-generated programs."""
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
upstream = repo / 'vendor/repos/tetragon'
run = repo / 'corpus/results/x86_kvm_corpus_20261117_034829_591728'
sources = [
    ('program-type probe', 'vendor/github.com/cilium/ebpf/features/prog.go', 26, 29),
    ('mixed BPF and tail calls probe', 'pkg/bpf/detect_linux.go', 693, 704),
    ('per-CPU stats update', 'pkg/sensors/map_update.go', 24, 52),
]
expected = []
for purpose, name, first, last in sources:
    path = upstream / name
    operations = []
    for lineno, line in enumerate(path.read_text().splitlines(), 1):
        if first <= lineno <= last:
            match = re.search(r'asm\.(\w+(?:\.\w+)*)\(', line)
            if match:
                operation = match[1]
                # In these blocks LoadImm explicitly uses DWord. Both it
                # and LoadMapPtr encode LD_IMM64 as two BPF instruction slots.
                operations.append(dict(line=lineno, operation=operation,
                                       encoded_slots=2 if operation in
                                       ('LoadMapPtr', 'LoadImm') else 1))
    expected.append(dict(purpose=purpose, source=str(path.relative_to(repo)),
                         first_line=first, last_line=last,
                         encoded_slots=sum(op['encoded_slots'] for op in operations),
                         operations=operations))

loads = []
pattern = re.compile(
    r'BPF_PROG_LOAD type=(1|17|26|29) \(([^)]+)\) name= insn_cnt=(3|11|18) '
    r'.*license=(.*?) expected_attach=(\d+) attach_btf_id=(\d+) ')
for phase in ('baseline', 'post_rejit'):
    log = run / 'details/shim-logs' / ('tetragon__observer.' + phase + '.log')
    for lineno, line in enumerate(log.read_text().splitlines(), 1):
        if match := pattern.search(line):
            kind, type_name, count, license, attach, btf_id = match.groups()
            loads.append(dict(phase=phase, log=str(log.relative_to(repo)), line=lineno,
                              type=int(kind), type_name=type_name, insn_count=int(count),
                              license=license, expected_attach=int(attach),
                              attach_btf_id=int(btf_id)))

manifest = repo / 'vendor/build/native-bpf/x86/stage/tetragon/manifest.json'
empty_entries = [entry for entry in json.loads(manifest.read_text())['objects']
                 if entry['program'] == '']
receipt = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    reviewed_tree=subprocess.check_output(['git', '-C', str(repo), 'rev-parse', '--short', 'HEAD'], text=True).strip(),
    scope='Source and retained load-metadata attribution. No captured original instruction bytes or caller stacks are available in this run directory; count/type/license/attach/ordering matches are not exact-byte binding or runtime-frequency measurements.',
    source_instruction_shapes=expected, unnamed_loads=loads,
    current_manifest=str(manifest.relative_to(repo)),
    current_manifest_empty_program_entries=len(empty_entries),
    call_sites=[
        dict(source='vendor/repos/tetragon/pkg/celbpf/celbpf.go', line=39,
             call='Supported -> DetectMixBpfAndTailCalls'),
        dict(source='vendor/repos/tetragon/pkg/sensors/exec/procevents/proc_reader_linux.go',
             line=138, call='writeExecveMap -> updateExecveMapStats(len(procs))'),
        dict(source='vendor/repos/tetragon/pkg/sensors/exec/procevents/proc_reader_linux.go',
             line=94, call='updateExecveMapStats -> sensors.UpdateStatsMap(m, procs)'),
        dict(source='vendor/repos/tetragon/pkg/sensors/map_update.go', line=67,
             call='UpdateStatsMap -> prog.Run')])
(here / 'tetragon-unnamed.json').write_text(json.dumps(receipt, indent=2) + '\n')
print([(e['purpose'], e['encoded_slots']) for e in expected])
print('matching metadata records:', len(loads), '; empty manifest entries:', len(empty_entries))
