# cond_select cilium unsound site - 2026-05-17

## Scope

Read-only investigation, except artifacts written under `docs/tmp/`.
No code, git state, or `vendor/linux-framework` changes were made.

- Failing run: `corpus/results/x86_kvm_corpus_20260517_054226_995873`
- App result: `details/apps/cilium__agent.json`
- Failure: `endpoint http://198.18.0.2:18080/ not ready after 60.0s (last='000')`
- Pass list under test: `noop,cond_select`

That run did not retain pass workdirs or input/output bytecode files.  I used the
matching live-bytecode snapshots in `bpfopt/testbin/cilium_agent/` for offline
bytecode diffs, and cross-checked them against the 054226 per-program reports
and verifier logs.

## Finding

- App/program: cilium/agent `cil_from_contai` (`cil_from_container`)
- Failing run program ids: `147`, `167`
- Program type: `3` (`sched_cls`)
- 054226 cond_select summary for both ids: `sites_applied=3`, `380 -> 406`
- Matching offline snapshot: `bpfopt/testbin/cilium_agent/198_cil_from_container/output_step0.bin`
- Offline report: `docs/tmp/cond_select_cilium_unsound_20260517_artifacts/198_cil_from_container_cond_select_report.json`

Root cause: `condition_prefix()` chose the final destination register `r5` as
the synthetic predicate register.  `emit_x86_cond_select_kops()` then emitted
the false-arm `movq` into `r5` before `testq/cmovneq`, clobbering the predicate.
The cmov tests the false value, not the original condition.

This is not primarily a missing zero-extension issue.  `select_mov_value()`
accepts `BPF_ALU` and `BPF_ALU64`, but `materialize_value()` uses `mov32` for
`Reg32`/`Imm32`.  In this site the selected values are `Imm32` and are
materialized as `w0=1` and `w2=0`.  The bug is that the predicate itself is
stored in `r5` and is overwritten before the x86 kop sequence consumes it.

## Bytecode site

Before cond_select, snapshot `198_cil_from_container/output_step0.bin`:

```text
0012: (71) r3 = *(u8 *)(r2 +12)
0013: (71) r9 = *(u8 *)(r2 +13)
0014: (64) w9 <<= 8
0015: (4c) w9 |= w3
0016: (b4) w5 = 1
0017: (26) if w9 > 0x5 goto pc+1
0018: (b4) w5 = 0
0019: (63) *(u32 *)(r10 -80) = r5
```

Original semantics:

```text
w5 = (w9 > 5) ? 1 : 0
```

After offline `bpfopt --pass cond_select`, output
`198_cil_from_container_cond_select.bin`:

```text
0016: (b7) r5 = 0
0017: (b6) if w9 <= 0x5 goto pc+1
0018: (b7) r5 = 1              ; synthetic predicate, cond_reg = r5
0019: (b4) w0 = 1              ; true value materialized
0020: (b4) w2 = 0              ; false value materialized
0021: kop bpf_x86_movq       ; dst=r5, src=r2  => r5 = 0
0022: call bpf_x86_movq
0023: kop bpf_x86_testq      ; cond=r5
0024: call bpf_x86_testq
0025: kop bpf_x86_cmovneq    ; dst=r5, src=r0, cond=r5
0026: call bpf_x86_cmovneq
0028: (63) *(u32 *)(r10 -80) = r5
```

Transformed semantics at this site:

```text
r5 = (w9 > 5) ? 1 : 0
r0 = 1
r2 = 0
r5 = r2          ; clobbers predicate
if (r5 != 0)     ; tests false value, always false here
    r5 = r0
```

So the transformed result is always `0`, while the original result is `1` when
`w9 > 5`.

## Verifier support from 054226

The real failing run's verifier log for program id `147` confirms the same
instantiated sequence and register states:

```text
16: (b7) r5 = 0
17: (b6) if w9 <= 0x5 goto pc+1
    R9=scalar(smin=umin=smin32=umin32=6,...)
18: (b7) r5 = 1                       ; R5=1
19: (b4) w0 = 1                       ; R0=1
20: (b4) w2 = 0                       ; R2=0
21: (bf) r5 = r2                      ; R2=0 R5=0
22: (7b) *(u64 *)(r10 -376) = r6
23: (7b) *(u64 *)(r10 -368) = r7
R7 !read_ok
```

