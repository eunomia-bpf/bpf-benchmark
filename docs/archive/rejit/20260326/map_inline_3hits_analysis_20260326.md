# Map Inline 3 Hits Analysis 2026-03-26

## Scope

This note analyzes the three corpus programs that really hit `map_inline` in the 2026-03-26 VM validation run:

1. `katran:xdp_pktcntr.bpf.o:pktcntr`
2. `tracee:tracee.bpf.o:cgroup_skb_ingress`
3. `tracee:tracee.bpf.o:cgroup_skb_egress`

The goal here was to answer one narrow question: are the observed slowdowns explained by worse bytecode after inlining?

Short answer: no. None of the three regressions are explained by instruction-count growth. `map_inline` is instruction-neutral on `katran`, instruction-negative on both Tracee programs, and the full pipeline shrinks all three programs.

## Artifacts

The raw before/after bytecode is captured in the daemon debug traces. The daemon already emits these traces in responses; there is no separate `--debug` CLI flag needed.

Primary artifacts:

- `docs/tmp/20260326/map_inline_3hits_artifacts/katran_xdp_pktcntr/map_inline_only/daemon_response.json`
- `docs/tmp/20260326/map_inline_3hits_artifacts/katran_xdp_pktcntr/full_pipeline/daemon_response.json`
- `docs/tmp/20260326/map_inline_3hits_artifacts/tracee_cgroup_skb_ingress/map_inline_only/daemon_response.json`
- `docs/tmp/20260326/map_inline_3hits_artifacts/tracee_cgroup_skb_ingress/full_pipeline/daemon_response.json`
- `docs/tmp/20260326/map_inline_3hits_artifacts/tracee_cgroup_skb_egress/map_inline_only/daemon_response.json`
- `docs/tmp/20260326/map_inline_3hits_artifacts/tracee_cgroup_skb_egress/full_pipeline/daemon_response.json`

The `attempts[0].debug.pass_traces[*].bytecode_before/after.raw_hex_blob` fields contain the exact raw BPF bytecode before and after each pass. The `program.orig_insn_count/final_insn_count` fields contain the instruction counts for the daemon's transformable bytecode.

## Executive Summary

| Program | Original insns | After `map_inline` | After `const_prop` | After `dce` | Final after full pipeline | Net delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `katran/xdp_pktcntr` | 22 | 22 | 22 | 12 | 12 | -10 |
| `tracee/cgroup_skb_ingress` | 3602 | 3544 | 3544 | 3521 | 3203 | -399 |
| `tracee/cgroup_skb_egress` | 3602 | 3544 | 3544 | 3521 | 3203 | -399 |

Key points:

- No pass increases total instruction count on any of the three programs.
- `katran` is not slower because `map_inline` emitted more code. The inline itself is exactly instruction-neutral, and the later cleanup removes 10 instructions.
- The two Tracee programs are not slower because of bytecode growth either. `map_inline` alone removes 58 instructions, and the full pipeline removes 399.
- The only local instruction additions are inside `map_inline` itself at six Tracee sites where a 64-bit zero load is re-emitted as a 2-slot `ldimm64 0` instead of a 1-slot `mov64_imm 0`. Those six local `+1`s are already included inside the `-58` net shrink.

## Per-Program Analysis

### 1. `katran/xdp_pktcntr`

#### Pass-level count changes

| Pass | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `map_inline` | 22 | 22 | 0 |
| `const_prop` | 22 | 22 | 0 |
| `dce` | 22 | 12 | -10 |

#### Inlined site

`map_inline` applied once:

- `site at PC=7: inlined successfully, value=0x0`

Skipped site:

- `site at PC=15: map_type=6, skip reason: unsupported map type`

#### Original vs replacement quality

Original bytecode around the hit:

```text
5:  r1 = 0x4 ll
7:  call 1
8:  if r0 == 0 goto 20
9:  r1 = *(u32 *)(r0 + 0)
10: if r1 == 0 goto 20
```

After `map_inline`:

```text
5:  r1 = 0x4 ll
7:  call 1
8:  if r0 == 0 goto 20
9:  r1 = 0
10: if r1 == 0 goto 20
```

Local replacement accounting:

