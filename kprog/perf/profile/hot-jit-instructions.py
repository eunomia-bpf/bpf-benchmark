#!/usr/bin/env python3
"""Decode root samples against the exact live JIT bytes in both measured arms.

CPU-clock attribution has sampling skid and possible periodic aliasing. A hot
load or an instruction after a call is not proof of load latency or call cost.
Stack-address syntax does not establish compiler spills. Retained native source
intervals leave all expanded/synthetic instructions explicitly unmapped.
"""
import argparse
import bisect
from collections import Counter
import importlib.util
import json
from pathlib import Path
import subprocess

spec = importlib.util.spec_from_file_location('instruction_costs', Path(__file__).with_name('instruction-costs.py'))
costs = importlib.util.module_from_spec(spec)
spec.loader.exec_module(costs)


def main(a):
    result = dict(scope=__doc__, phases={})
    analysis = json.loads(a.analysis.read_text())
    source_map = json.loads(a.source_map.read_text())
    regions = source_map['retained_source_intervals']
    region_starts = [r['start'] for r in regions]
    a.output.mkdir(parents=True, exist_ok=True)
    for phase in ('baseline', 'post_rejit'):
        measured, = [p for p in analysis['phases'][phase]['programs'] if p['measured_counters']]
        live, = [p for p in json.loads((a.capture/f'{phase}.jit-lines.json').read_text())['programs']
                  if p['id'] == measured['id']]
        binary = a.capture/live['binary']
        command = ['objdump', '-D', '-z', '-w', '--no-show-raw-insn', '-b', 'binary', '-m', 'i386:x86-64', str(binary)]
        dump = subprocess.run(command, text=True, capture_output=True, check=True)
        (a.output/f'{phase}.asm').write_text(dump.stdout)
        instructions = costs.instructions(dump.stdout, 0, live['jited_bytes'])
        addresses = [r['address'] for r in instructions]
        periods, blocks, categories = Counter(), Counter(), Counter()
        for offset, period in measured['offset_period_ns']:
            index = bisect.bisect_right(addresses, offset)-1
            if index < 0 or not instructions[index]['address'] <= offset < instructions[index]['end']:
                raise ValueError('Sample falls outside decoded instruction extent')
            periods[index] += period
            blocks[offset//64*64] += period
            categories[costs.category(instructions[index]['asm'])] += period
        rows = []
        count = measured['measured_counters']['run_cnt_delta']
        for index, period in periods.most_common(30):
            instruction = instructions[index]
            row = dict(offset=instruction['address'], bytes=instruction['end']-instruction['address'],
                asm=instruction['asm'], period_ns=period, sampled_ns_per_call=period/count,
                context=instructions[max(0,index-3):index+4])
            if phase == 'post_rejit':
                region = bisect.bisect_right(region_starts, instruction['address'])-1
                row['retained_source'] = regions[region] if region >= 0 and instruction['address'] < regions[region]['end'] else None
            else:
                offset = instruction['address']
                for function in live['functions']:
                    if offset < function['length']:
                        absolute = function['address']+offset
                        lines = [line for line in live['lines']
                                 if function['address'] <= line['address'] <= absolute]
                        row['btf_source'] = max(lines, key=lambda line: line['address']) if lines else None
                        break
                    offset -= function['length']
            rows.append(row)
        result['phases'][phase] = dict(id=measured['id'], bytes=live['jited_bytes'],
            measured_counters=measured['measured_counters'],
            sampled_text_ns_per_call=measured['sampled_text_ns_per_call'],
            category_sampled_ns_per_call={k:v/count for k,v in categories.items()},
            hot_64byte_blocks=[dict(offset=o, sampled_ns_per_call=n/count) for o,n in blocks.most_common(20)],
            hot_instructions=rows, disassembly_command=command)
    (a.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('capture', 'analysis', 'source-map', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
