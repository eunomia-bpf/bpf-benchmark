# Pass-Induced Regression Root Cause Analysis (2026-03-28)

## Scope

Investigated the two slowdown clusters from the `vm_corpus_20260328_194356` corpus run and focused on one question: did the passes make these programs slower because they became larger, or because they changed hot-path code shape in a way the x86 JIT likes less?

## Evidence Used

- `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`
  - authoritative before/after runtime, xlated size, JIT code size, and total sites for the exact regressors
- `daemon/src/passes/const_prop.rs`
  - `emit_constant_load()` and `fold_jump_instruction()`
- `daemon/src/passes/map_inline.rs`
  - `emit_constant_load()`
- `daemon/tests/results/static_verify.json`
  - unsanitized per-pass diagnostics and before/after bytecode diffs for BCC programs
- `docs/tmp/20260328/daemon_batch_result_opensnoop_openat_compileonly.json`
  - supplemental direct daemon probe in the VM for `opensnoop`; useful, but not treated as canonical because it did not reproduce the exact final pass set seen in the corpus batch

## Bottom Line

1. Calico is not a bulk code-growth regression. The exact `const_prop`-only regressors keep the same xlated size and add only 2-4 native bytes, yet slow down by 2.9-4.0x.
2. BCC does contain one concrete codegen inefficiency: `map_inline` rewrites 32-bit `0xffffffff` map values into 2-slot `LD_IMM64` sequences at some sites, which explains the local `+2 insn` growth in `tcpconnect` and `tcptracer`.
3. But BCC is also not a pure code-size story: `opensnoop` and `tcpconnlat:fentry_tcp_rcv_state_process` get smaller or stay flat and still slow down. The dominant mechanism across both clusters is most likely hot-path layout / branch-structure / JIT-shape perturbation, not raw instruction-count increase.

## Cluster 1: Calico `const_prop` Regressions

### Exact corpus measurements

| Program | Passes | Sites | Exec ns | Xlated bytes | Native bytes | Result / retval |
| --- | --- | ---: | --- | --- | --- | --- |
| `from_nat_debug:calico_tc_main` | `const_prop` | 25 | `300 -> 1204` (`4.01x`) | `54776 -> 54776` | `33217 -> 33221` | `0/2 -> 0/2` |
| `from_nat_debug:calico_tc_skb_new_flow_entrypoint` | `const_prop` | 25 | `150 -> 552` (`3.68x`) | `34344 -> 34344` | `21254 -> 21256` | `0/2 -> 0/2` |
| `to_hep_debug:calico_tc_skb_new_flow_entrypoint` | `const_prop` | 32 | `138 -> 407` (`2.95x`) | `36128 -> 36128` | `22610 -> 22612` | `0/2 -> 0/2` |

### What the data rules out

- Semantics appear unchanged: `result` and `retval` are identical before/after in all three cases.
- `xlated_prog_len` is identical before/after in all three cases.
- Native code grows by only `+4B`, `+2B`, and `+2B` on already huge JIT bodies (`21-33 KB`).

That is too small to explain a `3-4x` slowdown via simple code-footprint or I-cache-pressure growth. The original hypothesis "const_prop replaced many `MOV_IMM` with `LD_IMM64` and bloated the program" is not supported by the exact measured sizes for these three regressors.

### What `const_prop` can still change

In `daemon/src/passes/const_prop.rs`:

- `emit_constant_load()` emits a 1-slot `mov64_imm` when the value fits signed 32-bit, otherwise it emits 2-slot `LD_IMM64` (`const_prop.rs:471-499`).
- `fold_jump_instruction()` rewrites a resolved conditional branch into either `ja` or `nop` (`const_prop.rs:262-275`).

For these exact Calico regressors, the measured sizes say the main effect is not widespread wide-immediate expansion. The plausible remaining mechanism is control-flow and layout perturbation:

- `const_prop` changes hot-path instructions without materially changing total size
- folded branches can become `ja` or `nop`
- downstream PCs and final x86 JIT layout shift
- branch prediction / alignment / front-end behavior can worsen even when byte growth is negligible

This is an inference, not a directly dumped per-PC diff for these exact three pass-isolated runs. The retained corpus artifact has the size/runtime data but not the unsanitized per-pass diff for the Calico regressors.

## Cluster 2: BCC `map_inline + const_prop + dce` Regressions

