"""Record stacks of an explicitly supplied running compiler without restarting it."""
import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import subprocess


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    proc = Path('/proc') / str(a.pid)
    records = []
    for i in range(3):
        record = dict(pid=a.pid, recorded_at=datetime.now(timezone.utc).isoformat(),
                      command=proc.joinpath('cmdline').read_bytes().decode().split('\0'),
                      status=proc.joinpath('status').read_text())
        command = ['gdb', '--batch', '--nx', '-q',
                   '-iex', 'set debuginfod enabled off',
                   '-ex', 'set pagination off', '-ex', 'set print frame-arguments none',
                   '-p', str(a.pid), '-ex', 'thread apply all bt 40', '-ex', 'detach']
        result = subprocess.run(command, capture_output=True, text=True)
        record.update(debugger_command=command, returncode=result.returncode,
                      stdout=result.stdout, stderr=result.stderr)
        records.append(record)
        (a.output / 'samples.json').write_text(json.dumps(records, indent=2) + '\n')
        result.check_returncode()
        print(result.stdout, flush=True)


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--pid', type=int, required=True)
    p.add_argument('--output', type=Path, required=True)
    main(p.parse_args())
