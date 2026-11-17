#!/usr/bin/env python3
"""Count draft emitter source bytes and retain original kernel clock disassembly only."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
path = REPO / 'kprog/x86/native_lab/native_link/src/x86_ktime.rs'
source = path.read_text().split('pub(super) fn routine(',1)[1].split('/// Every bpf_ktime_get_ns',1)[0]
arrays = re.findall(r'b.extend_from_slice\(&\[([^]]+)\]\)',source)
parts = dict(literal_arrays=sum(len([x for x in a.split(',') if x.strip()]) for a in arrays),
    displacement_fields=4*len(re.findall(r'b.extend_from_slice\(&disp\(',source)),
    gs_displacements=4*len(re.findall(r'b.extend_from_slice\(&(?:preempt|hv)\)',source)),
    absolute_addresses=8*len(re.findall(r'b.extend_from_slice\(&l\.\w+\.to_le_bytes\(\)\)',source)),
    conditional_branches=6*source.count('append_x86_jcc_rel32('),
    direct_jumps=5*source.count('jump(&mut b)'),
    external_call_slots=5*source.count('call(&mut b, &mut relocs,'),
    one_byte_pushes=source.count('b.push('))
mask_rows = [dict(delta=hex(delta),masked=hex(delta & ((1<<64)-1)),same=delta==(delta & ((1<<64)-1)))
             for delta in (0,1,(1<<63)-1,1<<63,(1<<64)-1)]
result = dict(recorded_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
    scope='Literal emitter source-byte accounting at read time, original sole-kernel disassembly and arithmetic examples. No native candidate generated/patched/assembled/executed, no installed/per-call result or new check. Counts describe this literal builder, not later revisions.',
    source=str(path.relative_to(REPO)),source_parts_bytes=parts,literal_builder_total_bytes=sum(parts.values()),
    kvm_mask_source='vendor/linux-framework/arch/x86/kernel/kvmclock.c:158-163',
    timekeeper_mask_source='vendor/linux-framework/kernel/time/timekeeping.c:318-322',
    mask_identity_examples=mask_rows)
result['source_history_commit'] = subprocess.check_output(
    ['git','log','-1','--format=%h','--',str(path.relative_to(REPO))],cwd=REPO,text=True).strip()
result['source_working_changes'] = subprocess.check_output(
    ['git','diff','--name-only','--',str(path.relative_to(REPO))],cwd=REPO,text=True).splitlines()
cohort = json.loads((HERE / 'helper-parity.json').read_text())
matched = {app:sum(count for name,count in values.items()
                  if '__native_x86_ktime_get_mono_fast_ns' in name.split('/'))
           for app,values in cohort['emission_entries_with_calls_by_app'].items()}
result['historical_emission_body_budget'] = dict(
    scope='One body per retained emission with a target call, assuming clock eligibility. Not current loaded-program counts, an installed result or a gate.',
    entries_with_target_call=matched,
    body_bytes_if_each_emission_gets_the_current_literal_body={app:count*sum(parts.values())
        for app,count in matched.items()})
(HERE / 'clock-review.json').write_text(json.dumps(result,indent=2)+'\n')
disassembly=[]
for symbol in ('ktime_get_mono_fast_ns','kvm_clock_read','__pvclock_clocksource_read'):
    disassembly.append(subprocess.check_output(['objdump','-d','--no-show-raw-insn',
        '--disassemble='+symbol,'/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'],text=True))
(HERE / 'clock-kernel.disassembly.txt').write_text('\n'.join(disassembly))
print('literal builder bytes:',sum(parts.values()),parts)
