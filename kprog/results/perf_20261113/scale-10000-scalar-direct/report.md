# Scalar-direct 10,000-instruction scale case

The compiler terminated with signal 9 after 7,030.056 seconds, reporting peak
RSS 83,234,848 KiB. `compiler-resources.json` retains the exact command and
process measurements; `n10000_scalar_direct.json` records `proof_compile` as
the failing stage. The termination cause beyond the observed signal remains
unknown. This case contributes a compiler resource failure to the scale scan.

The previous handoff described this case as compiled; this receipt corrects
that description. Eight 100/1,000-instruction cases completed B compilation.
The original batch continues with scalar-indirect 10,000 instructions. The
complete scan and verifier execution remain open.

Raw inputs, empty compiler log and rebuild commands remain under
`/workspaces/kprog-raw/perf/20261114-scale-current/retry3`. This harness uses one
preprocessed translation unit; production uses chunk preprocessing. These
measurements describe this compiler case and its recorded 80 GiB address-space
budget, with production capacity requiring a matched replay.
