#!/usr/bin/env python3
"""Summarize retained helper-body timings; app timing remains separate."""
import argparse
import csv
import json
from pathlib import Path
from statistics import median

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('raw', type=Path)
p.add_argument('--output', type=Path, required=True)
a = p.parse_args()
series = {}
checks = []
for row in csv.reader((a.raw/'samples.csv').open()):
    if row[0] == 'check':
        checks.append(row)
    else:
        _, case, sample, arm, calls, elapsed, checksum = row
        series.setdefault(case, {}).setdefault(arm, []).append(dict(
            sample=int(sample), calls=int(calls), elapsed_ns=int(elapsed),
            ns_per_call=int(elapsed)/int(calls), checksum=int(checksum)))
for case in series.values():
    case['median_kernel_over_native'] = median(r['ns_per_call'] for r in case['kernel'])/median(
        r['ns_per_call'] for r in case['native'])
result = dict(raw=str(a.raw), extraction=json.loads((a.raw/'extraction.json').read_text()),
              checks=checks, series=series, exit_code=int((a.raw/'exit-code').read_text()),
              scope='Stable-node host helper-body diagnostic, ordinary returns; app and installed-byte effects pending.')
a.output.write_text(json.dumps(result, indent=2)+'\n')
for name, case in series.items():
    print(name, 'kernel', [round(r['ns_per_call'],3) for r in case['kernel']],
          'native', [round(r['ns_per_call'],3) for r in case['native']],
          'median kernel/native', round(case['median_kernel_over_native'],4))
