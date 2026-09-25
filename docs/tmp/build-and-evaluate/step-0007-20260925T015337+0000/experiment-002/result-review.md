# Result Review: Cilium `map_inline` Snapshot Attribution

Date: 2026-09-25T02:29:00+00:00
Verdict: valid, hypothesis supported
Research value: supporting mechanism boundary
Paper impact: narrow RQ2 observation only

The independent reviewer recomputed the result directly from the raw report
stream and retained workdirs without importing the analyzer.  The artifact has
169 report rows: 47 with zero applied sites and 122 changed load instances.
The reports contain 3,787 applied sites and exactly 3,787 inlined-entry records,
with no matched/applied/skipped or entry-cardinality mismatch.

All 3,787 entries joined through their report workdir to 122 unique map
metadata files and 122 dumps.  The only metadata class was
`name=.rodata.config`, `type=array`, `frozen=1`, `flags=1152`.  Every reported
key had exactly one entry in its corresponding dump.  As a concrete direct
check, report line 26 (`loadtime_3945_29`, `cil_xdp_entry`) references map ID
480 and key `00000000`; the workdir-local `map-480.show.json` has the same ID
and the sole metadata class, and its dump has exactly one matching key.

The formal analyzer output agrees with every recomputed total and its stderr is
empty.  Reported-value containment is only a weak diagnostic because the
report omits source offsets and short byte strings recur inside the full map
value.

The earlier rewrite finding remains invalid/inconclusive.  All 122 changed
`input.bin` files match the reported after size, none match the reported before
size, and no changed workdir retains `output.next.0.bin`.  This result therefore
does not prove that rewrites occurred, reconstruct exact value offsets, show
attachment or execution, establish cross-start stability, or attribute any
throughput difference to `map_inline`.

The permitted paper statement is limited to this one retained Cilium startup:
every optimizer-reported applied entry referenced a workdir-local map ID whose
metadata named a frozen `.rodata.config` array.  The next paper decision is a
fresh single-pass run with retained before/after bytecode after the optimizer
owner's uncommitted work is resolved.
