#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/.." && pwd)

for venv_dir in "${HOME}/workspace/.venv" "${HOME}/.venv" "${REPO_ROOT}/.venv" "${REPO_ROOT}/venv"; do
  if [[ -f "${venv_dir}/bin/activate" ]]; then
    # Keep the shell entrypoint aligned with the Python harness dependencies.
    source "${venv_dir}/bin/activate"
    break
  fi
done

cd "${REPO_ROOT}"
exec sudo python3 micro/driver.py corpus tracing "$@"
