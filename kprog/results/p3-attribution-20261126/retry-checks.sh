#!/bin/bash
set -euo pipefail
cd /workspaces/repository
tail --pid="$1" --sleep-interval=5 -f /dev/null
exec make -C kprog/results/p3-attribution-20261126 checks OUT="$2"
