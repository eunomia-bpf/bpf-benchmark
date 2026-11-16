#!/bin/sh
# Deprecated entry point: kept so the name in older notes still works.
#
# The capture moved to kprog/perf/otel-unwind-counters.sh, which boots the guest
# itself and no longer depends on the entry's `corpus` target passing a guest
# command through. This wrapper is that script verbatim and takes the same
# argument: an output directory under the repository (the only host path the
# guest has).
#
# Usage: otel-rodata-phases.sh <output-dir-under-repo>
exec sh "$(dirname "$0")/../../otel-unwind-counters.sh" "$@"