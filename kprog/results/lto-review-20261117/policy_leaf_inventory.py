#!/usr/bin/env python3
"""Read the sole kernel's compiled policies and an existing probe fixture."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
kernel = Path('/workspaces/.agent-state/kprog-ck/build-x86')
symbols = ('nmi_uaccess_okay', 'copy_from_kernel_nofault_allowed')
policies = []
for symbol in symbols:
    assembly = subprocess.check_output([
        'objdump', '-d', '-M', 'intel', '--no-show-raw-insn',
        '--disassemble=' + symbol, str(kernel / 'vmlinux')], text=True)
    policies.append(dict(symbol=symbol, on_disk_disassembly=assembly))
config = (kernel / '.config').read_text().splitlines()
wanted = ('CONFIG_X86_64', 'CONFIG_DEBUG_VM', 'CONFIG_DEBUG_VM_PGTABLE',
          'CONFIG_MITIGATION_RETHUNK', 'CONFIG_FUNCTION_TRACER')
selected = [line for line in config
            if any(line.startswith(name + '=') or line == '# ' + name + ' is not set'
                   for name in wanted)]
capture = Path('/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json')
fixture = json.loads(capture.read_text())
frame = [row for row in fixture['instructions'] if row[1] in ('push', 'pop')]
calls = [dict(offset=row[0], operation=row[1]) for row in fixture['instructions']
         if row[1] == 'call']
assignment = {
    'RAX': 'policy temporary, then copy load/result',
    'RDI': 'advancing destination',
    'RSI': 'advancing source',
    'RDX': 'SMAP decision after source has moved, if not boot-folded; zeroing scratch after cleanup',
    'RCX': 'remaining copy/zero count',
    'R8': 'original destination',
    'R9D': 'original u32 size',
    'R10': 'current task for mm comparison and pagefault nesting',
    'R11': 'policy/feature temporary before copy, then source-load fault status',
}
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    kernel_image=str(kernel / 'vmlinux'), kernel_config=str(kernel / '.config'),
    selected_config_lines=selected, policies=policies,
    existing_user_fixture=dict(capture=str(capture), bytes=len(bytes.fromhex(fixture['instruction_bytes'])),
                               frame_instructions=frame, external_call_slots=calls),
    possible_leaf_register_assignment=assignment,
    scope='Source/on-disk kernel policy inspection plus historical fixture frame counts. Kernel fentry and return sites can be patched at boot, so their on-disk instructions are not asserted as executed guest costs. Register assignment is a design witness, not emitted or tested candidate code, a minimum-register proof, or a measured speedup.')
(here / 'policy-leaf.json').write_text(json.dumps(result, indent=2) + '\n')
print('kernel policies:', list(symbols))
print('fixture frame instructions:', len(frame), '; policy CALL slots:', len(calls))
print('config:', selected)
