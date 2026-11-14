"""Retain the loader's exit status independently of trace-cmd's exit status."""
from pathlib import Path
import subprocess
import sys


def run(status, command):
    result = subprocess.run(command)
    status.write_text(str(result.returncode)+'\n')
    return result.returncode


if __name__ == '__main__':
    if len(sys.argv) < 3:
        raise SystemExit('usage: scale_probe_status.py STATUS COMMAND [ARG ...]')
    raise SystemExit(run(Path(sys.argv[1]), sys.argv[2:]))
