#!/usr/bin/env python3
"""Retain the actual-header regression result and return its status."""
import json
from pathlib import Path
import subprocess
import sys
out=Path(sys.argv[1])
invocation=[str(out/'fixture')]
with (out/'stdout').open('w') as stdout,(out/'stderr').open('w') as stderr:
    status=subprocess.run(invocation,stdout=stdout,stderr=stderr).returncode
(out/'execution.json').write_text(json.dumps(dict(invocation=invocation,returncode=status),indent=2)+'\n')
print((out/'stdout').read_text(),end='')
sys.exit(status)
