#!/bin/bash
set -euo pipefail
cd /workspaces/repository/kprog/fidelity/build-sp-v3c/source/kprog/formal
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/local-sp-v3c-focused.exit"' EXIT
cp -a /workspaces/repository/kprog/fidelity/build-sp-v3/source/kprog/formal/.lake .lake
export PATH=/root/.elan/bin:/usr/local/cargo/bin:$PATH
taskset -c 16-19 lake build KProgFormal.CrossIsaStackArena KProgFormal.X86StackArmShape
printf "0\n" > "$state/local-sp-v3c-focused.exit"
python3 "$state/local-sp-v3c-full.py"
