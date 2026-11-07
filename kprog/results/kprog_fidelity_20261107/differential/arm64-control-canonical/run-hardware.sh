#!/bin/sh
# Run the saved static AArch64 CPU observer on actual ARM hardware.
set -eu
cd "$(dirname "$0")"
exec make cpu-hardware OUT="${OUT:-$PWD/hardware-fresh}"
