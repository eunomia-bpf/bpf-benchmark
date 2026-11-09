#!/bin/bash
set -eu
repo=$(git rev-parse --show-toplevel)
cd "$repo/kprog/formal"
scratch=/var/tmp/kprog-tmp/S13-replay
export scratch
mkdir -p "$scratch/KProgFormal"
python3 - <<'PY'
from pathlib import Path
import os
root=Path(os.environ['scratch'])/'KProgFormal'
for source in Path('.lake/build/lib/lean/KProgFormal').iterdir():
    if source.name.startswith('ControlABI.'):
        continue
    destination=root/source.name
    if not destination.exists() and not destination.is_symlink():
        destination.symlink_to(source.resolve(),target_is_directory=source.is_dir())
PY
export LEAN_PATH="$scratch:$repo/kprog/formal/.lake/build/lib/lean:$repo/kprog/tv/build"
taskset -c 8-23 lean -o "$scratch/KProgFormal/ControlABI.olean" KProgFormal/ControlABI.lean
taskset -c 8-23 lean -R ../tv -o "$scratch/ControlABIComposition.olean" ../tv/ControlABIComposition.lean
taskset -c 8-23 lean ../results/kprog_control_abi_20261109/Audit.lean
