# Tetragon retained B stack pressure

Inspect request 6's retained O1 pre-PEI MIR after the existing scalar packing
pass. The earlier emission diagnostic found a 5,776-byte direct R10 depth;
production compilation failed at 4,096 bytes, before stock verification.
Neither limit nor the simulator source changes in this experiment.

`inspect.py` reads the MIR once, records declared objects and computes
conservative backward whole-slot liveness over its actual CFG. Address-taken,
partial and unfamiliar slot accesses are excluded from the lifetime claim.
The analysis reports peaks, rather than assuming every declared spill is
live at once. It does not establish path feasibility, a safe coloring, stock
acceptance or any runtime gain. Its join/loop/partial-store regression passes.

Run through the local Makefile under timing SH on CPU 19 with an 8 GiB
address-space bound. Retain the source revision, commands, output and status
under `/workspaces/kprog-raw/perf/tetragon-stack-liveness-20261119/`.