- Original `call + null-check + field-load`: 3 insns
- Replacement `call + null-check + mov-constant`: 3 insns
- Local delta: 0

Why the lookup setup was not removed:

- The pass identified the usual removable set `{source imm, stack store, r2 mov, r2 add, map ldimm64, call, null-check}`.
- For this site that set spans PCs `0..8`, but PC `2` belongs to the next map's key setup, not to this lookup.
- Because the removable PCs are not a tight contiguous block, `lookup_pattern_removal_is_safe()` rejects deleting them.
- Result: `map_inline` only rewrites the load at PC `9`; it does not delete the helper setup.

#### Did `const_prop` and `dce` help?

Yes, fully for the remaining branch:

After `const_prop`:

```text
9:  r1 = 0
10: goto 20
```

After `dce`:

- The entire dead tail from PCs `11..19` is removed.
- Diagnostics: `removed 9 unreachable insns`, `removed 1 nop insns`

Final reduced program tail:

```text
7:  call 1
8:  if r0 == 0 goto 10
9:  r1 = 0
10: r0 = 2
11: exit
```

#### Conclusion for `katran`

This regression is not explained by code growth. The inline itself is instruction-neutral, and the cleanup pass removes 10 instructions. Given the measured samples in the validation note (`[15,17,7,10,18]` vs `[16,7,17,7,16]`), this looks like measurement noise at `repeat=100`.

### 2. `tracee/cgroup_skb_ingress`

### 3. `tracee/cgroup_skb_egress`

The two Tracee programs have different full-program bytecode, but the nine successful `map_inline` sites have the same structure, the same inlined values, and the same per-site deltas. The pass counts are also identical.

#### Pass-level count changes

| Pass | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `map_inline` | 3602 | 3544 | -58 |
| `const_prop` | 3544 | 3544 | 0 |
| `dce` | 3544 | 3521 | -23 |
| `wide_mem` | 3521 | 3203 | -318 |
| `endian_fusion` | 3203 | 3203 | 0 |

Important: no pass is net-positive. The measured slowdown cannot be explained by instruction-count growth.

#### Inlined sites and local deltas

All successful Tracee inlines use a zero value.

| Call PC | Fixed loads consumed from `r0` | Pattern removable? | Local delta from `map_inline` | Reason |
| ---: | --- | --- | ---: | --- |
| 443 | `u32 @ +0` | No | 0 | only the load is rewritten |
| 630 | `u32 @ +4` | Yes | -8 | 8-slot lookup setup removed |
| 2357 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | 8-slot setup removed, but `u64` zero replacement costs +1 |
| 2453 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | same as PC 2357 |
| 2584 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | same as PC 2357 |
| 2818 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | same as PC 2357 |
| 2931 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | same as PC 2357 |
| 3319 | `u32 @ +4`, `u64 @ +0` | Yes | -7 | same as PC 2357 |
| 3507 | `u32 @ +4` | Yes | -8 | 8-slot lookup setup removed |

Check:

- `0 + (-8) + 6 * (-7) + (-8) = -58`
- This matches the daemon's `map_inline.insn_delta = -58`

#### Pattern A: PC 443, load-only rewrite, no setup deletion

Original:

```text
435: r1 = 0
436: r2 = 0
437: *(u64 *)(r10 - 0xc0) = r2
438: *(u32 *)(r10 - 0x24) = r1
439: r2 = r10
440: r2 += -0x24
441: r1 = map ll
443: call 1
444: if r0 == 0 goto ...
445: r1 = *(u32 *)(r0 + 0)
446: r1 &= 1
447: if r1 != 0 goto ...
```

After `map_inline`:

```text
441: r1 = map ll
443: call 1
444: if r0 == 0 goto ...
445: r1 = 0
446: r1 &= 1
447: if r1 != 0 goto ...
```

Why removal did not happen:

- The removable PCs for this site are `{435,438,439,440,441,442,443,444}`.
- They are not contiguous because PCs `436` and `437` are unrelated instructions between the constant materialization and the key store.
- So `map_inline` keeps the helper setup and only replaces the load.

Replacement quality:

- Original `call + null-check + field-load`: 3 insns
- Replacement `call + null-check + mov-constant`: 3 insns
- Local delta: 0

Cascade:

