"""Summarize captured post-branch evidence without changing raw run records."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
OUT = HERE / 'post-branch-profiles-20261126T145836Z'
report = {'profiles': {}, 'scope': 'Own QEMU guest samples, final54s workload windows; stats off. No per-call inference.'}
for app in ('tetragon', 'otel'):
    case = OUT / (app + '-profile')
    data = json.loads((case / 'phase-summary.json').read_text())
    run = Path((case / 'run_dir').read_text().strip())
    raw = json.loads(next((run / 'details/apps').glob('*.json')).read_text())
    requests = []
    for line in (case / 'stack-requests.txt').read_text().splitlines():
        match = re.fullmatch(r'([\d.]+) end=([\d.]+) request_rc=(\d+)', line)
        if match:
            start, end = map(float, match.group(1, 2))
            requests.append({'start': start, 'end': end, 'returncode': int(match[3]),
                             'intersecting_windows': [phase for phase, (a, b) in data['windows'].items()
                                                      if start < b and end >= a]})
    phases = {}
    for phase, values in data['phases'].items():
        phases[phase] = {k: values[k] for k in ('total_samples', 'kernel_samples', 'groups',
                                               'kernel_sample_shares', 'callchains', 'other_owner_samples')}
        phases[phase]['top_functions'] = dict(list(values['functions'].items())[:25])
        lock = values['functions'].get('resilient_queued_spin_lock_slowpath', 0)
        phases[phase]['lock_samples'] = lock
        phases[phase]['lock_kernel_share'] = lock / values['kernel_samples']
    report['profiles'][app] = dict(run=str(run), app_status=raw['status'], app_error=raw['error'],
        image=(case / 'profile-image.txt').read_text().strip(), qemu_host_pid=data['qemu_host_pid'],
        windows=data['windows'], stack_requests=requests, phases=phases)

old = HERE.parent / 'p3-attribution-20261126/collection-20261126T104107Z/tetragon-profile/linkcache/native_kernel_link_cache/025c0e981641eb7f.proof.o'
new = OUT / 'tetragon-profile/linkcache/native_kernel_link_cache/9117db37f534f8ab.proof.o'
instructions = []
for path in (old, new):
    disassembly = subprocess.check_output(['llvm-objdump-18', '-dr', '--no-show-raw-insn',
        '--disassemble-symbols=generic_tracepoint_event', str(path)], text=True)
    instructions.append([re.sub(r'^\s*[0-9a-f]+:\s*', '', line) for line in disassembly.splitlines()
                         if re.match(r'^\s*[0-9a-f]+:', line)])
report['tetragon_root_instruction_comparison'] = dict(old=str(old), new=str(new),
    symbol='generic_tracepoint_event', identical=instructions[0] == instructions[1],
    instruction_counts=list(map(len, instructions)),
    cmov_counts=[sum('cmov' in line for line in rows) for rows in instructions])
(OUT / 'post-profile-report.json').write_text(json.dumps(report, indent=2) + '\n')
