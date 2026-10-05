# Soft Fold Unreachable Fix 2026-05-08

## Context

The reported katran failure was:

```text
BPF_PROG_REJIT errno 22
unreachable insn 533
```

The one allowed `make corpus` run in this workspace did not reproduce the
failure because the current dirty `katran.yaml` used a hard `vip_map` hint.
For bytecode inspection, the old failing shape was reconstructed from the
saved `/tmp/katran_fail9` noop input using the old soft `vip_map` hint. That
matched the reported `map_inline` shape: `sites_applied=9`,
`insn_count_before=2542`, `insn_count_after=2562`, with `vip_map` soft sites at
PC 512/762 skipped and PC 520/770 folded.

## PC 533 Disasm

Failing `map_inline` output around PC 533:

```text
 513: code=0x55 dst=r0 src=r0 off=25 imm=0 target=539
 ...
 521: code=0x5d dst=r3 src=r4 off=9 imm=0 target=531
 ...
 529: code=0xb4 dst=r1 src=r0 off=0 imm=2
 530: code=0x05 dst=r0 src=r0 off=4 imm=0 target=535
 531: code=0xb7 dst=r0 src=r0 off=0 imm=0
 532: code=0x05 dst=r0 src=r0 off=1018 imm=0 target=1551
 533: code=0xb7 dst=r8 src=r0 off=0 imm=2
 534: code=0x79 dst=r1 src=r10 off=-152 imm=0
 535: code=0x57 dst=r1 src=r0 off=0 imm=136
 536: code=0x55 dst=r1 src=r0 off=2 imm=0 target=539
```

No branch targeted PC 533. The replacement hit path jumps from PC 530 to 535,
and the replacement miss path jumps from PC 532 to 1551. PC 533 and 534 were
old instructions between the lookup helper call and the delayed null check.

Original bytecode at the same logical site:

```text
 520: code=0x85 dst=r0 src=r0 off=0 imm=1
 521: code=0xb7 dst=r8 src=r0 off=0 imm=2
 522: code=0x79 dst=r1 src=r10 off=-152 imm=0
 523: code=0x15 dst=r0 src=r0 off=1007 imm=0 target=1531
 524: code=0x61 dst=r1 src=r0 off=0 imm=0
 525: code=0x57 dst=r1 src=r0 off=0 imm=136
```

## Root Cause

`find_soft_fold_null_handler()` scanned forward from the lookup call until it
found a direct `if r0 == 0` check. That accepted delayed null checks with
ordinary fallthrough instructions between the helper call and the null check.

Soft fold replacement does not replay those intervening instructions. It emits
key checks, folded scalar loads, and then jumps to the old non-null path after
the null check. For PC 520, that skipped old PC 521/522 semantically while
leaving them physically in the stream between unconditional replacement
jumps, which made old PC 521 become unreachable new PC 533.

## Fix

Soft fold now only accepts an immediate direct null check at:

```text
call_pc + insn_width(call)
```

If the next instruction is not direct `BPF_JEQ r0, 0`, the site is vetoed with
`soft fold not applicable: missing null handler`. The existing direct-null
soft fold path remains unchanged.

## Test Coverage

Added `map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists`.
It builds one hard-fold map lookup and one soft-hinted lookup whose null check
is delayed by ordinary instructions. The test verifies:

- the hard fold still applies;
- the delayed soft fold is skipped;
- the remaining helper call is preserved;
- the output CFG has no unreachable instruction PCs.

Validation:

```text
cargo test -p bpfopt
```

Passed: lib 320, bin 9, cli 11, doctests 0.
