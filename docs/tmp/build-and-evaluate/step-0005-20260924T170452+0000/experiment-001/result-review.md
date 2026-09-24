# Independent Result Review

Date: 2026-09-24
Reviewer mode: read-only, direct recomputation without importing the new audit
tool

## Verdict

- Run status: `invalid/inconclusive` for the pre-registered mechanism audit;
  the underlying KVM benchmark itself completed successfully.
- Tested hypothesis: inconclusive because the retained workdirs lack the
  pre-registered before/after bytecode pair.
- Research value: dependency/provenance finding.
- Paper impact: mechanism-evidence boundary, not additional RQ evidence.
- Paper decision: do not add the 122-load mechanism claim or the single
  `1.0295093736067695` ratio to the main results.

## Independent recomputation

The reviewer verified completed x86 KVM corpus metadata, `SAMPLES=1`, a
30-second workload, the sole `map_inline` pass, Cilium status `ok`, load-time
mode, source revision `38476c24f6caf50b64956c4b44e80f464096dc78`, the
recorded `make corpus` entrypoint, and exit code zero.

The 169 parseable JSONL rows refer to 169 unique workdirs: 122 changed load
instances and 47 unchanged instances.  Across changed rows, the reports record
154,340 before instructions, 106,270 after instructions, delta -48,070, and
3,787 matched/applied sites with zero skipped.  The 19 reported name/type
groups are truncated runtime names and counts of repeated load instances, not
19 unique static programs.  Embedded reports match their `report.0.json`
files.

The 122 changed reports and 122 `loadtime optimized` events form a strict
workdir-level bijection.  Program names and instruction counts match.  Each
event has exactly one following same-PID/TID `PROG_LOAD` result: all 122 return
a nonnegative fd with errno zero and a unique kernel program ID.  There are no
candidate rejection or unpaired optimized events.  Ten separate
original-bytecode preflight rejections are pass-throughs, not optimized
candidate failures.  This log chain shows stock load/verifier/JIT acceptance;
it does not establish per-program attachment or execution.

The file oracle fails uniformly.  All 122 changed `input.bin` files equal the
reported after-size, zero equal the before-size, and no changed workdir retains
`output.next.0.bin`.  The workdirs contain 2,586 files and 2,475,653 bytes.
At the recorded revision, `shim_loadtime.h` renames each step output over
`input.bin`, so the before images cannot be recovered from this artifact.

The workload recomputation is:

| Phase | Forward pps | Reverse pps | Total pps | Packets | Errors |
| --- | ---: | ---: | ---: | ---: | ---: |
| Baseline | 771,777 | 805,044 | 1,576,821 | 47,214,527 | 0 |
| Policy | 794,992 | 828,360 | 1,623,352 | 48,606,246 | 0 |

The single paired policy/baseline ratio is `1.0295093736067695`.  Both phases
have exactly the forward/reverse kernel-pktgen leaves, return code zero, and
`Result: OK`.  This is a descriptive single observation, not a repeated
performance estimate and not a causal comparison with the July batches.

## Provenance correction and next action

The whole run directory is local and untracked, but not uniformly ignored:
core JSON/report/provenance files are untracked, while shim logs and workdirs
are ignored by `corpus/.gitignore`.  None is known to be public.

The decisive next action is to preserve immutable per-step input and output
bytecode when workdir retention is enabled, then rerun Cilium `map_inline`
through `make corpus`.  Re-analysis cannot reconstruct the lost before image.
