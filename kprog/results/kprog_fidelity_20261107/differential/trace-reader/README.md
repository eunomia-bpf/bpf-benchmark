# Differential observer trace diagnostics

The generic reader preserves the observer return code and validates the complete
stream before loading native-code metadata or opening canonical result streams.
A zero-byte observer result reports the return code, header byte count and trace
byte count. Header and record-length errors carry their observed and expected
values. A complete trace from an observer reporting state differences proceeds
through the canonical comparison and retains the observer failure result.

## Results

| Check group | Checks | Outcome |
| --- | ---: | --- |
| Archived empty trace, format boundaries, both ARM state sizes, preserved reports and observer exit propagation | 17 | pass |
| ARM candidate trace canonical replay | 8 forms / 8,192 states | exact published reports |
| x86 production trace canonical replay | 32 forms / 32,768 states | exact published reports |

All 19 checks passed; canonical replay covers 40,960 archived states. Each ISA's
reference-forms table, mismatch stream and unavailable stream equals the
published cohort byte for byte. Both replay logs report zero differences and
zero forms awaiting reference. ARM retains the private generic candidate source
epoch from acd62b43; x86 retains the production numeric-token epoch from 0cdf0b7f.
These replays check the reader against existing observations. Production ARM
adoption continues with A/V contract, source and universal-model synchronization.

The state decoder, state comparison, control extents and control witness functions
retain identical ASTs; source-review.json records the before/after source hashes.
The original buffered ARM abort produced a zero-byte trace, archived in
../arm64-numeric-tokens/baseline-attempts.tar.gz. The check extracts those exact
bytes. Fresh observer exits -6, 1 and 0 are injected at the process boundary with
that archived trace; each raises a header diagnostic, makes zero canonical calls
and preserves an existing result file. The full trace with observer exit 1 passes
layout inspection, keeping architectural mismatches available for comparison.

The first regression attempt assumed an 840-byte numeric ARM state. Inspection
of the original stream established its 344-byte state. The corrected regression
checks that observed layout and an additional generic 840-byte vector layout.
initial-check.log.gz retains the original assertion failure.

## Inputs and reproduction

summary.json records the exact reference, trace and reader identities, commands
and per-check diagnostics. Original source/static archives remain with the two
numeric-token cohorts. The executable reference is V's frozen c110b03a snapshot.
Run from /workspaces/repository:

~~~sh
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/differential/trace-reader/check.py \
  --out kprog/results/kprog_fidelity_20261107/differential/trace-reader
~~~

The local Workspace retains the full ARM trace (14,876,696 bytes) and x86 trace
(59,506,712 bytes), the frozen reference and both observer build caches. Each
successful replay writes its reference table, diagnostic streams and run log
under this directory. Compressed run/exit/closure receipts preserve the completed
background job 3686299, which exited 0 at 2026-11-07T20:17:31Z.