### Exact corpus measurements

| Program | Passes | Sites | Exec ns | Xlated bytes | Native bytes | Result / retval |
| --- | --- | ---: | --- | --- | --- | --- |
| `opensnoop:tracepoint__syscalls__sys_enter_openat` | `map_inline,const_prop,dce` | 483 | `210 -> 333` (`1.59x`) | `288 -> 280` | `174 -> 163` | `2480/0 -> 2480/0` |
| `tcpconnect:tcp_v4_connect` | `map_inline,const_prop,dce` | 221 | `1137 -> 1708` (`1.50x`) | `184 -> 192` | `115 -> 116` | `50/0 -> 50/0` |
| `tcpconnlat:fentry_tcp_rcv_state_process` | `map_inline,const_prop,dce` | 36 | `1003 -> 1691` (`1.69x`) | `1024 -> 1024` | `671 -> 669` | `50/0 -> 50/0` |
| `tcptracer:tcp_v4_connect` | `map_inline,const_prop,dce` | 64 | `1204 -> 2016` (`1.67x`) | `280 -> 288` | `178 -> 179` | `50/0 -> 50/0` |

### What the data rules out

- `opensnoop` gets smaller in both xlated and native form, but still slows down.
- `tcpconnlat:fentry_tcp_rcv_state_process` has no xlated growth and shrinks by `2B` in native form, but still slows down.
- `tcpconnect` and `tcptracer` only grow by `+8` xlated bytes and `+1` native byte each.

So the BCC cluster is also not explained by "more instructions -> more I-cache pressure" alone.

## Concrete BCC Rewrite Evidence

`daemon/tests/results/static_verify.json` contains unsanitized pass-by-pass diagnostics and before/after bytecode for three BCC programs in this cluster.

### `tcpconnect:tcp_v4_connect`

Static-verify record:

- final size: `23 -> 24` insns, `115 -> 116` native bytes
- `map_inline`: `4` sites, `insn_delta = +2`
- `const_prop`: `2` sites, `insn_delta = 0`
- `dce`: `10` sites, `insn_delta = -10`

`map_inline` diagnostics:

- `site at PC=6: ... off=8 value=0x0`
- `site at PC=8: ... off=8 value=0x0`
- `site at PC=14: ... off=4 value=0xffffffff`
- `site at PC=18: ... off=4 value=0xffffffff`

Relevant before/after diff:

```text
   6: 61 12 00 00 00 00 00 00
  10: 61 12 00 00 00 00 00 00
  11: 18 03 00 00 ff ff ff ff

   6: b7 02 00 00 00 00 00 00
  10: 18 02 00 00 ff ff ff ff
  12: 18 03 00 00 ff ff ff ff
```

This is the clearest concrete regression mechanism in the BCC cluster: two `0xffffffff` 32-bit map values were materialized as 2-slot `LD_IMM64`, causing `map_inline` to add `+2` instructions locally.

### `tcptracer:tcp_v4_connect`

Static-verify record:

- final size: `35 -> 36` insns, `178 -> 179` native bytes
- `map_inline`: `4` sites, `insn_delta = +2`
- `const_prop`: `2` sites, `insn_delta = 0`
- `dce`: `10` sites, `insn_delta = -10`

`map_inline` diagnostics again show two zero loads and two `0xffffffff` loads:

- `site at PC=19: ... off=4 value=0x0`
- `site at PC=22: ... off=4 value=0x0`
- `site at PC=26: ... off=0 value=0xffffffff`
- `site at PC=30: ... off=0 value=0xffffffff`

Relevant before/after diff:

```text
  19: 61 12 00 00 00 00 00 00
  22: 61 12 00 00 00 00 00 00
  23: 18 03 00 00 ff ff ff ff

  19: b7 02 00 00 00 00 00 00
  22: 18 02 00 00 ff ff ff ff
  24: 18 03 00 00 ff ff ff ff
```

Same pattern as `tcpconnect`: local code growth exists, but it is tiny in the final program size.

### `tcpconnlat:fentry_tcp_rcv_state_process`

Static-verify record:

- final size: `128 -> 128` insns, `671 -> 669` native bytes
- `map_inline`: `2` sites, `insn_delta = 0`
- `const_prop`: `1` site, `insn_delta = 0`
- `dce`: `3` sites, `insn_delta = -3`

