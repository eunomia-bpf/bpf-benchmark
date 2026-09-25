# Plan Review

## Round 1 — 2026-09-25T02:14:00+00:00

Verdict: **blocking revisions required**.

The reviewer accepted workdir-local map-ID attribution as independent of the
missing before bytecode, but rejected substring containment as per-site value
provenance because short reported values occur many times in the full dump.
The reviewer also required exact report-entry cardinality invariants and a
literal paper-facing claim that cannot imply rewrite occurrence, exact value
offsets, cross-start stability, performance benefit, or a completed RQ2.

Root disposition: accept all findings.  Experiment 002 now makes the unique
map-ID-to-metadata join decisive, retains dump containment only as a weak
diagnostic, validates entry cardinality for every row, and predeclares the
exact maximum paper statement.

## Round 2 — 2026-09-25T02:17:00+00:00

Verdict: **one blocking wording inconsistency**.

The reviewer found that the proposed paper sentence used `every` for both
supported and mixed outcomes even though mixed explicitly includes another
map class.  Root disposition: accept and close the final permitted review
round by restricting the `every` sentence to supported results; a mixed result
may report only its class counts.  This exact repair introduces no new method
or evidence requirement, so the plan proceeds to execution.
