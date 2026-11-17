#!/usr/bin/env python3
"""Read retained Os failure logs; no build, guest, or source mutation."""
import datetime
import json
from pathlib import Path
import re

root = Path(__file__).resolve().parents[3]
tracee = root / 'corpus/results/x86_kvm_corpus_20261117_013735_779007'
shim = tracee / 'details/shim-logs/tracee__monitor.post_rejit.log'
lines = shim.read_text().splitlines()
failures = []
maps = []
loads = []
for number, line in enumerate(lines, 1):
    match = re.search(r'native-loader failed prog=(\S+).* error=(.*)', line)
    if match:
        failures.append(dict(line=number, program=match[1], error=match[2]))
    match = re.search(r'BPF_MAP_CREATE type=(\d+) key_size=(\d+) value_size=(\d+) '
                      r'max_entries=(\d+) name=(\S+)', line)
    if match and match[5] == '.rodata.str1.1':
        maps.append(dict(line=number, type=int(match[1]), key_size=int(match[2]),
                         value_size=int(match[3]), max_entries=int(match[4]), name=match[5]))
    match = re.search(r'BPF_PROG_LOAD type=\d+ \(kprobe\) name=trace_ret_vfs_w '
                      r'insn_cnt=(\d+)', line)
    if match:
        loads.append(dict(line=number, name='trace_ret_vfs_w', insn_count=int(match[1])))

bcc = root / 'corpus/results/x86_kvm_corpus_20261117_012030_406547'
bcc_log = Path('/workspaces/kprog-raw/flag-tuning-20261117/2-Os/bcc_set.log')
bcc_lines = bcc_log.read_text().splitlines()
bcc_shim = bcc / 'details/shim-logs/bcc__set.post_rejit.log'
bcc_native_lines = bcc_shim.read_text().splitlines()
progress_path = bcc / 'details/progress.json'
progress = json.loads(progress_path.read_text())
result = dict(
    captured_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
    scope='Retained Os logs only; no new measurement or native execution.',
    tracee=dict(run=str(tracee), shim_log=str(shim), string_maps=maps,
                failing_loads=loads, failures=failures,
                replacement_events=sum('native-loader replaced prog=' in line for line in lines),
                program_name_scope='Kernel name is truncated; full ELF symbol not established here.'),
    bcc=dict(run=str(bcc), log=str(bcc_log),
             retained_files=sorted(str(path.relative_to(bcc)) for path in bcc.rglob('*') if path.is_file()),
             progress_status=progress.get('status'),
             events=[json.loads(line) for line in bcc_lines if line.startswith('{')],
             make_errors=[line for line in bcc_lines if line.startswith('make: ***')],
             native_replacement_events=sum('native-loader replaced prog=' in line for line in bcc_native_lines),
             native_failure_events=sum('native-loader failed prog=' in line for line in bcc_native_lines),
             shim_last_line_number=len(bcc_native_lines),
             shim_last_event=bcc_native_lines[-1].split('] ', 1)[-1],
             cause='Not established: retained files contain no native loader or kernel console failure.'))
output = Path(__file__).with_name('flag-failures.json')
output.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(tracee_replacements=result['tracee']['replacement_events'],
                      tracee_failures=len(failures), string_maps=maps,
                      bcc_retained_files=result['bcc']['retained_files'])))
