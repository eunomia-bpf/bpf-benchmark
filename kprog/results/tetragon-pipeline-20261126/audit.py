"""Inspect retained same-load output code and the three existing counter captures."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PROFILE = ROOT / 'kprog/results/cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile'
REPEATS = ROOT / 'kprog/results/cmov-branches-20261126/repetitions-20261126T140934Z'
symbols = {fields[2]: int(fields[0], 16) for line in (PROFILE / 'kallsyms.txt').read_text().splitlines()
           if len(fields := line.split()) >= 3 and fields[1] in 'tTwW'}
target = symbols['bpf_ringbuf_output']
report = {'profile_run': (PROFILE / 'run_dir').read_text().strip(),
          'image': (PROFILE / 'profile-image.txt').read_text().strip(),
          'kernel_ringbuf_output': hex(target), 'same_load_output': {}, 'counter_captures': []}
for kind, ident in [('original', 709), ('native', 710)]:
    stem = PROFILE / f'progdump/411.78/prog-{ident}-generic_tracepo'
    address, length = stem.with_suffix('.funcs.txt').read_text().split()
    text = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
        '--no-show-raw-insn', '--adjust-vma=0x' + address, str(stem.with_suffix('.jited.bin'))], text=True)
    (HERE / (kind + '-output.dis')).write_text(text)
    lines = text.splitlines()
    calls = [i for i, line in enumerate(lines) if re.search(r'\tcall\s+0x' + format(target, 'x') + r'\b', line)]
    if len(calls) != 1:
        raise ValueError(f'{kind}: expected one captured ring-buffer call, found {len(calls)}')
    call = calls[0]
    setup = lines[max(0, call - 6):call + 2]
    map_address = next(re.search(r'movabs\s+\$(0x[0-9a-f]+),%rdi', line)[1]
                       for line in setup if re.search(r'movabs\s+\$(0x[0-9a-f]+),%rdi', line))
    clamp = next(i for i, line in enumerate(lines) if '$0x7fff,' in line)
    report['same_load_output'][kind] = dict(program_id=ident, entry='0x' + address,
        jit_bytes=int(length), xlated_bytes=stem.with_suffix('.xlated.bin').stat().st_size,
        ringbuf_map_address=map_address, call_setup=setup, length_clamp=lines[clamp - 3:clamp + 6])

for case in sorted(REPEATS.glob('tetragon-[123]')):
    summary = json.loads((case / 'guest-summary.json').read_text())
    # Use the run already captured by the diagnostic collector, not a fresh guest.
    run = Path(summary['checks'][0]['run'])
    app = json.loads(next((run / 'details/apps').glob('*.json')).read_text())
    phases = {phase: [record for record in app[phase]['bpf'].values()
                      if record['name'] == 'generic_tracepo'] for phase in ('baseline', 'post_rejit')}
    report['counter_captures'].append(dict(case=case.name, run=str(run), phases=phases))
(HERE / 'audit.json').write_text(json.dumps(report, indent=2) + '\n')
