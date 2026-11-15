#!/usr/bin/env python3
"""Join offline root sample offsets with byte-matched retained source instructions.

The native retained subset excludes expanded instructions and generated helpers.
The JIT text still contains inlined helpers; its BTF line attribution is sampled
debug information, not a semantic boundary between helpers and application work.
These scopes cannot establish a pure-body speedup by dividing their totals.
"""
import argparse
import bisect
from collections import Counter
import json
from pathlib import Path


def main(a):
    analysis = json.loads(a.analysis.read_text())
    mapping = json.loads(a.source_map.read_text())
    native, = [p for p in analysis['phases']['post_rejit']['programs'] if p['id'] == mapping['program']]
    intervals = mapping['retained_source_intervals']
    starts = [r['start'] for r in intervals]
    periods, sizes = Counter(), Counter()
    for row in intervals:
        sizes[row['symbol']] += row['end']-row['start']
    for offset, period in native['offset_period_ns']:
        index = bisect.bisect_right(starts, offset)-1
        symbol = intervals[index]['symbol'] if index >= 0 and offset < intervals[index]['end'] else '[unmapped/expanded/runtime]'
        periods[symbol] += period
    count = native['measured_counters']['run_cnt_delta']
    baseline, = [p for p in analysis['phases']['baseline']['programs'] if p['measured_counters']]
    captured, = [p for p in json.loads(a.baseline_capture.read_text())['programs'] if p['id'] == baseline['id']]
    lines = sorted(captured['lines'], key=lambda r: r['address'])
    addresses = [r['address'] for r in lines]
    source_periods = Counter()
    for offset, period in baseline['offset_period_ns']:
        remaining = offset
        for function in captured['functions']:
            if remaining < function['length']:
                address = function['address']+remaining
                index = bisect.bisect_right(addresses, address)-1
                if index >= 0 and lines[index]['address'] >= function['address']:
                    line = lines[index]
                    source_periods[(line['file'], line['line'], line['text'])] += period
                else:
                    source_periods[('[no BTF line in function]', 0, '')] += period
                break
            remaining -= function['length']
        else:
            raise ValueError('Sample offset outside captured functions')
    observation = {k: v for k, v in mapping.items() if k != 'retained_source_intervals'}
    result = dict(scope=__doc__, source_map=observation,
        native_retained_output_bytes=dict(sizes), native_root_period_ns=dict(periods),
        native_sampled_ns_per_call={k: v/count for k, v in periods.items()},
        baseline_sampled_text_ns_per_call=baseline['sampled_text_ns_per_call'],
        native_sampled_text_ns_per_call=native['sampled_text_ns_per_call'],
        baseline_top_btf_lines=[dict(file=f, line=l, text=t, period_ns=n,
            sampled_ns_per_call=n/baseline['measured_counters']['run_cnt_delta'])
            for (f, l, t), n in source_periods.most_common(20)],
        phases={phase: dict(samples=r['samples'], windows=r['windows'],
            measured_programs=[dict(id=p['id'], counters=p['measured_counters'],
                root_period_ns_on_program_chain=p['root_period_ns_on_program_chain'])
                for p in r['programs'] if p['measured_counters']])
                for phase, r in analysis['phases'].items()})
    a.output.write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('analysis', 'source-map', 'baseline-capture', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