Program id `167` has the same `cil_from_contai` failure.  The `R7 !read_ok`
is where the verifier rejects the transformed program, but the semantic bug is
already visible one instruction earlier: the predicate had `R5=1` and was
clobbered to `R5=0` by the generated `movq` before `testq/cmovneq`.

## Secondary corroborating site

Failing run program id `115`, `cil_from_host`, also reports
`sites_applied=8`, `1194 -> 1257`, and hits the same hazard.

Original snapshot `164_cil_from_host/output_step0.bin` around PC 429:

```text
0429: (b4) w2 = 1
0430: (16) if w1 == 0xa00 goto pc+1
0431: (b4) w2 = 0
```

Transformed output around PC 453:

```text
0453: (b7) r2 = 0
0454: (56) if w1 != 0xa00 goto pc+1
0455: (b7) r2 = 1              ; synthetic predicate, cond_reg = r2
0456: (b4) w0 = 1
0457: (b4) w3 = 0
0458: kop bpf_x86_movq       ; dst=r2, src=r3  => r2 = 0
0460: kop bpf_x86_testq      ; cond=r2
0462: kop bpf_x86_cmovneq    ; dst=r2, src=r0, cond=r2
```

The 054226 verifier log shows the same clobber:

```text
480: (b7) r2 = 0
481: (56) if w1 != 0xa00 goto pc+1    ; R1=2560
482: (b7) r2 = 1                      ; R2=1
483: (b4) w0 = 1                      ; R0=1
484: (b4) w3 = 0                      ; R3=0
485: (bf) r2 = r3                     ; R2=0 R3=0
488: (7b) *(u64 *)(r10 -360) = r8
R8 !read_ok
```

## Code path

Relevant implementation points in
`bpfopt/crates/bpfopt/src/passes/cond_select.rs`:

- `select_mov_value()` accepts both 64-bit and 32-bit MOVs (`Reg`, `Imm`,
  `Reg32`, `Imm32`).
- `materialize_value()` emits `mov32_reg`/`mov32_imm` for `Reg32`/`Imm32`.
- `condition_prefix()` can choose `site.dst_reg` first via `choose_temp_reg()`.
- `emit_x86_cond_select_kops()` emits `movq(dst, false)`, then `testq(cond)`,
  then `cmovneq(dst, true, cond)` when no result scratch is allocated.
- `x86_result_scratch()` only checks `site.dst_reg == site.cond.dst_reg()`.
  For the `cil_from_container` site, original `site.cond.dst_reg()` is `r9`,
  but the synthetic predicate returned by `condition_prefix()` is `r5`.  The
  hazard is therefore missed.

## Proposed fix

Do not allow x86 lowering to clobber the predicate before `cmov`.

Concrete code-level options:

1. Move the x86 scratch decision until after `condition_prefix()` and check
   `site.dst_reg == lowering.cond_reg`, not just
   `site.dst_reg == site.cond.dst_reg()`.  If true, allocate
   `x86_result_scratch` and emit `movq(scratch, false); testq(cond);
   cmovneq(scratch, true, cond); movq(dst, scratch)`.
2. Alternatively, make `condition_prefix()` forbid `site.dst_reg` as a
   synthetic predicate for x86 sites whose final dst will be assigned before
   `cmov`.  This is less local because `condition_prefix()` is currently
   arch-neutral.
3. Add a regression test for this exact shape:

```text
w5 = 1
if w9 > 5 goto +1
w5 = 0
```

The test should assert that the x86 lowering never emits
`movq dst=<predicate>, false` before testing the same predicate.

For 32-bit selects, keep the existing zero-extension checks: `Reg32` and
`Imm32` must continue to materialize through `mov32`.  A separate hardening
could add an explicit width-aware assertion around x86 `movq/cmov` lowering,
but that is not the bug shown by the cilium failure above.