- `const_prop` does help:
  - `r1 &= 1` becomes `r1 = 0`
  - `if r1 != 0` becomes `goto`
- `dce` then removes the dead branch arm.

#### Pattern B: PCs 630 and 3507, full setup deletion, one 32-bit load

Representative original sequence:

```text
624: r1 = 0
625: *(u32 *)(r10 - 0x10) = r1
626: r2 = r10
627: r2 += -0x10
628: r1 = map ll
630: call 1
631: if r0 == 0 goto ...
632: r1 = *(u32 *)(r0 + 4)
633: if r1 < 0x10000 goto ...
634: r1 = 0x10000
635: if r1 == 0x10000 goto ...
636: if r1 != 0 goto ...
```

After `map_inline`:

```text
624: r1 = 0
625: if r1 < 0x10000 goto ...
626: r1 = 0x10000
627: if r1 == 0x10000 goto ...
628: if r1 != 0 goto ...
```

Local replacement accounting:

- Original removable lookup block from source-imm through first load: 9 instruction slots
  - `mov imm`
  - stack store
  - `r2 = fp`
  - `r2 += off`
  - `ldimm64 map` (2 slots)
  - `call`
  - null-check
  - `ldxw`
- Replacement left behind: 1 instruction slot (`mov64_imm 0`)
- Local delta: `-8`

This is already a strict improvement. It is not a plausible explanation for the runtime regression.

#### Pattern C: PCs 2357, 2453, 2584, 2818, 2931, 3319, full setup deletion, 32-bit plus 64-bit loads

Representative original sequence:

```text
2351: r1 = 0
2352: *(u32 *)(r10 - 0x10) = r1
2353: r2 = r10
2354: r2 += -0x10
2355: r1 = map ll
2357: call 1
2358: if r0 == 0 goto ...
2359: r1 = *(u32 *)(r0 + 4)
...
2387: r1 = *(u64 *)(r0 + 0)
2388: r4 &= r1
```

After `map_inline`:

```text
2343: r1 = 0
...
2371: r1 = 0x0 ll
2373: r4 &= r1
```

Local replacement accounting:

- Removed setup/null-check block: 8 instruction slots
- `u32` field load replacement: `ldxw` (1) -> `mov64_imm 0` (1), delta `0`
- `u64` field load replacement: `ldxdw` (1) -> `ldimm64 0` (2), delta `+1`
- Net local delta: `-8 + 1 = -7`

This is the most important codegen-quality issue in the current implementation:

- All six of these sites inline `0x0000000000000000`
- `emit_constant_load()` still uses a 2-slot `ldimm64` for every `BPF_DW` load
- For zero, the better codegen is a 1-slot `mov64_imm 0`

So the current emitter leaves 6 instructions on the table across these two Tracee programs.

## Replacement Quality Summary

### What got better

- The removable Tracee sites really do delete the expensive part of the lookup pattern.
- The best sites (`630`, `3507`) shrink from a 9-slot local sequence to a 1-slot constant.
- Even the larger two-load sites still shrink by 7 slots each.

### What did not improve

- `katran` PC `7` and Tracee PC `443` do not remove helper setup at all; they only replace `ldx` with `mov`.
- For those sites the local replacement is instruction-neutral, not instruction-reducing.

### Where current codegen is suboptimal

- Six Tracee sites inline a 64-bit zero load.
- Current emitter: `ldxdw` -> `ldimm64 0` (2 slots)
- Better emitter: `ldxdw` -> `mov64_imm 0` (1 slot)

That change would improve the map-inline delta on Tracee from `-58` to `-64`.

## Did `const_prop` / `dce` Actually Help?

### `katran`

Yes. The cascade works well here:

- `map_inline`: makes `r1` constant zero
- `const_prop`: folds `if r1 == 0` into an unconditional `goto`
- `dce`: removes the entire dead tail

### `tracee`

Yes, but only partially.

What does work:

- On the one-load sites, `const_prop` folds the first range check:

```text
if r1 < 0x10000 goto ...
```

into:

```text
goto ...
```

- `dce` then removes the dead `r1 = 0x10000` block.

What does not fully work:

1. `const_prop` is not rerun after `dce`

After `dce`, the surviving code often looks like:

