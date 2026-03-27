#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="/home/yunwei37/workspace/bpf-benchmark"
STAMP="$(date +%Y%m%d_%H%M%S)"
OUT_DIR="${ROOT_DIR}/docs/tmp/20260327/e2e_single_pass_runs_${STAMP}"
DURATION="${E2E_DURATION:-5}"
mkdir -p "${OUT_DIR}"

passes=("$@")
if [[ ${#passes[@]} -eq 0 ]]; then
  passes=(map_inline const_prop dce)
fi

cd "${ROOT_DIR}"

for pass in "${passes[@]}"; do
  log_path="${OUT_DIR}/${pass}.log"
  printf '=== running vm-e2e with pass %s duration %s ===\n' "${pass}" "${DURATION}" | tee "${log_path}"
  make vm-e2e E2E_ARGS="--rejit-passes ${pass} --duration ${DURATION}" 2>&1 | tee -a "${log_path}"
done

printf 'logs: %s\n' "${OUT_DIR}"
