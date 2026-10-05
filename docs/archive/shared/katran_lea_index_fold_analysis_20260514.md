# Katran lea_index_fold analysis

Date: 2026-05-14

Scope: only analysis. No pass implementation was changed in this round.

## Question

Katran native x86 output contains many `lea` instructions, so the candidate was
to check whether a BPF-level `lea_index_fold` is a real Katran opportunity or
mostly native address-mode noise.

The important distinction is:

- native x86 `lea` count: what clang can do with source-level addressing and
  x86 instruction selection;
- BPF bytecode foldability: what remains as adjacent `MOV+ADD` windows after
  compiling to BPF;
- verifier safety: whether replacing those windows preserves pointer/stack
  provenance.

## Inputs

- Testbin bytecode:
  `bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin`
- Current experimental pass implementation:
  `bpfopt/crates/bpfopt/src/passes/lea.rs`
- Existing broader census:
  `docs/tmp/lea_kop_design_census_20260513.md`
- Existing full corpus artifact:
  `corpus/results/x86_kvm_corpus_20260513_085300_456487/details/apps/katran.json`

## Native vs BPF Signal

The previous census already found the key mismatch:

- Katran direct native x86 has 225 `lea` instructions across copied Katran
  sources.
- `katran_balancer.bpf.x86.s` has 180 native `lea` instructions.
- Katran BPF object/runtime strict BPF foldable count is only 4.

So most Katran native `lea` instructions are x86 address materialization or
native instruction-selection artifacts. They are not BPF `MOV+ADD` windows that
a bytecode pass can recover.

## Current Pass Report

The current tree already has an experimental `lea` pass. I used it as a probe,
not as a requested implementation.

Command:

```sh
bpfopt/target/debug/bpfopt \
  --pass lea \
  --input bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin \
  --output /tmp/katran_candidate_reports/lea.bin \
  --report /tmp/katran_candidate_reports/lea.json \
  --prog-type xdp \
  --target /tmp/bpfopt-katran-kop-target.json
```

Report:

```json
{
  "pass": "lea",
  "sites_applied": 122,
  "sites_matched": 122,
  "sites_skipped": 0,
  "insn_count_before": 2542,
  "insn_count_after": 2542,
  "insn_delta": 0
}
```

The 122 sites split as:

```text
base+imm   64-bit: 118
base+index 64-bit: 4
```

The 4 true base+index sites are:

| pc | shape |
|---:|---|
| 414 | `r4 = r7; r4 += r5` |
| 442 | `r3 = r7; r3 += r4` |
| 705 | `r4 = r7; r4 += r5` |
| 734 | `r3 = r7; r3 += r4` |

Representative bytecode:

```text
00412: if r3 == 0 goto ...
00413: r5 = 0x66
00414: r4 = r7
00415: r4 += r5
00416: r5 = r4
00417: r5 += 0x14
```

This is packet-pointer style address calculation, not scalar arithmetic.

The first `base+imm` sites are also pointer materializations:

```text
pc 4: r1 = r8;  r1 += 14       ; packet data + Ethernet header
pc 9: r2 = r10; r2 += -132     ; stack key address
pc 42: r3 = r7; r3 += 34       ; packet pointer
```

That explains why the large 122-site count is misleading for Katran. It is
mostly pointer/stack address formation, not safe scalar `lea` folding.

## Verifier Evidence

The existing full Katran corpus run tried the experimental `lea` pass after
earlier passes. It applied 116 sites at that point, then `BPF_PROG_REJIT`
rejected the candidate:

```text
pass=lea
sites_applied=116
status=failed_rejit
error=kernel rejected BPF_PROG_REJIT: errno 13
```

The verifier log shows the core failure mode. A stack pointer used as a map key
was materialized as scalar:

```text
8:  w2 = w10
9:  w2 += -132
12: call bpf_map_lookup_elem#1
R2 type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ...
```

This is exactly the provenance problem the static Katran examples predict.
Offline bytecode rewriting can produce a report, but without pointer-state
gating it is not verifier-safe.

## Current Risk

For Katran, `lea_index_fold` has three separate problems:

1. Native `lea` count is not BPF-level opportunity. Katran has many native
   address-mode LEAs but only 4 strict BPF base+index sites.
2. The current broad pass matches 118 additional base+imm sites, but many are
   stack or packet pointer address calculations.
3. Existing live ReJIT evidence shows verifier rejection when pointer
   provenance is lost.

The current pass also has no bytecode instruction-count reduction for the
dominant two-instruction `MOV+ADD` form: packed kop replacement is still two
BPF instruction slots. Any win would have to come from final x86 lowering, and
Katran's verifier-safe scalar population is not established.

## Conclusion

Do not pursue Katran-specific `lea_index_fold` now.

A viable LEA pass would need to be scalar-only and verifier-state-gated before
benchmarking. It should reject stack, packet, map-value, ctx, and other pointer
provenance cases rather than trying to fold them through a KOperation. Once that
exists, the likely ROI is in non-Katran scalar-heavy programs, not in Katran.

For Katran specifically, the present answer is no-go:

- true BPF base+index sites: 4;
- broad current pass sites: 122, mostly pointer/stack address formation;
- existing full-run ReJIT: failed at `lea` due pointer provenance loss.