```text
r1 = 0
if r1 == 0x10000 goto ...
if r1 != 0 goto ...
```

At that point both branches are obviously foldable, but the pipeline has already moved past `const_prop`.

2. The current constant folder does not consume `x & 0` aggressively enough

Representative two-load site after `map_inline`:

```text
r1 = 0x0 ll
r4 &= r1
if r4 == 0 goto ...
```

This should collapse to `r4 = 0`, then to a constant-taken branch, but it survives unchanged through the current `const_prop` pass.

So the cascade is real, but it underfires on Tracee.

## Why The Measured Slowdowns Are Probably Not A Bytecode Problem

The validation note measured at `repeat=100`, `5` outer iterations, using median `exec_ns`.

Observed samples:

- `katran/xdp_pktcntr`
  - stock `[15, 17, 7, 10, 18]`
  - rejit `[16, 7, 17, 7, 16]`
- `tracee/cgroup_skb_ingress`
  - stock `[15, 13, 13, 13, 14]`
  - rejit `[40, 16, 15, 14, 23]`
- `tracee/cgroup_skb_egress`
  - stock `[13, 13, 15, 14, 13]`
  - rejit `[22, 15, 17, 18, 18]`

These numbers are inconsistent with a simple "more code made it slower" explanation:

- `katran`: no code growth, later cleanup removes 10 instructions
- `tracee`: `map_inline` alone removes 58 instructions, and the full pipeline removes 399

So the current evidence points to one of these instead:

1. measurement noise at very small absolute runtimes
2. a runtime/layout effect unrelated to bytecode count
3. interference from other passes in the full pipeline, especially because the measured run was not a `map_inline`-only ablation

## Proposed Fixes

### 1. Fix 64-bit constant emission in `map_inline`

Current issue:

- `emit_constant_load()` always emits `ldimm64` for `BPF_DW` loads
- For zero, this turns a 1-slot original `ldxdw` into a 2-slot replacement

Suggested fix:

- Use `mov64_imm` whenever the inlined 64-bit constant fits a signed 32-bit immediate
- Zero is the obvious immediate win

Expected effect on these two Tracee programs:

- 6 fewer instructions
- `map_inline` delta improves from `-58` to `-64`

### 2. Rerun `const_prop` after `dce`, or run `[const_prop, dce]` to fixed point

Current issue:

- `const_prop` folds the first branch
- `dce` removes dead setup
- the now-exposed constant branches are never revisited

Suggested fix:

- Pipeline option A: `map_inline -> const_prop -> dce -> const_prop -> dce`
- Pipeline option B: iterate `const_prop + dce` until no change

Expected effect:

- More dead range-check branches disappear on the Tracee sites

### 3. Teach `const_prop` simple annihilator identities

Current issue:

- `r4 &= 0` does not collapse to `r4 = 0`

Suggested fix:

- Add algebraic folding rules such as:
  - `x & 0 = 0`
  - `x | 0 = x`
  - `x ^ 0 = x`
  - `x * 0 = 0`

Expected effect:

- The second family of Tracee sites can fold the `u64 @ +0` zero path much harder

### 4. Re-measure with a higher repeat count and without `wide_mem`

This repo now has a dedicated profile for this:

```yaml
ablation_map_inline_full:
  passes:
    active_list: [map_inline, const_prop, dce]
  repeat: 500
```

Reason:

- The current slowdowns were measured with the full performance pipeline, not with `map_inline + cleanup` in isolation
- `repeat=100` is too noisy for 13-18ns medians

## Bottom Line

The three measured slow hits are not slower because `map_inline` made the programs bigger.

- `katran`: `map_inline` is instruction-neutral and the pipeline then removes 10 instructions
- `tracee ingress`: `map_inline` removes 58 instructions and the pipeline removes 399
- `tracee egress`: same story as ingress

There are two real map-inline quality issues, but neither explains the measured regressions:

1. six Tracee `u64` zero loads are emitted as 2-slot `ldimm64 0` instead of 1-slot `mov64_imm 0`
2. `const_prop + dce` only partially consume the new constants

So the most defensible conclusion is:

- the slowdown is not explained by instruction count
- the current measurements are likely noisy or confounded by later passes
- the next run should isolate `map_inline + const_prop + dce` at `repeat=500`
