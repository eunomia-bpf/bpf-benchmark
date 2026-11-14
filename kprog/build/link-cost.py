#!/usr/bin/env python3
"""Opt-in selected-linker child timing; workload execution remains in Make.

The installed copy reads its adjacent config.json. Each invocation retains its
exact child argv, clocks, CPU usage and exit code in a unique report. Timings
exclude this Python process's startup and therefore do not measure the full
loader path. The original linker owns all generated native bytes.
"""
import datetime
import json
import os
from pathlib import Path
import resource
import subprocess
import sys
import time


def main():
    directory = Path(__file__).resolve().parent
    config = json.loads((directory / 'config.json').read_text())
    command = [config['linker'], *sys.argv[1:]]
    start = time.clock_gettime_ns(time.CLOCK_MONOTONIC)
    wall = datetime.datetime.now(datetime.timezone.utc).isoformat()
    result = subprocess.run(command)
    finish = time.clock_gettime_ns(time.CLOCK_MONOTONIC)
    usage = resource.getrusage(resource.RUSAGE_CHILDREN)
    record = dict(pid=os.getpid(), command=command, wall_start=wall,
                  start_monotonic_ns=start, end_monotonic_ns=finish,
                  elapsed_seconds=(finish - start) / 1e9, returncode=result.returncode,
                  child_usage=dict(user_seconds=usage.ru_utime, system_seconds=usage.ru_stime,
                                   max_rss_kib=usage.ru_maxrss, minor_faults=usage.ru_minflt,
                                   major_faults=usage.ru_majflt, voluntary_switches=usage.ru_nvcsw,
                                   involuntary_switches=usage.ru_nivcsw))
    (directory / f'invocation-{start}-{os.getpid()}.json').write_text(json.dumps(record, indent=2) + '\n')
    return result.returncode if result.returncode >= 0 else 128 - result.returncode


if __name__ == '__main__':
    sys.exit(main())
