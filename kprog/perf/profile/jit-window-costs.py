#!/usr/bin/env python3
"""Offline CPU-clock attribution using live JIT ranges and shim measurement clocks.

Program text includes inlined helpers. Inclusive callchain categories overlap;
missing frames do not establish absent work. Period sums are sampling estimates,
not replacements for BPF counters or measurements of pure application bodies.
"""
import argparse
import bisect
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import subprocess

import symbolize


def records(lines):
    stamp, period, chain = None, None, []
    for line in lines:
        if not line.strip():
            if stamp is not None:
                if not chain:
                    raise ValueError('Sample has no IP')
                yield stamp, period, chain
            stamp, period, chain = None, None, []
        elif match := re.fullmatch(r'\s*([0-9]+\.[0-9]+):\s+(\d+)\s*', line):
            if stamp is not None:
                raise ValueError('Missing sample separator')
            stamp, period = float(match[1]), int(match[2])
        else:
            if stamp is None:
                raise ValueError('IP without sample header: '+line)
            chain.append(int(line.strip(), 16))
    if stamp is not None:
        if not chain:
            raise ValueError('Final sample has no IP')
        yield stamp, period, chain


def intervals(path):
    windows, start = [], None
    for line in path.read_text().splitlines():
        match = re.match(r'\[([0-9.]+) .*?socket: cmd=measure_(start|finish)\b', line)
        if not match:
            continue
        stamp, event = float(match[1]), match[2]
        if event == 'start':
            if start is not None:
                raise ValueError('Nested measurement starts')
            start = stamp
        else:
            if start is None or stamp < start:
                raise ValueError('Unmatched measurement finish')
            windows.append((start, stamp))
            start = None
    if start is not None or not windows:
        raise ValueError('Incomplete measurement clocks')
    return windows


def analyze(args):
    app = json.loads((args.run/'details/apps'/f'{args.app}.json').read_text())
    result = dict(scope=__doc__, app_status=app['status'], phases={})
    args.output.mkdir(parents=True, exist_ok=True)
    for phase in ('baseline', 'post_rejit'):
        live = json.loads((args.directory/f'{phase}.jit-lines.json').read_text())
        table, names, _ = symbolize.load_kallsyms(args.directory/f'{phase}.kallsyms')
        ranges, programs = [], {}
        for p in live['programs']:
            raw = (args.directory/p['binary']).read_bytes()
            if len(raw) != p['jited_bytes'] or hashlib.sha256(raw).hexdigest() != p['sha256']:
                raise ValueError('Captured binary differs from live metadata')
            programs[p['id']] = dict(id=p['id'], name=p['name'], sha256=p['sha256'],
                bytes=p['jited_bytes'], functions=p['functions'], samples=0, period_ns=0,
                offsets=Counter())
            if sum(f['length'] for f in p['functions']) != len(raw):
                raise ValueError('Captured function lengths do not cover binary')
            offset = 0
            for f in p['functions']:
                ranges.append((f['address'], f['address']+f['length'], p['id'], offset))
                offset += f['length']
        ranges.sort()
        if any(a[1] > b[0] for a, b in zip(ranges, ranges[1:])):
            raise ValueError('Overlapping live JIT functions')
        starts = [r[0] for r in ranges]

        def resolve(ip):
            i = bisect.bisect_right(starts, ip)-1
            if i >= 0 and ip < ranges[i][1]:
                first, _, ident, offset = ranges[i]
                return f"jit:{ident}:{programs[ident]['name']}", ident, offset+ip-first
            if ip < 0xffff800000000000:
                return '[user-or-low-ip]', None, None
            i = bisect.bisect_right(table, ip)-1
            if i < 0 or ip-table[i] > (1 << 21):
                return '[unknown-kernel]', None, None
            return names[i], None, None

        windows = intervals(args.run/'details/shim-logs'/f'{args.app}.{phase}.log')
        roots, root_periods, inclusive, inclusive_periods = [Counter() for _ in range(4)]
        under_jit = {ident: Counter() for ident in programs}
        commands, samples, periods = [], 0, 0
        for first, last in windows:
            command = [str(args.perf), 'script', '-i', str(args.directory/f'{phase}.data'),
                       '-F', 'time,period,ip', '--no-inline', '--time', f'{first},{last}']
            commands.append(command)
            with (args.output/f'{phase}.perf-script.stderr').open('w') as error:
                child = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=error, text=True)
                for stamp, period, chain in records(child.stdout):
                    if not first <= stamp <= last:
                        raise ValueError('perf emitted a sample outside requested clocks')
                    resolved = [resolve(ip) for ip in chain]
                    symbol, ident, offset = resolved[0]
                    samples += 1
                    periods += period
                    roots[symbol] += 1
                    root_periods[symbol] += period
                    for sym in {r[0] for r in resolved}:
                        inclusive[sym] += 1
                        inclusive_periods[sym] += period
                    for parent in {r[1] for r in resolved if r[1] is not None}:
                        under_jit[parent][symbol] += period
                    if ident is not None:
                        p = programs[ident]
                        p['samples'] += 1
                        p['period_ns'] += period
                        p['offsets'][offset] += period
                child.stdout.close()
                if child.wait():
                    raise subprocess.CalledProcessError(child.returncode, command)
        measured = app[phase]['bpf']
        for p in programs.values():
            p['offset_period_ns'] = sorted(p.pop('offsets').items())
            p['measured_counters'] = measured.get(str(p['id']))
            p['root_period_ns_on_program_chain'] = dict(under_jit[p['id']].most_common())
            if p['measured_counters'] and p['measured_counters']['run_cnt_delta']:
                p['sampled_text_ns_per_call'] = p['period_ns']/p['measured_counters']['run_cnt_delta']
        result['phases'][phase] = dict(windows=windows, commands=commands,
            capture_errors=live['errors'], samples=samples, sampled_period_ns=periods,
            root_symbols=dict(roots.most_common()), root_period_ns=dict(root_periods.most_common()),
            inclusive_symbols=dict(inclusive.most_common()),
            inclusive_period_ns=dict(inclusive_periods.most_common()), programs=list(programs.values()))
    (args.output/'result.json').write_text(json.dumps(result, indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('directory', 'run', 'perf', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--app', required=True)
    analyze(parser.parse_args())
