#!/bin/bash
set -euo pipefail
cd /workspaces/repository
here=corpus/results/kprog_app_coverage_20261107/per-run-profile
mountpoint -q /sys/fs/bpf || mount -t bpf bpf /sys/fs/bpf
pin=/sys/fs/bpf/kprog-c-jit-dump-control
trap 'rm -f "$pin"' EXIT
vendor/build/x86/bpftool/bin/bpftool prog load "$here/dump-control.bpf.o" "$pin" type xdp
id=$(vendor/build/x86/bpftool/bin/bpftool -j prog show pinned "$pin" | python3 -c 'import json,sys;j=json.load(sys.stdin);print((j[0] if isinstance(j,list) else j)["id"])')
"$here/fixed-run" dump "$id" 0 "$here/dump-control.jit.bin" > "$here/dump-control.info.json"
vendor/build/x86/bpftool/bin/bpftool prog run pinned "$pin" data_in corpus/inputs/katran_vip_packet_64.bin > "$here/dump-control.run.json"
python3 - <<'PY'
import json
from pathlib import Path
p=Path('corpus/results/kprog_app_coverage_20261107/per-run-profile')
j=json.load(open(p/'dump-control.info.json'));b=(p/'dump-control.jit.bin').read_bytes()
assert len(b)==j['jited_len'] and len(b)>0 and any(b)
print('Actual BPF-prog-info JIT bytes captured:',len(b),'program',j['id'])
PY
