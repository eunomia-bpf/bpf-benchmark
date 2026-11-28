#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/x86-otel-perf-20261127/profile-20261128T033629Z
trap 'printf "%s\n" "$?" > "$out/preservation-exit.txt"' EXIT
python3 kprog/results/x86-otel-perf-20261127/analyse_profile.py "$out" > "$out/pmu-analysis.log" 2>&1
python3 kprog/results/x86-otel-perf-20261127/collect_profile.py > "$out/collection.log" 2>&1
