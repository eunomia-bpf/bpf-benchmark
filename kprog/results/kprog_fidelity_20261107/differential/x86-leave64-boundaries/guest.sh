#!/bin/bash
set -euo pipefail
cd /workspaces/repository
O=kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries
B=kprog/fidelity/build-x86-leave64-boundaries
Q="$O/kvm-clearcpuid-lass"
uname -a > "$Q/host.txt"
lscpu >> "$Q/host.txt"
python3 - "$Q" <<'PY'
from pathlib import Path
import json,sys
flags=next(l.split(':',1)[1].split() for l in Path('/proc/cpuinfo').read_text().splitlines() if l.startswith('flags'))
(Path(sys.argv[1])/'linux-profile.json').write_text(json.dumps(dict(lass_linux_flag='lass' in flags,la57_linux_flag='la57' in flags,kernel_cmdline=Path('/proc/cmdline').read_text().strip()),indent=2)+'\n')
PY
"$B/leave64" "$Q" --boundaries
"$B/address-control" "$O/control-inputs.tsv" "$Q"
