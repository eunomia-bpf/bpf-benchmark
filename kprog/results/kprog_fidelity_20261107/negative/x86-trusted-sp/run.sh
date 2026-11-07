#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$PWD/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/trusted-negative.exit"' EXIT
python3 - <<'PINS'
from pathlib import Path
import hashlib,json
r=Path('/workspaces/repository');o=r/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp'
files=['kprog/tv/build-kernel-x86/arch/x86/boot/bzImage','kprog/tv/build-x86/bpf_x86_native_lab.ko','kprog/x86/x86_sim_local_bpf.h','kprog/trusted_service.py','kprog/trusted_generation.py','kprog/x86/trusted_specializer.py','kprog/libnativeloader/build/trusted-native-loader','kprog/formal/build/fidelity-trusted/bound-probe','kprog/libnativeloader/src/native_loader.cpp']
(o/'guest-input-pins.json').write_text(json.dumps({f:hashlib.sha256((r/f).read_bytes()).hexdigest() for f in files},indent=2)+'\n')
PINS
taskset -c 20-23 vng --run "$PWD/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$PWD" --rwdir "$PWD" --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile guest'
