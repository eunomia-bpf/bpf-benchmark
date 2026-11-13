#!/usr/bin/env python3
"""Count inclusive stack observations in retained `perf script` text.

Groups overlap. Sample periods are CPU event weights, never elapsed wall time.
Samples without recovered frames remain in every denominator.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import re

HEADER = re.compile(r'^(.+?)\s+(\d+)\s+(\d+\.\d+):\s+(\d+)\s+(\S+):\s*$')
FRAME = re.compile(r'^\s+[a-fA-F0-9]+\s+(.+)\s+\((.+)\)$')
GROUPS = dict(readlink='do_readlinkat', verifier='bpf_check',
              getdents='__x64_sys_getdents64', map_info='bpf_map_get_info_by_fd',
              native_load='native_loader::load_from_fd(native_loader::FdLoadOptions const&)')


def samples(text):
    rows = []
    for line in text.splitlines():
        if not line.strip() or line.startswith('#'):
            continue
        header = HEADER.match(line)
        if header:
            comm, tid, timestamp, period, event = header.groups()
            rows.append(dict(comm=comm, tid=int(tid), seconds=float(timestamp),
                             period=int(period), event=event, frames=[]))
            continue
        frame = FRAME.match(line)
        if not rows or not frame:
            raise ValueError(f'unrecognized perf script line: {line}')
        symbol, dso = frame.groups()
        symbol = re.sub(r'\.(?:isra|constprop)\.\d+$', '', symbol.rsplit('+0x', 1)[0])
        rows[-1]['frames'].append(dict(symbol=symbol, dso=dso))
    return rows


def summarize(rows):
    groups = {}
    for name, symbol in GROUPS.items():
        selected = [r for r in rows if any(f['symbol'] == symbol for f in r['frames'])]
        groups[name] = dict(samples=len(selected), period_sum=sum(r['period'] for r in selected),
                            with_native_load=sum(any(f['symbol'] == GROUPS['native_load']
                                                     for f in r['frames']) for r in selected),
                            tids=dict(Counter(r['tid'] for r in selected)))
    return dict(samples=len(rows), period_sum=sum(r['period'] for r in rows),
                events=dict(Counter(r['event'] for r in rows)),
                tids=dict(Counter(r['tid'] for r in rows)),
                empty_stacks=sum(not r['frames'] for r in rows),
                with_file_backed_frames=sum(any(f['dso'].startswith('/') for f in r['frames']) for r in rows),
                groups=groups, limits=['Groups overlap; each group counts a sample once.',
                                      'Periods are CPU event weights, not guest elapsed or loader wall cost.',
                                      'Unknown or empty stacks remain in the sample denominator.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('script', type=Path)
    args = parser.parse_args()
    print(json.dumps(dict(source=str(args.script), **summarize(samples(args.script.read_text()))), indent=2))


if __name__ == '__main__':
    main()
