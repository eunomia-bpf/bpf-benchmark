# Rotate Zero-Match Diagnosis

Date: 2026-05-06.

## Verdict

H1 is confirmed: the rotate pattern matcher was too narrow. The Cilium bytecode contains the Jenkins rotate sequence, but clang emits it as a split-copy five-instruction shape:

```text
2462: w1 = w6
2463: w1 >>= 0x1c
2464: w2 = w6
2465: w2 <<= 0x4
2466: w2 |= w1
```

The old matcher only scanned adjacent `shift; shift; OR` triples with one provenance `MOV` immediately before the pair. At the real Cilium site it saw either `RSH; MOV; LSH` or `MOV; LSH; OR`, so `scan_rotate_sites()` returned no candidate at all. That explains the smoke result's `matched=0`, not just `applied=0`.

H2 is not supported. The pre-`2b126921` rotate64 matcher already had the same adjacent-shift assumption; `2b126921` generalized that shape to rotate32 but did not introduce the split-copy blind spot.

H3 is false for Cilium. `docs/tmp/crc32_hash_kop_recheck_20260506.md` correctly identified Jenkins hash rotate clusters in the cached Cilium objects; the bytecode contains them.

## Artifact Scope

The only corpus `result.json` read for this investigation was:

```text
corpus/results/x86_kvm_corpus_20260506_065933_243748/details/result.json
```

The Cilium bytecode inspection used `corpus/build/cilium/bpf_xdp.bpf.o`, with `xdp/tail` extracted as raw `struct bpf_insn[]` bytecode for `bpfopt`.

## Fix

`bpfopt/crates/bpfopt/src/passes/rotate.rs` now recognizes this split-copy rotate form for both W32 and W64:

```text
MOV a, val; SHIFT a, A; MOV b, val; SHIFT b, B; OR result, other
```

The matcher requires:

- both copies read the same source register
- the two shifted registers are distinct
- the shifts are one LSH and one RSH
- shift immediates sum to the operation width
- OR combines exactly the two shifted registers
- the encoded scratch register is not the result or source register

The original adjacent-shift matcher remains intact and is still the fallback path, so the rotate64 shape covered by existing tests is preserved.

## Verification

Rotate unit tests:

```text
cargo test -p bpfopt rotate
23 passed
```

Focused regression test added:

```text
test_rotate32_pass_cilium_split_copy_shape
```

Offline Cilium `xdp/tail` before the matcher fix:

```json
{"sites_applied":0,"sites_matched":0,"sites_skipped":0}
```

Offline Cilium `xdp/tail` after the matcher fix:

```json
{"sites_applied":0,"sites_matched":111,"sites_skipped":111}
```

The 111 skips are from the existing kop tail-call safety gate: the extracted `xdp/tail` section contains a tail-call helper, and rotate replacement changes instruction count. This investigation did not change tail-call policy. The important fix result is that structural matching is no longer zero.

## Expected Smoke Change

Rotate should no longer report `matched=0` on Cilium Jenkins-shape programs. Actual `applied` can still be lower than `matched` when existing safety checks reject a site, especially in programs with tail-call helper constraints.

Top risk: if all hot production rotate sites for an app live in tail-call programs, this matcher fix will expose nonzero matched/skipped counts but may not increase applied count until tail-call-safe kop replacement is designed separately.
