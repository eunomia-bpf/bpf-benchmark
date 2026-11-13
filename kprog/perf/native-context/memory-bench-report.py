#!/usr/bin/env python3
"""Summarize retained host memory-routine timings; no production selection."""
import argparse
from collections import defaultdict
import json
from pathlib import Path
import statistics


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', type=Path)
    args = parser.parse_args()
    raw = json.loads(args.input.read_text())
    groups = defaultdict(lambda: defaultdict(list))
    for row in raw['observations']:
        groups[(row['copy'], row['length'], row['offset'])][row['form']].append(
            row['elapsed_ns'] / row['iterations'])
    result = []
    for (copy, length, offset), forms in sorted(groups.items()):
        medians = {form: statistics.median(values) for form, values in forms.items()}
        eligible = raw['host_cpuid']['fsrm' if copy else 'fsrs']
        available = {k:v for k,v in medians.items() if k != 'rep' or eligible}
        result.append(dict(copy=copy, length=length, offset=offset,
                           median_ns_per_call=medians, rep_hardware_eligible=eligible,
                           fastest_observed_eligible=min(available, key=available.get)))
    print(json.dumps(dict(source=str(args.input), host_cpuid=raw['host_cpuid'],
        observations=len(raw['observations']), cases=result,
        limits=['Hot host buffers with immediate read, five rounds and three alignments.',
                'These comparisons do not select production code and do not measure guest throughput.']), indent=2))


if __name__ == '__main__':
    main()
