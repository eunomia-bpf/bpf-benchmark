#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/.." && pwd)

if [[ -f /home/yunwei37/workspace/.venv/bin/activate ]]; then
  # Keep the shell entrypoint aligned with the Python harness dependencies.
  source /home/yunwei37/workspace/.venv/bin/activate
fi

cd "${REPO_ROOT}"
exec sudo python3 corpus/run_corpus_tracing.py "$@"
