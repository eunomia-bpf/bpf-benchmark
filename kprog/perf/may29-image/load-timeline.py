#!/usr/bin/env python3
"""Decode existing shim logs into per-thread program-load durations, offline.

Each completion is paired with its own PID/TID's BPF_PROG_LOAD. Unfinished
requests remain explicit; this tool neither changes startup nor admits runs.
"""
import argparse
import json
from pathlib import Path
import re

LINE = re.compile(r'^\[([0-9.]+) pid=(\d+) tid=(\d+)\] (.*)$')
START = re.compile(r'BPF_PROG_LOAD type=(\d+) \(([^)]+)\) name=(\S*) insn_cnt=(\d+)')
END = re.compile(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)')


def timeline(path):
    pending = {}
    completed = []
    unmatched = []
    for number, line in enumerate(path.read_text().splitlines(), 1):
        match = LINE.match(line)
        if not match:
            continue
        timestamp, pid, tid, message = match.groups()
        thread = (int(pid), int(tid))
        start = START.match(message)
        end = END.match(message)
        if start:
            if thread in pending:
                unmatched.append(pending.pop(thread))
            kind, kind_name, name, instructions = start.groups()
            pending[thread] = dict(start_seconds=float(timestamp), pid=thread[0],
                                  tid=thread[1], line=number, type=int(kind),
                                  type_name=kind_name, name=name,
                                  instructions=int(instructions), native=False)
        elif message.startswith('native-loader replaced prog=') and thread in pending:
            pending[thread]['native'] = True
        elif end:
            if thread not in pending:
                unmatched.append(dict(completion_line=number, pid=thread[0], tid=thread[1]))
                continue
            record = pending.pop(thread)
            fd, error, ident = map(int, end.groups())
            record.update(end_seconds=float(timestamp), fd=fd, errno=error, id=ident)
            record['elapsed_seconds'] = record['end_seconds'] - record['start_seconds']
            completed.append(record)
    return dict(log=str(path), clock='shim monotonic seconds', completed=completed,
                unmatched=unmatched + list(pending.values()))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('logs', type=Path, nargs='+')
    args = parser.parse_args()
    print(json.dumps([timeline(path) for path in args.logs], indent=2))


if __name__ == '__main__':
    main()
