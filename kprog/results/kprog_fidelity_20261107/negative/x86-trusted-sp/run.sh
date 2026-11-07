#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=${1:-$PWD/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp}
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/trusted-negative.exit"' EXIT
python3 - "$out" <<'PINS'
from pathlib import Path
import hashlib,json,sys,shutil
r=Path('/workspaces/repository');original=r/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp';o=Path(sys.argv[1]);o.mkdir(parents=True,exist_ok=True)
if o!=original:shutil.copy2(original/'cases.json',o/'cases.json')
files=['kprog/tv/build-kernel-x86/arch/x86/boot/bzImage','kprog/tv/build-x86/bpf_x86_native_lab.ko','kprog/x86/x86_sim_local_bpf.h','kprog/trusted_service.py','kprog/trusted_generation.py','kprog/x86/trusted_specializer.py','kprog/libnativeloader/build/trusted-native-loader','kprog/formal/build/fidelity-trusted/bound-probe','kprog/libnativeloader/src/native_loader.cpp']
(o/'guest-input-pins.json').write_text(json.dumps({f:hashlib.sha256((r/f).read_bytes()).hexdigest() for f in files},indent=2)+'\n')
PINS
taskset -c 20-23 vng --run "$PWD/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$PWD" --rwdir "$PWD" --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec "make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile guest RUN_OUT=$out"
