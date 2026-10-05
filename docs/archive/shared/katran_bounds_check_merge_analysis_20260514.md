# Katran bounds_check_merge analysis

Date: 2026-05-14

Scope: only analysis. No pass implementation was changed.

## Question

Katran has packet bounds checks in the hot path. The candidate was to see
whether `bounds_check_merge` has real Katran merge points that are hot and
verifier-safe.

This note separates three levels:

1. broad syntax: `mov cursor, root; add cursor, K; if cursor > data_end`;
2. current bpfopt pass report;
3. evidence from an existing full Katran corpus run.

## Inputs

- Testbin bytecode:
  `bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin`
- Existing live xlated/JIT:
  `docs/tmp/katran_kvm_live_jit_noop_20260513_220629/`
- Existing full corpus artifact:
  `corpus/results/x86_kvm_corpus_20260513_085300_456487/details/apps/katran.json`

The testbin input has 2542 raw BPF instructions. The scanner's logical view has
2453 instructions after treating `ldimm64` second slots as metadata, which is
how `ProgramCFG` sees windows internally.

## Current Pass Result

Command:

```sh
bpfopt/target/debug/bpfopt \
  --pass bounds_check_merge \
  --input bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin \
  --output /tmp/katran_candidate_reports/bounds.bin \
  --report /tmp/katran_candidate_reports/bounds.json \
  --prog-type xdp
```

Report:

```json
{
  "pass": "bounds_check_merge",
  "sites_applied": 0,
  "sites_matched": 1,
  "sites_skipped": 1,
  "skip_reasons": {
    "guard not part of a mergeable ladder": 1
  },
  "skipped_sites": [
    {
      "pc": 6,
      "reason": "guard not part of a mergeable ladder"
    }
  ],
  "insn_count_before": 2542,
  "insn_count_after": 2542,
  "insn_delta": 0
}
```

I also checked the likely default predecessor shape by running `wide_mem` first:

```text
wide_mem: sites_applied=4, insn_delta=-12
bounds_after_wide_mem: sites_matched=1, sites_applied=0
```

So `wide_mem` does not expose a Katran merge point for the current pass.

The existing full Katran corpus run agrees after the real pass sequence:

```text
bounds_check_merge: sites_matched=1, sites_applied=0
skip_reasons={"guard not part of a mergeable ladder": 1}
```

## Static Scanner Result

A broad syntax scanner found 9 `mov+add+cmp data_end` shapes:

| compare pc | root | data_end | window | note |
|---:|---:|---:|---:|---|
| 6 | r8 | r9 | 14 | initial Ethernet bounds check |
| 1154 | r1 | r2 | 14 | syntactic pair with pc 1157, growth 40 |
| 1157 | r1 | r2 | 54 | syntactic pair with pc 1154, growth 40 |
| 1405 | r1 | r2 | 14 | syntactic pair with pc 1408, growth 20 |
| 1408 | r1 | r2 | 34 | syntactic pair with pc 1405, growth 20 |
| 1854 | r1 | r2 | 14 | syntactic pair with pc 1857, growth 40 |
| 1857 | r1 | r2 | 54 | syntactic pair with pc 1854, growth 40 |
| 2102 | r1 | r2 | 14 | syntactic pair with pc 2105, growth 20 |
| 2105 | r1 | r2 | 34 | syntactic pair with pc 2102, growth 20 |

Representative entry guard:

```text
00004: r1 = r8
00005: r1 += 14
00006: if r1 > r9 goto ...
```

Representative broad ladder-looking pair:

```text
01403: r3 = r1
01404: r3 += 14
01405: if r3 > r2 goto ...
01406: r3 = r1
01407: r3 += 34
01408: if r3 > r2 goto ...
```

The broad scanner is intentionally weaker than the pass. It does not prove that
`r1` and `r2` are verifier-equivalent packet-data and packet-end registers at
the compare site, and it does not prove that deleting the intermediate branch is
safe across the real CFG.

## Why Current Pass Applies 0

`bounds_check_merge` requires more than the surface instruction pattern:

- root and data_end must be proven by `ProgramCFG::reg_fact_at()` as the same
  packet pointer identity;
- guards must share root, data_end, compare kind, and slow target;
- the next window must be larger, but by at most
  `MAX_LADDER_WINDOW_GROWTH = 24`;
- the interleaving path must not contain unsafe stores, branches, branch
  targets, or frame changes;
- the cursor must be dead enough for setup deletion/widening.

The only verifier-fact-recognized Katran guard is the initial pc 6 guard, and it
is alone. The later syntax pairs are not accepted by the current packet-fact
model. Two pairs also have a 40-byte window growth, which exceeds the current
budget even before considering fact/provenance safety.

The two 14 -> 34 pairs are the only syntax-level shapes that look plausibly
within the budget. The current pass still rejects them because they are not
recognized as verifier-safe guard sites.

## Conclusion

There is no current Katran `bounds_check_merge` optimization to enable.

The safe conclusion is:

- current pass report: 1 matched guard, 0 applied;
- after `wide_mem`: still 1 matched guard, 0 applied;
- existing full corpus run: still 1 matched guard, 0 applied;
- broad scanner: 9 syntactic checks, but no current verifier-safe merge.

If this is revisited, the only narrow research target is the two syntax pairs
with 14 -> 34 growth. That would first require improving packet/data_end fact
tracking around the relevant Katran control-flow region and then proving the
rewrite through live `BPF_PROG_REJIT`. It should not be treated as an
optimization candidate until the pass report changes from syntax evidence to an
actual verifier-accepted merge.
