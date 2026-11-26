"""Inventory host PID/TID ownership of guest samples in these cycles captures."""
import collections
import json
import mmap
from pathlib import Path
import struct
import sys

def records(path):
    with path.open('rb') as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
        assert data[:8] == b'PERFILE2', data[:8]
        offset, length = struct.unpack_from('<QQ', data, 40)
        end = offset + length
        assert end <= len(data)
        while offset < end:
            kind, misc, size = struct.unpack_from('<IHH', data, offset)
            assert size >= 8 and offset + size <= end
            yield kind, misc, offset, size, data
            offset += size

def sample(data, offset, size):
    # evlist.txt: IDENTIFIER, IP, TID, TIME, CPU, CALLCHAIN.
    identifier, ip, pid, tid, time, cpu, reserved, nr = struct.unpack_from('<QQIIQIIQ', data, offset + 8)
    assert 56 + nr * 8 == size, (size, nr)
    frames = struct.unpack_from('<' + 'Q' * nr, data, offset + 56)
    return identifier, ip, pid, tid, time, cpu, frames

def inventory(target):
    out = Path(target)
    counters = collections.Counter()
    comms = collections.defaultdict(set)
    sample_examples = {}
    for kind, misc, offset, size, data in records(out / 'host-perf.data'):
        if kind == 3:  # PERF_RECORD_COMM (pid, tid, NUL-terminated comm).
            pid, tid = struct.unpack_from('<II', data, offset + 8)
            if pid:
                comms[pid].add(data[offset + 16:offset + size].split(b'\0', 1)[0].decode(errors='replace'))
        elif kind == 9 and misc & 7 in (4, 5):
            identifier, ip, pid, tid, time, cpu, frames = sample(data, offset, size)
            counters[pid] += 1
            if pid not in sample_examples:
                sample_examples[pid] = dict(tid=tid, time=time, cpu=cpu, ip=hex(ip), identifier=identifier)
    report = dict(scope='All guest samples on recorded host CPUs, before ownership selection.',
                  samples=sum(counters.values()),
                  owners=[dict(pid=p, samples=n, comms=sorted(comms[p]), example=sample_examples[p])
                          for p, n in counters.most_common()])
    (out / 'pmu-owners.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))

if __name__ == '__main__':
    for target in sys.argv[1:]:
        inventory(target)
