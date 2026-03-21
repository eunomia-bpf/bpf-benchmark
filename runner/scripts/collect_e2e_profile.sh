#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
source /home/yunwei37/workspace/.venv/bin/activate
cd "${repo_root}"

exec python3 runner/scripts/collect_e2e_profile.py "$@"
