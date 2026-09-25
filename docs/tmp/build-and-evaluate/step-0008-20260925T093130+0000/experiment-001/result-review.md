# Experiment 001 Result Review: Retained per-step bytecode

Date: 2026-09-25T09:31:00+00:00
Outcome: supported

## Result

The retained report stream holds 169 rows: 122 changed load instances (47
unchanged), 3,787 applied sites, and instruction counts 159,896 → 111,826
(−48,070).  The run's `metadata.status` is `completed`, its Cilium app record
is `status: ok` with an empty `error`, and the load-time post-phase shim log
records 122 optimized events with zero failed changed loads.

For all 122 changed workdirs the retained `input.step.0.bin` /
`output.next.0.bin` images satisfy `size == 8 * reported insn_count`, and all
122 before/after pairs differ byte-for-byte.  Zero length mismatches, zero
identical images.  The reconciling inputs and outputs are retained and bound by
SHA256 in the evidence `receipt.json`.

## Review

The run's post-phase shim log is a third independent stream: it emits exactly
122 `loadtime optimized prog=… insns=BEFORE->AFTER` lines with zero failure
lines, and their summed `154,340 → 106,270` equals the changed rows' summed
reported instruction counts.  (The report stream's `159,896 → 111,826` covers
all 169 rows including the 47 unchanged programs; `154,340 → 106,270` is the
changed-load population, which is the same population the shim log records.)
A separate auditor
`analysis/audit_loadtime_evidence.py` (with `--expected-pass map_inline`)
independently reports `outcome: supported` with
`integrity_errors.total = 0`, the same 122/3,787/`-48,070` values, and
`input_matches_reported_before = mutable_input_matches_reported_after =
output_matches_reported_after = retained_output_next_0 = 122`.

## Scientific boundary

The result establishes that, in this one startup, the reported `map_inline`
sites were applied to bytecode whose retained before/after images differ and
whose lengths match the reported instruction counts.  It does not establish
per-pass throughput causality (the run applied a single pass at load time and
compared one start pair), and it does not reproduce the paper's declared
4,086-site full-scale run, which retained no per-step bytecode.  The two
figures are reported beside each other and never merged.
