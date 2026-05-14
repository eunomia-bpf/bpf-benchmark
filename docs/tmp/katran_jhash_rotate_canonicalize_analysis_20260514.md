# Katran jhash_rotate_canonicalize analysis

Date: 2026-05-14

Scope: only analysis. No bpfopt pass code was changed for this note.

## Question

Katran's hot path computes a packet hash through `jhash`. The candidate idea was
to add a very narrow `jhash_rotate_canonicalize` step if the existing `rotate`
pass missed Katran's canonical `rol32` lowering.

The check here is: source shape -> committed testbin bytecode -> current
`rotate` report -> existing live JIT artifact.

## Inputs

- Source: `runner/repos/katran/katran/lib/bpf/balancer.bpf.c`
- Source hash helper: `runner/repos/katran/katran/lib/linux_includes/jhash.h`
- Testbin bytecode:
  `bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin`
- Existing live no-op JIT:
  `docs/tmp/katran_kvm_live_jit_noop_20260513_220629/live_jited.objdump`
- Direct native assembly:
  `bpfopt/testccode/katran_balancer.bpf.x86.s`

The testbin input SHA-256 was:

```text
1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e
```

## Source Shape

`get_packet_hash()` has two cases:

- IPv4/non-16-byte path: `jhash_2words(src, ports, INIT_JHASH_SEED)`.
- IPv6/16-byte path: inner `jhash(srcv6, 16, INIT_JHASH_SEED_V6)` plus outer
  `jhash_2words(...)`.

`jhash.h` defines `rol32(word, shift)` as:

```c
(word << shift) | (word >> ((-shift) & 31))
```

The macro counts explain the static site count:

- `__jhash_final`: 7 `rol32` operations.
- `__jhash_mix`: 6 `rol32` operations.
- IPv4 path executes the outer final only: 7 rotates.
- IPv6 path executes one mix + one inner final + one outer final: 20 rotates.

Direct native x86 confirms this is a rotate32 problem, not a separate jhash
primitive: `katran_balancer.bpf.x86.s` contains 20 `rorx` and 5 `rol` sites.
The 5 `rol` sites are 16-bit byte-swap style sites, not the jhash rotate32
group.

## Current rotate Pass Result

Command used:

```sh
bpfopt/target/debug/bpfopt \
  --pass rotate \
  --input bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin \
  --output /tmp/katran_candidate_reports/rotate.bin \
  --report /tmp/katran_candidate_reports/rotate.json \
  --prog-type xdp \
  --target /tmp/bpfopt-katran-kinsn-target.json
```

Report:

```json
{
  "pass": "rotate",
  "sites_applied": 20,
  "sites_matched": 20,
  "sites_skipped": 0,
  "insn_count_before": 2542,
  "insn_count_after": 2462,
  "insn_delta": -80
}
```

A separate read-only scanner over the same bytecode found the same 20 exact
current-pass shapes. All 20 were `masked32` rotate sites. No extra loose
`shift/shift/or` rotate-like windows were found outside the exact matches.

Shift distribution:

```text
shift 4:  4
shift 6:  1
shift 8:  1
shift 11: 2
shift 14: 4
shift 16: 3
shift 19: 1
shift 24: 2
shift 25: 2
```

Representative bytecode:

```text
02324: r4 = r2
02325: r4 &= r3        ; mask 0xf0000000
02326: r4 >>= 28
02327: r0 = r2
02328: r0 <<= 4
02329: r0 |= r4
```

This is exactly the masked-high32 shape that the current `rotate` pass already
handles.

The existing full Katran corpus run also hit the same count after earlier
passes:

```text
corpus/results/x86_kvm_corpus_20260513_085300_456487/details/apps/katran.json
rotate: sites_matched=20, sites_applied=20, insn_delta=-80
```

## Live JIT Check

The existing no-op live JIT artifact is baseline kernel-JIT output, not a
`rotate` pass dump. It is still useful to locate the current baseline lowering.

Mnemonic census from
`docs/tmp/katran_kvm_live_jit_noop_20260513_220629/live_jited.objdump`:

```text
bytes: 13629
rorx: 0
ror:  5
shl:  123
shr:  56
or:   67
```

The 5 `ror` instructions are 16-bit byte-swap style `ror $0x8` instructions.
There is no baseline `rorx` for the jhash rotate32 group. Direct native clang
does emit 20 `rorx` for the same source-level jhash code, so the baseline kernel
JIT does leave a native-instruction gap.

But that is not a matcher/canonicalization gap in bpfopt: the current `rotate`
pass already recovers all 20 Katran jhash rotate32 bytecode sites.

## Conclusion

Do not add `jhash_rotate_canonicalize` for current Katran. The evidence says:

- Source has 20 static jhash rotate32 operations in the full balancer program.
- Testbin bytecode has exactly 20 current-pass rotate matches.
- Current `rotate` applies all 20 with no skips.
- No loose rotate-like bytecode windows remain outside those 20.
- Baseline live JIT does not independently recover the jhash rotates, but the
  existing `bpf_rotate32` path is already the intended recovery mechanism.

The next useful work is not a new canonicalize pass. If we want a stronger
Katran rotate claim, capture a live JIT dump after `rotate` and run an isolated
`rotate` or `rotate,dce` Katran benchmark. That would validate emitted machine
code and performance, not expand the matcher.
