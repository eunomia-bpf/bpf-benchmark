#!/usr/bin/env python3
"""Boundary arithmetic for the existing x86 kernel-read policy; no code emission."""
import json
from pathlib import Path
import subprocess

MASK = (1 << 64) - 1
PAGE = 4096
VSYSCALL = 0xffffffffff600000


def canonical(address, width):
    low = address & ((1 << width) - 1)
    extended = low if low < (1 << (width - 1)) else low | (MASK ^ ((1 << width) - 1))
    return address == extended


def source_policy(address, threshold, width):
    # arch/x86/mm/maccess.c:17-36, including its early-boot zero-width case.
    return (address >= threshold and address & (MASK ^ (PAGE - 1)) != VSYSCALL
            and (width == 0 or canonical(address, width)))


def interval_policy(address, threshold, width):
    outside_vsyscall = address & (MASK ^ (PAGE - 1)) != VSYSCALL
    if width == 0:
        return address >= threshold and outside_vsyscall
    half = 1 << (width - 1)
    return (address >= threshold and outside_vsyscall
            and (address < half or address >= (1 << 64) - half))


rows = []
for threshold_bits in (47, 56):
    for width in (0, 48, 57):
        threshold = 1 << threshold_bits
        points = {0, MASK, threshold - 1, threshold, threshold + 1,
                  VSYSCALL - 1, VSYSCALL, VSYSCALL + PAGE - 1, VSYSCALL + PAGE}
        for canonical_width in (48, 57):
            half = 1 << (canonical_width - 1)
            points.update((half - 1, half, half + 1,
                           (1 << 64) - half - 1, (1 << 64) - half,
                           (1 << 64) - half + 1))
        for address in sorted(points):
            accepted = source_policy(address, threshold, width)
            rows.append(dict(threshold_bits=threshold_bits, width=width,
                             address=hex(address), source_allowed=accepted,
                             interval_allowed=interval_policy(address, threshold, width),
                             negative_only_allowed=accepted and bool(address >> 63)))

result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    source='vendor/linux-framework/arch/x86/mm/maccess.c:9-36',
    scope='Finite source arithmetic only. Widths/paging choices are scenarios, not measured guest facts. Negative-only is a rejected simplification. No candidate, compiler, guest or benchmark execution.',
    cases=len(rows), interval_disagreements=sum(r['source_allowed'] != r['interval_allowed'] for r in rows),
    negative_only_counterexamples=[r for r in rows if r['source_allowed'] != r['negative_only_allowed']],
    boundaries=rows)
Path(__file__).with_name('kernel-policy-boundaries.json').write_text(json.dumps(result, indent=2) + '\n')
print('boundary cases:', result['cases'], '; interval disagreements:', result['interval_disagreements'])
print('negative-only counterexamples:', len(result['negative_only_counterexamples']))