`map_inline` only constantizes zero-valued loads here, and one other site is skipped because the lookup key is not constant.

Relevant before/after diff:

```text
  45: 79 23 00 00 00 00 00 00
  45: b7 03 00 00 00 00 00 00
```

This is the strongest evidence against the blanket "map_inline made it slower because it made it bigger" story: this program gets no xlated growth, shrinks slightly in native form, and still regresses by `1.69x` in the corpus run.

## Why `map_inline` Produces the `LD_IMM64` Expansion

In `daemon/src/passes/map_inline.rs:1535-1545`:

```rust
fn emit_constant_load(dst_reg: u8, value: u64, size: u8) -> Vec<BpfInsn> {
    let signed_value = value as i64;
    if size == BPF_DW && signed_value >= i32::MIN as i64 && signed_value <= i32::MAX as i64 {
        return vec![BpfInsn::mov64_imm(dst_reg, signed_value as i32)];
    }

    if size != BPF_DW && value <= i32::MAX as u64 {
        return vec![BpfInsn::mov64_imm(dst_reg, value as i32)];
    }

    emit_ldimm64(dst_reg, value)
}
```

For non-`DW` loads, values above `i32::MAX` fall through to `emit_ldimm64()`. That means a 32-bit constant like `0xffffffff` becomes a 2-slot `LD_IMM64`. The `tcpconnect` and `tcptracer` diffs above show exactly this case.

So hypothesis `(b)` is partially correct: `map_inline` does create local instruction growth at these sites. But the corpus-wide evidence says this is only part of the story, not the full explanation for the slowdown cluster.

## Answers To The Original Hypotheses

### (a) `const_prop` used `LD_IMM64` instead of `MOV_IMM`, causing code bloat

- Not supported for the exact Calico regressors.
- Their xlated size is unchanged, and native growth is only `+2B/+4B`.
- If this effect exists there at all, it is too small to be the primary explanation.

### (b) `map_inline` inlined lookups and created more instructions

- Supported, but only locally.
- `tcpconnect` and `tcptracer` both show `0xffffffff` map values becoming 2-slot `LD_IMM64`.
- This explains a real `+2 insn` effect, but not the whole slowdown cluster because some slower programs shrink.

### (c) `dce`/folding changed branch layout and hurt prediction

- Strongly plausible.
- It is the best explanation for both:
  - Calico programs that slow down massively with almost no size change
  - BCC programs that slow down even when total size shrinks

### (d) The passes produced verifier-accepted but performance-poor code

- Yes, that is the overall conclusion.
- The programs still run correctly, but the rewritten hot path appears to be a worse shape for the final x86 JIT code.

## Supplemental Direct Daemon Probe

I also ran a direct single-program VM probe for `opensnoop:tracepoint__syscalls__sys_enter_openat` with `retain_daemon_debug = true` and captured the result in `docs/tmp/20260328/daemon_batch_result_opensnoop_openat_compileonly.json`.

That probe showed:

- `map_inline` changed `6` zero-valued pseudo-map-value loads
- `insn_delta = 0`
- `const_prop` was verifier-rejected in that compile-only environment with `unreachable insn 7`
- only `map_inline` was finally applied in that probe

Because this does not reproduce the exact final pass set from the corpus batch, I treat it as supplementary only. It is still directionally consistent with the main conclusion: the slowdown is not coming from large code expansion in `opensnoop`.

## Final Conclusion

- Calico cluster:
  - primary cause is almost certainly `const_prop` changing hot control flow / JIT layout, not instruction bloat
- BCC cluster:
  - there is one concrete `map_inline` codegen weakness for 32-bit `0xffffffff`
  - but the cluster as a whole is still dominated by code-shape/layout effects, because some regressors get smaller and still slow down

So the root cause is not "the passes made the programs much larger." The root cause is "the passes changed the hot code into verifier-valid but slower-to-run machine code," with one specific sub-problem in `map_inline`'s immediate emission logic making that effect worse for some BCC programs.

## Caveats

- The Calico conclusion is partly inferential because the exact pass-isolated run retained runtime/size data but not unsanitized per-pass diffs.
- The direct VM daemon probe for `opensnoop` did not reproduce the exact corpus pass set, so it was not used as the primary source.
- Even with those caveats, the exact corpus measurements already rule out the main alternative explanation of bulk code-size growth.
