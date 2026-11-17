#!/usr/bin/env python3
"""Read existing usercopy code/config/profile evidence; start no guest."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
repo = here.parents[2]
kernel = Path('/workspaces/.agent-state/kprog-ck/build-x86')
assembly = subprocess.check_output([
    'objdump', '-d', '-M', 'intel', '--no-show-raw-insn',
    '--disassemble=copy_from_user_nofault', str(kernel / 'vmlinux')], text=True)
config = [line for line in (kernel / '.config').read_text().splitlines()
          if line.startswith(('CONFIG_HARDENED_USERCOPY=',
                              'CONFIG_HARDENED_USERCOPY_DEFAULT_ON='))]
profile_path = repo / 'kprog/results/shared-hash-regression-20261116/otel-shared.costs.json'
profile = json.loads(profile_path.read_text())
symbols = ('__check_object_size', 'check_stack_object')
periods = {}
for phase, values in profile['phases'].items():
    periods[phase] = {name: values['external_root_cycles'][name]
                      for name in symbols if name in values['external_root_cycles']}
fixture_path = Path('/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json')
fixture = json.loads(fixture_path.read_text())
calls = [dict(offset=row[0], instruction=row[1]) for row in fixture['instructions']
         if row[1] == 'call']
receipt = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    kernel_image=str(kernel / 'vmlinux'), selected_config=config,
    on_disk_copy_from_user_nofault=assembly,
    current_native_emitter='kprog/x86/native_lab/native_link/src/x86_probe_read.rs',
    retained_fixture=str(fixture_path), retained_fixture_call_slots=calls,
    historical_profile=str(profile_path.relative_to(repo)),
    historical_profile_run=profile['run'],
    external_root_pmu_periods_without_caller_ownership=periods,
    scope='On-disk kernel and current emitter source comparison, with retained historical fixture/profile data. Jump-label/boot settings and sampled callers are not established by this receipt. External PMU roots include other guest work; no BPF-owned cycles/ns or speedup inferred. No candidate, runtime check, source change, build or guest.')
(here / 'usercopy-path.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('config:',config)
print('retained native fixture CALL slots:',len(calls))
print('unowned historical PMU periods:',periods)
