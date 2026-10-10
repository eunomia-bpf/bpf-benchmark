#!/usr/bin/env python3
"""Make's VM_EXECUTABLE override: retain its command and add fixed vCPU pins."""
import os
from pathlib import Path
import shlex
import sys

args = sys.argv[1:]
index = args.index('--exec') + 1
audit = Path(__file__).with_name('guest-audit.py')
run = Path(os.environ['CILIUM_AUDIT_RUN'])
(run/'make-input.txt').write_text(args[index]+'\n')
args[index] = shlex.join(['python3', str(audit), str(run)])
os.execv('/opt/virtme-ng/bin/vng', ['vng', '--pin', '1,4,0,3', '--rwdir', str(audit.parent), *args])
